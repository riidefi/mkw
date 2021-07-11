// Source:
// https://github.com/doldecomp/ogws/blob/82dbeac2267170fc5cef7e67a6d8c31c5ff45d69/include/RevoSDK/GX/GX.h
// Decompiled by kiwi515, GibHaltmannKill.

#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _GXColor {
  u8 r;
  u8 g;
  u8 b;
  u8 a;
} GXColor;

typedef struct _GXTlutObj {
  u32 _unk00[3];
} GXTlutObj;

typedef struct _GXTexObj {
  u32 _unk00[8];
} GXTexObj;

#ifdef __cplusplus
}
#endif
