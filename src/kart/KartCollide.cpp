#include "KartCollide.hpp"

// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern function references.
// PAL: 0x80021450
extern UNKNOWN_FUNCTION(__ptmf_scall);
// PAL: 0x80021570
extern UNKNOWN_FUNCTION(_savegpr_15);
// PAL: 0x8002157c
extern UNKNOWN_FUNCTION(_savegpr_18);
// PAL: 0x8002158c
extern UNKNOWN_FUNCTION(_savegpr_22);
// PAL: 0x80021594
extern UNKNOWN_FUNCTION(_savegpr_24);
// PAL: 0x80021598
extern UNKNOWN_FUNCTION(_savegpr_25);
// PAL: 0x800215a0
extern UNKNOWN_FUNCTION(_savegpr_27);
// PAL: 0x800215bc
extern UNKNOWN_FUNCTION(_restgpr_15);
// PAL: 0x800215c8
extern UNKNOWN_FUNCTION(_restgpr_18);
// PAL: 0x800215d8
extern UNKNOWN_FUNCTION(_restgpr_22);
// PAL: 0x800215e0
extern UNKNOWN_FUNCTION(_restgpr_24);
// PAL: 0x800215e4
extern UNKNOWN_FUNCTION(_restgpr_25);
// PAL: 0x800215ec
extern UNKNOWN_FUNCTION(_restgpr_27);
// PAL: 0x80026050
extern UNKNOWN_FUNCTION(VWarning);
// PAL: 0x80085040
extern UNKNOWN_FUNCTION(FrSqrt);
// PAL: 0x80085580
extern UNKNOWN_FUNCTION(VEC3Maximize__Q24nw4r4mathFPQ34nw4r4math4VEC3PCQ34nw4r4math4VEC3PCQ34nw4r4math4VEC3);
// PAL: 0x800855c0
extern UNKNOWN_FUNCTION(VEC3Minimize__Q24nw4r4mathFPQ34nw4r4math4VEC3PCQ34nw4r4math4VEC3PCQ34nw4r4math4VEC3);
// PAL: 0x80229dcc
extern UNKNOWN_FUNCTION(__nw__FUl);
// PAL: 0x8023a2d0
extern UNKNOWN_FUNCTION(rotateVector__Q23EGG5QuatfFRCQ23EGG8Vector3fRQ23EGG8Vector3f);
// PAL: 0x80243adc
extern UNKNOWN_FUNCTION(normalise__Q23EGG8Vector3fFv);
// PAL: 0x80514810
extern UNKNOWN_FUNCTION(Vec3_scale);
// PAL: 0x80514838
extern UNKNOWN_FUNCTION(Vec3_add);
// PAL: 0x8051486c
extern UNKNOWN_FUNCTION(VEC3_sub);
// PAL: 0x80516808
extern UNKNOWN_FUNCTION(unk_80516808);
// PAL: 0x80537830
extern UNKNOWN_FUNCTION(VEC3_fromCross);
// PAL: 0x8056e764
extern UNKNOWN_FUNCTION(processBody__Q24Kart11KartCollideFRQ24Kart17KartCollisionInfoRCQ24Kart6HitboxRCQ25Field7ColInfoPUl);
// PAL: 0x8056e8d4
extern UNKNOWN_FUNCTION(processWheels__Q24Kart11KartCollideFRQ24Kart17KartCollisionInfoRCQ24Kart6HitboxRCQ25Field7ColInfoPUl);
// PAL: 0x8056ea04
extern UNKNOWN_FUNCTION(kartStats__Q24Kart15KartObjectProxyCFv);
// PAL: 0x8056eef4
extern UNKNOWN_FUNCTION(unk_8056eef4);
// PAL: 0x8056f26c
extern UNKNOWN_FUNCTION(checkNeighborhood__Q24Kart11KartCollideFRQ24Kart17KartCollisionInfoRCQ24Kart6HitboxRCQ25Field7ColInfo);
// PAL: 0x8056f510
extern UNKNOWN_FUNCTION(unk_8056f510);
// PAL: 0x80570da8
extern UNKNOWN_FUNCTION(unk_80570da8);
// PAL: 0x80571484
extern UNKNOWN_FUNCTION(unk_80571484);
// PAL: 0x80571570
extern UNKNOWN_FUNCTION(unk_80571570);
// PAL: 0x805718d4
extern UNKNOWN_FUNCTION(unk_805718d4);
// PAL: 0x80571d98
extern UNKNOWN_FUNCTION(unk_80571d98);
// PAL: 0x80572544
extern UNKNOWN_FUNCTION(unk_80572544);
// PAL: 0x80573464
extern UNKNOWN_FUNCTION(unk_80573464);
// PAL: 0x80573520
extern UNKNOWN_FUNCTION(unk_80573520);
// PAL: 0x80573b00
extern UNKNOWN_FUNCTION(PlayerSub18_activateOob);
// PAL: 0x80573ff0
extern UNKNOWN_FUNCTION(__dt__Q24Kart11KartCollideFv);
// PAL: 0x805758e4
extern UNKNOWN_FUNCTION(PlayerZipper_end);
// PAL: 0x805799ac
extern UNKNOWN_FUNCTION(PlayerSub10_respawn);
// PAL: 0x80579ce4
extern UNKNOWN_FUNCTION(unk_80579ce4);
// PAL: 0x80579f6c
extern UNKNOWN_FUNCTION(unk_80579f6c);
// PAL: 0x80580768
extern UNKNOWN_FUNCTION(unk_80580768);
// PAL: 0x805819a8
extern UNKNOWN_FUNCTION(unk_805819a8);
// PAL: 0x805832e4
extern UNKNOWN_FUNCTION(clearBoost__Q24Kart8KartMoveFv);
// PAL: 0x80586db4
extern UNKNOWN_FUNCTION(unk_80586db4);
// PAL: 0x80590100
extern UNKNOWN_FUNCTION(PlayerHolder_getPlayer);
// PAL: 0x8059020c
extern UNKNOWN_FUNCTION(getPos__Q24Kart15KartObjectProxyCFv);
// PAL: 0x80590264
extern UNKNOWN_FUNCTION(PlayerPointers_getMat);
// PAL: 0x805903ac
extern UNKNOWN_FUNCTION(kartPhysics__Q24Kart15KartObjectProxyFv);
// PAL: 0x805903cc
extern UNKNOWN_FUNCTION(kartDynamics__Q24Kart15KartObjectProxyFv);
// PAL: 0x8059041c
extern UNKNOWN_FUNCTION(unk_8059041c);
// PAL: 0x80590650
extern UNKNOWN_FUNCTION(PlayerPointers_isReal);
// PAL: 0x80590678
extern UNKNOWN_FUNCTION(PlayerPointers_isGhost);
// PAL: 0x8059069c
extern UNKNOWN_FUNCTION(kartBody__Q24Kart15KartObjectProxyFv);
// PAL: 0x8059077c
extern UNKNOWN_FUNCTION(kartMove__Q24Kart15KartObjectProxyFv);
// PAL: 0x80590794
extern UNKNOWN_FUNCTION(kartSnd__Q24Kart15KartObjectProxyFv);
// PAL: 0x805907a0
extern UNKNOWN_FUNCTION(unk_805907a0);
// PAL: 0x805907b0
extern UNKNOWN_FUNCTION(unk_805907b0);
// PAL: 0x805907c0
extern UNKNOWN_FUNCTION(kartAccessor_34__Q24Kart15KartObjectProxyFv);
// PAL: 0x805907d8
extern UNKNOWN_FUNCTION(hitboxGroup__Q24Kart15KartObjectProxyFv);
// PAL: 0x8059084c
extern UNKNOWN_FUNCTION(kartCollide__Q24Kart15KartObjectProxyFv);
// PAL: 0x80590888
extern UNKNOWN_FUNCTION(bsp__Q24Kart15KartObjectProxyCFv);
// PAL: 0x80590a40
extern UNKNOWN_FUNCTION(kartModel__Q24Kart15KartObjectProxyFv);
// PAL: 0x80590a4c
extern UNKNOWN_FUNCTION(unk_80590a4c);
// PAL: 0x80590a5c
extern UNKNOWN_FUNCTION(getPlayerIdx__Q24Kart15KartObjectProxyCFv);
// PAL: 0x80590a6c
extern UNKNOWN_FUNCTION(PlayerPointers_isBike);
// PAL: 0x80590c44
extern UNKNOWN_FUNCTION(PlayerPointers_getPlayerMatCol0);
// PAL: 0x80590cd0
extern UNKNOWN_FUNCTION(unk_80590cd0);
// PAL: 0x80590ce4
extern UNKNOWN_FUNCTION(PlayerPointers_getMalCol2);
// PAL: 0x80590cf8
extern UNKNOWN_FUNCTION(getVehicleSpeed__Q24Kart15KartObjectProxyFv);
// PAL: 0x80590d08
extern UNKNOWN_FUNCTION(playerPointers_getSpeed);
// PAL: 0x80590d20
extern UNKNOWN_FUNCTION(kartAction__Q24Kart15KartObjectProxyFv);
// PAL: 0x80590d38
extern UNKNOWN_FUNCTION(unk_80590d38);
// PAL: 0x80590db4
extern UNKNOWN_FUNCTION(clearBoost__Q24Kart15KartObjectProxyFv);
// PAL: 0x80590de0
extern UNKNOWN_FUNCTION(hasCamera__Q24Kart15KartObjectProxyFv);
// PAL: 0x80590ef8
extern UNKNOWN_FUNCTION(unk_80590ef8);
// PAL: 0x80590f18
extern UNKNOWN_FUNCTION(unk_80590f18);
// PAL: 0x80590f70
extern UNKNOWN_FUNCTION(unk_80590f70);
// PAL: 0x805910c0
extern UNKNOWN_FUNCTION(kartEnemy__Q24Kart15KartObjectProxyFv);
// PAL: 0x8059144c
extern UNKNOWN_FUNCTION(kartNetReceiver__Q24Kart15KartObjectProxyFv);
// PAL: 0x805914bc
extern UNKNOWN_FUNCTION(getScale__Q24Kart15KartObjectProxyFv);
// PAL: 0x805914f4
extern UNKNOWN_FUNCTION(inRespawn__Q24Kart15KartObjectProxyFv);
// PAL: 0x80591784
extern UNKNOWN_FUNCTION(unk_80591784);
// PAL: 0x805917a0
extern UNKNOWN_FUNCTION(PlayerPointers_getOobWipeState);
// PAL: 0x80591828
extern UNKNOWN_FUNCTION(unk_80591828);
// PAL: 0x805918bc
extern UNKNOWN_FUNCTION(unk_805918bc);
// PAL: 0x805918e0
extern UNKNOWN_FUNCTION(unk_805918e0);
// PAL: 0x80591904
extern UNKNOWN_FUNCTION(kartHalfPipe__Q24Kart15KartObjectProxyFv);
// PAL: 0x8059197c
extern UNKNOWN_FUNCTION(unk_8059197c);
// PAL: 0x80595ca4
extern UNKNOWN_FUNCTION(unk_80595ca4);
// PAL: 0x805ae9ec
extern UNKNOWN_FUNCTION(VEC3_perpInPlane);
// PAL: 0x805aeb88
extern UNKNOWN_FUNCTION(projUnit__6RKGeomFRQ23EGG8Vector3fRCQ23EGG8Vector3fRCQ23EGG8Vector3f);
// PAL: 0x805aebd0
extern UNKNOWN_FUNCTION(rejUnit__6RKGeomFRQ23EGG8Vector3fRCQ23EGG8Vector3fRCQ23EGG8Vector3f);
// PAL: 0x805b5ce8
extern UNKNOWN_FUNCTION(applyWrenchScaled__Q24Kart12KartDynamicsFRCQ23EGG8Vector3fRCQ23EGG8Vector3ff);
// PAL: 0x805b6388
extern UNKNOWN_FUNCTION(addForce__Q24Kart12KartDynamicsFRCQ23EGG8Vector3f);
// PAL: 0x805b6724
extern UNKNOWN_FUNCTION(PlayerSub18_findCollisionInner);
// PAL: 0x805b72b8
extern UNKNOWN_FUNCTION(unk_805b72b8);
// PAL: 0x805b7fbc
extern UNKNOWN_FUNCTION(update__Q24Kart6HitboxFRCQ23EGG8Vector3fRCQ23EGG5QuatfRCQ23EGG8Vector3fff);
// PAL: 0x805b80a8
extern UNKNOWN_FUNCTION(setLastPos__Q24Kart6HitboxFRCQ23EGG8Vector3fRCQ23EGG9Matrix34f);
// PAL: 0x806a6428
extern UNKNOWN_FUNCTION(unk_806a6428);
// PAL: 0x806aace4
extern UNKNOWN_FUNCTION(unk_806aace4);
// PAL: 0x806ab1d4
extern UNKNOWN_FUNCTION(unk_806ab1d4);
// PAL: 0x806ab6b0
extern UNKNOWN_FUNCTION(unk_806ab6b0);
// PAL: 0x806ab8a0
extern UNKNOWN_FUNCTION(unk_806ab8a0);
// PAL: 0x80708b44
extern UNKNOWN_FUNCTION(unk_80708b44);
// PAL: 0x807091ac
extern UNKNOWN_FUNCTION(unk_807091ac);
// PAL: 0x807263c4
extern UNKNOWN_FUNCTION(unk_807263c4);
// PAL: 0x807263cc
extern UNKNOWN_FUNCTION(unk_807263cc);
// PAL: 0x807901f0
extern UNKNOWN_FUNCTION(checkSphereCachedPartial__Q25Field11CourseModelFRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field14ColInfoPartialPUlfUl);
// PAL: 0x807903bc
extern UNKNOWN_FUNCTION(checkSphereCachedPartialPush__Q25Field11CourseModelFRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field14ColInfoPartialPUlfUl);
// PAL: 0x8079864c
extern UNKNOWN_FUNCTION(ItemHolderPlayer_activateMushroom);
// PAL: 0x80798a0c
extern UNKNOWN_FUNCTION(unk_80798a0c);
// PAL: 0x80798d0c
extern UNKNOWN_FUNCTION(unk_80798d0c);
// PAL: 0x80799cac
extern UNKNOWN_FUNCTION(ItemHolder_checkPlayerCollision);
// PAL: 0x8079a578
extern UNKNOWN_FUNCTION(unk_8079a578);
// PAL: 0x807a2234
extern UNKNOWN_FUNCTION(unk_807a2234);
// PAL: 0x807bd96c
extern UNKNOWN_FUNCTION(findClosestCollisionEntry__5FieldFPUlUl);
// PAL: 0x807d19c8
extern UNKNOWN_FUNCTION(unk_807d19c8);
// PAL: 0x807d396c
extern UNKNOWN_FUNCTION(unk_807d396c);
// PAL: 0x80865518
extern UNKNOWN_FUNCTION(unk_80865518);
// PAL: 0x80865534
extern UNKNOWN_FUNCTION(unk_80865534);// Extern data references.
// PAL: 0x802a4100
extern UNKNOWN_DATA(lbl_802a4100);
// PAL: 0x802a4118
//extern UNKNOWN_DATA(RKSystem_ex);
// PAL: 0x802a4148
extern UNKNOWN_DATA(lbl_802a4148);
// PAL: 0x808a66cc
extern UNKNOWN_DATA(lbl_808a66cc);
// PAL: 0x808a6700
extern UNKNOWN_DATA(gColInfo);
// PAL: 0x808b5468
extern UNKNOWN_DATA(lbl_808b5468);
// PAL: 0x808b551c
extern UNKNOWN_DATA(lbl_808b551c);
// PAL: 0x808b56d0
extern UNKNOWN_DATA(lbl_808b56d0);
// PAL: 0x808b56f4
extern UNKNOWN_DATA(lbl_808b56f4);
// PAL: 0x809bd6e8
extern UNKNOWN_DATA(spInstance__Q26System9CourseMap);
// PAL: 0x809bd728
extern UNKNOWN_DATA(spInstance__Q26System10RaceConfig);
// PAL: 0x809bd730
extern UNKNOWN_DATA(spInstance__Q26System11RaceManager);
// PAL: 0x809c18d8
extern UNKNOWN_DATA(lbl_809c18d8);
// PAL: 0x809c18f8
extern UNKNOWN_DATA(lbl_809c18f8);
// PAL: 0x809c21d0
extern UNKNOWN_DATA(lbl_809c21d0);
// PAL: 0x809c2f38
extern UNKNOWN_DATA(lbl_809c2f38);
// PAL: 0x809c2f44
extern UNKNOWN_DATA(spInstance__Q25Field11CourseModel);
// PAL: 0x809c3618
extern UNKNOWN_DATA(lbl_809c3618);
// PAL: 0x809c3bdc
extern UNKNOWN_DATA(closestCollisionEntry__5Field);
// PAL: 0x809c3c04
extern UNKNOWN_DATA(VEC_INFINITY);
// PAL: 0x809c4330
extern UNKNOWN_DATA(lbl_809c4330);
}

// --- EXTERN DECLARATIONS END ---

// .rodata
DEFINE_REL_DATA(lbl_80891730, 0x80891730, const f32, 0.0f);
DEFINE_REL_DATA(lbl_80891734, 0x80891734, const f32, 1.0f);
DEFINE_REL_DATA(lbl_80891738, 0x80891738, const f32, 100.0f);
DEFINE_REL_DATA(lbl_8089173c, 0x8089173c, const f32, 0.8f);

extern "C" EGG::Vector3f RKSystem_ex;

// .data
#ifdef __CWCC__ // needed for matching padding
#pragma explicit_zero_data on
u32 __vt__Q24Kart11KartCollide[] = {
    0x00000000, 0x00000000, (u32)&processBody__Q24Kart11KartCollideFRQ24Kart17KartCollisionInfoRCQ24Kart6HitboxRCQ25Field7ColInfoPUl, (u32)&processWheels__Q24Kart11KartCollideFRQ24Kart17KartCollisionInfoRCQ24Kart6HitboxRCQ25Field7ColInfoPUl,
    (u32)&__dt__Q24Kart11KartCollideFv, 0x00000000
};
#pragma explicit_zero_data off
#endif

using namespace Field;

namespace Kart {
FORCESTRIP void _orderfloat() {0.0f;1.0f;}
KartCollide::KartCollide() {
  this->boundingRadius = 100.0f;
  this->surfaceFlags = 0;
  this->kartCollideArea = new KartCollideArea();
}

struct _Dummy {
  ~_Dummy();
};
_Dummy::~_Dummy(){}

void KartCollide::init() {
  this->kartCollideArea->init();
  this->updateBbox();
  this->playerBumpTimer = 0;
  _1c = 0.8f;
  _20.setZero();
  this->surfaceFlags = 0;
  this->tangentOff.setZero();
  this->movement.setZero();
  this->respawnTimer = 0;
  this->solidOobTimer = 0;
  this->someLightningTimer = 0;
  _50 = 0.0f;
  this->suspBottomHeightNonSoftWall = 0.0f;
  this->suspBottomHeightSoftWall = 0.0f;
  this->someNonSoftWallTimer = 0;
  this->someSoftWallTimer = 0;
  this->someAngVel3FrameTimer = 0;
  this->someYawAngVel = 0.0f;
  _68 = 0.0f;
  this->oobAreaIdx = -1;
  _70 = 0.0f;
}

void KartCollide::updateBbox() {
  this->boundingRadius = this->hitboxGroup()->getBoundingRadius() * this->kartMove()->hitboxScale();
}
}

extern const u32 lbl_80891740[];
const u32 lbl_80891740[] = {
    /*0x3f4ccccd, */0x41200000, 0xbf800000, 0xbf000000,
    0x3f000000, 0x3fc00000, 0x40400000, 0x3de147ae,
    0x3e99999a, 0x3e4ccccd
};
const u32 lbl_80891764[] = {
    0x3c23d70a, 0x3d4ccccd, 0x00000000, 0x43300000,
    0x00000000, 0x42a00000, 0x3fe66666, 0x3f333333
};
const u32 lbl_80891784[] = {
    0x41f00000, 0xbf34fdf4, 0x3ba3d70a, 0xc2480000
};
const u32 lbl_80891794[] = {
    0x3f51eb85, 0x40a00000, 0xc0800000, 0x3f733333,
    0x3d4cccd0, 0x428c0000, 0x00000000
};

namespace Kart {
void KartCollide::processBody(KartCollisionInfo& kartColInfo, const Hitbox& hitbox, const Field::ColInfo& colInfo, u32* colTypeMask) {
  this->processMovingWater(kartColInfo, colTypeMask);

  //bool hasWallCol = this->processWall(kartColInfo, colInfo, colTypeMask); // regswap
  bool hasWallCol;
  if (Field::lookupCollisionEntry(colTypeMask, KCL_TYPE_PLAYER_WALL_CAT1)) {
    u32 wallKclType = KCL_ATTRIBUTE_TYPE(Field::closestCollisionEntry->attribute);
    u32 wallKclVariant = KCL_ATTRIBUTE_VARIANT(Field::closestCollisionEntry->attribute);

    if (Field::lookupCollisionEntry(colTypeMask, KCL_TYPE_PLAYER_WALL_CAT2)) {
      kartColInfo.wallKclType = wallKclType;
      kartColInfo.wallKclVariant = wallKclVariant;
      if ((Field::closestCollisionEntry->attribute & KCL_SOFT_WALL_MASK) != 0) {
        kartColInfo.flags |= COL_FLAG_SOFT_WALL;
      }
    }
    hasWallCol = true;
  } else {
    hasWallCol = false;
  }

  this->processFloor(kartColInfo, hitbox, colInfo, colTypeMask, false);
  if (hasWallCol) {
    this->checkNeighborhood(kartColInfo, hitbox, colInfo);
  }

  this->processCannon(colTypeMask);
}

void KartCollide::processWheels(KartCollisionInfo& kartColInfo, const Hitbox& hitbox, const Field::ColInfo& colInfo, u32* colTypeMask) {
  this->processMovingWater(kartColInfo, colTypeMask);
  this->processFloor(kartColInfo, hitbox, colInfo, colTypeMask, true);
}

void KartCollide::processMovingWater(KartCollisionInfo& kartColInfo, u32* colTypeMask) {
  if (Field::lookupCollisionEntry(colTypeMask, KCL_MOVING_WATER_MASK)) {
    kartState()->set(KART_FLAG_STICKY_ROAD);
    s32 variant = KCL_ATTRIBUTE_VARIANT(Field::closestCollisionEntry->attribute);
    if (variant == 1) {
      kartColInfo.flags |= (COL_FLAG_MOVING_WATER_V0 | COL_FLAG_MOVING_WATER_STRONG_CURRENT | COL_FLAG_MOVING_WATER_DISABLE_ACC);
    } else if (variant == 2) {
      kartColInfo.flags |= COL_FLAG_MOVING_WATER_V2;
    } else if (variant == 3) {
      kartColInfo.flags |= (COL_FLAG_MOVING_WATER_V2 | COL_FLAG_MOVING_WATER_DISABLE_ACC| COL_FLAG_MOVING_WATER_V3);
    } else {
      kartColInfo.flags |= COL_FLAG_MOVING_WATER_V0;
    }
  }
}

void KartCollide::processFloor(KartCollisionInfo& kartColInfo, const Hitbox& hitbox, const Field::ColInfo& colInfo, u32* colTypeMask, bool isWheel) {
  if ((kartColInfo.flags & COL_FLAG_SOFT_WALL) != 0) {
    this->someSoftWallTimer++;
    f32 radius = hitbox.radius;
    this->suspBottomHeightSoftWall += hitbox.pos.y - radius;
  }

  if (Field::lookupCollisionEntry(colTypeMask, KCL_TYPE_FLOOR)) {
    if ((Field::closestCollisionEntry->attribute & KCL_TRICKABLE_MASK) != 0) {
      kartColInfo.flags |= COL_FLAG_TRICKABLE;
      this->surfaceFlags |= SURF_FLAG_TRICKABLE;
    } else {
      this->surfaceFlags |= SURF_FLAG_NOT_TRICKABLE;
    }

    kartColInfo.sinkDepth = KCL_ATTRIBUTE_SINK_DEPTH(Field::closestCollisionEntry->attribute);
    f32 speedFactor = kartStats()->getSpeedFactor(KCL_ATTRIBUTE_TYPE(Field::closestCollisionEntry->attribute));
    if (kartColInfo.speedFactor > speedFactor) {
      kartColInfo.speedFactor = speedFactor;
    }
    kartColInfo.handlingFactor += kartStats()->getHandlingFactor(KCL_ATTRIBUTE_TYPE(Field::closestCollisionEntry->attribute));

    if ((Field::closestCollisionEntry->attribute & KCL_REJECT_ROAD_MASK) != 0) {
      kartMove()->kartState()->set(KART_FLAG_REJECT_ROAD);
    }

    kartColInfo.floorKclTypeMask = closestCollisionEntry->typeMask;
    kartColInfo.floorKclVariant = KCL_ATTRIBUTE_VARIANT(closestCollisionEntry->attribute);

    if ((*colTypeMask & KCL_TYPE_OFFROAD_ANY) != 0) {
      this->surfaceFlags |= SURF_FLAG_OFFROAD;
    }

    if (isWheel && (*colTypeMask & KCL_BOOST_PAD_MASK) != 0) {
      kartMove()->setPadType(PAD_TYPE_BOOST_PANEL);
      this->surfaceFlags |= SURF_FLAG_BOOST_PANEL;
    }

    if (Field::lookupCollisionEntry(colTypeMask, KCL_BOOST_RAMP_MASK)) {
      kartMove()->setPadType(PAD_TYPE_BOOST_RAMP);
      kartState()->setBoostRampType(KCL_ATTRIBUTE_VARIANT(closestCollisionEntry->attribute));
      this->surfaceFlags |= (SURF_FLAG_BOOST_PANEL | SURF_FLAG_BOOST_RAMP | SURF_FLAG_TRICKABLE);
    } else {
      kartState()->setBoostRampType(-1);
      this->surfaceFlags |= SURF_FLAG_NOT_TRICKABLE;
    }

    if ((kartColInfo.flags & COL_FLAG_SOFT_WALL) == 0) {
      this->someNonSoftWallTimer++;
      f32 radius = hitbox.radius;
      this->suspBottomHeightNonSoftWall += hitbox.pos.y - radius;
    }

    if ((*colTypeMask & KCL_STICKY_ROAD_MASK) != 0) {
      kartMove()->kartState()->set(KART_FLAG_STICKY_ROAD);
    }

    if (Field::lookupCollisionEntry(colTypeMask, KCL_HALFPIPE_RAMP_MASK)) {
      kartMove()->kartState()->set(KART_FLAG_HALFPIPE_RAMP);
      if (!kartState()->on(KART_FLAG_ONLINE_REMOTE)) {
        kartMove()->kartState()->set(KART_FLAG_HALFPIPE_RAMP_LOCAL);
      }
      this->surfaceFlags |= SURF_FLAG_HALFPIPE_RAMP;
      kartState()->setHalfpipeInvisibilityTimer(2);
      if (KCL_ATTRIBUTE_VARIANT(closestCollisionEntry->attribute) == 1) {
        kartMove()->setPadType(PAD_TYPE_BOOST_PANEL);

      }
    }

    if (Field::lookupCollisionEntry(colTypeMask, KCL_JUMP_PAD_MASK)) {
      KartState* ks = kartState();
      if ((!ks->on(KART_FLAG_TOUCHING_GROUND) || !ks->on(KART_FLAG_JUMPPAD)) && !ks->on(KART_FLAG_JUMPPAD_VELY_INCREASE)) {
	kartMove()->setPadType(PAD_TYPE_JUMP_PAD);
	kartState()->setJumpPadType(KCL_ATTRIBUTE_VARIANT(closestCollisionEntry->attribute));
      }
      kartColInfo.flags |= COL_FLAG_TRICKABLE;
    }

    if ((*colTypeMask & KCL_MOVING_ROAD_MASK) != 0) {
      this->surfaceFlags |= SURF_FLAG_MOVING_ROAD;
    }
  }
}

void KartCollide::updateHitboxes() {
  KartDynamics* dynamics = kartDynamics();
  HitboxGroup* hGroup = hitboxGroup();
  for (s32 i = 0; (u16)i < hGroup->getHitboxCount(); i++) {
    Hitbox& hbox = hGroup->getHitbox(i);
    hbox.update(getScale(), dynamics->fullRot, dynamics->pos, kartMove()->totalScale(), kartBody()->getSinkDepth());
  }
}
}

// Symbol: unk_8056eef4
// PAL: 0x8056eef4..0x8056f184
MARK_BINARY_BLOB(unk_8056eef4, 0x8056eef4, 0x8056f184);
asm UNKNOWN_FUNCTION(unk_8056eef4) {
  #include "asm/8056eef4.s"
}

namespace Kart {
bool KartCollide::processWall(KartCollisionInfo& kartColInfo, const Field::ColInfo& colInfo, u32* colTypeMask) {
  if (Field::lookupCollisionEntry(colTypeMask, KCL_TYPE_PLAYER_WALL_CAT1)) {
    u32 wallKclType = KCL_ATTRIBUTE_TYPE(Field::closestCollisionEntry->attribute);
    u32 wallKclVariant = KCL_ATTRIBUTE_VARIANT(Field::closestCollisionEntry->attribute);

    if (Field::lookupCollisionEntry(colTypeMask, KCL_TYPE_PLAYER_WALL_CAT2)) {
      kartColInfo.wallKclType = wallKclType;
      kartColInfo.wallKclVariant = wallKclVariant;
      if ((Field::closestCollisionEntry->attribute & KCL_SOFT_WALL_MASK) != 0) {
        kartColInfo.flags |= COL_FLAG_SOFT_WALL;
      }
    }
    return true;
  } else {
    return false;
  }
}
}

# ifdef NON_MATCHING
namespace Kart {
void KartCollide::checkNeighborhood(KartCollisionInfo& kartColInfo, const Hitbox& hitbox, const Field::ColInfo& colInfo) {
  f32 colPerp = colInfo.colPerpendicularity;
  if (colPerp> 0.0f) {
    if (_68 < colPerp) {
      _68 = colPerp;
    }

    if ((kartColInfo.flags & (COL_FLAG_WALL_AT_LEFT_CLOSER | COL_FLAG_WALL_AT_RIGHT_CLOSER)) != 0) {
      if (fabs(hitbox.bsp->pos.x) > 10.0f) {
        if (colPerp > 0.0f) {
          kartColInfo.flags |= COL_FLAG_WALL_AT_LEFT_CLOSER;
        } else {
          kartColInfo.flags |= COL_FLAG_WALL_AT_RIGHT_CLOSER;
        }
        kartColInfo.colPerpendicularity = colInfo.colPerpendicularity;
      } else {
        EGG::Vector3f localRight;
        kartDynamics()->mainRot.rotateVector(RKSystem_ex, localRight);
        f32 offs[2];
        f32 sign;
        for (s32 i = 0; i < 2; i++) {
          if (i == 1) {
            sign = -1.0f;
          } else {
            sign = 1.0f;
          }
          sign *= hitbox.radius;
          EGG::Vector3f offset = hitbox.pos + localRight * sign;
          ColInfoPartial tmpInfo;
          tmpInfo.bboxLow.setZero();
          tmpInfo.bboxHigh.setZero();
          if (CourseModel::spInstance->checkSphereCachedPartial(offset, hitbox.lastPos, KCL_TYPE_DRIVER_WALL, &tmpInfo, &lbl_808a66cc, hitbox.radius, 0)) {
            offs[i] = colInfo.tangentOff.lenSq();
          }
        }

        if (offs[0] > offs[1]) {
          kartColInfo.flags |= COL_FLAG_WALL_AT_RIGHT_CLOSER;
          kartColInfo.colPerpendicularity = colInfo.colPerpendicularity;
        } else if (offs[1] > offs[0]) {
          kartColInfo.flags |= COL_FLAG_WALL_AT_LEFT_CLOSER;
          kartColInfo.colPerpendicularity = colInfo.colPerpendicularity;
        }
      }
    }
  }
}
}
#else
// Symbol: checkNeighborhood__Q24Kart11KartCollideFRQ24Kart17KartCollisionInfoRCQ24Kart6HitboxRCQ25Field7ColInfo
// PAL: 0x8056f26c..0x8056f490
MARK_BINARY_BLOB(checkNeighborhood__Q24Kart11KartCollideFRQ24Kart17KartCollisionInfoRCQ24Kart6HitboxRCQ25Field7ColInfo, 0x8056f26c, 0x8056f490);
asm void Kart::KartCollide::checkNeighborhood(KartCollisionInfo& kartColInfo, const Hitbox& hitbox, const Field::ColInfo& colInfo) {
  #include "asm/8056f26c.s"
}
#endif

namespace Kart {
void KartCollide::processCannon(u32* colTypeMask) {
  if (Field::lookupCollisionEntry(colTypeMask, KCL_CANNON_TRIGGER_MASK)) {
    kartState()->setCannonPointId(KCL_ATTRIBUTE_VARIANT(Field::closestCollisionEntry->attribute));
    kartState()->set(KART_FLAG_CANNON_START);
  }
}
}

// Symbol: unk_8056f510
// PAL: 0x8056f510..0x8056f73c
MARK_BINARY_BLOB(unk_8056f510, 0x8056f510, 0x8056f73c);
asm UNKNOWN_FUNCTION(unk_8056f510) {
  #include "asm/8056f510.s"
}

// Symbol: unk_8056f73c
// PAL: 0x8056f73c..0x8056f7f0
MARK_BINARY_BLOB(unk_8056f73c, 0x8056f73c, 0x8056f7f0);
asm UNKNOWN_FUNCTION(unk_8056f73c) {
  #include "asm/8056f73c.s"
}

// Symbol: PlayerSub18_checkPlayerCollision
// PAL: 0x8056f7f0..0x80570d20
MARK_BINARY_BLOB(PlayerSub18_checkPlayerCollision, 0x8056f7f0, 0x80570d20);
asm UNKNOWN_FUNCTION(PlayerSub18_checkPlayerCollision) {
  #include "asm/8056f7f0.s"
}

// Symbol: unk_80570d20
// PAL: 0x80570d20..0x80570d24
MARK_BINARY_BLOB(unk_80570d20, 0x80570d20, 0x80570d24);
asm UNKNOWN_FUNCTION(unk_80570d20) {
  #include "asm/80570d20.s"
}

// Symbol: unk_80570d24
// PAL: 0x80570d24..0x80570da8
MARK_BINARY_BLOB(unk_80570d24, 0x80570d24, 0x80570da8);
asm UNKNOWN_FUNCTION(unk_80570d24) {
  #include "asm/80570d24.s"
}

// Symbol: unk_80570da8
// PAL: 0x80570da8..0x80571234
MARK_BINARY_BLOB(unk_80570da8, 0x80570da8, 0x80571234);
asm UNKNOWN_FUNCTION(unk_80570da8) {
  #include "asm/80570da8.s"
}

// Symbol: unk_80571234
// PAL: 0x80571234..0x805713b8
MARK_BINARY_BLOB(unk_80571234, 0x80571234, 0x805713b8);
asm UNKNOWN_FUNCTION(unk_80571234) {
  #include "asm/80571234.s"
}

// Symbol: unk_805713b8
// PAL: 0x805713b8..0x805713d8
MARK_BINARY_BLOB(unk_805713b8, 0x805713b8, 0x805713d8);
asm UNKNOWN_FUNCTION(unk_805713b8) {
  #include "asm/805713b8.s"
}

// Symbol: unk_805713d8
// PAL: 0x805713d8..0x805713fc
MARK_BINARY_BLOB(unk_805713d8, 0x805713d8, 0x805713fc);
asm UNKNOWN_FUNCTION(unk_805713d8) {
  #include "asm/805713d8.s"
}

// Symbol: unk_805713fc
// PAL: 0x805713fc..0x80571484
MARK_BINARY_BLOB(unk_805713fc, 0x805713fc, 0x80571484);
asm UNKNOWN_FUNCTION(unk_805713fc) {
  #include "asm/805713fc.s"
}

// Symbol: unk_80571484
// PAL: 0x80571484..0x80571570
MARK_BINARY_BLOB(unk_80571484, 0x80571484, 0x80571570);
asm UNKNOWN_FUNCTION(unk_80571484) {
  #include "asm/80571484.s"
}

// Symbol: unk_80571570
// PAL: 0x80571570..0x805715f4
MARK_BINARY_BLOB(unk_80571570, 0x80571570, 0x805715f4);
asm UNKNOWN_FUNCTION(unk_80571570) {
  #include "asm/80571570.s"
}

// Symbol: unk_805715f4
// PAL: 0x805715f4..0x80571634
MARK_BINARY_BLOB(unk_805715f4, 0x805715f4, 0x80571634);
asm UNKNOWN_FUNCTION(unk_805715f4) {
  #include "asm/805715f4.s"
}

// Symbol: PlayerSub18_checkOob
// PAL: 0x80571634..0x805718d4
MARK_BINARY_BLOB(PlayerSub18_checkOob, 0x80571634, 0x805718d4);
asm UNKNOWN_FUNCTION(PlayerSub18_checkOob) {
  #include "asm/80571634.s"
}

// Symbol: unk_805718d4
// PAL: 0x805718d4..0x80571c5c
MARK_BINARY_BLOB(unk_805718d4, 0x805718d4, 0x80571c5c);
asm UNKNOWN_FUNCTION(unk_805718d4) {
  #include "asm/805718d4.s"
}

// Symbol: unk_80571c5c
// PAL: 0x80571c5c..0x80571d04
MARK_BINARY_BLOB(unk_80571c5c, 0x80571c5c, 0x80571d04);
asm UNKNOWN_FUNCTION(unk_80571c5c) {
  #include "asm/80571c5c.s"
}

// Symbol: unk_80571d04
// PAL: 0x80571d04..0x80571d98
MARK_BINARY_BLOB(unk_80571d04, 0x80571d04, 0x80571d98);
asm UNKNOWN_FUNCTION(unk_80571d04) {
  #include "asm/80571d04.s"
}

// Symbol: unk_80571d98
// PAL: 0x80571d98..0x80571f10
MARK_BINARY_BLOB(unk_80571d98, 0x80571d98, 0x80571f10);
asm UNKNOWN_FUNCTION(unk_80571d98) {
  #include "asm/80571d98.s"
}

// Symbol: unk_80571f10
// PAL: 0x80571f10..0x80572544
MARK_BINARY_BLOB(unk_80571f10, 0x80571f10, 0x80572544);
asm UNKNOWN_FUNCTION(unk_80571f10) {
  #include "asm/80571f10.s"
}

// Symbol: unk_80572544
// PAL: 0x80572544..0x80572574
MARK_BINARY_BLOB(unk_80572544, 0x80572544, 0x80572574);
asm UNKNOWN_FUNCTION(unk_80572544) {
  #include "asm/80572544.s"
}

// Symbol: Object_getId
// PAL: 0x80572574..0x8057257c
MARK_BINARY_BLOB(Object_getId, 0x80572574, 0x8057257c);
asm UNKNOWN_FUNCTION(Object_getId) {
  #include "asm/80572574.s"
}

// Symbol: PlayerSub18_checkItemCollision
// PAL: 0x8057257c..0x80572b94
MARK_BINARY_BLOB(PlayerSub18_checkItemCollision, 0x8057257c, 0x80572b94);
asm UNKNOWN_FUNCTION(PlayerSub18_checkItemCollision) {
  #include "asm/8057257c.s"
}

// Symbol: unk_80572b94
// PAL: 0x80572b94..0x80572c20
MARK_BINARY_BLOB(unk_80572b94, 0x80572b94, 0x80572c20);
asm UNKNOWN_FUNCTION(unk_80572b94) {
  #include "asm/80572b94.s"
}

// Symbol: PlayerSub18_findCollision
// PAL: 0x80572c20..0x80572f4c
MARK_BINARY_BLOB(PlayerSub18_findCollision, 0x80572c20, 0x80572f4c);
asm UNKNOWN_FUNCTION(PlayerSub18_findCollision) {
  #include "asm/80572c20.s"
}

// Symbol: unk_80572f4c
// PAL: 0x80572f4c..0x805730d4
MARK_BINARY_BLOB(unk_80572f4c, 0x80572f4c, 0x805730d4);
asm UNKNOWN_FUNCTION(unk_80572f4c) {
  #include "asm/80572f4c.s"
}

// Symbol: PlayerSub18_initHitboxes
// PAL: 0x805730d4..0x80573170
MARK_BINARY_BLOB(PlayerSub18_initHitboxes, 0x805730d4, 0x80573170);
asm UNKNOWN_FUNCTION(PlayerSub18_initHitboxes) {
  #include "asm/805730d4.s"
}

// Symbol: PlayerSub18_handleNoopCollision
// PAL: 0x80573170..0x80573178
MARK_BINARY_BLOB(PlayerSub18_handleNoopCollision, 0x80573170, 0x80573178);
asm UNKNOWN_FUNCTION(PlayerSub18_handleNoopCollision) {
  #include "asm/80573170.s"
}

// Symbol: PlayerSub18_handleBananaCollision
// PAL: 0x80573178..0x80573190
MARK_BINARY_BLOB(PlayerSub18_handleBananaCollision, 0x80573178, 0x80573190);
asm UNKNOWN_FUNCTION(PlayerSub18_handleBananaCollision) {
  #include "asm/80573178.s"
}

// Symbol: PlayerSub18_handleShellCollision
// PAL: 0x80573190..0x805731b0
MARK_BINARY_BLOB(PlayerSub18_handleShellCollision, 0x80573190, 0x805731b0);
asm UNKNOWN_FUNCTION(PlayerSub18_handleShellCollision) {
  #include "asm/80573190.s"
}

// Symbol: PlayerSub18_handleBlueShellCollision
// PAL: 0x805731b0..0x805731c8
MARK_BINARY_BLOB(PlayerSub18_handleBlueShellCollision, 0x805731b0, 0x805731c8);
asm UNKNOWN_FUNCTION(PlayerSub18_handleBlueShellCollision) {
  #include "asm/805731b0.s"
}

// Symbol: PlayerSub18_handleBombCollision
// PAL: 0x805731c8..0x805731e0
MARK_BINARY_BLOB(PlayerSub18_handleBombCollision, 0x805731c8, 0x805731e0);
asm UNKNOWN_FUNCTION(PlayerSub18_handleBombCollision) {
  #include "asm/805731c8.s"
}

// Symbol: PlayerSub18_handleMushroomCollision
// PAL: 0x805731e0..0x80573224
MARK_BINARY_BLOB(PlayerSub18_handleMushroomCollision, 0x805731e0, 0x80573224);
asm UNKNOWN_FUNCTION(PlayerSub18_handleMushroomCollision) {
  #include "asm/805731e0.s"
}

// Symbol: PlayerSub18_handleStarCollision
// PAL: 0x80573224..0x8057325c
MARK_BINARY_BLOB(PlayerSub18_handleStarCollision, 0x80573224, 0x8057325c);
asm UNKNOWN_FUNCTION(PlayerSub18_handleStarCollision) {
  #include "asm/80573224.s"
}

// Symbol: PlayerSub18_handleFibCollision
// PAL: 0x8057325c..0x805733c4
MARK_BINARY_BLOB(PlayerSub18_handleFibCollision, 0x8057325c, 0x805733c4);
asm UNKNOWN_FUNCTION(PlayerSub18_handleFibCollision) {
  #include "asm/8057325c.s"
}

// Symbol: unk_805733c4
// PAL: 0x805733c4..0x805733cc
MARK_BINARY_BLOB(unk_805733c4, 0x805733c4, 0x805733cc);
asm UNKNOWN_FUNCTION(unk_805733c4) {
  #include "asm/805733c4.s"
}

// Symbol: unk_805733cc
// PAL: 0x805733cc..0x805733d4
MARK_BINARY_BLOB(unk_805733cc, 0x805733cc, 0x805733d4);
asm UNKNOWN_FUNCTION(unk_805733cc) {
  #include "asm/805733cc.s"
}

// Symbol: unk_805733d4
// PAL: 0x805733d4..0x805733dc
MARK_BINARY_BLOB(unk_805733d4, 0x805733d4, 0x805733dc);
asm UNKNOWN_FUNCTION(unk_805733d4) {
  #include "asm/805733d4.s"
}

// Symbol: unk_805733dc
// PAL: 0x805733dc..0x805733e4
MARK_BINARY_BLOB(unk_805733dc, 0x805733dc, 0x805733e4);
asm UNKNOWN_FUNCTION(unk_805733dc) {
  #include "asm/805733dc.s"
}

// Symbol: unk_805733e4
// PAL: 0x805733e4..0x805733ec
MARK_BINARY_BLOB(unk_805733e4, 0x805733e4, 0x805733ec);
asm UNKNOWN_FUNCTION(unk_805733e4) {
  #include "asm/805733e4.s"
}

// Symbol: unk_805733ec
// PAL: 0x805733ec..0x805733f4
MARK_BINARY_BLOB(unk_805733ec, 0x805733ec, 0x805733f4);
asm UNKNOWN_FUNCTION(unk_805733ec) {
  #include "asm/805733ec.s"
}

// Symbol: unk_805733f4
// PAL: 0x805733f4..0x80573464
MARK_BINARY_BLOB(unk_805733f4, 0x805733f4, 0x80573464);
asm UNKNOWN_FUNCTION(unk_805733f4) {
  #include "asm/805733f4.s"
}

// Symbol: unk_80573464
// PAL: 0x80573464..0x80573518
MARK_BINARY_BLOB(unk_80573464, 0x80573464, 0x80573518);
asm UNKNOWN_FUNCTION(unk_80573464) {
  #include "asm/80573464.s"
}

// Symbol: unk_80573518
// PAL: 0x80573518..0x80573520
MARK_BINARY_BLOB(unk_80573518, 0x80573518, 0x80573520);
asm UNKNOWN_FUNCTION(unk_80573518) {
  #include "asm/80573518.s"
}

// Symbol: unk_80573520
// PAL: 0x80573520..0x8057353c
MARK_BINARY_BLOB(unk_80573520, 0x80573520, 0x8057353c);
asm UNKNOWN_FUNCTION(unk_80573520) {
  #include "asm/80573520.s"
}

// Symbol: unk_8057353c
// PAL: 0x8057353c..0x805735ac
MARK_BINARY_BLOB(unk_8057353c, 0x8057353c, 0x805735ac);
asm UNKNOWN_FUNCTION(unk_8057353c) {
  #include "asm/8057353c.s"
}

// Symbol: unk_805735ac
// PAL: 0x805735ac..0x805735b4
MARK_BINARY_BLOB(unk_805735ac, 0x805735ac, 0x805735b4);
asm UNKNOWN_FUNCTION(unk_805735ac) {
  #include "asm/805735ac.s"
}

// Symbol: unk_805735b4
// PAL: 0x805735b4..0x805735bc
MARK_BINARY_BLOB(unk_805735b4, 0x805735b4, 0x805735bc);
asm UNKNOWN_FUNCTION(unk_805735b4) {
  #include "asm/805735b4.s"
}

// Symbol: unk_805735bc
// PAL: 0x805735bc..0x805735d4
MARK_BINARY_BLOB(unk_805735bc, 0x805735bc, 0x805735d4);
asm UNKNOWN_FUNCTION(unk_805735bc) {
  #include "asm/805735bc.s"
}

// Symbol: unk_805735d4
// PAL: 0x805735d4..0x805735dc
MARK_BINARY_BLOB(unk_805735d4, 0x805735d4, 0x805735dc);
asm UNKNOWN_FUNCTION(unk_805735d4) {
  #include "asm/805735d4.s"
}

// Symbol: unk_805735dc
// PAL: 0x805735dc..0x805735e4
MARK_BINARY_BLOB(unk_805735dc, 0x805735dc, 0x805735e4);
asm UNKNOWN_FUNCTION(unk_805735dc) {
  #include "asm/805735dc.s"
}

// Symbol: unk_805735e4
// PAL: 0x805735e4..0x805735ec
MARK_BINARY_BLOB(unk_805735e4, 0x805735e4, 0x805735ec);
asm UNKNOWN_FUNCTION(unk_805735e4) {
  #include "asm/805735e4.s"
}

// Symbol: unk_805735ec
// PAL: 0x805735ec..0x8057363c
MARK_BINARY_BLOB(unk_805735ec, 0x805735ec, 0x8057363c);
asm UNKNOWN_FUNCTION(unk_805735ec) {
  #include "asm/805735ec.s"
}

// Symbol: unk_8057363c
// PAL: 0x8057363c..0x805736c8
MARK_BINARY_BLOB(unk_8057363c, 0x8057363c, 0x805736c8);
asm UNKNOWN_FUNCTION(unk_8057363c) {
  #include "asm/8057363c.s"
}

// Symbol: unk_805736c8
// PAL: 0x805736c8..0x80573754
MARK_BINARY_BLOB(unk_805736c8, 0x805736c8, 0x80573754);
asm UNKNOWN_FUNCTION(unk_805736c8) {
  #include "asm/805736c8.s"
}

// Symbol: unk_80573754
// PAL: 0x80573754..0x80573790
MARK_BINARY_BLOB(unk_80573754, 0x80573754, 0x80573790);
asm UNKNOWN_FUNCTION(unk_80573754) {
  #include "asm/80573754.s"
}

// Symbol: unk_80573790
// PAL: 0x80573790..0x805737b8
MARK_BINARY_BLOB(unk_80573790, 0x80573790, 0x805737b8);
asm UNKNOWN_FUNCTION(unk_80573790) {
  #include "asm/80573790.s"
}

// Symbol: unk_805737b8
// PAL: 0x805737b8..0x80573824
MARK_BINARY_BLOB(unk_805737b8, 0x805737b8, 0x80573824);
asm UNKNOWN_FUNCTION(unk_805737b8) {
  #include "asm/805737b8.s"
}

// Symbol: unk_80573824
// PAL: 0x80573824..0x80573a2c
MARK_BINARY_BLOB(unk_80573824, 0x80573824, 0x80573a2c);
asm UNKNOWN_FUNCTION(unk_80573824) {
  #include "asm/80573824.s"
}

// Symbol: unk_80573a2c
// PAL: 0x80573a2c..0x80573b00
MARK_BINARY_BLOB(unk_80573a2c, 0x80573a2c, 0x80573b00);
asm UNKNOWN_FUNCTION(unk_80573a2c) {
  #include "asm/80573a2c.s"
}

// Symbol: PlayerSub18_activateOob
// PAL: 0x80573b00..0x80573ec4
MARK_BINARY_BLOB(PlayerSub18_activateOob, 0x80573b00, 0x80573ec4);
asm UNKNOWN_FUNCTION(PlayerSub18_activateOob) {
  #include "asm/80573b00.s"
}

// Symbol: unk_80573ec4
// PAL: 0x80573ec4..0x80573ed4
MARK_BINARY_BLOB(unk_80573ec4, 0x80573ec4, 0x80573ed4);
asm UNKNOWN_FUNCTION(unk_80573ec4) {
  #include "asm/80573ec4.s"
}

// Symbol: PlayerSub18_updateRespawn
// PAL: 0x80573ed4..0x80573ff0
MARK_BINARY_BLOB(PlayerSub18_updateRespawn, 0x80573ed4, 0x80573ff0);
asm UNKNOWN_FUNCTION(PlayerSub18_updateRespawn) {
  #include "asm/80573ed4.s"
}

