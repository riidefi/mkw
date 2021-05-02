
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



import os

VERBOSE = False

DEVKITPPC = os.environ["DEVKITPPC"]

GAS = os.path.join(DEVKITPPC, "bin\\powerpc-eabi-as.exe")

MWLD = "tools\\mwldeppc.exe"

ELF2DOL = "tools\\elf2dol.exe"

CWCC_PATHS = {
	'default': ".\\tools\\4199_60831\\mwcceppc.exe",

	# For the main game
	# August 17, 2007
	# 4.2.0.1 Build 127
	#
	# Ideally we would use this version
	# We don't have this, so we use build 142:
	# This version has the infuriating bug where random 
	# nops are inserted into your code.
	'4201_127': ".\\tools\\4201_142\\mwcceppc.exe",

	# For most of RVL
	# We actually have the correct version
	'4199_60831': ".\\tools\\4199_60831\\mwcceppc.exe",

	# For HBM/WPAD, NHTTP/SSL
	# We use build 60831
	'4199_60726': '\\tools\\4199_60831\\mwcceppc.exe'
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
	lcf = ""

	with open(src, 'r') as f:
		lcf = f.read()
		lcf += "\nFORCEFILES {\n"
		lcf += "\n".join(x.replace("out/", "") for x in o_files)
		lcf += "\n}\n"
	
	with open(dst, 'w') as f:
		f.write(lcf)


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
	try:
		os.mkdir("out")
	except: pass

	RVL_OPTS = '-ipa file'
	EGG_OPTS = '-ipa function -rostr'

	compile_source("source/rvl/arc/rvlArchive.c", "out/rvlArchive.o", '4199_60831', RVL_OPTS)
	compile_source("source/rvl/mem/rvlMemList.c", "out/rvlMemList.o", '4199_60831', RVL_OPTS)

	compile_source("source/dwc/common/dwc_error.c", "out/dwc_error.o", '4199_60831', RVL_OPTS)

	compile_source("source/egg/core/eggArchive.cpp", "out/eggArchive.o", '4201_127', EGG_OPTS + " -use_lmw_stmw=on ")
	compile_source("source/egg/core/eggDisposer.cpp", "out/eggDisposer.o", '4201_127', EGG_OPTS)
	compile_source("source/egg/core/eggGraphicsFifo.cpp", "out/eggGraphicsFifo.o", '4201_127', EGG_OPTS)
	compile_source("source/egg/core/eggHeap.cpp", "out/eggHeap.o", '4201_127', EGG_OPTS + " -ipa file -use_lmw_stmw=on  ")
	compile_source("source/egg/math/eggQuat.cpp", "out/eggQuat.o", '4201_127', EGG_OPTS)
	compile_source("source/egg/core/eggStreamDecomp.cpp", "out/eggStreamDecomp.o", '4201_127', EGG_OPTS)
	# compile_source("source/egg/core/eggSystem.cpp", "out/eggSystem.o", '4201_127', EGG_OPTS)
	compile_source("source/egg/core/eggThread.cpp", "out/eggThread.o", '4201_127', EGG_OPTS)
	compile_source("source/egg/math/eggVector.cpp", "out/eggVector.o", '4201_127', EGG_OPTS)
	# compile_source("source/egg/core/eggXfb.cpp", "out/eggXfb.o", '4201_127', EGG_OPTS)
	# compile_source("source/egg/core/eggXfbManager.cpp", "out/eggXfbManager.o", '4201_127', EGG_OPTS)

	compile_source("source/game/ui/MessageGroup.cpp", "out/MessageGroup.o", '4201_127', EGG_OPTS)

	from pathlib import Path
	asm_files = ["asm/" + str(x.stem) + ".s" for x in Path(os.path.join(os.getcwd(), "asm")).glob("**/*.s")]

	for asm in asm_files:
		assemble("out/" + make_obj(asm).replace("asm/", ""), asm)

def link_dol(o_files):
	gen_lcf("link.lcf", "out/generated.lcf", o_files)
	link('out/built.elf', o_files, "out/generated.lcf")

	with open('out/built.elf', 'r+b') as elf:
		elf.seek(0x18)
		elf.write(bytes([0x80, 0x00, 0x60, 0xA4]))

	command(ELF2DOL + " out/built.elf target/mkw_pal.dol -v -v")

	# This is a bug with elf2dol; this works fine with makedol
	# for now I'll just patch it...
	with open('target/mkw_pal.dol', 'r+b') as dol:
		dol.seek(0xDC)
		# bss_size
		dol.write(bytes([0x00, 0x0E, 0x50, 0xFC]))

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

	print("[REL] Oof: Output doesn't match.")
	# TODO: Add diff'ing

build()
