import io
import os
import struct
import sys
from collections import OrderedDict

# Change directory to script folder to make relative repo paths work.
os.chdir(sys.path[0])

REL_BASE = 0x805102e0

ul = lambda f : struct.unpack(">L", f.read(4))[0]
us = lambda f : struct.unpack(">H", f.read(2))[0]
uc = lambda f : struct.unpack(">B", f.read(1))[0]
ubool = lambda f : struct.unpack(">?", f.read(1))[0]

pl = lambda d : struct.pack(">L", d)
ps = lambda d : struct.pack(">H", d)
pc = lambda d : struct.pack(">B", d)
pbool = lambda d : struct.pack(">?", d)

def hprint(val):
    print(hex(val))


def src_artifact(file):
    return os.path.join("../artifacts/pal/", file)

def rel_component(file):
    return os.path.join("../tmp/", file)

class Rel:
    def __init__(self, filename=None):
        if filename is None:
            with open("rel_header.bin", "rb") as f:
                self.header = RelHeader(f)
            self.sectionInfo = [RelSection() for i in range(17)]
            self.relocations = [RelRelData(), RelRelData()]
            self.imps = [RelImpEntry(), RelImpEntry()]
            return

        with open(filename, "rb") as f:
            # header
            self.header = RelHeader(f)

            # section info stuff
            self.sectionInfo = [None] * self.header.numSections
            for i in range (0, self.header.numSections):
                section = RelSection(f, self.header.sectionInfoOffset, i)
                self.sectionInfo[i] = section

            # dumb way to divide by 8 and keep int
            self.imps = [None] * (self.header.impSize >> 3)
            for i in range(0, self.header.impSize >> 3):
                self.imps[i] = RelImpEntry(f, self.header.impOffset, i)

            # assertion i guess
            assert(self.header.relOffset == self.imps[0].offset)

            # relocation data
            self.relocations = [None] * (self.header.impSize >> 3)
            for i in range(0, self.header.impSize >> 3):
                self.relocations[i] = RelRelData(f, self.imps[i].offset)

    def reconstruct(self, filename):
        rel = io.BytesIO()
        # write temporary header
        rel.write(b'\x41' * 0x4C)
        sectionTableOffset = rel.tell()

        # write temporary section table entries
        rel.write( b'\x41' * (len(self.sectionInfo) * 0x8) )

        # write section data
        sectionStartOffset = rel.tell()
        offset = 0
        for s in self.sectionInfo:
            if s.existsInRel():
                # recalculate offset
                s.offset = offset + sectionStartOffset
                rel.write( s.data )
                # fuck it this is being hardcoded
                offset += s.length
                if s.length == 0xC:
                    rel.write(b'\0' * 0x10)
                    offset += 0x10

        sectionEndOffset = rel.tell()

        # write section info table
        rel.seek(sectionTableOffset, os.SEEK_SET)
        for s in self.sectionInfo:
            rel.write( s.reconstructTableEntry() )

        # write temporary imp table
        rel.seek(0, os.SEEK_END)
        rel.write( b'\x41' * (len(self.imps) * 8))

        relocationOffsets = []
        # write relocation data
        for r in self.relocations:
            relocationOffsets.append(rel.tell())
            r.reconstruct(rel)

        # write imp data
        rel.seek(sectionEndOffset, os.SEEK_SET)
        for i, r in enumerate(relocationOffsets):
            rel.write( pl(1 - i) ) # module id (hacky)
            rel.write( pl(r) ) # offset

        # finally, the header
        # write new values with inconsistent names
        self.header.numSections = len(self.sectionInfo)
        self.header.sectionInfoOffset = sectionTableOffset
        self.header.relOffset = relocationOffsets[0]
        self.header.impOffset = sectionEndOffset
        self.impSize = len(self.imps) * 8

        header = self.header.reconstruct()        
        rel.seek(0, os.SEEK_SET)
        rel.write(header)

        # write to file
        with open(filename, "wb") as f:
            f.write(rel.getbuffer())
    
    def dump_reloc(self, index, filename):
        rel = io.BytesIO()
        self.relocations[index].reconstruct(rel)

        with open(filename, "wb") as f:
            f.write(rel.getbuffer())
    
    def load_reloc(self, index, filename):
        with open(filename, "rb") as f:
            self.relocations[index] = RelRelData(f, 0)

    def dump_section(self, index, filename):
        with open(filename, "wb") as f:
            s = self.sectionInfo[index]
            if s.offset != 0:
                f.write(s.data)
            else:
                f.write(b'\0' * s.length)

    def load_section(self, index, filename):
        with open(filename, "rb") as f:
            s = RelSection()
            s.data = f.read()
            s.length = len(s.data)
            self.sectionInfo[index] = s



class RelHeader:
    def __init__(self, f):
        f.seek(0, os.SEEK_SET) # just in case
        # unpack header
        self.id = ul(f)
        self.next = ul(f)
        self.prev = ul(f)
        self.numSections = ul(f)
        self.sectionInfoOffset = ul(f)
        self.nameOffset = ul(f)
        self.nameSize = ul(f)
        self.version = ul(f)
        self.bssSize = ul(f)
        self.relOffset = ul(f)
        self.impOffset = ul(f)
        self.impSize = ul(f)
        self.prologSection = ubool(f)
        self.epilogSection = ubool(f)
        self.unresolvedSection = ubool(f)
        self.bssSection = ubool(f)
        self.prolog = ul(f)
        self.epilog = ul(f)
        self.unresolved = ul(f)
        if self.version >= 2:
            self.align = ul(f)
            self.bssAlign = ul(f)
        if self.version >= 3:
            self.fixSize = ul(f)

    def reconstruct(self):
        header = io.BytesIO()
        header.write(pl(self.id))
        header.write(pl(self.next))
        header.write(pl(self.prev))
        header.write(pl(self.numSections))
        header.write(pl(self.sectionInfoOffset))
        header.write(pl(self.nameOffset))
        header.write(pl(self.nameSize))
        header.write(pl(self.version))
        header.write(pl(self.bssSize))
        header.write(pl(self.relOffset))
        header.write(pl(self.impOffset))
        header.write(pl(self.impSize))
        header.write(pbool(self.prologSection))
        header.write(pbool(self.epilogSection))
        header.write(pbool(self.unresolvedSection))
        header.write(pbool(self.bssSection))
        header.write(pl(self.prolog))
        header.write(pl(self.epilog))
        header.write(pl(self.unresolved))
        header.write(pl(self.align))
        header.write(pl(self.bssAlign))
        header.write(pl(self.fixSize))
        return header.getvalue()



class RelSection:
    def __init__(self, f=None, sectionInfoOffset=None, sid=None):
        if f is None:
            self.offset = 0
            self.unk = False
            self.executable = False
            self.length = 0
            self.data = None
            return

        # get the section stuff
        f.seek(sectionInfoOffset + (sid * 0x8), os.SEEK_SET)
        self.offset = ul(f)
        # dumb
        self.unk = self.offset & 2
        self.executable = self.offset & 1
        self.offset &= ~3
        self.length = ul(f)

        # data
        # skip empty shit and bss
        print(f"section {sid}: {self.offset:X} {self.executable} {self.unk:X} {self.length:X}")
        if self.offset == 0 or self.length == 0:
            return

        f.seek(self.offset, os.SEEK_SET)
        self.data = f.read(self.length)

    def existsInRel(self):
        return (self.offset != 0 and self.length != 0)

    def reconstructTableEntry(self):
        # recalculate length
        if self.offset != 0:
            self.length = len(self.data)

        entry = io.BytesIO()
        word = self.offset | (self.unk << 1) | self.executable
        entry.write( pl(word) )
        entry.write( pl(self.length) )
        return entry.getvalue()


class RelImpEntry:
    def __init__(self, f=None, impOffset=None, sid=None):
        if f is None:
            self.moduleId = 0
            self.offset = 0
            return

        # does a thing
        f.seek(impOffset + (sid * 8), os.SEEK_SET)
        self.moduleId = ul(f)
        self.offset = ul(f)
        print(f"imp {sid}: {self.moduleId:X} {self.offset:X}")

# funny name
class RelRelData:
    def __init__(self, f=None, relOffset=None):
        if f is None:
            self.entries = OrderedDict()
            return

        f.seek(relOffset, os.SEEK_SET)
        self.entries = OrderedDict()

        counter = 0
        section = 0
        while True:
            entry = RelRelEntry(f)

            #R_RVL_SECT
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

    def reconstruct(self, f):
        for e in self.entries:
            # write R_RVL_SECT
            f.write( ps(0) )
            f.write( pc(202) )
            f.write( pc(e) ) # section id

            # write R_RVL_NOP
            f.write( b'\0' * 4 )

            # write actual entries
            for ee in self.entries[e]:
                entry = ee.reconstruct()
                f.write(entry)


class RelRelEntry:
    def __init__(self, f):
        self.offset = us(f)
        self.type = uc(f)
        self.section = uc(f)
        self.addend = ul(f)

    def reconstruct(self):
        entry = io.BytesIO()
        entry.write( ps(self.offset) )
        entry.write( pc(self.type) )
        entry.write( pc(self.section) )
        entry.write( pl(self.addend) )
        return entry.getvalue()


def DumpStaticR():
    rel = Rel(src_artifact("StaticR.rel"))
    
    rel.dump_reloc(0, "dol_rel.bin")
    rel.dump_reloc(1, "rel_abs.bin")

    rel.dump_section(1, rel_component("text.bin"))
    rel.dump_section(2, rel_component("ctors.bin"))
    rel.dump_section(3, rel_component("dtors.bin"))
    rel.dump_section(4, rel_component("rodata.bin"))
    rel.dump_section(5, rel_component("data.bin"))
    rel.dump_section(6, rel_component("bss.bin"))



def ReconstructStaticR():
    rel = Rel()

    rel.load_reloc(0, "dol_rel.bin")
    rel.load_reloc(1, "rel_abs.bin")

    rel.load_section(1, rel_component("text.bin"))
    rel.load_section(2, rel_component("ctors.bin"))
    rel.load_section(3, rel_component("dtors.bin"))
    rel.load_section(4, rel_component("rodata.bin"))
    rel.load_section(5, rel_component("data.bin"))
    rel.load_section(6, rel_component("bss.bin"))

    rel.sectionInfo[1].executable = True
    rel.sectionInfo[1].offset = 0xD4
    rel.sectionInfo[2].offset = 0x37F120
    rel.sectionInfo[3].offset = 0x37F424
    rel.sectionInfo[4].offset = 0x37F440
    rel.sectionInfo[5].offset = 0x3A28F0
    rel.sectionInfo[6].offset = 0
    
    rel.imps[0].moduleId = 1
    rel.imps[0].offset = 0x3CD104
    rel.imps[1].moduleId = 0
    rel.imps[1].offset = 0x4820F4

    rel.reconstruct("../target/StaticR.rel")

if __name__ == "__main__":
    DumpStaticR()
    ReconstructStaticR()
    
