
#include "KartDynamics.hpp"

#include <math.h>
#include <float.h>

namespace Kart {
KartDynamicsKart::KartDynamicsKart() {
  0.0f; // to make 0.0f appear before 1.0f in rodata
  this->angVel0Factor = 1.0f;
  this->inertiaTensor.makeIdentity();
  this->invInertiaTensor.makeIdentity();
  this->setDefault();
}

extern "C" EGG::Vector3f RKSystem_ey; // 0x802a4130
void KartDynamics::setDefault() {
  this->pos.setZero();
  this->externalVel.setZero();
  this->acceleration.setZero();
  this->externalVelBody.setZero();
  this->_98.setZero();
  this->angVel0.setZero();
  this->movingRoadVel.setZero();
  this->angVel1.setZero();
  this->movingWaterVel.setZero();
  this->speed.setZero();
  this->speedNorm = 0.0f;
  this->angVel2.setZero();
  this->mainRot.setIdentity();
  this->fullRot.setIdentity();
  this->totalForce.setZero();
  this->totalTorque.setZero();
  this->specialRot.setIdentity();
  this->extraRot.setIdentity();
  this->gravity = -1.0f;
  this->internalVel.setZero();

  this->up.setUp();
  this->_forceUpright = true;
  this->noGravity = false;
  this->isHit = false;
  this->force0xVelY = false;
  this->inBullet = false;
  this->stabilizationFactor = 0.1f;
  this->upInterpolated = RKSystem_ey;
  this->speedFix = 0.0f;
  this->_18c.setZero();
  this->_198.setZero();
  this->angVel0YFactor = 0.0f;
  this->scale.x = 1.0f;
  this->scale.y = 1.0f;
  this->scale.z = 1.0f;
}

void KartDynamics::reset() {
  this->externalVel.setZero();
  this->acceleration.setZero();
  this->externalVelBody.setZero();
  this->_98.setZero();
  this->angVel0.setZero();
  this->movingRoadVel.setZero();
  this->angVel1.setZero();
  this->movingWaterVel.setZero();
  this->angVel2.setZero();
  this->totalForce.setZero();
  this->totalTorque.setZero();
  this->internalVel.setZero();
}

void KartDynamics::init() {
  this->setDefault();
}

void KartDynamics::setBspParams(const EGG::Vector3f& m, const EGG::Vector3f& n, bool skipInertia, float angVel0Factor) {
  this->angVel0Factor = angVel0Factor;
  if (skipInertia) {
    return;
  }
  this->setInertia(m, n);
}

void KartDynamics::setInertia(const EGG::Vector3f& m, const EGG::Vector3f& n) {
  this->inertiaTensor.makeZero();
  float den = 1 / 12.0f;
  float x = (m.y * m.y + m.z * m.z) * den;
  float y = (m.z * m.z + m.x * m.x) * den;
  float z = (m.x * m.x + m.y * m.y) * den;
  this->inertiaTensor(0,0) = x + (n.y * n.y + n.z * n.z);
  this->inertiaTensor(1,1) = y + (n.z * n.z + n.x * n.x);
  this->inertiaTensor(2,2) = z + (n.x * n.x + n.y * n.y);
  this->updateInertiaTensorInverse();
}

void KartDynamics::updateInertiaTensorInverse() {
  this->inertiaTensor.inverseToC(this->invInertiaTensor);
}

MARK_FLOW_CHECK(0x805b50f8);
void KartDynamics::composeQuat(EGG::Quatf& dst, const EGG::Quatf& q1, const EGG::Vector3f& v) {
  EGG::Quatf::quatMul(dst, q1, v);
}

inline void clamp(float& x, float min, float max) {
  if (x >= min) {
    if (x > max) {
       x = max;
    }
  } else {
    x = min;
  }
}

void KartDynamics::calc(float dt, float maxSpeed, int air) {
  if (this->noGravity) {
    this->totalForce.y += this->gravity;
  }
  this->acceleration = totalForce;

  this->externalVel += this->acceleration * dt;
  if (isHit && speedNorm > 0.0f) {
    this->externalVel.y = 0.0f;
  }
  if (force0xVelY) {
    this->externalVel.y = 0.0f;
  }

  this->externalVel *= 0.998f;
  this->angVel0 *= 0.98f;

  // inline weirdness probably
  EGG::Vector3f kartBack2 = EGG::Vector3f::ez;
  EGG::Vector3f kartBack;
  kartBack.fromRotated(this->mainRot, kartBack2);
  kartBack2 = kartBack;

  EGG::Vector3f kartBackHorizontal = kartBack;
  kartBackHorizontal.y = 0.0f;
  if (kartBackHorizontal.squaredLength() > FLT_EPSILON) {
    kartBackHorizontal.normalise();
    EGG::Vector3f speedBack;
    EGG::Vector3f::projAndRej(speedBack, this->externalVel, this->externalVel, kartBackHorizontal);
    float speedNorm = speedBack.squaredLength();
    if (speedNorm > FLT_EPSILON) {
      speedNorm = sqrt(speedNorm);
    } else {
      speedNorm = 0.0f;
    }

    this->speedFix = speedNorm * EGG::Vector3f::dot(kartBack2, kartBackHorizontal);

    if (EGG::Vector3f::dot(speedBack, kartBackHorizontal)) {
      this->speedFix = -this->speedFix;
    }
  }

  if (air && this->internalVel.y > 120.0f) {
    this->internalVel.y = 120.0f;
  }
  this->speed = externalVel * dt + internalVel + movingRoadVel + movingWaterVel;
  this->speedNorm = speed.normalise();
  if (this->scale.z < 1.0f) {
    maxSpeed *= this->scale.z;
  }
  if (this->speedNorm > maxSpeed) {
    this->speedNorm = maxSpeed;
  }
  this->pos += this->speed;

  // wtf
  EGG::Vector3f t1 = (invInertiaTensor * totalTorque) * dt;
  this->angVel0 += (t1 + invInertiaTensor * (t1 + totalTorque) * dt) * 0.5f;

  if (_forceUpright) {
    this->forceUpright();
  }
  clamp(this->angVel0.x, -0.4f, 0.4f);
  clamp(this->angVel0.y, -0.4f, 0.4f);
  clamp(this->angVel0.z, -0.8f, 0.8f);

  this->angVel0.y *= this->angVel0YFactor;
  EGG::Vector3f angVel = angVel2 + angVel1 + angVel0 * this->angVel0Factor;
  if (angVel.squaredLength() > FLT_EPSILON) {
    // https://stackoverflow.com/questions/46908345/integrate-angular-velocity-as-quaternion-rotation
    EGG::Quatf drot;
    EGG::Quatf::quatMul(drot, this->mainRot, angVel);
    this->mainRot += drot * dt * 0.5f;

    // inlined together with same logic below probs
    if (__fabs(mainRot.squareNorm()) <= FLT_EPSILON) {
      this->mainRot.setIdentity();
    } else {
      this->mainRot.normalise();
    }
  }

  if (_forceUpright) {
    this->stabilize();
  }
  if (__fabs(mainRot.squareNorm()) <= FLT_EPSILON) {
    this->mainRot.setIdentity();
  } else {
    this->mainRot.normalise();
  }

  EGG::Quatf::quatMul(this->fullRot, this->mainRot, this->extraRot);
  EGG::Quatf::quatMul(this->fullRot, this->fullRot, this->specialRot);
  this->fullRot.normalise();
  this->mainRot.rotateVectorInv(externalVel, externalVelBody);
  this->totalForce.setZero();
  this->totalTorque.setZero();
  this->angVel2.setZero();
}

void KartDynamics::forceUpright() {
}

// https://decomp.me/scratch/d96Z7, can be proven with stack analysis
void KartDynamics::applyWrenchScaled(const EGG::Vector3f& r, const EGG::Vector3f& F, float bumpDeviation) {
  volatile EGG::Vector3f unused = r;
  this->totalForce += F;
  EGG::Vector3f fBody;
  this->fullRot.rotateVectorInv(F, fBody);
  EGG::Vector3f dr = r - this->pos;
  EGG::Vector3f rBody;
  this->fullRot.rotateVectorInv(dr, rBody);
  EGG::Vector3f torque = EGG::Vector3f::cross(rBody, fBody);
  torque.x *= bumpDeviation;
  torque.y *= bumpDeviation;
  torque.z *= bumpDeviation;
  this->addTorque(torque);
}

// Stack issues. Can be proven with checkflow with better stack analysis
MARK_FLOW_CHECK(0x805b5e40);
void KartDynamics::applyTorqueWorld(const EGG::Vector3f& r, const EGG::Vector3f& F) {
  volatile EGG::Vector3f unused = r;
  EGG::Vector3f fBodyFrame;
  this->fullRot.rotateVectorInv(F, fBodyFrame);

  EGG::Vector3f dr = r - this->pos;
  EGG::Vector3f drBodyFrame;
  this->fullRot.rotateVectorInv(dr, drBodyFrame);

  EGG::Vector3f torque = EGG::Vector3f::cross(drBodyFrame, fBodyFrame);
  torque.y = 0.0f;
  this->totalTorque += torque;
}

void KartDynamics::addTorque(const EGG::Vector3f& t) {
  totalTorque += t;
}

// https://decomp.me/scratch/B1p1o
MARK_FLOW_CHECK(0x805b6150);
void KartDynamics::applySuspensionWrench(const EGG::Vector3f& p, const EGG::Vector3f& Flinear, const EGG::Vector3f& Frot, bool ignoreX) {
  volatile EGG::Vector3f unused = p;
  this->totalForce.y += Flinear.y;
  EGG::Vector3f fBody;
  this->fullRot.rotateVectorInv(Frot, fBody);
  EGG::Vector3f r = p - this->pos;
  EGG::Vector3f rBody;
  this->fullRot.rotateVectorInv(r, rBody);
  EGG::Vector3f torque = EGG::Vector3f::cross(rBody, fBody);
  if (ignoreX) {
    torque.x = 0.0f;
  }
  torque.y = 0.0f;
  this->addTorque(torque);
}

void KartDynamics::applyWrench(const EGG::Vector3f& r, const EGG::Vector3f& F) {
  EGG::Vector3f fWorldFrame;
  this->fullRot.rotateVector(F, fWorldFrame);
  this->addForce(fWorldFrame);
  this->addTorque(EGG::Vector3f::cross(r, F));
}

void KartDynamics::addForce(const EGG::Vector3f& f) {
  totalForce += f;
}

void KartDynamics::getAngAcc(EGG::Vector3f& out, const EGG::Vector3f& v) {
  const EGG::Matrix34f& M = this->invInertiaTensor;
  float outZ = (M.mtx[2][0] * v.x) + (M.mtx[2][1] * v.y) + (M.mtx[2][2] * v.z);
  float outY = (M.mtx[1][0] * v.x) + (M.mtx[1][1] * v.y) + (M.mtx[1][2] * v.z);
  float outX = (M.mtx[0][0] * v.x) + (M.mtx[0][1] * v.y) + (M.mtx[0][2] * v.z);
  out.z = outZ;
  out.y = outY;
  out.x = outX;
}

// wants 0.0f rodata defined
// most likely inline
void KartDynamicsBike::forceUpright() {
  this->angVel0.z = 0.0;
}
}
