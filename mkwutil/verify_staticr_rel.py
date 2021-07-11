"""
Script to verify the target StaticR.rel for authenticity.
"""

import argparse
from colorama import Fore, Style
import hashlib
from pathlib import Path

def verify_rel(target):
    """Verifies the target StaticR.rel for authenticity."""
    content = open(target, "rb").read()
    ctx = hashlib.sha1(content)
    digest = ctx.hexdigest()
    if digest.lower() == "887bcc076781f5b005cc317a6e3cc8fd5f911300":
        print(Fore.GREEN + Style.BRIGHT + "[REL] Everything went okay! Output is matching! ^^" + Style.RESET_ALL)
        return

    want_len = 4903876
    if len(content) != want_len:
        print(Fore.RED + f"Mismatched file size: Got {len(content)} ({len(content)-want_len})" + Style.RESET_ALL)

    print(Fore.RED + Style.BRIGHT + "[REL] Oof: Output doesn't match." + Style.RESET_ALL)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--target", type=Path, required=True, help="Path to target main.dol"
    )
    args = parser.parse_args()

    verify_rel(args.target)
