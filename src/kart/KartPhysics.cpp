#include "KartPhysics.hpp"

#include <float.h>

extern "C" EGG::Vector3f RKSystem_ey;

namespace Kart {
KartPhysics::KartPhysics(bool isBike) {
  this->pose.makeIdentity();
  KartDynamics* dynamics;
  if (!isBike) {
    dynamics = new KartDynamicsKart();
  } else {
    dynamics = new KartDynamicsBike();
  }
  this->mpDynamics = dynamics;
  this->mpHitboxGroup = new HitboxGroup();
  this->_fc = 50.0f;
}

KartPhysics::~KartPhysics() {
  delete mpDynamics;
  delete mpHitboxGroup;
}

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

void KartPhysics::reset() {
  this->mpDynamics->init();
  this->mpHitboxGroup->reset();
  this->up = RKSystem_ey;
  this->decayingSpecialRot.setIdentity();
  this->instantaneousSpecialRot.setIdentity();
  this->specialRot.setIdentity();
  this->decayingExtraRot.setIdentity();
  this->instantaneousExtraRot.setIdentity();
  this->extraRot.setIdentity();
  this->movingRoadVel.setZero();
  this->movingWaterVel.setZero();
  this->pose.makeIdentity();

  UPDATE_AXES_INLINE

  this->pos = mpDynamics->pos;
  this->speed = mpDynamics->speed;
}

void KartPhysics::calc(f32 dt, f32 maxSpeed, const EGG::Vector3f& scale, u32 airtime) {
  EGG::Quatf::quatMul(this->specialRot, this->instantaneousSpecialRot, this->decayingSpecialRot);
  EGG::Quatf::quatMul(this->extraRot, this->instantaneousExtraRot, this->decayingExtraRot);
  this->mpDynamics->specialRot = this->specialRot;
  this->mpDynamics->extraRot = this->extraRot;
  this->mpDynamics->scale = scale;
  this->mpDynamics->calc(dt, maxSpeed, airtime);
  EGG::Quatf unit;
  unit.setIdentity();
  this->decayingSpecialRot.slerpTo(unit, 0.1f, this->decayingSpecialRot);
  this->decayingExtraRot.slerpTo(unit, 0.1f, this->decayingExtraRot);
  this->instantaneousSpecialRot.setIdentity();
  this->instantaneousExtraRot.setIdentity();
}

void KartPhysics::updateDynamicsSpecialRot(const EGG::Quatf& rot) {
  this->mpDynamics->specialRot = rot;
}

void KartPhysics::addForce(const EGG::Vector3f& f) {
  this->mpDynamics->addForce(f);
}

void KartPhysics::applyWrench(const EGG::Vector3f& r, const EGG::Vector3f& f) {
  this->mpDynamics->applyWrenchScaled(r, f, 1.0f);
}

void KartPhysics::addInstantaneousSpecialRot(const EGG::Quatf& q) {
  EGG::Quatf::quatMul(this->instantaneousSpecialRot, this->instantaneousSpecialRot, q);
}

void KartPhysics::addInstantaneousExtraRot(const EGG::Quatf& q) {
  EGG::Quatf::quatMul(this->instantaneousExtraRot, this->instantaneousExtraRot, q);
}

void KartPhysics::addDecayingSpecialRot(const EGG::Quatf& q) {
  EGG::Quatf::quatMul(this->decayingSpecialRot, this->decayingSpecialRot, q);
}

void KartPhysics::addDecayingExtraRot(const EGG::Quatf& q) {
  EGG::Quatf::quatMul(this->decayingExtraRot, this->decayingExtraRot, q);
}

void KartPhysics::addMainRot(const EGG::Quatf& q) {
  EGG::Quatf res;
  // not quite rotation composition nintendo... no wonder this func is unused
  EGG::Quatf::quatMul(res, q, this->mpDynamics->mainRot);
  this->mpDynamics->mainRot = res;
}

void KartPhysics::decayMovingRoadVel(f32 normalRate, f32 airRate, bool touchingGround) {
  this->movingRoadVel.x *= touchingGround ? normalRate : airRate;
  this->movingRoadVel.y *= touchingGround ? normalRate : airRate;
  this->movingRoadVel.z *= touchingGround ? normalRate : airRate;

  this->mpDynamics->movingRoadVel = this->movingRoadVel;
}

void KartPhysics::shiftDecayMovingWaterVel(const EGG::Vector3f& amount, f32 rate) {
  this->movingWaterVel += amount;

  if (!this->movingWaterVel.isSmall()) {
    f32 norm = this->movingWaterVel.normalise();
    if (rate < norm) {
      norm = rate;
    }

    this->movingWaterVel *= norm;
    this->mpDynamics->movingWaterVel = this->movingWaterVel;
  }

}

void KartPhysics::decayMovingWaterVel(f32 normalRate, f32 airRate, bool touchingGround) {
  this->movingWaterVel.x *= touchingGround ? normalRate : airRate;
  this->movingWaterVel.y *= touchingGround ? normalRate : airRate;
  this->movingWaterVel.z *= touchingGround ? normalRate : airRate;
  this->movingWaterVel.y = 0.0f;

  this->mpDynamics->movingWaterVel = this->movingWaterVel;
}

void KartPhysics::updatePose() {
  this->pose.makeQT(mpDynamics->fullRot, mpDynamics->pos);
  UPDATE_AXES_INLINE
}

void KartPhysics::updateAxes() {
  UPDATE_AXES_INLINE
}

void KartPhysics::resetPendingOrientations() {
  this->decayingSpecialRot.setIdentity();
  this->decayingExtraRot.setIdentity();
}
}
