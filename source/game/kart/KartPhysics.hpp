#pragma once

#include <rk_types.h>

#include <decomp.h>

#include <egg/math/eggVector.hpp>
#include <egg/math/eggQuat.hpp>
#include <egg/math/eggMatrix.hpp>

#include "KartHitbox.hpp"
#include "KartDynamics.hpp"

extern "C" UNKNOWN_FUNCTION(unk_8059f788);

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

  void addInstantaneousSpecialRot(const EGG::Quatf& q);
  void addInstantaneousExtraRot(const EGG::Quatf& q);
  void addDecayingSpecialRot(const EGG::Quatf& q);
  void addDecayingExtraRot(const EGG::Quatf& q);
  void addMainRot(const EGG::Quatf& q);

  void setMovingRoadVel(const EGG::Vector3f& vel, f32 rate);
  void decayMovingRoadVel(f32 airRate, f32 normalRate, bool touchingGround);
  void setMovingWaterVel(const EGG::Vector3f& vel, f32 rate);
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
