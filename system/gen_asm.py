import csv
import os
import shutil
import struct
import sys

from ppc_dis import *
from contextlib import redirect_stdout


# Change directory to script folder to make relative repo paths work.
os.chdir(sys.path[0])


def read_u8(f):
    return struct.unpack("B", f.read(1))[0]

def read_u32(f):
    return struct.unpack(">I", f.read(4))[0]

def read_u16(f):
    return struct.unpack(">H", f.read(2))[0]

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
    with open(name) as f:
        reader = csv.DictReader(f)
        for row in reader:
            yield row["name"], Segment(int(row["start"], 16), int(row["end"], 16))

def read_segments(name):
    result = {}
    for name, segment in read_segments_iter(name):
        result[name] = segment
    return result

class Slice:
    def __init__(self, obj_file, segments):
        self.obj_file = obj_file
        self.segments = segments

    def __repr__(self):
        return "Slice { %s, %u segs }" % (self.obj_file, len(self.segments))

# Limitation: slices must be ordered
def read_slices(name):
    lines = open(name).readlines()
    reader = csv.DictReader(lines)
    for row in reader:
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
        yield Slice(name, segments)

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



def format_gap(name, gap, folder):
    return "asm/%s/%s_%s.s" % (folder, name, hex(gap.begin)[2:])

def format_segname(name):
    if "extab" in name: return name + "_"
    return '.' + name

def read_u32b(filecontent, offset):
    return (filecontent[offset + 0] << 24) | (filecontent[offset + 1] << 16) | (filecontent[offset + 2] << 8) | filecontent[offset + 3]


# stdout must be redirected
def dump_bss(size):
    print(".skip 0x%x" % size)

# stdout must be redirected
def dump_data(image, addr_start, seg):
    for i in range(seg.begin, seg.end, 4):
        if seg.end - i >= 4:
            print(".4byte 0x%08X" % read_u32b(image, i - addr_start))
            continue

        for j in range(i, seg.end):
            print(".byte 0x%02x" % image[j - addr_start])

# stdout must be redirected
def dump_text(image, addr_start, seg):
    disasm_iter(image, seg.begin - addr_start, seg.begin, seg.size(), disassemble_callback)

def compute_perm(name):
    perm = "wa"
    if name == "text" or name == "init":
        perm = "ax"
    
    # if "bss" in name:
    #     perm = "ba"

    if name == "rodata" or "2" in name:
        perm = perm.replace('w', '')

    return perm

# stdout must be redirected
def dump_section_body(name, image, addr_start, seg):
    if "bss" in name:
        dump_bss(seg.size())
        return

    if name == "text" or name == "init":
        dump_text(image, addr_start, seg)
        return

    dump_data(image, addr_start, seg)

# stdout must be redirected
def dump_section_header(name, seg):
    # section permissions
    perm = compute_perm(name)
    
    print("\n.section %s, \"%s\" # 0x%08X - 0x%08X" % (format_segname(name), perm, seg.begin, seg.end))

# stdout must be redirected
def dump_section(name, image, addr_start, seg):
    dump_section_header(name, seg)
    dump_section_body(name, image, addr_start, seg)

# stdout must be redirected
def dump_object_file(image, addr_start, segments = []):
    print("\n.include \"macros.inc\"")

    for segment_name, segment in segments:
        dump_section(segment_name, image, addr_start, segment)

def disassemble_object_file(path, image, addr_start, segments = []):
    with open(path, 'w') as file:
        with redirect_stdout(file):
            dump_object_file(image, addr_start, segments)

def require_folder(path):
    try:
        os.mkdir(path)
    except FileExistsError:
        pass

def disasm(folder, name, image, addr_start, seg, is_data):
    require_folder(os.path.join("..", "asm"))
    require_folder(os.path.join("..", "asm", folder))
    
    path = os.path.join("..", format_gap(name, seg, folder))

    disassemble_object_file(path, image, addr_start, [ (name, seg) ])


def gen_start_segs(segments):
    # Start segs:
    # ['text']: (0, 0x8...)
    start_seg = {}
    for name, seg in segments.items():
        start_seg[name] = Segment(0, seg.begin)

    return start_seg


def gen_end_segs(segments):
    # End segs:
    # ['text']: (0x8..., 0)
    end_seg = {}
    for name, seg in segments.items():
        end_seg[name] = Segment(seg.end, 0)

    return end_seg


def find_gaps(all_slices):
    last_segments = all_slices[0].segments

    # [1:] to skip initial (previously start_seg)
    for slice_obj in all_slices[1:]:
        obj_file = slice_obj.obj_file
        slice  = slice_obj.segments
        for name, segment in slice.items():
            if last_segments[name].end != segment.begin:
                # There's a gap!

                print("[.%s] Gap from %x to %x" % (name, last_segments[name].end, segment.begin))
                yield name, Segment(last_segments[name].end, segment.begin)

            last_segments[name] = segment
        if not obj_file.startswith('#'):
            yield obj_file, None

def find_o_files(all_slices, folder):
    for name, gap_seg in find_gaps(all_slices):
        if gap_seg is None:
            yield name, gap_seg, "??"
            continue

        print(format_gap(name, gap_seg, folder))
        dest = format_gap(name, gap_seg, folder).replace("asm/", "").replace(".s", ".o")
        yield name, gap_seg, dest

def unpack_binary(folder, all_slices, image, addr_start):
    for name, gap_seg, dest in find_o_files(all_slices, folder): 
        is_decompiled = gap_seg is None

        if not is_decompiled:
            # print("name %s dest %s" % (name, dest))
            disasm(folder, name, image, addr_start, gap_seg, False)
            yield dest
        
        if is_decompiled:
            yield name.replace(".cpp", ".o").replace(".c", ".o")

def compute_end_cap(segments):
    # Final 0x8 -> 0x8; second part ignored
    end_seg = gen_end_segs(segments)

    end_slice = Slice('# 0x80 [finish] -> 0x80 [ignored]', end_seg)

    return end_slice

def compute_begin_cap(segments):
    # Final 0x8 -> 0x8; second part ignored
    start_seg = gen_start_segs(segments)

    start_slice = Slice('# 0 [ignored] -> 0x80 [start]', start_seg)

    return start_slice

def gen_cuts(slices, segments):
    # Initial 0 -> 0x8; first part ignored
    
    start_slice = compute_begin_cap(segments)
    end_slice = compute_end_cap(segments)
    
    return [start_slice] + slices + [end_slice] 

def compute_cuts_from_spreadsheets(segments, decomplog):
    # segments: binary descriptor, .text: 0x8..0x8
    # decomplog: slices, what decompiled code replaces
    
    slices = list(read_slices(decomplog))
    segments = read_segments(segments)

    return slices, segments, gen_cuts(slices, segments)
    
def unpack_base_dol():
    base_dol  = DolBinary("../artifacts/pal/main.dol")

    slices, segments, cuts = compute_cuts_from_spreadsheets("../artifacts/pal/segments.csv", "slices.csv")

    # o_files
    return list(unpack_binary("dol", cuts, base_dol.image, base_dol.image_base))

## REL

def load_rel_binary(segments) -> (bytearray, int):
    print(segments)
    max_vaddr = max(segments[seg].end for seg in segments)
    image_base = 0x80000000
    image = bytearray(max_vaddr - image_base)

    for segment in segments:
        with open("../tmp/%s.bin" % segment, 'rb') as file:
            data = file.read()

            segment_data = segments[segment]

            start = segment_data.begin
            end   = segment_data.end

            data_len = len(data) # virtual

            for i in range(start, end):
                #try:
                #    x = data[i - start]
                #except:
                #    print(segment, hex(i), hex(start), hex(end),i - start, len(data))
                #    print(end - (start + len(data)))

                # Hack for alignment (miss by 16)
                if i - start >= data_len:
                    continue
                image[i - image_base] = data[i - start]

    return image, image_base

def unpack_staticr_rel():
    slices, segments, cuts = compute_cuts_from_spreadsheets("../artifacts/pal/rel_segments.csv", "rel_slices.csv")

    image, image_base = load_rel_binary(segments)

    # o_files
    return list(unpack_binary("rel", cuts, image, image_base))

def unpack_everything():
    dol_o_files = unpack_base_dol()
    open('../o_files.txt', 'w').write('\n'.join(dol_o_files))
    
    rel_o_files = unpack_staticr_rel()
    open('../rel_o_files.txt', 'w').write('\n'.join(rel_o_files))

if __name__ == '__main__':
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

    unpack_everything()