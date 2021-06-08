SHELL := /bin/bash
.SUFFIXES:

# Python interpreter.
PYTHON = python3

# Linker.
LD = ../tools/mwldeppc.exe

# Read objects from file.
OBJS_DOL = $(addprefix ../,$(patsubst %.s,%.o,$(file < ../pack/dol_objects.txt)))
OBJS_REL = $(addprefix ../,$(patsubst %.s,%.o,$(file < ../pack/rel_objects.txt)))

# Build meta-target.
.PHONY: build
build: target/pal/main.dol target/pal/StaticR.rel
	@$(PYTHON) ../util/verify_main_dol.py --reference orig/pal/main.dol --target target/pal/main.dol
	@$(PYTHON) ../util/verify_staticr_rel.py --target target/pal/StaticR.rel
	@$(PYTHON) ../util/percent_decompiled.py

.PHONY: clean
	find ./target -type f -name '*.elf' -o -name '*.dol' -o -name '*.rel' -delete

# Build main.dol.
target/pal/main.dol: target/pal/main.elf
	$(PYTHON) ../util/pack_main_dol.py -o $@ $<
# Build StaticR.rel.
target/pal/StaticR.rel: target/pal/StaticR.elf
	$(PYTHON) ../util/pack_staticr_rel.py -o $@ $<
# Build ELFs.
target/pal/main.elf: ../pack/dol.lcf $(OBJS_DOL)
	mkdir -p target/pal/
	$(LD) -fp hard -o $@ -lcf ../pack/dol.lcf $(OBJS_DOL)
target/pal/StaticR.elf: ../pack/rel.lcf $(OBJS_REL)
	mkdir -p target/pal/
	$(LD) -fp hard -o $@ -lcf ../pack/rel.lcf -r $(OBJS_REL)
