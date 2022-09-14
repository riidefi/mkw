"""
Script to verify the target main.dol for authenticity.
"""

import argparse
from colorama import Fore, Style
from pathlib import Path
import sys

from mkwutil.lib.dol import DolBinary
from mkwutil.lib.verify_binary import *

from mkwutil.sections import DOL_SECTIONS

# https://stackoverflow.com/questions/312443/how-do-you-split-a-list-into-evenly-sized-chunks
def chunks(lst, n):
    """Yield successive n-sized chunks from lst."""
    for i in range(0, len(lst), n):
        yield lst[i:i + n]

def verify_dol(reference: Path, target: Path):
    """Verifies the target main.dol for authenticity."""
    print("[DOL] Verifying...")

    content = open(target, "rb").read()
    if check_hash(content, "ac7d72448630ade7655fc8bc5fd7a6543cb53a49"):
        print(
            Fore.GREEN
            + Style.BRIGHT
            + "[DOL] Everything went okay! Output is matching! ^^"
            + Style.RESET_ALL
        )
        return

    want_len = 2766496
    if len(content) != want_len:
        print(
            (Fore.RED + "Mismatched file size: Got %d (%+d)" + Style.RESET_ALL)
            % (len(content), len(content) - want_len)
        )

    with open(reference, "rb") as file:
        good = DolBinary(file)
    with open(target, "rb") as file:
        bad = DolBinary(file)

    for i in range(0, DolBinary.SEGMENT_COUNT):
        good_segment = good.segments[i]
        bad_segment = bad.segments[i]
        if len(good_segment) == 0:
            continue
        match = good_segment.data == bad_segment.data
        tag = "OK" if match else "FAIL"
        if good_segment is not None and len(good_segment) != len(bad_segment):
            tag = "SIZE"
        print(
            format_segment(
                good_segment.name(),
                good_segment.start,
                bad_segment.start,
                len(good_segment),
                len(bad_segment),
                tag,
            )
        )
        if not match:
            amount_printed = 0
            for vaddr in range(min(good_segment.start, bad_segment.start), max(good_segment.stop, bad_segment.stop), 4):
                good_bytes = good.virtual_read_word(vaddr)
                bad_bytes = bad.virtual_read_word(vaddr)

                if good_bytes == bad_bytes or amount_printed > 10:
                    continue
                print("%x: Good=%x Bad=%x" % (vaddr, good_bytes, bad_bytes))
                amount_printed += 1
    print(
        format_segment(
            "bss",
            good.bss.start,
            bad.bss.stop,
            len(good.bss),
            len(bad.bss),
            "OK" if len(good.bss) == len(bad.bss) else "SIZE",
        )
    )
    # TODO: Add diff'ing

    print(
        Fore.RED + Style.BRIGHT + "[DOL] Oof: Output doesn't match." + Style.RESET_ALL
    )

    sys.exit(1)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--reference", type=Path, required=True, help="Path to reference main.dol"
    )
    parser.add_argument(
        "--target", type=Path, required=True, help="Path to target main.dol"
    )
    args = parser.parse_args()

    verify_dol(args.reference, args.target)
