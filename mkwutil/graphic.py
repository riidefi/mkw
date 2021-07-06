def html_emit_box(style, tooltip):
	return "<div class=\"rectangle\" style=\"%s\" data-tooltip=\"%s\"></div>" % (style, tooltip)

def html_emit_page(boxes, boxes2):
	return """<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<style>
.rectangle {
  height: 50px;
  float: left;
}
</style>
</head>
<body>

<h2>DOL Decompiled</h2>""" + boxes + """</body>
<h2>DOL Libraries</h2>""" + boxes2 + """</body>
</html>
"""

#<div class="rectangle"></div>
#<div class="rectangle" style="background-color:#eee"></div>


def build_box(width, label, color):
	return html_emit_box("background-color:%s; width:%spx;" % (color, width), label)

#CODE_COLOR = "#d5feff"
CODE_COLOR = "hsl(%s, 100, 91.8)"
UNK_COLOR = "#000000"

import colorsys

def make_code_color(hue):
	rgb = colorsys.hsv_to_rgb(hue, 100/100, 91.8/100)
	#print(rgb)
	return rgb


def make_code_color_hex(hue):
	vals = list(round(i * 255) for i in make_code_color(hue))

	r = "#"

	for v in vals:
		if len(hex(v)) == len(hex(3)):
			r += "0"
		r += hex(v)[2:]

	return r

PX_FACTOR = 1 / 2000

import random
def box_from_code_seg(begin, end, label):
	return build_box(abs(end - begin) * PX_FACTOR, label, make_code_color_hex(random.randint(0, 360)/360))

def box_from_gap_seg(begin, end):
	return build_box(abs(end - begin) * PX_FACTOR, "gap", UNK_COLOR)

SPLITS = [
	["rvl/trk/rvlTrkMem.c",0x80005f34,0x80006068,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	["nw4r/g3d/g3d_camera.cpp",0,0, 0,0, 0,0, 0x8006a0c0 ,0x8006a518, 0,0, 0,0, 0,0, 0,0, 0x802bd4ec,0x802bd4ec, 0,0, 0,0, 0x80387cac,0x80387cd8, 0,0],
	["nw4r/g3d/g3d_fog.cpp",0,0,0,0,0,0,0x800774d0,0x800775d0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x80387d58,0x80387d5C,0,0],
	["nw4r/math/mathTriangular.cpp",0,0,0,0,0,0,0x80085110,0x80085578,0,0,0,0,0x80248010,0x80249020,0x80274148,0x80274250,0,0,0,0,0,0,0x80387e80,0x80387ea4,0,0],
	["nw4r/math/mathTypes.cpp",0,0,0,0,0,0,0x80085600,0x80085938,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x80387ea8,0x80387eb4,0,0],
	["nw4r/ut/utList.cpp",0,0,0,0,0,0,0x800AEF60,0x800af1a0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	["dwc/common/dwc_error.c",0,0,0,0,0,0,0x800CCB4C,0x800CCC80,0,0,0,0,0,0,0x80275700,0x80275758,0,0,0,0,0x803862A8,0x803862B0,0,0,0,0],
	["gamespy/darray.c",0,0,0,0,0,0,0x800ef378,0x800efdcc,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	["gamespy/hashtable.c",0,0,0,0,0,0,0x800efdcc,0x800f0264,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	["gamespy/md5c.c",0,0,0,0,0,0,0x800f0264,0x800f118c,0,0,0,0,0x8024c6b8,0x8024c6c9,0x8027aca0,0x8027ace0,0,0,0,0,0,0,0,0,0,0],
	["gamespy/common/revolution/gsSocketRevolution.c",0,0,0,0,0,0,0x800f118c,0x800f164c,0,0,0,0,0,0,0,0,0,0,0,0,0x80386350,0x80386358,0,0,0,0],
	["gamespy/common/revolution/gsUtilRevolution.c",0,0,0,0,0,0,0x800f1f58,0x800f2048,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	["gamespy/common/gsAvailable.c",0,0,0,0,0,0,0x800f38a4,0x800f3a20,0,0,0,0,0,0,0x8027ad58,0x8027ad79,0x802f2338,0x802f2410,0,0,0x80386358,0x8038635c,0,0,0,0],
	["gamespy/common/gsCore.c",0,0,0,0,0,0,0x800f3c08 ,0x800f41dc,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	["gamespy/common/gsUdpEngine.c",0,0,0,0,0,0,0x800f489c,0x800f5a6c,0,0,0,0,0,0,0,0,0x802f2440,0x802f247c,0,0,0,0,0,0,0,0],
	["gamespy/common/gsXML.c",0,0,0,0,0,0,0x800f5a6c,0x800fb828,0,0,0,0,0,0,0x8027ad80,0x8027af18,0,0,0x803850a0,0x80385105,0,0,0,0,0,0],
	["gamespy/gp/gp.c",0,0,0,0,0,0,0x800fb828,0x800fc7d4,0,0,0,0,0,0,0x8027af18,0x8027b289,0,0,0x80385108,0x80385118,0,0,0,0,0,0],
	["gamespy/gp/gpi.c",0,0,0,0,0,0,0x800fc7d4,0x800fd160,0,0,0,0,0,0,0x8027b290,0x8027b30f,0,0,0x80385118,0x80385150,0,0,0,0,0,0],
	["gamespy/gp/gpiBuddy.c",0,0,0,0,0,0,0x800fd160,0x800fee90,0,0,0,0,0,0,0x8027b310,0x8027b453,0,0,0x80385150,0x803851ea,0,0,0,0,0,0],
	["gamespy/gp/gpiBuffer.c",0,0,0,0,0,0,0x800fee90,0x800ff8c4,0,0,0,0,0,0,0x8027b458,0x8027b4ba,0,0,0x803851f0,0x80385206,0,0,0,0,0,0],
	["gamespy/gp/gpiCallback.c",0,0,0,0,0,0,0x800ff8c4,0x800ffe28 ,0,0,0,0,0,0,0x8027b4c0,0x8027b4cf,0,0,0,0,0,0,0,0,0,0],
	["gamespy/gp/gpiConnect.c",0,0,0,0,0,0,0x800ffe28 ,0x80101470,0,0,0,0,0,0,0x8027b4d0,0x8027b876,0,0,0x80385208,0x8038529b,0,0,0,0,0,0],
	["gamespy/gp/gpiInfo.c",0,0,0,0,0,0,0x80101470,0x80103908,0,0,0,0,0,0,0x8027b878,0x8027bbce,0,0,0x803852a0,0x80385355,0,0,0x80388470,0x80388474,0,0],
	["gamespy/gp/gpiKeys.c",0,0,0,0,0,0,0x80103908,0x80103f70,0,0,0,0,0,0,0x8027bbd0,0x8027bc11,0,0,0x80385358,0x8038535a,0,0,0,0,0,0],
	["gamespy/gp/gpiOperation.c",0,0,0,0,0,0,0x80103f70,0x80104648,0,0,0,0,0,0,0x8027bc18,0x8027bc60,0,0,0,0,0,0,0,0,0,0],
	["gamespy/gp/gpiPeer.c",0,0,0,0,0,0,0x80104648,0x80105d54,0,0,0,0,0,0,0x8027bc60,0x8027bd2a,0,0,0x80385360,0x803853b9,0,0,0,0,0,0],
	["gamespy/sake/sakeMain.c",0,0,0,0,0,0,0x80121eec ,0x8012249c,0,0,0,0,0,0,0x8027de48,0x8027df3e,0x802f3f40,0x802f4040,0x80385740,0x80385744,0,0,0,0,0,0],
	["rvl/arc/rvlArchive.c",0,0,0,0,0,0,0x80124500,0x80124E80,0,0,0,0,0,0,0x8027E708,0x8027E772,0,0,0x803857F0,0x803857F6,0,0,0,0,0,0],
	["rvl/mem/rvlMemHeap.c",0,0,0,0,0,0,0x801981ec,0x80198798,0,0,0,0,0,0,0,0,0x80346cf0,0x80346d18,0,0,0x80386838,0x8038683C,0,0,0,0],
	["rvl/mem/rvlMemExpHeap.c",0,0,0,0,0,0,0x80198798,0x80199430,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	["rvl/mem/rvlMemFrmHeap.c",0,0,0,0,0,0,0x80199430,0x801998A4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	["rvl/mem/rvlMemUnitHeap.c",0,0,0,0,0,0,0x801998A4,0x80199b58,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	["rvl/mem/rvlMemAllocator.c",0,0,0,0,0,0,0x80199b58,0x80199bf0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x80388860,0x80388870,0,0],
	["rvl/mem/rvlMemList.c",0,0,0,0,0,0,0x80199BF0,0x80199D04,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	["rvl/mtx/rvlMtx.c",0,0,0,0,0,0,0x80199d04,0x8019a9c4,0,0,0,0,0,0,0,0,0,0,0x80385a08,0x80385a10,0,0,0x80388870,0x80388890,0,0],
	["rvl/mtx/rvlMtx2.c",0,0,0,0,0,0,0x8019a9c4,0x8019abe4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x80388890,0x803888a8,0,0],
	["rvl/mtx/rvlVec.c",0,0,0,0,0,0,0x8019abe4,0x8019ae08,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x803888a8,0x803888b4,0,0],
	["rvl/mtx/rvlQuat.c",0,0,0,0,0,0,0x8019ae08,0x8019b178,0,0,0,0,0x80252c78,0x80252c84,0,0,0,0,0,0,0,0,0x803888b8,0x803888cc,0,0],
	["rvl/so/soCommon.c",0,0,0,0,0,0,0x801ec088,0x801ecf20,0,0,0,0,0,0,0x802a2318,0x802a24f4,0x80357220,0x80357238,0x80385ee0,0x80385ee8,0x80386D30,0x80386D38,0,0,0,0],
	["rvl/so/soBasic.c",0,0,0,0,0,0,0x801ecf20,0x801ecff4,0,0,0,0,0,0,0x802a24f8 ,0x802a2543,0,0,0x80385ee8,0x80385eeC,0,0,0,0,0,0],
	["egg/core/eggAllocator.cpp",0,0,0,0,0,0,0x8020F62C,0x8020F6EC,0,0,0,0,0,0,0x802A2668,0x802A2680 ,0,0,0,0,0,0,0,0,0,0],
	["egg/core/eggArchive.cpp",0,0,0,0,0,0,0x8020F6EC,0x8020FCC4,0,0,0,0,0,0,0x802A2680,0x802A268C,0x803832D8,0x803832E4,0,0,0x80386D80,0x80386D84,0,0,0,0],
	["egg/core/eggDisposer.cpp",0,0,0,0,0,0,0x8021A0F0,0x8021A1B8,0,0,0,0,0,0,0x802A2B48,0x802A2B54 ,0,0,0,0,0,0,0,0,0,0],
	["egg/core/eggExpHeap.cpp",0,0,0,0,0,0,0x802269A8,0x80226F04,0,0,0,0,0x80257700,0x8025771A,0x802A2FF8,0x802A3024,0,0,0,0,0,0,0,0,0,0],
	["egg/core/eggGraphicsFifo.cpp",0,0,0,0,0,0,0x80229540,0x802296A8,0,0,0,0,0,0,0x802A30B0,0x802A30BC,0,0,0,0,0x80386E90,0x80386E99,0,0,0,0],
	["egg/core/eggHeap.cpp",0,0,0,0,0,0,0x802296A8,0x80229FAC,0,0,0,0,0x80257740,0x80257824,0x802A30C0,0x802a30ec,0x80384320,0x80384348,0,0,0x80386EA0,0x80386EC0,0x80388D68 ,0x80388D80,0,0],
	["egg/math/eggQuat.cpp",0,0,0,0,0,0,0x80239DFC,0x80239E10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	["egg/core/eggScene.cpp",0,0,0,0,0,0,0x8023AD10,0x8023ADDC,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	["egg/core/eggStreamDecomp.cpp",0,0,0,0,0,0,0x80242498,0x80242504,0,0,0,0,0,0,0x802A3F78,0x802A3F90,0,0,0,0,0,0,0,0,0,0],
	["egg/core/eggSystem.cpp",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x80386F60,0x80386F64,0,0,0,0],
	["egg/core/eggThread.cpp",0,0,0,0,0,0,0x802432E0 ,0x80243754,0,0,0,0,0,0,0x802A3FC0,0x802A3FD8,0x80384B60,0x80384B6C ,0,0,0,0,0,0,0,0],
	["egg/core/eggUnitHeap.cpp",0,0,0,0,0,0,0x80243754,0x80243A00,0,0,0,0,0,0,0x802A3FD8,0x802A4004,0,0,0,0,0,0,0,0,0,0],
	["egg/math/eggVector.cpp",0,0,0,0,0,0,0x80243A00,0x80243D18,0x80244E88,0x80244E8C,0,0,0,0,0,0,0x80384B70,0x80384BF4,0,0,0x80386F78,0x80386F90,0x803890F8 ,0x80389104,0,0],
	["egg/core/eggVideo.cpp",0,0,0,0,0,0,0x80243D18,0x80244074,0,0,0,0,0x802582E0,0x80258560,0,0,0,0,0,0,0,0,0x80389108,0x80389118,0,0]
]



def child_of(parent, child):
	if child[0] >= parent[1]:
		return False

	if child[1] <= parent[0]:
		return False

	return True

def fs(a):
	return "%x %x %s" % (a[0], a[1], a[2])


class RangeMapper:
	def __init__(self, begin, end):
		self.segs = [ [ begin, end, "unk"] ]
		self.begin = begin
		self.end = end


	def comp_total(self):
		t = 0
		for s in self.segs:
			t += abs(s[1] - s[0])

			if s[0] > s[1]:
				return 0

		return t

	def assert_valid(self):
		ctotal = self.comp_total()
		rtotal = self.end - self.begin

		if ctotal == rtotal:
			return

		print("INVALID: CTOTAL = %x, RTOTAL = %x" % (ctotal, rtotal))

		assert False

	def find_parent(self, block):
		for s in self.segs:
			if child_of(s, block):
				return s

		return None

	def add_mem_range(self, sec, file):
		self.assert_valid()

		low, high = sec

		# Handle replace case
		for s in self.segs:
			if s[0] == low and s[1] == high:
				# print("REPLACE")
				s[0] = low
				s[1] = high
				s[2] = file
				self.assert_valid()
				self.segs = sorted(self.segs)
				return


		self.segs = sorted(self.segs)

		parent = self.find_parent(sec)
		assert parent

		print("Splitting to add %s" % file)
		

		parent_file = parent[2]
		low_block = [parent[0], low, "unk"]
		mid_block = [low, high, file]
		top_block = [high, parent[1], "unk"]


		
		#print("Parent")
		#print(fs(parent))
		#print("us")
		#print(fs((sec[0], sec[1], file)))
		#print(list(fs(a) for a in segs))
		assert low_block[0] <= low_block[1]
		assert mid_block[0] <= mid_block[1]
		assert top_block[0] <= top_block[1]

		if low_block[0] != low_block[1]:
			self.segs.append(low_block)
		
		parent[0] = mid_block[0]
		parent[1] = mid_block[1]
		parent[2] = mid_block[2]

		if parent[0] == parent[1]:
			print("Removing parent")
			self.segs.remove(parent)
		
		if top_block[0] != top_block[1]:
			self.segs.append(top_block)
		
		self.assert_valid()
		self.segs = sorted(self.segs)


def populate_mapper(mapper, splits):
	for split in splits:
		file = split[0]
		for i in range(1, len(split), 2):
			sec = [split[i], split[i + 1]]

			if sec[0] == 0:
				assert sec[1] == 0
				continue

			if sec[0] == sec[1]:
				print("WARN: file %s invalidy configured, begin == end, begin != 0" % file)
				continue
			
			assert sec[1] > sec[0]

			mapper.add_mem_range(sec, file)

	for seg in mapper.segs:
		perc = "-" * int(1  + abs(seg[0]-seg[1]) / 400000)
		print("%s %s %s %s" % (perc, hex(seg[0]), hex(seg[1]), seg[2]))

def size_of_mapper(mapper):
	n_code = 0
	n_unk = 0

	for seg in mapper.segs:
		if seg[2] == "unk":
			n_unk += abs(seg[0] - seg[1])
		else:
			n_code += abs(seg[0] - seg[1])

	return n_code, n_unk

def boxlist_from_mapper(mapper):
	boxes = []

	for seg in mapper.segs:
		if seg[2] == "unk":
			boxes.append(box_from_gap_seg(seg[0], seg[1]))
		else:
			boxes.append(box_from_code_seg(seg[0], seg[1], seg[2]))

	return boxes

def percent_decomp_stats(mapper):
	n_code, n_unk = size_of_mapper(mapper)

	total = n_unk + n_code
	print("Total: %s, real total: %s" % (total, DOL_SIZE))

	print("Code&Data Percent: %s" % (100 * n_code / total))

DOL_BEGIN = 0x80004000
DOL_END = 0x8038917C

DOL_SIZE = DOL_END - DOL_BEGIN

def standard_boxes():
	mapper = RangeMapper(DOL_BEGIN, DOL_END)
	populate_mapper(mapper, SPLITS)

	# percent_decomp_stats(mapper)

	return boxlist_from_mapper(mapper)

LIB_SPLITS = [
	[ "NW4R", 0x80021BB0, 0x800BBB80],
	[ "RFL", 0x800BBB80, 0x800CC7E4],
	[ "DWC", 0x800CC7E4, 0x800EF378],
	[ "SPY", 0x800EF378, 0x80123F88],
	[ "RVL", 0x80123F88, 0x8020F62C],
	[ "EGG", 0x8020F62C, 0x80244DD4]
]

def lib_boxes():
	mapper = RangeMapper(DOL_BEGIN, DOL_END)
	populate_mapper(mapper, LIB_SPLITS)

	return boxlist_from_mapper(mapper)

page = html_emit_page("\n".join(standard_boxes()), "\n".join(lib_boxes()))


with open("out.html", 'w') as f:
	f.write(page)