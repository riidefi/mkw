"""
DOL binary executable parser.
"""

from pathlib import Path
import struct
from typing import Optional


class DolSegment:
    """Describes a DOL segment."""

    def __init__(self, index: int, start: int, stop: int, offset=None):
        assert isinstance(start, int) and isinstance(stop, int)
        assert start <= stop
        self.index = index
        self.start = start
        self.stop = stop
        self.offset = offset
        self.data = None

    # Section names in MKW.
    NAMES = [
        "init",  # 0x00
        "text",  # 0x01
        "",  # 0x02
        "",  # 0x03
        "",  # 0x04
        "",  # 0x05
        "",  # 0x06
        "extab",  # 0x07
        "extabindex",  # 0x08
        "ctors",  # 0x09
        "dtors",  # 0x0a
        "rodata",  # 0x0b
        "data",  # 0x0c
        "sdata",  # 0xd
        "sdata2",  # 0x0e
    ]

    def __repr__(self):
        return "%08x..%08x" % (self.start, self.stop)

    def empty(self):
        """Returns whether the segment is empty."""
        return self.start == self.stop

    def size(self):
        """Returns the length of the segment in bytes."""
        return self.stop - self.start

    def __len__(self):
        return self.size()

    def __contains__(self, key):
        return isinstance(key, int) and self.start <= key < self.stop

    def virtual_read(self, vaddr, size):
        """Returns the bytes at the given virtual address."""
        if self.data is None:
            return None
        assert vaddr in self, f"Virtual address {vaddr} not within segment {self}"
        offset = vaddr - self.start
        assert (
            offset + size <= self.stop
        ), f"Out-of-bounds read: {offset + size} > {self.stop}"
        result = self.data[offset : offset + size]
        assert len(result) == size
        return result

    def name(self):
        if self.index == -1:
            return "bss"
        try:
            return self.NAMES[self.index]
        except IndexError:
            return ""


class DolBinary:
    """Describes a DOL executable."""

    SEGMENT_COUNT = 18

    def __init__(self, file, read_body=True):
        # Open file if path-like.
        if isinstance(file, str) or isinstance(file, Path):
            with open(file, "rb") as file:
                return self.__init__(file, read_body)
        # Read header.
        segment_offsets = list(
            bin[0]
            for bin in struct.iter_unpack(">I", file.read(DolBinary.SEGMENT_COUNT * 4))
        )
        segment_addrs = list(
            bin[0]
            for bin in struct.iter_unpack(">I", file.read(DolBinary.SEGMENT_COUNT * 4))
        )
        segment_lens = list(
            bin[0]
            for bin in struct.iter_unpack(">I", file.read(DolBinary.SEGMENT_COUNT * 4))
        )
        self.segments: list[DolSegment] = []
        for i in range(0, DolBinary.SEGMENT_COUNT):
            self.segments.append(
                DolSegment(
                    i,
                    segment_addrs[i],
                    segment_addrs[i] + segment_lens[i],
                    segment_offsets[i],
                )
            )
        bss_addr, bss_len = struct.unpack(">II", file.read(8))
        self.bss = DolSegment(-1, bss_addr, bss_addr + bss_len)
        self.entry_point = struct.unpack(">I", file.read(4))[0]
        # Determine bounds.
        self.start = min(seg.start for seg in self.segments if len(seg) > 0)
        self.stop = max(seg.stop for seg in self.segments if len(seg) > 0)
        self.stop = max(self.stop, self.bss.stop)
        # Read segment content.
        if read_body:
            for segment in self.segments:
                if len(segment) <= 0:
                    continue
                file.seek(segment.offset)
                segment.data = file.read(segment.size())

    def virtual_read(self, vaddr: int, size: int) -> Optional[bytes]:
        """Returns the bytes at the given virtual address. Must span exactly one segment."""
        segment = next((seg for seg in self.segments if vaddr in seg), None)
        if segment is None:
            return None
        return segment.virtual_read(vaddr, size)

    def virtual_to_rom(self, vaddr: int) -> Optional[int]:
        """Returns the DOL offset given a virtual address."""
        for seg in self.segments:
            if vaddr >= seg.start and vaddr <= seg.stop:
                return seg.offset + (vaddr - seg.start)
        return None
