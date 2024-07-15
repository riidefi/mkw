"""
Build script for Mario Kart Wii.
"""


import argparse
from itertools import chain
import os
import os.path
from pathlib import Path
from random import randbytes
import subprocess
import sys

from elftools.elf.elffile import ELFFile
from multiprocessing.dummy import Pool as ThreadPool, Lock
import multiprocessing

import colorama
from termcolor import colored

from ninja_syntax import Writer

from sources import SOURCES_DOL, SOURCES_REL
from mkwutil.lib.slices import SliceTable
from mkwutil.sections import DOL_SECTIONS, REL_SECTIONS
from mkwutil.verify_object_file import verify_object_file
from mkwutil.gen_lcf import gen_lcf
from mkwutil.mkw_binary_patch import patch_elf
from mkwutil.pack_main_dol import pack_main_dol
from mkwutil.pack_staticr_rel import pack_staticr_rel
from mkwutil.verify_main_dol import verify_dol
from mkwutil.verify_staticr_rel import verify_rel
from mkwutil.progress.percent_decompiled import build_stats
from mkwutil.gen_asm import gen_asm
from mkwutil.project import load_dol_slices, load_rel_slices
from mkwutil.ppcdis_adapter.ppcdis_analyse import analyse_bins


def parse_args():
    parser = argparse.ArgumentParser(description="Build main.dol and StaticR.rel.")
    parser.add_argument("--regen_asm", action="store_true", help="Regenerate all ASM")
    parser.add_argument("--shiftable", action="store_true", help="Attempt to make a shiftable build. Useful for mods, although will probably cause the output to not match")
    parser.add_argument("--force_analyse", action="store_true", help="Force run original binary analysis")
    parser.add_argument("--link_only", action="store_true", help="Link only, don't build")
    parser.add_argument("--full_errors", action="store_true", help="Show full error log")
    args = parser.parse_args()
    return args


colorama.init()
print_mutex = Lock()

# Remember which files are stripped.
def get_strip_info_and_slices():
    dol_slices = load_dol_slices(sections=DOL_SECTIONS)
    stripped_files = set()
    for _slice in dol_slices:
        if "strip" in _slice.tags:
            stripped_files.add(Path(_slice.name).stem)
    dol_object_slices = dol_slices.object_slices()
    # Rename objects to stem, not full path.
    dol_object_slices.objects = {
        Path(k).stem: v for k, v in dol_object_slices.objects.items()
    }

    rel_slices = load_rel_slices(sections=REL_SECTIONS)
    rel_object_slices = rel_slices.object_slices()
    # Rename objects to stem, not full path.
    rel_object_slices.objects = {
        Path(k).stem: v for k, v in rel_object_slices.objects.items()
    }
    return stripped_files, dol_object_slices, rel_object_slices


def __native_binary(path):
    if sys.platform == "win32" or sys.platform == "msys":
        return path + ".exe"
    return path


VERBOSE = False

DEVKITPPC = os.environ.get("DEVKITPPC")
if DEVKITPPC is None:
    # devkitPPC not specified in env.
    # Default to ./tools/devkitppc
    DEVKITPPC = Path().joinpath("tools", "devkitppc")
    if not os.path.isdir(DEVKITPPC):
        print(
            f'Could not find devkitPPC under "{DEVKITPPC}" and $DEVKITPPC var is not set.',
            file=sys.stderr,
        )
        sys.exit(1)


GAS = __native_binary(os.path.join(DEVKITPPC, "bin", "powerpc-eabi-as"))
GCC = __native_binary(os.path.join(DEVKITPPC, "bin", "powerpc-eabi-gcc"))

MWLD = os.path.join("tools", "mwldeppc.exe")
PPC2CPP = __native_binary(os.path.join("tools", "ppc2cpp", "bin", "ppc2cpp"))
ALLOW_CHAIN = "cmd /c " if os.name == "nt" else ""

CWCC_PATHS = {
    "default": os.path.join(".", "tools", "4199_60831", "mwcceppc.exe"),
    # For the main game
    # August 17, 2007
    # 4.2.0.1 Build 127
    #
    # Ideally we would use this version
    # We don't have this, so we use build 142:
    # This version has the infuriating bug where random
    # nops are inserted into your code.
    "4201_127": os.path.join(".", "tools", "4201_142", "mwcceppc.exe"),
    # The script doesn't automatically make this backup, because Windows may block attempts to run an
    # executable file created from python's process without UAC override (WinError 740).
    "4201_127_unpatched": os.path.join(".", "tools", "4201_142", "mwcceppc_unpatched.exe"),

    # For most of RVL
    # We actually have the correct version
    "4199_60831": os.path.join(".", "tools", "4199_60831", "mwcceppc.exe"),
    # For HBM/WPAD, NHTTP/SSL
    # We use build 60831
    "4199_60726": os.path.join(".", "tools", "4199_60831", "mwcceppc.exe"),
}


def patch_compilers():
    with open(CWCC_PATHS["4201_127"], "rb") as og:
        ogbytes = bytearray(og.read())

    patches = [
        # Fix PS scheduling (mark instructions following a PS operation as data-dependencies in gekko mode)
        # Found by stebler.
        #
        {
            "at": 0x1A8540,
            "before": bytes([0x66, 0x83, 0x3D, 0x40, 0xF3]),
            "after": bytes([0xE9, 0x8B, 0x0D, 0x00, 0x00]),
        }
    ]

    for patch in patches:
        assert len(patch["before"]) == len(patch["after"])
        patch_size = len(patch["before"])

        before = ogbytes[patch["at"] : patch["at"] + patch_size]
        assert before == patch["after"] or before == patch["before"]
        ogbytes[patch["at"] : patch["at"] + patch_size] = patch["after"]

    with open(CWCC_PATHS["4201_127"], "wb") as new:
        new.write(ogbytes)


patch_compilers()

CW_ARGS = [
    "-nodefaults",
    "-align powerpc",
    "-enc SJIS",
    "-c",
    # "-I-",
    "-gccinc",
    "-i ./source/ -i ./source/platform",
    # "-inline deferred",
    "-proc gekko",
    "-enum int",
    "-O4,p",
    "-inline auto",
    "-W all",
    "-fp hardware",
    "-Cpp_exceptions off",
    "-RTTI off",
    #'-pragma "cats off"',  # ???
    # "-pragma \"aggressive_inline on\"",
    # "-pragma \"auto_inline on\"",
    "-inline auto",
    "-w notinlined -W noimplicitconv -w nounwanted",
    "-nostdinc",
    "-msgstyle gcc -DREVOKART",
    "-func_align 4",
    #"-sym dwarf-2",
]

# Hack: $@ doesn't behave properly with this
if sys.platform != "darwin":
    # suppress "function has no prototype
    CW_ARGS.append('-pragma "warning off(10178)"')

CWCC_OPT = " ".join(CW_ARGS)


def run_windows_cmd(cmd: str) -> tuple[list[str], int]:
    """Runs a shell command and returns the stdout lines."""
    if sys.platform == "win32" or sys.platform == "msys":
        return __run_windows_cmd_win32(cmd)
    return __run_windows_cmd_wine(cmd)


def __run_windows_cmd_win32(cmd: str) -> tuple[list[str], int]:
    process = subprocess.Popen(
        cmd, text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT
    )
    lines = process.stdout.readlines()
    process.wait()
    return lines, process.returncode


def __unix_tmp_file():
    name = f"mkw-build-{randbytes(16).hex()}.log"
    # Wine with /dev/shm is slower than /tmp on Linux!
    tmp_dir = Path("/tmp")
    file_path = tmp_dir / name
    file = open(file_path, "w+")
    os.unlink(file_path)  # ensure file gets removed after build
    return file


def __run_windows_cmd_wine(cmd: str) -> tuple[list[str], int]:
    if sys.platform == "darwin":
        compat = os.path.abspath("./mkwutil/tools/crossover.sh")
    else:
        compat = "wine"
    cmd = f"{compat} {cmd}"
    with __unix_tmp_file() as stdout:
        process = subprocess.run(
            cmd, text=True, stdout=stdout, stderr=subprocess.STDOUT, shell=True
        )
        stdout.seek(0, 0)
        return stdout.readlines(), process.returncode


def get_compat_cmd(cmd: str) -> str:
    if not (sys.platform == "win32" or sys.platform == "msys"):
        if sys.platform == "darwin":
            compat = os.path.abspath("./mkwutil/tools/crossover.sh")
        else:
            compat = "wine"
        cmd = f"{compat} {cmd}"
    return cmd


def __assert_command_success(returncode, command):
    assert returncode == 0, f"{command} exited with returncode {returncode}"


def link(
    dst: Path, objs: list[Path], lcf: Path, map_path: Path, n: Writer, partial: bool = False
) -> bool:
    """Links an ELF."""
    ldflagslist = [
            "-lcf",
            lcf,
            "-fp",
            "hard",
            "-linkmode",
            "moreram",
            "-map",
            map_path,
        ]
    if partial:
        ldflagslist.append("-r1")
    ldflags = " ".join(map(str, ldflagslist))

    n.build(
        str(dst),
        rule = "ld",
        inputs = list(map(str, objs)),
        implicit = str(lcf),
        variables = {
            "ldflags" : ldflags
        }
    )


def add_compile_rules(args, n: Writer):
    OUTDIR = 'out'
    out_dir = Path(OUTDIR)
    out_dir.mkdir(exist_ok=True)
    (out_dir / "dol").mkdir(exist_ok=True)
    (out_dir / "rel").mkdir(exist_ok=True)

    asm_files = [
        x.relative_to(os.getcwd())
        for x in Path(os.path.join(os.getcwd(), "asm")).glob("**/*.s")
    ]

    n.variable("outdir", OUTDIR)
    n.variable("as", GAS)
    n.variable("gcc", GCC)
    n.variable("asflags", "-mgekko -Iasm")

    n.rule(
        "as",
        command = ALLOW_CHAIN + "$as $in $asflags -o $out && python -m mkwutil.postprocess -fno-ctor_realign -fsymbol-fixup -fprologue-fixup=none $out",
        description = "AS $in"
    )

    n.rule(
        "cc",
        command = ALLOW_CHAIN + "$gcc -Isource -Isource/platform -nostdinc -M -MF $out.d $in && $cc $cflags -o $out $in && python -m mkwutil.postprocess -fno-ctor_realign -fsymbol-fixup -fprologue-fixup=none $out",
        description = "CC $in",
        deps = "gcc",
        depfile = "$out.d"
    )

    for src in chain(SOURCES_DOL, SOURCES_REL):
        srcPath = Path(src.src)
        o_path = str((Path("out") / srcPath.parts[-1]).with_suffix(".o"))

        error_cap = 0 if args.full_errors else 1

        n.build(
            o_path,
            rule = "cc",
            inputs = src.src,
            variables = {
                "cc" : get_compat_cmd(CWCC_PATHS[src.cc]),
                "cflags" : CWCC_OPT + f' -maxerrors {error_cap} ' + src.opts + (" -DSHIFTABLE" if args.shiftable else ""),
            }
        )

    for asm in asm_files:
        out_o = str(Path("out") / asm.relative_to("asm").with_suffix(".o"))
        n.build(
            out_o,
            rule = "as",
            inputs = str(asm)
        )


def link_dol(dol_objects_path: Path, n: Writer):
    """Links main.dol."""
    dol_objects = open(dol_objects_path, "r").readlines()
    dol_objects = [Path(x.strip()) for x in dol_objects]
    # Generate LCF.
    src_lcf_path = Path("pack", "dol.lcf.j2")
    dst_lcf_path = Path("pack", "dol.lcf")
    slices_path = Path("pack", "dol_slices.yml")
    n.build(
        str(dst_lcf_path),
        rule = "lcfgen",
        inputs = str(dol_objects_path),
        implicit= [str(src_lcf_path), str(slices_path)],
        variables = {
            "base" : str(src_lcf_path),
            "slices" : str(slices_path),
        }
    )
    # Create dest dir.
    dest_dir = Path("artifacts", "target", "pal")
    dest_dir.mkdir(parents=True, exist_ok=True)
    # Link ELF.
    elf_path = dest_dir / "main.elf"
    map_path = dest_dir / "main.map"
    link(elf_path, dol_objects, dst_lcf_path, map_path, n)
    # Convert ELF to DOL.
    dol_path = dest_dir / "main.dol"
    n.rule(
        "pack_dol",
        command = ALLOW_CHAIN + "python -m mkwutil.mkw_binary_patch $in && python -m mkwutil.pack_main_dol -o $out $in",
        description = "PACK $out"
    )
    n.build(
        str(dol_path),
        rule = "pack_dol",
        inputs = str(elf_path)
    )
    return dol_path, elf_path


def link_rel(rel_objects_path: Path, n: Writer):
    rel_objects = open(rel_objects_path, "r").readlines()
    rel_objects = [Path(x.strip()) for x in rel_objects]
    """Links StaticR.rel."""
    # Create dest dir.
    dest_dir = Path("artifacts", "target", "pal")
    dest_dir.mkdir(parents=True, exist_ok=True)
    # Link ELF.
    elf_path = dest_dir / "StaticR.elf"
    map_path = dest_dir / "StaticR.map"
    lcf_path = Path("pack", "rel.lcf")
    link(elf_path, rel_objects, lcf_path, map_path, n, partial=True)
    # Convert ELF to REL.
    dol_elf_path = dest_dir / "main.elf"
    rel_path = dest_dir / "StaticR.rel"
    orig_dir = Path("artifacts", "orig")
    orig_rel_yml_path = Path("mkwutil", "ppcdis_adapter", "rel.yaml")
    n.rule(
        "pack_rel",
        command = "python -m mkwutil.pack_staticr_rel --base-rel $baserel --dol-elf $dolelf -o $out $in",
        description = "PACK $out"
    )
    n.build(
        str(rel_path),
        rule = "pack_rel",
        inputs = str(elf_path),
        implicit = [str(dol_elf_path),str(orig_rel_yml_path)],
        variables = {
            "baserel" : str(orig_rel_yml_path),
            "dolelf" : str(dol_elf_path),
        }
    )
    return rel_path, elf_path


def provide_ppc2cpp():
    if not os.path.exists(PPC2CPP):
        import urllib.request
        import zipfile
        ppc2cpp_zip = "ppc2cpp.zip"
        print("Downloading ppc2cpp...")
        if sys.platform == "win32" or sys.platform == "msys":
            ppc2cpp_url = "https://github.com/em-eight/ppc2cpp/releases/download/v1.1-rc1/ppc2cpp-Windows.zip"
        else:
            ppc2cpp_url = "https://github.com/em-eight/ppc2cpp/releases/download/v1.1-rc1/ppc2cpp-Linux.zip"
        urllib.request.urlretrieve(ppc2cpp_url, ppc2cpp_zip)
        with zipfile.ZipFile(ppc2cpp_zip, 'r') as zip_ref:
            zip_ref.extractall("tools/ppc2cpp")
            st = os.stat(str(PPC2CPP))
            import stat
            os.chmod(str(PPC2CPP), st.st_mode | stat.S_IEXEC)



def add_ppc2cpp_rules(orig_files, target_files, orig_out, target_out, n: Writer):
    provide_ppc2cpp()
    n.variable("ppc2cpp", str(PPC2CPP))
    n.variable("ppcdis_dir", "mkwutil/ppcdis_adapter")
    symmap = Path("pack/symbols.yml")
    n.variable("symmap", str(symmap))
    importcmd = "$ppc2cpp importppcdis -s $symmap -i $out -p $ppcdis_dir/dol.yaml $ppcdis_dir/dol_labels.pickle $ppcdis_dir/dol_relocs.pickle -p $ppcdis_dir/rel.yaml $ppcdis_dir/rel_labels.pickle $ppcdis_dir/rel_relocs.pickle"
    n.rule(
        "ppc2cppcreateorig",
        command=ALLOW_CHAIN + "$ppc2cpp create -o $out $in && " + importcmd,
        description="PPC2CPP CREATE ORIG"
    )
    n.rule(
        "ppc2cppcreatetarget",
        command="$ppc2cpp create -o $out $in",
        description="PPC2CPP CREATE TARGET"
    )
    n.build(
        str(orig_out),
        rule="ppc2cppcreateorig",
        inputs=list(str(pth) for pth in orig_files),
        implicit=[str(symmap)]
    )
    n.build(
        str(target_out),
        rule="ppc2cppcreatetarget",
        inputs=list(str(pth) for pth in target_files)
    )


def configure(args):
    analyse_bins(args.force_analyse)
    gen_asm(args.regen_asm)

    """Builds the game."""
    Path("target").mkdir(exist_ok=True)

    dol_objects_path = Path("pack/dol_objects.txt")
    rel_objects_path = Path("pack/rel_objects.txt")

    ninjapath = 'build.ninja'
    with open(ninjapath, 'w') as ninjafile:
        n = Writer(ninjafile)
        add_compile_rules(args, n)

        orig_dol_path = Path("artifacts", "orig", "pal", "main.dol")
        orig_rel_path = Path("artifacts", "orig", "pal", "StaticR.rel")

        slices_path = Path("pack", "rel_slices.yml")
        n.variable("slices", str(slices_path))
        n.rule(
            "lcfgen",
            command = "python -m mkwutil.gen_lcf --base $base --out $out --objs $in --slices $slices",
            description = "LCFGEN $out"
        )
        n.variable("ld", get_compat_cmd(MWLD))
        n.rule(
            "ld",
            command = "$ld $in $ldflags -o $out",
            description = "LD $out"
        )
        target_dol_path, target_dol_elf_path = link_dol(dol_objects_path, n)
        target_rel_path, target_rel_elf_path = link_rel(rel_objects_path, n)

        orig_ppc2cpp_proj = Path("artifacts", "orig", "pal", "orig.ppc2cpp")
        target_ppc2cpp_proj = Path("artifacts", "orig", "pal", "target.ppc2cpp")
        add_ppc2cpp_rules([orig_dol_path, orig_rel_path], [target_dol_elf_path, target_rel_elf_path], orig_ppc2cpp_proj, target_ppc2cpp_proj, n)

        n.rule(
            "verify",
            command = "python -m $verifyscript --reference $ref --target $in",
            description = "VERIFY $in"
        )
        dol_ok = "." + str(orig_dol_path)+".ok"
        n.build(
            dol_ok,
            rule = "verify",
            inputs = str(target_dol_path),
            implicit = [str(orig_ppc2cpp_proj), str(target_ppc2cpp_proj), str(target_dol_elf_path)],
            variables = {
                "verifyscript" : "mkwutil.verify_main_dol",
                "ref" : str(orig_dol_path),
            }
        )
        rel_ok = "." + str(orig_rel_path)+".ok"
        n.build(
            rel_ok,
            rule = "verify",
            inputs = str(target_rel_path),
            implicit = [str(orig_ppc2cpp_proj), str(target_ppc2cpp_proj), str(target_rel_elf_path)],
            variables = {
                "verifyscript" : "mkwutil.verify_staticr_rel",
                "ref" : str(orig_rel_path),
            }
        )

        n.rule("stats", command = "python -m mkwutil.progress.percent_decompiled", description = "STATS")
        n.build("phony", rule="stats", inputs=[rel_ok, dol_ok], implicit=[dol_ok, rel_ok])


if __name__ == "__main__":
    args = parse_args()
    configure(args)
