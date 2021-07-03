// Source:
// https://github.com/doldecomp/ogws/blob/82dbeac2267170fc5cef7e67a6d8c31c5ff45d69/include/RevoSDK/GX/GXTransform.h
// Decompiled by kiwi515.

#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

void GXSetScissor(u32, u32, u32, u32);
void GXSetScissorBoxOffset(s32, s32);

void GXSetCurrentMtx(u32);

void GXSetViewport(f32, f32, f32, f32, f32, f32);
void GXSetViewportJitter(f32, f32, f32, f32, f32, f32, u32);

void GXSetProjection(const f32*, u32);

void GXLoadPosMtxImm(const f32 mtxPtr[3][4], u32 id2);

#ifdef __cplusplus
}
#endif
