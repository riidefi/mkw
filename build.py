import os

VERBOSE = False

DEVKITPPC = "C:\\devkitPro\\devkitPPC"

GCC = os.path.join(DEVKITPPC, "bin\\powerpc-eabi-gcc.exe")
GAS = os.path.join(DEVKITPPC, "bin\\powerpc-eabi-as.exe")

MWLD = "tools\\mwldeppc.exe"

ELF2DOL = "tools\\elf2dol.exe"

SOURCE_PATH   = "./source/"
ASM_TEXT_PATH = "./asm/text/"
BUILD_PATH 	  = "./build/"
CWCC_OLD = False

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
	"-ipa file",
	"-inline auto",
	"-w notinlined -W noimplicitconv",
	"-nostdinc",
	"-msgstyle gcc -lang=c99 -DREVOKART",
	"-func_align 4"
])

def postprocess(dst):
	command("python tools/postprocess.py -fsymbol-fixup %s" % dst)

def compile_source(src, dst, version='default'):
	try:
		os.mkdir("tmp")
	except: pass
	command = f"{CWCC_PATHS[version]} {CWCC_OPT} {src} -o {dst}"
	
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
	cmd = GAS + " %s -mgekko -o %s" % (src, dst)
	command(cmd)

def link(dst, objs, lcf):
	cmd = MWLD + " %s -o %s -lcf %s -fp hard" % (' '.join(objs), dst, lcf)
	command(cmd)

def make_obj(src):
	substitutions = (
		'.cpp', '.asm', '.c', '.s'
	)
	for s in substitutions:
		src = src.replace(s, '.o')
	return src

def build():
	from pathlib import Path
	asm_files = ["asm/" + str(x.stem) + ".s" for x in Path(os.path.join(os.getcwd(), "asm")).glob("**/*.s")]
	o_files = ["out/" + x.strip() for x in open('build/o_files.txt', 'r').readlines()]

	try:
		os.mkdir("out")
	except: pass

	compile_source("source/rx/rxArchive.c", "out/rxArchive.o", '4199_60831')
	compile_source("source/rx/rxList.c", "out/rxList.o", '4199_60831')
	compile_source("source/dwc/common/dwc_error.c", "out/dwc_error.o", '4199_60831')
	compile_source("source/egg/math/eggVector.cpp", "out/eggVector.o", '4201_127')

	for asm in asm_files:
		assemble("out/" + make_obj(asm).replace("asm/", ""), asm)

	lcf = open("build/link.lcf", 'r').read()
	lcf += "\nFORCEFILES {\n"
	lcf += "\n".join(x.replace("out/", "") for x in o_files)
	lcf += "\n}\n"

	open('out/generated.lcf', 'w').write(lcf)

	link('out/built.elf', o_files, "out/generated.lcf")

	with open('out/built.elf', 'r+b') as elf:
		elf.seek(0x18)
		elf.write(bytes([0x80, 0x00, 0x60, 0xA4]))

	try:
		os.mkdir("target")
	except: pass
	command(ELF2DOL + " out/built.elf target/mkw_pal.dol -v -v")

	# This is a bug with elf2dol; this works fine with makedol
	# for now I'll just patch it...
	with open('target/mkw_pal.dol', 'r+b') as dol:
		dol.seek(0xDC)
		# bss_size
		dol.write(bytes([0x00, 0x0E, 0x50, 0xFC]))

	import hashlib
	ctx = hashlib.sha1(open('target/mkw_pal.dol', 'rb').read())
	digest = ctx.hexdigest()
	if digest.lower() == 'ac7d72448630ade7655fc8bc5fd7a6543cb53a49':
		print("Everything went okay! Output is matching! ^^")
		return

	print("Oof: Output doesn't match.")
	# TODO: Add diff'ing

build()