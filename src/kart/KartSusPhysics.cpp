#include "KartSusPhysics.hpp"

namespace Kart {
    
KartSusPhysics::KartSusPhysics(u32 wheelIdx, KartWheelType wheelType, s32 bspWheelIdx) : KartObjectProxy() {
    this->wheelPhysics = nullptr;
    this->wheelType = wheelType;
    this->bspWheelIdx = bspWheelIdx;
    this->wheelIdx = wheelIdx;
    this->_38 = 1.0f;
  }
  
  void KartSusPhysics::reset() {
    this->_38 = 1.0f / this->bspWheel->maxTravel;
    this->suspTop.setZero();
    this->maxTravelScaled = 0.0f;
    this->hasFloorCol = false;
    this->_36 = 0;
    this->downDir.setZero();
  }
  
  void KartSusPhysics::init() {
    this->wheelPhysics = this->KartObjectProxy::kartWheel(this->wheelIdx)->getPhysics();
    this->bspWheel = this->KartObjectProxy::bspWheel(this->bspWheelIdx);
    this->reset();
  }
  
  void KartSusPhysics::setInitialState() {
    EGG::Vector3f suspTop;
  #ifdef __CWCC__
    __memcpy(&suspTop, &this->bspWheel->centerPos, sizeof(suspTop)); // why (assignment copy uses lfs/stfs)
  #else
    suspTop = this->bspWheel->centerPos;
  #endif
      
    EGG::Vector3f bottom(0.0f, -1.0f, 0.0f);
    if (wheelType == KART_WHEEL_KART_RIGHT) {
      suspTop.x = -suspTop.x;
    }
    EGG::Vector3f suspTopWorld;
    kartDynamics()->fullRot.rotateVector(suspTop, suspTopWorld);
    suspTopWorld += kartDynamics()->pos;
    EGG::Vector3f kartBottom;
    kartDynamics()->fullRot.rotateVector(bottom, kartBottom);
      
    f32 travel = this->bspWheel->maxTravel;
    EGG::Vector3f scaledBottom = travel * kartBottom;  
    EGG::Vector3f wheelPos;
    wheelPos.x = suspTopWorld.x + scaledBottom.x;
    wheelPos.y = suspTopWorld.y + scaledBottom.y;
    wheelPos.z = suspTopWorld.z + scaledBottom.z;
    wheelPhysics->wheelPos = wheelPos;
    wheelPhysics->prevWheelPos = wheelPos;
  
    KartWheelPhysics* physics = wheelPhysics;
    physics->prevWheelOffset.x = wheelPos.x - suspTopWorld.x;
    physics->prevWheelOffset.y = wheelPos.y - suspTopWorld.y;
    physics->prevWheelOffset.z = wheelPos.z - suspTopWorld.z;
  
    f32 scale = kartMove()->totalScale();
    f32 radius = wheelPhysics->effectiveRadius;
    f32 currentRadius = radius * scale;
  
    KartWheelPhysics* physics2 = wheelPhysics;
    physics2->wheelEdgePos.x = currentRadius * kartBottom.x + wheelPos.x;
    physics2->wheelEdgePos.y = currentRadius * kartBottom.y + wheelPos.y;
    physics2->wheelEdgePos.z = currentRadius * kartBottom.z + wheelPos.z;
  
    EGG::Vector3f& hitboxPos = wheelPhysics->getHitbox()->getHitbox(0).pos;
    Hitbox& wheelHitbox = wheelPhysics->getHitbox()->getHitbox(0);
    hitboxPos.x = wheelPos.x;
    hitboxPos.y = wheelPos.y;
    hitboxPos.z = wheelPos.z;
    EGG::Vector3f dynamicsPos = kartDynamics()->pos;
    dynamicsPos.y += wheelHitboxHeight;
    wheelHitbox.lastPos = dynamicsPos;
    this->suspTop = suspTopWorld;
  }
  
  void KartSusPhysics::calcCollision(const EGG::Vector3f& gravity, const EGG::Matrix34f& mtx, f32 dt) {
    this->maxTravelScaled = this->bspWheel->maxTravel * kartPhysicsEngine()->getYScale();
    const EGG::Vector3f& scale = getScale();
    EGG::Vector3f scaledRelPos;
    scaledRelPos.x = this->bspWheel->centerPos.x * scale.x;
    scaledRelPos.y = this->bspWheel->centerPos.y * scale.y;
    scaledRelPos.z = this->bspWheel->centerPos.z * scale.z;
  
    EGG::Vector3f bottom(0.0f, -1.0f, 0.0f);
    if (wheelType == KART_WHEEL_KART_RIGHT) {
      scaledRelPos.x = -scaledRelPos.x;
    }
    EGG::Vector3f suspTopWorld = mtx.multVector(scaledRelPos);
    EGG::Vector3f wheelPos;
    EGG::Vector3f rotEuler(DEG2RAD(this->bspWheel->xRot), 0.0f, 0.0f);
    EGG::Matrix34f_aligned8 rotMtx;
    rotMtx.makeR(rotEuler);
    bottom = rotMtx.multVector33(bottom);
    this->downDir = mtx.multVector33(bottom);
  
    this->wheelPhysics->setColState(dt, this->maxTravelScaled, gravity);
  
    EGG::Vector3f& down = this->downDir;
    f32 susTravel = this->wheelPhysics->getSusTravel();
    wheelPos.x = susTravel * down.x + suspTopWorld.x;
    wheelPos.y = susTravel * down.y + suspTopWorld.y;
    wheelPos.z = susTravel * down.z + suspTopWorld.z;
    this->wheelPhysics->setWheelPos(wheelPos);
  
    if (!kartState()->on(KART_FLAG_SKIP_WHEEL_CALC)) {
      this->wheelPhysics->calcCollision(down, suspTopWorld);
      this->suspTop = suspTopWorld;
    }
  }

  void KartSusPhysics::calc(const EGG::Vector3f& forward, const EGG::Vector3f& movement) {
    EGG::Vector3f prevWhlOff = this->wheelPhysics->prevWheelOffset;
    this->wheelPhysics->calc(this->downDir, movement);
  
    HitboxGroup* hitboxGroup = wheelPhysics->hitboxGroup;
    if ((hitboxGroup->getKartCollisionInfo().flags & COL_FLAG_FLOOR) != 0) {
      EGG::Vector3f travelVector = wheelPhysics->wheelPos - suspTop;
      f32 travel = EGG::Vector3f::dot(downDir, travelVector);
      if (travel < 0.0f) travel = 0.0f;
  
      EGG::Vector3f wheelMovement = prevWhlOff - travelVector;
      f32 suspMax = this->maxTravelScaled;
      f32 travelSpeed = EGG::Vector3f::dot(downDir, wheelMovement);
      if (_36 > 0 && kartPhysics()->speed.dot(hitboxGroup->getKartCollisionInfo().floorNrm) < -15.0f) {
        f32 targetSuspSpeed = 0.0f;
        if (maxTravelScaled > 0.0f) {
          f32 travelPerc = travel / maxTravelScaled;
      if (travelPerc > 0.0f) {
            targetSuspSpeed = travelPerc <= 1.0f ? travelPerc : 1.0f;
      }
      travelSpeed *= unk_suspSpeedRate + (1.0f - unk_suspSpeedRate) * targetSuspSpeed;
        }
  
      }
      _36--;
      if (_36 < 0) _36 = 0;
  
      EGG::Vector3f rawSuspForce;
      rawSuspForce.z = -bspWheel->springStiffness * (suspMax - travel) + bspWheel->dampingFactor * travelSpeed;
      rawSuspForce.x = downDir.x * rawSuspForce.z;
      rawSuspForce.y = downDir.y * rawSuspForce.z;
      rawSuspForce.z = downDir.z * rawSuspForce.z;
  
      bool isRespawning = inRespawn();
      if (isRespawning) {
        if (rawSuspForce.y < -respawnSuspLimit) {
          rawSuspForce.y = -respawnSuspLimit;
        } else if (rawSuspForce.y > respawnSuspLimit) {
          rawSuspForce.y = respawnSuspLimit;
        }
      }
  
      EGG::Vector3f suspForce = rawSuspForce;
      EGG::Vector3f suspForcePlanar = rawSuspForce;
      suspForcePlanar.y = 0.0f;
      RKGeom::projUnit(suspForcePlanar, suspForcePlanar, hitboxGroup->getKartCollisionInfo().floorNrm);
      suspForce.y += suspForcePlanar.y;
      if (suspForce.y > kartStats()->maxVerticalAcc) {
        suspForce.y = kartStats()->maxVerticalAcc;
      }
      if (kartDynamics()->externalVel.y > disableSuspForceVerticalXV) {
        suspForce.y = 0.0f;
      }
      if (kartState()->on(KART_FLAG_DISABLE_Y_SUS_FORCE)) {
        suspForce.y = 0.0f;
      }
      kartDynamics()->applySuspensionWrench(suspTop, suspForce, rawSuspForce, kartState()->on(KART_FLAG_WHEELIE_ROT));
      if (!kartState()->on(KART_FLAG_IN_A_BULLET)) {
        wheelPhysics->unk80599dc0(forward);
      }
    }
    hasFloorCol = (hitboxGroup->getKartCollisionInfo().flags & COL_FLAG_FLOOR) != 0;
  }
}
