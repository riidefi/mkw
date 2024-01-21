#pragma once

#include <rk_types.h>

#include <decomp.h>

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

  // public collision query functions
  bool checkPointPartial(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 scale);
  bool checkPointPartialPush(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 scale);
  bool checkPointFull(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoFull* colInfo, u32* typeMaskOut, f32 scale);
  bool checkPointFullPush(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoFull* colInfo, u32* typeMaskOut, f32 scale);

  bool checkPointCachedPartial(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 scale);
  bool checkPointCachedPartialPush(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 scale);
  bool checkPointCachedFull(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoFull* colInfo, u32* typeMaskOut, f32 scale);
  bool checkPointCachedFullPush(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoFull* colInfo, u32* typeMaskOut, f32 scale);

  bool checkSpherePartial(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 scale, f32 radius);
  bool checkSpherePartialPush(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 scale, f32 radius);
  bool checkSphereFull(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoFull* colInfo, u32* typeMaskOut, f32 scale, f32 radius);
  bool checkSphereFullPush(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoFull* colInfo, u32* typeMaskOut, f32 scale, f32 radius);

  bool checkSphereCachedPartial(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 scale, f32 radius);
  bool checkSphereCachedPartialPush(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 scale, f32 radius);
  bool checkSphereCachedFull(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoFull* colInfo, u32* typeMaskOut, f32 scale, f32 radius);
  bool checkSphereCachedFullPush(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoFull* colInfo, u32* typeMaskOut, f32 scale, f32 radius);

private:
  bool doCheckWithPartialInfo(RKGndCol* colMgr, CollisionCheckFunc collisionCheckFunc, ColInfoPartial* colInfoPartial, u32* typeMask);
  bool doCheckWithPartialInfoPush(RKGndCol* colMgr, CollisionCheckFunc collisionCheckFunc, ColInfoPartial* colInfoPartial, u32* typeMask);
  bool doCheckWithFullInfo(RKGndCol* colMgr, CollisionCheckFunc collisionCheckFunc, ColInfoFull* colInfoPartial, u32* typeMask);
  bool doCheckWithFullInfoPush(RKGndCol* colMgr, CollisionCheckFunc collisionCheckFunc, ColInfoFull* colInfoPartial, u32* typeMask);
  bool doCheckMaskOnly(RKGndCol* colMgr, CollisionCheckFunc collisionCheckFunc, u32* typeMaskOut) {
    bool hasCol = false;
    f32 dist;
    u16 attribute;

    while((colMgr->*collisionCheckFunc)(&dist, nullptr, &attribute)) {
      if (this->softWallColInfo != nullptr && (attribute & KCL_SOFT_WALL_MASK) != 0) {
        hasCol = true;
      } else {
        u32 kclAttributeTypeBit = KCL_ATTRIBUTE_TYPE_BIT(attribute);
          
        if (typeMaskOut != nullptr) {
          *typeMaskOut |= kclAttributeTypeBit;
        }
        hasCol = true;
      }
    }

    return hasCol;
  }
  bool doCheckMaskOnlyPush(RKGndCol* colMgr, CollisionCheckFunc collisionCheckFunc, u32* typeMaskOut) {
    bool hasCol = false;
    f32 dist;
    u16 attribute;

    while((colMgr->*collisionCheckFunc)(&dist, nullptr, &attribute)) {
      if (this->softWallColInfo != nullptr && (attribute & KCL_SOFT_WALL_MASK) != 0) {
        hasCol = true;
      } else {
        u32 kclAttributeTypeBit = KCL_ATTRIBUTE_TYPE_BIT(attribute);
          
        if (typeMaskOut != nullptr) {
          pushCollisionEntry(dist, typeMaskOut, kclAttributeTypeBit, attribute);
        }
        hasCol = true;
      }
    }

    return hasCol;
  }

  // KCL handle
  RKGndCol* colMgr;
  f32 kclScale;
  SoftWallColInfo* softWallColInfo;
  // pose of entity being checked for collision with course
  EGG::Matrix34f* localMtx;
};
}
