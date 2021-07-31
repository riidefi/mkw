"""
Script to verify the target StaticR.rel for authenticity.
"""

import argparse
from colorama import Fore, Style
from pathlib import Path
import sys

from .lib.rel import Rel
from .lib.verify_binary import *
from .sections import REL_SECTIONS, REL_SECTION_IDX


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

    for i, idx in enumerate(REL_SECTION_IDX):
        good_section = good.section_info[idx]
        bad_section = bad.section_info[idx]
        match = good_section.data == bad_section.data
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

    verify_rel(args.target)
