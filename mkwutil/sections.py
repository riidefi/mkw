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
    Section("dtors", "data", 0x80244EA0, 0x80244EAC),
    Section("rodata", "data", 0x80244EC0, 0x80258580),
    Section("data", "data", 0x80258580, 0x802A4040),
    Section("bss", "bss", 0x802A4080, 0x80384C00),
    Section("sdata", "data", 0x80384C00, 0x80385FC0),
    Section("sbss", "bss", 0x80385FC0, 0x80386FA0),
    Section("sdata2", "data", 0x80386FA0, 0x80389140),
    Section("sbss2", "bss", 0x80389140, 0x8038917C),
]

DOL_LIBS = [
    Slice(name="DOL/NW4R/DB", start=0x80021BB0, stop=0x80026220, section="text"),
    Slice(name="DOL/NW4R/EF", start=0x80026220, stop=0x8004BD30, section="text"),
    Slice(name="DOL/NW4R/G3D", start=0x8004BD30, stop=0x80078920, section="text"),
    Slice(name="DOL/NW4R/LYT", start=0x80078920, stop=0x80084F00, section="text"),
    Slice(name="DOL/NW4R/MATH", start=0x80084F00, stop=0x80086920, section="text"),
    Slice(name="DOL/NW4R/SND", start=0x80086920, stop=0x800AEF60, section="text"),
    Slice(name="DOL/NW4R/UT", start=0x800AEF60, stop=0x800BBB80, section="text"),
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
    Section("rodata", "data", 0x8088F720, 0x808B2BD0),
    Section("data", "data", 0x808B2BD0, 0x808DD3D4),
    Section("bss", "bss", 0x809BD6E0, 0x809C4F90),
]

# Maps virtual REL section indexes to REL sections in file.
REL_SECTION_IDX = [1, 2, 3, 4, 5, 6]

REL_DIRS = [
    Slice(name="REL/SYSTEM", start=0x805103B4, stop=0x80553788, section="text"),
    Slice(name="REL/SCENE", start=0x80553788, stop=0x8055531C, section="text"),
    Slice(name="REL/KART", start=0x805672CC, stop=0x805B9010, section="text"),
    Slice(name="REL/UI", start=0x805B9300, stop=0x80653208, section="text"),
    Slice(name="REL/NET", start=0x80653208, stop=0x8067B318, section="text"),
    Slice(name="REL/GEO/0", start=0x8067E280, stop=0x8068CEDC, section="text"),
    Slice(name="REL/GEO/1", start=0x806B70D0, stop=0x806F62FC, section="text"),
    Slice(name="REL/SND", start=0x806F62FC, stop=0x8071B808, section="text"),
    Slice(name="REL/AI", start=0x80725FDC, stop=0x8074BB34, section="text"),
    Slice(name="REL/GEO/2", start=0x807519C8, stop=0x8077EE80, section="text"),
    Slice(name="REL/ITEM", start=0x8079754C, stop=0x807BD1D0, section="text"),
    Slice(name="REL/UI/CTRL", start=0x807E093C, stop=0x807F9278, section="text"),
    Slice(name="REL/GEO/3", start=0x807F9278, stop=0x8081A690, section="text"),
    Slice(name="REL/GEO", start=0x8081A690, stop=0x8082F3C8, section="text"),
    Slice(name="REL/UI/PAGE", start=0x80836B9C, stop=0x8085FFD4, section="text"),
    Slice(name="REL/GEO/4", start=0x8086AC20, stop=0x8088BE00, section="text"),
]
