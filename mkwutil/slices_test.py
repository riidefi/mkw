from pathlib import Path
import pytest

from mkwutil.slices import Slice, SliceTable


def test_slice_compare():
    assert Slice(0, 2) == Slice(0, 2)
    assert not (Slice(0, 2) > Slice(0, 16))


def test_slice_table():
    table = SliceTable(0, 16)
    # Right gap insert.
    table.add(Slice(0, 2, name="Sec1", section="text"))
    # Make sure adding overlapping slices fails.
    with pytest.raises(AssertionError):
        table.add(Slice(1, 3, name="Sec2", section="text"))
    # Light and right gap insert.
    table.add(Slice(4, 6, name="Sec3", section="text"))
    # Left gap insert.
    table.add(Slice(14, 16, name="Sec4", section="text"))
    assert list(table) == [
        Slice(0, 2),
        Slice(2, 4),
        Slice(4, 6),
        Slice(6, 14),
        Slice(14, 16),
    ]


def test_slices_reader():
    dol_slices_path = Path(__file__) / ".." / ".." / "pack" / "dol_slices.csv"
    with open(dol_slices_path, "r") as file:
        table = SliceTable(0x80000000, 0x8038917C)
        table.read_from(file)
