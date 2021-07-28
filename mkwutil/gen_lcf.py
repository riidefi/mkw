import argparse
import jinja2
from pathlib import Path
import re

from elftools.elf.elffile import ELFFile

from mkwutil.lib.slices import SliceTable
from mkwutil.lib.symbols import Symbol, SymbolsList


MATCH_UNK = re.compile(r"^unk_([0-9a-f]{8})$")


def gen_lcf(
    src: Path,
    dst: Path,
    object_paths: list[Path],
    slices_path: Path,
    symbols_path: Path,
):
    """Generates the LCF."""
    # Read slices and search for stripped objects.
    slices = SliceTable.load_path(slices_path)
    slices = slices.filter(SliceTable.ONLY_ENABLED)
    stripped = set()
    for _slice in slices:
        if _slice.has_name() and "strip" in _slice.tags:
            stripped.add(Path(_slice.name).stem)
    # Read symbols list.
    symbols = SymbolsList()
    symbols.read_from(open(symbols_path, "r"))
    # Scan objects for references to unknown symbols (unk_XXX).
    # We'll add those implicitly to LCF.
    for obj_path in object_paths:
        with open(obj_path, "rb") as file:
            elf = ELFFile(file)
            symtab = elf.get_section_by_name(".symtab")
            assert symtab is not None, "ELF has no symbol table"
            for symbol in symtab.iter_symbols():
                match = MATCH_UNK.match(symbol.name)
                if not match:
                    continue
                addr = int(match.group(1), 16)
                symbols.put(Symbol(addr, symbol.name))
    # Remove all symbols that fall into named slices.
    # They will be included in the object files, not the linker command file.
    for sym in symbols:
        _slice, _ = slices.find(sym.addr)
        assert _slice is not None
        if _slice.has_name():
            del symbols[sym]
    # Create list of FORCEFILES.
    force_files = []
    for obj_path in object_paths:
        if obj_path.stem in stripped:
            continue
        force_files.append(str(obj_path.parent / (obj_path.stem + ".o")))
    # Compile template.
    template = jinja2.Template(src.read_text())
    # Render template to string.
    lcf = template.render({"symbols": list(symbols), "force_files": force_files})
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
