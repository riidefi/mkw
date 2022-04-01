#pragma once

#ifndef RII_CLIENT
#define UNKNOWN_FUNCTION(name) void name(void)
#else
#define UNKNOWN_FUNCTION(...)
#endif

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

// Compiler intrinsics.
#include <eabi.h>
#else
#define MARK_BINARY_BLOB
#endif
