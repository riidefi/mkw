import struct


def read_u8(f):
    return struct.unpack("B", f.read(1))[0]

def read_u32(f):
    return struct.unpack(">I", f.read(4))[0]

def read_u16(f):
    return struct.unpack(">H", f.read(2))[0]

class CSV:
    def __init__(self, name):
        lines = open(name).readlines()
        self.header = lines[0].strip().split(',')
        self.body = [x.strip().split(',') for x in lines[1:]]

    def get_row(self, index):
        row = {}
        for i, value in enumerate(self.body[index]):
            label = self.header[i]
            row[label] = value
        return row

    def rows(self):
        for i in range(len(self.body)):
            yield self.get_row(i)

class Segment:
    def __init__(self, begin : int, end : int):
        assert isinstance(begin, int) and isinstance(end, int)
        self.begin = begin
        self.end = end

    def __repr__(self):
        return "(%s, %s)" % (hex(self.begin), hex(self.end))

    def empty(self):
        return self.begin == self.end

    def size(self):
        return self.end - self.begin

def read_segments_iter(name):
    for row in CSV(name).rows():
        yield row["name"], Segment(int(row["start"], 16), int(row["end"], 16))

def read_segments(name):
    result = {}
    for name, segment in read_segments_iter(name):
        result[name] = segment
    return result

# Limitation: slices must be ordered
def read_slices(name):
    result = []
    for row in CSV(name).rows():
        if not row.pop("enabled"):
            continue
        
        name = row.pop("name")
        segments = {}

        for cell, value in row.items():
            segment_attributes = ["Start", "End"]
            seg_name = ""
            seg_type = ""
            for attr in segment_attributes:
                if cell.endswith(attr):
                    seg_type = attr
                    seg_name = cell[:-len(attr)]
            assert seg_name and seg_type

            if not value: continue

            if not seg_name in segments:
                segments[seg_name] = Segment(0, 0)

            if seg_type == "Start":
                segments[seg_name].begin = int(value, 16)
            elif seg_type == "End":
                segments[seg_name].end = int(value, 16)

        print("#### %s %s" % (name, segments))
        result.append((name, segments))
    return result

class DolBinary:
    def __init__(self, file):
        file = open(file, 'rb')
        text_ofs = [read_u32(file) for _ in range(7)]
        data_ofs = [read_u32(file) for _ in range(11)]

        text_vaddr = [read_u32(file) for _ in range(7)]
        data_vaddr = [read_u32(file) for _ in range(11)]

        text_size = [read_u32(file) for _ in range(7)]
        data_size = [read_u32(file) for _ in range(11)]

        self.text_segs = [Segment(x, x + y) for x, y in zip(text_vaddr, text_size)]
        self.data_segs = [Segment(x, x + y) for x, y in zip(data_vaddr, data_size)]
                
        bss_vaddr = read_u32(file)
        bss_size = read_u32(file)

        self.bss = Segment(bss_vaddr, bss_vaddr + bss_size)

        self.entry_point = read_u32(file)

        max_vaddr = max(x.end for x in self.text_segs + self.data_segs)
        self.image_base = 0x80000000
        self.image = bytearray(max_vaddr - self.image_base)
        
        for i in range(7):
            if not text_size[i]:
                continue

            file.seek(text_ofs[i])
            data = file.read(text_size[i])
            for j in range(text_size[i]):
                self.image[text_vaddr[i] + j - self.image_base] = data[j]

        for i in range(11):
            if not data_size[i]:
                continue

            file.seek(data_ofs[i])
            data = file.read(data_size[i])
            for j in range(data_size[i]):
                self.image[data_vaddr[i] + j - self.image_base] = data[j]



def format_gap(name, gap):
    return "asm/%s_%s.s" % (name, hex(gap.begin)[2:])

base   = DolBinary("../artifacts/pal/main.dol")
segments = read_segments("../artifacts/pal/segments.csv")
slices = read_slices("slices.csv")


from ppc_dis import *
import sys

def format_segname(name):
    if "extab" in name: return name + "_"
    return '.' + name

def disasm(name, base, seg, is_data):
    file = open("../" + format_gap(name, seg), 'w')
    original_stdout = sys.stdout
    sys.stdout = file
    perm = "wa"
    if name == "text" or name == "init":
        perm = "ax"
    
    # if "bss" in name:
    #     perm = "ba"

    if name == "rodata" or "2" in name:
        perm = perm.replace('w', '')

    print("\n.include \"macros.inc\"")

    file.write("\n.section %s, \"%s\" # 0x%08X - 0x%08X\n" % (format_segname(name), perm, seg.begin, seg.end))
    if "bss" in name:
        print(".skip 0x%x" % seg.size())
    elif name != "text" and name != "init":
        for i in range(seg.begin, seg.end, 4):
            def read_u32b(filecontent, offset):
                return (filecontent[offset + 0] << 24) | (filecontent[offset + 1] << 16) | (filecontent[offset + 2] << 8) | filecontent[offset + 3]

            if seg.end - i >= 4:
                print(".4byte 0x%08X" % read_u32b(base.image, i- 0x80000000))
            else:
                for j in range(i, seg.end):
                    print(".byte 0x%02x" % base.image[j - 0x80000000])
    else:
        disasm_iter(base.image, seg.begin - 0x80000000, seg.begin, seg.size(), disassemble_callback)
    sys.stdout = original_stdout

start_seg = {}
for name, seg in segments.items():
    start_seg[name] = Segment(0, seg.begin)

end_seg = {}
for name, seg in segments.items():
    end_seg[name] = Segment(seg.end, 0)

all_slices = slices + [('', end_seg)]

asm_files = []
o_files = []
cpp_files = []

import shutil
import os

try: shutil.rmtree("../asm")
except: pass

try: os.mkdir("../asm")
except: pass

with open('../asm/macros.inc', 'w') as file:
    file.write('# PowerPC Register Constants\n')
    for i in range(0, 32):
        file.write(".set r%i, %i\n" % (i, i))
    for i in range(0, 32):
        file.write(".set f%i, %i\n" % (i, i))
    for i in range(0, 8):
        file.write(".set qr%i, %i\n" % (i, i))

last_segments = start_seg
for obj_file, slice in all_slices:
    for name, segment in slice.items():
        if last_segments[name].end != segment.begin:
            # There's a gap!

            print("[.%s] Gap from %x to %x" % (name, last_segments[name].end, segment.begin))
            gap_seg = Segment(last_segments[name].end, segment.begin)
            print(format_gap(name, gap_seg))
            asm_files.append(format_gap(name, gap_seg))
            o_files.append(format_gap(name, gap_seg).replace("asm/", "").replace(".s", ".o"))
            disasm(name, base, gap_seg, False)
        last_segments[name] = segment
    if obj_file:
        o_files.append(obj_file.replace(".cpp", ".o").replace(".c", ".o"))
        cpp_files.append(obj_file)

open('../build/o_files.txt', 'w').write('\n'.join(o_files))