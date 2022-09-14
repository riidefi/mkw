"""
Script to verify the target StaticR.rel for authenticity.
"""

import argparse
from colorama import Fore, Style
from pathlib import Path
import struct
import sys

from mkwutil.lib.rel import Rel
from mkwutil.lib.verify_binary import *
from mkwutil.sections import REL_SECTIONS, REL_SECTION_IDX

from ppcdis import diff_relocs, load_binary_yml

# https://stackoverflow.com/questions/312443/how-do-you-split-a-list-into-evenly-sized-chunks
def chunks(lst, n):
    """Yield successive n-sized chunks from lst."""
    for i in range(0, len(lst), n):
        yield lst[i:i + n]

def verify_rel(reference: Path, target: Path):
    """Verifies the target StaticR.rel for authenticity."""
    print("[REL] Verifying...")

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
        match = good_section.data == bad_section.data
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
            paired_data = zip(chunks(good_section.data, 4), chunks(bad_section.data, 4))
            amount_printed = 0

            for i, (good_bytes, bad_bytes) in enumerate(paired_data):
                vaddr = info.start + i * 4

                if good_bytes == bad_bytes or amount_printed > 10:
                    continue
                print("%x: Good=%x Bad=%x" % (vaddr, struct.unpack(">I", good_bytes)[0], struct.unpack(">I", bad_bytes)[0]))
                amount_printed += 1

    if section_match:
        orig_yaml = str(Path("mkwutil/ppcdis_adapter/rel.yaml"))
        good = load_binary_yml(orig_yaml)
        test = good.load_other(target)
        diff_relocs(good, test)

    print(
        Fore.RED + Style.BRIGHT + "[REL] Oof: Output doesn't match." + Style.RESET_ALL
    )

    sys.exit(1)


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
