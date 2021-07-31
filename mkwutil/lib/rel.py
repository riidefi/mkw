"""
Utility for manipulating rel files.
"""

from collections import OrderedDict
import io
import os
from os import PathLike
from pathlib import Path
import struct
from typing import Optional

REL_BASE = 0x805102E0

read_u32 = lambda f: struct.unpack(">L", f.read(4))[0]
read_u16 = lambda f: struct.unpack(">H", f.read(2))[0]
read_u8 = lambda f: struct.unpack(">B", f.read(1))[0]
read_bool = lambda f: struct.unpack(">?", f.read(1))[0]

write_u32 = lambda d: struct.pack(">L", d)
write_u16 = lambda d: struct.pack(">H", d)
write_u8 = lambda d: struct.pack(">B", d)
write_bool = lambda d: struct.pack(">?", d)


class Rel:
    """Holds a .rel library."""

    def __init__(self, file=None):
        if file is None:
            module_path = Path(__file__).parent
            with open(module_path / "rel_header.bin", "rb") as rel_header:
                self.header = RelHeader(rel_header)
            self.section_info = [RelSection() for i in range(17)]
            self.relocations = [RelRelData(), RelRelData()]
            self.imps = [RelImpEntry(), RelImpEntry()]
            return

        # header
        self.header = RelHeader(file)

        # section info stuff
        self.section_info = [None] * self.header.num_sections
        for i in range(0, self.header.num_sections):
            section = RelSection(file, self.header.section_info_offset, i)
            self.section_info[i] = section

        # dumb way to divide by 8 and keep int
        self.imps = [None] * (self.header.imp_size >> 3)
        for i in range(0, self.header.imp_size >> 3):
            self.imps[i] = RelImpEntry(file, self.header.imp_offset, i)

        # assertion i guess
        assert self.header.rel_offset == self.imps[0].offset

        # relocation data
        self.relocations = [None] * (self.header.imp_size >> 3)
        for i in range(0, self.header.imp_size >> 3):
            self.relocations[i] = RelRelData(file, self.imps[i].offset)

    def reconstruct(self, file):
        rel = io.BytesIO()
        # write temporary header
        rel.write(b"\x41" * 0x4C)
        section_table_offset = rel.tell()

        # write temporary section table entries
        rel.write(b"\x41" * (len(self.section_info) * 0x8))

        # write section data
        section_start_offset = rel.tell()
        offset = 0
        for s in self.section_info:
            if s.exists_in_rel():
                # recalculate offset
                s.offset = offset + section_start_offset
                rel.write(s.data)
                # fuck it this is being hardcoded
                offset += s.length
                if s.length == 0xC:
                    rel.write(b"\0" * 0x10)
                    offset += 0x10

        section_end_offset = rel.tell()

        # write section info table
        rel.seek(section_table_offset, os.SEEK_SET)
        for s in self.section_info:
            rel.write(s.reconstruct_table_entry())

        # write temporary imp table
        rel.seek(0, os.SEEK_END)
        rel.write(b"\x41" * (len(self.imps) * 8))

        relocation_offsets = []
        # write relocation data
        for r in self.relocations:
            relocation_offsets.append(rel.tell())
            r.reconstruct(rel)

        # write imp data
        rel.seek(section_end_offset, os.SEEK_SET)
        for i, r in enumerate(relocation_offsets):
            rel.write(write_u32(1 - i))  # module id (hacky)
            rel.write(write_u32(r))  # offset

        # finally, the header
        # write new values with inconsistent names
        self.header.num_sections = len(self.section_info)
        self.header.section_info_offset = section_table_offset
        self.header.rel_offset = relocation_offsets[0]
        self.header.imp_offset = section_end_offset
        self.header.imp_size = len(self.imps) * 8

        header = self.header.reconstruct()
        rel.seek(0, os.SEEK_SET)
        rel.write(header)

        # write to file
        file.write(rel.getbuffer())

    def dump_reloc(self, index, file):
        """Dumps a relocation to the provided file."""
        rel = io.BytesIO()
        self.relocations[index].reconstruct(rel)

        with open(file, "wb") as file:
            file.write(rel.getbuffer())

    def load_reloc(self, index, file):
        """Loads a relocation from the provided file."""
        with open(file, "rb") as file:
            self.relocations[index] = RelRelData(file, 0)

    def dump_section(self, index, file):
        """Dumps a section to the provided file."""
        s = self.section_info[index]
        if s.offset != 0:
            data = s.data
        else:
            data = b"\0" * s.length

        with open(file, "wb") as file:
            file.write(data)

    def load_section(self, index, file):
        """Loads a section from the provided file."""
        s = RelSection()
        s.data = file.read()
        s.length = len(s.data)
        self.section_info[index] = s

    def virtual_read(
        self, vaddr: int, size: int, sections, section_idx
    ) -> Optional[bytes]:
        # Find the virtual address section where vaddr falls into.
        section_virtual_idx, section_virtual = next(
            (seg for seg in enumerate(sections) if vaddr in seg[1]), None
        )
        # Map to REL section number.
        section_idx = section_idx[section_virtual_idx]
        # Calculate addres.
        relative_addr = vaddr - section_virtual.start
        result = self.section_info[section_idx].data[
            relative_addr : relative_addr + size
        ]
        if len(result) == size:
            return result

        assert size >= len(result)
        print("Warning: Size %s exceeds section size %s" % (size, len(result)))

        return result + bytes(size - len(result))


class RelHeader:
    """Holds a .rel header."""

    def __init__(self, file):
        file.seek(0, os.SEEK_SET)  # just in case
        # unpack header
        self.rel_id = read_u32(file)
        self.next = read_u32(file)
        self.prev = read_u32(file)
        self.num_sections = read_u32(file)
        self.section_info_offset = read_u32(file)
        self.name_offset = read_u32(file)
        self.name_size = read_u32(file)
        self.version = read_u32(file)
        self.bss_size = read_u32(file)
        self.rel_offset = read_u32(file)
        self.imp_offset = read_u32(file)
        self.imp_size = read_u32(file)
        self.prolog_section = read_bool(file)
        self.epilog_section = read_bool(file)
        self.unresolved_section = read_bool(file)
        self.bss_section = read_bool(file)
        self.prolog = read_u32(file)
        self.epilog = read_u32(file)
        self.unresolved = read_u32(file)
        if self.version >= 2:
            self.align = read_u32(file)
            self.bss_align = read_u32(file)
        if self.version >= 3:
            self.fix_size = read_u32(file)

    def reconstruct(self):
        """Writes a .rel header"""
        header = io.BytesIO()
        header.write(write_u32(self.rel_id))
        header.write(write_u32(self.next))
        header.write(write_u32(self.prev))
        header.write(write_u32(self.num_sections))
        header.write(write_u32(self.section_info_offset))
        header.write(write_u32(self.name_offset))
        header.write(write_u32(self.name_size))
        header.write(write_u32(self.version))
        header.write(write_u32(self.bss_size))
        header.write(write_u32(self.rel_offset))
        header.write(write_u32(self.imp_offset))
        header.write(write_u32(self.imp_size))
        header.write(write_bool(self.prolog_section))
        header.write(write_bool(self.epilog_section))
        header.write(write_bool(self.unresolved_section))
        header.write(write_bool(self.bss_section))
        header.write(write_u32(self.prolog))
        header.write(write_u32(self.epilog))
        header.write(write_u32(self.unresolved))
        header.write(write_u32(self.align))
        header.write(write_u32(self.bss_align))
        header.write(write_u32(self.fix_size))
        return header.getvalue()


class RelSection:
    def __init__(self, f=None, section_info_offset=None, sid=None):
        if f is None:
            self.offset = 0
            self.unk = False
            self.executable = False
            self.length = 0
            self.data = None
            return

        # get the section stuff
        f.seek(section_info_offset + (sid * 0x8), os.SEEK_SET)
        self.offset = read_u32(f)
        # dumb
        self.unk = self.offset & 2
        self.executable = self.offset & 1
        self.offset &= ~3
        self.length = read_u32(f)

        # data
        # skip empty shit and bss
        print(
            f"section {sid}: {self.offset:X} {self.executable} {self.unk:X} {self.length:X}"
        )
        if self.offset == 0 or self.length == 0:
            return

        f.seek(self.offset, os.SEEK_SET)
        self.data = f.read(self.length)

    def exists_in_rel(self):
        return self.offset != 0 and self.length != 0

    def reconstruct_table_entry(self):
        # recalculate length
        if self.offset != 0:
            self.length = len(self.data)

        entry = io.BytesIO()
        word = self.offset | (self.unk << 1) | self.executable
        entry.write(write_u32(word))
        entry.write(write_u32(self.length))
        return entry.getvalue()


class RelImpEntry:
    def __init__(self, f=None, imp_offset=None, sid=None):
        if f is None:
            self.module_id = 0
            self.offset = 0
            return

        # does a thing
        f.seek(imp_offset + (sid * 8), os.SEEK_SET)
        self.module_id = read_u32(f)
        self.offset = read_u32(f)
        print(f"imp {sid}: {self.module_id:X} {self.offset:X}")


# funny name
class RelRelData:
    def __init__(self, f=None, rel_offset=None):
        if f is None:
            self.entries = OrderedDict()
            return

        f.seek(rel_offset, os.SEEK_SET)
        self.entries = OrderedDict()

        counter = 0
        section = 0
        while True:
            entry = RelRelEntry(f)

            # R_RVL_SECT
            if entry.type == 202:
                # print("R_RVL_SECT", counter, entry.section)
                section = entry.section
                self.entries[section] = []
                continue

            self.entries[section].append(entry)

            # R_RVL_STOP
            if entry.type == 203:
                # print("R_RVL_STOP")
                break

            counter += 1

    def reconstruct(self, file):
        for entry_bin in self.entries:
            # write R_RVL_SECT
            file.write(struct.pack(">HBB", 0, 202, entry_bin))  # section id

            # write R_RVL_NOP
            file.write(b"\0" * 4)

            # write actual entries
            for inner_entry_bin in self.entries[entry_bin]:
                entry = inner_entry_bin.reconstruct()
                file.write(entry)


class RelRelEntry:
    def __init__(self, f):
        data = f.read(struct.calcsize(">HBBL"))
        self.offset, self.type, self.section, self.addend = struct.unpack(">HBBL", data)

    def reconstruct(self):
        return struct.pack(">HBBL", self.offset, self.type, self.section, self.addend)


def dump_staticr(rel: Rel, _path: Path) -> None:
    rel.dump_reloc(0, _path / "dol_rel.bin")
    rel.dump_reloc(1, _path / "rel_abs.bin")

    rel.dump_section(1, _path / "text.bin")
    rel.dump_section(2, _path / "ctors.bin")
    rel.dump_section(3, _path / "dtors.bin")
    rel.dump_section(4, _path / "rodata.bin")
    rel.dump_section(5, _path / "data.bin")
    rel.dump_section(6, _path / "bss.bin")


def reconstruct_staticr(path):
    _path = Path(path)
    rel = Rel()

    rel.load_reloc(0, _path / "dol_rel.bin")
    rel.load_reloc(1, _path / "rel_abs.bin")

    rel.load_section(1, _path / "text.bin")
    rel.load_section(2, _path / "ctors.bin")
    rel.load_section(3, _path / "dtors.bin")
    rel.load_section(4, _path / "rodata.bin")
    rel.load_section(5, _path / "data.bin")
    rel.load_section(6, _path / "bss.bin")

    rel.section_info[1].executable = True
    rel.section_info[1].offset = 0xD4
    rel.section_info[2].offset = 0x37F120
    rel.section_info[3].offset = 0x37F424
    rel.section_info[4].offset = 0x37F440
    rel.section_info[5].offset = 0x3A28F0
    rel.section_info[6].offset = 0

    rel.imps[0].module_id = 1
    rel.imps[0].offset = 0x3CD104
    rel.imps[1].module_id = 0
    rel.imps[1].offset = 0x4820F4

    return rel
