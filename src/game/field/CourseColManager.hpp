#pragma once

#include <rk_types.h>

#include <decomp.h>

#include "RKGndCol.hpp"
#include "CollisionInfo.hpp"
#include "CollisionEntries.hpp"
#include "egg/math/eggMatrix.hpp"
#include "egg/math/eggMath.hpp"

namespace Field {
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
  void setSoftWallColInfo(SoftWallColInfo* swColInfo) { this->softWallColInfo = swColInfo; }
  SoftWallColInfo* getSoftWallColInfo() const { return this->softWallColInfo; }
  void setLocalMtx(EGG::Matrix34f* mtx) { this->localMtx = mtx; }
  void scaledNarrowScopeLocal(RKGndCol* maybeColMgr, const EGG::Vector3f& pos, u32 typeMask, f32 scale, f32 radius, u32 unused);

  // public collision query functions
  // Naming:
  // -Point/-Sphere - Point or sphere collision algorithm
  // -Cached        - Use previously looked up prisms
  // -Partial/-Full - Fill partial or full collision information
  // -Push          - Push collision entry to global collision array
  bool checkPointPartial(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 scale);
  bool checkPointPartialPush(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 scale);
  bool checkPointFull(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut, f32 scale);
  bool checkPointFullPush(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut, f32 scale);

  bool checkPointCachedPartial(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 scale);
  bool checkPointCachedPartialPush(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 scale);
  bool checkPointCachedFull(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut, f32 scale);
  bool checkPointCachedFullPush(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut, f32 scale);

  bool checkSpherePartial(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 scale, f32 radius);
  bool checkSpherePartialPush(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 scale, f32 radius);
  bool checkSphereFull(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut, f32 scale, f32 radius);
  bool checkSphereFullPush(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut, f32 scale, f32 radius);

  bool checkSphereCachedPartial(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 scale, f32 radius);
  bool checkSphereCachedPartialPush(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 scale, f32 radius);
  bool checkSphereCachedFull(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut, f32 scale, f32 radius);
  bool checkSphereCachedFullPush(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut, f32 scale, f32 radius);

private:
  bool doCheckWithPartialInfo(RKGndCol* colMgr, CollisionCheckFunc collisionCheckFunc, ColInfoPartial* colInfoPartial, u32* typeMask);
  bool doCheckWithPartialInfoPush(RKGndCol* colMgr, CollisionCheckFunc collisionCheckFunc, ColInfoPartial* colInfoPartial, u32* typeMask);
  bool doCheckWithFullInfo(RKGndCol* colMgr, CollisionCheckFunc collisionCheckFunc, ColInfo* colInfoPartial, u32* typeMask);
  bool doCheckWithFullInfoPush(RKGndCol* colMgr, CollisionCheckFunc collisionCheckFunc, ColInfo* colInfoPartial, u32* typeMask);
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
