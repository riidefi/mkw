#include "KartPhysics.hpp"

#include <float.h>

extern "C" {
// Extern function references.
// PAL: 0x8059f6b8
extern UNKNOWN_FUNCTION(__dt__Q24Kart12KartDynamicsFv);
// PAL: 0x8059f6f8
extern UNKNOWN_FUNCTION(__dt__Q24Kart11KartPhysicsFv);
// PAL: 0x805b5b64
extern UNKNOWN_FUNCTION(forceUpright__Q24Kart12KartDynamicsFv);
// PAL: 0x805b5b68
extern UNKNOWN_FUNCTION(stabilize__Q24Kart12KartDynamicsFv);
}

// .data
#pragma explicit_zero_data on
// How to match all KartPhysics and KartDynamics vtables (two more in KartDynamics.cpp)
// 1) match KartDynamics::calc, stabilize and forceUpright
// 2) place stabilize and forceUpright inline in KartDynamics.hpp
// 3) Remove WIP decomp that implements KartPhysic's dtor
// 4) Remove the dummy vtable definitions (don't forget the ones in KartDynamics.cpp)
// 5) Watch how all vtables are put in place perfectly
u32 __vt__Q24Kart11KartPhysics[] = {
    0x00000000, 0x00000000, (u32)&__dt__Q24Kart11KartPhysicsFv
};
extern u32 __vt__Q24Kart12KartDynamics[];
u32 __vt__Q24Kart12KartDynamics[] = {
    0x00000000,
    0x00000000, (u32)&__dt__Q24Kart12KartDynamicsFv, (u32)&stabilize__Q24Kart12KartDynamicsFv, (u32)&forceUpright__Q24Kart12KartDynamicsFv
};
#pragma explicit_zero_data off

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
}

#ifndef WIP_DECOMP
// see "How to match all KartPhysics and KartDynamics vtables" above
// Symbol: __dt__Q24Kart11KartPhysicsFv
// PAL: 0x8059f6f8..0x8059f788
MARK_BINARY_BLOB(__dt__Q24Kart11KartPhysicsFv, 0x8059f6f8, 0x8059f788);
asm UNKNOWN_FUNCTION(__dt__Q24Kart11KartPhysicsFv) {
  #include "asm/8059f6f8.s"
}
#else
namespace Kart
void KartPhysics::~KartPhysics() {
  delete mpDynamics;
  delete mpHitboxGroup;
}
}
#endif

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

// Symbol: unk_8059f788__Fv__Fv
// PAL: 0x8059f788..0x8059f7c8
MARK_BINARY_BLOB(unk_8059f788, 0x8059f788, 0x8059f7c8);
asm UNKNOWN_FUNCTION(unk_8059f788) {
  #include "asm/8059f788.s"
}

extern "C" EGG::Vector3f RKSystem_ey;
namespace Kart {
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

// Symbol: setMovingRoadVel__Q24Kart11KartPhysicsFRCQ23EGG8Vector3ff
// PAL: 0x805a0050..0x805a00d0
MARK_BINARY_BLOB(setMovingRoadVel__Q24Kart11KartPhysicsFRCQ23EGG8Vector3ff, 0x805a0050, 0x805a00d0);
asm void KartPhysics::setMovingRoadVel(const EGG::Vector3f& vel, f32 rate) {
  #include "asm/805a0050.s"
}

void KartPhysics::decayMovingRoadVel(f32 normalRate, f32 airRate, bool touchingGround) {
  this->movingRoadVel.x *= touchingGround ? normalRate : airRate;
  this->movingRoadVel.y *= touchingGround ? normalRate : airRate;
  this->movingRoadVel.z *= touchingGround ? normalRate : airRate;

  this->mpDynamics->movingRoadVel = this->movingRoadVel;
}

// Symbol: setMovingWaterVel__Q24Kart11KartPhysicsFRCQ23EGG8Vector3ff
// PAL: 0x805a014c..0x805a01cc
MARK_BINARY_BLOB(setMovingWaterVel__Q24Kart11KartPhysicsFRCQ23EGG8Vector3ff, 0x805a014c, 0x805a01cc);
asm void KartPhysics::setMovingWaterVel(const EGG::Vector3f& vel, f32 rate) {
  #include "asm/805a014c.s"
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
