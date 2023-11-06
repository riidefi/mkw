#pragma once

#include <rk_types.h>

#include <decomp.h>

extern "C" {
// PAL: 0x8059f5bc..0x8059f678
UNKNOWN_FUNCTION(__ct__Q24Kart11KartPhysicsFb);
// PAL: 0x8059f6f8..0x8059f788
UNKNOWN_FUNCTION(__dt__Q24Kart11KartPhysicsFv);
// PAL: 0x8059f788..0x8059f7c8
UNKNOWN_FUNCTION(unk_8059f788);
// PAL: 0x8059f7c8..0x8059f968
UNKNOWN_FUNCTION(reset__Q24Kart11KartPhysicsFv);
// PAL: 0x8059f968..0x8059fc08
UNKNOWN_FUNCTION(calc__Q24Kart11KartPhysicsFffRCQ23EGG8Vector3fUl);
// PAL: 0x8059fc08..0x8059fc30
UNKNOWN_FUNCTION(updateDynamicsSpecialRot__Q24Kart11KartPhysicsFRCQ23EGG5Quatf);
// PAL: 0x8059fc30..0x8059fc38
UNKNOWN_FUNCTION(unk_8059fc30);
// PAL: 0x8059fc38..0x8059fc48
UNKNOWN_FUNCTION(unk_8059fc38);
// PAL: 0x8059fc48..0x8059fd0c
UNKNOWN_FUNCTION(unk_8059fc48);
// PAL: 0x8059fd0c..0x8059fdd0
UNKNOWN_FUNCTION(unk_8059fd0c);
// PAL: 0x8059fdd0..0x8059fe94
UNKNOWN_FUNCTION(unk_8059fdd0);
// PAL: 0x8059fe94..0x8059ff58
UNKNOWN_FUNCTION(unk_8059fe94);
// PAL: 0x8059ff58..0x805a0050
UNKNOWN_FUNCTION(unk_8059ff58);
// PAL: 0x805a0050..0x805a00d0
UNKNOWN_FUNCTION(unk_805a0050);
// PAL: 0x805a00d0..0x805a014c
UNKNOWN_FUNCTION(unk_805a00d0);
// PAL: 0x805a014c..0x805a01cc
UNKNOWN_FUNCTION(unk_805a014c);
// PAL: 0x805a01cc..0x805a02b8
UNKNOWN_FUNCTION(shiftDecayMovingWaterVel__Q24Kart11KartPhysicsFRCQ23EGG8Vector3ff);
// PAL: 0x805a02b8..0x805a0340
UNKNOWN_FUNCTION(decayMovingWaterVel__Q24Kart11KartPhysicsFffb);
// PAL: 0x805a0340..0x805a03c4
UNKNOWN_FUNCTION(PlayerPhysicsHolder_updateMat);
// PAL: 0x805a03c4..0x805a0410
UNKNOWN_FUNCTION(updateAxes__Q24Kart11KartPhysicsFv);
// PAL: 0x805a0410..0x805a0480
UNKNOWN_FUNCTION(resetPendingOrientations__Q24Kart11KartPhysicsFv);
// PAL: 0x805a0480..0x805a04a0
UNKNOWN_FUNCTION(destroyPhysicsInstance__4KartFf);
// PAL: 0x805a04a0..0x805a0550
UNKNOWN_FUNCTION(createPhysicsInstance__4KartFbRCQ24Kart9KartParamPvl);
}

#include <egg/math/eggVector.hpp>
#include <egg/math/eggQuat.hpp>
#include <egg/math/eggMatrix.hpp>

#include "KartHitbox.hpp"
#include "KartDynamics.hpp"

namespace Kart {
class KartPhysics {
public:
  virtual ~KartPhysics();

  KartPhysics(bool isBike);

  void reset();
  void calc(f32 dt, f32 maxSpeed, const EGG::Vector3f& scale, u32 airtime);
  void updateDynamicsSpecialRot(const EGG::Quatf& rot);
  void addForce(const EGG::Vector3f& f);
  void applyWrench(const EGG::Vector3f& r, const EGG::Vector3f& f);
  void shiftDecayMovingWaterVel(const EGG::Vector3f& amount, f32 rate);
  void decayMovingWaterVel(f32 airRate, f32 normalRate, bool touchingGround);
  void updatePose();
  void updateAxes();
  // Zeros decaying rotations (e.g. to cancel trick or itemhit rotation when entering cannon)
  void resetPendingOrientations();
  #define UPDATE_AXES_INLINE {\
    float _00 = this->pose(0, 0); \
    float _10 = this->pose(1, 0); \
    float _20 = this->pose(2, 0); \
    float _01 = this->pose(0, 1); \
    float _11 = this->pose(1, 1); \
    float _21 = this->pose(2, 1); \
    float _02 = this->pose(0, 2); \
    float _12 = this->pose(1, 2); \
    float _22 = this->pose(2, 2); \
    this->xAxis.x = _00; \
    this->xAxis.y = _10; \
    this->xAxis.z = _20; \
    this->yAxis.x = _01; \
    this->yAxis.y = _11; \
    this->yAxis.z = _21; \
    this->zAxis.x = _02; \
    this->zAxis.y = _12; \
    this->zAxis.z = _22; \
  }

public:
  KartDynamics* mpDynamics;
  HitboxGroup* mpHitboxGroup;

  EGG::Vector3f up;
  EGG::Vector3f pos;
  // rotation from stunts
  // instantaneous is the extra rot of the current trick.
  // Decaying is used when a trick is ended early (low trick) to smoothly decay the rotation back to normal
  EGG::Quatf decayingSpecialRot;
  EGG::Quatf instantaneousSpecialRot;
  EGG::Quatf specialRot;
  // rotation from e.g. item interactions
  EGG::Quatf decayingExtraRot;
  EGG::Quatf instantaneousExtraRot;
  EGG::Quatf extraRot;

  EGG::Vector3f movingRoadVel;
  EGG::Vector3f movingWaterVel;
  // the following 4 poses/orientation fields do not include wheelieing
  // vehicle pose
  EGG::Matrix34f pose;
  // vehicle orientation axes
  EGG::Vector3f xAxis;
  EGG::Vector3f yAxis;
  EGG::Vector3f zAxis;

  EGG::Vector3f speed;
  f32 _fc;
};
static_assert(sizeof(KartPhysics) == 0x100);
}
