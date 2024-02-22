"""
Assembly file generators.
"""

import argparse
from pathlib import Path, PurePosixPath
import os
from re import I
import struct
import pickle
import shutil

import jinja2
from ast import literal_eval

from mkwutil.lib.ppc_dis import InlineInstruction, disasm_iter, label_name
from mkwutil.lib.dol import DolBinary
from mkwutil.lib.rel import Rel, dump_staticr
from mkwutil.lib.symbols import Symbol, SymbolsList
from mkwutil.sections import DOL_SECTIONS, REL_SECTIONS, REL_SECTION_IDX, Section
from mkwutil.lib.slices import Slice, SliceTable
from mkwutil.ppcdis_adapter.ppcdis_disas import get_dol_disaser, get_rel_disaser
from ppcdis import Disassembler

from mkwutil.project import *

jinja_env = jinja2.Environment(
    loader=jinja2.PackageLoader("mkwutil", "gen_asm"),
    autoescape=jinja2.select_autoescape(),
)
jinja_env.filters["addr"] = lambda x: "0x%08x" % (x)


def is_text_addr(addr):
    # could be less hardcoded using mkwutil.lib
    return (0x805103b4<=addr and addr<0x8088f400) or (0x80004000<=addr and addr<0x80006460) or (0x800072c0<=addr and addr<0x80244de0)


class CAsmGenerator:
    """Generates C files with assembly functions."""

    def __init__(self, disaser, _slices, symbols, out_c, cpp_mode):
        self.disaser = disaser
        self.slices = _slices
        self.symbols = symbols
        self.out_c = out_c
        self.cpp_mode = cpp_mode
        # The list of seen extern declarations.
        self.extern_addrs = set()
        self.extern_functions = []
        self.extern_data = []
        # Output dirs
        self.func_dir = Path("./source") / "func"
        self.jtl_dir = Path("./source") / "jtl"
        self.func_dir.mkdir(exist_ok=True)
        self.jtl_dir.mkdir(exist_ok=True)

    def lookup_sym(self, addr):
        start, end = self.disaser._sym.get_containing_symbol(addr)
        sym = self.symbols.get(addr)
        if sym is not None:
            sym.size = end-addr
            return sym
        else:
            return Symbol(start, f"lbl_{addr:x}", end-addr)


    def dump_source(self):
        """Writes the C file to output."""
        functions = []
        rodata = []
        data = []
        bss = []

        for _slice in self.slices:
            addr = _slice.start
            while addr < _slice.stop:
                sym = self.lookup_sym(addr)
                if _slice.section == "text":
                    func_body = [f"#include \"asm/{addr:x}.s\"\n"]
                    # only called to collect refs lmao
                    self.disassemble_function(addr)
                    functions.append(
                        {
                            "addr": sym.addr,
                            "size": sym.size,
                            "name": sym.name,
                            "inline_asm": func_body,
                        }
                    )
                elif _slice.section == "rodata":
                    rodata_c = self.decompile_data(addr, const=True)
                    rodata.append(rodata_c)
                elif _slice.section == "data":
                    data_c = self.decompile_data(addr, const=False)
                    data.append(data_c)
                elif _slice.section == "bss":
                    # Remove duplicate extern declaration
                    if (addr, sym.name) in self.extern_data:
                        self.extern_data.remove((addr, sym.name))
                    bss.append({
                        "size": sym.size,
                        "name": sym.name,
                    })

                addr += sym.size

        # Sort extern functions.
        self.extern_functions.sort(key=lambda ref: ref[0])
        self.extern_data.sort(key=lambda ref: ref[0])
        emit_extern = lambda x: x[1] != '__dl__FPv'
        self.extern_functions = filter(emit_extern, self.extern_functions)
        # Write out to C file.
        template = jinja_env.get_template("source.c.j2")
        template.stream(
            cpp=self.cpp_mode,
            functions=functions,
            rodata=rodata,
            data=data,
            bss=bss,
            extern_functions=list({"name": a[1], "addr": a[0]} for a in self.extern_functions),
            extern_data=list({"name": a[1], "addr": a[0]} for a in self.extern_data),
        ).dump(self.out_c)


    def disassemble_function(self, fn_start_vma):
        inline_asm, refs = self.disaser.function_to_text_with_referenced(fn_start_vma, inline=True, extra=False,
            hashable=False, declare_mangled=False)
        self.collect_refs(refs)
        return inline_asm.split("\n")

    def decompile_data(self, addr, const):
        txt, refs = self.disaser.data_to_text_with_referenced(addr, const=const)
        self.collect_refs(refs)
        # Remove duplicate extern declaration
        if (addr, self.disaser._sym.get_name(addr)) in self.extern_data:
            self.extern_data.remove((addr, self.disaser._sym.get_name(addr)))
        return txt

    def collect_refs(self, refs):
        for (addr, name) in refs:
            if addr not in self.extern_addrs:
                self.extern_addrs.add(addr)

                if is_text_addr(addr):
                    self.extern_functions.append((addr, name))
                else:
                    self.extern_data.append((addr, name))


def get_asm_path(folder, _slice):
    assert _slice.section is not None
    return folder / ("%s_%08x_%08x.s" % (_slice.section, _slice.start, _slice.stop))


INLINE_ASM_RE = r'#include "asm\/([0-9a-f]{8})\.s"'

class DOLSrcGenerator:
    """Generates assembly from DOL."""

    def __init__(
        self,
        slices: SliceTable,
        dol: DolBinary,
        disaser: Disassembler,
        symbols: SymbolsList,
        dol_asm_dir: Path,
        dol_bin_dir: Path,
        source_dir: Path,
        pack_dir: Path,
        regen_asm: bool,
    ):
        self.slices = slices
        self.slices.set_sections(DOL_SECTIONS)
        self.dol = dol
        self.disaser = disaser
        self.symbols = symbols
        self.dol_asm_dir = dol_asm_dir
        self.dol_bin_dir = dol_bin_dir
        self.source_dir = source_dir
        self.pack_dir = pack_dir
        self.regen_asm = regen_asm
        self.dol_asm_sources = set()
        self.inline_asm_pattern = re.compile(INLINE_ASM_RE)


    def run(self):
        """Runs ASM generation for main.dol/StaticR.dol"""
        source_asm_dir = self.source_dir / "asm"
        for c_source_name, sections in self.slices.object_slices():
            self.__gen_c(c_source_name, sections)
            self.__gen_includes(c_source_name, source_asm_dir)
        for _slice in self.slices:
            if _slice.section is None:
                # ignore slices not belonging to sections
                continue
            if self.__slice_dest_asm(_slice):
               self. __gen_asm(_slice)
        # Delete stale ASM files.
        for path in self.dol_asm_dir.iterdir():
            if path.suffix != ".s":
                continue
            if path.stem not in self.dol_asm_sources:
                os.remove(path)
        # Give all ASM slices a name. This makes the slice table unusable.
        for _slice in self.slices:
            if _slice.section is None:
                continue
            out_path = None
            if not _slice.has_name():
                out_path = get_asm_path(Path("dol"), _slice)
            else:
                out_path = Path(Path(_slice.name).name)
            out_path = Path("out") / out_path.with_suffix(".o")
            _slice.name = str(out_path)
        # Write list of objects for linker.
        object_names = self.slices.object_slices().objects.keys()
        with open(self.pack_dir / "dol_objects.txt", "w") as file:
            for name in object_names:
                print(PurePosixPath(Path(name)), file=file)

    def __process_section(self, section: Section):
        """Processes a library section and all its slices."""
        subtable = self.slices.slice(section.start, section.stop)
        print(f".{section.name} ({section.type}): {subtable.count()} slices")
        for _slice in subtable:
            self.__process_slice(section, _slice)

    # If the slice should be output as a .s file
    def __slice_dest_asm(self, _slice):
        return not _slice.has_name()

    # If the slice should be output as a .c file
    def __slice_dest_c(self, _slice):
        return _slice.has_name()


    def __gen_c(self, c_source_name: str, _slices: list[Slice]):
        c_path = Path(c_source_name)
        if not c_path.exists():
            c_path.parent.mkdir(parents=True, exist_ok=True)
            with open(c_path, "w") as c_file:
                gen = CAsmGenerator(
                    self.disaser,
                    _slices,
                    self.symbols,
                    c_file,
                    not str(c_path).endswith(".c"),
                )
                gen.dump_source()

    def __gen_asm(self, _slice: Slice):
        """Generates an ASM file."""
        section = _slice.section
        asm_path = get_asm_path(self.dol_asm_dir, _slice)
        self.dol_asm_sources.add(asm_path.stem)
        if not self.regen_asm and asm_path.exists():
            return
        # print(f"    => {asm_path}")
        self.disaser.output_slice(asm_path, _slice.start, _slice.start+len(_slice))

    def __gen_includes(self, c_source_name: str, out_path: Path):
        c_path = Path(c_source_name)
        assert c_path.exists(), f"C source {c_source_name} not found"
        with open(c_path, "r") as c_file:
            c_text = c_file.read()
            for addr_str in re.findall(self.inline_asm_pattern, c_text):
                addr = int(addr_str, 16)
                inline_asm = self.disaser.function_to_text(addr, inline=True, extra=False,
                                                           hashable=False, declare_mangled=False)
                out_file = out_path / f"{addr:x}.s"
                with open(out_file, "w") as asm_file:
                    asm_file.write(inline_asm)


class RELSrcGenerator:
    """Generates assembly from REL."""

    def __init__(
        self,
        slices: SliceTable,
        rel: Rel,
        disaser: Disassembler,
        symbols: SymbolsList,
        rel_asm_dir: Path,
        rel_bin_dir: Path,
        source_dir: Path,
        pack_dir: Path,
        regen_asm: bool,
    ):
        self.slices = slices
        self.slices.set_sections(REL_SECTIONS)
        self.rel = rel
        self.disaser = disaser
        self.symbols = symbols
        self.rel_asm_dir = rel_asm_dir
        self.rel_bin_dir = rel_bin_dir
        self.source_dir = source_dir
        self.pack_dir = pack_dir
        self.regen_asm = regen_asm
        self.rel_asm_sources = set()
        self.inline_asm_pattern = re.compile(INLINE_ASM_RE)

    def run(self):
        """Runs ASM generation for StaticR.rel"""
        source_asm_dir = self.source_dir / "asm"
        for c_source_name, sections in self.slices.object_slices():
            self.__gen_c(c_source_name, sections)
            self.__gen_includes(c_source_name, source_asm_dir)
        for _slice in self.slices:
            if _slice.section is None:
                # ignore slices not belonging to sections
                continue
            if self.__slice_dest_asm(_slice):
               self. __gen_asm(_slice)
        # Delete stale ASM files.
        for path in self.rel_asm_dir.iterdir():
            if path.suffix != ".s":
                continue
            if path.stem not in self.rel_asm_sources:
                os.remove(path)
        # Give all ASM slices a name. This makes the slice table unusable.
        for _slice in self.slices:
            if _slice.section is None:
                continue
            out_path = None
            if not _slice.has_name():
                out_path = get_asm_path(Path("rel"), _slice)
            else:
                out_path = Path(Path(_slice.name).name)
            out_path = Path("out") / out_path.with_suffix(".o")
            _slice.name = str(out_path)
        # Write list of objects for linker.
        object_names = self.slices.object_slices().objects.keys()
        with open(self.pack_dir / "rel_objects.txt", "w") as file:
            for name in object_names:
                print(PurePosixPath(Path(name)), file=file)

    def __process_section(self, section: Section):
        """Processes a library section and all its slices."""
        subtable = self.slices.slice(section.start, section.stop)
        print(f".{section.name} ({section.type}): {subtable.count()} slices")
        for _slice in subtable:
            self.__process_slice(section, _slice)

    # If the slice should be output as a .s file
    def __slice_dest_asm(self, _slice):
        return not _slice.has_name()

    # If the slice should be output as a .c file
    def __slice_dest_c(self, _slice):
        return _slice.has_name()


    def __gen_c(self, c_source_name: str, _slices: list[Slice]):
        c_path = Path(c_source_name)
        if not c_path.exists():
            c_path.parent.mkdir(parents=True, exist_ok=True)
            with open(c_path, "w") as c_file:
                gen = CAsmGenerator(
                    self.disaser,
                    _slices,
                    self.symbols,
                    c_file,
                    not str(c_path).endswith(".c"),
                )
                gen.dump_source()

    def __gen_asm(self, _slice: Slice):
        """Generates an ASM file."""
        asm_path = get_asm_path(self.rel_asm_dir, _slice)
        self.rel_asm_sources.add(asm_path.stem)
        if not self.regen_asm and asm_path.exists():
            return
        # print(f"    => {asm_path}")
        self.disaser.output_slice(asm_path, _slice.start, _slice.start+len(_slice))

    def __gen_includes(self, c_source_name: str, out_path: Path):
        c_path = Path(c_source_name)
        assert c_path.exists(), f"C source {c_source_name} not found"
        with open(c_path, "r") as c_file:
            c_text = c_file.read()
            for addr_str in re.findall(self.inline_asm_pattern, c_text):
                addr = int(addr_str, 16)
                inline_asm = self.disaser.function_to_text(addr, inline=True, extra=False,
                                                           hashable=False, declare_mangled=False)
                out_file = out_path / f"{addr:x}.s"
                with open(out_file, "w") as asm_file:
                    asm_file.write(inline_asm)


def gen_asm(regen_asm=False):
    asm_dir = Path("./asm")
    pack_dir = Path("./pack")
    source_dir = Path("./source")
    source_asm_dir = source_dir / "asm"
    binary_dir = Path("./artifacts/orig/pal")

    asm_dir.mkdir(exist_ok=True)
    shutil.rmtree(source_asm_dir, ignore_errors=True)
    source_asm_dir.mkdir()

    symbols = read_symbol_map(pack_dir / "symbols.yml")
    symbols.derive_sizes(0x81000000)

    dol = read_dol(binary_dir / "main.dol")
    dol_disaser = get_dol_disaser()
    dol_bin_dir = binary_dir / "dol"
    dol_slices = read_enabled_slices(dol, pack_dir / "dol_slices.yml")

    # Disassemble DOL sections.
    dol_asm_dir = asm_dir / "dol"
    dol_asm_dir.mkdir(exist_ok=True)
    dol_gen = DOLSrcGenerator(
        dol_slices, dol, dol_disaser, symbols, dol_asm_dir, dol_bin_dir, source_dir, pack_dir, regen_asm
    )
    dol_gen.run()

    rel = read_rel(binary_dir / "StaticR.rel")
    rel_disaser = get_rel_disaser()
    # Dump StaticR.rel segments.
    rel_bin_dir = binary_dir / "rel"
    dump_staticr(rel, rel_bin_dir)
    # Map out slices in REL.
    rel_slices = load_rel_slices(sections=REL_SECTIONS).filter(SliceTable.ONLY_ENABLED)
    # Disassemble REL sections.
    rel_asm_dir = asm_dir / "rel"
    rel_asm_dir.mkdir(exist_ok=True)
    rel_gen = RELSrcGenerator(
        rel_slices, rel, rel_disaser, symbols, rel_asm_dir, rel_bin_dir, source_dir, pack_dir, regen_asm
    )
    rel_gen.run()


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Generate ASM blobs and linker object lists."
    )
    parser.add_argument("--regen_asm", action="store_true", help="Regenerate all ASM files")
    args = parser.parse_args()
    gen_asm(args.regen_asm)
