SHELL := /bin/bash
.SUFFIXES:

# Our Python tooling.
PYTHON ?= python3
GEN_ASM := $(PYTHON) ./util/gen_asm.py
GEN_LCF := $(PYTHON) ./util/gen_lcf.py
REL_REPACK := $(PYTHON) ./util/rel_repack.py

# The inputs and outputs of the gen_asm tool.
GEN_ASM_INPUTS := \
  pack/dol_segments.csv \
  pack/dol_slices.csv \
  pack/rel_segments.csv \
  pack/rel_slices.csv
GEN_ASM_OUTPUTS := \
  asm/dol \
  asm/rel \
  asm/macros.inc \
  pack/dol_objects.txt \
  pack/rel_objects.txt

# The original StaticR.rel artifact.
STATICR_REL := artifacts/orig/pal/StaticR.rel
# The extracted segments from the original StaticR.rel.
STATICR_SEGMENTS := artifacts/orig/pal/rel/

# Run everything required to build the final artifacts.
.PHONY: build
build: prepare source asm
	$(MAKE) -C artifacts

# First stage: Define the layout of the final executable.
# The build tooling roughly runs the following steps.
#  1. Extract the segments that make up the original StaticR.rel.
#  2. Generate assembly sources for code that was not decompiled (yet).
#  3. Define linker scripts and invocation arguments for reconstructed objects and auto-generated assembly.
.PHONY: prepare
prepare: $(GEN_ASM_OUTPUTS) ./pack/dol.lcf ./pack/rel.lcf ./pack/dol_objects.txt ./pack/rel_objects.txt 

# Re-compiles all decompiled sources to object files.
.PHONY: source
source:
	$(MAKE) -C source

# Re-compiles all binary blobs to object files.
.PHONY: asm
asm: asm/dol asm/rel asm/macros.inc
	$(MAKE) -C asm

# Clean deletes intermediate build artifacts that are not in Git.
.PHONY: clean
clean:
	$(MAKE) -C artifacts clean
	$(MAKE) -C asm clean
	$(MAKE) -C source clean

# Prune deletes ALL intermediate build artifacts.
.PHONY: prune
prune: clean
	rm -rf $(STATICR_SEGMENTS) $(GEN_ASM_OUTPUTS)

# Rules to generate linker scripts.
# For now, this just takes a hardcoded "base" linker script and appends a FORCEFILES section based on object files.
./pack/dol.lcf: ./pack/dol.base.lcf ./pack/dol_objects.txt
	$(GEN_LCF) --out ./pack/dol.lcf --base ./pack/dol.base.lcf --objs ./pack/dol_objects.txt --prefix ../
./pack/rel.lcf: ./pack/rel.base.lcf ./pack/rel_objects.txt
	$(GEN_LCF) --out ./pack/rel.lcf --base ./pack/rel.base.lcf --objs ./pack/rel_objects.txt --prefix ../

# If StaticR.rel is present, we can extract the individual segments.
ifneq ($(wildcard $(STATICR_REL)),)

# Rule to extract segments from StaticR.rel.
# Note that StaticR.rel is an order-only target,
# which means that segments are not re-dumped even if the original StaticR.rel changes.
$(STATICR_SEGMENTS): | $(STATICR_REL)
	mkdir -p "$(STATICR_SEGMENTS)"
	$(REL_REPACK) --dump --rel "artifacts/orig/pal/StaticR.rel" --dir "$(STATICR_SEGMENTS)"

# Rule to re-generate ASM sources from extracted segments.
$(GEN_ASM_OUTPUTS): $(STATICR_SEGMENTS) $(GEN_ASM_INPUTS)
	$(GEN_ASM) --asm_dir ./asm --pack_dir ./pack --binary_dir ./artifacts/orig/pal/

endif
