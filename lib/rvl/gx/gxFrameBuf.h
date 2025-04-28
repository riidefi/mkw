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

void GXCopyDisp(void*, u8);
void GXSetCopyClear(GXColor, u32 zClear);
void GXSetCopyFilter(u8, const u8[12][2], u8, const u8[7]);

void GXSetDispCopySrc(u16 left, u16 top, u16 width, u16 height);
void GXSetDispCopyDst(u16 width, u16 height);
u16 GXGetNumXfbLines(u16 efb_height, f32 y_scale_factor);
f32 GXGetYScaleFactor(u16 efb_height, u16 xfb_height);
u32 GXSetDispCopyYScale(f32 y_scale_factor);

#ifdef __cplusplus
}
#endif
