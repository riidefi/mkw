// Source:
// https://github.com/doldecomp/ogws/blob/82dbeac2267170fc5cef7e67a6d8c31c5ff45d69/include/nw4r/g3d/g3d_fog.h
// Decompiled by kiwi515.

#pragma once

#include <rk_types.h>

#include <nw4r/math/mathTypes.hpp>
#include <nw4r/ut/utColor.hpp>

#include "g3d_rescommon.hpp"

namespace nw4r {
namespace g3d {

struct FogData {
  u32 INT_0x0;
  f32 FLOATS_0x4[4];
  ut::Color mColor;
  u8 BYTE_0x18;
  u8 BYTE_0x19;
  u16 mAdjTable[11]; // at 0x1A
};

struct Fog {
  ResCommon<FogData> mFogData;

  inline Fog(void* vptr) : mFogData(vptr) {}

  Fog(FogData*);
  void Init();
  // PAL: 0x80077550
  void* CopyTo(void*) const;
  // PAL: 0x800775b0
  void SetFogRangeAdjParam(u16, u16, const math::MTX44&);
  void SetGP() const;
};

} // namespace g3d
} // namespace nw4r
