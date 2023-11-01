#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x805b7fbc..0x805b80a8
UNKNOWN_FUNCTION(Hitbox_update);
// PAL: 0x805b80a8..0x805b8158
UNKNOWN_FUNCTION(unk_805b80a8);
// PAL: 0x805b82bc..0x805b8330
UNKNOWN_FUNCTION(CollisionGroup_construct);
// PAL: 0x805b8330..0x805b83d8
UNKNOWN_FUNCTION(HitboxGroup_reset);
// PAL: 0x805b83d8..0x805b8420
UNKNOWN_FUNCTION(unk_805b83d8);
// PAL: 0x805b84c0..0x805b86a8
UNKNOWN_FUNCTION(astruct_1_init_bsp_params);
// PAL: 0x805b86a8..0x805b875c
UNKNOWN_FUNCTION(unk_805b86a8);
// PAL: 0x805b875c..0x805b883c
UNKNOWN_FUNCTION(astruct_1_init_bsp_params_single);

#include <egg/math/eggVector.hpp>
#include <egg/math/eggQuat.hpp>
#include <egg/math/eggMatrix.hpp>

namespace Kart {
struct BspData {
  u16 enabled;
  EGG::Vector3f pos;
  f32 radius;
  u16 wallOnly; // only collide with walls
  u16 tireCollisionIndex;
};
static_assert(sizeof(BspData) == 0x18);

// Represents a sphere hitbox
class Hitbox {

  BspData* bsp;
  f32 radius;
  u32 _8;
  // position in world coordinates
  EGG::Vector3f pos;
  EGG::Vector3f lastPos;
  // position in kart coordinates
  EGG::Vector3f relPos;

public:
  Hitbox();
  // ~Hitbox() {}
  void init();
  void update(const EGG::Vector3f& scale, const EGG::Quatf& rot, const EGG::Vector3f& pos, f32 totalScale, f32 hitboxElevation);
  void setLastPos(const EGG::Vector3f& scale, const EGG::Matrix34f& pose);
  Hitbox(const EGG::Vector3f& pos, f32 radius);
  void setScale(float);
};
static_assert(sizeof(Hitbox) == 0x30);

class HitboxGroup {
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
    u32 closestFloorFlags;
    u32 closestFloorSettings;
    u32 _74;
    u32 _78;
    u32 intensity;
    f32 _80;

    void initStatus();
    void reset();
  };
  static_assert(sizeof(CollisionInfo) == 0x84);

  s32 hitboxCount;
  f32 boundingRadius;
  CollisionInfo colInfo;
  Hitbox* hitboxes;
  u32 _90;
  f32 hitboxScale;
  f32 _98;

public:
  HitboxGroup();
  void reset();
  void setHitboxScale(f32 scale);
  void createHitboxes(u32 n);
  void initHitboxes(u32 n, BspData* hitboxData);
  void setHitboxes(u32 n, BspData* hitboxData);
  void createSingleHitbox(const EGG::Vector3f& pos, f32 radius);
  void computeCollisionLimits();
};
static_assert(sizeof(HitboxGroup) == 0x9c);
}

#ifdef __cplusplus
}
#endif
