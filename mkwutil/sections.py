class Section:
    def __init__(self, name, type, start, stop):
        self.name = name
        self.type = type
        assert start <= stop
        self.start = start
        self.stop = stop

    def size(self):
        return self.stop - self.start

    def __len__(self):
        return self.size()

    def __contains__(self, key):
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
