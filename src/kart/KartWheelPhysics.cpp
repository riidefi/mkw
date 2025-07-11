#include "KartWheelPhysics.hpp"

#include "KartWheel.hpp"

namespace Kart {
f32 rateForward = 0.1f;
f32 wheelColForceFactor = 10.0f;
f32 wheelHitboxHeight = 100.0f;
f32 forwardFactor = 0.3f;
f32 respawnSuspLimit = 1.0f;
f32 disableSuspForceVerticalXV = 5.0f;
f32 unk_suspSpeedRate = 0.3f;

KartWheelPhysics::KartWheelPhysics(u32 wheelIdx, s32 bspWheelIdx) : KartObjectProxy(), wheelIdx(wheelIdx), 
	bspWheelIdx(bspWheelIdx), bspWheel(nullptr) {

}

void KartWheelPhysics::init() {
  this->hitboxGroup = new HitboxGroup;
  EGG::Vector3f pos(0.0f, 0.0f, 0.0f);
  this->hitboxGroup->createSingleHitbox(pos, 10.0f);
}

void KartWheelPhysics::setBsp() {
  this->bspWheel = this->KartObjectProxy::bspWheel(this->bspWheelIdx);
}

void KartWheelPhysics::reset() {
  this->hitboxGroup->reset();
  this->wheelPos.setZero();
  this->prevWheelPos.setZero();
  this->prevWheelOffset.setZero();
  this->susTravel = 0.0f;
  this->colVel.setZero();
  this->speed.setZero();
  this->wheelEdgePos.setZero();
  this->effectiveRadius = 0.0f;
  this->targetEffectiveRadius = 0.0f;
  this->isAtSuspLimit = 0.0f;
  this->suspTop.setZero();
  if (this->bspWheel) {
    this->susTravel = bspWheel->maxTravel;
    this->effectiveRadius = bspWheel->wheelRadius;
  }
}

void KartWheelPhysics::setColState(f32 dt, f32 travel, const EGG::Vector3f& colForce) {
  f32 maxTravel = this->susTravel + kartPhysicsEngine()->getYScale() * 5.0f;
  this->susTravel = maxTravel;
  if (maxTravel > travel) {
    this->susTravel = travel;
  }
  if (this->susTravel < 0.0f) {
    this->susTravel = 0.0f;
  }
 
  f32 factor = dt * wheelColForceFactor;

  this->colVel.x = factor * colForce.x;
  this->colVel.y = factor * colForce.y;
  this->colVel.z = factor * colForce.z;
}

// https://decomp.me/scratch/VAgkF
void KartWheelPhysics::calcCollision(const EGG::Vector3f& downDir, const EGG::Vector3f& suspTop) {
  KartDynamics* kartDyn = kartDynamics();
  HitboxGroup* hitboxGroup = getHitbox();
  Hitbox& wheelHitbox = hitboxGroup->getHitbox(0);
  if (!kartState()->on(KART_FLAG_SKIP_WHEEL_CALC) && !kartState()->on(KART_FLAG_COL_INVISIBILITY) && !kartState()->on(KART_FLAG_STH_KILLER)) {
    f32 radius = bspWheel->wheelRadius;
    f32 effRadius = effectiveRadius;
    f32 totalScale = kartMove()->totalScale();
    const EGG::Vector3f& scale = getScale();
    f32 dist = effRadius * scale.y - radius * totalScale;
    EGG::Vector3f center;
    center.x = wheelPos.x + dist * downDir.x;
    center.y = wheelPos.y + dist * downDir.y;
    center.z = wheelPos.z + dist * downDir.z;

    EGG::Vector3f bodyForward;
    getBodyForward(bodyForward);
    f32 forwardDist = forwardFactor * radius * kartMove()->getLeanRot() * kartMove()->totalScale();
    center += forwardDist * bodyForward;

    if (!kartState()->on(KART_FLAG_HALFPIPE_MIDAIR) && !kartState()->on(KART_FLAG_IN_CANNON)) {
      hitboxGroup->setHitboxScale(kartMove()->totalScale());
      if (kartState()->on(KART_FLAG_STH_61)) {
        wheelHitbox.lastPos = getPos();
      }

      kartCollide()->calcWheelCollision(getPlayerIdx(), wheelIdx, kartDyn, getHitbox(), colVel, center, radius);

      if ((hitboxGroup->getKartCollisionInfo().flags & (COL_FLAG_FLOOR | COL_FLAG_WALL | COL_FLAG_WALL_3)) != 0) {
	wheelPos += hitboxGroup->getKartCollisionInfo().tangentOff;
	u32 sinkDepth = hitboxGroup->getKartCollisionInfo().sinkDepth;
	u32 sinkDepthAmount = sinkDepthFactor * sinkDepth;
	targetEffectiveRadius = bspWheel->wheelRadius - sinkDepthAmount;
	kartBody()->requireSinkDepth(sinkDepthAmount);
      }

    } else {
      hitboxGroup->getKartCollisionInfo().reset();
    }

    hitboxGroup->getHitbox(0).lastPos = center;
  }

  f32 scaledRadius = effectiveRadius * kartMove()->totalScale();
  this->suspTop = suspTop;
  wheelEdgePos = wheelPos + scaledRadius * downDir;
  f32 travel = EGG::Vector3f::dot(downDir, wheelPos - suspTop);
  updateEffectiveRadius();
  this->susTravel = travel;

  if (travel < 0.0f) {
    isAtSuspLimit = 1.0f;
    kartPhysicsEngine()->registerSuspLimits(travel * downDir);
    kartState()->set(KART_FLAG_AT_SUSP_LIMIT);
  } else {
    isAtSuspLimit = 0.0f;
  }
}

void KartWheelPhysics::calc(const EGG::Vector3f &down, const EGG::Vector3f &movement) {
  EGG::Vector3f topmost;
  topmost.x = suspTop.x + movement.x;
  topmost.y = suspTop.y + movement.y;
  topmost.z = suspTop.z + movement.z;

  EGG::Vector3f susTravelVector;
  susTravelVector.x = wheelPos.x - topmost.x;
  susTravelVector.y = wheelPos.y - topmost.y;
  susTravelVector.z = wheelPos.z - topmost.z;
  
  susTravel = down.dot(susTravelVector);
  if (susTravel > bspWheel->maxTravel * getYScale()) {
    susTravel = bspWheel->maxTravel * getYScale();
  }
  
  if (susTravel < 0.0f) {
    susTravel = 0.0f;
  }

  wheelPos.x = susTravel * down.x + topmost.x;
  wheelPos.y = susTravel * down.y + topmost.y;
  wheelPos.z = susTravel * down.z + topmost.z;

  EGG::Vector3f spd;
  spd.x = wheelPos.x - prevWheelPos.x;
  spd.y = wheelPos.y - prevWheelPos.y;
  spd.z = wheelPos.z - prevWheelPos.z;

  KartDynamics *pDynamics = kartDynamics();
  speed =  spd;
  speed -= pDynamics->internalVel;
  speed -= pDynamics->movingRoadVel;
  speed -= pDynamics->movingWaterVel;
  speed -= bodyColInfo()->movement;
  speed -= kartCollide()->getMovement();
  hitboxGroup->getKartCollisionInfo().vel += speed;
  prevWheelPos = wheelPos;
  prevWheelOffset.x = prevWheelPos.x - topmost.x;
  prevWheelOffset.y = prevWheelPos.y - topmost.y;
  prevWheelOffset.z = prevWheelPos.z - topmost.z;
}

void KartWheelPhysics::updateEffectiveRadius() {
  this->effectiveRadius += (targetEffectiveRadius - effectiveRadius) * 0.1f;
}

void KartWheelPhysics::unk80599dc0(const EGG::Vector3f& front) {
  f32 rateLateral;
  if (kartState()->on(KART_FLAG_STH_WALL_COL)) {
    rateLateral = 0.01f;
  } else {
    rateLateral = kartCollide()->get1c();
  }

  bool affectAngVel = kartState()->on(KART_FLAG_LARGE_FLIP_HIT) || kartState()->on(KART_FLAG_WHEELIE_ROT);
  kartCollide()->applySomeFloorMoment(kartDynamics(), this->hitboxGroup, front, kartMove()->dir(), this->speed,
		  rateForward, rateLateral, true, true, !affectAngVel);
}

bool KartWheelPhysics::hasFloorCollision() const {
  return (hitboxGroup->getKartCollisionInfo().flags & COL_FLAG_FLOOR) != 0;
}


const EGG::Vector3f& KartWheelPhysics::getCollisionFloorNrm() const {
  return this->getKartCollisionInfo().floorNrm;
}

const KartCollisionInfo& KartWheelPhysics::getKartCollisionInfo() const {
  return this->hitboxGroup->getKartCollisionInfo();
}


}

EGG::Vector3f EGG::Matrix34f::multVector33(const EGG::Vector3f& v) const {
  EGG::Vector3f ret;
  ret.z = mtx[2][0] * v.x + mtx[2][1] * v.y + mtx[2][2] * v.z;
  ret.y = mtx[1][0] * v.x + mtx[1][1] * v.y + mtx[1][2] * v.z;
  ret.x = mtx[0][0] * v.x + mtx[0][1] * v.y + mtx[0][2] * v.z;
  return ret;
}
