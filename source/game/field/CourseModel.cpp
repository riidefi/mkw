#include "CourseModel.hpp"

// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern function references.
// PAL: 0x8002158c
extern UNKNOWN_FUNCTION(_savegpr_22);
// PAL: 0x80021590
extern UNKNOWN_FUNCTION(_savegpr_23);
// PAL: 0x80021594
extern UNKNOWN_FUNCTION(_savegpr_24);
// PAL: 0x80021598
extern UNKNOWN_FUNCTION(_savegpr_25);
// PAL: 0x800215d8
extern UNKNOWN_FUNCTION(_restgpr_22);
// PAL: 0x800215dc
extern UNKNOWN_FUNCTION(_restgpr_23);
// PAL: 0x800215e0
extern UNKNOWN_FUNCTION(_restgpr_24);
// PAL: 0x800215e4
extern UNKNOWN_FUNCTION(_restgpr_25);
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
// PAL: 0x805411fc
extern UNKNOWN_FUNCTION(getFile__Q26System15ResourceManagerFlPCcPUl);
// PAL: 0x8055b50c
extern UNKNOWN_FUNCTION(unk_8055b50c);
// PAL: 0x8055b618
extern UNKNOWN_FUNCTION(unk_8055b618);
// PAL: 0x8055ba00
extern UNKNOWN_FUNCTION(resourceExists__Q26System10RKResourceFUlPCc);
// PAL: 0x8055c378
extern UNKNOWN_FUNCTION(unk_8055c378);
// PAL: 0x8055eae0
extern UNKNOWN_FUNCTION(unk_8055eae0);
// PAL: 0x805b9010
extern UNKNOWN_FUNCTION(unk_805b9010);
// PAL: 0x805b9124
extern UNKNOWN_FUNCTION(unk_805b9124);
// PAL: 0x805b91d0
extern UNKNOWN_FUNCTION(unk_805b91d0);
// PAL: 0x8078e1b0
extern UNKNOWN_FUNCTION(loadModels__Q25Field11CourseModelFbRQ34nw4r3g3d7ResFilePPQ26System9DrawModelPCcPcUl);
// PAL: 0x80790a68
extern UNKNOWN_FUNCTION(unk_80790a68);
// PAL: 0x807bd930
extern UNKNOWN_FUNCTION(unk_807bd930);
// PAL: 0x807bd954
extern UNKNOWN_FUNCTION(unk_807bd954);
// PAL: 0x807bda7c
extern UNKNOWN_FUNCTION(resetCollisionEntries__5FieldFPUl);
// PAL: 0x807c2824
extern UNKNOWN_FUNCTION(createInstance__Q25Field16CourseColManagerFv);
// PAL: 0x807c2884
extern UNKNOWN_FUNCTION(destroyInstance__Q25Field16CourseColManagerFv);
// PAL: 0x807c28d8
extern UNKNOWN_FUNCTION(init__Q25Field16CourseColManagerFRCQ25Field16KCollisionHeader);
// PAL: 0x807c293c
extern UNKNOWN_FUNCTION(scaledNarrowScopeLocal__Q25Field16CourseColManagerFPQ25Field8RKGndColRCQ23EGG8Vector3fUlffUl);
// PAL: 0x807c2a60
extern UNKNOWN_FUNCTION(checkPointPartial__Q25Field16CourseColManagerFPQ25Field8RKGndColRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUlf);
// PAL: 0x807c2da0
extern UNKNOWN_FUNCTION(checkPointPartialPush__Q25Field16CourseColManagerFPQ25Field8RKGndColRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUlf);
// PAL: 0x807c30e0
extern UNKNOWN_FUNCTION(checkPointFull__Q25Field16CourseColManagerFPQ25Field8RKGndColRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUlf);
// PAL: 0x807c3554
extern UNKNOWN_FUNCTION(checkPointFullPush__Q25Field16CourseColManagerFPQ25Field8RKGndColRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUlf);
// PAL: 0x807c39c8
extern UNKNOWN_FUNCTION(checkSpherePartial__Q25Field16CourseColManagerFPQ25Field8RKGndColRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUlff);
// PAL: 0x807c3b5c
extern UNKNOWN_FUNCTION(checkSpherePartialPush__Q25Field16CourseColManagerFPQ25Field8RKGndColRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUlff);
// PAL: 0x807c3cf0
extern UNKNOWN_FUNCTION(checkSphereFull__Q25Field16CourseColManagerFPQ25Field8RKGndColRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUlff);
// PAL: 0x807c3e84
extern UNKNOWN_FUNCTION(checkSphereFullPush__Q25Field16CourseColManagerFPQ25Field8RKGndColRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUlff);
// PAL: 0x807c4018
extern UNKNOWN_FUNCTION(checkPointCachedPartial__Q25Field16CourseColManagerFPQ25Field8RKGndColRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUlf);
// PAL: 0x807c41a4
extern UNKNOWN_FUNCTION(checkPointCachedPartialPush__Q25Field16CourseColManagerFPQ25Field8RKGndColRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUlf);
// PAL: 0x807c4330
extern UNKNOWN_FUNCTION(checkPointCachedFull__Q25Field16CourseColManagerFPQ25Field8RKGndColRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUlf);
// PAL: 0x807c44bc
extern UNKNOWN_FUNCTION(checkPointCachedFullPush__Q25Field16CourseColManagerFPQ25Field8RKGndColRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUlf);
// PAL: 0x807c4648
extern UNKNOWN_FUNCTION(checkSphereCachedPartial__Q25Field16CourseColManagerFPQ25Field8RKGndColRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUlff);
// PAL: 0x807c47f0
extern UNKNOWN_FUNCTION(checkSphereCachedPartialPush__Q25Field16CourseColManagerFPQ25Field8RKGndColRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUlff);
// PAL: 0x807c4998
extern UNKNOWN_FUNCTION(checkSphereCachedFull__Q25Field16CourseColManagerFPQ25Field8RKGndColRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUlff);
// PAL: 0x807c4b40
extern UNKNOWN_FUNCTION(checkSphereCachedFullPush__Q25Field16CourseColManagerFPQ25Field8RKGndColRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUlff);
// PAL: 0x8081b7cc
extern UNKNOWN_FUNCTION(narrowScopeLocal__Q26GeoObj18ObjDrivableManagerFRCQ23EGG8Vector3ffUlUl);
// PAL: 0x8081b870
extern UNKNOWN_FUNCTION(checkPointPartial__Q26GeoObj18ObjDrivableManagerFRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUl);
// PAL: 0x8081b940
extern UNKNOWN_FUNCTION(checkPointPartialPush__Q26GeoObj18ObjDrivableManagerFRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUl);
// PAL: 0x8081ba10
extern UNKNOWN_FUNCTION(checkPointFull__Q26GeoObj18ObjDrivableManagerFRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUl);
// PAL: 0x8081bb54
extern UNKNOWN_FUNCTION(checkPointFullPush__Q26GeoObj18ObjDrivableManagerFRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUl);
// PAL: 0x8081bc98
extern UNKNOWN_FUNCTION(checkSpherePartial__Q26GeoObj18ObjDrivableManagerFRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUlfUl);
// PAL: 0x8081bd70
extern UNKNOWN_FUNCTION(checkSpherePartialPush__Q26GeoObj18ObjDrivableManagerFRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUlfUl);
// PAL: 0x8081be48
extern UNKNOWN_FUNCTION(checkSphereFull__Q26GeoObj18ObjDrivableManagerFRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUlfUl);
// PAL: 0x8081bfa0
extern UNKNOWN_FUNCTION(checkSphereFullPush__Q26GeoObj18ObjDrivableManagerFRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUlfUl);
// PAL: 0x8081c0f8
extern UNKNOWN_FUNCTION(checkPointCachedPartial__Q26GeoObj18ObjDrivableManagerFRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUl);
// PAL: 0x8081c1e8
extern UNKNOWN_FUNCTION(checkPointCachedPartialPush__Q26GeoObj18ObjDrivableManagerFRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUl);
// PAL: 0x8081c2d8
extern UNKNOWN_FUNCTION(checkPointCachedFull__Q26GeoObj18ObjDrivableManagerFRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUl);
// PAL: 0x8081c43c
extern UNKNOWN_FUNCTION(checkPointCachedFullPush__Q26GeoObj18ObjDrivableManagerFRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUl);
// PAL: 0x8081c5a0
extern UNKNOWN_FUNCTION(checkSphereCachedPartial__Q26GeoObj18ObjDrivableManagerFRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUlfUl);
// PAL: 0x8081c6b4
extern UNKNOWN_FUNCTION(checkSphereCachedPartialPush__Q26GeoObj18ObjDrivableManagerFRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUlfUl);
// PAL: 0x8081c7c8
extern UNKNOWN_FUNCTION(checkSphereCachedFull__Q26GeoObj18ObjDrivableManagerFRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUlfUl);
// PAL: 0x8081c958
extern UNKNOWN_FUNCTION(checkSphereCachedFullPush__Q26GeoObj18ObjDrivableManagerFRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field7ColInfoPUlfUl);// Extern data references.
// PAL: 0x808a4b58
extern UNKNOWN_DATA(lbl_808a4b58);
// PAL: 0x808a6700
extern UNKNOWN_DATA(lbl_808a6700);
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
// PAL: 0x808d1860
extern UNKNOWN_DATA(lbl_808d1860);
// PAL: 0x808d1890
extern UNKNOWN_DATA(lbl_808d1890);
// PAL: 0x808d18c8
extern UNKNOWN_DATA(lbl_808d18c8);
// PAL: 0x809bd728
extern UNKNOWN_DATA(spInstance__Q26System10RaceConfig);
// PAL: 0x809bd738
extern UNKNOWN_DATA(spInstance__Q26System15ResourceManager);
// PAL: 0x809c3c04
extern UNKNOWN_DATA(lbl_809c3c04);
// PAL: 0x809c3c10
extern UNKNOWN_DATA(spInstance__Q25Field16CourseColManager);
// PAL: 0x809c4310
extern UNKNOWN_DATA(spInstance__Q26GeoObj18ObjDrivableManager);
}

// --- EXTERN DECLARATIONS END ---

// .rodata
const u32 lbl_808a4be0[] = {
    0x3f800000
};
const u32 lbl_808a4be4[] = {
    0x302b2800, 0x80800000
};

// .bss
u8 lbl_809c2f40[4];

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
}

// Symbol: CourseModel_setKclWrapper8
// PAL: 0x8078e4e8..0x8078e4f0
MARK_BINARY_BLOB(CourseModel_setKclWrapper8, 0x8078e4e8, 0x8078e4f0);
asm UNKNOWN_FUNCTION(CourseModel_setKclWrapper8) {
  #include "asm/8078e4e8.s"
}

// Symbol: unk_8078e4f0
// PAL: 0x8078e4f0..0x8078e588
MARK_BINARY_BLOB(unk_8078e4f0, 0x8078e4f0, 0x8078e588);
asm UNKNOWN_FUNCTION(unk_8078e4f0) {
  #include "asm/8078e4f0.s"
}

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

// Symbol: unk_8078e8ec
// PAL: 0x8078e8ec..0x8078e8f0
MARK_BINARY_BLOB(unk_8078e8ec, 0x8078e8ec, 0x8078e8f0);
asm UNKNOWN_FUNCTION(unk_8078e8ec) {
  #include "asm/8078e8ec.s"
}

// Symbol: unk_8078e8f0
// PAL: 0x8078e8f0..0x8078ea98
MARK_BINARY_BLOB(unk_8078e8f0, 0x8078e8f0, 0x8078ea98);
asm UNKNOWN_FUNCTION(unk_8078e8f0) {
  #include "asm/8078e8f0.s"
}

// Symbol: unk_8078ea98
// PAL: 0x8078ea98..0x8078eb00
MARK_BINARY_BLOB(unk_8078ea98, 0x8078ea98, 0x8078eb00);
asm UNKNOWN_FUNCTION(unk_8078ea98) {
  #include "asm/8078ea98.s"
}

// Symbol: unk_8078eb00
// PAL: 0x8078eb00..0x8078eca8
MARK_BINARY_BLOB(unk_8078eb00, 0x8078eb00, 0x8078eca8);
asm UNKNOWN_FUNCTION(unk_8078eb00) {
  #include "asm/8078eb00.s"
}

// Symbol: unk_8078eca8
// PAL: 0x8078eca8..0x8078eef4
MARK_BINARY_BLOB(unk_8078eca8, 0x8078eca8, 0x8078eef4);
asm UNKNOWN_FUNCTION(unk_8078eca8) {
  #include "asm/8078eca8.s"
}

// Symbol: unk_8078eef4
// PAL: 0x8078eef4..0x8078f140
MARK_BINARY_BLOB(unk_8078eef4, 0x8078eef4, 0x8078f140);
asm UNKNOWN_FUNCTION(unk_8078eef4) {
  #include "asm/8078eef4.s"
}

// Symbol: unk_8078f140
// PAL: 0x8078f140..0x8078f320
MARK_BINARY_BLOB(unk_8078f140, 0x8078f140, 0x8078f320);
asm UNKNOWN_FUNCTION(unk_8078f140) {
  #include "asm/8078f140.s"
}

// Symbol: unk_8078f320
// PAL: 0x8078f320..0x8078f500
MARK_BINARY_BLOB(unk_8078f320, 0x8078f320, 0x8078f500);
asm UNKNOWN_FUNCTION(unk_8078f320) {
  #include "asm/8078f320.s"
}

// Symbol: unk_8078f500
// PAL: 0x8078f500..0x8078f784
MARK_BINARY_BLOB(unk_8078f500, 0x8078f500, 0x8078f784);
asm UNKNOWN_FUNCTION(unk_8078f500) {
  #include "asm/8078f500.s"
}

// Symbol: unk_8078f784
// PAL: 0x8078f784..0x8078fa08
MARK_BINARY_BLOB(unk_8078f784, 0x8078f784, 0x8078fa08);
asm UNKNOWN_FUNCTION(unk_8078f784) {
  #include "asm/8078f784.s"
}

// Symbol: unk_8078fa08
// PAL: 0x8078fa08..0x8078fbb0
MARK_BINARY_BLOB(unk_8078fa08, 0x8078fa08, 0x8078fbb0);
asm UNKNOWN_FUNCTION(unk_8078fa08) {
  #include "asm/8078fa08.s"
}

// Symbol: unk_8078fbb0
// PAL: 0x8078fbb0..0x8078fd58
MARK_BINARY_BLOB(unk_8078fbb0, 0x8078fbb0, 0x8078fd58);
asm UNKNOWN_FUNCTION(unk_8078fbb0) {
  #include "asm/8078fbb0.s"
}

// Symbol: unk_8078fd58
// PAL: 0x8078fd58..0x8078ffa4
MARK_BINARY_BLOB(unk_8078fd58, 0x8078fd58, 0x8078ffa4);
asm UNKNOWN_FUNCTION(unk_8078fd58) {
  #include "asm/8078fd58.s"
}

// Symbol: unk_8078ffa4
// PAL: 0x8078ffa4..0x807901f0
MARK_BINARY_BLOB(unk_8078ffa4, 0x8078ffa4, 0x807901f0);
asm UNKNOWN_FUNCTION(unk_8078ffa4) {
  #include "asm/8078ffa4.s"
}

// Symbol: unk_807901f0
// PAL: 0x807901f0..0x807903bc
MARK_BINARY_BLOB(unk_807901f0, 0x807901f0, 0x807903bc);
asm UNKNOWN_FUNCTION(unk_807901f0) {
  #include "asm/807901f0.s"
}

// Symbol: unk_807903bc
// PAL: 0x807903bc..0x80790588
MARK_BINARY_BLOB(unk_807903bc, 0x807903bc, 0x80790588);
asm UNKNOWN_FUNCTION(unk_807903bc) {
  #include "asm/807903bc.s"
}

// Symbol: unk_80790588
// PAL: 0x80790588..0x807907f8
MARK_BINARY_BLOB(unk_80790588, 0x80790588, 0x807907f8);
asm UNKNOWN_FUNCTION(unk_80790588) {
  #include "asm/80790588.s"
}

// Symbol: unk_807907f8
// PAL: 0x807907f8..0x80790a68
MARK_BINARY_BLOB(unk_807907f8, 0x807907f8, 0x80790a68);
asm UNKNOWN_FUNCTION(unk_807907f8) {
  #include "asm/807907f8.s"
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

