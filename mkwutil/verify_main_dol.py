"""
Script to verify the target main.dol for authenticity.
"""

import argparse
from colorama import Fore, Style
from pathlib import Path
import sys

from .lib.dol import DolBinary
from .lib.verify_binary import *


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
