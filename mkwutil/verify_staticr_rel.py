"""
Script to verify the target StaticR.rel for authenticity.
"""

import argparse
from colorama import Fore, Style
from pathlib import Path
import struct
import sys
import os

from elftools.elf.elffile import ELFFile, Section as ELFSection

from mkwutil.lib.rel import Rel, RelSection
from mkwutil.lib.verify_binary import *
from mkwutil.project import *
from mkwutil.sections import REL_SECTIONS, REL_SECTION_IDX, Section
from mkwutil.lib.symbols import SymbolsList, Symbol

from ppcdis import diff_relocs, load_binary_yml

# https://stackoverflow.com/questions/312443/how-do-you-split-a-list-into-evenly-sized-chunks
def chunks(lst, n):
    """Yield successive n-sized chunks from lst."""
    for i in range(0, len(lst), n):
        yield lst[i:i + n]

# returns whether the section was equal or not. If not equal, the second return value contains the region that failed
def compare_section_data(good_section: RelSection, bad_section: RelSection, info: Section, dataflow_funcs):
    if info.name != "text":
        return good_section.data == bad_section.data, (info.start, info.start + len(info))
    else:
        # check all section regions except those occupied by function to be checked by the flow-checker
        match = True
        reg_start = 0
        for addr, size, name in dataflow_funcs:
            assert info.start <= addr and addr+size <= info.stop, "Can't dataflow-compare region outside .text!"
            func_off = addr - info.start
            assert func_off >= reg_start, "dataflow-checked functions must be non-overlapping and in incresing order"

            match = good_section.data[reg_start:func_off] == bad_section.data[reg_start:func_off] and match
            if not match:
                return match, (info.start + reg_start, info.start + func_off)

            reg_start = func_off + size
        
        func_off = len(info)
        match = good_section.data[reg_start:func_off] == bad_section.data[reg_start:func_off] and match

        return match, (info.start + reg_start, info.start + func_off)


def __native_binary(path):
    if sys.platform == "win32" or sys.platform == "msys":
        return path + ".exe"
    return path


def get_dataflow_addrs(elf: ELFFile):
    dataflow_func_addrs = []
    addrs_raw: ELFSection = elf.get_section_by_name("flow_check")
    if not addrs_raw:
        return dataflow_func_addrs
    for addr in struct.iter_unpack(">I", addrs_raw.data()):
        dataflow_func_addrs.append(addr[0])

    return dataflow_func_addrs


PPC2CPP = __native_binary(os.path.join("tools", "ppc2cpp", "bin", "ppc2cpp"))
def check_dataflow_funcs(dataflow_funcs):
    if len(dataflow_funcs) > 0:
        dataflow_func_names = list(map(lambda x: x[2], dataflow_funcs))
        print("flow-equivalent funcs: " + " ".join(dataflow_func_names))
        orig_ppc2cpp_proj = Path("artifacts", "orig", "pal", "orig.ppc2cpp")
        target_ppc2cpp_proj = Path("artifacts", "orig", "pal", "target.ppc2cpp")
        import subprocess
        ppc2cpp_args = [str(PPC2CPP), "checkflow",  str(orig_ppc2cpp_proj), str(target_ppc2cpp_proj)] + dataflow_func_names
        completedProc = subprocess.run(ppc2cpp_args)
        return completedProc.returncode


def get_dataflow_funcs(target):
    pack_dir = Path("./pack")
    symbols = read_symbol_map(pack_dir / "symbols.yml")
    symbols.derive_sizes(0x81000000)
    dataflow_funcs = []
    for addr in get_dataflow_addrs(ELFFile(target)):
        sym = symbols[addr]
        dataflow_funcs.append((addr, sym.size, sym.name))
    from functools import cmp_to_key
    def dataflow_func_comparator(x, y):
        return x[0] - y[0]
    dataflow_funcs = sorted(dataflow_funcs, key=cmp_to_key(dataflow_func_comparator))
    return dataflow_funcs


def verify_rel(reference: Path, target: Path):
    """Verifies the target StaticR.rel for authenticity."""
    print("[REL] Verifying...")

    with open(target.with_suffix(".elf"), "rb") as elffile:
        dataflow_funcs = get_dataflow_funcs(elffile)

    content = open(target, "rb").read()
    if check_hash(content, "887bcc076781f5b005cc317a6e3cc8fd5f911300"):
        print(
            Fore.GREEN
            + Style.BRIGHT
            + "[REL] Everything went okay! Output is matching! ^^"
            + Style.RESET_ALL
        )
        return

    want_len = 4903876
    if len(content) != want_len:
        print(
            Fore.RED
            + f"Mismatched file size: Got {len(content)} ({len(content)-want_len})"
            + Style.RESET_ALL
        )

    with open(reference, "rb") as file:
        good = Rel(file)
    with open(target, "rb") as file:
        bad = Rel(file)

    section_match = True
    for i, idx in enumerate(REL_SECTION_IDX):
        good_section = good.section_info[idx]
        bad_section = bad.section_info[idx]
        info = REL_SECTIONS[idx - 1]
        match, region = compare_section_data(good_section, bad_section, info, dataflow_funcs)
        section_match = section_match and match
        tag = "OK" if match else "FAIL"
        if good_section.length != bad_section.length:
            tag = "SIZE"
        print(
            format_segment(
                REL_SECTIONS[i].name,
                good_section.offset,
                bad_section.offset,
                good_section.length,
                bad_section.length,
                tag,
            )
        )
        if not match:
            slices = load_rel_slices(sections=REL_SECTIONS)

            paired_data = zip(chunks(good_section.data, 4), chunks(bad_section.data, 4))
            amount_printed = 0

            for i, (good_bytes, bad_bytes) in enumerate(paired_data):
                vaddr = info.start + i * 4

                if vaddr < region[0] or vaddr > region[1]:
                    continue
                if good_bytes == bad_bytes or amount_printed > 10:
                    continue
                print("%x: Good=%x Bad=%x" % (vaddr, struct.unpack(">I", good_bytes)[0], struct.unpack(">I", bad_bytes)[0]))
                slice_it, slice_i = slices.find(vaddr)
                if slice_it:
                    print(" -> This is in %s" % slice_it)
                amount_printed += 1


    binary_diff_exitcode = 0 if section_match else 1
    if section_match:
        orig_yaml = str(Path("mkwutil/ppcdis_adapter/rel.yaml"))
        good = load_binary_yml(orig_yaml)
        test = good.load_other(target)
        reloc_match = not diff_relocs(good, test, max_diffs=20)

        if reloc_match:
            binary_diff_exitcode = check_dataflow_funcs(dataflow_funcs)
        else:
            binary_diff_exitcode = 1

    if binary_diff_exitcode != 0:
        print(
            Fore.RED + Style.BRIGHT + "[REL] Oof: Output doesn't match." + str(binary_diff_exitcode) + Style.RESET_ALL
        )
    else:
        print(
            Fore.GREEN
            + Style.BRIGHT
            + "[REL] Everything went okay! Output looks equivalent. :p"
            + Style.RESET_ALL
        )

    sys.exit(binary_diff_exitcode)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--reference", type=Path, required=True, help="Path to reference StaticR.rel"
    )
    parser.add_argument(
        "--target", type=Path, required=True, help="Path to target StaticR.rel"
    )
    args = parser.parse_args()

    verify_rel(args.reference, args.target)
