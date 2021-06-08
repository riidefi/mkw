import argparse
from pathlib import Path

def gen_lcf(src, dst, o_files):
	lcf = ""

	with open(src, 'r') as f:
		lcf = f.read()
		lcf += "\nFORCEFILES {\n"
		for x in o_files:
			# TODO: Add ability to disable FORCEFILE to slices.csv
			if x.stem == "eggVideo":
				continue
			lcf += str(x.parent / (x.stem + ".o")) + "\n"
		lcf += "}\n"
	
	with open(dst, 'w') as f:
		f.write(lcf)


parser = argparse.ArgumentParser()
parser.add_argument("--base", type=Path, required=True, help="Path to base linker script")
parser.add_argument("--out", type=Path, required=True, help="Path to linker script output")
parser.add_argument("--objs", type=Path, required=True, help="Path to objects list")
parser.add_argument("--prefix", type=Path, default="", help="Dir prefix for references in linker script")
args = parser.parse_args()


# Read list of objects.
objs = []
with open(args.objs, "r") as file:
    for line in file:
        objs.append(args.prefix / Path(line))

gen_lcf(args.base, args.out, objs)
