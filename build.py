
class Segment:
	def __init__(self, begin : int, end : int):
		assert isinstance(begin, int) and isinstance(end, int)
		self.begin = begin
		self.end = end

	def __repr__(self):
		return "(%s, %s)" % (hex(self.begin), hex(self.end))

	def empty(self):
		return self.begin == self.end

	def size(self):
		return self.end - self.begin
import struct
def read_u32(f):
	return struct.unpack(">I", f.read(4))[0]


import sys

def native_binary(path):
	if sys.platform == "win32" or sys.platform == "msys":
		return path + ".exe"
	else:
		return path

def windows_binary(path):
	if sys.platform == "win32" or sys.platform == "msys":
		return path
	else:
		return "wine " + path

import os

VERBOSE = False

DEVKITPPC = os.environ["DEVKITPPC"]

GAS = native_binary(os.path.join(DEVKITPPC, "bin", "powerpc-eabi-as"))

MWLD = windows_binary(os.path.join("tools", "mwldeppc.exe"))

CWCC_PATHS = {
	'default': windows_binary(os.path.join(".", "tools", "4199_60831", "mwcceppc.exe")),

	# For the main game
	# August 17, 2007
	# 4.2.0.1 Build 127
	#
	# Ideally we would use this version
	# We don't have this, so we use build 142:
	# This version has the infuriating bug where random 
	# nops are inserted into your code.
	'4201_127': windows_binary(os.path.join(".", "tools", "4201_142", "mwcceppc.exe")),

	# For most of RVL
	# We actually have the correct version
	'4199_60831': windows_binary(os.path.join(".", "tools", "4199_60831", "mwcceppc.exe")),

	# For HBM/WPAD, NHTTP/SSL
	# We use build 60831
	'4199_60726': windows_binary(os.path.join(".", "tools", "4199_60831", "mwcceppc.exe")),
}
CWCC_OPT = " ".join([
	"-nodefaults",
	"-align powerpc",
	"-enc SJIS",
	"-c",
	# "-I-",
	"-gccinc",
	"-i ./source/ -i ./source/platform",
	# "-inline deferred",
	"-proc gekko",
	"-enum int",
	"-O4,p",
	"-inline auto",
	"-W all",
	"-fp hardware",
	"-Cpp_exceptions off",
	"-RTTI off",
	"-pragma \"cats off\"", # ???
	# "-pragma \"aggressive_inline on\"",
	# "-pragma \"auto_inline on\"",	
	"-inline auto",
	"-w notinlined -W noimplicitconv",
	"-nostdinc",
	"-msgstyle gcc -lang=c99 -DREVOKART",
	"-func_align 4"
])

def require_folder(path):
    try:
        os.mkdir(path)
    except FileExistsError:
        pass

def postprocess(dst):
	command("python tools/postprocess.py -fsymbol-fixup %s" % dst)

def compile_source(src, dst, version='default', additional='-ipa file'):
	try:
		os.mkdir("tmp")
	except: pass
	command = f"{CWCC_PATHS[version]} {CWCC_OPT + ' ' + additional} {src} -o {dst}"
	
	if VERBOSE:
		print(command)
	
	os.system(command + " > ./tmp/compiler_log.txt")
	print(open("./tmp/compiler_log.txt").read().replace("source\\", ""))
	# postprocess(dst)

def command(cmd):
	if VERBOSE:
		print(cmd)
	os.system(cmd)

def assemble(dst, src):
	# print(dst, src)
	cmd = GAS + " %s -mgekko -Iasm -o %s" % (src, dst)
	command(cmd)

def link(dst, objs, lcf, partial=False):
	cmd = MWLD + " %s -o %s -lcf %s -fp hard" % (' '.join(objs), dst, lcf)
	if partial:
		cmd += " -r "
	command(cmd)

def make_obj(src):
	substitutions = (
		'.cpp', '.asm', '.c', '.s'
	)
	for s in substitutions:
		src = src.replace(s, '.o')
	return src

def gen_lcf(src, dst, o_files):
	from pathlib import Path
	lcf = ""

	with open(src, 'r') as f:
		lcf = f.read()
		lcf += "\nFORCEFILES {\n"
		for x in o_files:
			# TODO: Add ability to disable FORCEFILE to slices.csv
			if 'eggVideo' in x:
				continue
			lcf += Path(x).stem + ".o\n"
		lcf += "}\n"
	
	with open(dst, 'w') as f:
		f.write(lcf)

def segment_is_text(segment):
	from elftools.elf.constants import P_FLAGS

	return segment["p_flags"] & P_FLAGS.PF_X == P_FLAGS.PF_X

def segment_is_data(segment):
	return not segment_is_text(segment) and not segment_is_bss(segment)

def segment_is_bss(segment):
	return segment["p_filesz"] == 0

def write_to_dol_header(dol_file, offset, val):
	import io

	dol_file.seek(offset)
	dol_file.write(val.to_bytes(4, byteorder='big'))
	dol_file.seek(0, io.SEEK_END)

def write_segment_to_dol(idx, segment, dol_file):
	write_to_dol_header(dol_file, 0x00 + 0x04 * idx, dol_file.tell())
	write_to_dol_header(dol_file, 0x48 + 0x04 * idx, segment["p_vaddr"])
	# align filesz to 0x20
	filesz = ((segment["p_filesz"] + 0x1f) >> 5) << 5
	write_to_dol_header(dol_file, 0x90 + 0x04 * idx, filesz)

	dol_file.write(segment.data())
	# align current dol size to 0x20
	size = 0x20 - dol_file.tell() & 0x1f
	dol_file.write(bytes([0x00] * size))

def elf_to_dol(elf_path, dol_path):
	from elftools.elf.elffile import ELFFile

	with open(elf_path, 'rb') as elf_file, open(dol_path, 'wb') as dol_file:
		elf = ELFFile(elf_file)
		num_segments = elf.num_segments()

		dol_file.write(bytes([0x00] * 0x100))

		idx = 0
		for i in range(num_segments):
			segment = elf.get_segment(i)
			if not segment_is_text(segment):
				continue
			write_segment_to_dol(idx, segment, dol_file)
			idx += 1

		idx = 7
		for i in range(num_segments):
			segment = elf.get_segment(i)
			if not segment_is_data(segment):
				continue
			write_segment_to_dol(idx, segment, dol_file)
			idx += 1

		bss_start = 0
		bss_end = 0
		for i in range(num_segments):
			segment = elf.get_segment(i)
			if not segment_is_bss(segment):
				continue
			if bss_start == 0:
				bss_start = segment["p_vaddr"]
			bss_end = segment["p_vaddr"] + segment["p_memsz"]
		write_to_dol_header(dol_file, 0xd8, bss_start)
		bss_size = bss_end - bss_start
		write_to_dol_header(dol_file, 0xdc, bss_size)

		write_to_dol_header(dol_file, 0xe0, elf["e_entry"])

def read_elf_sec(elf, name):
	from system.rel_repack import RelSection

	elf_sec = elf.get_section_by_name(name)

	data = elf_sec.data()

	t = RelSection()
	t.data = bytearray(data)
	t.length = len(data)

	# Added
	t.name = name

	return t

R_PPC_NONE = 0
R_PPC_ADDR32 = 1
R_PPC_ADDR24 = 2
R_PPC_ADDR16 = 3
R_PPC_ADDR16_LO = 4
R_PPC_ADDR16_HI = 5
R_PPC_ADDR16_HA = 6
R_PPC_ADDR14 = 7
R_PPC_ADDR14_BRTAKEN = 8
R_PPC_ADDR14_BRNKTAKEN = 9
R_PPC_REL24 = 10
R_PPC_REL14 = 11

R_PPC_REL32 = 26

def build_elf(rel_path, elf_path):
	from system.rel_repack import Rel

	# Hack: for header.bin
	os.chdir("system")
	
	rel = Rel()
	os.chdir("..")

	rel.load_reloc(0, "system/dol_rel.bin")
	rel.load_reloc(1, "system/rel_abs.bin")

	from elftools.elf.elffile import ELFFile

	with open(elf_path, 'rb') as f:
		elf = ELFFile(f)

		rel.sectionInfo[1] = read_elf_sec(elf, ".text")
		rel.sectionInfo[2] = read_elf_sec(elf, ".ctors")
		rel.sectionInfo[3] = read_elf_sec(elf, ".dtors")
		rel.sectionInfo[4] = read_elf_sec(elf, ".rodata")
		rel.sectionInfo[5] = read_elf_sec(elf, ".data")
		rel.sectionInfo[6] = read_elf_sec(elf, ".bss")

		# .rodata padding hack
		rodata = rel.sectionInfo[4]
		rodata.data = rodata.data[:-16]
		rodata.length = len(rodata.data)

		# Jump to _Unresolved
		_Unresolved = 0x805553B0
		text = rel.sectionInfo[1]
		relocs = elf.get_section_by_name(".rela.text")
		if relocs:
			for reloc_acc in relocs.iter_relocations():
				reloc = reloc_acc.entry
				if reloc.r_info_type == R_PPC_REL24:
					instruction = struct.unpack(">I", text.data[reloc.r_offset : reloc.r_offset + 4])[0]
					instruction_addr = 0x805103B4 + reloc.r_offset

					delta = _Unresolved - instruction_addr
					new_ins = (instruction & ~0x03fffffc) | (delta & 0x03fffffc)

					# print(hex(instruction))
					# print(hex(new_ins))

					packed = struct.pack(">I", new_ins)
					for i in range(4):
						text.data[reloc.r_offset + i] = packed[i]

	rel.sectionInfo[1].executable = True
	rel.sectionInfo[1].offset = 0xD4
	rel.sectionInfo[2].offset = 0x37F120
	rel.sectionInfo[3].offset = 0x37F424
	rel.sectionInfo[4].offset = 0x37F440
	rel.sectionInfo[5].offset = 0x3A28F0
	rel.sectionInfo[6].offset = 0

	# This seems to affect tz, but absolutely no one else?
	# Hack: Fix .bss size
	rel.sectionInfo[6].length = 0x78b0
	
	rel.imps[0].moduleId = 1
	rel.imps[0].offset = 0x3CD104
	rel.imps[1].moduleId = 0
	rel.imps[1].offset = 0x4820F4

	rel.reconstruct(rel_path)

	# Debug
	for i in range(1, 6+1):
		sec = rel.sectionInfo[i]

		dest_path = "tmp/" + sec.name[1:] + "_rebuilt.bin"

		with open(dest_path, 'wb') as f:
			f.write(sec.data)

def compile_sources():
	require_folder("out")

	# import sources
	with open('sources.py', 'r') as sourcespy:
		exec(sourcespy.read())

	from pathlib import Path
	asm_files = [str(x.relative_to(os.getcwd())) for x in Path(os.path.join(os.getcwd(), "asm")).glob("**/*.s")]
	
	require_folder("out")
	require_folder(os.path.join("out", "dol"))
	require_folder(os.path.join("out", "rel"))

	for asm in asm_files:
		# Hack: Should use pathlib for this
		out_o = "out" + asm[len("asm"):]
		assemble(make_obj(out_o), asm)

def link_dol(o_files):
	gen_lcf("link.lcf", "out/generated.lcf", o_files)
	link('out/built.elf', o_files, "out/generated.lcf")

	with open('out/built.elf', 'r+b') as elf:
		elf.seek(0x18)
		elf.write(bytes([0x80, 0x00, 0x60, 0xA4]))

	elf_to_dol("out/built.elf", "target/mkw_pal.dol")

def link_rel(rel_o_files):
	gen_lcf("rel_link.lcf", "out/rel_generated.lcf", rel_o_files)
	link('out/rel_built.elf', rel_o_files, "out/rel_generated.lcf", partial=True)

	build_elf("target/StaticR.rel", "out/rel_built.elf")

def build():
	try:
		os.mkdir("target")
	except: pass

	o_files = ["out/" + x.strip() for x in open('o_files.txt', 'r').readlines()]
	rel_o_files = ["out/" + x.strip() for x in open('rel_o_files.txt', 'r').readlines()]

	compile_sources()

	link_dol(o_files)
	
	link_rel(rel_o_files)

	verify_dol()

	verify_rel()

	import percent_decompiled

import hashlib

def verify_rel():
	ctx = hashlib.sha1(open('target/StaticR.rel', 'rb').read())
	digest = ctx.hexdigest()
	if digest.lower() == '887bcc076781f5b005cc317a6e3cc8fd5f911300':
		print("[REL] Everything went okay! Output is matching! ^^")
		return

	print("[REL] Oof: Output doesn't match.")

def verify_dol():
	ctx = hashlib.sha1(open('target/mkw_pal.dol', 'rb').read())
	digest = ctx.hexdigest()
	if digest.lower() == 'ac7d72448630ade7655fc8bc5fd7a6543cb53a49':
		print("[DOL] Everything went okay! Output is matching! ^^")
		return

	print("[DOL] Oof: Output doesn't match.")
	
	class DolBinary:
		def __init__(self, file):
			file = open(file, 'rb')
			text_ofs = [read_u32(file) for _ in range(7)]
			data_ofs = [read_u32(file) for _ in range(11)]

			text_vaddr = [read_u32(file) for _ in range(7)]
			data_vaddr = [read_u32(file) for _ in range(11)]

			self.text_size = [read_u32(file) for _ in range(7)]
			self.data_size = [read_u32(file) for _ in range(11)]

			self.text_segs = [Segment(x, x + y) for x, y in zip(text_vaddr, self.text_size)]
			self.data_segs = [Segment(x, x + y) for x, y in zip(data_vaddr, self.data_size)]
					
			bss_vaddr = read_u32(file)
			bss_size = read_u32(file)

			self.bss = Segment(bss_vaddr, bss_vaddr + bss_size)

			self.entry_point = read_u32(file)

			max_vaddr = max(x.end for x in self.text_segs + self.data_segs)
			self.image_base = 0x80000000
			self.image = bytearray(max_vaddr - self.image_base)
			return
			for i in range(7):
				if not self.text_size[i]:
					continue

				file.seek(text_ofs[i])
				data = file.read(self.text_size[i])
				for j in range(self.text_size[i]):
					self.image[text_vaddr[i] + j - self.image_base] = data[j]

			for i in range(11):
				if not self.data_size[i]:
					continue

				file.seek(data_ofs[i])
				data = file.read(self.data_size[i])
				for j in range(self.data_size[i]):
					self.image[data_vaddr[i] + j - self.image_base] = data[j]

	good = DolBinary("source/baserom.dol")
	bad = DolBinary("target/mkw_pal.dol")
	
	for i, sizes in enumerate(zip(good.text_size, bad.text_size)):
		print(sizes)
	for i, sizes in enumerate(zip(good.data_size, bad.data_size)):
		print(sizes)
	# TODO: Add diff'ing

build()
