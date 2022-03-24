"""
Attempts to detect TU boundaries by looking at zero byte padding between functions.
"""

import argparse
from dataclasses import dataclass
from pathlib import Path
import struct
from typing import Optional, Iterator

from mkwutil.lib.dol import DolSegment
from mkwutil.project import read_dol


@dataclass
class SdataAccess:
    at: int
    target: int

    def __str__(self) -> str:
        return "%08x %08x" % (self.target, self.at)


class SdataAccessScanner:
    R2 = 0x8038EFA0
    R13 = 0x8038CC00

    def __init__(self, segment: DolSegment):
        self.segment = segment
        self.pointer = self.segment.start

    def scan(self) -> Iterator[SdataAccess]:
        while self.pointer < self.segment.stop:
            access = self._next()
            if access is not None:
                yield access

    def _next(self) -> Optional[SdataAccess]:
        assert self.pointer % 4 == 0
        at = self.pointer
        self.pointer += 4
        blob = self.segment.virtual_read(at, 4)
        word = struct.unpack(">I", blob)[0]

        # lwz opcode
        if word >> 26 != 32:
            return
        # r2 or r13
        rT = word >> 16 & 0b11111
        if rT == 2:
            base = SdataAccessScanner.R2
        elif rT == 13:
            base = SdataAccessScanner.R13
        else:
            return
        offset_uimm = word & 0xFFFF
        offset = struct.unpack(">h", struct.pack(">H", (offset_uimm)))[0]

        access = SdataAccess(at, base + offset)
        print(access)


def main():
    parser = argparse.ArgumentParser(description="TU detect text padding heuristic")
    parser.add_argument("--all", action="store_true", help="Print all")
    args = parser.parse_args()

    dol = read_dol(Path("./artifacts/orig/pal/main.dol"))
    text_segment = dol.segments[DolSegment.NAMES.index("text")]

    scanner = SdataAccessScanner(text_segment)
    list(scanner.scan())


if __name__ == "__main__":
    main()
