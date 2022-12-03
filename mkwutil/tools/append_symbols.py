import argparse
import os
from pathlib import Path

from mkwutil.lib.symbols import SymbolsList

parser = argparse.ArgumentParser(
    description="Populates a symbols.yml with new entries, ignoring existing"
)
parser.add_argument("base", type=Path, help="Path to base symbols.yml")
parser.add_argument("new", type=Path, help="Path to new symbols.yml")
args = parser.parse_args()

symbols = SymbolsList()
with open(args.base, "r") as f:
    symbols.read_from_yaml(f)

new_syms = SymbolsList()
with open(args.new, "r") as f:
    new_syms.read_from_yaml(f)

for sym in new_syms:
    if not sym.addr in symbols:
        symbols.put(sym)

temp_filename = args.base.with_name("." + args.base.name + ".tmp")
with open(temp_filename, "w", newline="") as f:
    symbols.write_to_yaml(f)
os.replace(temp_filename, args.base)
