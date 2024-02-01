#include "CourseColManager.hpp"

extern "C" const u32 _unused;
const u32 _unused = 0;

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

CourseColManager::CourseColManager() {
  this->colMgr = nullptr;
  this->kclScale = 1.0f;
  this->softWallColInfo = nullptr;
  this->localMtx = nullptr;
}

CourseColManager::~CourseColManager() { delete colMgr; }

bool CourseColManager::checkPointPartial(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 scale) {
  if (colMgr == nullptr) {
    colMgr = this->colMgr;
  }
  this->kclScale = scale;
  EGG::Vector3f scaledPos;
  EGG::Vector3f scaledPrevPos;
  f32 scaleInv = 1.0f / scale;
  VECScale(reinterpret_cast<const Vec*>(&pos), reinterpret_cast<Vec*>(&scaledPos), scaleInv);
  VECScale(reinterpret_cast<const Vec*>(&prevPos), reinterpret_cast<Vec*>(&scaledPrevPos), scaleInv);

  colMgr->lookupPoint(scaledPos, scaledPrevPos, typeMask);

  if (colInfo != nullptr) {
    return this->doCheckWithPartialInfo(colMgr, &RKGndCol::checkPointCollision, colInfo, typeMaskOut);
  } else {
    return this->doCheckMaskOnly(colMgr, &RKGndCol::checkPointCollision, typeMaskOut);
  }
}

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

bool CourseColManager::checkPointPartialPush(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 scale) {
  if (colMgr == nullptr) {
    colMgr = this->colMgr;
  }
  this->kclScale = scale;
  EGG::Vector3f scaledPos;
  EGG::Vector3f scaledPrevPos;
  f32 scaleInv = 1.0f / scale;
  VECScale(reinterpret_cast<const Vec*>(&pos), reinterpret_cast<Vec*>(&scaledPos), scaleInv);
  VECScale(reinterpret_cast<const Vec*>(&prevPos), reinterpret_cast<Vec*>(&scaledPrevPos), scaleInv);

  colMgr->lookupPoint(scaledPos, scaledPrevPos, typeMask);

  if (colInfo != nullptr) {
    return this->doCheckWithPartialInfoPush(colMgr, &RKGndCol::checkPointCollision, colInfo, typeMaskOut);
  } else {
    return this->doCheckMaskOnlyPush(colMgr, &RKGndCol::checkPointCollision, typeMaskOut);
  }
}

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

bool CourseColManager::checkPointFull(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut, f32 scale) {
  if (colMgr == nullptr) {
    colMgr = this->colMgr;
  }
  this->kclScale = scale;
  EGG::Vector3f scaledPos;
  EGG::Vector3f scaledPrevPos;
  f32 scaleInv = 1.0f / scale;
  VECScale(reinterpret_cast<const Vec*>(&pos), reinterpret_cast<Vec*>(&scaledPos), scaleInv);
  VECScale(reinterpret_cast<const Vec*>(&prevPos), reinterpret_cast<Vec*>(&scaledPrevPos), scaleInv);

  colMgr->lookupPoint(scaledPos, scaledPrevPos, typeMask);

  if (colInfo != nullptr) {
    return this->doCheckWithFullInfo(colMgr, &RKGndCol::checkPointCollision, colInfo, typeMaskOut);
  } else {
    return this->doCheckMaskOnly(colMgr, &RKGndCol::checkPointCollision, typeMaskOut);
  }
}

bool CourseColManager::doCheckWithFullInfo(RKGndCol* colMgr, CollisionCheckFunc collisionCheckFunc, ColInfo* colInfo, u32* typeMask) {
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

bool CourseColManager::checkPointFullPush(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut, f32 scale) {
  if (colMgr == nullptr) {
    colMgr = this->colMgr;
  }
  this->kclScale = scale;
  EGG::Vector3f scaledPos;
  EGG::Vector3f scaledPrevPos;
  f32 scaleInv = 1.0f / scale;
  VECScale(reinterpret_cast<const Vec*>(&pos), reinterpret_cast<Vec*>(&scaledPos), scaleInv);
  VECScale(reinterpret_cast<const Vec*>(&prevPos), reinterpret_cast<Vec*>(&scaledPrevPos), scaleInv);

  colMgr->lookupPoint(scaledPos, scaledPrevPos, typeMask);

  if (colInfo != nullptr) {
    return this->doCheckWithFullInfoPush(colMgr, &RKGndCol::checkPointCollision, colInfo, typeMaskOut);
  } else {
    return this->doCheckMaskOnlyPush(colMgr, &RKGndCol::checkPointCollision, typeMaskOut);
  }
}

bool CourseColManager::doCheckWithFullInfoPush(RKGndCol* colMgr, CollisionCheckFunc collisionCheckFunc, ColInfo* colInfo, u32* typeMask) {
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

bool CourseColManager::checkSpherePartial(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 scale, f32 radius) {
  if (colMgr == nullptr) {
    colMgr = this->colMgr;
  }
  this->kclScale = scale;
  EGG::Vector3f scaledPos;
  EGG::Vector3f scaledPrevPos;
  f32 scaleInv = 1.0f / scale;
  VECScale(reinterpret_cast<const Vec*>(&pos), reinterpret_cast<Vec*>(&scaledPos), scaleInv);
  VECScale(reinterpret_cast<const Vec*>(&prevPos), reinterpret_cast<Vec*>(&scaledPrevPos), scaleInv);
  radius *= scaleInv;

  colMgr->lookupSphere(scaledPos, scaledPrevPos, typeMask, radius);

  if (colInfo != nullptr) {
    return this->doCheckWithPartialInfo(colMgr, &RKGndCol::checkSphereCollision, colInfo, typeMaskOut);
  } else {
    return this->doCheckMaskOnly(colMgr, &RKGndCol::checkSphereCollision, typeMaskOut);
  }
}

bool CourseColManager::checkSpherePartialPush(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 scale, f32 radius) {
  if (colMgr == nullptr) {
    colMgr = this->colMgr;
  }
  this->kclScale = scale;
  EGG::Vector3f scaledPos;
  EGG::Vector3f scaledPrevPos;
  f32 scaleInv = 1.0f / scale;
  VECScale(reinterpret_cast<const Vec*>(&pos), reinterpret_cast<Vec*>(&scaledPos), scaleInv);
  VECScale(reinterpret_cast<const Vec*>(&prevPos), reinterpret_cast<Vec*>(&scaledPrevPos), scaleInv);
  radius *= scaleInv;

  colMgr->lookupSphere(scaledPos, scaledPrevPos, typeMask, radius);

  if (colInfo != nullptr) {
    return this->doCheckWithPartialInfoPush(colMgr, &RKGndCol::checkSphereCollision, colInfo, typeMaskOut);
  } else {
    return this->doCheckMaskOnlyPush(colMgr, &RKGndCol::checkSphereCollision, typeMaskOut);
  }
}

bool CourseColManager::checkSphereFull(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut, f32 scale, f32 radius) {
  if (colMgr == nullptr) {
    colMgr = this->colMgr;
  }
  this->kclScale = scale;
  EGG::Vector3f scaledPos;
  EGG::Vector3f scaledPrevPos;
  f32 scaleInv = 1.0f / scale;
  VECScale(reinterpret_cast<const Vec*>(&pos), reinterpret_cast<Vec*>(&scaledPos), scaleInv);
  VECScale(reinterpret_cast<const Vec*>(&prevPos), reinterpret_cast<Vec*>(&scaledPrevPos), scaleInv);
  radius *= scaleInv;

  colMgr->lookupSphere(scaledPos, scaledPrevPos, typeMask, radius);

  if (colInfo != nullptr) {
    return this->doCheckWithFullInfo(colMgr, &RKGndCol::checkSphereCollision, colInfo, typeMaskOut);
  } else {
    return this->doCheckMaskOnly(colMgr, &RKGndCol::checkSphereCollision, typeMaskOut);
  }
}

bool CourseColManager::checkSphereFullPush(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut, f32 scale, f32 radius) {
  if (colMgr == nullptr) {
    colMgr = this->colMgr;
  }
  this->kclScale = scale;
  EGG::Vector3f scaledPos;
  EGG::Vector3f scaledPrevPos;
  f32 scaleInv = 1.0f / scale;
  VECScale(reinterpret_cast<const Vec*>(&pos), reinterpret_cast<Vec*>(&scaledPos), scaleInv);
  VECScale(reinterpret_cast<const Vec*>(&prevPos), reinterpret_cast<Vec*>(&scaledPrevPos), scaleInv);
  radius *= scaleInv;

  colMgr->lookupSphere(scaledPos, scaledPrevPos, typeMask, radius);

  if (colInfo != nullptr) {
    return this->doCheckWithFullInfoPush(colMgr, &RKGndCol::checkSphereCollision, colInfo, typeMaskOut);
  } else {
    return this->doCheckMaskOnlyPush(colMgr, &RKGndCol::checkSphereCollision, typeMaskOut);
  }
}

bool CourseColManager::checkPointCachedPartial(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 scale) {
  if (colMgr == nullptr) {
    colMgr = this->colMgr;
  }
  if (colMgr->getPrismCache(0) == 0) {
    return false;
  }
  this->kclScale = scale;
  EGG::Vector3f scaledPos;
  EGG::Vector3f scaledPrevPos;
  f32 scaleInv = 1.0f / scale;
  VECScale(reinterpret_cast<const Vec*>(&pos), reinterpret_cast<Vec*>(&scaledPos), scaleInv);
  VECScale(reinterpret_cast<const Vec*>(&prevPos), reinterpret_cast<Vec*>(&scaledPrevPos), scaleInv);

  colMgr->lookupPointCached(scaledPos, scaledPrevPos, typeMask);

  if (colInfo != nullptr) {
    return this->doCheckWithPartialInfo(colMgr, &RKGndCol::checkPointCollision, colInfo, typeMaskOut);
  } else {
    return this->doCheckMaskOnly(colMgr, &RKGndCol::checkPointCollision, typeMaskOut);
  }
}

bool CourseColManager::checkPointCachedPartialPush(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 scale) {
  if (colMgr == nullptr) {
    colMgr = this->colMgr;
  }
  if (colMgr->getPrismCache(0) == 0) {
    return false;
  }
  this->kclScale = scale;
  EGG::Vector3f scaledPos;
  EGG::Vector3f scaledPrevPos;
  f32 scaleInv = 1.0f / scale;
  VECScale(reinterpret_cast<const Vec*>(&pos), reinterpret_cast<Vec*>(&scaledPos), scaleInv);
  VECScale(reinterpret_cast<const Vec*>(&prevPos), reinterpret_cast<Vec*>(&scaledPrevPos), scaleInv);

  colMgr->lookupPointCached(scaledPos, scaledPrevPos, typeMask);

  if (colInfo != nullptr) {
    return this->doCheckWithPartialInfoPush(colMgr, &RKGndCol::checkPointCollision, colInfo, typeMaskOut);
  } else {
    return this->doCheckMaskOnlyPush(colMgr, &RKGndCol::checkPointCollision, typeMaskOut);
  }
}

bool CourseColManager::checkPointCachedFull(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut, f32 scale) {
  if (colMgr == nullptr) {
    colMgr = this->colMgr;
  }
  if (colMgr->getPrismCache(0) == 0) {
    return false;
  }
  this->kclScale = scale;
  EGG::Vector3f scaledPos;
  EGG::Vector3f scaledPrevPos;
  f32 scaleInv = 1.0f / scale;
  VECScale(reinterpret_cast<const Vec*>(&pos), reinterpret_cast<Vec*>(&scaledPos), scaleInv);
  VECScale(reinterpret_cast<const Vec*>(&prevPos), reinterpret_cast<Vec*>(&scaledPrevPos), scaleInv);

  colMgr->lookupPointCached(scaledPos, scaledPrevPos, typeMask);

  if (colInfo != nullptr) {
    return this->doCheckWithFullInfo(colMgr, &RKGndCol::checkPointCollision, colInfo, typeMaskOut);
  } else {
    return this->doCheckMaskOnly(colMgr, &RKGndCol::checkPointCollision, typeMaskOut);
  }
}

bool CourseColManager::checkPointCachedFullPush(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut, f32 scale) {
  if (colMgr == nullptr) {
    colMgr = this->colMgr;
  }
  if (colMgr->getPrismCache(0) == 0) {
    return false;
  }
  this->kclScale = scale;
  EGG::Vector3f scaledPos;
  EGG::Vector3f scaledPrevPos;
  f32 scaleInv = 1.0f / scale;
  VECScale(reinterpret_cast<const Vec*>(&pos), reinterpret_cast<Vec*>(&scaledPos), scaleInv);
  VECScale(reinterpret_cast<const Vec*>(&prevPos), reinterpret_cast<Vec*>(&scaledPrevPos), scaleInv);

  colMgr->lookupPointCached(scaledPos, scaledPrevPos, typeMask);

  if (colInfo != nullptr) {
    return this->doCheckWithFullInfoPush(colMgr, &RKGndCol::checkPointCollision, colInfo, typeMaskOut);
  } else {
    return this->doCheckMaskOnlyPush(colMgr, &RKGndCol::checkPointCollision, typeMaskOut);
  }
}

bool CourseColManager::checkSphereCachedPartial(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 scale, f32 radius) {
  if (colMgr == nullptr) {
    colMgr = this->colMgr;
  }
  if (colMgr->getPrismCache(0) == 0) {
    return false;
  }
  this->kclScale = scale;
  EGG::Vector3f scaledPos;
  EGG::Vector3f scaledPrevPos;
  f32 scaleInv = 1.0f / scale;
  VECScale(reinterpret_cast<const Vec*>(&pos), reinterpret_cast<Vec*>(&scaledPos), scaleInv);
  VECScale(reinterpret_cast<const Vec*>(&prevPos), reinterpret_cast<Vec*>(&scaledPrevPos), scaleInv);
  radius *= scaleInv;

  colMgr->lookupSphereCached(scaledPos, scaledPrevPos, typeMask, radius);

  if (colInfo != nullptr) {
    return this->doCheckWithPartialInfo(colMgr, &RKGndCol::checkSphereCollision, colInfo, typeMaskOut);
  } else {
    return this->doCheckMaskOnly(colMgr, &RKGndCol::checkSphereCollision, typeMaskOut);
  }
}

bool CourseColManager::checkSphereCachedPartialPush(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 scale, f32 radius) {
  if (colMgr == nullptr) {
    colMgr = this->colMgr;
  }
  if (colMgr->getPrismCache(0) == 0) {
    return false;
  }
  this->kclScale = scale;
  EGG::Vector3f scaledPos;
  EGG::Vector3f scaledPrevPos;
  f32 scaleInv = 1.0f / scale;
  VECScale(reinterpret_cast<const Vec*>(&pos), reinterpret_cast<Vec*>(&scaledPos), scaleInv);
  VECScale(reinterpret_cast<const Vec*>(&prevPos), reinterpret_cast<Vec*>(&scaledPrevPos), scaleInv);
  radius *= scaleInv;

  colMgr->lookupSphereCached(scaledPos, scaledPrevPos, typeMask, radius);

  if (colInfo != nullptr) {
    return this->doCheckWithPartialInfoPush(colMgr, &RKGndCol::checkSphereCollision, colInfo, typeMaskOut);
  } else {
    return this->doCheckMaskOnlyPush(colMgr, &RKGndCol::checkSphereCollision, typeMaskOut);
  }
}

bool CourseColManager::checkSphereCachedFull(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut, f32 scale, f32 radius) {
  if (colMgr == nullptr) {
    colMgr = this->colMgr;
  }
  if (colMgr->getPrismCache(0) == 0) {
    return false;
  }
  this->kclScale = scale;
  EGG::Vector3f scaledPos;
  EGG::Vector3f scaledPrevPos;
  f32 scaleInv = 1.0f / scale;
  VECScale(reinterpret_cast<const Vec*>(&pos), reinterpret_cast<Vec*>(&scaledPos), scaleInv);
  VECScale(reinterpret_cast<const Vec*>(&prevPos), reinterpret_cast<Vec*>(&scaledPrevPos), scaleInv);
  radius *= scaleInv;

  colMgr->lookupSphereCached(scaledPos, scaledPrevPos, typeMask, radius);

  if (colInfo != nullptr) {
    return this->doCheckWithFullInfo(colMgr, &RKGndCol::checkSphereCollision, colInfo, typeMaskOut);
  } else {
    return this->doCheckMaskOnly(colMgr, &RKGndCol::checkSphereCollision, typeMaskOut);
  }
}

bool CourseColManager::checkSphereCachedFullPush(RKGndCol* colMgr, const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut, f32 scale, f32 radius) {
  if (colMgr == nullptr) {
    colMgr = this->colMgr;
  }
  if (colMgr->getPrismCache(0) == 0) {
    return false;
  }
  this->kclScale = scale;
  EGG::Vector3f scaledPos;
  EGG::Vector3f scaledPrevPos;
  f32 scaleInv = 1.0f / scale;
  VECScale(reinterpret_cast<const Vec*>(&pos), reinterpret_cast<Vec*>(&scaledPos), scaleInv);
  VECScale(reinterpret_cast<const Vec*>(&prevPos), reinterpret_cast<Vec*>(&scaledPrevPos), scaleInv);
  radius *= scaleInv;

  colMgr->lookupSphereCached(scaledPos, scaledPrevPos, typeMask, radius);

  if (colInfo != nullptr) {
    return this->doCheckWithFullInfoPush(colMgr, &RKGndCol::checkSphereCollision, colInfo, typeMaskOut);
  } else {
    return this->doCheckMaskOnlyPush(colMgr, &RKGndCol::checkSphereCollision, typeMaskOut);
  }
}
}
