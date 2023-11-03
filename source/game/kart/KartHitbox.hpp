#pragma once

#include <rk_types.h>

#include <decomp.h>

#include <egg/math/eggVector.hpp>
#include <egg/math/eggQuat.hpp>
#include <egg/math/eggMatrix.hpp>

#include "BSP.hpp"

namespace Kart {
// Represents a sphere hitbox
class Hitbox {
public:
  BspHitbox* bsp;
  f32 radius;
  u32 _8;
  // position in world coordinates
  EGG::Vector3f pos;
  EGG::Vector3f lastPos;
  // position in kart coordinates
  EGG::Vector3f relPos;

public:
  Hitbox();
  ~Hitbox() {}
  void reset();
  void update(const EGG::Vector3f& scale, const EGG::Quatf& rot, const EGG::Vector3f& pos, f32 totalScale, f32 hitboxElevation);
  void setLastPos(const EGG::Vector3f& scale, const EGG::Matrix34f& pose);
  BspHitbox* create(const EGG::Vector3f& pos, f32 radius);
  void setScale(float);
};
static_assert(sizeof(Hitbox) == 0x30);

struct CollisionInfo {
  // Not fully understood, names not final
  u32 flags;
  EGG::Vector3f nrm;
  EGG::Vector3f floorDir;
  EGG::Vector3f maybeLastWallDir;
  EGG::Vector3f _28;
  EGG::Vector3f vel;
  EGG::Vector3f relPos;
  EGG::Vector3f movement;
  EGG::Vector3f _58;
  f32 speedFactor;
  f32 rotFactor;
  // KCL base and variant?
  u32 closestFloorFlags;
  s32 closestFloorSettings;
  // extra KCL base and variant?
  u32 _74;
  s32 _78;
  u32 intensity;
  f32 _80;

  CollisionInfo* initStatus();
  void reset();
};
static_assert(sizeof(CollisionInfo) == 0x84);

class HitboxGroup {

  s16 hitboxCount;
  f32 boundingRadius;
  CollisionInfo colInfo;
  Hitbox* hitboxes;
  u32 _90;
  f32 hitboxScale;
  f32 _98;

public:
  HitboxGroup();
  ~HitboxGroup() {}
  void reset();
  void setHitboxScale(f32 scale);
  void createHitboxes(s32 n);
  f32 initHitboxes(BspHitbox* hitboxData, void* unused, s32 wheelCount);
  f32 setHitboxes(BspHitbox* hitboxData);
  void createSingleHitbox(const EGG::Vector3f& pos, f32 radius);
  f32 computeCollisionLimits();

  inline Hitbox& getHitbox(u16 i) const { return hitboxes[i]; }
};
static_assert(sizeof(HitboxGroup) == 0x9c);
}
