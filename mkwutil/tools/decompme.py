"""
Creates a decomp.me scratch for a function
Inspired by https://github.com/SeekyCt/spm-decomp/blob/master/decompme.py
Modified for mkw ops
"""

from argparse import ArgumentParser
from pathlib import Path
import os

import requests

from mkwutil.tools.create_ctx import get_ctx
from mkwutil.project import read_symbol_map
from mkwutil.ppcdis_adapter.ppcdis_disas import get_dol_disaser, get_rel_disaser
from configure import CWCC_OPT
from ast import literal_eval

# Get arguments
parser = ArgumentParser()
parser.add_argument("sym", type=str, help="Symbol name or address")
parser.add_argument("-m", "--match", type=str, help="String contained in desired context header file")
parser.add_argument("--host", default="https://decomp.me")
args = parser.parse_args()

# Find address and diff_label
symbols = read_symbol_map(Path("pack") / "symbols.yml")
symbols.derive_sizes(0x8100_0000)
try:
    addr = literal_eval(args.sym)
    sym = symbols.get(addr)
except:
    sym = symbols.get_by_name(args.sym)
if sym is not None:
    addr = sym.addr
    diff_label = sym.name
else:
    print(f"Could not find symbol with name/address {args.sym}")
    exit(-1)

# Get flags for binary
if addr < 0x8050_0000:
    preset = "Mario Kart Wii (DOL)"
    disaser = get_dol_disaser()
else:
    preset = "Mario Kart Wii (REL)"
    disaser = get_rel_disaser()

# Disassemble function
fn_start_vma = addr
fn_end_vma = fn_start_vma + sym.size
asm = disaser.function_to_text(fn_start_vma, inline=False, extra=True,
            hashable=False, declare_mangled=False)

# Get context
tmpfile = Path("ctx.hpp")
source = get_ctx(args.match, tmpfile, verbose=False)
flags = CWCC_OPT + ' ' + source.opts
with open(tmpfile, 'r') as file:
    ctx = file.read()
os.unlink(tmpfile)

# Send request
req = {
    "target_asm" : asm,
    "context" : ctx,
    "platform" : "gc_wii",
# TODO: Different compiler for DOL
    "compiler" : 89,
    "compiler_flags" : flags,
    "preset" : preset,
    "diff_label" : diff_label
}
r = requests.post(args.host + "/api/scratch", json=req)
assert r.status_code == 201, f"Bad status code {r.status_code}"
print(args.host + r.json()["html_url"])
