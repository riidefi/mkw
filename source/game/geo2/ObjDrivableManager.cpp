#include "ObjDrivableManager.hpp"

// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern function references.
// PAL: 0x80021590
extern UNKNOWN_FUNCTION(_savegpr_23);
// PAL: 0x80021594
extern UNKNOWN_FUNCTION(_savegpr_24);
// PAL: 0x800215dc
extern UNKNOWN_FUNCTION(_restgpr_23);
// PAL: 0x800215e0
extern UNKNOWN_FUNCTION(_restgpr_24);
// PAL: 0x80785ec4
extern UNKNOWN_FUNCTION(unk_80785ec4);
// PAL: 0x80785f2c
extern UNKNOWN_FUNCTION(unk_80785f2c);
// PAL: 0x80786b14
extern UNKNOWN_FUNCTION(unk_80786b14);
// PAL: 0x80786e60
extern UNKNOWN_FUNCTION(isSomeSphereExist__13BoxColManagerCFRCQ23EGG8Vector3fUlf);
// PAL: 0x8081b870
extern UNKNOWN_FUNCTION(unk_8081b870);
// PAL: 0x8081b940
extern UNKNOWN_FUNCTION(unk_8081b940);
// PAL: 0x8081ba10
extern UNKNOWN_FUNCTION(unk_8081ba10);
// PAL: 0x8081bb54
extern UNKNOWN_FUNCTION(unk_8081bb54);
// PAL: 0x8081bc98
extern UNKNOWN_FUNCTION(unk_8081bc98);
// PAL: 0x8081bd70
extern UNKNOWN_FUNCTION(unk_8081bd70);
// PAL: 0x8081be48
extern UNKNOWN_FUNCTION(unk_8081be48);
// PAL: 0x8081bfa0
extern UNKNOWN_FUNCTION(unk_8081bfa0);// Extern data references.
// PAL: 0x809c2ef0
extern UNKNOWN_DATA(lbl_809c2ef0);
}

// --- EXTERN DECLARATIONS END ---

// .rodata
const u32 lbl_808ab558[] = {
    0x00000000
};

namespace GeoObj {
ObjDrivableHolder* ObjDrivableHolder::spInstance;

#define DRIVABLE_HOLDER_MAX_OBJ_COUNT 100
ObjDrivableHolder::ObjDrivableHolder() {
  this->objs       = new ObjDrivable*[DRIVABLE_HOLDER_MAX_OBJ_COUNT];
  this->needUpdate = new ObjDrivable*[DRIVABLE_HOLDER_MAX_OBJ_COUNT];
  this->drawDebug  = new ObjDrivable*[DRIVABLE_HOLDER_MAX_OBJ_COUNT];
}

ObjDrivableHolder::~ObjDrivableHolder() {
  for (u16 i = 0; i < this->objCount; i++) {
    if (this->objs[i]) {
      delete this->objs[i];
      this->objs[i] = nullptr;
    }
  }
}

ObjDrivableHolder* ObjDrivableHolder::createInstance() {
  if (!spInstance) {
    spInstance = new ObjDrivableHolder();
  }

  return spInstance;
}

void ObjDrivableHolder::destroyInstance() {
  if (spInstance) {
    delete spInstance;
    spInstance = nullptr;
  }
}

void ObjDrivableHolder::initObjs() {
  for (u16 i = 0; i < this->objCount; i++) {
    if (this->objs[i] != nullptr) {
      this->objs[i]->loadRoute();
      this->objs[i]->setup();
      this->objs[i]->update();
    }
  }
}

void ObjDrivableHolder::debugDraw() {
  for (u16 i = 0; i < this->drawDebugCount; i++) {
    if (this->drawDebug[i] != nullptr) {
      this->drawDebug[i]->drawDebug();
    }
  }
}

void ObjDrivableHolder::update() {
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

s32 ObjDrivableHolder::push(ObjDrivable* obj) {
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
}

// Symbol: unk_8081b7cc
// PAL: 0x8081b7cc..0x8081b870
MARK_BINARY_BLOB(unk_8081b7cc, 0x8081b7cc, 0x8081b870);
asm UNKNOWN_FUNCTION(unk_8081b7cc) {
  #include "asm/8081b7cc.s"
}

// Symbol: unk_8081b870
// PAL: 0x8081b870..0x8081b940
MARK_BINARY_BLOB(unk_8081b870, 0x8081b870, 0x8081b940);
asm UNKNOWN_FUNCTION(unk_8081b870) {
  #include "asm/8081b870.s"
}

// Symbol: unk_8081b940
// PAL: 0x8081b940..0x8081ba10
MARK_BINARY_BLOB(unk_8081b940, 0x8081b940, 0x8081ba10);
asm UNKNOWN_FUNCTION(unk_8081b940) {
  #include "asm/8081b940.s"
}

// Symbol: unk_8081ba10
// PAL: 0x8081ba10..0x8081bb54
MARK_BINARY_BLOB(unk_8081ba10, 0x8081ba10, 0x8081bb54);
asm UNKNOWN_FUNCTION(unk_8081ba10) {
  #include "asm/8081ba10.s"
}

// Symbol: unk_8081bb54
// PAL: 0x8081bb54..0x8081bc98
MARK_BINARY_BLOB(unk_8081bb54, 0x8081bb54, 0x8081bc98);
asm UNKNOWN_FUNCTION(unk_8081bb54) {
  #include "asm/8081bb54.s"
}

// Symbol: unk_8081bc98
// PAL: 0x8081bc98..0x8081bd70
MARK_BINARY_BLOB(unk_8081bc98, 0x8081bc98, 0x8081bd70);
asm UNKNOWN_FUNCTION(unk_8081bc98) {
  #include "asm/8081bc98.s"
}

// Symbol: unk_8081bd70
// PAL: 0x8081bd70..0x8081be48
MARK_BINARY_BLOB(unk_8081bd70, 0x8081bd70, 0x8081be48);
asm UNKNOWN_FUNCTION(unk_8081bd70) {
  #include "asm/8081bd70.s"
}

// Symbol: unk_8081be48
// PAL: 0x8081be48..0x8081bfa0
MARK_BINARY_BLOB(unk_8081be48, 0x8081be48, 0x8081bfa0);
asm UNKNOWN_FUNCTION(unk_8081be48) {
  #include "asm/8081be48.s"
}

// Symbol: unk_8081bfa0
// PAL: 0x8081bfa0..0x8081c0f8
MARK_BINARY_BLOB(unk_8081bfa0, 0x8081bfa0, 0x8081c0f8);
asm UNKNOWN_FUNCTION(unk_8081bfa0) {
  #include "asm/8081bfa0.s"
}

// Symbol: unk_8081c0f8
// PAL: 0x8081c0f8..0x8081c1e8
MARK_BINARY_BLOB(unk_8081c0f8, 0x8081c0f8, 0x8081c1e8);
asm UNKNOWN_FUNCTION(unk_8081c0f8) {
  #include "asm/8081c0f8.s"
}

// Symbol: unk_8081c1e8
// PAL: 0x8081c1e8..0x8081c2d8
MARK_BINARY_BLOB(unk_8081c1e8, 0x8081c1e8, 0x8081c2d8);
asm UNKNOWN_FUNCTION(unk_8081c1e8) {
  #include "asm/8081c1e8.s"
}

// Symbol: unk_8081c2d8
// PAL: 0x8081c2d8..0x8081c43c
MARK_BINARY_BLOB(unk_8081c2d8, 0x8081c2d8, 0x8081c43c);
asm UNKNOWN_FUNCTION(unk_8081c2d8) {
  #include "asm/8081c2d8.s"
}

// Symbol: unk_8081c43c
// PAL: 0x8081c43c..0x8081c5a0
MARK_BINARY_BLOB(unk_8081c43c, 0x8081c43c, 0x8081c5a0);
asm UNKNOWN_FUNCTION(unk_8081c43c) {
  #include "asm/8081c43c.s"
}

// Symbol: unk_8081c5a0
// PAL: 0x8081c5a0..0x8081c6b4
MARK_BINARY_BLOB(unk_8081c5a0, 0x8081c5a0, 0x8081c6b4);
asm UNKNOWN_FUNCTION(unk_8081c5a0) {
  #include "asm/8081c5a0.s"
}

// Symbol: unk_8081c6b4
// PAL: 0x8081c6b4..0x8081c7c8
MARK_BINARY_BLOB(unk_8081c6b4, 0x8081c6b4, 0x8081c7c8);
asm UNKNOWN_FUNCTION(unk_8081c6b4) {
  #include "asm/8081c6b4.s"
}

// Symbol: unk_8081c7c8
// PAL: 0x8081c7c8..0x8081c958
MARK_BINARY_BLOB(unk_8081c7c8, 0x8081c7c8, 0x8081c958);
asm UNKNOWN_FUNCTION(unk_8081c7c8) {
  #include "asm/8081c7c8.s"
}

// Symbol: unk_8081c958
// PAL: 0x8081c958..0x8081cae8
MARK_BINARY_BLOB(unk_8081c958, 0x8081c958, 0x8081cae8);
asm UNKNOWN_FUNCTION(unk_8081c958) {
  #include "asm/8081c958.s"
}

