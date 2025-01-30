#include "CourseModel.hpp"

// .bss
u8 lbl_809c2f40[4];

extern "C" EGG::Vector3f VEC_INFINITY; // TODO: CourseColManager .bss
extern "C" Field::ColInfo* gColInfo; // TODO: CourseColManager .data 0x808a6714

#include "CollisionEntries.hpp"

using namespace System;

namespace Field {
CourseModel* CourseModel::spInstance;

inline KCollisionHeader* getKcl(const char* name) {
  return (KCollisionHeader*)ResourceManager::getInstance()->getFile(1, name, nullptr);
}

void CourseModel::createInstance() {
  if (!spInstance) {
    spInstance = new CourseModel();
  }
}

void CourseModel::destroyInstance() {
  delete spInstance;
  spInstance = nullptr;
}

CourseModel::CourseModel() {
  KCollisionHeader* kclHeader = getKcl("course.kcl");
  CourseColManager::createInstance();
  CourseColManager::spInstance->init(*kclHeader);

  const char* courseBackupName = "course_d_model.brres";
  const char* vrcornBackupName = "vrcorn_d_model.brres";
  const char* courseModelFile =
      RKResource::resourceExists(1, courseBackupName) ? courseBackupName : "course_model.brres";
  const char* vrcornModelFile =
      RKResource::resourceExists(1, vrcornBackupName) ? vrcornBackupName : "vrcorn_model.brres";

  CourseModel::loadModels(true, this->courseRes, &this->courseModel, courseModelFile, "course", 6);
  CourseModel::loadModels(false, this->vrcornRes, &this->vrcornModel, vrcornModelFile, "vrcorn", 4);

  this->softWallColInfo = nullptr;
}

CourseModel::~CourseModel() {
  CourseColManager::destroyInstance();
  delete this->courseModel;
  delete this->vrcornModel;
}

void CourseModel::setSoftWallColInfo(SoftWallColInfo* softWallColInfo) {
  this->softWallColInfo = softWallColInfo;
}

void CourseModel::narrowScopeLocal(const EGG::Vector3f& pos, f32 radius, u32 typeMask, u32 unused) {
  CourseColManager::spInstance->scaledNarrowScopeLocal(nullptr, pos, typeMask, 1.0f, radius, unused);
  GeoObj::ObjDrivableManager::spInstance->narrowScopeLocal(pos, radius, typeMask, unused);
}

struct SoftWallColInfoNuller {
  SoftWallColInfo** accessor;

  SoftWallColInfoNuller();

  ~SoftWallColInfoNuller() {
    if (accessor != nullptr) {
      CourseColManager::spInstance->setSoftWallColInfo(nullptr);
      *accessor = nullptr;
    }
  }
};

SoftWallColInfoNuller::SoftWallColInfoNuller() { }

bool CourseModel::checkPointPartial(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut) {
  SoftWallColInfoNuller nuller;
  nuller.accessor = nullptr;
  if (this->softWallColInfo) {
    nuller.accessor = &this->softWallColInfo;
    CourseColManager::spInstance->setSoftWallColInfo(this->softWallColInfo);
  }

  SoftWallColInfo* swColInfo = this->softWallColInfo;
  if (colInfo != nullptr) {
    colInfo->bboxLow.setZero();
    colInfo->bboxHigh.setZero();
  }
  if (typeMaskOut != nullptr) {
    *typeMaskOut = 0;
  }
  if (swColInfo) {
    swColInfo->bboxLow.setZero();
    swColInfo->bboxHigh.setZero();
    swColInfo->dist = -FLT_MIN;
  }

  bool hasCourseCol = CourseColManager::spInstance->checkPointPartial(nullptr, pos, prevPos, typeMask, colInfo, typeMaskOut, 1.0f);
  bool hasCol = GeoObj::ObjDrivableManager::spInstance->checkPointPartial(pos, prevPos, typeMask, colInfo, typeMaskOut) || hasCourseCol;

  if (hasCol) {
    if (colInfo != nullptr) {
      nw4r::math::VEC3Add(&colInfo->tangentOff, &colInfo->bboxLow, &colInfo->bboxHigh);
    }
    if (swColInfo != nullptr) {
      nw4r::math::VEC3Add(&swColInfo->tangentOff, &swColInfo->bboxLow, &swColInfo->bboxHigh);
    }
  }

  return hasCol;
}

bool CourseModel::checkPointPartialPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut) {
  SoftWallColInfoNuller nuller;
  nuller.accessor = nullptr;
  if (this->softWallColInfo) {
    nuller.accessor = &this->softWallColInfo;
    CourseColManager::spInstance->setSoftWallColInfo(this->softWallColInfo);
  }

  SoftWallColInfo* swColInfo = this->softWallColInfo;
  if (colInfo != nullptr) {
    colInfo->bboxLow.setZero();
    colInfo->bboxHigh.setZero();
  }
  if (typeMaskOut != nullptr) {
    resetCollisionEntries(typeMaskOut);
  }
  if (swColInfo) {
    swColInfo->bboxLow.setZero();
    swColInfo->bboxHigh.setZero();
    swColInfo->dist = -FLT_MIN;
  }

  bool hasCourseCol = CourseColManager::spInstance->checkPointPartialPush(nullptr, pos, prevPos, typeMask, colInfo, typeMaskOut, 1.0f);
  bool hasCol = GeoObj::ObjDrivableManager::spInstance->checkPointPartialPush(pos, prevPos, typeMask, colInfo, typeMaskOut) || hasCourseCol;

  if (hasCol) {
    if (colInfo != nullptr) {
      nw4r::math::VEC3Add(&colInfo->tangentOff, &colInfo->bboxLow, &colInfo->bboxHigh);
    }
    if (swColInfo != nullptr) {
      nw4r::math::VEC3Add(&swColInfo->tangentOff, &swColInfo->bboxLow, &swColInfo->bboxHigh);
    }
  }

  return hasCol;
}

bool CourseModel::checkPointFull(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut) {
  SoftWallColInfoNuller nuller;
  nuller.accessor = nullptr;
  if (this->softWallColInfo) {
    nuller.accessor = &this->softWallColInfo;
    CourseColManager::spInstance->setSoftWallColInfo(this->softWallColInfo);
  }

  SoftWallColInfo* swColInfo = this->softWallColInfo;
  if (colInfo != nullptr) {
    colInfo->bboxLow.setZero();
    colInfo->bboxHigh.setZero();
    colInfo->_50 = -FLT_MIN;
    colInfo->wallDist = -FLT_MIN;
    colInfo->floorDist = -FLT_MIN;
    colInfo->colPerpendicularity = 0.0f;
  }
  if (typeMaskOut != nullptr) {
    *typeMaskOut = 0;
  }
  if (swColInfo) {
    swColInfo->bboxLow.setZero();
    swColInfo->bboxHigh.setZero();
    swColInfo->dist = -FLT_MIN;
  }

  if (colInfo != nullptr) {
    DrivableColInfo* dColInfo = colInfo->drivableColInfo;
    if (colInfo->drivableColInfo != nullptr) {
      if ((dColInfo->flags & 0x100) != 0) {
        typeMask &= dColInfo->unk_807bd954();
        if ((dColInfo->flags & 0x80) != 0) {
          u32 itemStateModifierFlags = 0;
          if (CourseColManager::spInstance->checkPointPartial(
              nullptr, pos, VEC_INFINITY, KCL_ATTRIBUTE_TYPE_BIT(COL_TYPE_ITEM_STATE_MODIFIER), gColInfo, &itemStateModifierFlags, 1.0f)) {
            dColInfo->flags |= 0x400;
          }
        }
      } else {
        dColInfo->unk_807bd930();
      }
    }
  }

  bool hasCourseCol = CourseColManager::spInstance->checkPointFull(nullptr, pos, prevPos, typeMask, colInfo, typeMaskOut, 1.0f);
  bool hasCol = GeoObj::ObjDrivableManager::spInstance->checkPointFull(pos, prevPos, typeMask, colInfo, typeMaskOut) || hasCourseCol;

  if (hasCol) {
    if (colInfo != nullptr) {
      colInfo->calcTangentOff();
    }
    if (swColInfo != nullptr) {
      nw4r::math::VEC3Add(&swColInfo->tangentOff, &swColInfo->bboxLow, &swColInfo->bboxHigh);
    }
  }

  return hasCol;
}

bool CourseModel::checkPointFullPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut) {
  SoftWallColInfoNuller nuller;
  nuller.accessor = nullptr;
  if (this->softWallColInfo) {
    nuller.accessor = &this->softWallColInfo;
    CourseColManager::spInstance->setSoftWallColInfo(this->softWallColInfo);
  }

  SoftWallColInfo* swColInfo = this->softWallColInfo;
  if (colInfo != nullptr) {
    colInfo->bboxLow.setZero();
    colInfo->bboxHigh.setZero();
    colInfo->_50 = -FLT_MIN;
    colInfo->wallDist = -FLT_MIN;
    colInfo->floorDist = -FLT_MIN;
    colInfo->colPerpendicularity = 0.0f;
  }
  if (typeMaskOut != nullptr) {
    resetCollisionEntries(typeMaskOut);
  }
  if (swColInfo) {
    swColInfo->bboxLow.setZero();
    swColInfo->bboxHigh.setZero();
    swColInfo->dist = -FLT_MIN;
  }

  if (colInfo != nullptr) {
    DrivableColInfo* dColInfo = colInfo->drivableColInfo;
    if (colInfo->drivableColInfo != nullptr) {
      if ((dColInfo->flags & 0x100) != 0) {
        typeMask &= dColInfo->unk_807bd954();
        if ((dColInfo->flags & 0x80) != 0) {
          u32 itemStateModifierFlags = 0;
          if (CourseColManager::spInstance->checkPointPartial(
              nullptr, pos, VEC_INFINITY, KCL_ATTRIBUTE_TYPE_BIT(COL_TYPE_ITEM_STATE_MODIFIER), gColInfo, &itemStateModifierFlags, 1.0f)) {
            dColInfo->flags |= 0x400;
          }
        }
      } else {
        dColInfo->unk_807bd930();
      }
    }
  }

  bool hasCourseCol = CourseColManager::spInstance->checkPointFullPush(nullptr, pos, prevPos, typeMask, colInfo, typeMaskOut, 1.0f);
  bool hasCol = GeoObj::ObjDrivableManager::spInstance->checkPointFullPush(pos, prevPos, typeMask, colInfo, typeMaskOut) || hasCourseCol;

  if (hasCol) {
    if (colInfo != nullptr) {
      colInfo->calcTangentOff();
    }
    if (swColInfo != nullptr) {
      nw4r::math::VEC3Add(&swColInfo->tangentOff, &swColInfo->bboxLow, &swColInfo->bboxHigh);
    }
  }

  return hasCol;
}

bool CourseModel::checkSpherePartial(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 radius, u32 start) {
  SoftWallColInfoNuller nuller;
  nuller.accessor = nullptr;
  if (this->softWallColInfo) {
    nuller.accessor = &this->softWallColInfo;
    CourseColManager::spInstance->setSoftWallColInfo(this->softWallColInfo);
  }

  SoftWallColInfo* swColInfo = this->softWallColInfo;
  if (colInfo != nullptr) {
    colInfo->bboxLow.setZero();
    colInfo->bboxHigh.setZero();
  }
  if (typeMaskOut != nullptr) {
    *typeMaskOut = 0;
  }
  if (swColInfo) {
    swColInfo->bboxLow.setZero();
    swColInfo->bboxHigh.setZero();
    swColInfo->dist = -FLT_MIN;
  }

  bool hasCourseCol = typeMask != 0 && CourseColManager::spInstance->checkSpherePartial(nullptr, pos, prevPos, typeMask, colInfo, typeMaskOut, 1.0f, radius);
  bool hasCol = GeoObj::ObjDrivableManager::spInstance->checkSpherePartial(pos, prevPos, typeMask, colInfo, typeMaskOut, radius, start) || hasCourseCol;

  if (hasCol) {
    if (colInfo != nullptr) {
      nw4r::math::VEC3Add(&colInfo->tangentOff, &colInfo->bboxLow, &colInfo->bboxHigh);
    }
    if (swColInfo != nullptr) {
      nw4r::math::VEC3Add(&swColInfo->tangentOff, &swColInfo->bboxLow, &swColInfo->bboxHigh);
    }
  }

  return hasCol;
}

bool CourseModel::checkSpherePartialPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 radius, u32 start) {
  SoftWallColInfoNuller nuller;
  nuller.accessor = nullptr;
  if (this->softWallColInfo) {
    nuller.accessor = &this->softWallColInfo;
    CourseColManager::spInstance->setSoftWallColInfo(this->softWallColInfo);
  }

  SoftWallColInfo* swColInfo = this->softWallColInfo;
  if (colInfo != nullptr) {
    colInfo->bboxLow.setZero();
    colInfo->bboxHigh.setZero();
  }
  if (typeMaskOut != nullptr) {
    resetCollisionEntries(typeMaskOut);
  }
  if (swColInfo) {
    swColInfo->bboxLow.setZero();
    swColInfo->bboxHigh.setZero();
    swColInfo->dist = -FLT_MIN;
  }

  bool hasCourseCol = typeMask != 0 && CourseColManager::spInstance->checkSpherePartialPush(nullptr, pos, prevPos, typeMask, colInfo, typeMaskOut, 1.0f, radius);
  bool hasCol = GeoObj::ObjDrivableManager::spInstance->checkSpherePartialPush(pos, prevPos, typeMask, colInfo, typeMaskOut, radius, start) || hasCourseCol;

  if (hasCol) {
    if (colInfo != nullptr) {
      nw4r::math::VEC3Add(&colInfo->tangentOff, &colInfo->bboxLow, &colInfo->bboxHigh);
    }
    if (swColInfo != nullptr) {
      nw4r::math::VEC3Add(&swColInfo->tangentOff, &swColInfo->bboxLow, &swColInfo->bboxHigh);
    }
  }

  return hasCol;
}

bool CourseModel::checkSphereFull(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut, f32 radius, u32 start) {
  SoftWallColInfoNuller nuller;
  nuller.accessor = nullptr;
  if (this->softWallColInfo) {
    nuller.accessor = &this->softWallColInfo;
    CourseColManager::spInstance->setSoftWallColInfo(this->softWallColInfo);
  }

  SoftWallColInfo* swColInfo = this->softWallColInfo;
  if (colInfo != nullptr) {
    colInfo->bboxLow.setZero();
    colInfo->bboxHigh.setZero();
    colInfo->_50 = -FLT_MIN;
    colInfo->wallDist = -FLT_MIN;
    colInfo->floorDist = -FLT_MIN;
    colInfo->colPerpendicularity = 0.0f;
  }
  if (typeMaskOut != nullptr) {
    *typeMaskOut = 0;
  }
  if (swColInfo) {
    swColInfo->bboxLow.setZero();
    swColInfo->bboxHigh.setZero();
    swColInfo->dist = -FLT_MIN;
  }

  if (colInfo != nullptr) {
    DrivableColInfo* dColInfo = colInfo->drivableColInfo;
    if (colInfo->drivableColInfo != nullptr) {
      if ((dColInfo->flags & 0x100) != 0) {
        typeMask &= dColInfo->unk_807bd954();
        if ((dColInfo->flags & 0x80) != 0) {
          u32 itemStateModifierFlags = 0;
          if (CourseColManager::spInstance->checkPointPartial(
              nullptr, pos, VEC_INFINITY, KCL_ATTRIBUTE_TYPE_BIT(COL_TYPE_ITEM_STATE_MODIFIER), gColInfo, &itemStateModifierFlags, 1.0f)) {
            dColInfo->flags |= 0x400;
          }
        }
      } else {
        dColInfo->unk_807bd930();
      }
    }
  }

  bool hasCourseCol = typeMask != 0 && CourseColManager::spInstance->checkSphereFull(nullptr, pos, prevPos, typeMask, colInfo, typeMaskOut, 1.0f, radius);
  bool hasCol = GeoObj::ObjDrivableManager::spInstance->checkSphereFull(pos, prevPos, typeMask, colInfo, typeMaskOut, radius, start) || hasCourseCol;

  if (hasCol) {
    if (colInfo != nullptr) {
      colInfo->calcTangentOff();
    }
    if (swColInfo != nullptr) {
      nw4r::math::VEC3Add(&swColInfo->tangentOff, &swColInfo->bboxLow, &swColInfo->bboxHigh);
    }
  }

  return hasCol;
}

bool CourseModel::checkSphereFullPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut, f32 radius, u32 start) {
  SoftWallColInfoNuller nuller;
  nuller.accessor = nullptr;
  if (this->softWallColInfo) {
    nuller.accessor = &this->softWallColInfo;
    CourseColManager::spInstance->setSoftWallColInfo(this->softWallColInfo);
  }

  SoftWallColInfo* swColInfo = this->softWallColInfo;
  if (colInfo != nullptr) {
    colInfo->bboxLow.setZero();
    colInfo->bboxHigh.setZero();
    colInfo->_50 = -FLT_MIN;
    colInfo->wallDist = -FLT_MIN;
    colInfo->floorDist = -FLT_MIN;
    colInfo->colPerpendicularity = 0.0f;
  }
  if (typeMaskOut != nullptr) {
    resetCollisionEntries(typeMaskOut);
  }
  if (swColInfo) {
    swColInfo->bboxLow.setZero();
    swColInfo->bboxHigh.setZero();
    swColInfo->dist = -FLT_MIN;
  }

  if (colInfo != nullptr) {
    DrivableColInfo* dColInfo = colInfo->drivableColInfo;
    if (colInfo->drivableColInfo != nullptr) {
      if ((dColInfo->flags & 0x100) != 0) {
        typeMask &= dColInfo->unk_807bd954();
        if ((dColInfo->flags & 0x80) != 0) {
          u32 itemStateModifierFlags = 0;
          if (CourseColManager::spInstance->checkPointPartial(
              nullptr, pos, VEC_INFINITY, KCL_ATTRIBUTE_TYPE_BIT(COL_TYPE_ITEM_STATE_MODIFIER), gColInfo, &itemStateModifierFlags, 1.0f)) {
            dColInfo->flags |= 0x400;
          }
        }
      } else {
        dColInfo->unk_807bd930();
      }
    }
  }

  bool hasCourseCol = typeMask != 0 && CourseColManager::spInstance->checkSphereFullPush(nullptr, pos, prevPos, typeMask, colInfo, typeMaskOut, 1.0f, radius);
  bool hasCol = GeoObj::ObjDrivableManager::spInstance->checkSphereFullPush(pos, prevPos, typeMask, colInfo, typeMaskOut, radius, start) || hasCourseCol;

  if (hasCol) {
    if (colInfo != nullptr) {
      colInfo->calcTangentOff();
    }
    if (swColInfo != nullptr) {
      nw4r::math::VEC3Add(&swColInfo->tangentOff, &swColInfo->bboxLow, &swColInfo->bboxHigh);
    }
  }

  return hasCol;
}

bool CourseModel::checkPointCachedPartial(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut) {
  SoftWallColInfoNuller nuller;
  nuller.accessor = nullptr;
  if (this->softWallColInfo) {
    nuller.accessor = &this->softWallColInfo;
    CourseColManager::spInstance->setSoftWallColInfo(this->softWallColInfo);
  }

  SoftWallColInfo* swColInfo = this->softWallColInfo;
  if (colInfo != nullptr) {
    colInfo->bboxLow.setZero();
    colInfo->bboxHigh.setZero();
  }
  if (typeMaskOut != nullptr) {
    *typeMaskOut = 0;
  }
  if (swColInfo) {
    swColInfo->bboxLow.setZero();
    swColInfo->bboxHigh.setZero();
    swColInfo->dist = -FLT_MIN;
  }

  bool hasCourseCol = CourseColManager::spInstance->checkPointCachedPartial(nullptr, pos, prevPos, typeMask, colInfo, typeMaskOut, 1.0f);
  bool hasCol = GeoObj::ObjDrivableManager::spInstance->checkPointCachedPartial(pos, prevPos, typeMask, colInfo, typeMaskOut) || hasCourseCol;

  if (hasCol) {
    if (colInfo != nullptr) {
      nw4r::math::VEC3Add(&colInfo->tangentOff, &colInfo->bboxLow, &colInfo->bboxHigh);
    }
    if (swColInfo != nullptr) {
      nw4r::math::VEC3Add(&swColInfo->tangentOff, &swColInfo->bboxLow, &swColInfo->bboxHigh);
    }
  }

  return hasCol;
}

bool CourseModel::checkPointCachedPartialPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut) {
  SoftWallColInfoNuller nuller;
  nuller.accessor = nullptr;
  if (this->softWallColInfo) {
    nuller.accessor = &this->softWallColInfo;
    CourseColManager::spInstance->setSoftWallColInfo(this->softWallColInfo);
  }

  SoftWallColInfo* swColInfo = this->softWallColInfo;
  if (colInfo != nullptr) {
    colInfo->bboxLow.setZero();
    colInfo->bboxHigh.setZero();
  }
  if (typeMaskOut != nullptr) {
    resetCollisionEntries(typeMaskOut);
  }
  if (swColInfo) {
    swColInfo->bboxLow.setZero();
    swColInfo->bboxHigh.setZero();
    swColInfo->dist = -FLT_MIN;
  }

  bool hasCourseCol = CourseColManager::spInstance->checkPointCachedPartialPush(nullptr, pos, prevPos, typeMask, colInfo, typeMaskOut, 1.0f);
  bool hasCol = GeoObj::ObjDrivableManager::spInstance->checkPointCachedPartialPush(pos, prevPos, typeMask, colInfo, typeMaskOut) || hasCourseCol;

  if (hasCol) {
    if (colInfo != nullptr) {
      nw4r::math::VEC3Add(&colInfo->tangentOff, &colInfo->bboxLow, &colInfo->bboxHigh);
    }
    if (swColInfo != nullptr) {
      nw4r::math::VEC3Add(&swColInfo->tangentOff, &swColInfo->bboxLow, &swColInfo->bboxHigh);
    }
  }

  return hasCol;
}

bool CourseModel::checkPointCachedFull(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut) {
  SoftWallColInfoNuller nuller;
  nuller.accessor = nullptr;
  if (this->softWallColInfo) {
    nuller.accessor = &this->softWallColInfo;
    CourseColManager::spInstance->setSoftWallColInfo(this->softWallColInfo);
  }

  SoftWallColInfo* swColInfo = this->softWallColInfo;
  if (colInfo != nullptr) {
    colInfo->bboxLow.setZero();
    colInfo->bboxHigh.setZero();
    colInfo->_50 = -FLT_MIN;
    colInfo->wallDist = -FLT_MIN;
    colInfo->floorDist = -FLT_MIN;
    colInfo->colPerpendicularity = 0.0f;
  }
  if (typeMaskOut != nullptr) {
    *typeMaskOut = 0;
  }
  if (swColInfo) {
    swColInfo->bboxLow.setZero();
    swColInfo->bboxHigh.setZero();
    swColInfo->dist = -FLT_MIN;
  }

  if (colInfo != nullptr) {
    DrivableColInfo* dColInfo = colInfo->drivableColInfo;
    if (colInfo->drivableColInfo != nullptr) {
      if ((dColInfo->flags & 0x100) != 0) {
        typeMask &= dColInfo->unk_807bd954();
        if ((dColInfo->flags & 0x80) != 0) {
          u32 itemStateModifierFlags = 0;
          if (CourseColManager::spInstance->checkPointPartial(
              nullptr, pos, VEC_INFINITY, KCL_ATTRIBUTE_TYPE_BIT(COL_TYPE_ITEM_STATE_MODIFIER), gColInfo, &itemStateModifierFlags, 1.0f)) {
            dColInfo->flags |= 0x400;
          }
        }
      } else {
        dColInfo->unk_807bd930();
      }
    }
  }

  bool hasCourseCol = CourseColManager::spInstance->checkPointCachedFull(nullptr, pos, prevPos, typeMask, colInfo, typeMaskOut, 1.0f);
  bool hasCol = GeoObj::ObjDrivableManager::spInstance->checkPointCachedFull(pos, prevPos, typeMask, colInfo, typeMaskOut) || hasCourseCol;

  if (hasCol) {
    if (colInfo != nullptr) {
      colInfo->calcTangentOff();
    }
    if (swColInfo != nullptr) {
      nw4r::math::VEC3Add(&swColInfo->tangentOff, &swColInfo->bboxLow, &swColInfo->bboxHigh);
    }
  }

  return hasCol;
}

bool CourseModel::checkPointCachedFullPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut) {
  SoftWallColInfoNuller nuller;
  nuller.accessor = nullptr;
  if (this->softWallColInfo) {
    nuller.accessor = &this->softWallColInfo;
    CourseColManager::spInstance->setSoftWallColInfo(this->softWallColInfo);
  }

  SoftWallColInfo* swColInfo = this->softWallColInfo;
  if (colInfo != nullptr) {
    colInfo->bboxLow.setZero();
    colInfo->bboxHigh.setZero();
    colInfo->_50 = -FLT_MIN;
    colInfo->wallDist = -FLT_MIN;
    colInfo->floorDist = -FLT_MIN;
    colInfo->colPerpendicularity = 0.0f;
  }
  if (typeMaskOut != nullptr) {
    resetCollisionEntries(typeMaskOut);
  }
  if (swColInfo) {
    swColInfo->bboxLow.setZero();
    swColInfo->bboxHigh.setZero();
    swColInfo->dist = -FLT_MIN;
  }

  if (colInfo != nullptr) {
    DrivableColInfo* dColInfo = colInfo->drivableColInfo;
    if (colInfo->drivableColInfo != nullptr) {
      if ((dColInfo->flags & 0x100) != 0) {
        typeMask &= dColInfo->unk_807bd954();
        if ((dColInfo->flags & 0x80) != 0) {
          u32 itemStateModifierFlags = 0;
          if (CourseColManager::spInstance->checkPointPartial(
              nullptr, pos, VEC_INFINITY, KCL_ATTRIBUTE_TYPE_BIT(COL_TYPE_ITEM_STATE_MODIFIER), gColInfo, &itemStateModifierFlags, 1.0f)) {
            dColInfo->flags |= 0x400;
          }
        }
      } else {
        dColInfo->unk_807bd930();
      }
    }
  }

  bool hasCourseCol = CourseColManager::spInstance->checkPointCachedFullPush(nullptr, pos, prevPos, typeMask, colInfo, typeMaskOut, 1.0f);
  bool hasCol = GeoObj::ObjDrivableManager::spInstance->checkPointCachedFullPush(pos, prevPos, typeMask, colInfo, typeMaskOut) || hasCourseCol;

  if (hasCol) {
    if (colInfo != nullptr) {
      colInfo->calcTangentOff();
    }
    if (swColInfo != nullptr) {
      nw4r::math::VEC3Add(&swColInfo->tangentOff, &swColInfo->bboxLow, &swColInfo->bboxHigh);
    }
  }

  return hasCol;
}

bool CourseModel::checkSphereCachedPartial(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 radius, u32 start) {
  SoftWallColInfoNuller nuller;
  nuller.accessor = nullptr;
  if (this->softWallColInfo) {
    nuller.accessor = &this->softWallColInfo;
    CourseColManager::spInstance->setSoftWallColInfo(this->softWallColInfo);
  }

  SoftWallColInfo* swColInfo = this->softWallColInfo;
  if (colInfo != nullptr) {
    colInfo->bboxLow.setZero();
    colInfo->bboxHigh.setZero();
  }
  if (typeMaskOut != nullptr) {
    *typeMaskOut = 0;
  }
  if (swColInfo) {
    swColInfo->bboxLow.setZero();
    swColInfo->bboxHigh.setZero();
    swColInfo->dist = -FLT_MIN;
  }

  bool hasCourseCol = CourseColManager::spInstance->checkSphereCachedPartial(nullptr, pos, prevPos, typeMask, colInfo, typeMaskOut, 1.0f, radius);
  bool hasCol = GeoObj::ObjDrivableManager::spInstance->checkSphereCachedPartial(pos, prevPos, typeMask, colInfo, typeMaskOut, radius, start) || hasCourseCol;

  if (hasCol) {
    if (colInfo != nullptr) {
      nw4r::math::VEC3Add(&colInfo->tangentOff, &colInfo->bboxLow, &colInfo->bboxHigh);
    }
    if (swColInfo != nullptr) {
      nw4r::math::VEC3Add(&swColInfo->tangentOff, &swColInfo->bboxLow, &swColInfo->bboxHigh);
    }
  }

  return hasCol;
}

bool CourseModel::checkSphereCachedPartialPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 radius, u32 start) {
  SoftWallColInfoNuller nuller;
  nuller.accessor = nullptr;
  if (this->softWallColInfo) {
    nuller.accessor = &this->softWallColInfo;
    CourseColManager::spInstance->setSoftWallColInfo(this->softWallColInfo);
  }

  SoftWallColInfo* swColInfo = this->softWallColInfo;
  if (colInfo != nullptr) {
    colInfo->bboxLow.setZero();
    colInfo->bboxHigh.setZero();
  }
  if (typeMaskOut != nullptr) {
    resetCollisionEntries(typeMaskOut);
  }
  if (swColInfo) {
    swColInfo->bboxLow.setZero();
    swColInfo->bboxHigh.setZero();
    swColInfo->dist = -FLT_MIN;
  }

  bool hasCourseCol = CourseColManager::spInstance->checkSphereCachedPartialPush(nullptr, pos, prevPos, typeMask, colInfo, typeMaskOut, 1.0f, radius);
  bool hasCol = GeoObj::ObjDrivableManager::spInstance->checkSphereCachedPartialPush(pos, prevPos, typeMask, colInfo, typeMaskOut, radius, start) || hasCourseCol;

  if (hasCol) {
    if (colInfo != nullptr) {
      nw4r::math::VEC3Add(&colInfo->tangentOff, &colInfo->bboxLow, &colInfo->bboxHigh);
    }
    if (swColInfo != nullptr) {
      nw4r::math::VEC3Add(&swColInfo->tangentOff, &swColInfo->bboxLow, &swColInfo->bboxHigh);
    }
  }

  return hasCol;
}

bool CourseModel::checkSphereCachedFull(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut, f32 radius, u32 start) {
  SoftWallColInfoNuller nuller;
  nuller.accessor = nullptr;
  if (this->softWallColInfo) {
    nuller.accessor = &this->softWallColInfo;
    CourseColManager::spInstance->setSoftWallColInfo(this->softWallColInfo);
  }

  SoftWallColInfo* swColInfo = this->softWallColInfo;
  if (colInfo != nullptr) {
    colInfo->bboxLow.setZero();
    colInfo->bboxHigh.setZero();
    colInfo->_50 = -FLT_MIN;
    colInfo->wallDist = -FLT_MIN;
    colInfo->floorDist = -FLT_MIN;
    colInfo->colPerpendicularity = 0.0f;
  }
  if (typeMaskOut != nullptr) {
    *typeMaskOut = 0;
  }
  if (swColInfo) {
    swColInfo->bboxLow.setZero();
    swColInfo->bboxHigh.setZero();
    swColInfo->dist = -FLT_MIN;
  }

  if (colInfo != nullptr) {
    DrivableColInfo* dColInfo = colInfo->drivableColInfo;
    if (colInfo->drivableColInfo != nullptr) {
      if ((dColInfo->flags & 0x100) != 0) {
        typeMask &= dColInfo->unk_807bd954();
        if ((dColInfo->flags & 0x80) != 0) {
          u32 itemStateModifierFlags = 0;
          if (CourseColManager::spInstance->checkPointPartial(
              nullptr, pos, VEC_INFINITY, KCL_ATTRIBUTE_TYPE_BIT(COL_TYPE_ITEM_STATE_MODIFIER), gColInfo, &itemStateModifierFlags, 1.0f)) {
            dColInfo->flags |= 0x400;
          }
        }
      } else {
        dColInfo->unk_807bd930();
      }
    }
  }

  bool hasCourseCol = CourseColManager::spInstance->checkSphereCachedFull(nullptr, pos, prevPos, typeMask, colInfo, typeMaskOut, 1.0f, radius);
  bool hasCol = GeoObj::ObjDrivableManager::spInstance->checkSphereCachedFull(pos, prevPos, typeMask, colInfo, typeMaskOut, radius, start) || hasCourseCol;

  if (hasCol) {
    if (colInfo != nullptr) {
      colInfo->calcTangentOff();
    }
    if (swColInfo != nullptr) {
      nw4r::math::VEC3Add(&swColInfo->tangentOff, &swColInfo->bboxLow, &swColInfo->bboxHigh);
    }
  }

  return hasCol;
}

bool CourseModel::checkSphereCachedFullPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut, f32 radius, u32 start) {
  SoftWallColInfoNuller nuller;
  nuller.accessor = nullptr;
  if (this->softWallColInfo) {
    nuller.accessor = &this->softWallColInfo;
    CourseColManager::spInstance->setSoftWallColInfo(this->softWallColInfo);
  }

  SoftWallColInfo* swColInfo = this->softWallColInfo;
  if (colInfo != nullptr) {
    colInfo->bboxLow.setZero();
    colInfo->bboxHigh.setZero();
    colInfo->_50 = -FLT_MIN;
    colInfo->wallDist = -FLT_MIN;
    colInfo->floorDist = -FLT_MIN;
    colInfo->colPerpendicularity = 0.0f;
  }
  if (typeMaskOut != nullptr) {
    resetCollisionEntries(typeMaskOut);
  }
  if (swColInfo) {
    swColInfo->bboxLow.setZero();
    swColInfo->bboxHigh.setZero();
    swColInfo->dist = -FLT_MIN;
  }

  if (colInfo != nullptr) {
    DrivableColInfo* dColInfo = colInfo->drivableColInfo;
    if (colInfo->drivableColInfo != nullptr) {
      if ((dColInfo->flags & 0x100) != 0) {
        typeMask &= dColInfo->unk_807bd954();
        if ((dColInfo->flags & 0x80) != 0) {
          u32 itemStateModifierFlags = 0;
          if (CourseColManager::spInstance->checkPointPartial(
              nullptr, pos, VEC_INFINITY, KCL_ATTRIBUTE_TYPE_BIT(COL_TYPE_ITEM_STATE_MODIFIER), gColInfo, &itemStateModifierFlags, 1.0f)) {
            dColInfo->flags |= 0x400;
          }
        }
      } else {
        dColInfo->unk_807bd930();
      }
    }
  }

  bool hasCourseCol = CourseColManager::spInstance->checkSphereCachedFullPush(nullptr, pos, prevPos, typeMask, colInfo, typeMaskOut, 1.0f, radius);
  bool hasCol = GeoObj::ObjDrivableManager::spInstance->checkSphereCachedFullPush(pos, prevPos, typeMask, colInfo, typeMaskOut, radius, start) || hasCourseCol;

  if (hasCol) {
    if (colInfo != nullptr) {
      colInfo->calcTangentOff();
    }
    if (swColInfo != nullptr) {
      nw4r::math::VEC3Add(&swColInfo->tangentOff, &swColInfo->bboxLow, &swColInfo->bboxHigh);
    }
  }

  return hasCol;
}
}
