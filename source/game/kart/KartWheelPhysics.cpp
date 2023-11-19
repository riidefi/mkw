#include "KartWheelPhysics.hpp"

// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern function references.
// PAL: 0x80021594
extern UNKNOWN_FUNCTION(_savegpr_24);
// PAL: 0x80021598
extern UNKNOWN_FUNCTION(_savegpr_25);
// PAL: 0x800215a0
extern UNKNOWN_FUNCTION(_savegpr_27);
// PAL: 0x800215e0
extern UNKNOWN_FUNCTION(_restgpr_24);
// PAL: 0x800215e4
extern UNKNOWN_FUNCTION(_restgpr_25);
// PAL: 0x800215ec
extern UNKNOWN_FUNCTION(_restgpr_27);
// PAL: 0x80229dcc
extern UNKNOWN_FUNCTION(__nw__FUl);
// PAL: 0x8022ff98
extern UNKNOWN_FUNCTION(makeR__Q23EGG9Matrix34fFRCQ23EGG8Vector3f);
// PAL: 0x802303f8
extern UNKNOWN_FUNCTION(multVector__Q23EGG9Matrix34fCFRCQ23EGG8Vector3f);
// PAL: 0x8023a2d0
extern UNKNOWN_FUNCTION(rotateVector__Q23EGG5QuatfFRCQ23EGG8Vector3fRQ23EGG8Vector3f);
// PAL: 0x8056c950
extern UNKNOWN_FUNCTION(unk_8056c950);
// PAL: 0x8059018c
extern UNKNOWN_FUNCTION(__ct__Q24Kart15KartObjectProxyFv);
// PAL: 0x8059020c
extern UNKNOWN_FUNCTION(PlayerPointers_getPlayerPosition);
// PAL: 0x805903ac
extern UNKNOWN_FUNCTION(PlayerPointers_getPlayerPhysicsHolder);
// PAL: 0x805903cc
extern UNKNOWN_FUNCTION(PlayerPointers_getPlayerPhysics);
// PAL: 0x8059069c
extern UNKNOWN_FUNCTION(kartBody__Q24Kart15KartObjectProxyFv);
// PAL: 0x805906dc
extern UNKNOWN_FUNCTION(kartWheel__Q24Kart15KartObjectProxyFl);
// PAL: 0x80590764
extern UNKNOWN_FUNCTION(kartSub__Q24Kart15KartObjectProxyFv);
// PAL: 0x8059077c
extern UNKNOWN_FUNCTION(kartMove__Q24Kart15KartObjectProxyFv);
// PAL: 0x8059081c
extern UNKNOWN_FUNCTION(PlayerPointers_getVehicleBodyCollisionData);
// PAL: 0x8059084c
extern UNKNOWN_FUNCTION(kartCollide__Q24Kart15KartObjectProxyFv);
// PAL: 0x80590874
extern UNKNOWN_FUNCTION(PlayerPointers_getPlayerStats);
// PAL: 0x805908b4
extern UNKNOWN_FUNCTION(bspWheel__Q24Kart15KartObjectProxyCFl);
// PAL: 0x80590a5c
extern UNKNOWN_FUNCTION(PlayerPointers_getPlayerIdx);
// PAL: 0x80590c44
extern UNKNOWN_FUNCTION(PlayerPointers_getPlayerMatCol0);
// PAL: 0x805914bc
extern UNKNOWN_FUNCTION(getScale__Q24Kart15KartObjectProxyFv);
// PAL: 0x805914f4
extern UNKNOWN_FUNCTION(inRespawn__Q24Kart15KartObjectProxyFv);
// PAL: 0x805979ec
extern UNKNOWN_FUNCTION(unk_805979ec);
// PAL: 0x80599690
extern UNKNOWN_FUNCTION(WheelPhysics_updateCollision);
// PAL: 0x80599ad0
extern UNKNOWN_FUNCTION(WheelPhysics_realign);
// PAL: 0x8059a4f8
extern UNKNOWN_FUNCTION(vec3_from_mat33_mul);
// PAL: 0x805aeb88
extern UNKNOWN_FUNCTION(Vec3_projUnit);
// PAL: 0x805b6150
extern UNKNOWN_FUNCTION(applySuspensionWrench__Q24Kart12KartDynamicsFRCQ23EGG8Vector3fRCQ23EGG8Vector3fRCQ23EGG8Vector3fb);
// PAL: 0x805b6f4c
extern UNKNOWN_FUNCTION(unk_805b6f4c);
// PAL: 0x805b7928
extern UNKNOWN_FUNCTION(unk_805b7928);
// PAL: 0x805b821c
extern UNKNOWN_FUNCTION(reset__Q24Kart13CollisionInfoFv);
// PAL: 0x805b8330
extern UNKNOWN_FUNCTION(reset__Q24Kart11HitboxGroupFv);
// PAL: 0x805b83d8
extern UNKNOWN_FUNCTION(setHitboxScale__Q24Kart11HitboxGroupFf);
// PAL: 0x805b875c
extern UNKNOWN_FUNCTION(createSingleHitbox__Q24Kart11HitboxGroupFRCQ23EGG8Vector3ff);// Extern data references.
// PAL: 0x808b6590
extern UNKNOWN_DATA(lbl_808b6590);
}

// --- EXTERN DECLARATIONS END ---

// .rodata
/*const u32 lbl_80891f68[] = {
    0x00000000
};*/
extern "C" const u32 lbl_80891f68;
REL_SYMBOL_AT(lbl_80891f68, 0x80891f68);

// .data
#pragma explicit_zero_data on
u32 lbl_808b6688[] = {
    0x3dcccccd
};
u32 lbl_808b668c[] = {
    0x41200000
};
u32 lbl_808b6690[] = {
    0x42c80000
};
u32 lbl_808b6694[] = {
    0x3e99999a, 0x3f800000, 0x40a00000, 0x3e99999a
};
#pragma explicit_zero_data off

#include "KartWheel.hpp"

namespace Kart {
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
  this->_48.setZero();
  this->speed.setZero();
  this->wheelEdgePos.setZero();
  this->effectiveRadius = 0.0f;
  this->targetEffectiveRadius = 0.0f;
  this->isAtSuspTopLimit = 0.0f;
  this->suspTop.setZero();
  if (this->bspWheel) {
    this->susTravel = bspWheel->maxTravel;
    this->effectiveRadius = bspWheel->wheelRadius;
  }
}
}

const u32 lbl_80891f70[] = {
    0x40a00000
};
const u32 lbl_80891f74[] = {
    0x3dcccccd
};
extern "C" const u32 lbl_80891f88[];

// Symbol: unk_805995c0
// PAL: 0x805995c0..0x80599690
MARK_BINARY_BLOB(unk_805995c0, 0x805995c0, 0x80599690);
asm UNKNOWN_FUNCTION(unk_805995c0) {
  #include "asm/805995c0.s"
}

// Symbol: WheelPhysics_updateCollision
// PAL: 0x80599690..0x80599ad0
MARK_BINARY_BLOB(WheelPhysics_updateCollision, 0x80599690, 0x80599ad0);
asm UNKNOWN_FUNCTION(WheelPhysics_updateCollision) {
  #include "asm/80599690.s"
}

// Symbol: WheelPhysics_realign
// PAL: 0x80599ad0..0x80599d9c
MARK_BINARY_BLOB(WheelPhysics_realign, 0x80599ad0, 0x80599d9c);
asm UNKNOWN_FUNCTION(WheelPhysics_realign) {
  #include "asm/80599ad0.s"
}

namespace Kart {
void KartWheelPhysics::updateEffectiveRadius() {
  this->effectiveRadius += (targetEffectiveRadius - effectiveRadius) * 0.1f;
}
}

// Symbol: unk_80599dc0
// PAL: 0x80599dc0..0x80599eac
MARK_BINARY_BLOB(unk_80599dc0, 0x80599dc0, 0x80599eac);
asm UNKNOWN_FUNCTION(unk_80599dc0) {
  #include "asm/80599dc0.s"
}

// Symbol: WheelPhysics_hasFloorCollision
// PAL: 0x80599eac..0x80599ebc
MARK_BINARY_BLOB(WheelPhysics_hasFloorCollision, 0x80599eac, 0x80599ebc);
asm UNKNOWN_FUNCTION(WheelPhysics_hasFloorCollision) {
  #include "asm/80599eac.s"
}

namespace Kart {
const EGG::Vector3f* KartWheelPhysics::getCollisionFloorDir() const {
  return &this->getCollisionInfo()->floorDir;
}

const CollisionInfo* KartWheelPhysics::getCollisionInfo() const {
  return this->hitboxGroup->getCollisionInfo();
}

KartSusPhysics::KartSusPhysics(u32 wheelIdx, s32 wheelType, s32 bspWheelIdx) : KartObjectProxy() {
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
  this->_34 = 0;
  this->_36 = 0;
  this->downDir.setZero();
}

void KartSusPhysics::init() {
  this->wheelPhysics = this->KartObjectProxy::kartWheel(this->wheelIdx)->getWheelPhysics();
  this->bspWheel = this->KartObjectProxy::bspWheel(this->bspWheelIdx);
  this->reset();
}
}

#ifndef SHIFTABLE
extern "C" UNKNOWN_DATA(lbl_80891f78);
REL_SYMBOL_AT(lbl_80891f78, 0x80891f78);
#else
extern "C" f32 lbl_80891f78[];
const f32 lbl_80891f78[] = 1.0f;
#endif
extern const u32 lbl_80891f7c[];
const u32 lbl_80891f7c[] = {
    /*0x3f800000, */0x00000000, 0x43300000, 0x80000000
};
const u32 lbl_80891f88[] = {
    0x3c23d70a
};
const u32 lbl_80891f8c[] = {
    0xbf800000, 0x3c8efa35, 0xc1700000
};

// Symbol: unk_8059a02c
// PAL: 0x8059a02c..0x8059a278
MARK_BINARY_BLOB(unk_8059a02c, 0x8059a02c, 0x8059a278);
asm UNKNOWN_FUNCTION(unk_8059a02c) {
  #include "asm/8059a02c.s"
}

// Symbol: WheelPhysicsHolder_update
// PAL: 0x8059a278..0x8059a4f8
MARK_BINARY_BLOB(WheelPhysicsHolder_update, 0x8059a278, 0x8059a4f8);
asm UNKNOWN_FUNCTION(WheelPhysicsHolder_update) {
  #include "asm/8059a278.s"
}

// Symbol: vec3_from_mat33_mul
// PAL: 0x8059a4f8..0x8059a574
MARK_BINARY_BLOB(vec3_from_mat33_mul, 0x8059a4f8, 0x8059a574);
asm UNKNOWN_FUNCTION(vec3_from_mat33_mul) {
  #include "asm/8059a4f8.s"
}

// Symbol: WheelPhysicsHolder_applySuspensions
// PAL: 0x8059a574..0x8059a9c4
MARK_BINARY_BLOB(WheelPhysicsHolder_applySuspensions, 0x8059a574, 0x8059a9c4);
asm UNKNOWN_FUNCTION(WheelPhysicsHolder_applySuspensions) {
  #include "asm/8059a574.s"
}
