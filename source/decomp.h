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
