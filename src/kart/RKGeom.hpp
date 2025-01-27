#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x805ae7b4..0x805ae8d0
UNKNOWN_FUNCTION(unk_805ae7b4);
// PAL: 0x805ae8d0..0x805ae9ec
UNKNOWN_FUNCTION(unk_805ae8d0);
// PAL: 0x805ae9ec..0x805aead8
UNKNOWN_FUNCTION(VEC3_perpInPlane);
// PAL: 0x805aead8..0x805aeb88
UNKNOWN_FUNCTION(unk_805aead8);
// PAL: 0x805aec8c..0x805aeca8
UNKNOWN_FUNCTION(f32_interpolate__6RKGeomFfRfRCfRCf);
// PAL: 0x805aeca8..0x805aed14
UNKNOWN_FUNCTION(unk_805aeca8);
// PAL: 0x805aed14..0x805aee14
UNKNOWN_FUNCTION(unk_805aed14);
// PAL: 0x805aee14..0x805aeec4
UNKNOWN_FUNCTION(unk_805aee14);
// PAL: 0x805aeec4..0x805aef6c
UNKNOWN_FUNCTION(unk_805aeec4);
// PAL: 0x805aef6c..0x805af020
UNKNOWN_FUNCTION(unk_805aef6c);
// PAL: 0x805af020..0x805af048
UNKNOWN_FUNCTION(unk_805af020);
// PAL: 0x805af048..0x805af0f0
UNKNOWN_FUNCTION(unk_805af048);
// PAL: 0x805af0f0..0x805af148
UNKNOWN_FUNCTION(unk_805af0f0);
// PAL: 0x805af148..0x805af1bc
UNKNOWN_FUNCTION(unk_805af148);
// PAL: 0x805af1bc..0x805af228
UNKNOWN_FUNCTION(unk_805af1bc);
// PAL: 0x805af228..0x805af330
UNKNOWN_FUNCTION(unk_805af228);
// PAL: 0x805af330..0x805af370
UNKNOWN_FUNCTION(unk_805af330);

#ifdef __cplusplus
}
#endif

#include "egg/math/eggVector.hpp"

namespace RKGeom {
void projUnit(EGG::Vector3f&, const EGG::Vector3f &v0, const EGG::Vector3f &v1);
void rejUnit(EGG::Vector3f& dst, const EGG::Vector3f &v0, const EGG::Vector3f &v1);
void projAndRej(EGG::Vector3f& proj, EGG::Vector3f& rej, const EGG::Vector3f &v0, const EGG::Vector3f &v1);

// template maybe?
void f32_interpolate(f32 t, f32& dst, const f32& f1, const f32& f2);
void vec_interpolate(f32 t, EGG::Vector3f& dst, const EGG::Vector3f& f1, const EGG::Vector3f& f2);
}
