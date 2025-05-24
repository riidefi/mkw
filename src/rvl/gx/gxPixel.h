// Source:
// https://github.com/doldecomp/ogws/blob/82dbeac2267170fc5cef7e67a6d8c31c5ff45d69/include/RevoSDK/GX/GXPixel.h
// Decompiled by kiwi515.

#pragma once

#include <rk_types.h>
#include <decomp.h>

#include "gx.h"

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x801722cc..0x801724f8
void GXSetFog(int, f32, f32, f32, f32, GXColor);

// PAL: 0x801724f8..0x80172658
void GXInitFogAdjTable(u16* table, u16 width, const f32[4][4]);
// PAL: 0x80172658..0x8017277c
void GXSetFogRangeAdj(u8, u16, u16* table);

// PAL: 0x8017277c..0x801727cc
void GXSetBlendMode(u32, u32, u32, u32);

// PAL: 0x801727cc..0x801727f8
void GXSetColorUpdate(u8);
// PAL: 0x801727f8..0x80172824
void GXSetAlphaUpdate(u8);
// PAL: 0x80172824..0x80172858
void GXSetZMode(u8, u32, u8);
// PAL: 0x80172858..0x80172888
void GXSetZCompLoc(u8);

// PAL: 0x8017295c..0x8017298c
void GXSetDstAlpha(u8, u8);

// PAL: 0x80172888..0x80172930
UNKNOWN_FUNCTION(GXSetPixelFmt);
// PAL: 0x80172930..0x8017295c
UNKNOWN_FUNCTION(GXSetDither);
// PAL: 0x8017298c..0x801729c0
UNKNOWN_FUNCTION(GXSetFieldMask);
// PAL: 0x801729c0..0x80172a30
UNKNOWN_FUNCTION(GXSetFieldMode);

#ifdef __cplusplus
}
#endif
