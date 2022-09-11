"""
Attempts to detect TU boundaries by looking at zero byte padding between functions.
"""

import argparse
from dataclasses import dataclass
from pathlib import Path
import struct
import sys
from typing import Iterable, Iterator

from mkwutil.lib.symbols import Symbol, SymbolsList
from mkwutil.lib.dol import DolSegment
from mkwutil.project import read_dol, read_symbol_map


@dataclass
class PaddedSymbol:
    padding: int  # words
    sym: Symbol

    def __str__(self) -> str:
        return "%08x %02x %s" % (self.sym.addr, self.padding, self.sym.name)


class TextPaddingScanner:
    def __init__(self, segment: DolSegment, symbols: SymbolsList):
        self.segment = segment
        self.symbols = symbols.slice(self.segment.start, self.segment.stop)
        self.pointer = self.segment.start

    def scan(self) -> Iterator[PaddedSymbol]:
        for sym in self.symbols:
            for pad_sym in self._next_symbol(sym):
                yield pad_sym

    def _next_symbol(self, sym: Symbol) -> Iterator[PaddedSymbol]:
        assert self.pointer % 4 == 0
        padding = 0

        while self.pointer < sym.addr:
            # TODO unpack_iter would be faster
            blob = self.segment.virtual_read(self.pointer, 4)
            word = struct.unpack(">I", blob)[0]
            if word == 0:
                padding += 1
            elif padding > 0:
                print(
                    f"WARN: found padding in the middle of a symbol at {hex(self.pointer)}",
                    file=sys.stderr,
                )
                yield PaddedSymbol(padding, sym)
                sym = Symbol(self.pointer, f"unk2_{hex(self.pointer)}")
            self.pointer += 4

        yield PaddedSymbol(padding, sym)


class TextPaddingDumper:
    def __init__(self, iter: Iterable[PaddedSymbol]):
        self.iter = iter

    def dump_all(self):
        for sym in self.iter:
            print(str(sym))

    def dump_short(self):
        self.group = []
        self.padded = False
        for sym in self.iter:
            self._next_sym(sym)
        self._dump_group()

    def _next_sym(self, sym):
        if (sym.padding > 0) != self.padded and len(self.group) > 0:
            self._dump_group()
            self.group = []
            self.padded = sym.padding > 0
        self.group.append(sym)

    def _dump_group(self):
        group = self.group
        if len(group) > 2:
            print(str(group[0]))
            print(f"... (x{len(group)-2})")
            print(str(group[-1]))
        else:
            for sym2 in group:
                print(str(sym2))
        if len(group) > 1:
            print("---")


def main():
    parser = argparse.ArgumentParser(description="TU detect text padding heuristic")
    parser.add_argument("--all", action="store_true", help="Print all")
    args = parser.parse_args()

    dol = read_dol(Path("./artifacts/orig/pal/main.dol"))
    symbols = read_symbol_map(Path("./pack/symbols.yml"))
    text_segment = dol.segments[DolSegment.NAMES.index("text")]

    scanner = TextPaddingScanner(text_segment, symbols)
    dumper = TextPaddingDumper(scanner.scan())
    if args.all:
        dumper.dump_all()
    else:
        dumper.dump_short()


if __name__ == "__main__":
    main()
