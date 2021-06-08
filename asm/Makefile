SHELL := /bin/bash
.SUFFIXES:

# Assembler.
AS = ../tools/devkitppc/bin/powerpc-eabi-as.exe
AS_FLAGS = -mgekko -Iasm

# Scan for binary blobs.
BLOB_ASMS_DOL := $(wildcard ./dol/*.s)
BLOB_OBJS_DOL := $(patsubst %.s,%.o,$(BLOB_ASMS_DOL))
BLOB_ASMS_REL := $(wildcard ./rel/*.s)
BLOB_OBJS_REL := $(patsubst %.s,%.o,$(BLOB_ASMS_REL))

# Rule for assembling binary blobs.
./%.o: ./%.s
	$(AS) $(AS_FLAGS) -o $@ $<

.PHONY: build
build: dol-objects rel-objects
.PHONY: dol-objects
dol-objects: $(BLOB_OBJS_DOL)
.PHONY: rel-objects
rel-objects: $(BLOB_OBJS_REL)

.PHONY: clean
clean:
	find . -type f -name '*.o' -delete
