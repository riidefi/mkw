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
    parser.add_argument("--force_analyse", action="store_true", help="Force run original binary analysis")
    parser.add_argument("--link_only", action="store_true", help="Link only, don't build")
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
    "-msgstyle gcc -lang=c99 -DREVOKART",
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
        command = f"$as $in $asflags -o $out",
        description = "AS $in"
    )

    ALLOW_CHAIN = "cmd /c " if os.name == "nt" else ""
    n.rule(
        "cc",
        command = ALLOW_CHAIN + f"$gcc -Isource -Isource/** -MM -MF $out.d $in && $cc $cflags -o $out $in",
        description = "CC $in",
        deps = "gcc",
        depfile = "$out.d"
    )

    for src in chain(SOURCES_DOL, SOURCES_REL):
        srcPath = Path(src.src)
        o_path = str((Path("out") / srcPath.parts[-1]).with_suffix(".o"))

        n.build(
            o_path,
            rule = "cc",
            inputs = src.src,
            variables = {
                "cc" : get_compat_cmd(CWCC_PATHS[src.cc]),
                "cflags" : CWCC_OPT + ' ' + src.opts,
            }
        )

    for asm in asm_files:
        out_o = Path("out") / asm.relative_to("asm").with_suffix(".o")
        n.build(
            str(out_o),
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
    slices_path = Path("pack", "dol_slices.csv")
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
        command = f"python mkwutil/mkw_binary_patch.py $in && python mkwutil/pack_main_dol.py -o $out $in",
        description = "PACK $out"
    )
    n.build(
        str(dol_path),
        rule = "pack_dol",
        inputs = str(elf_path)
    )
    return dol_path


def link_rel(rel_objects_path: Path, n: Writer):
    rel_objects = open(rel_objects_path, "r").readlines()
    rel_objects = [Path(x.strip()) for x in rel_objects]
    """Links StaticR.rel."""
    # Generate LCF.
    src_lcf_path = Path("pack", "rel.lcf.j2")
    dst_lcf_path = Path("pack", "rel.lcf")
    slices_path = Path("pack", "rel_slices.csv")
    n.build(
        str(dst_lcf_path),
        rule = "lcfgen",
        inputs = str(rel_objects_path),
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
    elf_path = dest_dir / "StaticR.elf"
    map_path = dest_dir / "StaticR.map"
    link(elf_path, rel_objects, dst_lcf_path, map_path, n, partial=True)
    # Convert ELF to REL.
    dol_elf_path = dest_dir / "main.elf"
    rel_path = dest_dir / "StaticR.rel"
    orig_dir = Path("artifacts", "orig")
    orig_rel_yml_path = Path("mkwutil", "ppcdis_adapter", "rel.yaml")
    n.rule(
        "pack_rel",
        command = f"python mkwutil/pack_staticr_rel.py --base-rel $baserel --dol-elf $dolelf -o $out $in",
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
    return rel_path


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

        slices_path = Path("pack", "rel_slices.csv")
        n.variable("slices", str(slices_path))
        n.rule(
            "lcfgen",
            command = f"python mkwutil/gen_lcf.py --base $base --out $out --objs $in --slices $slices",
            description = "LCFGEN $out"
        )
        n.variable("ld", get_compat_cmd(MWLD))
        n.rule(
            "ld",
            command = f"$ld $in $ldflags -o $out",
            description = "LD $out"
        )
        target_dol_path = link_dol(dol_objects_path, n)
        target_rel_path = link_rel(rel_objects_path, n)

        n.rule(
            "verify",
            command = f"python $verifyscript --reference $ref --target $in",
            description = "VERIFY $in"
        )
        dol_ok = "." + str(orig_dol_path)+".ok"
        n.build(
            dol_ok,
            rule = "verify",
            inputs = str(target_dol_path),
            variables = {
                "verifyscript" : "mkwutil/verify_main_dol.py",
                "ref" : str(orig_dol_path),
            }
        )
        rel_ok = "." + str(orig_rel_path)+".ok"
        n.build(
            rel_ok,
            rule = "verify",
            inputs = str(target_rel_path),
            variables = {
                "verifyscript" : "mkwutil/verify_staticr_rel.py",
                "ref" : str(orig_rel_path),
            }
        )

        n.rule("stats", command = f"python mkwutil/progress/percent_decompiled.py", description = "STATS")
        n.build("phony", rule="stats", inputs=[rel_ok, dol_ok], implicit=[dol_ok, rel_ok])


if __name__ == "__main__":
    args = parse_args()
    configure(args)
