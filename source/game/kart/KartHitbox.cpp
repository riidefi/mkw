
#include "KartHitbox.hpp"

#include <math.h>
#include <rvl/mtx/mtx.h>

namespace Kart {
Hitbox::Hitbox() {
  this->bsp = nullptr;
  this->reset();
}

void Hitbox::reset() {
  this->_8 = 0;
  this->pos.setZero();
  this->lastPos.setZero();
  this->relPos.setZero();
}

MARK_FLOW_CHECK(0x805b7fbc);
void Hitbox::update(const EGG::Vector3f& scale, const EGG::Quatf& rot, const EGG::Vector3f& pos, f32 totalScale, f32 hitboxElevation) {
  f32 postScaleHitboxElevation = 0.0f;
  if (scale.y < totalScale) {
    float dist = totalScale - scale.y;
    postScaleHitboxElevation = (dist) * this->bsp->radius;
  }

  EGG::Vector3f scaledPos = this->bsp->pos;

  scaledPos.x *= scale.x;
  scaledPos.z *= scale.z;
  float sum = (scaledPos.y + hitboxElevation);
  float summult = sum * scale.y;
  scaledPos.y = (summult) + postScaleHitboxElevation;
  const_cast<EGG::Quatf&>(rot).rotateVector(scaledPos, this->relPos);
    
  this->pos.x = this->relPos.x + pos.x;
  this->pos.y = this->relPos.y + pos.y;
  this->pos.z = this->relPos.z + pos.z;
}

void Hitbox::setLastPos(const EGG::Vector3f& scale, const EGG::Matrix34f& pose) {
  float yScaleFactor = scale.y;
  EGG::Vector3f scaledPos = this->bsp->pos;
  scaledPos.x *= scale.x;
  scaledPos.z *= scale.z;
  if (scale.y != scale.z && scale.y < 1.0f) {
    f32 rad = this->radius;
    scaledPos.y += (1.0f - scale.y) * rad;
    yScaleFactor = scale.z;
  }
  scaledPos.y *= yScaleFactor;
  VEC3Transform(&this->lastPos, &pose, &scaledPos);
}

MARK_FLOW_CHECK(0x805b8158);
BspHitbox* Hitbox::create(const EGG::Vector3f& pos, f32 radius) {
  BspHitbox* bspData = new BspHitbox;
  this->bsp = bspData;
  this->bsp->pos = pos;
  BspHitbox* tmp = this->bsp;
  tmp->radius = radius;
  this->radius = radius;
  return tmp;
}

void Hitbox::setScale(f32 scale) {
  this->radius = this->bsp->radius * scale;
}

KartCollisionInfo* KartCollisionInfo::initStatus() {
  this->flags = 0;
  this->reset();
  return this;
}

void KartCollisionInfo::reset() {
  this->flags = 0;
  this->tangentOff.setZero();
  this->floorNrm.setZero();
  this->wallNrm.setZero();
  this->softWallNrm.setZero();
  this->vel.setZero();
  this->relPos.setZero();
  this->movement.setZero();
  this->_58.setZero();
  this->speedFactor = 1.0f;
  this->handlingFactor = 0.0f;
  this->floorKclTypeMask = 0;
  this->floorKclVariant = -1;
  this->wallKclType = 0;
  this->wallKclVariant = -1;
  this->sinkDepth = 0;
  this->colPerpendicularity = 0.0f;
}

HitboxGroup::HitboxGroup() {
  KartCollisionInfo& collisionInfo = this->colInfo;
  this->hitboxCount = 0;
  collisionInfo.initStatus();
  this->hitboxes = nullptr;
  this->_90 = 0;
  this->hitboxScale = 1.0f;
  this->_98 = 0.0f;
  this->colInfo.reset();
}

void HitboxGroup::reset() {
  this->colInfo.reset();
  for (s32 i = 0; (u16)i < this->hitboxCount; i++) {
    this->getHitbox(i).reset();
    this->getHitbox(i).setScale(this->hitboxScale);
  }
}

void HitboxGroup::setHitboxScale(f32 scale) {
  this->hitboxScale = scale;
  for (s32 i = 0; (u16)i < this->hitboxCount; i++) {
    this->getHitbox(i).setScale(this->hitboxScale);
  }
}

void HitboxGroup::createHitboxes(s32 n) {
  this->hitboxes = new Hitbox[n];
}

f32 HitboxGroup::initHitboxes(BspHitbox* bspHitboxes, void* unused, s32 wheelCount) {
  u16 count = 0;
  this->_90 = 2;
  for (s32 i = 0; i < BSP_HITBOX_COUNT; i++) {
    if ((bspHitboxes + i)->enabled) {
      count++;
    }
  }
  this->hitboxCount = count;
  this->createHitboxes(this->hitboxCount);
  return this->setHitboxes(bspHitboxes);
}

f32 HitboxGroup::setHitboxes(BspHitbox* bspHitboxes) {
  BspHitbox* bspIt = bspHitboxes;
  s32 hitboxIdx = 0;
  for (s32 i = 0; i < BSP_HITBOX_COUNT; i++) {
    if (bspIt->enabled) {
      this->getHitbox(hitboxIdx).bsp = (bspHitboxes + i);
      hitboxIdx++;
    }
    bspIt++;
  }
  return this->computeCollisionLimits();
}

void HitboxGroup::createSingleHitbox(const EGG::Vector3f& pos, f32 radius) {
  this->_90 = 1;
  this->hitboxCount = 1;

  Hitbox* hitbox = new Hitbox;
  this->hitboxes = hitbox;
  hitbox->create(pos, radius);

  this->boundingRadius = radius;
}

f32 HitboxGroup::computeCollisionLimits() {
  BspHitbox* bspData; 
  EGG::Vector3f max(0.0f, 0.0f, 0.0f);
  float _meme[6];
  _meme[0] = 0.0f;
  _meme[1] = 0.0f;
  _meme[2] = 0.0f;
  _meme[3] = 0.0f;
  _meme[4] = 0.0f;
  _meme[5] = 0.0f;

  for (s32 i = 0; (u16)i < this->hitboxCount; i++) {
    bspData = this->getHitbox(i).bsp;
    if (bspData->enabled) {
      float r = bspData->radius;
      EGG::Vector3f bspPos(bspData->pos);
      f32 bboxx = r + fabsf(bspPos.x);
      max.x = bboxx > max.x ? bboxx : max.x;
    
      f32 bboxy = r + fabsf(bspPos.y);
      max.y = bboxy > max.y ? bboxy : max.y;
    
      f32 bboxz = r + fabsf(bspPos.z);
      max.z = bboxz > max.z ? bboxz : max.z;
    } 
  }

  f32 z = max.z;
  f32 y = max.y;
  f32 x = max.x;

  float maxAll = x > y ? (x > z ? x : z) : (y > z ? y : z);
  this->boundingRadius = maxAll;
  return 0.5f * max.z;
}
}

extern const u32 lbl_808927b0[];
const u32 lbl_808927b0[] = {
    0x00000000, 0x3f800000, 0x00000000,
    0x3f800000, 0x00000000
};
