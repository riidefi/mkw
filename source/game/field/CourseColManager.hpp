#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x807c2a60..0x807c2bd8
UNKNOWN_FUNCTION(unk_807c2a60);
// PAL: 0x807c2bd8..0x807c2da0
UNKNOWN_FUNCTION(doCheckWithPartialInfo__Q25Field16CourseColManagerFPQ25Field8RKGndColMQ25Field8RKGndColFPCvPvPfPQ23EGG8Vector3fPUs_bPQ25Field14ColInfoPartialPUl);
// PAL: 0x807c2da0..0x807c2f18
UNKNOWN_FUNCTION(unk_807c2da0);
// PAL: 0x807c2f18..0x807c30e0
UNKNOWN_FUNCTION(doCheckWithPartialInfoPush__Q25Field16CourseColManagerFPQ25Field8RKGndColMQ25Field8RKGndColFPCvPvPfPQ23EGG8Vector3fPUs_bPQ25Field14ColInfoPartialPUl);
// PAL: 0x807c30e0..0x807c3258
UNKNOWN_FUNCTION(unk_807c30e0);
// PAL: 0x807c3258..0x807c3554
UNKNOWN_FUNCTION(doCheckWithFullInfo__Q25Field16CourseColManagerFPQ25Field8RKGndColMQ25Field8RKGndColFPCvPvPfPQ23EGG8Vector3fPUs_bPQ25Field11ColInfoFullPUl);
// PAL: 0x807c3554..0x807c36cc
UNKNOWN_FUNCTION(unk_807c3554);
// PAL: 0x807c36cc..0x807c39c8
UNKNOWN_FUNCTION(doCheckWithFullInfoPush__Q25Field16CourseColManagerFPQ25Field8RKGndColMQ25Field8RKGndColFPCvPvPfPQ23EGG8Vector3fPUs_bPQ25Field11ColInfoFullPUl);
// PAL: 0x807c39c8..0x807c3b5c
UNKNOWN_FUNCTION(unk_807c39c8);
// PAL: 0x807c3b5c..0x807c3cf0
UNKNOWN_FUNCTION(unk_807c3b5c);
// PAL: 0x807c3cf0..0x807c3e84
UNKNOWN_FUNCTION(unk_807c3cf0);
// PAL: 0x807c3e84..0x807c4018
UNKNOWN_FUNCTION(unk_807c3e84);
// PAL: 0x807c4018..0x807c41a4
UNKNOWN_FUNCTION(unk_807c4018);
// PAL: 0x807c41a4..0x807c4330
UNKNOWN_FUNCTION(unk_807c41a4);
// PAL: 0x807c4330..0x807c44bc
UNKNOWN_FUNCTION(unk_807c4330);
// PAL: 0x807c44bc..0x807c4648
UNKNOWN_FUNCTION(unk_807c44bc);
// PAL: 0x807c4648..0x807c47f0
UNKNOWN_FUNCTION(unk_807c4648);
// PAL: 0x807c47f0..0x807c4998
UNKNOWN_FUNCTION(unk_807c47f0);
// PAL: 0x807c4998..0x807c4b40
UNKNOWN_FUNCTION(unk_807c4998);
// PAL: 0x807c4b40..0x807c4ce8
UNKNOWN_FUNCTION(unk_807c4b40);

#ifdef __cplusplus
}
#endif

#include "RKGndCol.hpp"
#include "CollisionEntries.hpp"
#include "egg/math/eggMatrix.hpp"
#include "egg/math/eggMath.hpp"

namespace Field {
struct SoftWallColInfo {
  EGG::Vector3f bboxLow;
  EGG::Vector3f bboxHigh;
  // bboxLow + bboxHigh. This is the offset that needs to be added to a colliding sphere so
  // it barely does not collide with any prisms (becomes tangent to at least on of them)
  // This is used e.g. to place the wheels tangentially to the ground instead of them appearing to be "sinking"
  // when landing
  // ref: 0x805998c0
  EGG::Vector3f tangentOff;
  f32 dist;
  EGG::Vector3f fnrm;

  void update(f32 now_dist, const EGG::Vector3f& offset, const EGG::Vector3f& fnrm) {
    nw4r::math::VEC3Minimize(&this->bboxLow, &this->bboxLow, &offset);
    nw4r::math::VEC3Maximize(&this->bboxHigh, &this->bboxHigh, &offset);

    bool updateNrm;
    if (now_dist > this->dist) {
      this->dist = now_dist;
      updateNrm = true;
    } else {
      updateNrm = false;
    }
    if (updateNrm) {
      this->fnrm = fnrm;
    }
  }
};

struct ColInfoPartial {
  EGG::Vector3f bboxLow;
  EGG::Vector3f bboxHigh;
};

// not 100% sure if it's a distinct struct from the one above
struct ColInfoFull {
  EGG::Vector3f bboxLow;
  EGG::Vector3f bboxHigh;
  EGG::Vector3f tangentOff;
  // closest drivable road normal
  EGG::Vector3f floorNrm;
  // closest wall normal
  EGG::Vector3f wallNrm;
  EGG::Vector3f _3c;
  // distance to closest road
  f32 floorDist;
  // distance to closest wall
  f32 wallDist;
  f32 _50;
  f32 colPerpendicularity;
  // astruct7* ??


  void updateFloor(f32 dist, const EGG::Vector3f& fnrm) {
    bool updateNrm;
    if (dist > this->floorDist) {
      this->floorDist = dist;
      updateNrm = true;

    } else {
      updateNrm = false;
    }
    if (updateNrm) {
      this->floorNrm = fnrm;
    }
  }
  void updateWall(f32 dist, const EGG::Vector3f& fnrm) {
    bool updateNrm;
    if (dist > this->wallDist) {
      this->wallDist = dist;
      updateNrm = true;

    } else {
      updateNrm = false;
    }
    if (updateNrm) {
      this->wallNrm = fnrm;
    }
  }

  void update(f32 now_dist, const EGG::Vector3f& offset, const EGG::Vector3f& fnrm, u32 kclAttributeTypeBit) {
    nw4r::math::VEC3Minimize(&this->bboxLow, &this->bboxLow, &offset);
    nw4r::math::VEC3Maximize(&this->bboxHigh, &this->bboxHigh, &offset);

    if ((kclAttributeTypeBit & KCL_TYPE_FLOOR) != 0) {
      this->updateFloor(now_dist, fnrm);
    } else if ((kclAttributeTypeBit & KCL_TYPE_WALL) != 0) {

    if (EGG::Mathf::isNonNegative(this->wallDist)) {
      f32 perpendicularity = 1.0f - VEC3Dot(&this->wallNrm, &fnrm);
      bool updatePerp;
      if (perpendicularity > this->colPerpendicularity) {
        this->colPerpendicularity = perpendicularity;
        updatePerp = true;
      } else {
        updatePerp = false;
      }
      if (updatePerp && this->colPerpendicularity > 1.0f) {
        this->colPerpendicularity = 1.0f;
      }
    }

    this->updateWall(now_dist, fnrm);
    }
  }
};

typedef bool (RKGndCol::*CollisionCheckFunc) (f32* distOut, EGG::Vector3f* fnrmOut, u16* attributeOut);
/**
 * Manager for course KCL
 */
class CourseColManager {
public:
  static CourseColManager* spInstance;
  static void createInstance();
  static void destroyInstance();

  CourseColManager();
  ~CourseColManager();

  void init(const KCollisionHeader& header);
  f32 setThickness(RKGndCol* colMgr);
  void scaledNarrowScopeLocal(RKGndCol* maybeColMgr, const EGG::Vector3f& pos, u32 typeMask, f32 scale, f32 radius, u32 unused);
private:
  bool doCheckWithPartialInfo(RKGndCol* colMgr, CollisionCheckFunc collisionCheckFunc, ColInfoPartial* colInfoPartial, u32* typeMask);
  bool doCheckWithPartialInfoPush(RKGndCol* colMgr, CollisionCheckFunc collisionCheckFunc, ColInfoPartial* colInfoPartial, u32* typeMask);
  bool doCheckWithFullInfo(RKGndCol* colMgr, CollisionCheckFunc collisionCheckFunc, ColInfoFull* colInfoPartial, u32* typeMask);
  bool doCheckWithFullInfoPush(RKGndCol* colMgr, CollisionCheckFunc collisionCheckFunc, ColInfoFull* colInfoPartial, u32* typeMask);

  // KCL handle
  RKGndCol* colMgr;
  f32 kclScale;
  SoftWallColInfo* softWallColInfo;
  // pose of entity being checked for collision with course
  EGG::Matrix34f* localMtx;
};
}
