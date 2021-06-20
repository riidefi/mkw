#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  f32 x, y, z;
} Vec;

typedef f32 Mtx[3][4];
typedef f32 (*MtxPtr)[4];

typedef f32 Mtx44[4][4];
typedef f32 (*Mtx44Ptr)[4];

// PAL: 0x80199d04
void PSMTXIdentity(Mtx);
// PAL: 0x80199d30
void PSMTXCopy(const Mtx, Mtx);
// PAL: 0x80199d64
void PSMTXConcat(const Mtx, const Mtx, Mtx);
// PAL: 0x80199e30
void PSMTXConcatArray(const Mtx, const Mtx*, Mtx*, u32);
// PAL: 0x80199fc8
u32 PSMTXInverse(const Mtx, Mtx);
// PAL: 0x8019a0c0
u32 PSMTXInvXpose(const Mtx, Mtx);

// PAL: 0x8019aa60
void C_MTXPerspective (Mtx44, f32, f32, f32, f32);



void PSMTXRotAxisRad(Mtx, const Vec*, f32);

#ifdef __cplusplus
}
#endif
