from dataclasses import dataclass

from mkwutil.lib.slices import Slice


@dataclass
class Section:
    name: str
    type: str
    start: int
    stop: int

    def __post_init__(self):
        assert self.start <= self.stop

    def size(self) -> int:
        return self.stop - self.start

    def __len__(self) -> int:
        return self.size()

    def __contains__(self, key) -> bool:
        return isinstance(key, int) and self.start <= key < self.stop


DOL_SECTIONS = [
    Section("init", "code", 0x80004000, 0x80006460),
    Section("extab", "data", 0x80006460, 0x80006A20),
    Section("extabindex", "data", 0x80006A20, 0x800072C0),
    Section("text", "code", 0x800072C0, 0x80244DE0),
    Section("ctors", "data", 0x80244DE0, 0x80244E90),
    Section("dtors", "data", 0x80244EA4, 0x80244EAC),
    Section("rodata", "data", 0x80244EC0, 0x80258580),
    Section("data", "data", 0x80258580, 0x802A4040),
    Section("bss", "bss", 0x802A4080, 0x80384C00),
    Section("sdata", "data", 0x80384C00, 0x80385FC0),
    Section("sbss", "bss", 0x80385FC0, 0x80386FA0),
    Section("sdata2", "data", 0x80386FA0, 0x80389140),
    Section("sbss2", "bss", 0x80389140, 0x8038917C),
]

DOL_LIBS = [
    Slice(name="DOL/NW4R", start=0x80021BB0, stop=0x800BBB80, section="text"),
    Slice(name="DOL/RFL", start=0x800BBB80, stop=0x800CC7E4, section="text"),
    Slice(name="DOL/DWC", start=0x800CC7E4, stop=0x800EF378, section="text"),
    Slice(name="DOL/SPY", start=0x800EF378, stop=0x80123F88, section="text"),
    Slice(name="DOL/RVL", start=0x80123F88, stop=0x8020F62C, section="text"),
    Slice(name="DOL/EGG", start=0x8020F62C, stop=0x80244DD4, section="text"),
]

# Virtual (loaded) REL sections.
REL_SECTIONS = [
    Section("text", "code", 0x805103B4, 0x8088F400),
    Section("ctors", "data", 0x8088F400, 0x8088F704),
    Section("dtors", "data", 0x8088F704, 0x8088F710),
    Section("rodata", "data", 0x8088F710, 0x808B2BD0),
    Section("data", "data", 0x808B2BD0, 0x808DD3D4),
    Section("bss", "bss", 0x809BD6E0, 0x809C4F90),
]

# Maps virtual REL section indexes to REL sections in file.
REL_SECTION_IDX = [1, 2, 3, 4, 5, 6]
