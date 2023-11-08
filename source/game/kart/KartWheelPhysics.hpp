#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8059940c..0x80599470
UNKNOWN_FUNCTION(__ct__Q24Kart16KartWheelPhysicsFUll);
// PAL: 0x80599470..0x805994d4
UNKNOWN_FUNCTION(TirePhysics_init);
// PAL: 0x805994d4..0x80599508
UNKNOWN_FUNCTION(TirePhysics_initBsp);
// PAL: 0x80599508..0x805995c0
UNKNOWN_FUNCTION(unk_80599508);
// PAL: 0x805995c0..0x80599690
UNKNOWN_FUNCTION(unk_805995c0);
// PAL: 0x80599690..0x80599ad0
UNKNOWN_FUNCTION(WheelPhysics_updateCollision);
// PAL: 0x80599ad0..0x80599d9c
UNKNOWN_FUNCTION(WheelPhysics_realign);
// PAL: 0x80599d9c..0x80599dc0
UNKNOWN_FUNCTION(unk_80599d9c);
// PAL: 0x80599dc0..0x80599eac
UNKNOWN_FUNCTION(unk_80599dc0);
// PAL: 0x80599eac..0x80599ebc
UNKNOWN_FUNCTION(WheelPhysics_hasFloorCollision);
// PAL: 0x80599ebc..0x80599ec8
UNKNOWN_FUNCTION(unk_80599ebc);
// PAL: 0x80599ec8..0x80599ed4
UNKNOWN_FUNCTION(WheelPhysics_getCollisionData);
// PAL: 0x80599ed4..0x80599f54
UNKNOWN_FUNCTION(__ct__Q24Kart14KartSusPhysicsFUlll);
// PAL: 0x80599f54..0x80599fa0
UNKNOWN_FUNCTION(KartSusPhysics_reset);
// PAL: 0x80599fa0..0x8059a02c
UNKNOWN_FUNCTION(KartSusPhysics_init);
// PAL: 0x8059a02c..0x8059a278
UNKNOWN_FUNCTION(unk_8059a02c);
// PAL: 0x8059a278..0x8059a4f8
UNKNOWN_FUNCTION(WheelPhysicsHolder_update);
// PAL: 0x8059a4f8..0x8059a574
UNKNOWN_FUNCTION(vec3_from_mat33_mul);
// PAL: 0x8059a574..0x8059a9c4
UNKNOWN_FUNCTION(WheelPhysicsHolder_applySuspensions);
// PAL: 0x8059a9c4..0x8059aa04
UNKNOWN_FUNCTION(WheelPhysics_destroy);
// PAL: 0x8059aa04..0x8059aa44
UNKNOWN_FUNCTION(unk_8059aa04);

#ifdef __cplusplus
}
#endif

#include "KartObjectProxy.hpp"
#include "KartHitbox.hpp"
#include "BSP.hpp"

#include "egg/math/eggVector.hpp"

namespace Kart {
class KartWheelPhysics;
class KartSusPhysics : public KartObjectProxy {
public:
  virtual ~KartSusPhysics() {}

  KartSusPhysics(u32 wheelIdx, s32 wheelType, s32 bspWheelIdx);

private:
  BspWheel* bspWheel;
  KartWheelPhysics* wheelPhysics;
  s32 wheelType;
  u32 bspWheelIdx;
  u32 wheelIdx;
  // topmost point of the suspension the wheel can reach
  EGG::Vector3f suspTop;
  // bsp max suspension travel after vehicle scale is applied
  f32 maxTravelScaled;
  u8 unk[0x38 - 0x34];
  f32 _38;
  EGG::Vector3f downDir;
};

static_assert(sizeof(KartSusPhysics) == 0x48);
class KartWheelPhysics : public KartObjectProxy {
public:
  virtual ~KartWheelPhysics() {}

  KartWheelPhysics(u32 wheelIdx, s32 bspWheelIdx);

private:
  u32 wheelIdx;
  u32 bspWheelIdx;
  BspWheel* bspWheel;
  HitboxGroup* hitboxGroup;
};
}
