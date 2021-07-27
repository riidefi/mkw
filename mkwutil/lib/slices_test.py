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

def test_slice_table_remove_1():
    # Create a gap spanning some slices.
    table = SliceTable(0, 10)
    for x in range(2, 10, 2):
        table.add(Slice(x, x+2, "slice"))
    assert str(table) == """[
  { 00000000..00000002 }
  { 00000002..00000004 slice }
  { 00000004..00000006 slice }
  { 00000006..00000008 slice }
  { 00000008..0000000a slice }
]"""
    table.remove(3, 7)
    assert str(table) == """[
  { 00000000..00000002 }
  { 00000002..00000003 slice }
  { 00000003..00000007 }
  { 00000007..00000008 slice }
  { 00000008..0000000a slice }
]"""


def test_slice_table_remove_2():
    # Create a gap spanning the entire table.
    table = SliceTable(0, 10)
    for x in range(0, 10, 2):
        table.add(Slice(x, x+2, "slice"))
    table.remove(0, 10)
    assert str(table) == """[
  { 00000000..0000000a }
]"""

def test_slice_table_remove_3():
    # Create a gap where a gap already is.
    table = SliceTable(0, 6)
    for x in range(2, 6, 2):
        table.add(Slice(x, x+2, "slice"))
    table.remove(0, 2)
    assert str(table) == """[
  { 00000000..00000002 }
  { 00000002..00000004 slice }
  { 00000004..00000006 slice }
]"""


def test_slice_table_remove_4():
    # Shoot a hole in a slice.
    table = SliceTable(0, 10)
    table.add(Slice(0, 10, "slice"))
    table.remove(4, 5)
    assert str(table) == """[
  { 00000000..00000004 slice }
  { 00000004..00000005 }
  { 00000005..0000000a slice }
]"""

def test_slice_table_remove_5():
    # Remove exact slice.
    table = SliceTable(0, 6)
    for x in range(0, 6, 2):
        table.add(Slice(x, x+2, "slice"))
    table.remove(2, 4)
    assert str(table) == """[
  { 00000000..00000002 slice }
  { 00000002..00000004 }
  { 00000004..00000006 slice }
]"""

def test_slice_table_remove_6():
    # Remove slice prefix.
    table = SliceTable(0, 6)
    for x in range(2, 6, 2):
        table.add(Slice(x, x+2, "slice"))
    assert str(table) == """[
  { 00000000..00000002 }
  { 00000002..00000004 slice }
  { 00000004..00000006 slice }
]"""
    table.remove(2, 3)
    assert str(table) == """[
  { 00000000..00000003 }
  { 00000003..00000004 slice }
  { 00000004..00000006 slice }
]"""

def test_slice_table_remove_7():
    # Remove slice prefix.
    table = SliceTable(0, 6)
    for x in range(2, 6, 2):
        table.add(Slice(x, x+2, "slice"))
    assert str(table) == """[
  { 00000000..00000002 }
  { 00000002..00000004 slice }
  { 00000004..00000006 slice }
]"""
    table.remove(0, 3)
    assert str(table) == """[
  { 00000000..00000003 }
  { 00000003..00000004 slice }
  { 00000004..00000006 slice }
]"""

def test_slice_table_remove_8():
    # Remove slice suffix.
    table = SliceTable(0, 6)
    for x in range(0, 4, 2):
        table.add(Slice(x, x+2, "slice"))
    assert str(table) == """[
  { 00000000..00000002 slice }
  { 00000002..00000004 slice }
  { 00000004..00000006 }
]"""
    table.remove(3, 4)
    assert str(table) == """[
  { 00000000..00000002 slice }
  { 00000002..00000003 slice }
  { 00000003..00000006 }
]"""

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
