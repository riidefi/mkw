"""
Verifies that the symbols defined in an ELF match symbols.txt
"""

import argparse
from pathlib import Path
import sys
from typing import Optional

from elftools.elf.elffile import ELFFile

from mkwutil.lib.symbols import Symbol
from mkwutil.tools.dump_symbols import symbols_from_elf
from mkwutil.project import read_symbol_map


def diff_symbols(elf_sym: Symbol, orig_sym: Optional[Symbol]) -> bool:
    if orig_sym is None:
        if not elf_sym.name.startswith("unk_") and not elf_sym.name.startswith("_unk_"):
            print("[-] 0x%08x %s" % (elf_sym.addr, elf_sym.name))
        return False
    if elf_sym.name in ("__save_gpr", "__rest_gpr"):
        return True # ignore
    if elf_sym.name != orig_sym.name:
        print("[!] 0x%08x %s != %s" % (elf_sym.addr, elf_sym.name, orig_sym.name))
        return False
    elif elf_sym.addr != orig_sym.addr:
        print("[!] 0x%08x %s != 0x%08x" % (elf_sym.addr, elf_sym.name, orig_sym.addr))
        return False
    return True


def verify_symbols(symbols_txt: Path, target_elf):
    elf = ELFFile(target_elf)
    elf_syms = symbols_from_elf(elf)
    orig_syms = read_symbol_map(symbols_txt)
    for elf_sym in elf_syms:
        orig_sym = orig_syms.get(elf_sym.addr)
        diff_symbols(elf_sym, orig_sym)
        orig_sym = orig_syms.get_by_name(elf_sym.name)
        if orig_sym:
            diff_symbols(elf_sym, orig_sym)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--symbols", type=Path, default="./pack/symbols.txt", help="Path to symbols.txt"
    )
    parser.add_argument(
        "--elf",
        type=Path,
        default="./artifacts/target/pal/main.elf",
        help="Path to source ELF",
    )
    args = parser.parse_args()

    with open(args.elf, "rb") as elf_file:
        verify_symbols(args.symbols, elf_file)
