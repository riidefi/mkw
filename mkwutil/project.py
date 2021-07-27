from mkwutil.lib.slices import SliceTable
from mkwutil.lib.binary_blob import *
from pathlib import Path

def load_dol_slices(sections=None) -> "SliceTable":
    """Loads pack/dol_slices.csv in the default DOL region."""
    return SliceTable.load_path(
        Path(__file__).parent / ".." / "pack" / "dol_slices.csv", sections=sections
    )

def load_rel_slices(sections=None) -> "SliceTable":
    """Loads pack/rel_slices.csv in the default DOL region."""
    return SliceTable.load_path(
        Path(__file__).parent / ".." / "pack" / "rel_slices.csv", sections=sections
    )

def load_dol_binary_blob_slices(dir_="."):
    dir_ = Path(dir_)

    path = dir_ / "artifacts" / "target" / "pal" / "main.elf"
    return load_binary_blob_slices(path)