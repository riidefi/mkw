#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef GEKKO
#define MTX_USE_C
#undef  MTX_USE_PS
#endif

#if ( !defined(MTX_USE_PS) && !defined(MTX_USE_C) )
#ifndef _DEBUG
#define MTX_USE_PS
#endif
#endif

typedef struct {
  f32 x, y, z;
} Vec;

typedef struct {
  f32 x, y;
} Vec2;

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
// PAL: 0x8019a188
void PSMTXRotRad(Mtx, char, f32);
// PAL: 0x8019a204
void PSMTXRotTrig(Mtx, char, f32, f32);
// PAL: 0x8019a2b4
void __PSMTXRotAxisRadInternal(Mtx, const Vec*, f32, f32);
// PAL: 0x8019a364
void PSMTXRotAxisRad(Mtx, const Vec*, f32);
// PAL: 0x8019a3e0
void PSMTXTrans(Mtx, f32, f32, f32);
// PAL: 0x8019a414
void PSMTXTransApply(const Mtx, Mtx, f32, f32, f32);
// PAL: 0x8019a460
void PSMTXScale(Mtx, f32, f32, f32);
// PAL: 0x8019a488
void PSMTXScaleApply(const Mtx, Mtx, f32, f32, f32);
// PAL: 0x8019a4e0
void PSMTXQuat(Mtx m, const Quaternion*);
// PAL: 0x8019a584
void C_MTXLookAt(Mtx, const Vec*, const Vec*, const Vec*);
// PAL: 0x8019a6f8
void C_MTXLightFrustum(Mtx, f32, f32, f32, f32, f32, f32, f32, f32, f32);
// PAL: 0x8019a79c
void C_MTXLightPerspective(Mtx, f32, f32, f32, f32, f32, f32);
// PAL: 0x8019a894
void C_MTXLightOrtho(Mtx, f32, f32, f32, f32, f32, f32, f32, f32);
// not present in mkw
void C_MTXMultVec(const Mtx, const Vec*, Vec*);
// PAL: 0x8019a91c
void PSMTXMultVec(const Mtx, const Vec*, Vec*);
// not present in mkw
void C_MTXMultVecSR(const Mtx, const Vec*, Vec*);
// PAL: 0x8019a970
void PSMTXMultVecSR(const Mtx, const Vec*, Vec*);

#ifdef MTX_USE_PS
#define MTXIdentity             PSMTXIdentity
#define MTXCopy                 PSMTXCopy
#define MTXConcat               PSMTXConcat
#define MTXConcatArray          PSMTXConcatArray
#define MTXTranspose            PSMTXTranspose
#define MTXInverse              PSMTXInverse
#define MTXInvXpose             PSMTXInvXpose
#else // MTX_USE_C
#define MTXIdentity             C_MTXIdentity
#define MTXCopy                 C_MTXCopy
#define MTXConcat               C_MTXConcat
#define MTXConcatArray          C_MTXConcatArray
#define MTXTranspose            C_MTXTranspose
#define MTXInverse              C_MTXInverse
#define MTXInvXpose             C_MTXInvXpose
#endif

#ifdef MTX_USE_PS
#define MTXMultVec              PSMTXMultVec
#define MTXMultVecArray         PSMTXMultVecArray
#define MTXMultVecSR            PSMTXMultVecSR
#define MTXMultVecArraySR       PSMTXMultVecArraySR
#else // MTX_USE_C
#define MTXMultVec              C_MTXMultVec
#define MTXMultVecArray         C_MTXMultVecArray
#define MTXMultVecSR            C_MTXMultVecSR
#define MTXMultVecArraySR       C_MTXMultVecArraySR
#endif

// rvlMtx2.c
// PAL: 0x8019a9c4
void C_MTXFrustum(Mtx44, f32, f32, f32, f32, f32, f32);
// PAL: 0x8019aa60
void C_MTXPerspective(Mtx44, f32, f32, f32, f32);
// PAL: 0x8019ab4c
void C_MTXOrtho(Mtx44, f32, f32, f32, f32, f32, f32);

#define MTXFrustum              C_MTXFrustum
#define MTXPerspective          C_MTXPerspective
#define MTXOrtho                C_MTXOrtho

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
void C_VECCrossProduct(const Vec*, const Vec*, Vec*);
// PAL: 0x8019accc
void PSVECCrossProduct(const Vec*, const Vec*, Vec*);
// PAL: 0x8019ad08
void C_VECHalfAngle(const Vec*, const Vec*, Vec*);
// PAL: 0x8019ade0
f32 PSVECSquareDistance(const Vec*, const Vec*);

#ifdef MTX_USE_PS
#define VECAdd                  PSVECAdd
#define VECSubtract             PSVECSubtract
#define VECScale                PSVECScale
#define VECNormalize            PSVECNormalize
#define VECSquareMag            PSVECSquareMag
#define VECMag                  PSVECMag
#define VECDotProduct           PSVECDotProduct
#define VECCrossProduct         PSVECCrossProduct
#define VECSquareDistance       PSVECSquareDistance
#define VECDistance             PSVECDistance
#else // MTX_USE_C
#define VECAdd                  C_VECAdd
#define VECSubtract             C_VECSubtract
#define VECScale                C_VECScale
#define VECNormalize            C_VECNormalize
#define VECSquareMag            C_VECSquareMag
#define VECMag                  C_VECMag
#define VECDotProduct           C_VECDotProduct
#define VECCrossProduct         C_VECCrossProduct
#define VECSquareDistance       C_VECSquareDistance
#define VECDistance             C_VECDistance
#endif

#define VECReflect              C_VECReflect
#define VECHalfAngle            C_VECHalfAngle

// rvlQuat.c
// PAL: 0x8019ae08
void PSQUATMultiply(const Quaternion*, const Quaternion*, Quaternion*);
// PAL: 0x8019ae64
void PSQUATScale(const Quaternion*, Quaternion*, f32);
// PAL: 0x8019ae80
f32 PSQUATDotProduct(const Quaternion*, const Quaternion*);
// PAL: 0x8019aea0
void PSQUATNormalize(const Quaternion*, Quaternion*);
// PAL: 0x8019aef4
void PSQUATInverse(const Quaternion*, Quaternion*);
// PAL: 0x8019af48
void C_QUATMtx(Quaternion*, const Mtx);
// PAL: 0x8019b114
void C_QUATLerp(const Quaternion*, const Quaternion*, Quaternion*, f32);
// PAL: 0x8019b178
void C_QUATSlerp(const Quaternion*, const Quaternion*, Quaternion*, f32);

#ifdef MTX_USE_PS
#define QUATAdd                 PSQUATAdd
#define QUATSubtract            PSQUATSubtract
#define QUATMultiply            PSQUATMultiply
#define QUATDivide              PSQUATDivide
#define QUATScale               PSQUATScale
#define QUATDotProduct          PSQUATDotProduct
#define QUATNormalize           PSQUATNormalize
#define QUATInverse             PSQUATInverse
#else // MTX_USE_C
#define QUATAdd                 C_QUATAdd
#define QUATSubtract            C_QUATSubtract
#define QUATMultiply            C_QUATMultiply
#define QUATDivide              C_QUATDivide
#define QUATScale               C_QUATScale
#define QUATDotProduct          C_QUATDotProduct
#define QUATNormalize           C_QUATNormalize
#define QUATInverse             C_QUATInverse
#endif

#define QUATExp                 C_QUATExp
#define QUATLogN                C_QUATLogN
#define QUATMakeClosest         C_QUATMakeClosest
#define QUATRotAxisRad          C_QUATRotAxisRad
#define QUATMtx                 C_QUATMtx
#define QUATLerp                C_QUATLerp
#define QUATSlerp               C_QUATSlerp
#define QUATSquad               C_QUATSquad
#define QUATCompA               C_QUATCompA

#ifdef __cplusplus
}
#endif
