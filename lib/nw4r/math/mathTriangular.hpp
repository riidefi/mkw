#pragma once

#include <rk_types.h>

namespace nw4r {
namespace math {

namespace detail {
struct SinCosSample {
  f32 sin_val;
  f32 cos_val;
  f32 sin_delta;
  f32 cos_delta;
};

extern const SinCosSample gSinCosTbl[256 + 1];
} // namespace detail

// PAL 0x80085110
f32 SinFIdx(f32 fidx);

// PAL 0x80085180
f32 CosFIdx(f32 fidx);

// PAL 0x800851e0
void SinCosFIdx(MWREG f32*, MWREG f32*, MWREG f32);

// PAL 0x80085250
f32 AtanFIdx(f32);

// PAL: 0x800853c0
f32 Atan2FIdx(f32, f32);

} // namespace math
} // namespace nw4r
