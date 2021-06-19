"""
Script to verify the target StaticR.rel for authenticity.
"""

import argparse
import hashlib
from pathlib import Path


def verify_rel(target):
    """Verifies the target StaticR.rel for authenticity."""
    content = open(target, "rb").read()
    ctx = hashlib.sha1(content)
    digest = ctx.hexdigest()
    if digest.lower() == "887bcc076781f5b005cc317a6e3cc8fd5f911300":
        print("[REL] Everything went okay! Output is matching! ^^")
        return

    want_len = 4903876
    if len(content) != want_len:
        print(f"Mismatched file size: Got {len(content)} ({len(content)-want_len})")

    print("[REL] Oof: Output doesn't match.")


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--target", type=Path, required=True, help="Path to target main.dol"
    )
    args = parser.parse_args()

    verify_rel(args.target)
