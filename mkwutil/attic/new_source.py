"""
Use this to quickly add a new C source to slices and sources.
This action gets extremely repetitive while splitting.
"""

import argparse
from mkwutil.lib.slices import Slice

from mkwutil.project import load_dol_slices, save_dol_slices

parser = argparse.ArgumentParser(description="Add new file to slices and sources.py")
parser.add_argument(
    "--source_group",
    type=str,
    required=True,
    help="Group in sources.py, e.g. SOURCES_RVL_OS",
)
parser.add_argument(
    "--path", type=str, required=True, help="File path, e.g. source/rvl/os/osAlarm.c"
)
parser.add_argument(
    "--text", type=str, required=True, help="Text range, e.g. 0x12345678..0x12345678"
)
args = parser.parse_args()

[text_start, text_stop] = args.text.split("..", 2)
text_start = int(text_start, 16)
text_stop = int(text_stop, 16)

slices = load_dol_slices()
slices.add(Slice(start=text_start, stop=text_stop, name=args.path, section="text"))
objects = slices.object_slices()
save_dol_slices(objects)
