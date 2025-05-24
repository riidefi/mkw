#include "ObjColManager.hpp"

extern "C" EGG::Vector3f VEC_INFINITY; // TODO: CourseColManager .bss

namespace Field {
ObjColManager::ObjColManager(const KCollisionHeader& header) {
  #pragma warn_no_side_effect off
  0.0f;
  #pragma warn_no_side_effect on
  this->colMgr = new RKGndCol(header);
  this->mtx.makeIdentity();
  this->mtxInv.makeIdentity();
  this->kclScale = 1.0f;
  this->_68.x = 0.0f;
  this->_68.y = 0.0f;
  this->_68.z = 0.0f;
}

ObjColManager::~ObjColManager() { delete this->colMgr; }

void ObjColManager::narrowScopeLocal(const EGG::Vector3f& pos, u32 typeMask, f32 radius, u32 unused) {
  EGG::Vector3f posLocal;
  VEC3Transform(&posLocal, &this->mtxInv, &pos);
  CourseColManager::spInstance->scaledNarrowScopeLocal(this->colMgr, posLocal, typeMask, this->kclScale, radius, unused);
}

void ObjColManager::kclLowWorld(EGG::Vector3f& v, const ObjColManager& objColMgr) {
  nw4r::math::VEC3Scale(&v, &objColMgr.colMgr->getBboxLow(), objColMgr.kclScale);
  VEC3Transform(&v, &objColMgr.mtx, &v);
}

void ObjColManager::kclHighWorld(EGG::Vector3f& v, const ObjColManager& objColMgr) {
  nw4r::math::VEC3Scale(&v, &objColMgr.colMgr->getBboxHigh(), objColMgr.kclScale);
  VEC3Transform(&v, &objColMgr.mtx, &v);
}

bool ObjColManager::checkPointPartial(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut) {
  EGG::Vector3f posLocal;
  EGG::Vector3f prevPosLocal;
  VEC3Transform(&posLocal, &this->mtxInv, &pos);
  if (isfinite(prevPos.y)) {
    VEC3Transform(&prevPosLocal, &this->mtxInv, &prevPos);
  } else {
    prevPosLocal = VEC_INFINITY;
  }

  if (colInfo != nullptr) {
    ColInfoPartial colInfoLocal;
    colInfoLocal.bboxLow.setZero();
    colInfoLocal.bboxHigh.setZero();

    CourseColManager* gColMgr = CourseColManager::spInstance;
    if (gColMgr->getSoftWallColInfo() != nullptr) {
      gColMgr->setLocalMtx(&this->mtx);
    }

    bool hasCol = gColMgr->checkPointPartial(this->colMgr, posLocal, prevPosLocal, typeMask, &colInfoLocal, typeMaskOut, this->kclScale);

    if (hasCol) {
      VEC3TransformSR(&colInfoLocal.bboxLow, &this->mtx, &colInfoLocal.bboxLow);
      VEC3TransformSR(&colInfoLocal.bboxHigh, &this->mtx, &colInfoLocal.bboxHigh);

      EGG::Vector3f tmp = colInfoLocal.bboxLow;
      VEC3Minimize(&colInfoLocal.bboxLow, &tmp, &colInfoLocal.bboxHigh);
      VEC3Maximize(&colInfoLocal.bboxHigh, &tmp, &colInfoLocal.bboxHigh);
      VEC3Minimize(&colInfo->bboxLow, &colInfo->bboxLow, &colInfoLocal.bboxLow);
      VEC3Maximize(&colInfo->bboxHigh, &colInfo->bboxHigh, &colInfoLocal.bboxHigh);

      return true;
    } else {
      return false;
    }
  } else {
    return CourseColManager::spInstance->checkPointPartial(this->colMgr, posLocal, prevPosLocal, typeMask, colInfo, typeMaskOut, this->kclScale);
  }
}

bool ObjColManager::checkPointPartialPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut) {
  EGG::Vector3f posLocal;
  EGG::Vector3f prevPosLocal;
  VEC3Transform(&posLocal, &this->mtxInv, &pos);
  if (isfinite(prevPos.y)) {
    VEC3Transform(&prevPosLocal, &this->mtxInv, &prevPos);
  } else {
    prevPosLocal = VEC_INFINITY;
  }

  if (colInfo != nullptr) {
    ColInfoPartial colInfoLocal;
    colInfoLocal.bboxLow.setZero();
    colInfoLocal.bboxHigh.setZero();

    CourseColManager* gColMgr = CourseColManager::spInstance;
    if (gColMgr->getSoftWallColInfo() != nullptr) {
      gColMgr->setLocalMtx(&this->mtx);
    }

    bool hasCol = gColMgr->checkPointPartialPush(this->colMgr, posLocal, prevPosLocal, typeMask, &colInfoLocal, typeMaskOut, this->kclScale);

    if (hasCol) {
      VEC3TransformSR(&colInfoLocal.bboxLow, &this->mtx, &colInfoLocal.bboxLow);
      VEC3TransformSR(&colInfoLocal.bboxHigh, &this->mtx, &colInfoLocal.bboxHigh);

      EGG::Vector3f tmp = colInfoLocal.bboxLow;
      VEC3Minimize(&colInfoLocal.bboxLow, &tmp, &colInfoLocal.bboxHigh);
      VEC3Maximize(&colInfoLocal.bboxHigh, &tmp, &colInfoLocal.bboxHigh);
      VEC3Minimize(&colInfo->bboxLow, &colInfo->bboxLow, &colInfoLocal.bboxLow);
      VEC3Maximize(&colInfo->bboxHigh, &colInfo->bboxHigh, &colInfoLocal.bboxHigh);

      return true;
    } else {
      return false;
    }
  } else {
    return CourseColManager::spInstance->checkPointPartialPush(this->colMgr, posLocal, prevPosLocal, typeMask, colInfo, typeMaskOut, this->kclScale);
  }
}

bool ObjColManager::checkPointFull(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut) {
  EGG::Vector3f posLocal;
  EGG::Vector3f prevPosLocal;
  VEC3Transform(&posLocal, &this->mtxInv, &pos);
  f32 inf = 1.0f/0.0f ;
  int x = inf != prevPos.y;
  if (x) {
    VEC3Transform(&prevPosLocal, &this->mtxInv, &prevPos);
  } else {
    prevPosLocal = VEC_INFINITY;
  }

  if (colInfo != nullptr) {
    ColInfo colInfoLocal;
    colInfoLocal.drivableColInfo = nullptr;
    colInfoLocal.bboxLow.setZero();
    colInfoLocal.bboxHigh.setZero();
    colInfoLocal._50 = -FLT_MIN;
    colInfoLocal.wallDist = -FLT_MIN;
    colInfoLocal.floorDist = -FLT_MIN;
    colInfoLocal.colPerpendicularity = 0.0f;

    CourseColManager* gColMgr = CourseColManager::spInstance;
    if (gColMgr->getSoftWallColInfo() != nullptr) {
      gColMgr->setLocalMtx(&this->mtx);
    }

    if (gColMgr->checkPointFull(this->colMgr, posLocal, prevPosLocal, typeMask, &colInfoLocal, typeMaskOut, this->kclScale)) {
      colInfo->transformInfo(colInfoLocal, this->mtx, this->_68);
      return true;
    } else {
      return false;
    }
  } else {
    return CourseColManager::spInstance->checkPointFull(this->colMgr, posLocal, prevPosLocal, typeMask, colInfo, typeMaskOut, this->kclScale);
  }
}

bool ObjColManager::checkPointFullPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut) {
  EGG::Vector3f posLocal;
  EGG::Vector3f prevPosLocal;
  VEC3Transform(&posLocal, &this->mtxInv, &pos);
  f32 inf = 1.0f/0.0f ;
  int x = inf != prevPos.y;
  if (x) {
    VEC3Transform(&prevPosLocal, &this->mtxInv, &prevPos);
  } else {
    prevPosLocal = VEC_INFINITY;
  }

  if (colInfo != nullptr) {
    ColInfo colInfoLocal;
    colInfoLocal.drivableColInfo = nullptr;
    colInfoLocal.bboxLow.setZero();
    colInfoLocal.bboxHigh.setZero();
    colInfoLocal._50 = -FLT_MIN;
    colInfoLocal.wallDist = -FLT_MIN;
    colInfoLocal.floorDist = -FLT_MIN;
    colInfoLocal.colPerpendicularity = 0.0f;

    CourseColManager* gColMgr = CourseColManager::spInstance;
    if (gColMgr->getSoftWallColInfo() != nullptr) {
      gColMgr->setLocalMtx(&this->mtx);
    }

    bool hasCol = gColMgr->checkPointFullPush(this->colMgr, posLocal, prevPosLocal, typeMask, &colInfoLocal, typeMaskOut, this->kclScale);

    if (hasCol) {
      colInfo->transformInfo(colInfoLocal, this->mtx, this->_68);

      return true;
    } else {
      return false;
    }
  } else {
    return CourseColManager::spInstance->checkPointFullPush(this->colMgr, posLocal, prevPosLocal, typeMask, colInfo, typeMaskOut, this->kclScale);
  }
}

bool ObjColManager::checkSpherePartial(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 radius) {
  EGG::Vector3f posLocal;
  EGG::Vector3f prevPosLocal;
  VEC3Transform(&posLocal, &this->mtxInv, &pos);
  if (isfinite(prevPos.y)) {
    VEC3Transform(&prevPosLocal, &this->mtxInv, &prevPos);
  } else {
    prevPosLocal = VEC_INFINITY;
  }

  if (colInfo != nullptr) {
    ColInfoPartial colInfoLocal;
    colInfoLocal.bboxLow.setZero();
    colInfoLocal.bboxHigh.setZero();

    CourseColManager* gColMgr = CourseColManager::spInstance;
    if (gColMgr->getSoftWallColInfo() != nullptr) {
      gColMgr->setLocalMtx(&this->mtx);
    }

    bool hasCol = gColMgr->checkSpherePartial(this->colMgr, posLocal, prevPosLocal, typeMask, &colInfoLocal, typeMaskOut, this->kclScale, radius);

    if (hasCol) {
      VEC3TransformSR(&colInfoLocal.bboxLow, &this->mtx, &colInfoLocal.bboxLow);
      VEC3TransformSR(&colInfoLocal.bboxHigh, &this->mtx, &colInfoLocal.bboxHigh);

      EGG::Vector3f tmp = colInfoLocal.bboxLow;
      VEC3Minimize(&colInfoLocal.bboxLow, &tmp, &colInfoLocal.bboxHigh);
      VEC3Maximize(&colInfoLocal.bboxHigh, &tmp, &colInfoLocal.bboxHigh);
      VEC3Minimize(&colInfo->bboxLow, &colInfo->bboxLow, &colInfoLocal.bboxLow);
      VEC3Maximize(&colInfo->bboxHigh, &colInfo->bboxHigh, &colInfoLocal.bboxHigh);

      return true;
    } else {
      return false;
    }
  } else {
    return CourseColManager::spInstance->checkSpherePartial(this->colMgr, posLocal, prevPosLocal, typeMask, colInfo, typeMaskOut, this->kclScale, radius);
  }
}

bool ObjColManager::checkSpherePartialPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 radius) {
  EGG::Vector3f posLocal;
  EGG::Vector3f prevPosLocal;
  VEC3Transform(&posLocal, &this->mtxInv, &pos);
  if (isfinite(prevPos.y)) {
    VEC3Transform(&prevPosLocal, &this->mtxInv, &prevPos);
  } else {
    prevPosLocal = VEC_INFINITY;
  }

  if (colInfo != nullptr) {
    ColInfoPartial colInfoLocal;
    colInfoLocal.bboxLow.setZero();
    colInfoLocal.bboxHigh.setZero();

    CourseColManager* gColMgr = CourseColManager::spInstance;
    if (gColMgr->getSoftWallColInfo() != nullptr) {
      gColMgr->setLocalMtx(&this->mtx);
    }

    bool hasCol = gColMgr->checkSpherePartialPush(this->colMgr, posLocal, prevPosLocal, typeMask, &colInfoLocal, typeMaskOut, this->kclScale, radius);

    if (hasCol) {
      VEC3TransformSR(&colInfoLocal.bboxLow, &this->mtx, &colInfoLocal.bboxLow);
      VEC3TransformSR(&colInfoLocal.bboxHigh, &this->mtx, &colInfoLocal.bboxHigh);

      EGG::Vector3f tmp = colInfoLocal.bboxLow;
      VEC3Minimize(&colInfoLocal.bboxLow, &tmp, &colInfoLocal.bboxHigh);
      VEC3Maximize(&colInfoLocal.bboxHigh, &tmp, &colInfoLocal.bboxHigh);
      VEC3Minimize(&colInfo->bboxLow, &colInfo->bboxLow, &colInfoLocal.bboxLow);
      VEC3Maximize(&colInfo->bboxHigh, &colInfo->bboxHigh, &colInfoLocal.bboxHigh);

      return true;
    } else {
      return false;
    }
  } else {
    return CourseColManager::spInstance->checkSpherePartialPush(this->colMgr, posLocal, prevPosLocal, typeMask, colInfo, typeMaskOut, this->kclScale, radius);
  }
}

bool ObjColManager::checkSphereFull(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut, f32 radius) {
  EGG::Vector3f posLocal;
  EGG::Vector3f prevPosLocal;
  VEC3Transform(&posLocal, &this->mtxInv, &pos);
  f32 inf = 1.0f/0.0f ;
  int x = inf != prevPos.y;
  if (x) {
    VEC3Transform(&prevPosLocal, &this->mtxInv, &prevPos);
  } else {
    prevPosLocal = VEC_INFINITY;
  }

  if (colInfo != nullptr) {
    ColInfo colInfoLocal;
    colInfoLocal.drivableColInfo = nullptr;
    colInfoLocal.bboxLow.setZero();
    colInfoLocal.bboxHigh.setZero();
    colInfoLocal._50 = -FLT_MIN;
    colInfoLocal.wallDist = -FLT_MIN;
    colInfoLocal.floorDist = -FLT_MIN;
    colInfoLocal.colPerpendicularity = 0.0f;

    CourseColManager* gColMgr = CourseColManager::spInstance;
    if (gColMgr->getSoftWallColInfo() != nullptr) {
      gColMgr->setLocalMtx(&this->mtx);
    }

    if (gColMgr->checkSphereFull(this->colMgr, posLocal, prevPosLocal, typeMask, &colInfoLocal, typeMaskOut, this->kclScale, radius)) {
      colInfo->transformInfo(colInfoLocal, this->mtx, this->_68);
      return true;
    } else {
      return false;
    }
  } else {
    return CourseColManager::spInstance->checkSphereFull(this->colMgr, posLocal, prevPosLocal, typeMask, colInfo, typeMaskOut, this->kclScale, radius);
  }
}

bool ObjColManager::checkSphereFullPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut, f32 radius) {
  EGG::Vector3f posLocal;
  EGG::Vector3f prevPosLocal;
  VEC3Transform(&posLocal, &this->mtxInv, &pos);
  f32 inf = 1.0f/0.0f ;
  int x = inf != prevPos.y;
  if (x) {
    VEC3Transform(&prevPosLocal, &this->mtxInv, &prevPos);
  } else {
    prevPosLocal = VEC_INFINITY;
  }

  if (colInfo != nullptr) {
    ColInfo colInfoLocal;
    colInfoLocal.drivableColInfo = nullptr;
    colInfoLocal.bboxLow.setZero();
    colInfoLocal.bboxHigh.setZero();
    colInfoLocal._50 = -FLT_MIN;
    colInfoLocal.wallDist = -FLT_MIN;
    colInfoLocal.floorDist = -FLT_MIN;
    colInfoLocal.colPerpendicularity = 0.0f;

    CourseColManager* gColMgr = CourseColManager::spInstance;
    if (gColMgr->getSoftWallColInfo() != nullptr) {
      gColMgr->setLocalMtx(&this->mtx);
    }

    bool hasCol = gColMgr->checkSphereFullPush(this->colMgr, posLocal, prevPosLocal, typeMask, &colInfoLocal, typeMaskOut, this->kclScale, radius);

    if (hasCol) {
      colInfo->transformInfo(colInfoLocal, this->mtx, this->_68);

      return true;
    } else {
      return false;
    }
  } else {
    return CourseColManager::spInstance->checkSphereFullPush(this->colMgr, posLocal, prevPosLocal, typeMask, colInfo, typeMaskOut, this->kclScale, radius);
  }
}

bool ObjColManager::checkPointCachedPartial(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut) {
  if (this->colMgr->cacheEmpty()) return false;

  EGG::Vector3f posLocal;
  EGG::Vector3f prevPosLocal;
  VEC3Transform(&posLocal, &this->mtxInv, &pos);
  if (isfinite(prevPos.y)) {
    VEC3Transform(&prevPosLocal, &this->mtxInv, &prevPos);
  } else {
    prevPosLocal = VEC_INFINITY;
  }

  if (colInfo != nullptr) {
    ColInfoPartial colInfoLocal;
    colInfoLocal.bboxLow.setZero();
    colInfoLocal.bboxHigh.setZero();

    CourseColManager* gColMgr = CourseColManager::spInstance;
    if (gColMgr->getSoftWallColInfo() != nullptr) {
      gColMgr->setLocalMtx(&this->mtx);
    }

    bool hasCol = gColMgr->checkPointCachedPartial(this->colMgr, posLocal, prevPosLocal, typeMask, &colInfoLocal, typeMaskOut, this->kclScale);

    if (hasCol) {
      VEC3TransformSR(&colInfoLocal.bboxLow, &this->mtx, &colInfoLocal.bboxLow);
      VEC3TransformSR(&colInfoLocal.bboxHigh, &this->mtx, &colInfoLocal.bboxHigh);

      EGG::Vector3f tmp = colInfoLocal.bboxLow;
      VEC3Minimize(&colInfoLocal.bboxLow, &tmp, &colInfoLocal.bboxHigh);
      VEC3Maximize(&colInfoLocal.bboxHigh, &tmp, &colInfoLocal.bboxHigh);
      VEC3Minimize(&colInfo->bboxLow, &colInfo->bboxLow, &colInfoLocal.bboxLow);
      VEC3Maximize(&colInfo->bboxHigh, &colInfo->bboxHigh, &colInfoLocal.bboxHigh);

      return true;
    } else {
      return false;
    }
  } else {
    return CourseColManager::spInstance->checkPointCachedPartial(this->colMgr, posLocal, prevPosLocal, typeMask, colInfo, typeMaskOut, this->kclScale);
  }
}

bool ObjColManager::checkPointCachedPartialPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut) {
  if (this->colMgr->cacheEmpty()) return false;

  EGG::Vector3f posLocal;
  EGG::Vector3f prevPosLocal;
  VEC3Transform(&posLocal, &this->mtxInv, &pos);
  if (isfinite(prevPos.y)) {
    VEC3Transform(&prevPosLocal, &this->mtxInv, &prevPos);
  } else {
    prevPosLocal = VEC_INFINITY;
  }

  if (colInfo != nullptr) {
    ColInfoPartial colInfoLocal;
    colInfoLocal.bboxLow.setZero();
    colInfoLocal.bboxHigh.setZero();

    CourseColManager* gColMgr = CourseColManager::spInstance;
    if (gColMgr->getSoftWallColInfo() != nullptr) {
      gColMgr->setLocalMtx(&this->mtx);
    }

    bool hasCol = gColMgr->checkPointCachedPartialPush(this->colMgr, posLocal, prevPosLocal, typeMask, &colInfoLocal, typeMaskOut, this->kclScale);

    if (hasCol) {
      VEC3TransformSR(&colInfoLocal.bboxLow, &this->mtx, &colInfoLocal.bboxLow);
      VEC3TransformSR(&colInfoLocal.bboxHigh, &this->mtx, &colInfoLocal.bboxHigh);

      EGG::Vector3f tmp = colInfoLocal.bboxLow;
      VEC3Minimize(&colInfoLocal.bboxLow, &tmp, &colInfoLocal.bboxHigh);
      VEC3Maximize(&colInfoLocal.bboxHigh, &tmp, &colInfoLocal.bboxHigh);
      VEC3Minimize(&colInfo->bboxLow, &colInfo->bboxLow, &colInfoLocal.bboxLow);
      VEC3Maximize(&colInfo->bboxHigh, &colInfo->bboxHigh, &colInfoLocal.bboxHigh);

      return true;
    } else {
      return false;
    }
  } else {
    return CourseColManager::spInstance->checkPointCachedPartialPush(this->colMgr, posLocal, prevPosLocal, typeMask, colInfo, typeMaskOut, this->kclScale);
  }
}

bool ObjColManager::checkPointCachedFull(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut) {
  if (this->colMgr->cacheEmpty()) return false;

  EGG::Vector3f posLocal;
  EGG::Vector3f prevPosLocal;
  VEC3Transform(&posLocal, &this->mtxInv, &pos);
  f32 inf = 1.0f/0.0f ;
  int x = inf != prevPos.y;
  if (x) {
    VEC3Transform(&prevPosLocal, &this->mtxInv, &prevPos);
  } else {
    prevPosLocal = VEC_INFINITY;
  }

  if (colInfo != nullptr) {
    ColInfo colInfoLocal;
    colInfoLocal.drivableColInfo = nullptr;
    colInfoLocal.bboxLow.setZero();
    colInfoLocal.bboxHigh.setZero();
    colInfoLocal._50 = -FLT_MIN;
    colInfoLocal.wallDist = -FLT_MIN;
    colInfoLocal.floorDist = -FLT_MIN;
    colInfoLocal.colPerpendicularity = 0.0f;

    CourseColManager* gColMgr = CourseColManager::spInstance;
    if (gColMgr->getSoftWallColInfo() != nullptr) {
      gColMgr->setLocalMtx(&this->mtx);
    }

    if (gColMgr->checkPointCachedFull(this->colMgr, posLocal, prevPosLocal, typeMask, &colInfoLocal, typeMaskOut, this->kclScale)) {
      colInfo->transformInfo(colInfoLocal, this->mtx, this->_68);
      return true;
    } else {
      return false;
    }
  } else {
    return CourseColManager::spInstance->checkPointCachedFull(this->colMgr, posLocal, prevPosLocal, typeMask, colInfo, typeMaskOut, this->kclScale);
  }
}

bool ObjColManager::checkPointCachedFullPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut) {
  if (this->colMgr->cacheEmpty()) return false;

  EGG::Vector3f posLocal;
  EGG::Vector3f prevPosLocal;
  VEC3Transform(&posLocal, &this->mtxInv, &pos);
  f32 inf = 1.0f/0.0f ;
  int x = inf != prevPos.y;
  if (x) {
    VEC3Transform(&prevPosLocal, &this->mtxInv, &prevPos);
  } else {
    prevPosLocal = VEC_INFINITY;
  }

  if (colInfo != nullptr) {
    ColInfo colInfoLocal;
    colInfoLocal.drivableColInfo = nullptr;
    colInfoLocal.bboxLow.setZero();
    colInfoLocal.bboxHigh.setZero();
    colInfoLocal._50 = -FLT_MIN;
    colInfoLocal.wallDist = -FLT_MIN;
    colInfoLocal.floorDist = -FLT_MIN;
    colInfoLocal.colPerpendicularity = 0.0f;

    CourseColManager* gColMgr = CourseColManager::spInstance;
    if (gColMgr->getSoftWallColInfo() != nullptr) {
      gColMgr->setLocalMtx(&this->mtx);
    }

    bool hasCol = gColMgr->checkPointCachedFullPush(this->colMgr, posLocal, prevPosLocal, typeMask, &colInfoLocal, typeMaskOut, this->kclScale);

    if (hasCol) {
      colInfo->transformInfo(colInfoLocal, this->mtx, this->_68);

      return true;
    } else {
      return false;
    }
  } else {
    return CourseColManager::spInstance->checkPointCachedFullPush(this->colMgr, posLocal, prevPosLocal, typeMask, colInfo, typeMaskOut, this->kclScale);
  }
}

bool ObjColManager::checkSphereCachedPartial(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 radius) {
  if (this->colMgr->cacheEmpty()) return false;

  EGG::Vector3f posLocal;
  EGG::Vector3f prevPosLocal;
  VEC3Transform(&posLocal, &this->mtxInv, &pos);
  if (isfinite(prevPos.y)) {
    VEC3Transform(&prevPosLocal, &this->mtxInv, &prevPos);
  } else {
    prevPosLocal = VEC_INFINITY;
  }

  if (colInfo != nullptr) {
    ColInfoPartial colInfoLocal;
    colInfoLocal.bboxLow.setZero();
    colInfoLocal.bboxHigh.setZero();

    CourseColManager* gColMgr = CourseColManager::spInstance;
    if (gColMgr->getSoftWallColInfo() != nullptr) {
      gColMgr->setLocalMtx(&this->mtx);
    }

    bool hasCol = gColMgr->checkSphereCachedPartial(this->colMgr, posLocal, prevPosLocal, typeMask, &colInfoLocal, typeMaskOut, this->kclScale, radius);

    if (hasCol) {
      VEC3TransformSR(&colInfoLocal.bboxLow, &this->mtx, &colInfoLocal.bboxLow);
      VEC3TransformSR(&colInfoLocal.bboxHigh, &this->mtx, &colInfoLocal.bboxHigh);

      EGG::Vector3f tmp = colInfoLocal.bboxLow;
      VEC3Minimize(&colInfoLocal.bboxLow, &tmp, &colInfoLocal.bboxHigh);
      VEC3Maximize(&colInfoLocal.bboxHigh, &tmp, &colInfoLocal.bboxHigh);
      VEC3Minimize(&colInfo->bboxLow, &colInfo->bboxLow, &colInfoLocal.bboxLow);
      VEC3Maximize(&colInfo->bboxHigh, &colInfo->bboxHigh, &colInfoLocal.bboxHigh);

      return true;
    } else {
      return false;
    }
  } else {
    return CourseColManager::spInstance->checkSphereCachedPartial(this->colMgr, posLocal, prevPosLocal, typeMask, colInfo, typeMaskOut, this->kclScale, radius);
  }
}

bool ObjColManager::checkSphereCachedPartialPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 radius) {
  if (this->colMgr->cacheEmpty()) return false;

  EGG::Vector3f posLocal;
  EGG::Vector3f prevPosLocal;
  VEC3Transform(&posLocal, &this->mtxInv, &pos);
  if (isfinite(prevPos.y)) {
    VEC3Transform(&prevPosLocal, &this->mtxInv, &prevPos);
  } else {
    prevPosLocal = VEC_INFINITY;
  }

  if (colInfo != nullptr) {
    ColInfoPartial colInfoLocal;
    colInfoLocal.bboxLow.setZero();
    colInfoLocal.bboxHigh.setZero();

    CourseColManager* gColMgr = CourseColManager::spInstance;
    if (gColMgr->getSoftWallColInfo() != nullptr) {
      gColMgr->setLocalMtx(&this->mtx);
    }

    bool hasCol = gColMgr->checkSphereCachedPartialPush(this->colMgr, posLocal, prevPosLocal, typeMask, &colInfoLocal, typeMaskOut, this->kclScale, radius);

    if (hasCol) {
      VEC3TransformSR(&colInfoLocal.bboxLow, &this->mtx, &colInfoLocal.bboxLow);
      VEC3TransformSR(&colInfoLocal.bboxHigh, &this->mtx, &colInfoLocal.bboxHigh);

      EGG::Vector3f tmp = colInfoLocal.bboxLow;
      VEC3Minimize(&colInfoLocal.bboxLow, &tmp, &colInfoLocal.bboxHigh);
      VEC3Maximize(&colInfoLocal.bboxHigh, &tmp, &colInfoLocal.bboxHigh);
      VEC3Minimize(&colInfo->bboxLow, &colInfo->bboxLow, &colInfoLocal.bboxLow);
      VEC3Maximize(&colInfo->bboxHigh, &colInfo->bboxHigh, &colInfoLocal.bboxHigh);

      return true;
    } else {
      return false;
    }
  } else {
    return CourseColManager::spInstance->checkSphereCachedPartialPush(this->colMgr, posLocal, prevPosLocal, typeMask, colInfo, typeMaskOut, this->kclScale, radius);
  }
}

bool ObjColManager::checkSphereCachedFull(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut, f32 radius) {
  if (this->colMgr->cacheEmpty()) return false;

  EGG::Vector3f posLocal;
  EGG::Vector3f prevPosLocal;
  VEC3Transform(&posLocal, &this->mtxInv, &pos);
  f32 inf = 1.0f/0.0f ;
  int x = inf != prevPos.y;
  if (x) {
    VEC3Transform(&prevPosLocal, &this->mtxInv, &prevPos);
  } else {
    prevPosLocal = VEC_INFINITY;
  }

  if (colInfo != nullptr) {
    ColInfo colInfoLocal;
    colInfoLocal.drivableColInfo = nullptr;
    colInfoLocal.bboxLow.setZero();
    colInfoLocal.bboxHigh.setZero();
    colInfoLocal._50 = -FLT_MIN;
    colInfoLocal.wallDist = -FLT_MIN;
    colInfoLocal.floorDist = -FLT_MIN;
    colInfoLocal.colPerpendicularity = 0.0f;

    CourseColManager* gColMgr = CourseColManager::spInstance;
    if (gColMgr->getSoftWallColInfo() != nullptr) {
      gColMgr->setLocalMtx(&this->mtx);
    }

    if (gColMgr->checkSphereCachedFull(this->colMgr, posLocal, prevPosLocal, typeMask, &colInfoLocal, typeMaskOut, this->kclScale, radius)) {
      colInfo->transformInfo(colInfoLocal, this->mtx, this->_68);
      return true;
    } else {
      return false;
    }
  } else {
    return CourseColManager::spInstance->checkSphereCachedFull(this->colMgr, posLocal, prevPosLocal, typeMask, colInfo, typeMaskOut, this->kclScale, radius);
  }
}

bool ObjColManager::checkSphereCachedFullPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut, f32 radius) {
  if (this->colMgr->cacheEmpty()) return false;

  EGG::Vector3f posLocal;
  EGG::Vector3f prevPosLocal;
  VEC3Transform(&posLocal, &this->mtxInv, &pos);
  f32 inf = 1.0f/0.0f ;
  int x = inf != prevPos.y;
  if (x) {
    VEC3Transform(&prevPosLocal, &this->mtxInv, &prevPos);
  } else {
    prevPosLocal = VEC_INFINITY;
  }

  if (colInfo != nullptr) {
    ColInfo colInfoLocal;
    colInfoLocal.drivableColInfo = nullptr;
    colInfoLocal.bboxLow.setZero();
    colInfoLocal.bboxHigh.setZero();
    colInfoLocal._50 = -FLT_MIN;
    colInfoLocal.wallDist = -FLT_MIN;
    colInfoLocal.floorDist = -FLT_MIN;
    colInfoLocal.colPerpendicularity = 0.0f;

    CourseColManager* gColMgr = CourseColManager::spInstance;
    if (gColMgr->getSoftWallColInfo() != nullptr) {
      gColMgr->setLocalMtx(&this->mtx);
    }

    bool hasCol = gColMgr->checkSphereCachedFullPush(this->colMgr, posLocal, prevPosLocal, typeMask, &colInfoLocal, typeMaskOut, this->kclScale, radius);

    if (hasCol) {
      colInfo->transformInfo(colInfoLocal, this->mtx, this->_68);

      return true;
    } else {
      return false;
    }
  } else {
    return CourseColManager::spInstance->checkSphereCachedFullPush(this->colMgr, posLocal, prevPosLocal, typeMask, colInfo, typeMaskOut, this->kclScale, radius);
  }
}
}
