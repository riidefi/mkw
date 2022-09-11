import argparse
import os
from pathlib import Path

from mkwutil.lib.symbols import SymbolsList

parser = argparse.ArgumentParser(description="Reformats symbols.yml")
parser.add_argument("symbols", type=Path, help="Path to symbols.yml")
args = parser.parse_args()

symbols = SymbolsList()
with open(args.symbols, "r") as f:
    symbols.read_from_yaml(f)
temp_filename = args.symbols.with_name("." + args.symbols.name + ".tmp")
with open(temp_filename, "w", newline="") as f:
    symbols.write_to(f)
os.replace(temp_filename, args.symbols)
