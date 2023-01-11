import argparse
import os
from pathlib import Path
from elftools.elf.elffile import ELFFile

from mkwutil.lib.symbols import SymbolsList
from mkwutil.tools.dump_rel_elf_symbols import symbols_from_elf
from mkwutil.tools.set_symbol import set_symbol

parser = argparse.ArgumentParser(
    description="Updates symbol names from the names in elf file"
)
parser.add_argument("elf_file", type=Path, help="Path to generated ELF file")
parser.add_argument("symbol_map", type=Path, help="Path to new symbols.yml")
args = parser.parse_args()

with open(args.elf_file, "rb") as elf_file:
    elf = ELFFile(elf_file)
    elf_syms = symbols_from_elf(elf)

symbols = SymbolsList()
with open(args.symbol_map, "r") as f:
    symbols.read_from_yaml(f)

for sym in elf_syms:
    if sym.addr in symbols:
        old_name = symbols[sym.addr].name
        if old_name != sym.name:
            print(f"Updating symbol at {sym.addr:x} from {old_name} to {sym.name}")
            set_symbol(sym.addr, sym.name, args.symbol_map)
