"""
Script to verify the target main.dol for authenticity.
"""

import argparse
import hashlib
from pathlib import Path

from mkw.dol import DolBinary


def format_segment(name, at, at2, want_size, have_size, tag):
    return "%10s: at_src=0x%08x at_dst=0x%08x want=0x%08x have=0x%08x [%s]" % (name, at, at2, want_size, have_size, tag)


def verify_dol(reference, target):
    """Verifies the target main.dol for authenticity."""
    print("[DOL] Verifying...")
    content = open(target, "rb").read()
    ctx = hashlib.sha1(content)
    digest = ctx.hexdigest()
    if digest.lower() == "ac7d72448630ade7655fc8bc5fd7a6543cb53a49":
        print("[DOL] Everything went okay! Output is matching! ^^")
        return

    want_len = 2766496
    if len(content) != want_len:
        print("Mismatched file size: Got %d (%+d)" % (len(content), want_len-len(content)))

    good = DolBinary(reference)
    bad = DolBinary(target)

    text_names = [
        "init",
        "text"
    ]
    data_names = [
        "extab",
        "extabindex",
        "ctors",
        "dtors",
        "rodata",
        "data",
        "sdata",
        "sdata2",
    ]

    for i, sizes in enumerate(zip(good.text_size, bad.text_size)):
        if sizes[0] == 0 and sizes[1] == 0:
            continue
        good_segment = good.get_text_segment(i)
        bad_segment = bad.get_text_segment(i)
        match = good_segment == bad_segment
        tag = "OK" if match else "FAIL"
        if len(good_segment) != len(bad_segment):
            tag = "SIZE"
        print(format_segment(text_names[i], good.text_segs[i].begin, bad.text_segs[i].begin, sizes[0], sizes[1], tag))
    for i, sizes in enumerate(zip(good.data_size, bad.data_size)):
        if sizes[0] == 0 and sizes[1] == 0:
            continue
        good_segment = good.get_data_segment(i)
        bad_segment = bad.get_data_segment(i)
        match = good_segment == bad_segment
        tag = "OK" if match else "FAIL"
        if len(good_segment) != len(bad_segment):
            tag = "SIZE"
        print(format_segment(data_names[i], good.data_segs[i].begin, bad.data_segs[i].begin, sizes[0], sizes[1], tag))
    # TODO: Add diff'ing
    
    print("[DOL] Oof: Output doesn't match.")


parser = argparse.ArgumentParser()
parser.add_argument("--reference", type=Path, required=True, help="Path to reference main.dol")
parser.add_argument("--target", type=Path, required=True, help="Path to target main.dol")
args = parser.parse_args()

verify_dol(args.reference, args.target)
