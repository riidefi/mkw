#pragma once

#include <rk_types.h>

#include <decomp.h>

#include "egg/math/eggVector.hpp"

namespace RKGeom {
void projUnit(EGG::Vector3f&, const EGG::Vector3f &v0, const EGG::Vector3f &v1);
void rejUnit(EGG::Vector3f& dst, const EGG::Vector3f &v0, const EGG::Vector3f &v1);
void projAndRej(EGG::Vector3f& proj, EGG::Vector3f& rej, const EGG::Vector3f &v0, const EGG::Vector3f &v1);

// template maybe?
void f32_interpolate(f32 t, f32& dst, const f32& f1, const f32& f2);
void vec_interpolate(f32 t, EGG::Vector3f& dst, const EGG::Vector3f& f1, const EGG::Vector3f& f2);
}
