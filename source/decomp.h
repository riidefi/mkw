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
