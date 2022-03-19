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

from multiprocessing.dummy import Pool as ThreadPool, Lock
import multiprocessing

import colorama
from termcolor import colored

from sources import SOURCES_DOL, SOURCES_REL
from mkwutil.lib.slices import SliceTable
from mkwutil.sections import DOL_SECTIONS
from mkwutil.verify_object_file import verify_object_file
from mkwutil.gen_lcf import gen_lcf
from mkwutil.pack_main_dol import pack_main_dol
from mkwutil.pack_staticr_rel import pack_staticr_rel
from mkwutil.verify_main_dol import verify_dol
from mkwutil.verify_staticr_rel import verify_rel
from mkwutil.progress.percent_decompiled import build_stats
from mkwutil.gen_asm import gen_asm
from mkwutil.project import load_dol_slices


parser = argparse.ArgumentParser(description="Build main.dol and StaticR.rel.")
parser.add_argument("--regen_asm", action="store_true", help="Regenerate all ASM")
parser.add_argument(
    "-j",
    "--concurrency",
    type=int,
    default=multiprocessing.cpu_count(),
    help="Compile concurrency",
)
parser.add_argument(
    "--single_file",
    type=str,
    default=None,
    help="For quick iteration on a single file before we get full incremental builds")
args = parser.parse_args()
# Start by running gen_asm.
gen_asm(args.regen_asm)


colorama.init()
print_mutex = Lock()

# Remember which files are stripped.
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
    with open(CWCC_PATHS["4201_127"], 'rb') as og:
        ogbytes = bytearray(og.read())

    patches = [
        # Fix PS scheduling (mark instructions following a PS operation as data-dependencies in gekko mode)
        # Found by stebler.
        #
        {
            'at': 0x1A8540,
            'before': bytes([0x66, 0x83, 0x3D, 0x40, 0xF3]),
            'after':  bytes([0xE9, 0x8B, 0x0D, 0x00, 0x00])
        }
    ]

    for patch in patches:
        assert len(patch['before']) == len(patch['after'])
        patch_size = len(patch['before'])

        before = ogbytes[patch['at']:patch['at']+patch_size]
        assert before == patch['after'] or before == patch['before']
        ogbytes[patch['at']:patch['at']+patch_size] = patch['after']

    with open(CWCC_PATHS["4201_127"], 'wb') as new:
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
    "-sym dwarf-2",
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


def __assert_command_success(returncode, command):
    assert returncode == 0, f"{command} exited with returncode {returncode}"


def compile_source_impl(src, dst, version="default", additional="-ipa file"):
    """Compiles a source file."""
    # Compile ELF object file.
    command = f"{CWCC_PATHS[version]} {CWCC_OPT + ' ' + additional} {src} -o {dst}"
    lines, returncode = run_windows_cmd(command)
    with print_mutex:
        print(f'{colored("CC", "green")} {src}')
        if VERBOSE:
            print(command)
        for line in lines:
            print("   " + line.strip())
    __assert_command_success(returncode, command)


gSourceQueue = []


def compile_queued_sources():
    """Dispatches multiple threads to compile all queued sources."""
    print(colored(f"max_hw_concurrency={args.concurrency}", color="yellow"))

    if not len(gSourceQueue):
        print(colored("No sources to compile", color="red"))
        return

    pool = ThreadPool(min(args.concurrency, len(gSourceQueue)))

    pool.map(lambda s: compile_source_impl(*s), gSourceQueue)

    pool.close()
    pool.join()

    #
    # colorama doesn't seem to work with multithreading
    #
    for (src, dst, _, _) in gSourceQueue:
        if src.stem in stripped_files:
            continue
        # Verify ELF file section sizes.
        obj_slices = dol_object_slices.get(src.stem)
        if obj_slices:
            verify_object_file(dst, src, obj_slices)
        else:
            print(colored(f"Skipping slices verification on {src}", color="yellow"))

    gSourceQueue.clear()


# Queued
def queue_compile_source(src, version="default", additional="-ipa file"):
    """Queues a C/C++ file for compilation."""
    dst = (Path("out") / src.parts[-1]).with_suffix(".o")
    gSourceQueue.append((src, dst, version, additional))


def assemble(dst: Path, src: Path) -> None:
    """Assembles a .s file."""
    print(f'{colored("AS", "green")} {src}')
    subprocess.run([GAS, src, "-mgekko", "-Iasm", "-o", dst], check=True, text=True)


def link(
    dst: Path, objs: list[Path], lcf: Path, map_path: Path, partial: bool = False
) -> bool:
    """Links an ELF."""
    print(f'{colored("LD", "green")} {dst}')
    cmd = (
        [MWLD]
        + objs
        + [
            "-o",
            dst,
            "-lcf",
            lcf,
            "-fp",
            "hard",
            "-linkmode",
            "moreram",
            "-map",
            map_path,
        ]
    )
    if partial:
        cmd.append("-r")
    command = " ".join(map(str, cmd))
    lines, returncode = run_windows_cmd(command)
    for line in lines:
        print(line)
    __assert_command_success(returncode, command)


def compile_sources():
    """Compiles all C/C++ and ASM files."""
    out_dir = Path("out")
    out_dir.mkdir(exist_ok=True)

    for src in chain(SOURCES_DOL, SOURCES_REL):
        queue_compile_source(Path(src.src), src.cc, src.opts)

    if args.single_file:
        print(colored('[NOTE] Only compiling sources matching "%s".' % args.single_file, "red"))
        global gSourceQueue
        gSourceQueue = list(filter(lambda x: args.single_file in str(x[0]), gSourceQueue))

    compile_queued_sources()

    asm_files = [
        x.relative_to(os.getcwd())
        for x in Path(os.path.join(os.getcwd(), "asm")).glob("**/*.s")
    ]

    (out_dir / "dol").mkdir(exist_ok=True)
    (out_dir / "rel").mkdir(exist_ok=True)

    for asm in asm_files:
        out_o = Path("out") / asm.relative_to("asm").with_suffix(".o")
        # Optimization: Do not assemble ASM files if the target object already exists.
        if out_o.exists():
            continue
        assemble(out_o, asm)


def link_dol(o_files: list[Path]):
    """Links main.dol."""
    # Generate LCF.
    src_lcf_path = Path("pack", "dol.lcf.j2")
    dst_lcf_path = Path("pack", "dol.lcf")
    slices_path = Path("pack", "dol_slices.csv")
    symbols_path = Path("pack", "symbols.txt")
    gen_lcf(src_lcf_path, dst_lcf_path, o_files, slices_path, symbols_path)
    # Create dest dir.
    dest_dir = Path("artifacts", "target", "pal")
    dest_dir.mkdir(parents=True, exist_ok=True)
    # Link ELF.
    elf_path = dest_dir / "main.elf"
    map_path = dest_dir / "main.map"
    link(elf_path, o_files, dst_lcf_path, map_path)
    # Convert ELF to DOL.
    dol_path = dest_dir / "main.dol"
    pack_main_dol(elf_path, dol_path)
    return dol_path


def link_rel(o_files: list[Path]):
    """Links StaticR.rel."""
    # Generate LCF.
    src_lcf_path = Path("pack", "rel.lcf.j2")
    dst_lcf_path = Path("pack", "rel.lcf")
    slices_path = Path("pack", "rel_slices.csv")
    symbols_path = Path("pack", "symbols.txt")
    gen_lcf(src_lcf_path, dst_lcf_path, o_files, slices_path, symbols_path)
    # Create dest dir.
    dest_dir = Path("artifacts", "target", "pal")
    dest_dir.mkdir(parents=True, exist_ok=True)
    # Link ELF.
    elf_path = dest_dir / "StaticR.elf"
    map_path = dest_dir / "StaticR.map"
    link(elf_path, o_files, dst_lcf_path, map_path, partial=True)
    # Convert ELF to REL.
    rel_path = dest_dir / "StaticR.rel"
    orig_dir = Path("artifacts", "orig")
    pack_staticr_rel(elf_path, rel_path, orig_dir)
    return rel_path


def build():
    """Builds the game."""
    Path("target").mkdir(exist_ok=True)

    dol_objects_path = Path("pack/dol_objects.txt")
    rel_objects_path = Path("pack/rel_objects.txt")
    dol_objects = open(dol_objects_path, "r").readlines()
    dol_objects = [Path(x.strip()) for x in dol_objects]
    rel_objects = open(rel_objects_path, "r").readlines()
    rel_objects = [Path(x.strip()) for x in rel_objects]

    compile_sources()

    orig_dol_path = Path("artifacts", "orig", "pal", "main.dol")
    orig_rel_path = Path("artifacts", "orig", "pal", "StaticR.rel")
    target_dol_path = link_dol(dol_objects)
    target_rel_path = link_rel(rel_objects)

    verify_dol(orig_dol_path, target_dol_path)
    verify_rel(orig_rel_path, target_rel_path)

    build_stats(Path()).print()


if __name__ == "__main__":
    build()
