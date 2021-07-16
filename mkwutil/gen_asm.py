import argparse
import csv
import jinja2
import os
from pathlib import Path
import struct

import capstone.ppc

from .ppc_dis import InlineInstruction, disasm_iter, label_name
from .dol import DolBinary, Segment
from .rel import Rel, dump_staticr
from .symbols import SymbolsList


read_u32 = lambda f: struct.unpack(">L", f.read(4))[0]
read_u16 = lambda f: struct.unpack(">H", f.read(2))[0]
read_u8 = lambda f: struct.unpack(">B", f.read(1))[0]


jinja_env = jinja2.Environment(
    loader=jinja2.PackageLoader("mkwutil", "gen_asm"),
    autoescape=jinja2.select_autoescape(),
)


class AsmGenerator:
    """Generates assembly files."""

    def __init__(self, image, offset, seg, symbols, output):
        self.image = image
        self.offset = offset
        self.seg = seg
        self.symbols = symbols
        self.output = output

    # TODO Define symbols in ASM

    def dump_bss(self):
        """Writes a bss segment."""
        print(".skip 0x%x" % self.seg.size(), file=self.output)

    def dump_data(self):
        """Writes a data segment."""
        image_offset = self.seg.begin - self.offset
        data = self.image[image_offset : image_offset + self.seg.size()]
        while len(data) >= 4:
            int_val = struct.unpack(">I", data[:4])[0]
            print(".4byte 0x%08X" % (int_val), file=self.output)
            data = data[4:]
        for byte_val in data:
            print(".byte 0x%02x" % (byte_val), file=self.output)

    def dump_text(self):
        """Writes a disassembled text segment."""
        for ins in disasm_iter(
            self.image, self.seg.begin - self.offset, self.seg.begin, self.seg.size()
        ):
            print(ins.disassemble(), file=self.output)

    def dump_section_body(self, name):
        if "bss" in name:
            self.dump_bss()
            return

        if name == "text" or name == "init":
            self.dump_text()
            return

        self.dump_data()

    def dump_section_header(self, name):
        # section permissions
        perm = AsmGenerator.compute_perm(name)
        print(
            '\n.section %s, "%s" # 0x%08X - 0x%08X'
            % (format_segname(name), perm, self.seg.begin, self.seg.end),
            file=self.output,
        )

    def compute_perm(name):
        perm = "wa"
        if name == "text" or name == "init":
            perm = "ax"

        # if "bss" in name:
        #     perm = "ba"

        if name == "rodata" or "2" in name:
            perm = perm.replace("w", "")

        return perm

    def dump_section(self, name):
        self.dump_section_header(name)
        self.dump_section_body(name)


class CAsmGenerator:
    """Generates C files with assembly functions."""

    def __init__(self, image, offset, seg, symbols, output):
        self.image = image
        self.offset = offset
        self.seg = seg
        self.symbols = symbols
        self.output = output

    def disassemble_function(self, sym):
        """Returns the inline assembly function body."""
        assert isinstance(sym.size, int)
        # Grab the instructions.
        insns = list(
            disasm_iter(self.image, sym.addr - self.offset, sym.addr, sym.size)
        )
        # Walk instructions and collect jump targets.
        func_range = slice(sym.addr, sym.addr + sym.size)
        labels = set()
        for ins in insns:
            branch_info = ins.disassemble_branch()
            if branch_info is not None:
                _, addr = branch_info
                if addr in func_range:
                    labels.add(addr)
        sorted_labels = list(sorted(labels))
        # Disassemble instructions.
        for ins in insns:
            # TODO is there a better way to specialize a Python object?
            ins = InlineInstruction(
                ins.address, ins.offset, ins.insn, ins.bytes, labels, self.symbols
            )
            # Insert next label if address matches.
            if len(sorted_labels) > 0 and sorted_labels[0] <= ins.address:
                label = sorted_labels.pop()
                print(f"{label_name(label)}:", file=self.output)
            # Actual instruction.
            print(f"  {ins.disassemble()}", file=self.output)


def read_segments_iter(name):
    with open(name) as file:
        reader = csv.DictReader(file)
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
def read_slices(name, verbose=True):
    lines = open(name).readlines()
    reader = csv.DictReader(lines)
    for row in reader:
        if not row.pop("enabled"):
            continue
        if "strip" in row:
            row.pop("strip")
        name = row.pop("name")
        segments = {}

        for cell, value in row.items():
            segment_attributes = ["Start", "End"]
            seg_name = ""
            seg_type = ""
            for attr in segment_attributes:
                if cell.endswith(attr):
                    seg_type = attr
                    seg_name = cell[: -len(attr)]
            assert seg_name and seg_type

            if not value:
                continue

            if not seg_name in segments:
                segments[seg_name] = Segment(0, 0)

            if seg_type == "Start":
                segments[seg_name].begin = int(value, 16)
            elif seg_type == "End":
                segments[seg_name].end = int(value, 16)

        if verbose:
            print("#### %s %s" % (name, segments))
        yield Slice(name, segments)


def get_asm_path(name, gap, folder):
    folder.mkdir(exist_ok=True)
    return folder / ("%s_%08x_%08x.s" % (name, gap.begin, gap.end))


def format_segname(name):
    if "extab" in name:
        return name + "_"
    return "." + name


def dump_object_file(image, addr_start, segments, symbols, output):
    print('\n.include "macros.inc"', file=output)
    for segment_name, segment in segments:
        gen = AsmGenerator(image, addr_start, segment, symbols=symbols, output=output)
        gen.dump_section(segment_name)


def disassemble_object_file(path, image, addr_start, segments, symbols):
    if os.path.exists(path):
       return  # Don't bother updating existing file
    with open(path, "w") as file:
        dump_object_file(image, addr_start, segments, symbols, output=file)


def disasm(folder, name, image, addr_start, seg, symbols):
    path = get_asm_path(name, seg, folder)
    disassemble_object_file(path, image, addr_start, [(name, seg)], symbols)
    return path


def disasm_to_c(dst_path):
    print("Generating file", dst_path)
    # TODO Invoke CAsmGenerator()


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
        slice = slice_obj.segments
        for name, segment in slice.items():
            if last_segments[name].end != segment.begin:
                # There's a gap!

                print(
                    "[.%s] Gap from %x to %x"
                    % (name, last_segments[name].end, segment.begin)
                )
                yield name, Segment(last_segments[name].end, segment.begin)

            last_segments[name] = segment
        if not obj_file.startswith("#"):
            yield obj_file, None


def find_o_files(all_slices, folder):
    """Returns all paths to object files that will assemble the binary."""
    for name, gap_seg in find_gaps(all_slices):
        if gap_seg is None:
            yield name, gap_seg, "??"
            continue
        path = get_asm_path(name, gap_seg, folder)
        print(path)
        path.stem.replace(".s", ".o")
        yield name, gap_seg, path


# This needs some re-structuring.
def unpack_binary(folder, all_slices, image, addr_start, symbols):
    # Disassemble all slices if they don't exist already.
    # Keep track of the expected paths.
    asm_paths = set()
    for name, gap_seg, dest in find_o_files(all_slices, folder):
        is_decompiled = gap_seg is None
        if not is_decompiled:
            # print("name %s dest %s" % (name, dest))
            asm_path = disasm(folder, name, image, addr_start, gap_seg, symbols)
            asm_paths.add(str(asm_path.relative_to(folder)))
            kind = Path(dest.parent.name)  # dol or rel
            yield Path("out", kind, dest.stem + ".o")
        else:
            source_path = Path(name)
            if not os.path.exists(source_path):
                # TODO C++ support
                print(folder)
                disasm_to_c(source_path)
            object_name = source_path.stem + ".o"
            yield Path("out", object_name)
    # Check with paths we actually have.
    # Delete asm blobs that don't match those we just unpacked.
    for path in folder.iterdir():
        have_path = path.relative_to(folder)
        if have_path.suffix != ".s":
            continue
        if str(have_path) in asm_paths:
            continue
        print(f"Removing {path}")
        os.remove(path)


def compute_end_cap(segments):
    # Final 0x8 -> 0x8; second part ignored
    end_seg = gen_end_segs(segments)

    end_slice = Slice("# 0x80 [finish] -> 0x80 [ignored]", end_seg)

    return end_slice


def compute_begin_cap(segments):
    # Final 0x8 -> 0x8; second part ignored
    start_seg = gen_start_segs(segments)

    start_slice = Slice("# 0 [ignored] -> 0x80 [start]", start_seg)

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


def unpack_base_dol(asm_dir, pack_dir, binary_dir, symbols):
    base_dol = DolBinary(binary_dir / "main.dol")

    _, _, cuts = compute_cuts_from_spreadsheets(
        pack_dir / "dol_segments.csv",
        pack_dir / "dol_slices.csv",
    )

    # o_files
    return list(
        unpack_binary(
            asm_dir / "dol", cuts, base_dol.image, base_dol.image_base, symbols
        )
    )


## REL


def load_rel_binary(segments, binary_dir) -> (bytearray, int):
    print(segments)
    max_vaddr = max(segments[seg].end for seg in segments)
    image_base = 0x80000000
    image = bytearray(max_vaddr - image_base)

    rel_segment_dir = binary_dir / "rel"
    for segment in segments:
        rel_segment_path = rel_segment_dir / (segment + ".bin")
        with open(rel_segment_path, "rb") as file:
            data = file.read()

            segment_data = segments[segment]

            start = segment_data.begin
            end = segment_data.end

            data_len = len(data)  # virtual

            for i in range(start, end):
                # try:
                #    x = data[i - start]
                # except:
                #    print(segment, hex(i), hex(start), hex(end),i - start, len(data))
                #    print(end - (start + len(data)))

                # Hack for alignment (miss by 16)
                if i - start >= data_len:
                    continue
                image[i - image_base] = data[i - start]

    return image, image_base


def unpack_staticr_rel(asm_dir, pack_dir, binary_dir):
    _, segments, cuts = compute_cuts_from_spreadsheets(
        pack_dir / "rel_segments.csv",
        pack_dir / "rel_slices.csv",
    )

    image, image_base = load_rel_binary(segments, binary_dir)

    # o_files
    return list(unpack_binary(asm_dir / "rel", cuts, image, image_base, SymbolsList()))


def unpack_everything(asm_dir, pack_dir, binary_dir):
    """Unpack all ASM blobs into asm_dir."""
    symbols = SymbolsList()
    with open(pack_dir / "symbols.txt", "r") as f:
        symbols.read(f)
    dol_o_files = unpack_base_dol(asm_dir, pack_dir, binary_dir, symbols)
    with open(pack_dir / "dol_objects.txt", "w") as file:
        for path in dol_o_files:
            print(path, file=file)
    rel_o_files = unpack_staticr_rel(asm_dir, pack_dir, binary_dir)
    with open(pack_dir / "rel_objects.txt", "w") as file:
        for path in rel_o_files:
            print(path, file=file)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Generate ASM blobs and linker object lists."
    )
    parser.add_argument("--asm_dir", type=Path, default="./asm", help="Path to ASM dir")
    parser.add_argument(
        "--pack_dir", type=Path, default="./pack", help="Path to link instructions dir"
    )
    parser.add_argument(
        "--binary_dir",
        type=Path,
        default="./artifacts/orig/pal",
        help="Binary containing main.dol and StaticR.rel",
    )
    args = parser.parse_args()
    args.asm_dir.mkdir(exist_ok=True)

    # Feel free to move this around, dump staticr.rel segments
    with open("artifacts/orig/pal/StaticR.rel", "rb") as f:
        dump_staticr(Rel(f), "artifacts/orig/pal/rel")

    # Write the macros file.
    with open(args.asm_dir / "macros.inc", "w") as file:
        file.write("# PowerPC Register Constants\n")
        for i in range(0, 32):
            file.write(".set r%i, %i\n" % (i, i))
        for i in range(0, 32):
            file.write(".set f%i, %i\n" % (i, i))
        for i in range(0, 8):
            file.write(".set qr%i, %i\n" % (i, i))

    unpack_everything(args.asm_dir, args.pack_dir, args.binary_dir)
