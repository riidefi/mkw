#include "CourseModel.hpp"

// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern function references.
// PAL: 0x80025fb0
extern UNKNOWN_FUNCTION(Panic);
// PAL: 0x8004e8f0
extern UNKNOWN_FUNCTION(unk_8004e8f0);
// PAL: 0x80050470
extern UNKNOWN_FUNCTION(unk_80050470);
// PAL: 0x80050ea0
extern UNKNOWN_FUNCTION(unk_80050ea0);
// PAL: 0x8006db90
extern UNKNOWN_FUNCTION(SetMtx);
// PAL: 0x80229dcc
extern UNKNOWN_FUNCTION(__nw__FUl);
// PAL: 0x80230280
extern UNKNOWN_FUNCTION(makeS__Q23EGG9Matrix34fFRCQ23EGG8Vector3f);
// PAL: 0x8055b50c
extern UNKNOWN_FUNCTION(unk_8055b50c);
// PAL: 0x8055b618
extern UNKNOWN_FUNCTION(unk_8055b618);
// PAL: 0x8055c378
extern UNKNOWN_FUNCTION(unk_8055c378);
extern UNKNOWN_FUNCTION(unk_8055c9f0);
extern UNKNOWN_FUNCTION(unk_8055cb08);
extern UNKNOWN_FUNCTION(unk_8055b05c);
extern UNKNOWN_FUNCTION(unk_8055f894);
extern UNKNOWN_FUNCTION(unk_8055f848);
extern UNKNOWN_FUNCTION(unk_8055cd68);
extern UNKNOWN_FUNCTION(unk_805b918c);
extern UNKNOWN_FUNCTION(unk_80072fc0);
extern UNKNOWN_FUNCTION(unk_800730b0);
extern UNKNOWN_FUNCTION(unk_805b92c8);
// PAL: 0x8055eae0
extern UNKNOWN_FUNCTION(unk_8055eae0);
// PAL: 0x805b9010
extern UNKNOWN_FUNCTION(unk_805b9010);
// PAL: 0x805b9124
extern UNKNOWN_FUNCTION(unk_805b9124);
// PAL: 0x805b91d0
extern UNKNOWN_FUNCTION(unk_805b91d0);
// PAL: 0x80790a68
extern UNKNOWN_FUNCTION(unk_80790a68);
// PAL: 0x808b4818
extern UNKNOWN_DATA(lbl_808b4818);
// PAL: 0x808b70fc
extern UNKNOWN_DATA(lbl_808b70fc);
// PAL: 0x808b7118
extern UNKNOWN_DATA(lbl_808b7118);
// PAL: 0x808d18cc
extern UNKNOWN_DATA(lbl_808d18cc);
// PAL: 0x809c19b8
extern UNKNOWN_DATA(lbl_809c19b8);
// PAL: 0x808b4818
extern UNKNOWN_DATA(lbl_808b4818);
// PAL: 0x808b4820
extern UNKNOWN_DATA(lbl_808b4820);
// PAL: 0x808b4840
extern UNKNOWN_DATA(lbl_808b4840);
// PAL: 0x808b7168
extern UNKNOWN_DATA(lbl_808b7168);
// PAL: 0x808b7190
extern UNKNOWN_DATA(lbl_808b7190);
// PAL: 0x808d18c8
extern UNKNOWN_DATA(lbl_808d18c8);
// PAL: 0x809bd728
extern UNKNOWN_DATA(spInstance__Q26System10RaceConfig);
}

// --- EXTERN DECLARATIONS END ---

// .rodata
DEFINE_REL_DATA(lbl_808a4be0, 0x808a4be0, const f32, 1.0f);

#pragma push
#pragma force_active on
void FORCESTRIP _orderfloat() {f32 x = 0.0f;}
#pragma pop

DEFINE_REL_DATA(lbl_808a4b58, 0x808a4b58, const f32, 0.0f);

const u32 lbl_808a4b5c[] = {
    0x302b2800
};
const u32 lbl_808a4b60[] = {
    0x00020300
};
const u32 lbl_808a4b64[] = {
    0x476f616c, 0x5f4d6572, 0x67000000
};
const u32 lbl_808a4b70[] = {
    0x49776100
};
const u32 lbl_808a4b74[] = {
    0x4977615f, 0x616c6661, 0x00000000
};
const u32 lbl_808a4b80[] = {
    0x4e756b69, 0x5f52796f, 0x756d656e, 0x00000000
};
const u32 lbl_808a4b90[] = {
    0x57616c6c, 0x4d657267, 0x30300000
};
const u32 lbl_808a4b9c[] = {
    0x6d6f6f6e, 0x5f6b6162, 0x65303030, 0x30000000
};
const u32 lbl_808a4bac[] = {
    0x6d6f6f6e, 0x5f726f61, 0x64303000
};
const u32 lbl_808a4bb8[] = {
    0x726f6164, 0x00000000
};
const u32 lbl_808a4bc0[] = {
    0x726f6164, 0x30310000
};
const u32 lbl_808a4bc8[] = {
    0x726f6164, 0x30320000
};
const u32 lbl_808a4bd0[] = {
    0x726f6164, 0x30330000
};
const u32 lbl_808a4bd8[] = {
    0x73696261, 0x30300000
};

#pragma explicit_zero_data on
u32 lbl_808d1860[] = {
    (u32)&lbl_808a4b64, (u32)&lbl_808a4b70, (u32)&lbl_808a4b74, (u32)&lbl_808a4b80,
    (u32)&lbl_808a4b90, (u32)&lbl_808a4b9c, (u32)&lbl_808a4bac, (u32)&lbl_808a4bb8,
    (u32)&lbl_808a4bc0, (u32)&lbl_808a4bc8, (u32)&lbl_808a4bd0, (u32)&lbl_808a4bd8
};
u32 lbl_808d1890[] = {
    0x00000000, 0x00000000, (u32)&unk_80790a68, (u32)&unk_8055c9f0,
    (u32)&unk_8055cb08, (u32)&unk_8055b05c, (u32)&unk_8055f894, (u32)&unk_8055f848,
    (u32)&unk_8055cd68, (u32)&unk_805b918c, 0x00000000, 0x00000000,
    (u32)&unk_80790ad0, (u32)&unk_8078de60
};
#pragma explicit_zero_data off

// .bss
u8 lbl_809c2f40[4];

extern "C" EGG::Vector3f VEC_INFINITY; // TODO: CourseColManager .bss
extern "C" Field::ColInfo* gColInfo; // TODO: CourseColManager .data 0x808a6714

// Symbol: unk_8078de04
// PAL: 0x8078de04..0x8078de60
MARK_BINARY_BLOB(unk_8078de04, 0x8078de04, 0x8078de60);
asm UNKNOWN_FUNCTION(unk_8078de04) {
  #include "asm/8078de04.s"
}

// Symbol: unk_8078de60
// PAL: 0x8078de60..0x8078dfe8
MARK_BINARY_BLOB(unk_8078de60, 0x8078de60, 0x8078dfe8);
asm UNKNOWN_FUNCTION(unk_8078de60) {
  #include "asm/8078de60.s"
}

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

// Symbol: loadModels__Q25Field11CourseModelFbRQ34nw4r3g3d7ResFilePPQ26System9DrawModelPCcPcUl
// PAL: 0x8078e1b0..0x8078e33c
MARK_BINARY_BLOB(loadModels__Q25Field11CourseModelFbRQ34nw4r3g3d7ResFilePPQ26System9DrawModelPCcPcUl, 0x8078e1b0, 0x8078e33c);
asm void CourseModel::loadModels(bool isCourse, nw4r::g3d::ResFile& resFile, DrawModel** drawModel, const char* modelPath, char* modelName, u32 flags) {
  #include "asm/8078e1b0.s"
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
}

const u32 lbl_808a4be4[] = {
    0x302b2800
};

// Symbol: unk_8078e588
// PAL: 0x8078e588..0x8078e694
MARK_BINARY_BLOB(unk_8078e588, 0x8078e588, 0x8078e694);
asm UNKNOWN_FUNCTION(unk_8078e588) {
  #include "asm/8078e588.s"
}

// Symbol: unk_8078e694
// PAL: 0x8078e694..0x8078e7c4
MARK_BINARY_BLOB(unk_8078e694, 0x8078e694, 0x8078e7c4);
asm UNKNOWN_FUNCTION(unk_8078e694) {
  #include "asm/8078e694.s"
}

// Symbol: unk_8078e7c4
// PAL: 0x8078e7c4..0x8078e8ec
MARK_BINARY_BLOB(unk_8078e7c4, 0x8078e7c4, 0x8078e8ec);
asm UNKNOWN_FUNCTION(unk_8078e7c4) {
  #include "asm/8078e7c4.s"
}

namespace Field {
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

// Symbol: unk_80790a68
// PAL: 0x80790a68..0x80790ac0
MARK_BINARY_BLOB(unk_80790a68, 0x80790a68, 0x80790ac0);
asm UNKNOWN_FUNCTION(unk_80790a68) {
  #include "asm/80790a68.s"
}

// Symbol: unk_80790ac0
// PAL: 0x80790ac0..0x80790ad0
MARK_BINARY_BLOB(unk_80790ac0, 0x80790ac0, 0x80790ad0);
asm UNKNOWN_FUNCTION(unk_80790ac0) {
  #include "asm/80790ac0.s"
}

// Symbol: unk_80790ad0
// PAL: 0x80790ad0..0x80790ad8
MARK_BINARY_BLOB(unk_80790ad0, 0x80790ad0, 0x80790ad8);
asm UNKNOWN_FUNCTION(unk_80790ad0) {
  #include "asm/80790ad0.s"
}

