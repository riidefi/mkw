"""
Assembly file generators.
"""

import argparse
from pathlib import Path, PurePosixPath
import os
from re import I
import struct
import pickle

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


def addr_in_sym(addr, sym):
    return sym.addr <= addr < sym.addr + sym.size


def is_text_addr(addr):
    # could be less hardcoded using mkwutil.lib
    return (0x805103b4<=addr and addr<0x8088f400) or (0x80004000<=addr and addr<0x80006460) or (0x800072c0<=addr and addr<0x80244de0)

class AsmGenerator:
    """Generates assembly files."""

    def __init__(self, data, _slice, symbols, output, extra_labels, rel=False):
        self.data = data
        self.slice = _slice
        self.symbols = symbols
        self.output = output
        self.extra_labels = extra_labels
        extras = [addr for addr in extra_labels if addr not in symbols]
        self.symbol_locs = sorted([sym.addr for sym in symbols] + \
            [addr for addr in extra_labels if addr not in symbols])
        self.is_rel = rel


    # TODO Define symbols in ASM

    def emit_symbol(self, address):
        """Maybe emits a symbol, if there is one."""
        if address not in self.symbols:  # probably slow
            # TODO: maybe add to symbol map (this includes lots of data though)
            if address in self.extra_labels: # labels referenced by code not in symbol map
                if self.extra_labels[address] == 'DATA':
                    name = f'lbl_{address:08x}'
                    print(f'.global "{name}"\n"{name}":', file=self.output)
                elif self.extra_labels[address] == 'FUNCTION':
                    name = f'fun_{address:08x}'
                    print(f'.global "{name}"\n"{name}":', file=self.output)

            return
        name = self.symbols[address].name
        print(f'.global "{name}"\n"{name}":', file=self.output)

    def dump_bss(self):
        """Writes a bss segment."""
        for part in self.slice.split(self.symbol_locs):
            self.emit_symbol(part.start)
            print(".skip 0x%x" % len(part), file=self.output)

    def dump_data(self):
        """Writes a data segment."""
        for part in self.slice.split(self.symbol_locs):
            self.emit_data_words(part)

    def emit_data_words(self, part: Slice):
        """Emits a bunch of data segment words."""
        for address, chunk in self.iter_data_chunks(part, 4):
            if len(chunk) == 4:
                self.emit_symbol(address)
                print(".4byte 0x%08X" % struct.unpack(">I", chunk), file=self.output)
            else:
                self.emit_data_bytes(address, chunk)

    def emit_data_bytes(self, address, data):
        """Emits a few data segment bytes."""
        while len(data) > 0:
            self.emit_symbol(address)
            byte_val = data[0]
            print(".byte 0x%02x" % (byte_val), file=self.output)
            data = data[1:]
            address += 1

    def get_data_chunk(self, part: Slice) -> bytes:
        view = memoryview(self.data)
        view = view[part.start - self.slice.start :]
        view = view[: len(part)]
        return bytes(view)

    def iter_data_chunks(
        self, part: Slice, chunk_size: int
    ) -> Iterator[tuple[int, bytes]]:
        offset = part.start - self.slice.start
        # Use memoryview to scan over data efficiently.
        view = memoryview(self.data)
        view = view[offset : part.stop - self.slice.start]
        # Align first word.
        if offset % chunk_size != 0 and len(view) > chunk_size:
            cut = chunk_size - offset
            left, view = view[:cut], view[cut:]
            yield self.slice.start + offset, bytes(left)
            offset += len(left)
        while len(view) > 0:
            if len(view) > chunk_size:
                bs = len(view)
            else:
                bs = chunk_size
            left, view = view[:bs], view[bs:]
            yield self.slice.start + offset, bytes(left)
            offset += len(left)

    def dump_text(self):
        """Writes a disassembled text segment."""
        for part in self.slice.split(self.symbol_locs):
            assert part.start % 4 == 0, "misaligned text"
            self.emit_symbol(part.start)
            for ins in disasm_iter(self.get_data_chunk(part), part.start, self.symbols):
                print(ins.disassemble(dont_use_labels=self.is_rel), file=self.output)

    def dump_section_body(self):
        name = self.slice.section
        if "bss" in name:
            self.dump_bss()
        elif name == "text":
            self.dump_text()
        else:
            self.dump_data()

    def format_segname(self, name):
        if name in ("extab", "extabindex"):
            # The linker is supposed to auto-generate those.
            # It will crash if we try to feed it those sections with object files.
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
        if name == "text":
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

    def __init__(self, data, disaser, _slice, symbols, out_h, out_c, cpp_mode):
        self.data = data
        self.disaser = disaser
        self.slice = _slice
        self.symbols = symbols
        self.own_symbols = self.symbols.slice(self.slice.start, self.slice.stop)
        self.own_symbols.derive_sizes(self.slice.stop)
        self.out_h = out_h
        self.out_c = out_c
        self.cpp_mode = cpp_mode
        # The list of seen extern declarations.
        self.extern_addrs = set()
        self.extern_functions = []
        self.extern_data = []

    # Validated iterator of own_symbols
    def __symbols(self, addr):
        for sym in self.own_symbols:
            assert (
                sym.addr == addr
            ), f"Currently at {hex(addr)} but next symbol is at {hex(sym.addr)}"

            yield sym
            addr += sym.size

        assert addr == self.slice.stop, (
            f"Disassembled up to {hex(addr)} but slice goes to {hex(self.slice.stop)}.\n"
            + "You're probably missing entries in symbols.yml"
        )

    def dump_slice(self):
        """Writes the C file to output."""
        addr = self.slice.start
        functions = []

        for sym in self.__symbols(addr):
            func_body = self.disassemble_function(sym)
            functions.append(
                {
                    "addr": sym.addr,
                    "size": sym.size,
                    "name": sym.name,
                    "inline_asm": func_body,
                }
            )

        # Sort extern functions.
        self.extern_functions.sort(key=lambda ref: ref[0])
        self.extern_data.sort(key=lambda ref: ref[0])
        # Write out to C file.
        template = jinja_env.get_template("source.c.j2")
        template.stream(
            header=Path(self.out_h.name).name,
            cpp=self.cpp_mode,
            functions=functions,
            extern_functions=list({"name": a[1], "addr": a[0]} for a in self.extern_functions),
            extern_data=list({"name": a[1], "addr": a[0]} for a in self.extern_data),
        ).dump(self.out_c)
        # Write out to H file.
        template = jinja_env.get_template("source.h.j2")
        template.stream(functions=functions).dump(self.out_h)


    def __name_addr(self, addr):
        # If it's a known symbol, use its name.
        if addr in self.symbols:
            return self.symbols[addr]

        # If the target address is unknown we still need to create a symbol.
        ext_sym = Symbol(addr, "unk_%08x" % addr)
        self.symbols.put(ext_sym)
        return ext_sym


    def disassemble_function(self, sym):
        fn_start_vma = sym.addr
        fn_end_vma = fn_start_vma + sym.size
        inline_asm, refs = self.disaser.function_to_text_with_referenced(fn_start_vma, inline=True, extra=True,
            hashable=False, declare_mangled=False)
        for (addr, name) in refs:
            if addr not in self.extern_addrs:
                self.extern_addrs.add(addr)

                if is_text_addr(addr):
                    self.extern_functions.append((addr, name))
                else:
                    self.extern_data.append((addr, name))
        return inline_asm.split("\n")


def get_asm_path(folder, _slice):
    assert _slice.section is not None
    return folder / ("%s_%08x_%08x.s" % (_slice.section, _slice.start, _slice.stop))


INLINE_ASM_RE = '// Symbol: \S+(:?[^\n]*\n){1,3}MARK_BINARY_BLOB\([\s\n]*(\w+),[\s\n]*(\w+),[\s\n]*(\w+)[\s\n]*\);.*?}'
def replace_inline_asm(filestr, disaser, symbols):
    new_filestr = ""
    # The list of seen extern declarations
    extern_addrs = set()
    extern_functions = []
    extern_data = []
    template = jinja_env.get_template("source_fun.j2")
    prev_fn_end = 0
    for match in re.finditer(INLINE_ASM_RE, filestr, flags=re.DOTALL):
        assert len(match.groups()) == 4, "Unexpected inline function matching groups"
        print(match.group(0))
        fn_start = match.start()
        fn_end = match.end()
        fn_name = match.group(2)
        fn_start_vma = literal_eval(match.group(3))
        fn_end_vma = literal_eval(match.group(4))

        sym = symbols[fn_start_vma]
        if sym.size != fn_end_vma-fn_start_vma:
            ans = input(f"Detected size change " + \
                f"in inline ASM replacement of symbol {sym} " + \
                f"marked as 0x{fn_start_vma:x}-0x{fn_end_vma:x}, " + \
                f"in symbol map as 0x{sym.addr:x}-0x{(sym.addr+sym.size):x}." + \
                f"Do you want to update anyway? [y/n]")
            if ans != "y":
                continue

        print(f"Updating {sym.name}: L{fn_start}-L{fn_end} (0x{fn_start_vma:08x}-0x{fn_end_vma:08x})")
        inline_asm, refs = disaser.function_to_text_with_referenced(fn_start_vma, inline=True, \
            declare_mangled=False, end_addr=fn_end_vma)
        for (addr, name) in refs:
            if addr not in extern_addrs:
                extern_addrs.add(addr)
                if is_text_addr(addr):
                    extern_functions.append({"addr": addr, "name": name})
                else:
                    extern_data.append({"addr": addr, "name": name})
        new_asm_lines = inline_asm.split("\n")
        function = {"addr": fn_start_vma,
                    "size": fn_end_vma-fn_start_vma,
                    "name": fn_name,
                    "inline_asm": new_asm_lines}
        func_str = template.render(function=function)

        new_filestr += filestr[prev_fn_end:fn_start]
        new_filestr += func_str
        prev_fn_end = fn_end

    new_filestr += filestr[prev_fn_end:]
    return new_filestr, extern_functions, extern_data


def replace_source_extern_decls(filestr, extern_functions, extern_data, cpp_mode):
    template = jinja_env.get_template("source_decls.j2")
    decl_str = template.render(extern_functions=extern_functions, extern_data=extern_data, cpp=cpp_mode)
    new_filestr, count = re.subn(r'// --- EXTERN DECLARATIONS BEGIN ---\n.*' + \
        r'// --- EXTERN DECLARATIONS END ---\n', decl_str, filestr, count=1, flags=re.DOTALL)

    if count == 1:
        return new_filestr

    print(f"Warning: declarations not found, using old heuristics to add them")
    lines = filestr.split("\n")
    i = 0
    # search for extern "C" block. If it contains and UNKOWN_FUNCTION and // PAL, mark it to be replaced
    decl_str_lines = decl_str.split("\n")
    decls_start, decls_end = None, None
    unk_fun = True
    pal = True
    while i < len(lines):
        if decls_start is None:
            res = re.search(r'extern "C" {', lines[i])
            if res is not None:
                decls_start = i
        elif not unk_fun and re.search(r'extern UNKNOWN_FUNCTION(', lines[i]) is not None:
            unk_fun = True
        elif not pal and re.search(r'// PAL: ', lines[i]) is not None:
            pal = True
        else:
            res = re.search(r'}', lines[i])
            if res is not None and unk_fun and pal:
                decls_end = i
                break
            elif res is not None:
                decls_start, decls_end = None, None
                unk_fun = False
                pal = False

        i = i+1

    if decls_start is not None and decls_end is not None:
        del lines[decls_start:decls_end+1]
        for i,line in enumerate(decl_str_lines):
            lines.insert(decls_start+i, line)
        new_filestr = "\n".join(lines)
        return new_filestr
    else:
        print(f"Warning: old heuristics failed, just pasting new decls at file beginning")
        for i,line in enumerate(decl_str_lines):
            lines.insert(i, line)
        new_filestr = "\n".join(lines)
        return new_filestr


class DOLSrcGenerator:
    """Generates assembly files from DOL."""

    def __init__(
        self,
        slices: SliceTable,
        dol: DolBinary,
        disaser: Disassembler,
        symbols: SymbolsList,
        dol_asm_dir: Path,
        pack_dir: Path,
        regen_asm: bool,
        regen_inline: bool,
    ):
        self.slices = slices
        self.slices.set_sections(DOL_SECTIONS)
        self.dol = dol
        self.disaser = disaser
        self.symbols = symbols
        self.dol_asm_dir = dol_asm_dir
        self.pack_dir = pack_dir
        self.regen_asm = regen_asm
        self.regen_inline = regen_inline
        self.dol_asm_sources = set()
        self.dol_decomp_sources = set()

        dol_labels_path = Path("./mkwutil/ppcdis_adapter/externs.pickle")
        with open(dol_labels_path, 'rb') as dol_labels_file:
            self.extra_labels = pickle.load(dol_labels_file)
            self.extra_labels = self.extra_labels['labels']

    # Delete stale ASM files.
    def __prune_asm(self):
        for path in self.dol_asm_dir.iterdir():
            if path.suffix != ".s":
                continue
            if path.stem not in self.dol_asm_sources:
                os.remove(path)

    def __stem_for_asm_slice(self, _slice):
        if _slice.has_name():
            return Path(Path(_slice.name).name)

        return get_asm_path(Path("dol"), _slice)

    def __outpath_of_asm_slice(self, _slice):
        # Wrong term maybe
        stem = self.__stem_for_asm_slice(_slice)
        out_path = Path("out") / stem.with_suffix(".o")
        return str(out_path)

    # Iterator of all non-empty sections
    def __slice_sections(self):
        for _slice in self.slices:
            if _slice.section is None:
                continue

            yield _slice

    # Give all ASM slices a name. This makes the slice table unusable.
    def __name_asm_slices(self):
        for _slice in self.__slice_sections():
            _slice.name = self.__outpath_of_asm_slice(_slice)

    # Write list of objects for linker.
    def __write_objlist(self):
        # Drop slices smaller than 4 bytes.
        objects = self.slices.object_slices().objects
        for object in list(objects.keys()):
            # Drop slice.
            slices = objects[object]
            for i, slice in reversed(list(enumerate(slices))):
                if len(slice) < 4:
                    slices.pop(i)
            # Drop entire object if all slices have been removed.
            if len(slices) == 0:
                del objects[object]
        object_names = objects.keys()
        with open(self.pack_dir / "dol_objects.txt", "w") as file:
            for name in object_names:
                print(PurePosixPath(Path(name)), file=file)

    def run(self):
        """Runs ASM generation for main.dol."""
        for section in DOL_SECTIONS:
            self.__process_section(section)

        self.__prune_asm()
        self.__name_asm_slices()
        self.__write_objlist()

    def __process_section(self, section: Section):
        """Processes a program section and all its slices."""
        subtable = self.slices.slice(section.start, section.stop)
        # print(f".{section.name} ({section.type}): {subtable.count()} slices")
        for _slice in subtable:
            self.__process_slice(section, _slice)

    # If the slice should be output as a .s file
    def __slice_dest_asm(self, _slice):
        return not _slice.has_name()

    # If the slice should be output as a .c file
    def __slice_dest_c(self, _slice):
        return _slice.has_name()

    def __process_slice(self, section: Section, _slice: Slice):
        """Process a slice in slices.csv or a gap."""
        # print(f"  {_slice}")

        if self.__slice_dest_asm(_slice):
            self.__gen_asm(section, _slice)
            return

        # TODO Ideally this would work on the notion of objects instead of slices.
        if self.__slice_dest_c(_slice):
            source_path = Path(_slice.name)
            if source_path.stem not in self.dol_decomp_sources:
                self.dol_decomp_sources.add(source_path.stem)
            if section.type == "code":
                self.__gen_c(_slice)

    def __gen_c(self, _slice: Slice):
        """Generates a C file with inline assembly if not exists."""
        # Generate C inline assembly.
        c_path = Path(_slice.name)
        h_path = c_path.with_suffix(".h" if str(c_path).endswith(".c") else ".hpp")
        if c_path.exists() or h_path.exists():
            """
            if self.regen_inline and (str(c_path).endswith(".c") or str(c_path).endswith(".cpp")):
                print(c_path)
                with open(c_path) as file:
                    filestr = file.read()
                    new_filestr, extern_functions, extern_data = replace_inline_asm(filestr, self.disaser, self.symbols)
                    if len(extern_functions) != 0 or len(extern_data) != 0:
                        cpp_mode = not str(c_path).endswith(".c")
                        new_filestr = replace_source_extern_decls(new_filestr, extern_functions, extern_data, cpp_mode)
                #print(new_filestr)

                with open(c_path, "w") as c_file:
                    c_file.write(new_filestr)
            """
            return

        c_path.parent.mkdir(parents=True, exist_ok=True)
        # print(f"    => {_slice.name}")
        data = self.dol.virtual_read(_slice.start, len(_slice))
        with open(h_path, "w") as h_file, open(c_path, "w") as c_file:
            gen = CAsmGenerator(
                data,
                self.disaser,
                _slice,
                self.symbols,
                h_file,
                c_file,
                not str(c_path).endswith(".c"),
            )
            gen.dump_slice()

    def __gen_asm(self, section: Section, _slice: Slice):
        """Generates an ASM file."""
        # Relocatable ASM unsupported for DOL
        """
        asm_path = get_asm_path(self.dol_asm_dir, _slice)
        self.dol_asm_sources.add(asm_path.stem)
        if not self.regen_asm and asm_path.exists():
            return
        # print(f"    => {asm_path}")
        self.disaser.output_slice(asm_path, _slice.start, _slice.start+len(_slice))
        """
        asm_path = get_asm_path(self.dol_asm_dir, _slice)
        self.dol_asm_sources.add(asm_path.stem)
        if not self.regen_asm and asm_path.exists():
            return
        # print(f"    => {asm_path}")
        with open(asm_path, "w") as asm_file:
            data = (
                self.dol.virtual_read(_slice.start, len(_slice))
                if section.type != "bss"
                else None
            )
            gen = AsmGenerator(data, _slice, self.symbols, asm_file, self.extra_labels)
            gen.dump_section()


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
        pack_dir: Path,
        regen_asm: bool,
        regen_inline: bool,
    ):
        self.slices = slices
        self.slices.set_sections(REL_SECTIONS)
        self.rel = rel
        self.disaser = disaser
        self.symbols = symbols
        self.rel_asm_dir = rel_asm_dir
        self.rel_bin_dir = rel_bin_dir
        self.pack_dir = pack_dir
        self.regen_asm = regen_asm
        self.regen_inline = regen_inline
        self.rel_asm_sources = set()
        self.rel_decomp_sources = set()

    def run(self):
        """Runs ASM generation for StaticR.rel"""
        for section in REL_SECTIONS:
            self.__process_section(section)
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

    def __process_slice(self, section: Section, _slice: Slice):
        """Process a slice in slices.csv or a gap."""
        # print(f"  {_slice}")

        if self.__slice_dest_asm(_slice):
            self.__gen_asm(section, _slice)
            return

        # TODO Ideally this would work on the notion of objects instead of slices.
        if self.__slice_dest_c(_slice):
            source_path = Path(_slice.name)
            if source_path.stem not in self.rel_decomp_sources:
                self.rel_decomp_sources.add(source_path.stem)
            if section.type == "code":
                self.__gen_c(_slice)


    def __gen_c(self, _slice: Slice):
        """Generates a C file with inline assembly if not exists."""
        # Generate C inline assembly.
        c_path = Path(_slice.name)
        h_path = c_path.with_suffix(".h" if str(c_path).endswith(".c") else ".hpp")
        if c_path.exists() or h_path.exists():
            if self.regen_inline:
                with open(c_path) as file:
                    filestr = file.read()
                    new_filestr, extern_functions, extern_data = replace_inline_asm(filestr, self.disaser, self.symbols)
                    if len(extern_functions) != 0 or len(extern_data) != 0:
                        cpp_mode = not str(c_path).endswith(".c")
                        new_filestr = replace_source_extern_decls(new_filestr, extern_functions, extern_data, cpp_mode)

                with open(c_path, "w") as c_file:
                    c_file.write(new_filestr)

            return

        c_path.parent.mkdir(parents=True, exist_ok=True)
        # print(f"    => {_slice.name}")
        data = self.rel.virtual_read(
            _slice.start, len(_slice), REL_SECTIONS, REL_SECTION_IDX
        )
        with open(h_path, "w") as h_file, open(c_path, "w") as c_file:
            gen = CAsmGenerator(
                data,
                self.disaser,
                _slice,
                self.symbols,
                h_file,
                c_file,
                not str(c_path).endswith(".c"),
            )
            gen.dump_slice()

    def __gen_asm(self, section: Section, _slice: Slice):
        """Generates an ASM file."""
        asm_path = get_asm_path(self.rel_asm_dir, _slice)
        self.rel_asm_sources.add(asm_path.stem)
        if not self.regen_asm and asm_path.exists():
            return
        # print(f"    => {asm_path}")
        self.disaser.output_slice(asm_path, _slice.start, _slice.start+len(_slice))


def gen_asm(regen_asm=False, regen_inline=False):
    asm_dir = Path("./asm")
    pack_dir = Path("./pack")
    binary_dir = Path("./artifacts/orig/pal")

    asm_dir.mkdir(exist_ok=True)

    symbols = read_symbol_map(pack_dir / "symbols.yml")
    symbols.derive_sizes(0x81000000)

    dol = read_dol(binary_dir / "main.dol")
    dol_disaser = get_dol_disaser()
    dol_slices = read_enabled_slices(dol, pack_dir / "dol_slices.csv")

    # Disassemble DOL sections.
    dol_asm_dir = asm_dir / "dol"
    dol_asm_dir.mkdir(exist_ok=True)
    dol_gen = DOLSrcGenerator(
        dol_slices, dol, dol_disaser, symbols, dol_asm_dir, pack_dir, regen_asm, regen_inline
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
        rel_slices, rel, rel_disaser, symbols, rel_asm_dir, rel_bin_dir, pack_dir, regen_asm, regen_inline
    )
    rel_gen.run()


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Generate ASM blobs and linker object lists."
    )
    parser.add_argument("--regen_asm", action="store_true", help="Regenerate all ASM files")
    parser.add_argument("--regen_inline", action="store_true", help="Regenerate all inline ASM")
    args = parser.parse_args()
    gen_asm(args.regen_asm, args.regen_inline)
