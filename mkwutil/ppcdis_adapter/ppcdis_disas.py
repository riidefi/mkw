
# Performs preprocessing for disassembly
from pathlib import Path

from ppcdis import Disassembler
from ppcdis import load_binary_yml


def get_dol_disaser():
    pack_dir = Path("./pack")
    symbol_map_path = pack_dir / "symbols.yml"

    thispath = Path('./mkwutil/ppcdis_adapter')
    rel_labelspath = thispath / 'rel_labels.pickle'
    rel_relocspath = thispath / 'rel_relocs.pickle'
    dol_labelspath = thispath / 'dol_labels.pickle'
    dol_relocspath = thispath / 'dol_relocs.pickle'
    dol_overridespath = thispath / 'dol_overrides.yaml'
    dolpath = thispath / 'dol.yaml'
    relpath = thispath / 'rel.yaml'
    dolbin = load_binary_yml(dolpath)

    extra_labels = None
    thorough = False
    quiet = True
    source_name = None

    dol_disaser = Disassembler(dolbin, dol_labelspath, dol_relocspath, symbol_map_path,
        dol_overridespath, source_name, quiet)

    return dol_disaser


def get_rel_disaser():
    pack_dir = Path("./pack")
    symbol_map_path = pack_dir / "symbols.yml"

    thispath = Path('./mkwutil/ppcdis_adapter')
    rel_labelspath = thispath / 'rel_labels.pickle'
    rel_relocspath = thispath / 'rel_relocs.pickle'
    rel_overridespath = thispath / 'rel_overrides.yaml'
    dol_labelspath = thispath / 'dol_labels.pickle'
    dol_relocspath = thispath / 'dol_relocs.pickle'
    dolpath = thispath / 'dol.yaml'
    relpath = thispath / 'rel.yaml'
    relbin = load_binary_yml(relpath)

    extra_labels = None
    thorough = False
    quiet = True
    source_name = None

    rel_disaser = Disassembler(relbin, rel_labelspath, rel_relocspath, symbol_map_path,
        rel_overridespath, source_name, quiet)

    return rel_disaser
