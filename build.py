import os
import os.path
from pathlib import Path
import subprocess
import sys

from mkwutil.gen_asm import read_slices
from mkwutil.verify_object_file import verify_object_file
from mkwutil.gen_lcf import gen_lcf
from mkwutil.pack_main_dol import pack_main_dol
from mkwutil.pack_staticr_rel import pack_staticr_rel
from mkwutil.verify_main_dol import verify_dol
from mkwutil.verify_staticr_rel import verify_rel
from mkwutil.percent_decompiled import percent_decompiled


dol_slices = read_slices("pack/dol_slices.csv", verbose=False)
dol_slices = { sl.obj_file : sl for sl in dol_slices }

def native_binary(path):
    if sys.platform == "win32" or sys.platform == "msys":
        return path + ".exe"
    return path


def windows_binary(path):
    if sys.platform == "win32" or sys.platform == "msys":
        return path
    return "wine " + path


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


GAS = native_binary(os.path.join(DEVKITPPC, "bin", "powerpc-eabi-as"))

MWLD = windows_binary(os.path.join("tools", "mwldeppc.exe"))

CWCC_PATHS = {
    "default": windows_binary(os.path.join(".", "tools", "4199_60831", "mwcceppc.exe")),
    # For the main game
    # August 17, 2007
    # 4.2.0.1 Build 127
    #
    # Ideally we would use this version
    # We don't have this, so we use build 142:
    # This version has the infuriating bug where random
    # nops are inserted into your code.
    "4201_127": windows_binary(os.path.join(".", "tools", "4201_142", "mwcceppc.exe")),
    # For most of RVL
    # We actually have the correct version
    "4199_60831": windows_binary(
        os.path.join(".", "tools", "4199_60831", "mwcceppc.exe")
    ),
    # For HBM/WPAD, NHTTP/SSL
    # We use build 60831
    "4199_60726": windows_binary(
        os.path.join(".", "tools", "4199_60831", "mwcceppc.exe")
    ),
}
CWCC_OPT = " ".join(
    [
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
        '-pragma "cats off"',  # ???
        # "-pragma \"aggressive_inline on\"",
        # "-pragma \"auto_inline on\"",
        "-inline auto",
        "-w notinlined -W noimplicitconv",
        "-nostdinc",
        "-msgstyle gcc -lang=c99 -DREVOKART",
        "-func_align 4",
    ]
)


def compile_source(src, dst, version="default", additional="-ipa file"):
    # Compile ELF object file.
    command = f"{CWCC_PATHS[version]} {CWCC_OPT + ' ' + additional} {src} -o {dst}"
    if VERBOSE:
        print(command)
    subprocess.run(command, check=True)
    # Verify ELF file section sizes.
    tha_slice = dol_slices.get(src)
    if tha_slice:
        verify_object_file(dst, src, tha_slice)
    else:
        print("# Skipping slices verification on", src)


def assemble(dst, src):
    subprocess.run([GAS, src, "-mgekko", "-Iasm", "-o", dst], check=True, text=True)


def link(dst, objs, lcf, partial=False):
    cmd = [MWLD] + objs + ["-o", dst, "-lcf", lcf, "-fp", "hard"]
    if partial:
        cmd.append("-r")
    subprocess.run(cmd, check=True, text=True)


def make_obj(src):
    substitutions = (".cpp", ".asm", ".c", ".s")
    for sub in substitutions:
        src = src.replace(sub, ".o")
    return src


def compile_sources():
    out_dir = Path("out")
    out_dir.mkdir(exist_ok=True)

    # compile sources
    # TODO exec() is bad practice
    with open("sources.py", "r") as sourcespy:
        exec(sourcespy.read())

    asm_files = [
        str(x.relative_to(os.getcwd()))
        for x in Path(os.path.join(os.getcwd(), "asm")).glob("**/*.s")
    ]

    (out_dir / "dol").mkdir(exist_ok=True)
    (out_dir / "rel").mkdir(exist_ok=True)

    for asm in asm_files:
        # Hack: Should use pathlib for this
        out_o = "out" + asm[len("asm") :]
        assemble(make_obj(out_o), asm)


def link_dol(o_files):
    # Generate LCF.
    src_lcf_path = Path("pack", "dol.base.lcf")
    dst_lcf_path = Path("pack", "dol.lcf")
    gen_lcf(src_lcf_path, dst_lcf_path, o_files)
    # Create dest dir.
    dest_dir = Path("artifacts", "target", "pal")
    dest_dir.mkdir(parents=True, exist_ok=True)
    # Link ELF.
    elf_path = dest_dir / "main.elf"
    link(elf_path, o_files, dst_lcf_path)
    # Convert ELF to DOL.
    dol_path = dest_dir / "main.dol"
    pack_main_dol(elf_path, dol_path)
    return dol_path


def link_rel(o_files):
    # Generate LCF.
    src_lcf_path = Path("pack", "rel.base.lcf")
    dst_lcf_path = Path("pack", "rel.lcf")
    gen_lcf(src_lcf_path, dst_lcf_path, o_files)
    # Create dest dir.
    dest_dir = Path("artifacts", "target", "pal")
    dest_dir.mkdir(parents=True, exist_ok=True)
    # Link ELF.
    elf_path = dest_dir / "StaticR.elf"
    link(elf_path, o_files, dst_lcf_path, partial=True)
    # Convert ELF to REL.
    rel_path = dest_dir / "StaticR.rel"
    orig_dir = Path("artifacts", "orig")
    pack_staticr_rel(elf_path, rel_path, orig_dir)
    return rel_path


def build():
    Path("target").mkdir(exist_ok=True)

    dol_objects_path = Path("pack/dol_objects.txt")
    rel_objects_path = Path("pack/rel_objects.txt")
    dol_objects = open(dol_objects_path, "r").readlines()
    rel_objects = open(rel_objects_path, "r").readlines()

    compile_sources()

    orig_dol_path = Path("artifacts", "orig", "pal", "main.dol")
    target_dol_path = link_dol(dol_objects)
    target_rel_path = link_rel(rel_objects)

    verify_dol(orig_dol_path, target_dol_path)
    verify_rel(target_rel_path)

    percent_decompiled()


build()
