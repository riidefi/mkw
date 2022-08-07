
# Performs preprocessing for disassembly
from pathlib import Path

from mkwutil.ppcdis.disassembler import Disassembler
from mkwutil.ppcdis.binaryyml import load_binary_yml


def get_dol_disaser():
    thispath = Path('./mkwutil/ppcdis_adapter')
    symbol_map_path = thispath / 'symbol_map.yml'
    rel_labelspath = thispath / 'rel_labels.pickle'
    rel_relocspath = thispath / 'rel_relocs.pickle'
    dol_labelspath = thispath / 'dol_labels.pickle'
    dol_relocspath = thispath / 'dol_relocs.pickle'
    dolpath = thispath / 'dol.yaml'
    relpath = thispath / 'rel.yaml'
    dolbin = load_binary_yml(dolpath)

    overrides = None
    extra_labels = None
    thorough = False
    quiet = False
    source_name = None

    dol_disaser = Disassembler(dolbin, symbol_map_path, source_name, dol_labelspath,
                       dol_relocspath, overrides, quiet)

    return dol_disaser


def get_rel_disaser():
    thispath = Path('./mkwutil/ppcdis_adapter')
    symbol_map_path = thispath / 'symbol_map.yml'
    rel_labelspath = thispath / 'rel_labels.pickle'
    rel_labelspath = thispath / 'rel_labels.pickle'
    rel_relocspath = thispath / 'rel_relocs.pickle'
    dol_labelspath = thispath / 'dol_labels.pickle'
    dol_relocspath = thispath / 'dol_relocs.pickle'
    dolpath = thispath / 'dol.yaml'
    relpath = thispath / 'rel.yaml'
    relbin = load_binary_yml(relpath)

    overrides = None
    extra_labels = None
    thorough = False
    quiet = False
    source_name = None

    rel_disaser = Disassembler(relbin, symbol_map_path, source_name, rel_labelspath,
                       rel_relocspath, overrides, quiet)

    return rel_disaser
