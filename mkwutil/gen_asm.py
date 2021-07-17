"""
Assembly file generators.
"""

import argparse
from pathlib import Path
import struct

import jinja2

from mkwutil.ppc_dis import InlineInstruction, disasm_iter, label_name
from mkwutil.dol import DolBinary
from mkwutil.rel import Rel, dump_staticr
from mkwutil.symbols import SymbolsList
from mkwutil.sections import DOL_SECTIONS, Section
from mkwutil.slices import Slice, SliceTable


jinja_env = jinja2.Environment(
    loader=jinja2.PackageLoader("mkwutil", "gen_asm"),
    autoescape=jinja2.select_autoescape(),
)
jinja_env.filters["addr"] = lambda x: "0x%08x" % (x)


class AsmGenerator:
    """Generates assembly files."""

    def __init__(self, data, _slice, symbols, output):
        self.data = data
        self.slice = _slice
        self.symbols = symbols
        self.output = output

    # TODO Define symbols in ASM

    def dump_bss(self):
        """Writes a bss segment."""
        print(".skip 0x%x" % len(self.slice), file=self.output)

    def dump_data(self):
        """Writes a data segment."""
        data = self.data
        while len(data) >= 4:
            int_val = struct.unpack(">I", data[:4])[0]
            print(".4byte 0x%08X" % (int_val), file=self.output)
            data = data[4:]
        for byte_val in data:
            print(".byte 0x%02x" % (byte_val), file=self.output)

    def dump_text(self):
        """Writes a disassembled text segment."""
        for ins in disasm_iter(self.data, self.slice.start):
            print(ins.disassemble(), file=self.output)

    def dump_section_body(self):
        name = self.slice.section
        if "bss" in name:
            self.dump_bss()
        elif name in ("text", "init"):
            self.dump_text()
        else:
            self.dump_data()

    def format_segname(self, name):
        if "extab" in name:
            return name + "_"
        return "." + name

    def dump_section_header(self):
        """Writes the header to output."""
        # section permissions
        perm = self.compute_perm()
        print(
            f""".include "macros.inc"

.section {self.format_segname(self.slice.section)}, "{perm}" # {self.slice}""",
            file=self.output,
        )

    def compute_perm(self):
        """Computes the memory permissions."""
        name = self.slice.section
        perm = "wa"
        if name in ("text", "init"):
            perm = "ax"
        # if "bss" in name:
        #     perm = "ba"
        if name == "rodata" or "2" in name:
            perm = perm.replace("w", "")
        return perm

    def dump_section(self):
        """Writes unit header and body to output."""
        self.dump_section_header()
        self.dump_section_body()


class CAsmGenerator:
    """Generates C files with assembly functions."""

    def __init__(self, data, _slice, symbols, output):
        self.data = data
        self.slice = _slice
        self.symbols = symbols
        self.output = output

    # TODO not a good name
    def dump_section(self):
        """Writes the C file to output."""
        addr = self.slice.start
        symbols = self.symbols.slice(self.slice.start, self.slice.stop)
        symbols.derive_sizes(self.slice.stop)
        functions = []
        for sym in symbols:
            assert (
                sym.addr == addr
            ), f"Currently at {hex(addr)} but next symbol is at {hex(sym.addr)}"
            func_body = self.disassemble_function(sym)
            functions.append(
                {
                    "addr": sym.addr,
                    "size": sym.size,
                    "name": sym.name,
                    "inline_asm": func_body,
                }
            )
            addr += sym.size
        assert (
            addr == self.slice.stop
        ), f"Disassembled up to {hex(addr)} but slice goes to {hex(self.slice.stop)}"
        # Write out to C file.
        jinja_env.get_template("source.c.j2").stream(functions=functions).dump(
            self.output
        )

    def disassemble_function(self, sym):
        """Generates the inline assembly function body as a stream of lines."""
        assert isinstance(sym.size, int)
        assert sym.size > 0
        # Grab the instructions.
        data_start = sym.addr - self.slice.start
        data_stop = data_start + sym.size
        data = self.data[data_start:data_stop]
        insns = list(disasm_iter(data, sym.addr))
        # Walk instructions and collect jump targets.
        labels = set()
        for ins in insns:
            branch_info = ins.disassemble_branch()
            if branch_info is not None:
                _, addr = branch_info
                if sym.addr <= addr < sym.addr + sym.size:
                    labels.add(addr)
        sorted_labels = list(sorted(labels))
        # Disassemble instructions.
        for ins in insns:
            # TODO is there a better way to specialize a Python object?
            ins = InlineInstruction(
                ins.address, ins.insn, ins.bytes, labels, self.symbols
            )
            # Insert next label if address matches.
            if len(sorted_labels) > 0 and sorted_labels[0] <= ins.address:
                label = sorted_labels.pop(0)
                yield f"{label_name(label)}:"
            # Actual instruction.
            yield f"  {ins.disassemble()};"


def get_asm_path(folder, _slice):
    assert _slice.section is not None
    return folder / ("%s_%08x_%08x.s" % (_slice.section, _slice.start, _slice.stop))


class DOLSrcGenerator:
    def __init__(
        self,
        slices: SliceTable,
        dol: DolBinary,
        symbols: SymbolsList,
        dol_asm_dir: Path,
        pack_dir: Path,
        regen_asm: bool,
    ):
        self.slices = slices
        self.dol = dol
        self.symbols = symbols
        self.dol_asm_dir = dol_asm_dir
        self.pack_dir = pack_dir
        self.regen_asm = regen_asm
        self.dol_objects = []
        self.dol_asm_sources = set()

    def run(self):
        """Runs ASM generation for main.dol."""
        for section in DOL_SECTIONS:
            self.__process_section(section)
        # TODO Delete stale ASM files.
        # Write list of objects for linker.
        with open(self.pack_dir / "dol_objects.txt", "w") as file:
            for obj in self.dol_objects:
                print(obj, file=file)

    def __process_section(self, section: Section):
        """Processes a program section and all its slices."""
        subtable = self.slices.slice(section.start, section.stop)
        print(f".{section.name} ({section.type}): {subtable.count()} slices")
        for _slice in subtable:
            _slice.section = section.name
            self.__process_slice(section, _slice)

    def __process_slice(self, section: Section, _slice: Slice):
        """Process a slice in slices.csv or a gap."""
        print(f"  {_slice}")
        # Generate ASM file.
        if not _slice.has_name():
            self.__gen_asm(section, _slice)
        # Generate C code file.
        else:
            if section.type == "code":
                self.__gen_c(_slice)

    def __gen_c(self, _slice: Slice):
        """Generates a C file with inline assembly if not exists."""
        # Generate C inline assembly.
        c_path = Path(_slice.name)
        if c_path.exists():
            return
        c_path.parent.mkdir(parents=True, exist_ok=True)
        print(f"    => {_slice.name}")
        data = self.dol.virtual_read(_slice.start, len(_slice))
        with open(c_path, "w") as file:
            gen = CAsmGenerator(data, _slice, self.symbols, file)
            gen.dump_section()

    def __gen_asm(self, section: Section, _slice: Slice):
        """Generates an ASM file."""
        asm_path = get_asm_path(self.dol_asm_dir, _slice)
        self.dol_asm_sources.add(asm_path.name)
        self.dol_objects.append(Path("out") / "dol" / (asm_path.stem + ".o"))
        if not self.regen_asm and asm_path.exists():
            return
        print(f"    => {asm_path}")
        with open(asm_path, "w") as asm_file:
            data = (
                self.dol.virtual_read(_slice.start, len(_slice))
                if section.type != "bss"
                else None
            )
            gen = AsmGenerator(data, _slice, self.symbols, asm_file)
            gen.dump_section()


# TODO REL support


def main():
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
    parser.add_argument("--regen_asm", action="store_true", help="Regenerate all ASM")
    args = parser.parse_args()
    args.asm_dir.mkdir(exist_ok=True)

    # Read DOL.
    dol_path = args.binary_dir / "main.dol"
    with open(dol_path, "rb") as file:
        dol = DolBinary(file)
    # Read symbol map.
    symbols = SymbolsList()
    symbols_path = args.pack_dir / "symbols.txt"
    with open(symbols_path, "r") as file:
        symbols.read_from(file)
    # Map out slices in DOL.
    dol_slices = SliceTable(dol.start, dol.stop)
    with open(args.pack_dir / "dol_slices.csv") as file:
        dol_slices.read_from(file)
    dol_slices = dol_slices.filter(SliceTable.ONLY_ENABLED)
    # Disassemble DOL sections.
    # TODO This could be rewritten to a class to dedup code.
    dol_asm_dir = args.asm_dir / "dol"
    dol_asm_dir.mkdir(exist_ok=True)
    dol_gen = DOLSrcGenerator(
        dol_slices, dol, symbols, dol_asm_dir, args.pack_dir, args.regen_asm
    )
    dol_gen.run()


if __name__ == "__main__":
    main()
