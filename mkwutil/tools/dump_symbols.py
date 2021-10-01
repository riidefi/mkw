import argparse
from dataclasses import dataclass
from pathlib import Path
import sys
from typing import Generator, Optional

from elftools.elf.elffile import ELFFile
from elftools.elf.sections import StringTableSection, Symbol as ELFSymbol

from mkwutil.lib.symbols import Symbol, SymbolsList


@dataclass
class SectionInfo:
    index: int
    offset: int

    @staticmethod
    def from_elf(elf: ELFFile, name: str) -> Optional["SectionInfo"]:
        for i, section in enumerate(elf.iter_sections()):
            if section.name == name:
                return SectionInfo(i, section.header["sh_addr"])


def get_code_sections(elf: ELFFile) -> Generator[SectionInfo, None, None]:
    for name in (".init", ".text"):
        sec_info = SectionInfo.from_elf(elf, name)
        if not sec_info:
            continue
        yield sec_info


def process_symbol(
    sym: ELFSymbol, strtab: StringTableSection, code_secs: list[SectionInfo]
) -> Optional[Symbol]:
    sym_type = sym.entry["st_info"]["type"]
    sym_name = strtab.get_string(sym["st_name"])
    if len(sym_name) == 0:
        return
    if sym_type != "STT_FUNC":
        return
    sec = next(sec for sec in code_secs if sec.index == sym["st_shndx"])
    if not sec:
        return
    # Output
    addr = sym["st_value"]
    size = sym["st_size"]
    return Symbol(addr, sym_name, size)


def symbols_from_elf(elf: ELFFile) -> SymbolsList:
    strtab = elf.get_section_by_name(".strtab")  # String table
    symtab = elf.get_section_by_name(".symtab")  # Symbol table
    code_sections = list(get_code_sections(elf))

    symbols = SymbolsList()

    for elf_sym in symtab.iter_symbols():
        sym = process_symbol(elf_sym, strtab, code_sections)
        if not sym:
            continue
        symbols.put(sym)

    return symbols


def process_elf(elf: ELFFile, out):
    symbols = symbols_from_elf(elf)
    symbols.write_to(out)


def main():
    parser = argparse.ArgumentParser(
        description="Dumps symbols in ELF to symbols.txt format"
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
