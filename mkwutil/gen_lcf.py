import argparse
import csv
import jinja2
from pathlib import Path

from mkwutil.symbols import SymbolsList


def gen_lcf(src, dst, object_paths, slices_path, symbols_path):
    # Read slices and search for stripped objects.
    stripped = set()
    for entry in csv.DictReader(open(slices_path, "r")):
        strip_opt = entry.get("strip")
        if strip_opt is None:
            continue
        if strip_opt.strip() != "1":
            continue
        stripped.add(Path(entry["name"]).stem)
    # Read symbols list.
    symbols = SymbolsList()
    symbols.read(open(symbols_path, "r"))
    # Create list of FORCEFILES.
    force_files = []
    for obj_path in object_paths:
        obj_path = Path(obj_path)
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
