import argparse
import csv
from pathlib import Path


def gen_lcf(src, dst, object_paths, slices_path):
    # Read slices and search for stripped objects.
    stripped = set()
    for entry in csv.DictReader(open(slices_path, "r")):
        strip_opt = entry.get("strip")
        if strip_opt is None:
            continue
        if strip_opt.strip() != "1":
            continue
        stripped.add(Path(entry["name"]).stem)

    lcf = ""

    with open(src, "r") as f:
        lcf = f.read()
        lcf += "\nFORCEFILES {\n"
        for obj_path in object_paths:
            obj_path = Path(obj_path)
            if obj_path.stem in stripped:
                continue
            lcf += str(obj_path.parent / (obj_path.stem + ".o")) + "\n"
        lcf += "}\n"

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
    args = parser.parse_args()

    # Read list of objects.
    objs = []
    with open(args.objs, "r") as file:
        for line in file:
            objs.append(args.prefix / Path(line))

    gen_lcf(args.base, args.out, objs, args.slices)
