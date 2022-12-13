import argparse
from dataclasses import dataclass
from pathlib import Path
import re
import sys
from typing import Generator, Optional

from elftools.elf.elffile import ELFFile
from elftools.elf.sections import StringTableSection, Symbol as ELFSymbol

from mkwutil.lib.symbols import Symbol, SymbolsList


MATCH_DOLLAR_THING = re.compile(r"^\w+\$\d+$")

STATICR_ELF_TEXT_SECTION_IDX = 1
STATICR_ELF_RODATA_SECTION_IDX = 2
STATICR_ELF_DATA_SECTION_IDX = 5
STATICR_ELF_BSS_SECTION_IDX = 6

STATICR_TEXT_SECTION_VMA = 0x805103b4
STATICR_BSS_SECTION_VMA = 0x809bd6e0
STATICR_RODATA_SECTION_VMA = 0x8088f720
STATICR_DATA_SECTION_VMA = 0x808b2bd0


def process_symbol(sym: ELFSymbol, strtab: StringTableSection) -> Optional[Symbol]:
    sym_type = sym.entry["st_info"]["type"]
    sym_bind = sym.entry["st_info"]["bind"]
    sym_name = strtab.get_string(sym["st_name"])
    sym_shndx = sym.entry["st_shndx"]
    size = sym["st_size"]

    if len(sym_name) == 0:
        return

    # function symbol
    if sym_type == "STT_FUNC" and sym_shndx == STATICR_ELF_TEXT_SECTION_IDX:
        if sym_bind in ("STB_GLOBAL", "STB_WEAK"):
            # Output
            addr = sym["st_value"] + STATICR_TEXT_SECTION_VMA
            if not (0x800_0000 <= addr < 0x8100_0000):
                return
            return Symbol(addr, sym_name, size)

    # data symbol
    elif sym_type == "STT_OBJECT" and sym_bind in ("STB_GLOBAL", "STB_WEAK"):
        if sym_shndx == STATICR_ELF_BSS_SECTION_IDX:
            addr = sym["st_value"] + STATICR_BSS_SECTION_VMA
            if not (0x800_0000 <= addr < 0x8100_0000):
                return
            return Symbol(addr, sym_name, size)
        elif sym_shndx == STATICR_ELF_RODATA_SECTION_IDX:
            addr = sym["st_value"] + STATICR_RODATA_SECTION_VMA
            if not (0x800_0000 <= addr < 0x8100_0000):
                return
            return Symbol(addr, sym_name, size)
        elif sym_shndx == STATICR_ELF_DATA_SECTION_IDX:
            addr = sym["st_value"] + STATICR_DATA_SECTION_VMA
            if not (0x800_0000 <= addr < 0x8100_0000):
                return
            return Symbol(addr, sym_name, size)
        return

    return


def symbols_from_elf(elf: ELFFile) -> SymbolsList:
    strtab = elf.get_section_by_name(".strtab")  # String table
    symtab = elf.get_section_by_name(".symtab")  # Symbol table

    symbols = SymbolsList()

    for elf_sym in symtab.iter_symbols():
        sym = process_symbol(elf_sym, strtab)
        if not sym:
            continue
        symbols.put(sym)

    return symbols


def process_elf(elf: ELFFile, out):
    symbols = symbols_from_elf(elf)
    symbols_sorted = SymbolsList()
    for sym in symbols:
        symbols_sorted.put(sym)
    symbols_sorted.write_to_yaml(out)


def main():
    parser = argparse.ArgumentParser(
        description="Dumps symbols in ELF to symbols.yml format"
    )
    parser.add_argument("elf", type=Path)
    parser.add_argument(
        "-o",
        "--output",
        type=Path,
        required=False,
        help="Path to output symbol list to",
    )
    args = parser.parse_args()

    with open(args.elf, "rb") as file:
        elf = ELFFile(file)
        if args.output:
            with open(args.output, "w", newline="") as out_file:
                process_elf(elf, out_file)
        else:
            process_elf(elf, sys.stdout)


if __name__ == "__main__":
    main()
