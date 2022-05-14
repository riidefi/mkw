import argparse
import jinja2
from pathlib import Path, PurePosixPath, PureWindowsPath
import re
import sys

from elftools.elf.elffile import ELFFile

from mkwutil.lib.slices import SliceTable
from mkwutil.lib.symbols import Symbol, SymbolsList
from mkwutil.sections import DOL_SECTIONS, REL_SECTIONS


MATCH_UNK = re.compile(r"^unk_([0-9a-f]{8})$")

# LCF must use forward slashes on linux/osx
def format_path(p):
    if sys.platform == "win32" or sys.platform == "msys":
        return str(PureWindowsPath(p))
    return f'"{PurePosixPath(p)}"'


def gen_lcf(
    src: Path,
    dst: Path,
    object_paths: list[Path],
    slices_path: Path,
):
    """Generates the LCF."""
    # Read slices.
    slices = SliceTable.load_path(slices_path)
    slices = slices.filter(SliceTable.ONLY_ENABLED)
    # For dol and rel, we can also fill in section names.
    if slices_path.name == "dol_slices.csv":
        slices.set_sections(DOL_SECTIONS)
    elif slices_path.name == "rel_slices.csv":
        slices.set_sections(REL_SECTIONS)
    else:
        print(f"WARN: Using linker-defined symbols instead of inline assembly")
    # Search for stripped objects.
    stripped = set()
    for _slice in slices:
        if _slice.has_name() and "strip" in _slice.tags:
            stripped.add(Path(_slice.name).stem)
    # Read symbols list.
    symbols = SymbolsList()
    # Create list of FORCEFILES.
    force_files = []
    for obj_path in object_paths:
        if obj_path.stem in stripped:
            continue
        force_files.append(format_path(obj_path.parent / (obj_path.stem + ".o")))
    # Compile template.
    template = jinja2.Template(src.read_text())
    # Render template to string.
    lcf = template.render({"force_files": force_files})
    # Write out to final LCF.
    with open(dst, "w") as f:
        f.write(lcf)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--base", type=Path, required=True, help="Path to base linker script"
    )
    parser.add_argument(
        "--out", type=Path, required=True, help="Path to linker script output"
    )
    parser.add_argument("--objs", type=Path, required=True, help="Path to objects list")
    parser.add_argument(
        "--prefix",
        type=Path,
        default="",
        help="Dir prefix for references in linker script",
    )
    parser.add_argument(
        "--slices", type=Path, required=True, help="Path to slices file"
    )
    parser.add_argument(
        "--symbols", type=Path, required=True, help="Path to symbols.txt file"
    )
    args = parser.parse_args()

    # Read list of objects.
    objs = []
    with open(args.objs, "r") as file:
        for line in file:
            objs.append(args.prefix / Path(line))

    gen_lcf(args.base, args.out, objs, args.slices)
