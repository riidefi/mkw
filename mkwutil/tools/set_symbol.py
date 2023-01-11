import argparse
import os
from pathlib import Path
#import subprocess

from mkwutil.lib.symbols import SymbolsList, Symbol


def set_symbol(address, symbolname, symbolmap):
    symbols = SymbolsList()
    with open(symbolmap, "r") as f:
        symbols.read_from_yaml(f)

    if address in symbols:
        old_name = symbols[address].name
        if old_name != symbolname:
            del symbols[address]
            symbols.put(Symbol(address, symbolname))
    else:
        old_name = f"lbl_{address:x}"
        symbols.put(Symbol(address, symbolname))

    temp_filename = symbolmap.with_name("." + symbolmap.name + ".tmp")
    with open(temp_filename, "w", newline="") as f:
        symbols.write_to_yaml(f)
    os.replace(temp_filename, symbolmap)

    if old_name != symbolname:
        command = f"find asm source -type f \( -name \"*.hpp\" -o -name \"*.cpp\" -o -name \"*.s\" \) -exec sed -i 's/\<{old_name}\>/{symbolname}/g' {{}} +"
        print(command)
        os.system(command)


def main(args):
    set_symbol(args.address, args.symbolname, args.symbolmap)

if __name__ == '__main__':
    parser = argparse.ArgumentParser(
        description="Call from the project root as the working directory. Sets an address to a symbol name, updating if existing and adding a new one if not existing. It also renames every occurence of that symbol in all subdirectories. If the symbol did not exist in the symbol map, renames every occurence of lbl_{address} instead"
    )
    parser.add_argument("address", type=lambda x: int(x,0), help="Symbol address")
    parser.add_argument("symbolname", type=str, help="Symbol name")
    parser.add_argument("symbolmap", type=Path, help="Path to base symbols.yml")
    args = parser.parse_args()
    main(args)
