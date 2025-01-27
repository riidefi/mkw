// Source:
// https://github.com/doldecomp/ogws/blob/82dbeac2267170fc5cef7e67a6d8c31c5ff45d69/include/RevoSDK/GX/GXFrameBuf.h
// Decompiled by kiwi515.

#pragma once

#include <rk_types.h>
#include <decomp.h>

#include "gx.h"

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8016fc38..0x8016fd74
void GXCopyDisp(void*, u8);
// PAL: 0x8016f9c8..0x8016fa40
void GXSetCopyClear(GXColor, u32 zClear);
// PAL: 0x8016fa40..0x8016fc24
void GXSetCopyFilter(u8, const u8[12][2], u8, const u8[7]);

// PAL: 0x8016f438..0x8016f478
void GXSetDispCopySrc(u16 left, u16 top, u16 width, u16 height);
// PAL: 0x8016f478..0x8016f4b8
UNKNOWN_FUNCTION(GXSetTexCopySrc);
// PAL: 0x8016f4b8..0x8016f4dc
void GXSetDispCopyDst(u16 width, u16 height);
// PAL: 0x8016f4dc..0x8016f5f8
UNKNOWN_FUNCTION(GXSetTexCopyDst);
// PAL: 0x8016f5f8..0x8016f618
UNKNOWN_FUNCTION(GXSetDispCopyFrame2Field);
// PAL: 0x8016f618..0x8016f640
UNKNOWN_FUNCTION(GXSetCopyClamp);
// PAL: 0x8016f640..0x8016f6cc
u16 GXGetNumXfbLines(u16 efb_height, f32 y_scale_factor);
// PAL: 0x8016f6cc..0x8016f8fc
f32 GXGetYScaleFactor(u16 efb_height, u16 xfb_height);
// PAL: 0x8016f8fc..0x8016f9c8
u32 GXSetDispCopyYScale(f32 y_scale_factor);
// PAL: 0x8016fc24..0x8016fc38
UNKNOWN_FUNCTION(GXSetDispCopyGamma);
// PAL: 0x8016fd74..0x8016fecc
UNKNOWN_FUNCTION(GXCopyTex);
// PAL: 0x8016fecc..0x8016ff04
UNKNOWN_FUNCTION(GXClearBoundingBox);

#ifdef __cplusplus
}
#endif
