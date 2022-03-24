"""
Attempts to detect TU boundaries by looking at zero byte padding between functions.
"""

import argparse
from dataclasses import dataclass
from pathlib import Path
import struct
import sys
from typing import Iterator

from mkwutil.lib.symbols import Symbol, SymbolsList
from mkwutil.lib.dol import DolSegment
from mkwutil.project import read_dol, read_symbol_map


@dataclass
class PaddedSymbol:
    padding: int  # words
    sym: Symbol


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


def main():
    parser = argparse.ArgumentParser(description="TU parser text padding heuristic.")
    parser.parse_args()

    dol = read_dol(Path("./artifacts/orig/pal/main.dol"))
    symbols = read_symbol_map(Path("./pack/symbols.txt"))
    text_segment = dol.segments[DolSegment.NAMES.index("text")]

    scanner = TextPaddingScanner(text_segment, symbols)
    for sym in scanner.scan():
        print("%08x %02x %s" % (sym.sym.addr, sym.padding, sym.sym.name))


if __name__ == "__main__":
    main()
