from mkwutil.project import load_dol_slices, save_dol_slices

slices = load_dol_slices()
objects = slices.object_slices()
save_dol_slices(objects)
