// Source:
// https://github.com/doldecomp/ogws/blob/82dbeac2267170fc5cef7e67a6d8c31c5ff45d69/include/RevoSDK/GX/GXPixel.h
// Decompiled by kiwi515.

#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

void GXSetFog(int, f32, f32, f32, f32, GXColor);

void GXInitFogAdjTable(u16* table, u16 width, const f32 [4][4]);
void GXSetFogRangeAdj(u8, u16, u16* table);

void GXSetBlendMode(u32, u32, u32, u32);

void GXSetColorUpdate(u8);
void GXSetAlphaUpdate(u8);
void GXSetZMode(u8, u32, u8);
void GXSetZCompLoc(u8);

void GXSetDstAlpha(u8, u8);

#ifdef __cplusplus
}
#endif
