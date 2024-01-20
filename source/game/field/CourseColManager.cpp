#include "CourseColManager.hpp"

// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern function references.
// PAL: 0x80021450
extern UNKNOWN_FUNCTION(__ptmf_scall);
// PAL: 0x80021584
extern UNKNOWN_FUNCTION(_savegpr_20);
// PAL: 0x8002158c
extern UNKNOWN_FUNCTION(_savegpr_22);
// PAL: 0x8002159c
extern UNKNOWN_FUNCTION(_savegpr_26);
// PAL: 0x800215d0
extern UNKNOWN_FUNCTION(_restgpr_20);
// PAL: 0x800215d8
extern UNKNOWN_FUNCTION(_restgpr_22);
// PAL: 0x800215e8
extern UNKNOWN_FUNCTION(_restgpr_26);
// PAL: 0x80085580
extern UNKNOWN_FUNCTION(VEC3Maximize__Q24nw4r4mathFPQ34nw4r4math4VEC3PCQ34nw4r4math4VEC3PCQ34nw4r4math4VEC3);
// PAL: 0x800855c0
extern UNKNOWN_FUNCTION(VEC3Minimize__Q24nw4r4mathFPQ34nw4r4math4VEC3PCQ34nw4r4math4VEC3PCQ34nw4r4math4VEC3);
// PAL: 0x80085ab0
extern UNKNOWN_FUNCTION(VEC3TransformNormal__Q24nw4r4mathFPQ34nw4r4math4VEC3PCQ34nw4r4math5MTX34PCQ34nw4r4math4VEC3);
// PAL: 0x807bda9c
extern UNKNOWN_FUNCTION(pushCollisionEntry__FfPUlUlUs);
// PAL: 0x807bdc5c
extern UNKNOWN_FUNCTION(__ct__Q25Field8RKGndColFRCQ25Field16KCollisionHeader);
// PAL: 0x807bddbc
extern UNKNOWN_FUNCTION(__dt__Q25Field8RKGndColFv);
// PAL: 0x807c1b0c
extern UNKNOWN_FUNCTION(prepareCollisionTest__Q25Field8RKGndColFRCQ23EGG8Vector3fRCQ23EGG8Vector3fUl);
// PAL: 0x807c1bb4
extern UNKNOWN_FUNCTION(prepareCollisionTestSphere__Q25Field8RKGndColFRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlf);
// PAL: 0x807c1c8c
extern UNKNOWN_FUNCTION(lookupPointCached__Q25Field8RKGndColFRCQ23EGG8Vector3fRCQ23EGG8Vector3fUl);
// PAL: 0x807c1de8
extern UNKNOWN_FUNCTION(lookupSphereCached__Q25Field8RKGndColFRCQ23EGG8Vector3fRCQ23EGG8Vector3ffUl);
// PAL: 0x807c1f80
extern UNKNOWN_FUNCTION(checkPointCollision__Q25Field8RKGndColFPfPQ23EGG8Vector3fPUs);
// PAL: 0x807c2410
extern UNKNOWN_FUNCTION(checkSphereCollision__Q25Field8RKGndColFPfPQ23EGG8Vector3fPUs);
// PAL: 0x807c2bd8
extern UNKNOWN_FUNCTION(doCheckWithPartialInfo__Q25Field16CourseColManagerFPQ25Field8RKGndColMQ25Field8RKGndColFPCvPvPfPQ23EGG8Vector3fPUs_bPQ25Field14ColInfoPartialPUl);
// PAL: 0x807c2f18
extern UNKNOWN_FUNCTION(doCheckWithPartialInfoPush__Q25Field16CourseColManagerFPQ25Field8RKGndColMQ25Field8RKGndColFPCvPvPfPQ23EGG8Vector3fPUs_bPQ25Field14ColInfoPartialPUl);
// PAL: 0x807c3258
extern UNKNOWN_FUNCTION(doCheckWithFullInfo__Q25Field16CourseColManagerFPQ25Field8RKGndColMQ25Field8RKGndColFPCvPvPfPQ23EGG8Vector3fPUs_bPQ25Field11ColInfoFullPUl);
// PAL: 0x807c36cc
extern UNKNOWN_FUNCTION(doCheckWithFullInfoPush__Q25Field16CourseColManagerFPQ25Field8RKGndColMQ25Field8RKGndColFPCvPvPfPQ23EGG8Vector3fPUs_bPQ25Field11ColInfoFullPUl);
}

// --- EXTERN DECLARATIONS END ---

// .rodata
extern const u32 lbl_808a6710;
const u32 lbl_808a6710 = 0;
/*const u32 lbl_808a6714[] = {
    0x3f800000
};*/
extern "C" const f32 lbl_808a6714; //1.0f
REL_SYMBOL_AT(lbl_808a6714, 0x808a6714);
extern "C" const f32 lbl_808a6718; //-FLT_MIN
REL_SYMBOL_AT(lbl_808a6718, 0x808a6718);

// .data
#pragma explicit_zero_data on
u32 lbl_808d2808[] = {
    0x00000000, 0xffffffff, (u32)&checkPointCollision__Q25Field8RKGndColFPfPQ23EGG8Vector3fPUs
};
u32 lbl_808d2814[] = {
    0x00000000, 0xffffffff, (u32)&checkPointCollision__Q25Field8RKGndColFPfPQ23EGG8Vector3fPUs
};
u32 lbl_808d2820[] = {
    0x00000000, 0xffffffff, (u32)&checkPointCollision__Q25Field8RKGndColFPfPQ23EGG8Vector3fPUs
};
u32 lbl_808d282c[] = {
    0x00000000, 0xffffffff, (u32)&checkPointCollision__Q25Field8RKGndColFPfPQ23EGG8Vector3fPUs
};
u32 lbl_808d2838[] = {
    0x00000000, 0xffffffff, (u32)&checkPointCollision__Q25Field8RKGndColFPfPQ23EGG8Vector3fPUs
};
u32 lbl_808d2844[] = {
    0x00000000, 0xffffffff, (u32)&checkPointCollision__Q25Field8RKGndColFPfPQ23EGG8Vector3fPUs
};
u32 lbl_808d2850[] = {
    0x00000000, 0xffffffff, (u32)&checkPointCollision__Q25Field8RKGndColFPfPQ23EGG8Vector3fPUs
};
u32 lbl_808d285c[] = {
    0x00000000, 0xffffffff, (u32)&checkPointCollision__Q25Field8RKGndColFPfPQ23EGG8Vector3fPUs
};
u32 lbl_808d2868[] = {
    0x00000000, 0xffffffff, (u32)&checkSphereCollision__Q25Field8RKGndColFPfPQ23EGG8Vector3fPUs
};
u32 lbl_808d2874[] = {
    0x00000000, 0xffffffff, (u32)&checkSphereCollision__Q25Field8RKGndColFPfPQ23EGG8Vector3fPUs
};
u32 lbl_808d2880[] = {
    0x00000000, 0xffffffff, (u32)&checkSphereCollision__Q25Field8RKGndColFPfPQ23EGG8Vector3fPUs
};
u32 lbl_808d288c[] = {
    0x00000000, 0xffffffff, (u32)&checkSphereCollision__Q25Field8RKGndColFPfPQ23EGG8Vector3fPUs
};
u32 lbl_808d2898[] = {
    0x00000000, 0xffffffff, (u32)&checkSphereCollision__Q25Field8RKGndColFPfPQ23EGG8Vector3fPUs
};
u32 lbl_808d28a4[] = {
    0x00000000, 0xffffffff, (u32)&checkSphereCollision__Q25Field8RKGndColFPfPQ23EGG8Vector3fPUs
};
u32 lbl_808d28b0[] = {
    0x00000000, 0xffffffff, (u32)&checkSphereCollision__Q25Field8RKGndColFPfPQ23EGG8Vector3fPUs
};
u32 lbl_808d28bc[] = {
    0x00000000, 0xffffffff, (u32)&checkSphereCollision__Q25Field8RKGndColFPfPQ23EGG8Vector3fPUs
};
u32 lbl_808d28c8[] = {
    0x00000000, 0xffffffff, (u32)&checkPointCollision__Q25Field8RKGndColFPfPQ23EGG8Vector3fPUs
};
u32 lbl_808d28d4[] = {
    0x00000000, 0xffffffff, (u32)&checkPointCollision__Q25Field8RKGndColFPfPQ23EGG8Vector3fPUs
};
u32 lbl_808d28e0[] = {
    0x00000000, 0xffffffff, (u32)&checkPointCollision__Q25Field8RKGndColFPfPQ23EGG8Vector3fPUs
};
u32 lbl_808d28ec[] = {
    0x00000000, 0xffffffff, (u32)&checkPointCollision__Q25Field8RKGndColFPfPQ23EGG8Vector3fPUs
};
u32 lbl_808d28f8[] = {
    0x00000000, 0xffffffff, (u32)&checkPointCollision__Q25Field8RKGndColFPfPQ23EGG8Vector3fPUs
};
u32 lbl_808d2904[] = {
    0x00000000, 0xffffffff, (u32)&checkPointCollision__Q25Field8RKGndColFPfPQ23EGG8Vector3fPUs
};
u32 lbl_808d2910[] = {
    0x00000000, 0xffffffff, (u32)&checkPointCollision__Q25Field8RKGndColFPfPQ23EGG8Vector3fPUs
};
u32 lbl_808d291c[] = {
    0x00000000, 0xffffffff, (u32)&checkPointCollision__Q25Field8RKGndColFPfPQ23EGG8Vector3fPUs
};
u32 lbl_808d2928[] = {
    0x00000000, 0xffffffff, (u32)&checkSphereCollision__Q25Field8RKGndColFPfPQ23EGG8Vector3fPUs
};
u32 lbl_808d2934[] = {
    0x00000000, 0xffffffff, (u32)&checkSphereCollision__Q25Field8RKGndColFPfPQ23EGG8Vector3fPUs
};
u32 lbl_808d2940[] = {
    0x00000000, 0xffffffff, (u32)&checkSphereCollision__Q25Field8RKGndColFPfPQ23EGG8Vector3fPUs
};
u32 lbl_808d294c[] = {
    0x00000000, 0xffffffff, (u32)&checkSphereCollision__Q25Field8RKGndColFPfPQ23EGG8Vector3fPUs
};
u32 lbl_808d2958[] = {
    0x00000000, 0xffffffff, (u32)&checkSphereCollision__Q25Field8RKGndColFPfPQ23EGG8Vector3fPUs
};
u32 lbl_808d2964[] = {
    0x00000000, 0xffffffff, (u32)&checkSphereCollision__Q25Field8RKGndColFPfPQ23EGG8Vector3fPUs
};
u32 lbl_808d2970[] = {
    0x00000000, 0xffffffff, (u32)&checkSphereCollision__Q25Field8RKGndColFPfPQ23EGG8Vector3fPUs
};
u32 lbl_808d297c[] = {
    0x00000000, 0xffffffff, (u32)&checkSphereCollision__Q25Field8RKGndColFPfPQ23EGG8Vector3fPUs
};
#pragma explicit_zero_data off

namespace Field {
CourseColManager* CourseColManager::spInstance;

void CourseColManager::createInstance() {
  if (!spInstance) {
    spInstance = new CourseColManager;
  }
}

void CourseColManager::destroyInstance() {
  delete spInstance;
  spInstance = nullptr;
}

void CourseColManager::init(const KCollisionHeader& header) {
  this->colMgr = new RKGndCol(header);
}
f32 CourseColManager::setThickness(RKGndCol* colMgr) {
  if (colMgr == nullptr)
    colMgr = this->colMgr;
  return colMgr->getPrismThickness();
}

void CourseColManager::scaledNarrowScopeLocal(RKGndCol* colMgr, const EGG::Vector3f& pos, u32 typeMask, f32 scale, f32 radius, u32 unused) {
  EGG::Vector3f scaledPos;
  f32 scaleInv = 1.0f / scale;
  if (colMgr == nullptr)
    colMgr = this->colMgr;

  VECScale(reinterpret_cast<Vec*>(const_cast<EGG::Vector3f*>(&pos)), reinterpret_cast<Vec*>(&scaledPos), scaleInv);
  radius *= scaleInv;
  colMgr->narrowScopeLocal(scaledPos, radius, typeMask, unused);
}
}

namespace Field {
CourseColManager::CourseColManager() {
  this->colMgr = nullptr;
  this->kclScale = 1.0f;
  this->softWallColInfo = nullptr;
  this->localMtx = nullptr;
}

CourseColManager::~CourseColManager() { delete colMgr; }
}

/*const u32 lbl_808a6718[] = {
    0x80800000
};*/

// Symbol: unk_807c2a60
// PAL: 0x807c2a60..0x807c2bd8
MARK_BINARY_BLOB(unk_807c2a60, 0x807c2a60, 0x807c2bd8);
asm UNKNOWN_FUNCTION(unk_807c2a60) {
  #include "asm/807c2a60.s"
}

namespace Field {
bool CourseColManager::doCheckWithPartialInfo(RKGndCol* colMgr, CollisionCheckFunc collisionCheckFunc, ColInfoPartial* colInfoPartial, u32* typeMask) {
  f32 dist;
  EGG::Vector3f fnrm;
  u16 attribute;

  bool hasCol = false;

  while((colMgr->*collisionCheckFunc)(&dist, &fnrm, &attribute)) {
    dist *= this->kclScale;
    EGG::Vector3f offset;

    if (this->softWallColInfo != nullptr && (attribute & KCL_SOFT_WALL_MASK) != 0) {
      if (this->localMtx != nullptr) {
        nw4r::math::VEC3TransformNormal(&fnrm, this->localMtx, &fnrm);
      }

      nw4r::math::VEC3Scale(&offset, &fnrm, dist);
      this->softWallColInfo->update(dist, offset, fnrm);

      hasCol = true;
    } else {
      u32 kclAttributeTypeBit = KCL_ATTRIBUTE_TYPE_BIT(attribute);
      if (typeMask != nullptr) {
        *typeMask |= kclAttributeTypeBit;
      }
      if ((kclAttributeTypeBit & KCL_TYPE_SOLID_SURFACE) != 0) {
        nw4r::math::VEC3Scale(&offset, &fnrm, dist);
        nw4r::math::VEC3Minimize(&colInfoPartial->bboxLow, &colInfoPartial->bboxLow, &offset);
        nw4r::math::VEC3Maximize(&colInfoPartial->bboxHigh, &colInfoPartial->bboxHigh, &offset);
      }
      hasCol = true;
    }
  }
  this->localMtx = nullptr;

  return hasCol;
}
}

// Symbol: unk_807c2da0
// PAL: 0x807c2da0..0x807c2f18
MARK_BINARY_BLOB(unk_807c2da0, 0x807c2da0, 0x807c2f18);
asm UNKNOWN_FUNCTION(unk_807c2da0) {
  #include "asm/807c2da0.s"
}

namespace Field {
bool CourseColManager::doCheckWithPartialInfoPush(RKGndCol* colMgr, CollisionCheckFunc collisionCheckFunc, ColInfoPartial* colInfoPartial, u32* typeMask) {
  f32 dist;
  EGG::Vector3f fnrm;
  u16 attribute;

  bool hasCol = false;

  while((colMgr->*collisionCheckFunc)(&dist, &fnrm, &attribute)) {
    dist *= this->kclScale;
    EGG::Vector3f offset;

    if (this->softWallColInfo != nullptr && (attribute & KCL_SOFT_WALL_MASK) != 0) {
      if (this->localMtx != nullptr) {
        nw4r::math::VEC3TransformNormal(&fnrm, this->localMtx, &fnrm);
      }
      nw4r::math::VEC3Scale(&offset, &fnrm, dist);
      this->softWallColInfo->update(dist, offset, fnrm);

      hasCol = true;
    } else {
      u32 kclAttributeTypeBit = KCL_ATTRIBUTE_TYPE_BIT(attribute);
      if (typeMask != nullptr) {
        pushCollisionEntry(dist, typeMask, kclAttributeTypeBit, attribute);
      }
      if ((kclAttributeTypeBit & KCL_TYPE_SOLID_SURFACE) != 0) {
        nw4r::math::VEC3Scale(&offset, &fnrm, dist);
        nw4r::math::VEC3Minimize(&colInfoPartial->bboxLow, &colInfoPartial->bboxLow, &offset);
        nw4r::math::VEC3Maximize(&colInfoPartial->bboxHigh, &colInfoPartial->bboxHigh, &offset);
      }
      hasCol = true;
    }
  }
  this->localMtx = nullptr;

  return hasCol;
}
}

// Symbol: unk_807c30e0
// PAL: 0x807c30e0..0x807c3258
MARK_BINARY_BLOB(unk_807c30e0, 0x807c30e0, 0x807c3258);
asm UNKNOWN_FUNCTION(unk_807c30e0) {
  #include "asm/807c30e0.s"
}

/*// Symbol: doCheckWithFullInfo__Q25Field16CourseColManagerFPQ25Field8RKGndColMQ25Field8RKGndColFPCvPvPfPQ23EGG8Vector3fPUs_bPQ25Field11ColInfoFullPUl
// PAL: 0x807c3258..0x807c3554
MARK_BINARY_BLOB(doCheckWithFullInfo__Q25Field16CourseColManagerFPQ25Field8RKGndColMQ25Field8RKGndColFPCvPvPfPQ23EGG8Vector3fPUs_bPQ25Field11ColInfoFullPUl, 0x807c3258, 0x807c3554);
asm UNKNOWN_FUNCTION(doCheckWithFullInfo__Q25Field16CourseColManagerFPQ25Field8RKGndColMQ25Field8RKGndColFPCvPvPfPQ23EGG8Vector3fPUs_bPQ25Field11ColInfoFullPUl) {
  #include "asm/807c3258.s"
}*/
namespace Field {
bool CourseColManager::doCheckWithFullInfo(RKGndCol* colMgr, CollisionCheckFunc collisionCheckFunc, ColInfoFull* colInfo, u32* typeMask) {
  f32 dist;
  EGG::Vector3f fnrm;
  u16 attribute;

  bool hasCol = false;

  while((colMgr->*collisionCheckFunc)(&dist, &fnrm, &attribute)) {
    dist *= this->kclScale;
    EGG::Vector3f offset;

    if (this->softWallColInfo != nullptr && (attribute & KCL_SOFT_WALL_MASK) != 0) {
      if (this->localMtx != nullptr) {
        nw4r::math::VEC3TransformNormal(&fnrm, this->localMtx, &fnrm);
      }

      nw4r::math::VEC3Scale(&offset, &fnrm, dist);
      this->softWallColInfo->update(dist, offset, fnrm);

      hasCol = true;
    } else {
      u32 kclAttributeTypeBit = KCL_ATTRIBUTE_TYPE_BIT(attribute);
      if (typeMask != nullptr) {
        *typeMask |= kclAttributeTypeBit;
      }
      if ((kclAttributeTypeBit & KCL_TYPE_SOLID_SURFACE) != 0) {
        nw4r::math::VEC3Scale(&offset, &fnrm, dist);
        colInfo->update(dist, offset, fnrm, kclAttributeTypeBit);
      }
      hasCol = true;
    }
  }
  this->localMtx = nullptr;
  return hasCol;
}
}

// Symbol: unk_807c3554
// PAL: 0x807c3554..0x807c36cc
MARK_BINARY_BLOB(unk_807c3554, 0x807c3554, 0x807c36cc);
asm UNKNOWN_FUNCTION(unk_807c3554) {
  #include "asm/807c3554.s"
}

namespace Field {
bool CourseColManager::doCheckWithFullInfoPush(RKGndCol* colMgr, CollisionCheckFunc collisionCheckFunc, ColInfoFull* colInfo, u32* typeMask) {
  f32 dist;
  EGG::Vector3f fnrm;
  u16 attribute;

  bool hasCol = false;

  while((colMgr->*collisionCheckFunc)(&dist, &fnrm, &attribute)) {
    dist *= this->kclScale;
    EGG::Vector3f offset;

    if (this->softWallColInfo != nullptr && (attribute & KCL_SOFT_WALL_MASK) != 0) {
      if (this->localMtx != nullptr) {
        nw4r::math::VEC3TransformNormal(&fnrm, this->localMtx, &fnrm);
      }

      nw4r::math::VEC3Scale(&offset, &fnrm, dist);
      this->softWallColInfo->update(dist, offset, fnrm);

      hasCol = true;
    } else {
      u32 kclAttributeTypeBit = KCL_ATTRIBUTE_TYPE_BIT(attribute);
      if (typeMask != nullptr) {
        pushCollisionEntry(dist, typeMask, kclAttributeTypeBit, attribute);
      }
      if ((kclAttributeTypeBit & KCL_TYPE_SOLID_SURFACE) != 0) {
        nw4r::math::VEC3Scale(&offset, &fnrm, dist);
        colInfo->update(dist, offset, fnrm, kclAttributeTypeBit);
      }
      hasCol = true;
    }
  }
  this->localMtx = nullptr;
  return hasCol;
}
}

// Symbol: unk_807c39c8
// PAL: 0x807c39c8..0x807c3b5c
MARK_BINARY_BLOB(unk_807c39c8, 0x807c39c8, 0x807c3b5c);
asm UNKNOWN_FUNCTION(unk_807c39c8) {
  #include "asm/807c39c8.s"
}

// Symbol: unk_807c3b5c
// PAL: 0x807c3b5c..0x807c3cf0
MARK_BINARY_BLOB(unk_807c3b5c, 0x807c3b5c, 0x807c3cf0);
asm UNKNOWN_FUNCTION(unk_807c3b5c) {
  #include "asm/807c3b5c.s"
}

// Symbol: unk_807c3cf0
// PAL: 0x807c3cf0..0x807c3e84
MARK_BINARY_BLOB(unk_807c3cf0, 0x807c3cf0, 0x807c3e84);
asm UNKNOWN_FUNCTION(unk_807c3cf0) {
  #include "asm/807c3cf0.s"
}

// Symbol: unk_807c3e84
// PAL: 0x807c3e84..0x807c4018
MARK_BINARY_BLOB(unk_807c3e84, 0x807c3e84, 0x807c4018);
asm UNKNOWN_FUNCTION(unk_807c3e84) {
  #include "asm/807c3e84.s"
}

// Symbol: unk_807c4018
// PAL: 0x807c4018..0x807c41a4
MARK_BINARY_BLOB(unk_807c4018, 0x807c4018, 0x807c41a4);
asm UNKNOWN_FUNCTION(unk_807c4018) {
  #include "asm/807c4018.s"
}

// Symbol: unk_807c41a4
// PAL: 0x807c41a4..0x807c4330
MARK_BINARY_BLOB(unk_807c41a4, 0x807c41a4, 0x807c4330);
asm UNKNOWN_FUNCTION(unk_807c41a4) {
  #include "asm/807c41a4.s"
}

// Symbol: unk_807c4330
// PAL: 0x807c4330..0x807c44bc
MARK_BINARY_BLOB(unk_807c4330, 0x807c4330, 0x807c44bc);
asm UNKNOWN_FUNCTION(unk_807c4330) {
  #include "asm/807c4330.s"
}

// Symbol: unk_807c44bc
// PAL: 0x807c44bc..0x807c4648
MARK_BINARY_BLOB(unk_807c44bc, 0x807c44bc, 0x807c4648);
asm UNKNOWN_FUNCTION(unk_807c44bc) {
  #include "asm/807c44bc.s"
}

// Symbol: unk_807c4648
// PAL: 0x807c4648..0x807c47f0
MARK_BINARY_BLOB(unk_807c4648, 0x807c4648, 0x807c47f0);
asm UNKNOWN_FUNCTION(unk_807c4648) {
  #include "asm/807c4648.s"
}

// Symbol: unk_807c47f0
// PAL: 0x807c47f0..0x807c4998
MARK_BINARY_BLOB(unk_807c47f0, 0x807c47f0, 0x807c4998);
asm UNKNOWN_FUNCTION(unk_807c47f0) {
  #include "asm/807c47f0.s"
}

// Symbol: unk_807c4998
// PAL: 0x807c4998..0x807c4b40
MARK_BINARY_BLOB(unk_807c4998, 0x807c4998, 0x807c4b40);
asm UNKNOWN_FUNCTION(unk_807c4998) {
  #include "asm/807c4998.s"
}

// Symbol: unk_807c4b40
// PAL: 0x807c4b40..0x807c4ce8
MARK_BINARY_BLOB(unk_807c4b40, 0x807c4b40, 0x807c4ce8);
asm UNKNOWN_FUNCTION(unk_807c4b40) {
  #include "asm/807c4b40.s"
}

