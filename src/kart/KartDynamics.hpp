#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x805b5170..0x805b5b64
UNKNOWN_FUNCTION(calc__Q24kart12KartDynamicsFffi);
// PAL: 0x805b5ce8..0x805b5e40
UNKNOWN_FUNCTION(applyWrenchScaled__Q24kart12KartDynamicsFRCQ23EGG8Vector3fRCQ23EGG8Vector3ff);
// PAL: 0x805b6150..0x805b629c
UNKNOWN_FUNCTION(applySuspensionWrench__Q24Kart12KartDynamicsFRCQ23EGG8Vector3fRCQ23EGG8Vector3fRCQ23EGG8Vector3fb);
// PAL: 0x805b629c..0x805b6388
UNKNOWN_FUNCTION(lbl_805b4f44);
UNKNOWN_FUNCTION(applyTorqueWorld__Q24kart12KartDynamicsFRCQ23EGG8Vector3fRCQ23EGG8Vector3f);
UNKNOWN_FUNCTION(lbl_805b5f78);

#ifdef __cplusplus
}
#endif

#include "egg/math/eggMatrix.hpp"
#include "egg/math/eggVector.hpp"
#include "egg/math/eggQuat.hpp"

namespace Kart {

class KartDynamics {
public:
  virtual ~KartDynamics() {}
  virtual void stabilize();
  virtual void forceUpright();

  //KartDynamics();
  void setDefault();
  // clears state
  void reset();
  void init();
  // set inertia from cuboid with dimensions m (mass 1) and n (mass 12)
  void setBspParams(const EGG::Vector3f& m, const EGG::Vector3f& n, bool skipInertia, float angVel0Factor);
  void setInertia(const EGG::Vector3f& m, const EGG::Vector3f& n);
  void updateInertiaTensorInverse();
  void composeQuat(EGG::Quatf& dst, const EGG::Quatf& q1, const EGG::Vector3f& v);
  void calc(float dt, float maxSpeed, int air);
  void applyWrenchScaled(const EGG::Vector3f& r, const EGG::Vector3f& F, float bumpDeviation);
  void applyTorqueWorld(const EGG::Vector3f& r, const EGG::Vector3f& F);
  void addTorque(const EGG::Vector3f&);
  void addForce(const EGG::Vector3f&);
  void getAngAcc(EGG::Vector3f& out, const EGG::Vector3f& v);
  void applySuspensionWrench(const EGG::Vector3f& p, const EGG::Vector3f& Flinear, const EGG::Vector3f& Frot, bool ignoreX);
  void applyWrench(const EGG::Vector3f& r, const EGG::Vector3f& F);

  // inertia matrix
  EGG::Matrix34f inertiaTensor;
  EGG::Matrix34f invInertiaTensor;

  f32 angVel0Factor;
  // kart position
  EGG::Vector3f pos;
  // kart linear velocity due to dynamic interactions
  EGG::Vector3f externalVel;
  EGG::Vector3f acceleration;
  // external velocity in body frame (unused?)
  EGG::Vector3f externalVelBody;
  EGG::Vector3f _98;
  // kart angular velocity due to dynamic interactions
  EGG::Vector3f angVel0;
  EGG::Vector3f movingRoadVel;
  // kart angular velocity due to moving road?
  EGG::Vector3f angVel1;
  EGG::Vector3f movingWaterVel;
  // total vehicle speed (externalVel + internalVel + movingRoadVel + movingWaterVel)
  EGG::Vector3f speed;
  f32 speedNorm;
  EGG::Vector3f angVel2;
  // kart rotation with an without extra and special rot
  EGG::Quatf mainRot;
  EGG::Quatf fullRot;
  // forces acted on the vehicle ()
  EGG::Vector3f totalForce;
  EGG::Vector3f totalTorque;
  // rotation form stunts?
  EGG::Quatf specialRot;
  // rotation from object collision animations?
  EGG::Quatf extraRot;
  f32 gravity;
  // kart linear velocity due to engine power
  EGG::Vector3f internalVel;

  EGG::Vector3f up;
  u8 _168[0x170-0x164];
  bool _forceUpright;
  bool noGravity;
  // sets external velocity in the Y direction to 0 if going upwards. Used when hit by item or object
  bool isHit;
  // forces external velocity in the Y direction to 0. Never used?
  bool force0xVelY;
  bool inBullet;
  f32 stabilizationFactor;
  f32 speedFix;
  // used for stabilization
  EGG::Vector3f upInterpolated;
  EGG::Vector3f _18c;
  EGG::Vector3f _198;
  f32 angVel0YFactor;
  // model scale for some reason affects max speed limit
  // e.g. you can reach speeds higher than 120km/h in a mega
  EGG::Vector3f scale;
};

class KartDynamicsKart : public KartDynamics {
public:
  KartDynamicsKart();
  //virtual ~KartDynamicsKart() {}
};

class KartDynamicsBike : public KartDynamicsKart {
public:
  virtual ~KartDynamicsBike();
  virtual void stabilize() override;
  virtual void forceUpright() override;
};

} // ns
