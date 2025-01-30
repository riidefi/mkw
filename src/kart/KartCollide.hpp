#pragma once

#include <rk_types.h>

#include <decomp.h>

#include "KartObjectProxy.hpp"
#include "KartHitbox.hpp"
#include "KartMove.hpp"
#include "KartState.hpp"
#include "KartBody.hpp"
#include "KartDynamics.hpp"
#include "field/CourseColManager.hpp"
#include "field/CourseModel.hpp"
#include "field/CollisionEntries.hpp"

namespace Kart {
class KartCollideAreaBase : public KartObjectProxy {
public:
  virtual ~KartCollideAreaBase();
  virtual void init();
  virtual void vf10();
  virtual void vf14();

private:
  u8 _10[0x38 - 0x10];
};
static_assert(sizeof(KartCollideAreaBase) == 0x38);

// 0x80593fa4. Not understood well at all
class KartCollideArea : public KartCollideAreaBase {
public:
  KartCollideArea();
  virtual ~KartCollideArea();
  virtual void init() override;
  virtual void vf10() override;
  virtual void vf14() override;

private:
  u8 _38[0x40 - 0x38];
};
static_assert(sizeof(KartCollideArea) == 0x40);

class IKartCollide {
public:
  virtual void processBody(KartCollisionInfo& kartColInfo, const Hitbox& hitbox, const Field::ColInfo& colInfo, u32* colTypeMask) = 0;
  virtual void processWheels(KartCollisionInfo& kartColInfo, const Hitbox& hitbox, const Field::ColInfo& colInfo, u32* colTypeMask) = 0;
};

#define SURF_FLAG_WALL 		      0x1
#define SURF_FLAG_SOLID_OOB 	      0x2
#define SURF_FLAG_UNK_4 	      0x4
#define SURF_FLAG_UNK_8 	      0x8
// KCL boost ramps
#define SURF_FLAG_BOOST_RAMP 	      0x10
#define SURF_FLAG_GROUND_OFFROAD      0x20
#define SURF_FLAG_OFFROAD 	      0x40
// "boost panel" here includes KCL boost ramps
#define SURF_FLAG_GROUND_BOOST_PANEL  0x80
#define SURF_FLAG_BOOST_PANEL 	      0x100
#define SURF_FLAG_HALFPIPE_RAMP       0x200
#define SURF_FLAG_TRICKABLE 	      0x800
#define SURF_FLAG_NOT_TRICKABLE       0x1000
#define SURF_FLAG_FALL_BOUNDARY_SHORT 0x2000
#define SURF_FLAG_MOVING_ROAD 	      0x8000
#define SURF_FLAG_HALFPIPE_END 	      0x10000

class KartCollide : public IKartCollide, public KartObjectProxy {
public:
  KartCollide();
  virtual void processBody(KartCollisionInfo& kartColInfo, const Hitbox& hitbox, const Field::ColInfo& colInfo, u32* colTypeMask) override;
  virtual void processWheels(KartCollisionInfo& kartColInfo, const Hitbox& hitbox, const Field::ColInfo& colInfo, u32* colTypeMask) override;
  virtual ~KartCollide() {}
  //virtual void _unused();
  
  void init();
  void updateBbox();
  void processMovingWater(KartCollisionInfo& kartColInfo, u32* colTypeMask) NEVER_INLINE;
  void processFloor(KartCollisionInfo& kartColInfo, const Hitbox& hitbox, const Field::ColInfo& colInfo, u32* colTypeMask, bool isWheel);
  void checkNeighborhood(KartCollisionInfo& kartColInfo, const Hitbox& hitbox, const Field::ColInfo& colInfo);
  void updateHitboxes();
  bool processWall(KartCollisionInfo& kartColInfo, const Field::ColInfo& colInfo, u32* colTypeMask);
  void processCannon(u32* kclTypeMask);
  void applySomeFloorMoment(KartDynamics* kartDynamics, HitboxGroup* hitboxGroup,
		  const EGG::Vector3f& forward, const EGG::Vector3f& dir, const EGG::Vector3f& speed,
		  f32 rateForward, f32 rateLateral, bool zeroUp, bool zeroPlane, bool affectAngVel);
  void calcWheelCollision(s8 playerIdx, u32 wheelIdx, KartDynamics* kartDynamics, HitboxGroup* hitboxGroup, const EGG::Vector3f& colForce,
		  const EGG::Vector3f& wheelPos, f32 radius);

  const EGG::Vector3f& getMovement() const { return movement; }
  f32 get1c() const { return _1c; }

private:
  KartCollideArea* kartCollideArea;
  f32 boundingRadius;
  /// Collision between two players can't occur more often than every 10 frames, counted by this timer
  s16 playerBumpTimer;
  f32 _1c;
  EGG::Vector3f _20;
  /// Surface effects are determined by this flag
  u32 surfaceFlags;
  EGG::Vector3f tangentOff;
  EGG::Vector3f movement;
  s16 respawnTimer;
  /// Counts 3 frames of consecutive allowed collision with solid OOB
  s16 solidOobTimer;
  s16 someLightningTimer;
  f32 _50;
  f32 suspBottomHeightSoftWall;
  s16 someSoftWallTimer;
  f32 suspBottomHeightNonSoftWall;
  s16 someNonSoftWallTimer;
  s16 someAngVel3FrameTimer;
  f32 someYawAngVel;
  f32 _68;
  s16 oobAreaIdx;
  f32 _70;
};
}
