def process_line(tags, items):
	name = "Untitled"
	start = None
	code_total = 0
	data_total = 0

	for tag, entry in zip(tags, items):
		if tag == 'enabled' and entry == 0:
			return
		elif tag == 'name':
			name = entry
			continue

		is_code = 'text' in tag
		
		if 'Start' in tag:
			if not entry:
				start = None
				continue

			start = int(entry, 16)
			continue

		if 'End' in tag and start:
			size = int(entry, 16) - start

			if is_code:
				code_total += size
			else:
				data_total += size

	name = items[1]
	return name, code_total, data_total


def parse_slices(path):
	with open(path, 'r') as file:
		lines = file.readlines()
		
		tags = lines[0].split(',')
		for line in lines[1:]:
			yield process_line(tags, line.split(','))

def simple_count(path):
	code_total = 0
	data_total = 0

	for o_name, o_code_total, o_data_total in parse_slices(path):
		code_total += o_code_total
		data_total += o_data_total

	return code_total, data_total

def segments_of(path):
	with open(path, 'r') as file:
		for line in file.readlines()[1:]:
			seg, segclass, start, end = line.split(',')

			is_code = 'text' in seg

			yield is_code, int(end, 16) - int(start, 16)

def binary_total(path):
	segments = list(segments_of(path))

	num_code = sum(size if is_code else 0 for is_code, size in segments)
	num_data = sum(size if not is_code else 0 for is_code, size in segments)

	return num_code, num_data


dol_progress = simple_count("system/slices.csv")
rel_progress = simple_count("system/rel_slices.csv")

dol_total = binary_total("artifacts/pal/segments.csv")
rel_total = binary_total("artifacts/pal/rel_segments.csv")

def to_percent(frac):
	return round(frac * 100_000) / 1000

def analyze(prefix, progress, total):
	#	print("%s %s bytes (%s%%) of code, %s bytes (%s%%) of data decompiled" % (
	#		prefix,
	#		progress[0], to_percent(progress[0] / total[0]) if total[0] else '',
	#		progress[1], to_percent(progress[1] / total[1]) if total[1] else ''
	#	))
	print("%s %s%% code, %s%% data decompiled" % (
		prefix,
		to_percent(progress[0] / total[0]) if total[0] else '',
		to_percent(progress[1] / total[1]) if total[1] else ''
	))

analyze('[DOL]', dol_progress, dol_total)

egg_progress = [0, 0]
for o_name, o_code_total, o_data_total in parse_slices("system/slices.csv"):
	if 'egg' not in o_name:
		continue

	egg_progress[0] += o_code_total
	egg_progress[1] += o_data_total

egg_total = [0x80244DD4-0x8020F62C, None]

analyze('  -> [EGG]', egg_progress, egg_total)

analyze('[REL]', rel_progress, rel_total)

def piecewise_add(x, y):
	return list(a + b for a, b in zip(x, y))

analyze('--- main.dol + StaticR.rel ---\n',
	piecewise_add(dol_progress, rel_progress),
	piecewise_add(dol_total, rel_total))

print('------')
print('Player:')
print(' - %u BR (main.dol)' % (dol_progress[0] / dol_total[0] * 4999 + 5000))
print(' - %u VR (StaticR.rel)' % (rel_progress[0] / rel_total[0] * 4999 + 5000))

print(dol_total[0] / 4999 / 4)
print(rel_total[0] / 4999 / 4)