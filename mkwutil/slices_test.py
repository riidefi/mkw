from pathlib import Path
import pytest

from mkwutil.slices import ObjectSlices, Slice, SliceTable


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


def test_dol_slices():
    table = SliceTable.load_dol_slices()
    assert isinstance(table, SliceTable)
    objs = table.object_slices()
    assert isinstance(objs, ObjectSlices)
    assert len(objs) > 10


def test_rel_slices():
    table = SliceTable.load_rel_slices()
    assert isinstance(table, SliceTable)
    objs = table.object_slices()
    assert isinstance(objs, ObjectSlices)


def test_object_slices_sort_names():
    objects = ObjectSlices()
    objects.insert(Slice(name="s0", start=0x01, stop=0x02, section="text"))
    objects.insert(Slice(name="s2", start=0x06, stop=0x07, section="data"))
    objects.insert(Slice(name="s3", start=0x03, stop=0x04, section="text"))
    objects.insert(Slice(name="s1", start=0x02, stop=0x03, section="text"))
    objects.insert(Slice(name="s1", start=0x05, stop=0x06, section="data"))
    assert objects.sorted_names(order=["text", "data"]) == ["s0", "s1", "s2", "s3"]
