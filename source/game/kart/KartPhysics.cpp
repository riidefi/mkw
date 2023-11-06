#include "KartPhysics.hpp"

#include <float.h>

// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern function references.
// PAL: 0x80229dcc
extern UNKNOWN_FUNCTION(__nw__FUl);
// PAL: 0x8022fac4
extern UNKNOWN_FUNCTION(makeIdentity__Q23EGG9Matrix34fFv);
// PAL: 0x80230118
extern UNKNOWN_FUNCTION(makeSQT__Q23EGG9Matrix34fFRCQ23EGG8Vector3fRCQ23EGG5QuatfRCQ23EGG8Vector3f);
// PAL: 0x80239dfc
extern UNKNOWN_FUNCTION(set__Q23EGG5QuatfFffff);
// PAL: 0x8023a5c4
extern UNKNOWN_FUNCTION(slerpTo__Q23EGG5QuatfCFRCQ23EGG5QuatffRQ23EGG5Quatf);
// PAL: 0x80243adc
extern UNKNOWN_FUNCTION(normalise__Q23EGG8Vector3fFv);
// PAL: 0x8059f5bc
extern UNKNOWN_FUNCTION(__ct__Q24Kart11KartPhysicsFb);
// PAL: 0x8059f6b8
extern UNKNOWN_FUNCTION(__dt__Q24Kart12KartDynamicsFv);
// PAL: 0x8059f6f8
extern UNKNOWN_FUNCTION(__dt__Q24Kart11KartPhysicsFv);
// PAL: 0x805b4af8
extern UNKNOWN_FUNCTION(__ct__Q24Kart16KartDynamicsKartFv);
// PAL: 0x805b4dc0
extern UNKNOWN_FUNCTION(init__Q24Kart12KartDynamicsFv);
// PAL: 0x805b4dc4
extern UNKNOWN_FUNCTION(setBspParams__Q24Kart12KartDynamicsFRCQ23EGG8Vector3fRCQ23EGG8Vector3fbf);
// PAL: 0x805b5170
extern UNKNOWN_FUNCTION(calc__Q24kart12KartDynamicsFffi);
// PAL: 0x805b5b64
extern UNKNOWN_FUNCTION(forceUpright__Q24Kart12KartDynamicsFv);
// PAL: 0x805b5b68
extern UNKNOWN_FUNCTION(stabilize__Q24Kart12KartDynamicsFv);
// PAL: 0x805b5ce8
extern UNKNOWN_FUNCTION(applyWrenchScaled__Q24kart12KartDynamicsFRCQ23EGG8Vector3fRCQ23EGG8Vector3ff);
// PAL: 0x805b6388
extern UNKNOWN_FUNCTION(addForce__Q24Kart12KartDynamicsFRCQ23EGG8Vector3f);
// PAL: 0x805b82bc
extern UNKNOWN_FUNCTION(__ct__Q24Kart11HitboxGroupFv);
// PAL: 0x805b8330
extern UNKNOWN_FUNCTION(reset__Q24Kart11HitboxGroupFv);
// PAL: 0x805b84c0
extern UNKNOWN_FUNCTION(initHitboxes__Q24Kart11HitboxGroupFPQ24Kart9BspHitboxPvl);// Extern data references.
// PAL: 0x802a4130
//extern UNKNOWN_DATA(RKSystem_ey);
// PAL: 0x808b7300
extern UNKNOWN_DATA(__vt__Q24Kart16KartDynamicsBike);
}

// --- EXTERN DECLARATIONS END ---

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

// Symbol: unk_8059f788
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
}

// Symbol: unk_8059fc48
// PAL: 0x8059fc48..0x8059fd0c
MARK_BINARY_BLOB(unk_8059fc48, 0x8059fc48, 0x8059fd0c);
asm UNKNOWN_FUNCTION(unk_8059fc48) {
  #include "asm/8059fc48.s"
}

// Symbol: unk_8059fd0c
// PAL: 0x8059fd0c..0x8059fdd0
MARK_BINARY_BLOB(unk_8059fd0c, 0x8059fd0c, 0x8059fdd0);
asm UNKNOWN_FUNCTION(unk_8059fd0c) {
  #include "asm/8059fd0c.s"
}

// Symbol: unk_8059fdd0
// PAL: 0x8059fdd0..0x8059fe94
MARK_BINARY_BLOB(unk_8059fdd0, 0x8059fdd0, 0x8059fe94);
asm UNKNOWN_FUNCTION(unk_8059fdd0) {
  #include "asm/8059fdd0.s"
}

// Symbol: unk_8059fe94
// PAL: 0x8059fe94..0x8059ff58
MARK_BINARY_BLOB(unk_8059fe94, 0x8059fe94, 0x8059ff58);
asm UNKNOWN_FUNCTION(unk_8059fe94) {
  #include "asm/8059fe94.s"
}

// Symbol: unk_8059ff58
// PAL: 0x8059ff58..0x805a0050
MARK_BINARY_BLOB(unk_8059ff58, 0x8059ff58, 0x805a0050);
asm UNKNOWN_FUNCTION(unk_8059ff58) {
  #include "asm/8059ff58.s"
}

// Symbol: unk_805a0050
// PAL: 0x805a0050..0x805a00d0
MARK_BINARY_BLOB(unk_805a0050, 0x805a0050, 0x805a00d0);
asm UNKNOWN_FUNCTION(unk_805a0050) {
  #include "asm/805a0050.s"
}

// Symbol: unk_805a00d0
// PAL: 0x805a00d0..0x805a014c
MARK_BINARY_BLOB(unk_805a00d0, 0x805a00d0, 0x805a014c);
asm UNKNOWN_FUNCTION(unk_805a00d0) {
  #include "asm/805a00d0.s"
}

// Symbol: unk_805a014c
// PAL: 0x805a014c..0x805a01cc
MARK_BINARY_BLOB(unk_805a014c, 0x805a014c, 0x805a01cc);
asm UNKNOWN_FUNCTION(unk_805a014c) {
  #include "asm/805a014c.s"
}

namespace Kart {
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
