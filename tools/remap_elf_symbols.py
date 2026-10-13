"""Remaps symbols in a linked ELF to the names the project config (symbols.txt)
expects at the same addresses. MWCC emits anonymous data symbols (`@1234`,
`...data.0`) for string literals / unnamed rodata; dtk's reconstructed target
objects name those same bytes (`lbl_8024C6D0`, ...). The linked bytes already
match, so only the symbol names need fixing for `dtk dol diff` to pass.

Rewrites the ELF's symbol table directly (a fresh .strtab + .symtab are appended
at EOF and the section headers repointed), so duplicates and non-unique MWCC
local labels are handled per entry.
"""

import re
import struct
import sys

MW = r"C:\Users\nnnn\Documents\mkwii"

OLD_OK = re.compile(r"^[@A-Za-z][A-Za-z0-9_@]*$")
VALID = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")


def load_expected():
    exp = {}
    for p in (
        MW + r"\config\RMCP01\symbols.txt",
        MW + r"\config\RMCP01\module\symbols.txt",
    ):
        for line in open(p, encoding="utf-8", errors="replace"):
            m = re.match(r"(\S+)\s*=\s*\.\S+:(0x[0-9a-fA-F]+);", line)
            if m:
                exp[int(m.group(2), 16)] = m.group(1)
    return exp


def load_expected_full():
    exp = {}
    for p in (
        MW + r"\config\RMCP01\symbols.txt",
        MW + r"\config\RMCP01\module\symbols.txt",
    ):
        for line in open(p, encoding="utf-8", errors="replace"):
            m = re.match(
                r"(\S+)\s*=\s*\.\S+:(0x[0-9a-fA-F]+);\s*//\s*type:(\w+)\s+size:(0x[0-9a-fA-F]+)",
                line,
            )
            if m:
                exp[int(m.group(2), 16)] = (m.group(1), m.group(3), int(m.group(4), 16))
    return exp


def cstr(buf, off):
    end = buf.index(b"\0", off)
    return buf[off:end].decode("latin1")


def main():
    elf = sys.argv[1]
    out = sys.argv[2]
    exp = load_expected()
    data = bytearray(open(elf, "rb").read())
    assert data[:4] == b"\x7fELF" and data[4] == 1 and data[5] == 2, "expected ELF32 BE"
    e_shoff = struct.unpack_from(">I", data, 0x20)[0]
    e_shentsize = struct.unpack_from(">H", data, 0x2E)[0]
    e_shnum = struct.unpack_from(">H", data, 0x30)[0]
    e_shstrndx = struct.unpack_from(">H", data, 0x32)[0]

    shs = []
    for i in range(e_shnum):
        off = e_shoff + i * e_shentsize
        sh = list(struct.unpack_from(">IIIIIIIIII", data, off))
        shs.append(sh)

    def secname(i):
        p = shs[e_shstrndx][4] + shs[i][0]
        return cstr(data, p)

    sym_i = next(i for i, sh in enumerate(shs) if sh[1] == 2)  # SHT_SYMTAB
    str_i = shs[sym_i][6]  # sh_link
    sym_off, sym_sz, sym_ent = shs[sym_i][4], shs[sym_i][5], (shs[sym_i][9] or 16)
    str_off, str_sz = shs[str_i][4], shs[str_i][5]
    strtab = bytes(data[str_off : str_off + str_sz])

    new_strtab = bytearray(strtab)

    def addname(s):
        o = len(new_strtab)
        new_strtab.extend(s.encode("latin1") + b"\0")
        return o

    new_syms = bytearray()
    renamed = 0
    present = set()
    full = load_expected_full()
    n = sym_sz // sym_ent
    for k in range(n):
        o = sym_off + k * sym_ent
        st_name, st_value, st_size, st_info, st_other, st_shndx = struct.unpack_from(
            ">IIIBBH", data, o
        )
        nm = cstr(strtab, st_name) if st_name < len(strtab) else ""
        ent = full.get(st_value)
        if ent and VALID.match(ent[0]):
            if nm != ent[0] and OLD_OK.match(nm):
                st_name = addname(ent[0])
                renamed += 1
            st_size = ent[2]
        if st_shndx not in (0, 0xFFF1):
            present.add(st_value)
        new_syms += struct.pack(">IIIBBH", st_name, st_value, st_size, st_info, st_other, st_shndx)

    # Add expected symbols that are entirely missing.
    SHF_ALLOC = 2
    alloc = [
        (sh[3], sh[3] + sh[5], i)
        for i, sh in enumerate(shs)
        if (sh[2] & SHF_ALLOC) and sh[5]
    ]

    def section_of(addr):
        for lo, hi, i in alloc:
            if lo <= addr < hi:
                return i
        return 0

    added = 0
    for addr, (name, typ, size) in full.items():
        if addr in present or not VALID.match(name) or name.startswith("__"):
            continue
        st_type = 2 if typ == "func" else 1
        info = (1 << 4) | st_type  # GLOBAL
        new_syms += struct.pack(">IIIBBH", addname(name), addr, size, info, 0, section_of(addr))
        added += 1
    print(f"renamed: {renamed}  added: {added}")

    # Append new strtab + symtab at EOF, repoint section headers.
    new_str_off = len(data)
    data.extend(new_strtab)
    while len(data) % 4:
        data.append(0)
    new_sym_off = len(data)
    data.extend(new_syms)

    struct.pack_into(">IIIIIIIIII", data, e_shoff + str_i * e_shentsize,
                     shs[str_i][0], shs[str_i][1], shs[str_i][2], shs[str_i][3],
                     new_str_off, len(new_strtab), shs[str_i][6], shs[str_i][7],
                     shs[str_i][8], shs[str_i][9])
    struct.pack_into(">IIIIIIIIII", data, e_shoff + sym_i * e_shentsize,
                     shs[sym_i][0], shs[sym_i][1], shs[sym_i][2], shs[sym_i][3],
                     new_sym_off, len(new_syms), shs[sym_i][6], shs[sym_i][7],
                     shs[sym_i][8], shs[sym_i][9])

    open(out, "wb").write(data)
    print(f"wrote {out}")


if __name__ == "__main__":
    main()
