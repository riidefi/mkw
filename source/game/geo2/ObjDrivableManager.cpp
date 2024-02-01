#include "ObjDrivableManager.hpp"


namespace GeoObj {
ObjDrivableManager* ObjDrivableManager::spInstance;

#define DRIVABLE_HOLDER_MAX_OBJ_COUNT 100
ObjDrivableManager::ObjDrivableManager() {
  this->objs       = new ObjDrivable*[DRIVABLE_HOLDER_MAX_OBJ_COUNT];
  this->needUpdate = new ObjDrivable*[DRIVABLE_HOLDER_MAX_OBJ_COUNT];
  this->drawDebug  = new ObjDrivable*[DRIVABLE_HOLDER_MAX_OBJ_COUNT];
}

ObjDrivableManager::~ObjDrivableManager() {
  for (u16 i = 0; i < this->objCount; i++) {
    if (this->objs[i]) {
      delete this->objs[i];
      this->objs[i] = nullptr;
    }
  }
}

ObjDrivableManager* ObjDrivableManager::createInstance() {
  if (!spInstance) {
    spInstance = new ObjDrivableManager();
  }

  return spInstance;
}

void ObjDrivableManager::destroyInstance() {
  if (spInstance) {
    delete spInstance;
    spInstance = nullptr;
  }
}

void ObjDrivableManager::initObjs() {
  for (u16 i = 0; i < this->objCount; i++) {
    if (this->objs[i] != nullptr) {
      this->objs[i]->loadRoute();
      this->objs[i]->setup();
      this->objs[i]->update();
    }
  }
}

void ObjDrivableManager::debugDraw() {
  for (u16 i = 0; i < this->drawDebugCount; i++) {
    if (this->drawDebug[i] != nullptr) {
      this->drawDebug[i]->drawDebug();
    }
  }
}

void ObjDrivableManager::update() {
  for (u16 i = 0; i < this->needUpdateCount; i++) {
    if (this->needUpdate[i] != nullptr) {
      this->needUpdate[i]->calc();
    }
  }

  for (u16 i = 0; i < this->needUpdateCount; i++) {
    if (this->needUpdate[i] != nullptr) {
      this->needUpdate[i]->update();
    }
  }
}

s32 ObjDrivableManager::push(ObjDrivable* obj) {
  for (u16 i = 0; i < this->objCount; i++) {
    if (this->objs[i] == obj) {
      return -1;
    }
  }

  if ((obj->getKindFlags() & GEOOBJ_KIND_UPDATE) != 0) {
    this->needUpdate[this->needUpdateCount++] = obj;

  }

  if ((obj->getKindFlags() & GEOOBJ_KIND_DEBUG_DRAW) != 0) {
    this->drawDebug[this->drawDebugCount++] = obj;
  }

  this->objs[this->objCount] = obj;
  obj->managerIdx = this->objCount + 1000;
  this->objCount++;

  return this->objCount - 1;
}

void ObjDrivableManager::narrowScopeLocal(const EGG::Vector3f& pos, f32 radius, u32 colTypeMask, u32 unused) {
  if (objCount != 0) {
    BoxColManager::spInstance->initIterators(pos, radius, BOXCOL_FLAG_DRIVABLE);
    ObjDrivable* drivable;
    while ((drivable = BoxColManager::spInstance->nextDrivable()) != nullptr) {
      drivable->narrowScopeLocal(pos, radius, colTypeMask, unused);
    }
  }
}

bool ObjDrivableManager::checkPointPartial(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfoPartial* colInfo, u32* typeMaskOut) {
  if (objCount == 0) {
    return false;
  } else {
    bool hasCol = false;

    BoxColManager::spInstance->initIterators(pos, 0.0f, BOXCOL_FLAG_DRIVABLE);
    ObjDrivable* drivable;
    while ((drivable = BoxColManager::spInstance->nextDrivable()) != nullptr) {
      if (drivable != nullptr) {
        hasCol = drivable->checkPointPartial(pos, prevPos, typeMask, colInfo, typeMaskOut) || hasCol;
      }
    }

    return hasCol;
  }
}

bool ObjDrivableManager::checkPointPartialPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfoPartial* colInfo, u32* typeMaskOut) {
  if (objCount == 0) {
    return false;
  } else {
    bool hasCol = false;

    BoxColManager::spInstance->initIterators(pos, 0.0f, BOXCOL_FLAG_DRIVABLE);
    ObjDrivable* drivable;
    while ((drivable = BoxColManager::spInstance->nextDrivable()) != nullptr) {
      if (drivable != nullptr) {
        hasCol = drivable->checkPointPartialPush(pos, prevPos, typeMask, colInfo, typeMaskOut) || hasCol;
      }
    }

    return hasCol;
  }
}

bool ObjDrivableManager::checkPointFull(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfo* colInfo, u32* typeMaskOut) {
  if (objCount == 0) {
    return false;
  } else {
    bool hasCol = false;

    ObjDrivable* obj = nullptr;
    if (colInfo) {
      Field::DrivableColInfo* drivableColInfo = colInfo->drivableColInfo;
      if (drivableColInfo) {
        obj = drivableColInfo->getDrivable();
        if (obj) {
          hasCol = true;
          if (obj->checkPointFull(pos, prevPos, typeMask, colInfo, typeMaskOut) == 0) {
            hasCol = false;
          }
        }
      }
    }

    BoxColManager::spInstance->initIterators(pos, 0.0f, BOXCOL_FLAG_DRIVABLE);
    ObjDrivable* drivable;
    while ((drivable = BoxColManager::spInstance->nextDrivable()) != nullptr) {
      if (drivable != obj) {
        hasCol = drivable->checkPointFull(pos, prevPos, typeMask, colInfo, typeMaskOut) || hasCol;
      }
    }

    return hasCol;
  }
}

bool ObjDrivableManager::checkPointFullPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfo* colInfo, u32* typeMaskOut) {
  if (objCount == 0) {
    return false;
  } else {
    bool hasCol = false;

    ObjDrivable* obj = nullptr;
    if (colInfo) {
      Field::DrivableColInfo* drivableColInfo = colInfo->drivableColInfo;
      if (drivableColInfo) {
        obj = drivableColInfo->getDrivable();
        if (obj) {
          hasCol = true;
          if (obj->checkPointFullPush(pos, prevPos, typeMask, colInfo, typeMaskOut) == 0) {
            hasCol = false;
          }
        }
      }
    }

    BoxColManager::spInstance->initIterators(pos, 0.0f, BOXCOL_FLAG_DRIVABLE);
    ObjDrivable* drivable;
    while ((drivable = BoxColManager::spInstance->nextDrivable()) != nullptr) {
      if (drivable != obj) {
        hasCol = drivable->checkPointFullPush(pos, prevPos, typeMask, colInfo, typeMaskOut) || hasCol;
      }
    }

    return hasCol;
  }
}

bool ObjDrivableManager::checkSpherePartial(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfoPartial* colInfo, u32* typeMaskOut, f32 radius, u32 start) {
  if (objCount == 0) {
    return false;
  } else {
    bool hasCol = false;

    BoxColManager::spInstance->initIterators(pos, radius, BOXCOL_FLAG_DRIVABLE);
    ObjDrivable* drivable;
    while ((drivable = BoxColManager::spInstance->nextDrivable()) != nullptr) {
      if (drivable != nullptr) {
        hasCol = drivable->checkSpherePartial(pos, prevPos, typeMask, colInfo, typeMaskOut, radius, start) || hasCol;
      }
    }

    return hasCol;
  }
}

bool ObjDrivableManager::checkSpherePartialPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfoPartial* colInfo, u32* typeMaskOut, f32 radius, u32 start) {
  if (objCount == 0) {
    return false;
  } else {
    bool hasCol = false;

    BoxColManager::spInstance->initIterators(pos, radius, BOXCOL_FLAG_DRIVABLE);
    ObjDrivable* drivable;
    while ((drivable = BoxColManager::spInstance->nextDrivable()) != nullptr) {
      if (drivable != nullptr) {
        hasCol = drivable->checkSpherePartialPush(pos, prevPos, typeMask, colInfo, typeMaskOut, radius, start) || hasCol;
      }
    }

    return hasCol;
  }
}

bool ObjDrivableManager::checkSphereFull(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfo* colInfo, u32* typeMaskOut, f32 radius, u32 start) {
  if (objCount == 0) {
    return false;
  } else {
    bool hasCol = false;

    ObjDrivable* obj = nullptr;
    if (colInfo) {
      Field::DrivableColInfo* drivableColInfo = colInfo->drivableColInfo;
      if (drivableColInfo) {
        obj = drivableColInfo->getDrivable();
        if (obj) {
          hasCol = true;
          if (obj->checkSphereFull(pos, prevPos, typeMask, colInfo, typeMaskOut, radius, start) == 0) {
            hasCol = false;
          }
        }
      }
    }

    BoxColManager::spInstance->initIterators(pos, radius, BOXCOL_FLAG_DRIVABLE);
    ObjDrivable* drivable;
    while ((drivable = BoxColManager::spInstance->nextDrivable()) != nullptr) {
      if (drivable != obj) {
        hasCol = drivable->checkSphereFull(pos, prevPos, typeMask, colInfo, typeMaskOut, radius, start) || hasCol;
      }
    }

    return hasCol;
  }
}

bool ObjDrivableManager::checkSphereFullPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfo* colInfo, u32* typeMaskOut, f32 radius, u32 start) {
  if (objCount == 0) {
    return false;
  } else {
    bool hasCol = false;

    ObjDrivable* obj = nullptr;
    if (colInfo) {
      Field::DrivableColInfo* drivableColInfo = colInfo->drivableColInfo;
      if (drivableColInfo) {
        obj = drivableColInfo->getDrivable();
        if (obj) {
          hasCol = true;
          if (obj->checkSphereFullPush(pos, prevPos, typeMask, colInfo, typeMaskOut, radius, start) == 0) {
            hasCol = false;
          }
        }
      }
    }

    BoxColManager::spInstance->initIterators(pos, radius, BOXCOL_FLAG_DRIVABLE);
    ObjDrivable* drivable;
    while ((drivable = BoxColManager::spInstance->nextDrivable()) != nullptr) {
      if (drivable != obj) {
        hasCol = drivable->checkSphereFullPush(pos, prevPos, typeMask, colInfo, typeMaskOut, radius, start) || hasCol;
      }
    }

    return hasCol;
  }
}

bool ObjDrivableManager::checkPointCachedPartial(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfoPartial* colInfo, u32* typeMaskOut) {
  bool hasCol = false;
  if (!BoxColManager::spInstance->isSphereInSpatialCache(pos, 0.0f, BOXCOL_FLAG_DRIVABLE)) {
    return this->checkPointPartial(pos, prevPos, typeMask, colInfo, typeMaskOut);
  } else {
    BoxColManager::spInstance->resetIterators();
    ObjDrivable* drivable;
    while ((drivable = BoxColManager::spInstance->nextDrivable()) != nullptr) {
      if (drivable != nullptr) {
        hasCol = drivable->checkPointCachedPartial(pos, prevPos, typeMask, colInfo, typeMaskOut) || hasCol;
      }
    }

    return hasCol;
  }
}

bool ObjDrivableManager::checkPointCachedPartialPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfoPartial* colInfo, u32* typeMaskOut) {
  bool hasCol = false;
  if (!BoxColManager::spInstance->isSphereInSpatialCache(pos, 0.0f, BOXCOL_FLAG_DRIVABLE)) {
    return this->checkPointPartialPush(pos, prevPos, typeMask, colInfo, typeMaskOut);
  } else {
    BoxColManager::spInstance->resetIterators();
    ObjDrivable* drivable;
    while ((drivable = BoxColManager::spInstance->nextDrivable()) != nullptr) {
      if (drivable != nullptr) {
        hasCol = drivable->checkPointCachedPartialPush(pos, prevPos, typeMask, colInfo, typeMaskOut) || hasCol;
      }
    }

    return hasCol;
  }
}

bool ObjDrivableManager::checkPointCachedFull(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfo* colInfo, u32* typeMaskOut) {
  bool hasCol = false;
  if (!BoxColManager::spInstance->isSphereInSpatialCache(pos, 0.0f, BOXCOL_FLAG_DRIVABLE)) {
    return this->checkPointFull(pos, prevPos, typeMask, colInfo, typeMaskOut);
  } else {
    ObjDrivable* obj = nullptr;
    if (colInfo) {
      Field::DrivableColInfo* drivableColInfo = colInfo->drivableColInfo;
      if (drivableColInfo) {
        obj = drivableColInfo->getDrivable();
        if (obj) {
          hasCol = true;
          if (obj->checkPointCachedFull(pos, prevPos, typeMask, colInfo, typeMaskOut) == 0) {
            hasCol = false;
          }
        }
      }
    }

    BoxColManager::spInstance->resetIterators();
    ObjDrivable* drivable;
    while ((drivable = BoxColManager::spInstance->nextDrivable()) != nullptr) {
      if (drivable != obj) {
        hasCol = drivable->checkPointCachedFull(pos, prevPos, typeMask, colInfo, typeMaskOut) || hasCol;
      }
    }

    return hasCol;
  }
}

bool ObjDrivableManager::checkPointCachedFullPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfo* colInfo, u32* typeMaskOut) {
  bool hasCol = false;
  if (!BoxColManager::spInstance->isSphereInSpatialCache(pos, 0.0f, BOXCOL_FLAG_DRIVABLE)) {
    return this->checkPointFullPush(pos, prevPos, typeMask, colInfo, typeMaskOut);
  } else {
    ObjDrivable* obj = nullptr;
    if (colInfo) {
      Field::DrivableColInfo* drivableColInfo = colInfo->drivableColInfo;
      if (drivableColInfo) {
        obj = drivableColInfo->getDrivable();
        if (obj) {
          hasCol = true;
          if (obj->checkPointCachedFullPush(pos, prevPos, typeMask, colInfo, typeMaskOut) == 0) {
            hasCol = false;
          }
        }
      }
    }

    BoxColManager::spInstance->resetIterators();
    ObjDrivable* drivable;
    while ((drivable = BoxColManager::spInstance->nextDrivable()) != nullptr) {
      if (drivable != obj) {
        hasCol = drivable->checkPointCachedFullPush(pos, prevPos, typeMask, colInfo, typeMaskOut) || hasCol;
      }
    }

    return hasCol;
  }
}

bool ObjDrivableManager::checkSphereCachedPartial(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfoPartial* colInfo, u32* typeMaskOut, f32 radius, u32 start) {
  if (this->objCount == 0) return false;
  bool hasCol = false;
  if (!BoxColManager::spInstance->isSphereInSpatialCache(pos, radius, BOXCOL_FLAG_DRIVABLE)) {
    return this->checkSpherePartial(pos, prevPos, typeMask, colInfo, typeMaskOut, radius, start);
  } else {
    BoxColManager::spInstance->resetIterators();
    ObjDrivable* drivable;
    while ((drivable = BoxColManager::spInstance->nextDrivable()) != nullptr) {
      if (drivable != nullptr) {
        hasCol = drivable->checkSphereCachedPartial(pos, prevPos, typeMask, colInfo, typeMaskOut, radius, start) || hasCol;
      }
    }

    return hasCol;
  }
}

bool ObjDrivableManager::checkSphereCachedPartialPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfoPartial* colInfo, u32* typeMaskOut, f32 radius, u32 start) {
  if (this->objCount == 0) return false;
  bool hasCol = false;
  if (!BoxColManager::spInstance->isSphereInSpatialCache(pos, radius, BOXCOL_FLAG_DRIVABLE)) {
    return this->checkSpherePartialPush(pos, prevPos, typeMask, colInfo, typeMaskOut, radius, start);
  } else {
    BoxColManager::spInstance->resetIterators();
    ObjDrivable* drivable;
    while ((drivable = BoxColManager::spInstance->nextDrivable()) != nullptr) {
      if (drivable != nullptr) {
        hasCol = drivable->checkSphereCachedPartialPush(pos, prevPos, typeMask, colInfo, typeMaskOut, radius, start) || hasCol;
      }
    }

    return hasCol;
  }
}

bool ObjDrivableManager::checkSphereCachedFull(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfo* colInfo, u32* typeMaskOut, f32 radius, u32 start) {
  if (this->objCount == 0) return false;
  bool hasCol = false;
  if (!BoxColManager::spInstance->isSphereInSpatialCache(pos, radius, BOXCOL_FLAG_DRIVABLE)) {
    return this->checkSphereFull(pos, prevPos, typeMask, colInfo, typeMaskOut, radius, start);
  } else {
    ObjDrivable* obj = nullptr;
    if (colInfo) {
      Field::DrivableColInfo* drivableColInfo = colInfo->drivableColInfo;
      if (drivableColInfo) {
        obj = drivableColInfo->getDrivable();
        if (obj) {
          hasCol = true;
          if (obj->checkSphereCachedFull(pos, prevPos, typeMask, colInfo, typeMaskOut, radius, start) == 0) {
            hasCol = false;
          }
        }
      }
    }

    BoxColManager::spInstance->resetIterators();
    ObjDrivable* drivable;
    while ((drivable = BoxColManager::spInstance->nextDrivable()) != nullptr) {
      if (drivable != obj) {
        hasCol = drivable->checkSphereCachedFull(pos, prevPos, typeMask, colInfo, typeMaskOut, radius, start) || hasCol;
      }
    }

    return hasCol;
  }
}

bool ObjDrivableManager::checkSphereCachedFullPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfo* colInfo, u32* typeMaskOut, f32 radius, u32 start) {
  if (this->objCount == 0) return false;
  bool hasCol = false;
  if (!BoxColManager::spInstance->isSphereInSpatialCache(pos, radius, BOXCOL_FLAG_DRIVABLE)) {
    return this->checkSphereFullPush(pos, prevPos, typeMask, colInfo, typeMaskOut, radius, start);
  } else {
    ObjDrivable* obj = nullptr;
    if (colInfo) {
      Field::DrivableColInfo* drivableColInfo = colInfo->drivableColInfo;
      if (drivableColInfo) {
        obj = drivableColInfo->getDrivable();
        if (obj) {
          hasCol = true;
          if (obj->checkSphereCachedFullPush(pos, prevPos, typeMask, colInfo, typeMaskOut, radius, start) == 0) {
            hasCol = false;
          }
        }
      }
    }

    BoxColManager::spInstance->resetIterators();
    ObjDrivable* drivable;
    while ((drivable = BoxColManager::spInstance->nextDrivable()) != nullptr) {
      if (drivable != obj) {
        hasCol = drivable->checkSphereCachedFullPush(pos, prevPos, typeMask, colInfo, typeMaskOut, radius, start) || hasCol;
      }
    }

    return hasCol;
  }
}
}
