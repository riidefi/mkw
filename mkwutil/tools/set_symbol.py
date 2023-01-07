import argparse
import os
from pathlib import Path
#import subprocess

from mkwutil.lib.symbols import SymbolsList, Symbol

parser = argparse.ArgumentParser(
    description="Call from the project root as the working directory. Sets an address to a symbol name, updating if existing and adding a new one if not existing. It also renames every occurence of that symbol in all subdirectories. If the symbol did not exist in the symbol map, renames every occurence of lbl_{address} instead"
)
parser.add_argument("address", type=lambda x: int(x,0), help="Symbol address")
parser.add_argument("symbolname", type=str, help="Symbol name")
parser.add_argument("symbolmap", type=Path, help="Path to base symbols.yml")
args = parser.parse_args()

symbols = SymbolsList()
with open(args.symbolmap, "r") as f:
    symbols.read_from_yaml(f)

if args.address in symbols:
    old_name = symbols[args.address].name
    if old_name != args.symbolname:
        symbols[args.address] = args.symbolname
else:
    old_name = f"lbl_{args.address:x}"
    symbols.put(Symbol(args.address, args.symbolname))

temp_filename = args.symbolmap.with_name("." + args.symbolmap.name + ".tmp")
with open(temp_filename, "w", newline="") as f:
    symbols.write_to_yaml(f)
os.replace(temp_filename, args.symbolmap)

if old_name != args.symbolname:
    command = f"find asm source -type f \( -name \"*.hpp\" -o -name \"*.cpp\" -o -name \"*.s\" \) -exec sed -i 's/{old_name}/{args.symbolname}/g' {{}} +"
    print(command)
    os.system(command)
