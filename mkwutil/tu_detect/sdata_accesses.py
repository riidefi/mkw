"""
Attempts to detect TU boundaries by looking at sdata access patterns.
"""

import argparse
from dataclasses import dataclass, field
from pathlib import Path
from re import I
import struct
import sys
from typing import Optional, Iterable, Iterator

from mkwutil.lib.dol import DolBinary, DolSegment
from mkwutil.project import read_dol


@dataclass
class SdataAccess:
    """An instruction in the text section referencing sdata."""

    at: int  # text address
    target: int  # sdata address
    size: int = 4  # size of access

    def __str__(self) -> str:
        return "%08x %08x" % (self.target, self.at)


@dataclass
class SdataSite:
    """An word/dword in sdata."""

    at: int  # sdata address
    refs: set[int] = field(
        default_factory=lambda: set()
    )  # text addresses creating incoming refs
    value: Optional[int] = None  # default value (None for sbss)
    size: Optional[int] = None  # size of value stored

    def add(self, access: SdataAccess):
        """Adds an incoming reference."""
        if self.size is not None and self.size != access.size:
            print("WARN: access size mismatch", file=sys.stderr)
            self.size = 4
        else:
            self.size = access.size
        self.refs.add(access.at)

    def read_from(self, bin: DolBinary):
        """Reads the value from the DOL."""
        if self.size == 8:
            self.value = bin.virtual_read_dword(self.at)
        else:
            self.value = bin.virtual_read_word(self.at)

    def __str__(self) -> str:
        """Human-readable representation."""
        if self.value is None:
            value_str = "????????"
        elif self.size == 8:
            value_str = "%016x" % (self.value)
        else:
            value_str = "%08x" % (self.value) + " " * 8
        if len(self.refs) > 0:
            ret = "%08x %s % 4d %08x..%08x" % (
                self.at,
                value_str,
                len(self.refs),
                min(self.refs),
                max(self.refs),
            )
        else:
            ret = "%08x %s" % (self.at, value_str)
        return ret

    def __lt__(self, other) -> bool:
        return self.at < other.at


class SdataAccessScanner:
    """Scans the text section for sdata accesses."""

    R2 = 0x8038EFA0
    R13 = 0x8038CC00

    def __init__(self, segment: DolSegment):
        self.segment = segment
        self.pointer = self.segment.start

    def scan(self) -> Iterator[SdataAccess]:
        """Iterates through the text section, yielding any SdataAccesses."""
        while self.pointer < self.segment.stop:
            access = self._next()
            if access is not None:
                yield access

    def _next(self) -> Optional[SdataAccess]:
        """Reads the next instruction."""
        assert self.pointer % 4 == 0
        at = self.pointer
        self.pointer += 4
        blob = self.segment.virtual_read(at, 4)
        word = struct.unpack(">I", blob)[0]

        if word >> 26 in (32, 34, 36, 38, 40, 44, 48, 52):
            # lwz, lbz, stw, stb, lhz, sth, lfs, stfs opcodes
            access_size = 4
        elif word >> 26 in (50, 54):
            # lfd, stfd opcodes
            access_size = 8
        else:
            return
        # r2 or r13
        rT = word >> 16 & 0b11111
        if rT == 2:
            base = SdataAccessScanner.R2
        elif rT == 13:
            base = SdataAccessScanner.R13
        else:
            return
        # offset
        offset_uimm = word & 0xFFFF
        offset = struct.unpack(">h", struct.pack(">H", (offset_uimm)))[0]
        offset = offset & ~3

        return SdataAccess(at, base + offset, size=access_size)


class SdataAccessIndexer:
    """Indexes SdataAccesses by sdata address."""

    def __init__(self):
        self.sites = dict()

    def add(self, access: SdataAccess):
        site: SdataSite = self.sites.setdefault(access.target, SdataSite(access.target))
        site.add(access)

    def linear_pass(self, dol: DolBinary) -> Iterator[SdataAccess]:
        last = None
        for site in sorted(self.sites.values()):
            if site.at >= 0x80389140:
                break
            site.read_from(dol)
            # Fill gaps.
            if last is None:
                last = site.at
            while last < site.at:
                assert last % 4 == 0
                last += 4
                if last + (site.size or 4) < site.at:
                    yield SdataSite(at=last, value=dol.virtual_read_word(last))
            yield site


@dataclass
class Sdata2TU:
    """An estimated translation unit."""

    sdata_min: int
    sdata_max: int
    text_min: int
    text_max: int

    def __str__(self) -> str:
        return "%08x..%08x %08x..%08x" % (
            self.sdata_min,
            self.sdata_max,
            self.text_min,
            self.text_max,
        )


class Sdata2TUDetector:
    """Scans indexed sdata2 for likely TU boundaries.
    Implemented internally with a state machine that accumulates TUs and flushes them when conditions are met."""

    def __init__(self, sites: Iterable[SdataSite]):
        self.sites = sites

    def _reset_tu(self):
        self.tu = []
        self.vals = set()
        self.found_padding = False

    def run(self) -> Iterator[Sdata2TU]:
        self._reset_tu()
        # Scan over sdata.
        for site in self.sites:
            if site.at < 0x80386FA0:
                continue
            # If the last element was padding, finish TU.
            if self.found_padding:
                self._next_tu()
            # Next sdata field.
            tu = self._next_site(site)
            if tu is not None:
                yield tu
        # Last sdata field.
        tu = self._next_site(site)
        if tu is not None:
            yield tu

    def tu_spread(sites) -> tuple[int, int]:
        """Returns the min and max text instruction addresses referring to the sdata TU."""
        min_ref = 0xFFFF_FFFF_FFFF_FFFF
        max_ref = 0
        for site in sites:
            for ref in site.refs:
                min_ref = min(min_ref, ref)
                max_ref = max(max_ref, ref)
        return min_ref, max_ref + 4

    def _dump_tu(self) -> Optional[Sdata2TU]:
        if len(self.tu) == 0:
            return
        text_min, text_max = Sdata2TUDetector.tu_spread(self.tu)
        if text_max == 0:
            return
        return Sdata2TU(self.tu[0].at, self.tu[-1].at, text_min, text_max)

    def _next_tu(self) -> Optional[Sdata2TU]:
        tu = self._dump_tu()
        self._reset_tu()
        return tu

    def _next_site(self, site: SdataSite) -> Optional[Sdata2TU]:
        tu = None
        if site.value in self.vals:
            if site.value == 0 and len(site.refs) == 0 and site.at % 8 == 4:
                self.found_padding = True
                return
            tu = self._next_tu()
        self.vals.add(site.value)
        self.tu.append(site)
        return tu


def main():
    parser = argparse.ArgumentParser(description="TU detect text padding heuristic")
    parser.add_argument("--all", action="store_true", help="Print all")
    args = parser.parse_args()

    dol = read_dol(Path("./artifacts/orig/pal/main.dol"))
    text_segment = dol.segments[DolSegment.NAMES.index("text")]

    # Linear pass over text section for xrefs and index them by sdata address.
    scanner = SdataAccessScanner(text_segment)
    indexer = SdataAccessIndexer()
    for access in scanner.scan():
        indexer.add(access)

    # Linear pass over sdata section.
    sites = list(indexer.linear_pass(dol))
    for site in sites:
        print(site)
    print()

    # sdata2 section detect
    detector = Sdata2TUDetector(sites)
    for tu in detector.run():
        print(tu)


if __name__ == "__main__":
    main()
