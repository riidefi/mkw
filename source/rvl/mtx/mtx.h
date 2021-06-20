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

typedef struct {
  f32 x, y, z, w;
} Quaternion;

// rvlMtx.c
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

void PSMTXRotAxisRad(Mtx, const Vec*, f32);

// rvlMtx2.c
// PAL: 0x8019aa60
void C_MTXPerspective(Mtx44, f32, f32, f32, f32);
// PAL: 0x8019ab4c
void C_MTXOrtho(Mtx44, f32, f32, f32, f32, f32, f32);

// rvlVec.c
// PAL: 0x8019abe4
void PSVECAdd(const Vec*, const Vec*, Vec*);
// PAL: 0x8019ac08
void PSVECScale(const Vec*, Vec*, f32);
// PAL: 0x8019ac24
void PSVECNormalize(const Vec*, Vec*);
// PAL: 0x8019ac68
f32 PSVECMag(const Vec*);
// PAL: 0x8019acac
f32 PSVECDotProduct(const Vec*, const Vec*);
// PAL: 0x8019accc
void PSVECCrossProduct(const Vec*, const Vec*, Vec*);
// PAL: 0x8019ad08
void C_VECHalfAngle(const Vec*, const Vec*, Vec*);
// PAL: 0x8019ade0
f32 PSVECSquareDistance(const Vec*, const Vec*);

// rvlQuat.c
// PAL: 0x8019ae08
void PSQUATMultiply(const Quaternion*, const Quaternion*, Quaternion*);
// PAL: 0x8019ae64
void PSQUATScale(const Quaternion*, Quaternion*, f32);
// PAL: 0x8019ae80

// PAL: 0x8019aea0

// PAL: 0x8019aef4

// PAL: 0x8019af48

// PAL: 0x8019b114

// PAL: 0x8019b178

#ifdef __cplusplus
}
#endif
