#pragma once

#include <rk_types.h>

#include <decomp.h>

extern "C" {
// PAL: 0x80599690..0x80599ad0
UNKNOWN_FUNCTION(calcCollision__Q24Kart16KartWheelPhysicsFRCQ23EGG8Vector3fRCQ23EGG8Vector3f);
// PAL: 0x8059a574..0x8059a9c4
UNKNOWN_FUNCTION(WheelPhysicsHolder_applySuspensions);
}

#include "KartObjectProxy.hpp"
#include "KartHitbox.hpp"
#include "KartPhysicsEngine.hpp"
#include "KartDynamics.hpp"
#include "KartState.hpp"
#include "KartCollide.hpp"
#include "BSP.hpp"
#include "RKGeom.hpp"

#include "egg/math/eggVector.hpp"
#include "egg/math/eggMatrix.hpp"

namespace Kart {
enum KartWheelType {
  KART_WHEEL_KART_LEFT,
  KART_WHEEL_KART_RIGHT,
  KART_WHEEL_BIKE,
};

class KartWheelPhysics;
class KartSusPhysics : public KartObjectProxy {
public:
  virtual ~KartSusPhysics() {}

  KartSusPhysics(u32 wheelIdx, KartWheelType wheelType, s32 bspWheelIdx);
  void reset();
  void init();
  void setInitialState();
  void calc(const EGG::Vector3f& forward, const EGG::Vector3f& vehicleMovement);
  void calcCollision(const EGG::Vector3f& gravity, const EGG::Matrix34f& mtx, f32 dt);

private:
public:
  BspWheel* bspWheel;
  KartWheelPhysics* wheelPhysics;
private:
  KartWheelType wheelType;
  u32 bspWheelIdx;
  u32 wheelIdx;
  // topmost point of the suspension the wheel can reach
  EGG::Vector3f suspTop;
  // bsp max suspension travel after vehicle scale is applied
  f32 maxTravelScaled;
  bool hasFloorCol;
  s16 _36;
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
  // inlined at SusPhysics::calcCollision
  void setColState(f32 dt, f32 travel, const EGG::Vector3f& colForce);
  void setInitialState();
  void calcCollision(const EGG::Vector3f& bottom, const EGG::Vector3f& topmostPos);
  void calc(const EGG::Vector3f& down, const EGG::Vector3f& vehicleMovement);
  void updateEffectiveRadius();
  // inlined in SusPhysics::calc
  void unk80599dc0(const EGG::Vector3f& front);

  bool hasFloorCollision() const;
  const EGG::Vector3f& getCollisionFloorNrm() const;
  const KartCollisionInfo& getKartCollisionInfo() const;

  f32 getSusTravel() const { return susTravel; }
  void setWheelPos(const EGG::Vector3f& wheelPos) { this->wheelPos = wheelPos; }
  inline f32 getYScale() { return kartPhysicsEngine()->getYScale(); }
  inline const HitboxGroup* getHitbox() const { return hitboxGroup; }
  inline HitboxGroup* getHitbox() { return hitboxGroup; }

private:
public:
  u32 wheelIdx;
  u32 bspWheelIdx;
  BspWheel* bspWheel;
  HitboxGroup* hitboxGroup;
  // Positions wrt world unless specified otherwise
  // wheel center position
  EGG::Vector3f wheelPos;
  EGG::Vector3f prevWheelPos;
  // previous wheel offset wrt current suspension top
  EGG::Vector3f prevWheelOffset;
  f32 susTravel;
  EGG::Vector3f colVel;
  EGG::Vector3f speed;
  // position of the bottom part of the wheel (where it contacts the ground)
  EGG::Vector3f wheelEdgePos;
  // Tires get squished a little on hard floor collisions
  f32 effectiveRadius;
  f32 targetEffectiveRadius;
  f32 isAtSuspLimit;
  // topmost point of the suspension the wheel can reach
  EGG::Vector3f suspTop;
};
static_assert(sizeof(KartWheelPhysics) == 0x84);
}
