// Source:
// https://github.com/doldecomp/ogws/blob/82dbeac2267170fc5cef7e67a6d8c31c5ff45d69/include/RevoSDK/GX/GXTransform.h
// Decompiled by kiwi515.

#pragma once

#include <rk_types.h>
#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80173430..0x80173498
void GXSetScissor(u32, u32, u32, u32);
// PAL: 0x801734e0..0x8017351c
void GXSetScissorBoxOffset(s32, s32);

// PAL: 0x80173214..0x80173234
void GXSetCurrentMtx(u32);

// PAL: 0x801733b4..0x801733e0
void GXSetViewport(f32, f32, f32, f32, f32, f32);
// PAL: 0x80173378..0x801733b4
void GXSetViewportJitter(f32, f32, f32, f32, f32, f32, u32);

// PAL: 0x8017301c..0x80173080
void GXSetProjection(const f32*, u32);

// PAL: 0x8017310c..0x8017315c
void GXLoadPosMtxImm(const f32 mtxPtr[3][4], u32 id2);

// PAL: 0x80172fd8..0x8017301c
UNKNOWN_FUNCTION(__GXSetProjection);
// PAL: 0x80173080..0x801730cc
UNKNOWN_FUNCTION(GXSetProjectionv);
// PAL: 0x801730cc..0x8017310c
UNKNOWN_FUNCTION(GXGetProjectionv);
// PAL: 0x8017315c..0x80173188
UNKNOWN_FUNCTION(GXLoadPosMtxIndx);
// PAL: 0x80173188..0x801731e0
UNKNOWN_FUNCTION(GXLoadNrmMtxImm);
// PAL: 0x801731e0..0x80173214
UNKNOWN_FUNCTION(GXLoadNrmMtxIndx3x3);
// PAL: 0x80173234..0x801732e8
UNKNOWN_FUNCTION(GXLoadTexMtxImm);
// PAL: 0x801732e8..0x80173378
UNKNOWN_FUNCTION(__GXSetViewport);
// PAL: 0x801733e0..0x80173400
UNKNOWN_FUNCTION(GXGetViewportv);
// PAL: 0x80173400..0x80173430
UNKNOWN_FUNCTION(GXSetZScaleOffset);
// PAL: 0x80173498..0x801734e0
UNKNOWN_FUNCTION(GXGetScissor);
// PAL: 0x8017351c..0x80173544
UNKNOWN_FUNCTION(GXSetClipMode);
// PAL: 0x80173544..0x801735cc
UNKNOWN_FUNCTION(__GXSetMatrixIndex);

#ifdef __cplusplus
}
#endif
