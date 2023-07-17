from mkwutil.project import load_dol_slices, save_dol_slices, load_rel_slices, save_rel_slices

slices = load_dol_slices()
objects = slices.object_slices()
save_dol_slices(objects)
slices = load_rel_slices()
objects = slices.object_slices()
save_rel_slices(objects)
