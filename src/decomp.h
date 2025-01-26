#pragma once

#include <rk_types.h>

#ifndef RII_CLIENT
#define UNKNOWN_FUNCTION(name) void name(void)
#else
#define UNKNOWN_FUNCTION(...)
#endif
#define UNKNOWN_DATA(name) u8 name

#ifdef __CWCC__

#pragma section "binary_blobs"
#define SECTION_BINARY_BLOBS __declspec(section "binary_blobs")
#define MARK_BINARY_BLOB(name, start, stop)                                    \
  SECTION_BINARY_BLOBS static const char MARK_BINARY_BLOB_##name[] =           \
      "BINARY_BLOB: " #name "\t" #start "\t" #stop "\n"                        \
      __attribute__((force_export))

#pragma section RW "flow_check"
#define SECTION_FLOW_CHECK __declspec(section "flow_check")
#define MARK_FLOW_CHECK(start)                                                 \
  SECTION_FLOW_CHECK u32 __flow_check_##start = start             \
      __attribute__((force_export))

struct __mkw_patch {
  void* ptr;
  unsigned int len;
  unsigned long long val;
};

#pragma section "mkw_patches"
#define SECTION_MKW_PATCHES __declspec(section "mkw_patches")
#define MKW_PATCH_WORD(target, val)                                            \
  SECTION_MKW_PATCHES static const struct __mkw_patch __mkw_patch_##target     \
      __attribute__((force_export)) = {&target, 4, val}

typedef struct ps_f32 {
  f32 f0;
  f32 f1;
} ps_f32;

#define sdata_ps_f32 __declspec(section ".sdata") ps_f32
#define sdata2_ps_f32 __declspec(section ".sdata2") const ps_f32

//// Defines from ppcdis: https://github.com/SeekyCt/ppcdis
// Data dummy helpers

void __dummy_str(const char*);
void __dummy_float(float);
void __dummy_double(double);
void __dummy_pointer(const void*);

// Force a symbol to be stripped by elf2rel/elf2dol

#pragma section RX "forcestrip"
#ifndef __INTELLISENSE__
#define FORCESTRIP __declspec(section "forcestrip")
#else
#define FORCESTRIP
#endif

// Wrap in force_active pragmas to force a piece of data active
#define DUMMY_POINTER(name)                                                    \
  void dummy_ptr_##name();                                                     \
  void FORCESTRIP dummy_ptr_##name() { __dummy_pointer((const void*)&name); }

// Unfortunately these don't work on older compilers

#if __MWERKS__ >= 0x4199

// Disable deadstripping for a region

#define FORCEACTIVE_START _Pragma("push") _Pragma("force_active on")
#define FORCEACTIVE_END _Pragma("pop")

// Disable deadstripping for a bit of data

#define FORCEACTIVE_DATA(name)                                                 \
  FORCEACTIVE_START                                                            \
  DUMMY_POINTER(name)                                                          \
  FORCEACTIVE_END

#endif

// Rel symbol definition

#pragma section RW "relsymdef"

typedef struct {
  unsigned long addr;
  const void* ref;
} __RelSymbolDef;

#define REL_SYMBOL_AT(name, addr)                                              \
  __declspec(section "relsymdef")                                              \
      __RelSymbolDef rel_sym_##name = {addr, (const void*)&name};              \
  FORCEACTIVE_DATA(rel_sym_##name)

#ifndef SHIFTABLE
#define DEFINE_REL_DATA(name, addr, type, val)  \
    extern "C" UNKNOWN_DATA(name);		\
    REL_SYMBOL_AT(name, addr);
#else
#define DEFINE_REL_DATA(name, addr, type, val)  \
    static type name = val;
#endif

#define cr0lt 0
#define cr0gt 1
#define cr0eq 2
#define cr0un 3
#define cr1lt 4
#define cr1gt 5
#define cr1eq 6
#define cr1un 7
#define cr2lt 8
#define cr2gt 9
#define cr2eq 10
#define cr2un 11
#define cr3lt 12
#define cr3gt 13
#define cr3eq 14
#define cr3un 15
#define cr4lt 16
#define cr4gt 17
#define cr4eq 18
#define cr4un 19
#define cr5lt 20
#define cr5gt 21
#define cr5eq 22
#define cr5un 23
#define cr6lt 24
#define cr6gt 25
#define cr6eq 26
#define cr6un 27
#define cr7lt 28
#define cr7gt 29
#define cr7eq 30
#define cr7un 31

//// end of macros from ppcdis

#pragma section "garbage"
#define SECTION_GARBAGE
#define static_order_hints                                                     \
  SECTION_GARBAGE static void __garbage_ordering_hints(void)
#define order_hint_access(var) (void)(var)

// Compiler intrinsics.
#include <eabi.h>
#else
#define MARK_BINARY_BLOB
#endif

// for postprocess.py
#pragma dollar_identifiers on
