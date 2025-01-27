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
  /// 99% not actually last pos
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

#define COL_FLAG_FLOOR 			     0x1
#define COL_FLAG_WALL 			     0x2
#define COL_FLAG_INVISIBLE_WALL 	     0x4
#define COL_FLAG_TRICKABLE 		     0x8
#define COL_FLAG_UNK10 			     0x10
#define COL_FLAG_MOVING_WATER_V0 	     0x20
#define COL_FLAG_WALL_3 		     0x40
#define COL_FLAG_INVISIBLE_WALL_ONLY 	     0x80
#define COL_FLAG_MOVING_WATER_V2 	     0x100
#define COL_FLAG_SOFT_WALL 		     0x200
#define COL_FLAG_MOVING_WATER_STRONG_CURRENT 0x400
#define COL_FLAG_MOVING_WATER_DISABLE_ACC    0x800
#define COL_FLAG_WALL_AT_RIGHT_CLOSER 	     0x2000
#define COL_FLAG_WALL_AT_LEFT_CLOSER         0x4000
#define COL_FLAG_MOVING_WATER_V3             0x8000

struct KartCollisionInfo {
  u32 flags;
  EGG::Vector3f tangentOff;
  EGG::Vector3f floorNrm;
  EGG::Vector3f wallNrm;
  EGG::Vector3f softWallNrm;
  EGG::Vector3f vel;
  EGG::Vector3f relPos;
  EGG::Vector3f movement;
  EGG::Vector3f _58;
  f32 speedFactor;
  f32 handlingFactor;
  // floor KCL attribute stuff
  u32 floorKclTypeMask;
  s32 floorKclVariant;
  // wall KCL attribute stuff
  u32 wallKclType;
  s32 wallKclVariant;
  /// Causes the object to sink into the colliding surface by this amount (used for e.g. snow)
  u32 sinkDepth;
  /// Amount of angle between face normals of colliding wall from 0.0-1.0. Greater than 0.0 only when there is wall collision
  f32 colPerpendicularity;

  KartCollisionInfo* initStatus();
  void reset();
};
static_assert(sizeof(KartCollisionInfo) == 0x84);

class HitboxGroup {

  s16 hitboxCount;
  f32 boundingRadius;
  KartCollisionInfo colInfo;
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

  inline const Hitbox& getHitbox(u16 i) const { return hitboxes[i]; }
  inline Hitbox& getHitbox(u16 i) { return hitboxes[i]; }
  inline s32 getHitboxCount() const { return hitboxCount; }
  inline f32 getBoundingRadius() const { return boundingRadius; }
  inline const KartCollisionInfo& getKartCollisionInfo() const { return colInfo; }
  inline KartCollisionInfo& getKartCollisionInfo() { return colInfo; }
};
static_assert(sizeof(HitboxGroup) == 0x9c);
}
