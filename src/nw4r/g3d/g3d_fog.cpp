// Source:
// https://github.com/doldecomp/ogws/blob/82dbeac2267170fc5cef7e67a6d8c31c5ff45d69/src/nw4r/g3d/g3d_fog.cpp
// Decompiled by kiwi515.

#include "g3d_fog.hpp"

#include <rvl/gx/gx.h>
#include <rvl/gx/gxPixel.h>

namespace nw4r {
namespace g3d {

Fog::Fog(FogData* pFogData) : mFogData(pFogData) {}

void Fog::Init() {
  if (mFogData.IsValid()) {
    FogData& rFogData = mFogData.ref();

    rFogData.INT_0x0 = 0;

    for (int i = 0; i < 4; i++) {
      rFogData.FLOATS_0x4[i] = 0.0f;
    }

    rFogData.mColor.mChannels.a = 0;
    rFogData.mColor.mChannels.b = 0;
    rFogData.mColor.mChannels.g = 0;
    rFogData.mColor.mChannels.r = 0;

    rFogData.BYTE_0x18 = 0;
    rFogData.BYTE_0x19 = 0;

    for (int i = 0; i < 11; i++) {
      rFogData.mAdjTable[i] = 0;
    }
  }
}

void* Fog::CopyTo(void* pFog) const {
  if (pFog) {
    register FogData& src = mFogData.ref();
    register void* dest = pFog;

    if (mFogData.IsValid()) {
      asm {
        lfd f0, 0(src);
        stfd f0, 0(dest);
        lfd f0, 8(src);
        stfd f0, 8(dest);
        lfd f0, 16(src);
        stfd f0, 16(dest);
        lfd f0, 24(src);
        stfd f0, 24(dest);
        lfd f0, 32(src);
        stfd f0, 32(dest);
        lfd f0, 40(src);
        stfd f0, 40(dest);
      }
      return pFog;
    }
  }

  return NULL;
}

void Fog::SetFogRangeAdjParam(u16 param1, u16 param2, const math::MTX44& rMtx) {
  FogData& rFogData = mFogData.ref();

  if (mFogData.IsValid()) {
    rFogData.mAdjTable[0] = param2;
    GXInitFogAdjTable(&rFogData.mAdjTable[1], param1, rMtx);
  }
}

} // namespace g3d
} // namespace nw4r
