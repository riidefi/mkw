#!/usr/bin/env python3
"""Patcher for the experimental MWCC Wii/0x4201_127 allocator tweak used while
matching KartState::updateCollisions.

IMPORTANT / CAVEATS (read first)
--------------------------------
* This makes the build NON-STANDARD: the resulting object is not reproducible
  with the stock `mwcceppc.exe`. It is a research artifact, NOT wired into
  configure.py.
* The patch is *source-build specific*: it hard-codes the virtual-register ids
  (82 = the `kartStateReload()` pointer temp, 91 = the `flags0 & 0x60` mask
  temp) of the current `src/kart/KartState.cpp`. Any source edit that renumbers
  those temps invalidates it.
* It is function-gated: it only fires when the current function's name is
  "updateCollisions" (class 4 = GPR colouring in `_colorinstructions`).
* Effect: swaps the scratch-register colouring of those two webs from the
  compiler's default (v91->r5, v82->r6) to retail's (v82->r5, v91->r6).
  Measured: updateCollisions objdiff 97.7327 -> 98.4487.
* It does NOT fix the remaining ~13 mismatches in the dot/sqrt block, which a
  scheduler sweep showed are not compiler-tie-break reachable (they follow from
  the interference graph / PCode, i.e. the source).

Usage:
    python tools/mwcc_patch_updateCollisions.py <src_compiler_dir> <dst_dir>
Then compile with <dst_dir>/mwcceppc.exe.
"""
import os
import shutil
import sys

HOOK_RVA = 0x1B4420
HOOK_OLD = bytes.fromhex("66894312ebb8")
HOOK_NEW = bytes.fromhex("e9d5820b0090")
CAVE_RVA = 0x26C6FA
CAVE = bytes.fromhex(
    "803d95c376000475498b0d441e750085c9743f8b490c85c9743881790a7570646175"
    "2f81790e7465436f75268179126c6c6973751d817916696f6e73751480791a0075"
    "0e66837b105b741066837b1052740f66894312e9897cf4ff66b80600ebf166b805"
    "00ebeb")
TEXT_VA, TEXT_RAW = 0x1000, 0x400


def rva_to_offset(rva: int) -> int:
    return rva - TEXT_VA + TEXT_RAW


def main() -> int:
    if len(sys.argv) != 3:
        print(__doc__)
        return 2
    src, dst = sys.argv[1], sys.argv[2]
    if os.path.exists(dst):
        shutil.rmtree(dst)
    shutil.copytree(src, dst)
    exe = os.path.join(dst, "mwcceppc.exe")
    with open(exe, "rb") as fh:
        data = bytearray(fh.read())

    o = rva_to_offset(HOOK_RVA)
    if bytes(data[o:o + len(HOOK_OLD)]) != HOOK_OLD:
        print("ERROR: hook bytes at RVA 0x%X are %s, expected %s" %
              (HOOK_RVA, data[o:o + len(HOOK_OLD)].hex(), HOOK_OLD.hex()))
        return 1
    data[o:o + len(HOOK_NEW)] = HOOK_NEW

    c = rva_to_offset(CAVE_RVA)
    if any(b != 0 for b in data[c:c + len(CAVE)]):
        print("ERROR: cave region at RVA 0x%X is not zeroed" % CAVE_RVA)
        return 1
    data[c:c + len(CAVE)] = CAVE

    with open(exe, "wb") as fh:
        fh.write(data)
    print("patched %s -> %s (hook 0x%X, cave 0x%X, %d bytes)" %
          (src, dst, HOOK_RVA, CAVE_RVA, len(CAVE)))
    print("NOTE: non-standard compiler; source-build specific; see docstring.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
