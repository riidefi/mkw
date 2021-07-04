// Source:
// https://github.com/doldecomp/ogws/blob/82dbeac2267170fc5cef7e67a6d8c31c5ff45d69/include/RevoSDK/GX/GXFrameBuf.h
// Decompiled by kiwi515.

#pragma once

#include <rk_types.h>

#include "gx.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _GXRenderModeObj {
  u32 INT_0x0;
  u16 mFbWidth;   // at 0x4
  u16 mEfbHeight; // at 0x8
  u16 SHORT_0x8;
  u16 SHORT_0xA;
  u16 SHORT_0xC;
  u16 SHORT_0xE;
  u16 SHORT_0x10;
  u16 UNUSED_0x12;
  u32 INT_0x14;
  u8 BYTE_0x18;
  u8 BYTE_0x19;
  u8 BYTES_0x1A[24];
  u8 BYTES_0x32[7];
} GXRenderModeObj;

void GXCopyDisp(void*, u8);
void GXSetCopyClear(GXColor, u32 zClear);
void GXSetCopyFilter(u8, const u8[12][2], u8, const u8[7]);

#ifdef __cplusplus
}
#endif
