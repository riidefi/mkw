from mkwutil.lib.binary_blob import *
from mkwutil.lib.dol import DolBinary
from mkwutil.lib.rel import Rel
from mkwutil.lib.slices import SliceTable
from mkwutil.lib.symbols import SymbolsList
from pathlib import Path


dol_slices_path = Path(__file__).parent / ".." / "pack" / "dol_slices.csv"


def load_dol_slices(sections=None) -> "SliceTable":
    """Loads pack/dol_slices.csv in the default DOL region."""
    return SliceTable.load_path(dol_slices_path, sections=sections)


def save_dol_slices(objects: ObjectSlices):
    with open(dol_slices_path, "w", newline="\n") as slices_file:
        objects.write_to(slices_file, sections=SliceTable.SECTION_ORDER)


def load_rel_slices(sections=None) -> "SliceTable":
    """Loads pack/rel_slices.csv in the default DOL region."""
    return SliceTable.load_path(
        Path(__file__).parent / ".." / "pack" / "rel_slices.csv", sections=sections
    )


def load_dol_binary_blob_slices(dir: Path):
    path = dir / "artifacts" / "target" / "pal" / "main.elf"
    return load_binary_blob_slices(path)


def load_rel_binary_blob_slices(dir: Path):
    path = dir / "artifacts" / "target" / "pal" / "StaticR.elf"
    return load_binary_blob_slices(path)


def read_symbol_map(symbols_path):
    symbols = SymbolsList()
    with open(symbols_path, "r") as file:
        symbols.read_from_yaml(file)
        return symbols
    raise RuntimeError("Cannot find symbols")


def _project_base() -> Path:
    return Path(__file__).parents[1]


def read_dol(dol_path: Optional[Path] = None) -> DolBinary:
    if dol_path is None:
        dol_path = _project_base() / "artifacts" / "orig" / "pal" / "main.dol"
    with open(dol_path, "rb") as file:
        return DolBinary(file)
    raise RuntimeError("Cannot find DOL")


# Map out slices in DOL.
def read_enabled_slices(dol, slices_path):
    dol_slices = SliceTable(dol.start, dol.stop)
    with open(slices_path) as file:
        dol_slices.read_from(file)

        return dol_slices.filter(SliceTable.ONLY_ENABLED)

    raise RuntimeError("Cannot find dol_slices.csv")


def read_rel(rel_path):
    with open(rel_path, "rb") as file:
        return Rel(file, verbose=False)
    raise RuntimeError("Cannot find StaticR.rel")
