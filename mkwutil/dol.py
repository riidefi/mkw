import struct


read_u32 = lambda f: struct.unpack(">L", f.read(4))[0]
read_u16 = lambda f: struct.unpack(">H", f.read(2))[0]
read_u8 = lambda f: struct.unpack(">B", f.read(1))[0]


class Segment:
    """Describes a DOL segment."""

    def __init__(self, begin: int, end: int):
        assert isinstance(begin, int) and isinstance(end, int)
        self.begin = begin
        self.end = end

    def __repr__(self):
        return "(%s, %s)" % (hex(self.begin), hex(self.end))

    def empty(self):
        return self.begin == self.end

    def size(self):
        return self.end - self.begin


class DolBinary:
    """Describes a DOL executable."""

    def __init__(self, file):
        file = open(file, "rb")
        text_ofs = [read_u32(file) for _ in range(7)]
        data_ofs = [read_u32(file) for _ in range(11)]

        text_vaddr = [read_u32(file) for _ in range(7)]
        data_vaddr = [read_u32(file) for _ in range(11)]

        self.text_size = [read_u32(file) for _ in range(7)]
        self.data_size = [read_u32(file) for _ in range(11)]

        self.text_segs = [Segment(x, x + y) for x, y in zip(text_vaddr, self.text_size)]
        self.data_segs = [Segment(x, x + y) for x, y in zip(data_vaddr, self.data_size)]

        bss_vaddr = read_u32(file)
        bss_size = read_u32(file)

        self.bss = Segment(bss_vaddr, bss_vaddr + bss_size)

        self.entry_point = read_u32(file)

        max_vaddr = max(x.end for x in self.text_segs + self.data_segs)
        self.image_base = 0x80000000
        self.image = bytearray(max_vaddr - self.image_base)

        for i in range(7):
            if not self.text_size[i]:
                continue
            file.seek(text_ofs[i])
            offset = text_vaddr[i] - self.image_base
            self.image[offset : offset + self.text_size[i]] = file.read(
                self.text_size[i]
            )

        for i in range(11):
            if not self.data_size[i]:
                continue
            file.seek(data_ofs[i])
            offset = data_vaddr[i] - self.image_base
            self.image[offset : offset + self.data_size[i]] = file.read(
                self.data_size[i]
            )

    def get_text_segment(self, num):
        """Reads the binary content of a text segment."""
        offset = self.text_segs[num].begin - self.image_base
        return self.image[offset : offset + self.text_size[num]]

    def get_data_segment(self, num):
        """Reads the binary content of a data segment."""
        offset = self.data_segs[num].begin - self.image_base
        return self.image[offset : offset + self.data_size[num]]
