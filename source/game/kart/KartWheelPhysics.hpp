#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x805995c0..0x80599690
UNKNOWN_FUNCTION(unk_805995c0);
// PAL: 0x80599690..0x80599ad0
UNKNOWN_FUNCTION(WheelPhysics_updateCollision);
// PAL: 0x80599ad0..0x80599d9c
UNKNOWN_FUNCTION(WheelPhysics_realign);
// PAL: 0x80599d9c..0x80599dc0
UNKNOWN_FUNCTION(updateEffectiveRadius__Q24Kart16KartWheelPhysicsFv);
// PAL: 0x80599dc0..0x80599eac
UNKNOWN_FUNCTION(unk_80599dc0);
// PAL: 0x80599eac..0x80599ebc
UNKNOWN_FUNCTION(WheelPhysics_hasFloorCollision);
// PAL: 0x8059a02c..0x8059a278
UNKNOWN_FUNCTION(unk_8059a02c);
// PAL: 0x8059a278..0x8059a4f8
UNKNOWN_FUNCTION(WheelPhysicsHolder_update);
// PAL: 0x8059a4f8..0x8059a574
UNKNOWN_FUNCTION(vec3_from_mat33_mul);
// PAL: 0x8059a574..0x8059a9c4
UNKNOWN_FUNCTION(WheelPhysicsHolder_applySuspensions);

#ifdef __cplusplus
}
#endif

#include "KartObjectProxy.hpp"
#include "KartHitbox.hpp"
#include "BSP.hpp"

#include "egg/math/eggVector.hpp"
#include "egg/math/eggMatrix.hpp"

namespace Kart {
class KartWheelPhysics;
class KartSusPhysics : public KartObjectProxy {
public:
  virtual ~KartSusPhysics() {}

  KartSusPhysics(u32 wheelIdx, s32 wheelType, s32 bspWheelIdx);
  void reset();
  void init();
  void setInitialState();
  void calc(EGG::Vector3f& gravity, const EGG::Matrix34f& mat, f32 factor);
  void applySuspension(const EGG::Vector3f& forward, const EGG::Vector3f& vehicleMovement);

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
  u8 _34;
  u16 _36;
  f32 _38;
  EGG::Vector3f downDir;
};
static_assert(sizeof(KartSusPhysics) == 0x48);

class KartWheelPhysics : public KartObjectProxy {
public:
  virtual ~KartWheelPhysics() {}

  KartWheelPhysics(u32 wheelIdx, s32 bspWheelIdx);
  void init();
  void setBsp();
  void reset();
  // unused
  void setSuspState(f32 idk, f32 travel, const EGG::Vector3f& colVel);
  void updateCollision(const EGG::Vector3f& bottom, const EGG::Vector3f& topmostPos);
  void reallign(const EGG::Vector3f& down, const EGG::Vector3f& vehicleMovement);
  void updateEffectiveRadius();
  // unused
  void unk80599dc0(const EGG::Vector3f& front);
  const EGG::Vector3f* getCollisionFloorDir() const;
  const CollisionInfo* getCollisionInfo() const;

private:
  u32 wheelIdx;
  u32 bspWheelIdx;
  BspWheel* bspWheel;
  HitboxGroup* hitboxGroup;
  // Positions wrt world unless specified otherwise
  // wheel center position
  EGG::Vector3f wheelPos;
  EGG::Vector3f prevWheelPos;
  // previous wheel offset wrt suspension top
  EGG::Vector3f prevWheelOffset;
  f32 susTravel;
  EGG::Vector3f _48;
  EGG::Vector3f speed;
  // position of the bottom part of the wheel (where it contacts the ground)
  EGG::Vector3f wheelEdgePos;
  // Tires get squished a little on hard floor collisions
  f32 effectiveRadius;
  f32 targetEffectiveRadius;
  f32 isAtSuspTopLimit;
  // topmost point of the suspension the wheel can reach
  EGG::Vector3f suspTop;
};
static_assert(sizeof(KartWheelPhysics) == 0x84);
}
