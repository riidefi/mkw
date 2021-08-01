import argparse
import os
from pathlib import Path

from mkwutil.lib.symbols import SymbolsList

parser = argparse.ArgumentParser(description="Reformats symbols.txt")
parser.add_argument("symbols", type=Path, help="Path to symbols.txt")
args = parser.parse_args()

symbols = SymbolsList()
with open(args.symbols, "r") as f:
    symbols.read_from(f)
temp_filename = args.symbols.with_name("." + args.symbols.name + ".tmp")
with open(temp_filename, "w", newline="") as f:
    symbols.write_to(f)
os.replace(temp_filename, args.symbols)
