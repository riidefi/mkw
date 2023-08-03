#pragma once

#include <rk_types.h>
#include <decomp.h>
#include <rvl/gx.h>
#include <rvl/gx/gx.h>

// Source:
// https://github.com/doldecomp/ogws/blob/master/include/egg/gfx/eggFog.h
namespace EGG {
class Fog {
public:
  Fog();
  virtual ~Fog(); // at vt+0x8

public:
  //GXColor mColor;     // at 0x0
  //f32 mStartZ;        // at 0x4
  //f32 mEndZ;          // at 0x8 (??)
  //f32 mNearZ;         // at 0xC
  //f32 mFarZ;          // at 0x10
  //GXFogType mFogType; // at 0x14
  //u8 mFlags;          // at 0x18
};
} // namespace EGG

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80226f60..0x80227018
UNKNOWN_FUNCTION(unk_80226f60);
// PAL: 0x80227018..0x80227174
UNKNOWN_FUNCTION(unk_80227018);
// PAL: 0x80227174..0x802271bc
UNKNOWN_FUNCTION(unk_80227174);

#ifdef __cplusplus
}
#endif
