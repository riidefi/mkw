SHELL := /bin/bash
.SUFFIXES:

# Compilers.
CC_4199_60831 = ../tools/4199_60831/mwcceppc.exe
CC_4201_127 = ../tools/4201_142/mwcceppc.exe

# Common CodeWarrior C flags.
CWCC_FLAGS := \
  -nodefaults \
  -align powerpc \
  -enc SJIS \
  -c \
  -gccinc \
  -i ./ \
  -i ./platform \
  -proc gekko \
  -enum int \
  -O4,p \
  -inline auto \
  -W all \
  -fp hardware \
  -Cpp_exceptions off \
  -RTTI off \
  -pragma "cats off" \
  -w notinlined \
  -W noimplicitconv \
  -nostdinc \
  -msgstyle gcc \
  -lang=c99 \
  -DREVOKART \
  -func_align 4

# RVL library config.
CC_RVL := $(CC_4199_60831)
CFLAGS_RVL := $(CWCC_FLAGS) -ipa file
OBJS_RVL := \
  rvl/arc/rvlArchive.o \
  rvl/mem/rvlMemList.o
OBJS_RVLDWC := \
  dwc/common/dwc_error.o
# NW4R library config.
CXX_NW4R := $(CC_4201_127)
CXXFLAGS_NW4R := $(CWCC_FLAGS) -ipa file -rostr -O4,p
OBJS_NW4R := \
  nw4r/ut/utList.o
# EGG library config.
CXX_EGG := $(CC_4201_127)
CXXFLAGS_EGG := $(CWCC_FLAGS) -ipa function -rostr
OBJS_EGG := \
  egg/core/eggAllocator.o \
  egg/core/eggArchive.o \
  egg/core/eggDisposer.o \
  egg/core/eggExpHeap.o \
  egg/core/eggGraphicsFifo.o \
  egg/core/eggHeap.o \
  egg/core/eggStreamDecomp.o \
  egg/core/eggThread.o \
  egg/core/eggUnitHeap.o \
  egg/core/eggVideo.o \
  egg/math/eggQuat.o \
  egg/math/eggVector.o
# REL library config.
CXX_REL := $(CC_4201_127)
CXXFLAGS_REL := $(CWCC_FLAGS) -ipa file -rostr -sdata 0 -sdata2 0
OBJS_GAME := \
  game/ui/MessageGroup.o \
  game/ui/ControlGroup.o \
  game/ui/UIControl.o \
  game/jmap/JmpResourceCourse.o

# All DOL objects.
OBJS_DOL := $(OBJS_RVL) $(OBJS_RVLDWC) $(OBJS_NW4R) $(OBJS_EGG)
OBJS_REL := $(OBJS_GAME)

.PHONY: build
build: dol-objects rel-objects
.PHONY: dol-objects
dol-objects: $(OBJS_DOL)
.PHONY: rel-objects
rel-objects: $(OBJS_REL)

.PHONY: clean
clean:
	find . -type f -name '*.o' -delete

# RVL library.
rvl/arc/rvlArchive.o: rvl/arc/rvlArchive.c
	$(CC_RVL) $(CFLAGS_RVL) -o $@ $<
rvl/mem/rvlMemList.o: rvl/mem/rvlMemList.c
	$(CC_RVL) $(CFLAGS_RVL) -o $@ $<

# RVL DWC library.
dwc/common/dwc_error.o: dwc/common/dwc_error.c
	$(CC_RVL) $(CFLAGS_RVL) -o $@ $<

# NW4R library.
nw4r/ut/utList.o: nw4r/ut/utList.cpp
	$(CXX_NW4R) $(CXXFLAGS_NW4R) -o $@ $<

# EGG library.
egg/core/eggAllocator.o: egg/core/eggAllocator.cpp
	$(CXX_EGG) $(CXXFLAGS_EGG) -use_lmw_stmw on -o $@ $<
egg/core/eggArchive.o: egg/core/eggArchive.cpp
	$(CXX_EGG) $(CXXFLAGS_EGG) -use_lmw_stmw on -o $@ $<
egg/core/eggDisposer.o: egg/core/eggDisposer.cpp
	$(CXX_EGG) $(CXXFLAGS_EGG) -o $@ $<
egg/core/eggExpHeap.o: egg/core/eggExpHeap.cpp
	$(CXX_EGG) $(CXXFLAGS_EGG) -use_lmw_stmw on -o $@ $<
egg/core/eggGraphicsFifo.o: egg/core/eggGraphicsFifo.cpp
	$(CXX_EGG) $(CXXFLAGS_EGG) -o $@ $<
egg/core/eggHeap.o: egg/core/eggHeap.cpp
	$(CXX_EGG) $(CXXFLAGS_EGG) -ipa file -use_lmw_stmw on -o $@ $<
egg/math/eggQuat.o: egg/math/eggQuat.cpp
	$(CXX_EGG) $(CXXFLAGS_EGG) -o $@ $<
egg/core/eggStreamDecomp.o: egg/core/eggStreamDecomp.cpp
	$(CXX_EGG) $(CXXFLAGS_EGG) -o $@ $<
egg/core/eggThread.o: egg/core/eggThread.cpp
	$(CXX_EGG) $(CXXFLAGS_EGG) -o $@ $<
egg/core/eggUnitHeap.o: egg/core/eggUnitHeap.cpp
	$(CXX_EGG) $(CXXFLAGS_EGG) -use_lmw_stmw on -o $@ $<
egg/core/eggVideo.o: egg/core/eggVideo.cpp
	$(CXX_EGG) $(CXXFLAGS_EGG) -use_lmw_stmw on -o $@ $<
egg/math/eggVector.o: egg/math/eggVector.cpp
	$(CXX_EGG) $(CXXFLAGS_EGG) -o $@ $<

# StaticR.rel content
game/ui/MessageGroup.o: game/ui/MessageGroup.cpp
	$(CXX_REL) $(CXXFLAGS_REL) -o $@ $<
game/ui/ControlGroup.o: game/ui/ControlGroup.cpp
	$(CXX_REL) $(CXXFLAGS_REL) -o $@ $<
game/ui/UIControl.o: game/ui/UIControl.cpp
	$(CXX_REL) $(CXXFLAGS_REL) -o $@ $<
game/jmap/JmpResourceCourse.o: game/jmap/JmpResourceCourse.cpp
	$(CXX_REL) $(CXXFLAGS_REL) -o $@ $<
