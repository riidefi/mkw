#include "ResourceManager.hpp"

#include <rvl/os/osThread.h>
#include <game/host_system/SystemManager.hpp>
#include <game/RKScene.hpp>

extern RKScene* scenePtr;

extern const char* EarthResourceListing;
const char* EarthResourceListing = "/earth.brres.LZ";

// .rodata
extern const char* COURSE_NAMES[];

extern const int arr_80890AE8[];
const int arr_80890AE8[] = {819200, 921600, 36, 48, 14, 51200};

extern "C" {
extern UNKNOWN_FUNCTION(load__Q26System10DvdArchiveFPCcUlPQ23EGG4Heap);
extern UNKNOWN_FUNCTION(getFileCopy__Q26System10DvdArchiveFPcPQ23EGG4HeapPUlSc);
// PAL: 0x805192cc
extern UNKNOWN_FUNCTION(unmount__Q26System10DvdArchiveFv);
// PAL: 0x8051bed0
extern UNKNOWN_FUNCTION(getGameScene);
extern UNKNOWN_FUNCTION(
    createMultiDvdArchive__6SystemFQ26System17ResourceChannelID);
extern UNKNOWN_FUNCTION(__ct__Q26System16CourseDvdArchiveFv);
// PAL: 0x8052a538
extern UNKNOWN_FUNCTION(__ct__Q26System15MultiDvdArchiveFUs);
// PAL: 0x8052a760
extern UNKNOWN_FUNCTION(getFile__Q26System15MultiDvdArchiveFPCcPUl);
extern UNKNOWN_FUNCTION(isLoaded__Q26System15MultiDvdArchiveFv);
// PAL: 0x8052a864
extern UNKNOWN_FUNCTION(exists__Q26System15MultiDvdArchiveFPCc);
// PAL: 0x8052a954
extern UNKNOWN_FUNCTION(
    load__Q26System15MultiDvdArchiveFPCcPQ23EGG4HeapPQ23EGG4Heapi);
// PAL: 0x8052aa88
extern UNKNOWN_FUNCTION(unmount__Q26System15MultiDvdArchiveFv);
// PAL: 0x8052aae8
extern UNKNOWN_FUNCTION(
    loadOther__Q26System15MultiDvdArchiveFPQ26System15MultiDvdArchivePQ23EGG4Heap);
// PAL: 0x8052ab6c
extern UNKNOWN_FUNCTION(rip__Q26System15MultiDvdArchiveFPCcPQ23EGG4Heap);
// PAL: 0x8052ac40
extern UNKNOWN_FUNCTION(clear__Q26System15MultiDvdArchiveFv);
// PAL: 0x8052ae08
extern UNKNOWN_FUNCTION(rippedArchiveCount__Q26System15MultiDvdArchiveFv);
// PAL: 0x80552d90
extern UNKNOWN_FUNCTION(getSlotForCourseId);
// PAL: 0x805553b0
extern UNKNOWN_FUNCTION(unk_805553b0);
}

namespace System {

ResourceManager* ResourceManager::createInstance() {
  if (spInstance == nullptr) {
    spInstance = new ResourceManager();
  }

  return spInstance;
}

void ResourceManager::destroyInstance() {
  if (spInstance != nullptr) {
    delete spInstance;
  }
  spInstance = nullptr;
}

ResourceManager::ResourceManager() {
  foo();
  taskThread = EGG::TaskThread::create(14, 24, 0xC800, scenePtr->getA());
  taskThread->mTaskEndMessageQueue = &System::SystemManager::sInstance->_B8;
  multiArchives1 = new MultiDvdArchive*[9];
  for (u16 i = 0; i < 9; ++i) {
    multiArchives1[i] = createMultiDvdArchive((ResourceChannelID)i);
  }
  bar();
}

System::ResourceManager::~ResourceManager() {
  taskThread->destroy();
  taskThread = nullptr;
}

} // namespace System

// Symbol: unk_80540038
// PAL: 0x80540038..0x805400a0
MARK_BINARY_BLOB(unk_80540038, 0x80540038, 0x805400a0);
asm UNKNOWN_FUNCTION(unk_80540038) {
  // clang-format off
  nofralloc;
  lis r4, 0;
  cmpwi r3, 6;
  mulli r0, r3, 0x54;
  lwz r4, 0(r4);
  add r6, r4, r0;
  beq lbl_8054005c;
  cmpwi r3, 5;
  beq lbl_80540070;
  b lbl_80540088;
lbl_8054005c:
  lwz r3, 0x33c(r6);
  addi r4, r6, 0x344;
  lwz r5, 0x340(r6);
  lwz r6, 0x384(r6);
  b load__Q26System10DvdArchiveFPCcUlPQ23EGG4Heap;
lbl_80540070:
  lwz r3, 0x338(r6);
  addi r4, r6, 0x344;
  lwz r5, 0x384(r6);
  li r7, 0;
  lwz r6, 0x388(r6);
  b load__Q26System15MultiDvdArchiveFPCcPQ23EGG4HeapPQ23EGG4Heapi;
lbl_80540088:
  lwz r3, 0x338(r6);
  addi r4, r6, 0x344;
  lwz r5, 0x384(r6);
  li r6, 0;
  li r7, 0;
  b load__Q26System15MultiDvdArchiveFPCcPQ23EGG4HeapPQ23EGG4Heapi;
  // clang-format on
}

// Symbol: process__Q26System15ResourceManagerFv
// PAL: 0x805400a0..0x805401ec
MARK_BINARY_BLOB(process__Q26System15ResourceManagerFv, 0x805400a0, 0x805401ec);
asm UNKNOWN_FUNCTION(process__Q26System15ResourceManagerFv) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stmw r27, 0xc(r1);
  mr r27, r3;
  li r28, 0;
  lis r31, 0;
  lis r29, 0;
  lis r30, 0;
  b lbl_805401c8;
lbl_805400c8:
  lwz r3, 0(r29);
  lwz r3, 0x4c(r3);
  lwz r12, 4(r3);
  lwz r12, 0x14(r12);
  mtctr r12;
  bctrl;
  lwz r3, 0(r29);
  lwz r3, 0x4c(r3);
  lwz r12, 4(r3);
  lwz r12, 8(r12);
  mtctr r12;
  bctrl;
  lwz r3, 0(r31);
  lbz r0, 0x51(r3);
  cmpwi r0, 0;
  beq lbl_80540134;
  cmpwi r28, 0;
  bne lbl_80540124;
  li r3, 0;
  bl unk_805553b0;
  lwz r3, 0x584(r27);
  lwz r3, 8(r3);
  bl unk_805553b0;
lbl_80540124:
  lwz r3, 0(r31);
  li r28, 1;
  bl unk_805553b0;
  b lbl_80540164;
lbl_80540134:
  cmpwi r28, 0;
  beq lbl_80540148;
  lwz r3, 0x584(r27);
  lwz r3, 8(r3);
  bl unk_805553b0;
lbl_80540148:
  lwz r3, 0(r29);
  li r28, 0;
  lwz r3, 0x54(r3);
  lwz r12, 0(r3);
  lwz r12, 0x24(r12);
  mtctr r12;
  bctrl;
lbl_80540164:
  lwz r3, 0(r30);
  bl unk_805553b0;
  lwz r3, 0(r29);
  lwz r3, 0x4c(r3);
  lwz r12, 4(r3);
  lwz r12, 0xc(r12);
  mtctr r12;
  bctrl;
  cmpwi r28, 0;
  beq lbl_80540198;
  lwz r3, 0(r31);
  bl unk_805553b0;
  b lbl_805401b0;
lbl_80540198:
  lwz r3, 0(r29);
  lwz r3, 0x54(r3);
  lwz r12, 0(r3);
  lwz r12, 0x28(r12);
  mtctr r12;
  bctrl;
lbl_805401b0:
  lwz r3, 0(r29);
  lwz r3, 0x4c(r3);
  lwz r12, 4(r3);
  lwz r12, 0x10(r12);
  mtctr r12;
  bctrl;
lbl_805401c8:
  lwz r3, 0x584(r27);
  bl unk_805553b0;
  cmpwi r3, 0;
  bne lbl_805400c8;
  lmw r27, 0xc(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_805401ec
// PAL: 0x805401ec..0x805401fc
MARK_BINARY_BLOB(unk_805401ec, 0x805401ec, 0x805401fc);
asm UNKNOWN_FUNCTION(unk_805401ec) {
  // clang-format off
  nofralloc;
  lwz r12, 0(r3);
  lwz r12, 0x14(r12);
  mtctr r12;
  bctr;
  // clang-format on
}

// Symbol: unk_805401fc
// PAL: 0x805401fc..0x8054020c
MARK_BINARY_BLOB(unk_805401fc, 0x805401fc, 0x8054020c);
asm UNKNOWN_FUNCTION(unk_805401fc) {
  // clang-format off
  nofralloc;
  lwz r12, 0(r3);
  lwz r12, 0x1c(r12);
  mtctr r12;
  bctr;
  // clang-format on
}

// Symbol: unk_8054020c
// PAL: 0x8054020c..0x805402c0
/*MARK_BINARY_BLOB(unk_8054020c, 0x8054020c, 0x805402c0);
asm UNKNOWN_FUNCTION(unk_8054020c) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stmw r27, 0xc(r1);
  mr r28, r4;
  mulli r31, r28, 0x54;
  mr r27, r3;
  mr r29, r5;
  mr r4, r6;
  add r3, r3, r31;
  mr r30, r7;
  stw r5, 0x338(r3);
  addi r3, r3, 0x344;
  li r5, 0x40;
  bl unk_805553b0;
  add r3, r27, r31;
  lis r4, 0;
  stw r30, 0x384(r3);
  mr r5, r28;
  addi r4, r4, 0;
  li r6, 0;
  lwz r3, 0x584(r27);
  bl unk_805553b0;
  mr r3, r27;
  bl process__Q26System15ResourceManagerFv;
  mr r3, r29;
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  bne lbl_805402ac;
  lis r4, 0x8000;
  lis r3, 0x1062;
  lwz r0, 0xf8(r4);
  addi r4, r3, 0x4dd3;
  li r3, 0;
  srwi r0, r0, 2;
  mulhwu r4, r4, r0;
  srwi r0, r4, 6;
  rlwinm r4, r4, 0x1e, 2, 0x1b;
  rlwimi r3, r0, 4, 0x1c, 0x1f;
  bl unk_805553b0;
lbl_805402ac:
  lmw r27, 0xc(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}*/

namespace System {
void ResourceManager::requestLoad(s32 idx, MultiDvdArchive* m, const char* p,
                                  EGG::Heap* archiveHeap) {
  this->jobContexts[idx].multiArchive = m;
  strncpy(this->jobContexts[idx].filename, p, 0x40);
  this->jobContexts[idx].archiveHeap = archiveHeap;

  this->taskThread->request(ResourceManager::doLoadTask, (void*)idx, 0);
  this->process();

  if (!m->isLoaded()) {
    OSSleepMilliseconds(16);
  }
}
} // namespace System

// Symbol: unk_805402c0
// PAL: 0x805402c0..0x80540394
MARK_BINARY_BLOB(unk_805402c0, 0x805402c0, 0x80540394);
asm UNKNOWN_FUNCTION(unk_805402c0) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stmw r26, 8(r1);
  mr r27, r4;
  mulli r31, r27, 0x54;
  mr r26, r3;
  mr r28, r5;
  mr r4, r6;
  add r3, r3, r31;
  mr r29, r7;
  mr r30, r8;
  stw r5, 0x33c(r3);
  addi r3, r3, 0x344;
  li r5, 0x40;
  bl unk_805553b0;
  add r3, r26, r31;
  lis r4, 0;
  stw r30, 0x384(r3);
  mr r5, r27;
  addi r4, r4, 0;
  li r6, 0;
  stw r29, 0x340(r3);
  lwz r3, 0x584(r26);
  bl unk_805553b0;
  mr r3, r26;
  bl process__Q26System15ResourceManagerFv;
  lwz r0, 0x20(r28);
  li r3, 0;
  cmpwi r0, 4;
  beq lbl_80540348;
  lwz r0, 0x20(r28);
  cmpwi r0, 5;
  bne lbl_8054034c;
lbl_80540348:
  li r3, 1;
lbl_8054034c:
  cmpwi r3, 0;
  bne lbl_80540380;
  lis r4, 0x8000;
  lis r3, 0x1062;
  lwz r0, 0xf8(r4);
  addi r4, r3, 0x4dd3;
  li r3, 0;
  srwi r0, r0, 2;
  mulhwu r4, r4, r0;
  srwi r0, r4, 6;
  rlwinm r4, r4, 0x1e, 2, 0x1b;
  rlwimi r3, r0, 4, 0x1c, 0x1f;
  bl unk_805553b0;
lbl_80540380:
  lmw r26, 8(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_80540394
// PAL: 0x80540394..0x80540450
MARK_BINARY_BLOB(unk_80540394, 0x80540394, 0x80540450);
asm UNKNOWN_FUNCTION(unk_80540394) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stmw r26, 8(r1);
  mr r27, r4;
  mulli r31, r27, 0x54;
  mr r26, r3;
  mr r28, r5;
  mr r4, r6;
  add r3, r3, r31;
  mr r29, r7;
  mr r30, r8;
  stw r5, 0x338(r3);
  addi r3, r3, 0x344;
  li r5, 0x40;
  bl unk_805553b0;
  add r3, r26, r31;
  lis r4, 0;
  stw r29, 0x384(r3);
  mr r5, r27;
  addi r4, r4, 0;
  li r6, 0;
  stw r30, 0x388(r3);
  lwz r3, 0x584(r26);
  bl unk_805553b0;
  mr r3, r26;
  bl process__Q26System15ResourceManagerFv;
  mr r3, r28;
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  bne lbl_8054043c;
  lis r4, 0x8000;
  lis r3, 0x1062;
  lwz r0, 0xf8(r4);
  addi r4, r3, 0x4dd3;
  li r3, 0;
  srwi r0, r0, 2;
  mulhwu r4, r4, r0;
  srwi r0, r4, 6;
  rlwinm r4, r4, 0x1e, 2, 0x1b;
  rlwimi r3, r0, 4, 0x1c, 0x1f;
  bl unk_805553b0;
lbl_8054043c:
  lmw r26, 8(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: ResourceManager_load
// PAL: 0x80540450..0x80540558
MARK_BINARY_BLOB(ResourceManager_load, 0x80540450, 0x80540558);
asm UNKNOWN_FUNCTION(ResourceManager_load) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  cmpwi r6, 0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r3;
  stw r30, 0x18(r1);
  mr r30, r6;
  stw r29, 0x14(r1);
  stw r28, 0x10(r1);
  mr r28, r5;
  bne lbl_80540490;
  lis r5, 0;
  slwi r0, r4, 2;
  addi r5, r5, 0;
  lwzx r30, r5, r0;
lbl_80540490:
  lwz r3, 4(r3);
  slwi r29, r4, 2;
  lwzx r3, r3, r29;
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  bne lbl_80540530;
  lbz r0, 0(r30);
  extsb. r0, r0;
  beq lbl_80540530;
  lwz r6, 4(r31);
  mr r4, r30;
  addi r3, r31, 0x344;
  li r5, 0x40;
  lwzx r30, r6, r29;
  stw r30, 0x338(r31);
  bl unk_805553b0;
  lis r4, 0;
  stw r28, 0x384(r31);
  lwz r3, 0x584(r31);
  addi r4, r4, 0;
  li r5, 0;
  li r6, 0;
  bl unk_805553b0;
  mr r3, r31;
  bl process__Q26System15ResourceManagerFv;
  mr r3, r30;
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  bne lbl_80540530;
  lis r4, 0x8000;
  lis r3, 0x1062;
  lwz r0, 0xf8(r4);
  addi r4, r3, 0x4dd3;
  li r3, 0;
  srwi r0, r0, 2;
  mulhwu r4, r4, r0;
  srwi r0, r4, 6;
  rlwinm r4, r4, 0x1e, 2, 0x1b;
  rlwimi r3, r0, 4, 0x1c, 0x1f;
  bl unk_805553b0;
lbl_80540530:
  lwz r3, 4(r31);
  lwz r31, 0x1c(r1);
  lwzx r3, r3, r29;
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_80540558
// PAL: 0x80540558..0x80540680
MARK_BINARY_BLOB(unk_80540558, 0x80540558, 0x80540680);
asm UNKNOWN_FUNCTION(unk_80540558) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stmw r26, 8(r1);
  mulli r31, r4, 0x24;
  mr r30, r3;
  mr r26, r4;
  add r28, r3, r31;
  mr r27, r5;
  li r3, 1;
  lwz r0, 0x2c8(r28);
  cmpwi r0, 4;
  beq lbl_8054059c;
  lwz r0, 0x2c8(r28);
  cmpwi r0, 5;
  beq lbl_8054059c;
  li r3, 0;
lbl_8054059c:
  cmpwi r3, 0;
  bne lbl_80540664;
  mr r3, r26;
  bl unk_805553b0;
  lbz r0, 0(r3);
  extsb. r0, r0;
  beq lbl_80540664;
  mr r3, r26;
  bl unk_805553b0;
  mr r29, r3;
  mr r3, r26;
  bl unk_805553b0;
  add r5, r30, r31;
  mr r4, r3;
  addi r0, r5, 0x2a8;
  stw r0, 0x534(r30);
  addi r3, r30, 0x53c;
  li r5, 0x40;
  bl unk_805553b0;
  lis r4, 0;
  stw r27, 0x57c(r30);
  lwz r3, 0x584(r30);
  addi r4, r4, 0;
  stw r29, 0x538(r30);
  li r5, 6;
  li r6, 0;
  bl unk_805553b0;
  mr r3, r30;
  bl process__Q26System15ResourceManagerFv;
  lwz r0, 0x2c8(r28);
  li r3, 0;
  cmpwi r0, 4;
  beq lbl_8054062c;
  lwz r0, 0x2c8(r28);
  cmpwi r0, 5;
  bne lbl_80540630;
lbl_8054062c:
  li r3, 1;
lbl_80540630:
  cmpwi r3, 0;
  bne lbl_80540664;
  lis r4, 0x8000;
  lis r3, 0x1062;
  lwz r0, 0xf8(r4);
  addi r4, r3, 0x4dd3;
  li r3, 0;
  srwi r0, r0, 2;
  mulhwu r4, r4, r0;
  srwi r0, r4, 6;
  rlwinm r4, r4, 0x1e, 2, 0x1b;
  rlwimi r3, r0, 4, 0x1c, 0x1f;
  bl unk_805553b0;
lbl_80540664:
  add r3, r30, r31;
  lmw r26, 8(r1);
  lwz r0, 0x24(r1);
  addi r3, r3, 0x2a8;
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: ResourceManager_loadUI
// PAL: 0x80540680..0x80540760
MARK_BINARY_BLOB(ResourceManager_loadUI, 0x80540680, 0x80540760);
asm UNKNOWN_FUNCTION(ResourceManager_loadUI) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r4;
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r3;
  lwz r6, 4(r3);
  lwz r3, 8(r6);
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  bne lbl_8054073c;
  cmpwi r31, 0;
  beq lbl_8054073c;
  lwz r6, 4(r29);
  mr r4, r31;
  addi r3, r29, 0x398;
  li r5, 0x40;
  lwz r31, 8(r6);
  stw r31, 0x38c(r29);
  bl unk_805553b0;
  lis r4, 0;
  stw r30, 0x3d8(r29);
  lwz r3, 0x584(r29);
  addi r4, r4, 0;
  li r5, 1;
  li r6, 0;
  bl unk_805553b0;
  mr r3, r29;
  bl process__Q26System15ResourceManagerFv;
  mr r3, r31;
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  bne lbl_8054073c;
  lis r4, 0x8000;
  lis r3, 0x1062;
  lwz r0, 0xf8(r4);
  addi r4, r3, 0x4dd3;
  li r3, 0;
  srwi r0, r0, 2;
  mulhwu r4, r4, r0;
  srwi r0, r4, 6;
  rlwinm r4, r4, 0x1e, 2, 0x1b;
  rlwimi r3, r0, 4, 0x1c, 0x1f;
  bl unk_805553b0;
lbl_8054073c:
  lwz r3, 4(r29);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r0, 0x24(r1);
  lwz r3, 8(r3);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: ResourceManager_loadCourse
// PAL: 0x80540760..0x80540918
/*MARK_BINARY_BLOB(ResourceManager_loadCourse, 0x80540760, 0x80540918);
asm UNKNOWN_FUNCTION(ResourceManager_loadCourse) {
  // clang-format off
  nofralloc;
  stwu r1, -0xa0(r1);
  mflr r0;
  stw r0, 0xa4(r1);
  stw r31, 0x9c(r1);
  mr r31, r3;
  stw r30, 0x98(r1);
  mr r30, r6;
  stw r29, 0x94(r1);
  mr r29, r5;
  stw r28, 0x90(r1);
  mr r28, r4;
  lwz r7, 4(r3);
  lwz r3, 4(r7);
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  bne lbl_805408f0;
  lwz r3, 4(r31);
  lwz r3, 4(r3);
  lwz r12, 0(r3);
  lwz r12, 0xc(r12);
  mtctr r12;
  bctrl;
  cmpwi r30, 0;
  bne lbl_805407f4;
  lwz r0, 0x5a4(r31);
  cmpwi cr6, r0, 2;
  bne cr6, lbl_805407f4;
  lwz r0, 0x5a0(r31);
  cmpw r28, r0;
  bne lbl_805407f4;
  lwz r3, 4(r31);
  lwz r3, 4(r3);
  bne cr6, lbl_805408f0;
  lwz r4, 0x5a8(r31);
  mr r5, r29;
  bl
loadOther__Q26System15MultiDvdArchiveFPQ26System15MultiDvdArchivePQ23EGG4Heap;
  b lbl_805408f0;
lbl_805407f4:
  cmpwi r30, 0;
  beq lbl_80540840;
  lis r4, 0;
  lis r5, 0;
  slwi r0, r28, 2;
  addi r3, r1, 8;
  addi r4, r4, 0;
  addi r5, r5, 0;
  lwzx r6, r4, r0;
  li r4, 0x80;
  crclr 6;
  bl unk_805553b0;
  lwz r3, 4(r31);
  addi r4, r1, 8;
  lwz r3, 4(r3);
  bl exists__Q26System15MultiDvdArchiveFPCc;
  cmpwi r3, 0;
  bne lbl_80540840;
  li r30, 0;
lbl_80540840:
  cmpwi r30, 0;
  bne lbl_80540874;
  lis r4, 0;
  lis r5, 0;
  slwi r0, r28, 2;
  addi r3, r1, 8;
  addi r4, r4, 0;
  addi r5, r5, 0;
  lwzx r6, r4, r0;
  addi r5, r5, 0x11;
  li r4, 0x80;
  crclr 6;
  bl unk_805553b0;
lbl_80540874:
  lwz r6, 4(r31);
  addi r3, r31, 0x3ec;
  addi r4, r1, 8;
  li r5, 0x40;
  lwz r30, 4(r6);
  stw r30, 0x3e0(r31);
  bl unk_805553b0;
  lis r4, 0;
  stw r29, 0x42c(r31);
  lwz r3, 0x584(r31);
  addi r4, r4, 0;
  li r5, 2;
  li r6, 0;
  bl unk_805553b0;
  mr r3, r31;
  bl process__Q26System15ResourceManagerFv;
  mr r3, r30;
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  bne lbl_805408f0;
  lis r4, 0x8000;
  lis r3, 0x1062;
  lwz r0, 0xf8(r4);
  addi r4, r3, 0x4dd3;
  li r3, 0;
  srwi r0, r0, 2;
  mulhwu r4, r4, r0;
  srwi r0, r4, 6;
  rlwinm r4, r4, 0x1e, 2, 0x1b;
  rlwimi r3, r0, 4, 0x1c, 0x1f;
  bl unk_805553b0;
lbl_805408f0:
  lwz r3, 4(r31);
  lwz r31, 0x9c(r1);
  lwz r30, 0x98(r1);
  lwz r29, 0x94(r1);
  lwz r28, 0x90(r1);
  lwz r0, 0xa4(r1);
  lwz r3, 4(r3);
  mtlr r0;
  addi r1, r1, 0xa0;
  blr;
  // clang-format on
}*/

namespace System {
MultiDvdArchive* ResourceManager::loadCourse(CourseId courseId,
                                             EGG::Heap* param_3,
                                             bool splitScreen) {
  char courseName[128];

  if (!this->multiArchives1[1]->isLoaded()) {
    this->multiArchives1[1]->init();
    if (!splitScreen && this->courseCache.mState == 2 &&
        courseId == this->courseCache.mCourseId) {
      MultiDvdArchive* m = this->multiArchives1[1];
      if (this->courseCache.mState == 2)
        m->loadOther(this->courseCache.mArchive, param_3);
    } else {
      if (splitScreen) {
        snprintf(courseName, sizeof(courseName), "Race/Course/%s_d",
                 COURSE_NAMES[courseId]);
        if (!this->multiArchives1[1]->exists(courseName)) {
          splitScreen = false;
        }
      }
      if (!splitScreen) {
        snprintf(courseName, sizeof(courseName), "Race/Course/%s",
                 COURSE_NAMES[courseId]);
      }
      requestLoad(2, this->multiArchives1[1], courseName, param_3);
    }
  }
  return this->multiArchives1[1];
}

} // namespace System

// Symbol: ResourceManager_loadMission
// PAL: 0x80540918..0x80540b14
MARK_BINARY_BLOB(ResourceManager_loadMission, 0x80540918, 0x80540b14);
asm UNKNOWN_FUNCTION(ResourceManager_loadMission) {
  // clang-format off
  nofralloc;
  stwu r1, -0x120(r1);
  mflr r0;
  stw r0, 0x124(r1);
  stmw r27, 0x10c(r1);
  mr r28, r3;
  mr r29, r4;
  mr r27, r5;
  mr r30, r6;
  mr r31, r7;
  lwz r8, 4(r3);
  lwz r3, 4(r8);
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  bne lbl_80540af8;
  lwz r3, 4(r28);
  lwz r3, 4(r3);
  lwz r12, 0(r3);
  lwz r12, 0xc(r12);
  mtctr r12;
  bctrl;
  lis r4, 0;
  mr r6, r27;
  addi r4, r4, 0;
  addi r3, r1, 0x88;
  addi r5, r4, 0x20;
  li r4, 0x80;
  crclr 6;
  bl unk_805553b0;
  lwz r3, 4(r28);
  lwz r6, 4(r3);
  lhz r0, 8(r6);
  cmplwi r0, 1;
  ble lbl_805409bc;
  lwz r3, 0x18(r6);
  li r0, 1;
  addi r4, r1, 0x88;
  li r5, 0x80;
  stw r0, 4(r3);
  lwz r3, 0x10(r6);
  lwz r3, 4(r3);
  bl unk_805553b0;
lbl_805409bc:
  cmpwi r31, 0;
  bne lbl_805409f8;
  lwz r0, 0x5a4(r28);
  cmpwi cr6, r0, 2;
  bne cr6, lbl_805409f8;
  lwz r0, 0x5a0(r28);
  cmpw r29, r0;
  bne lbl_805409f8;
  lwz r3, 4(r28);
  lwz r3, 4(r3);
  bne cr6, lbl_80540af8;
  lwz r4, 0x5a8(r28);
  mr r5, r30;
  bl loadOther__Q26System15MultiDvdArchiveFPQ26System15MultiDvdArchivePQ23EGG4Heap;
  b lbl_80540af8;
lbl_805409f8:
  cmpwi r31, 0;
  beq lbl_80540a48;
  lis r4, 0;
  lis r5, 0;
  slwi r0, r29, 2;
  addi r3, r1, 8;
  addi r4, r4, 0;
  addi r5, r5, 0;
  lwzx r6, r4, r0;
  addi r5, r5, 0x3b;
  li r4, 0x80;
  crclr 6;
  bl unk_805553b0;
  lwz r3, 4(r28);
  addi r4, r1, 8;
  lwz r3, 4(r3);
  bl exists__Q26System15MultiDvdArchiveFPCc;
  cmpwi r3, 0;
  bne lbl_80540a48;
  li r31, 0;
lbl_80540a48:
  cmpwi r31, 0;
  bne lbl_80540a7c;
  lis r4, 0;
  lis r5, 0;
  slwi r0, r29, 2;
  addi r3, r1, 8;
  addi r4, r4, 0;
  addi r5, r5, 0;
  lwzx r6, r4, r0;
  addi r5, r5, 0x4c;
  li r4, 0x80;
  crclr 6;
  bl unk_805553b0;
lbl_80540a7c:
  lwz r6, 4(r28);
  addi r3, r28, 0x440;
  addi r4, r1, 8;
  li r5, 0x40;
  lwz r29, 4(r6);
  stw r29, 0x434(r28);
  bl unk_805553b0;
  lis r4, 0;
  stw r30, 0x480(r28);
  lwz r3, 0x584(r28);
  addi r4, r4, 0;
  li r5, 3;
  li r6, 0;
  bl unk_805553b0;
  mr r3, r28;
  bl process__Q26System15ResourceManagerFv;
  mr r3, r29;
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  bne lbl_80540af8;
  lis r4, 0x8000;
  lis r3, 0x1062;
  lwz r0, 0xf8(r4);
  addi r4, r3, 0x4dd3;
  li r3, 0;
  srwi r0, r0, 2;
  mulhwu r4, r4, r0;
  srwi r0, r4, 6;
  rlwinm r4, r4, 0x1e, 2, 0x1b;
  rlwimi r3, r0, 4, 0x1c, 0x1f;
  bl unk_805553b0;
lbl_80540af8:
  lwz r3, 4(r28);
  lmw r27, 0x10c(r1);
  lwz r0, 0x124(r1);
  lwz r3, 4(r3);
  mtlr r0;
  addi r1, r1, 0x120;
  blr;
  // clang-format on
}

// Symbol: ResourceManager_loadCompetition
// PAL: 0x80540b14..0x80540cfc
MARK_BINARY_BLOB(ResourceManager_loadCompetition, 0x80540b14, 0x80540cfc);
asm UNKNOWN_FUNCTION(ResourceManager_loadCompetition) {
  // clang-format off
  nofralloc;
  stwu r1, -0x140(r1);
  mflr r0;
  stw r0, 0x144(r1);
  stmw r21, 0x114(r1);
  mr r23, r3;
  mr r24, r4;
  mr r25, r5;
  mr r26, r6;
  mr r27, r7;
  mr r28, r8;
  lwz r9, 4(r3);
  lwz r3, 4(r9);
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  bne lbl_80540ce0;
  lwz r3, 4(r23);
  lwz r3, 4(r3);
  lwz r12, 0(r3);
  lwz r12, 0xc(r12);
  mtctr r12;
  bctrl;
  lis r21, 0;
  li r31, 1;
  addi r21, r21, 0;
  li r30, 0;
  li r29, 0;
  li r22, 1;
lbl_80540b80:
  clrlwi r4, r29, 0x18;
  slw r0, r22, r4;
  and. r0, r28, r0;
  beq lbl_80540bf4;
  addi r6, r4, 1;
  addi r3, r1, 0x88;
  addi r5, r21, 0x5b;
  li r4, 0x80;
  crclr 6;
  bl unk_805553b0;
  lwz r4, 4(r23);
  clrlwi r3, r31, 0x10;
  lwz r6, 4(r4);
  lhz r0, 8(r6);
  cmplw r3, r0;
  bge lbl_80540be0;
  lwz r3, 0x18(r6);
  rlwinm r0, r31, 2, 0xe, 0x1d;
  addi r4, r1, 0x88;
  li r5, 0x80;
  stwx r22, r3, r0;
  lwz r3, 0x10(r6);
  lwzx r3, r3, r0;
  bl unk_805553b0;
lbl_80540be0:
  addi r30, r30, 1;
  addi r31, r31, 1;
  clrlwi r0, r30, 0x10;
  cmplwi r0, 1;
  bgt lbl_80540c00;
lbl_80540bf4:
  addi r29, r29, 1;
  cmplwi r29, 0x10;
  blt lbl_80540b80;
lbl_80540c00:
  lwz r4, 4(r23);
  clrlwi r3, r31, 0x10;
  lwz r4, 4(r4);
  lhz r0, 8(r4);
  cmplw r3, r0;
  bge lbl_80540c38;
  lwz r3, 0x18(r4);
  rlwinm r5, r31, 2, 0xe, 0x1d;
  li r0, 2;
  stwx r0, r3, r5;
  lwz r3, 0x14(r4);
  stwx r25, r3, r5;
  lwz r3, 0xc(r4);
  stwx r26, r3, r5;
lbl_80540c38:
  lis r4, 0;
  lis r5, 0;
  slwi r0, r24, 2;
  addi r3, r1, 8;
  addi r4, r4, 0;
  addi r5, r5, 0;
  lwzx r6, r4, r0;
  addi r5, r5, 0x88;
  li r4, 0x80;
  crclr 6;
  bl unk_805553b0;
  lwz r6, 4(r23);
  addi r3, r23, 0x494;
  addi r4, r1, 8;
  li r5, 0x40;
  lwz r21, 4(r6);
  stw r21, 0x488(r23);
  bl unk_805553b0;
  lis r4, 0;
  stw r27, 0x4d4(r23);
  lwz r3, 0x584(r23);
  addi r4, r4, 0;
  li r5, 4;
  li r6, 0;
  bl unk_805553b0;
  mr r3, r23;
  bl process__Q26System15ResourceManagerFv;
  mr r3, r21;
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  bne lbl_80540ce0;
  lis r4, 0x8000;
  lis r3, 0x1062;
  lwz r0, 0xf8(r4);
  addi r4, r3, 0x4dd3;
  li r3, 0;
  srwi r0, r0, 2;
  mulhwu r4, r4, r0;
  srwi r0, r4, 6;
  rlwinm r4, r4, 0x1e, 2, 0x1b;
  rlwimi r3, r0, 4, 0x1c, 0x1f;
  bl unk_805553b0;
lbl_80540ce0:
  lwz r3, 4(r23);
  lmw r21, 0x114(r1);
  lwz r0, 0x144(r1);
  lwz r3, 4(r3);
  mtlr r0;
  addi r1, r1, 0x140;
  blr;
  // clang-format on
}

// Symbol: unk_80540cfc
// PAL: 0x80540cfc..0x80540e3c
MARK_BINARY_BLOB(unk_80540cfc, 0x80540cfc, 0x80540e3c);
asm UNKNOWN_FUNCTION(unk_80540cfc) {
  // clang-format off
  nofralloc;
  stwu r1, -0xa0(r1);
  mflr r0;
  lis r11, 0;
  cmpwi r7, 0x30;
  stw r0, 0xa4(r1);
  addi r11, r11, 0;
  stw r31, 0x9c(r1);
  mr r31, r4;
  stw r30, 0x98(r1);
  lwz r30, 0xa8(r1);
  stw r29, 0x94(r1);
  mr r29, r10;
  stw r28, 0x90(r1);
  mr r28, r3;
  blt lbl_80540d40;
  li r10, 0;
  b lbl_80540d4c;
lbl_80540d40:
  slwi r0, r7, 2;
  addi r3, r11, 0x130;
  lwzx r10, r3, r0;
lbl_80540d4c:
  lis r4, 0;
  cmpwi r6, 0x24;
  addi r4, r4, 0;
  addi r3, r1, 8;
  addi r5, r4, 0x97;
  li r4, 0x80;
  blt lbl_80540d70;
  li r6, 0;
  b lbl_80540d7c;
lbl_80540d70:
  slwi r0, r6, 2;
  addi r6, r11, 0x1f0;
  lwzx r6, r6, r0;
lbl_80540d7c:
  slwi r0, r9, 2;
  addi r9, r11, 0x28c;
  slwi r8, r8, 2;
  addi r7, r11, 0x280;
  lwzx r7, r7, r8;
  mr r8, r10;
  lwzx r9, r9, r0;
  crclr 6;
  bl unk_805553b0;
  stw r31, 0x4dc(r28);
  addi r3, r28, 0x4e8;
  addi r4, r1, 8;
  li r5, 0x40;
  bl unk_805553b0;
  lis r4, 0;
  stw r29, 0x528(r28);
  lwz r3, 0x584(r28);
  addi r4, r4, 0;
  stw r30, 0x52c(r28);
  li r5, 5;
  li r6, 0;
  bl unk_805553b0;
  mr r3, r28;
  bl process__Q26System15ResourceManagerFv;
  mr r3, r31;
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  bne lbl_80540e18;
  lis r4, 0x8000;
  lis r3, 0x1062;
  lwz r0, 0xf8(r4);
  addi r4, r3, 0x4dd3;
  li r3, 0;
  srwi r0, r0, 2;
  mulhwu r4, r4, r0;
  srwi r0, r4, 6;
  rlwinm r4, r4, 0x1e, 2, 0x1b;
  rlwimi r3, r0, 4, 0x1c, 0x1f;
  bl unk_805553b0;
lbl_80540e18:
  mr r3, r31;
  lwz r31, 0x9c(r1);
  lwz r30, 0x98(r1);
  lwz r29, 0x94(r1);
  lwz r28, 0x90(r1);
  lwz r0, 0xa4(r1);
  mtlr r0;
  addi r1, r1, 0xa0;
  blr;
  // clang-format on
}

// Symbol: unk_80540e3c
// PAL: 0x80540e3c..0x80540f90
MARK_BINARY_BLOB(unk_80540e3c, 0x80540e3c, 0x80540f90);
asm UNKNOWN_FUNCTION(unk_80540e3c) {
  // clang-format off
  nofralloc;
  stwu r1, -0xb0(r1);
  mflr r0;
  stw r0, 0xb4(r1);
  mulli r0, r4, 0x1c;
  stmw r23, 0x8c(r1);
  mr r30, r3;
  add r3, r3, r0;
  lis r29, 0;
  addi r31, r3, 8;
  mr r23, r5;
  mr r24, r6;
  mr r25, r7;
  mr r26, r8;
  mr r27, r9;
  mr r28, r10;
  mr r3, r31;
  addi r29, r29, 0;
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  bne lbl_80540f78;
  cmpwi r24, 0x30;
  blt lbl_80540e9c;
  li r8, 0;
  b lbl_80540ea8;
lbl_80540e9c:
  slwi r0, r24, 2;
  addi r3, r29, 0x130;
  lwzx r8, r3, r0;
lbl_80540ea8:
  lis r4, 0;
  cmpwi r23, 0x24;
  addi r4, r4, 0;
  addi r3, r1, 8;
  addi r5, r4, 0xab;
  li r4, 0x80;
  blt lbl_80540ecc;
  li r6, 0;
  b lbl_80540ed8;
lbl_80540ecc:
  slwi r0, r23, 2;
  addi r6, r29, 0x1f0;
  lwzx r6, r6, r0;
lbl_80540ed8:
  slwi r10, r25, 2;
  addi r7, r29, 0x280;
  slwi r0, r26, 2;
  addi r9, r29, 0x28c;
  lwzx r7, r7, r10;
  lwzx r9, r9, r0;
  crclr 6;
  bl unk_805553b0;
  stw r31, 0x4dc(r30);
  addi r3, r30, 0x4e8;
  addi r4, r1, 8;
  li r5, 0x40;
  bl unk_805553b0;
  lis r4, 0;
  stw r27, 0x528(r30);
  lwz r3, 0x584(r30);
  addi r4, r4, 0;
  stw r28, 0x52c(r30);
  li r5, 5;
  li r6, 0;
  bl unk_805553b0;
  mr r3, r30;
  bl process__Q26System15ResourceManagerFv;
  mr r3, r31;
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  bne lbl_80540f70;
  lis r4, 0x8000;
  lis r3, 0x1062;
  lwz r0, 0xf8(r4);
  addi r4, r3, 0x4dd3;
  li r3, 0;
  srwi r0, r0, 2;
  mulhwu r4, r4, r0;
  srwi r0, r4, 6;
  rlwinm r4, r4, 0x1e, 2, 0x1b;
  rlwimi r3, r0, 4, 0x1c, 0x1f;
  bl unk_805553b0;
lbl_80540f70:
  mr r3, r31;
  b lbl_80540f7c;
lbl_80540f78:
  mr r3, r31;
lbl_80540f7c:
  lmw r23, 0x8c(r1);
  lwz r0, 0xb4(r1);
  mtlr r0;
  addi r1, r1, 0xb0;
  blr;
  // clang-format on
}

// Symbol: unk_80540f90
// PAL: 0x80540f90..0x805410e4
MARK_BINARY_BLOB(unk_80540f90, 0x80540f90, 0x805410e4);
asm UNKNOWN_FUNCTION(unk_80540f90) {
  // clang-format off
  nofralloc;
  stwu r1, -0xb0(r1);
  mflr r0;
  stw r0, 0xb4(r1);
  mulli r0, r4, 0x1c;
  stmw r23, 0x8c(r1);
  mr r30, r3;
  add r3, r3, r0;
  lis r29, 0;
  addi r31, r3, 0x158;
  mr r23, r5;
  mr r24, r6;
  mr r25, r7;
  mr r26, r8;
  mr r27, r9;
  mr r28, r10;
  mr r3, r31;
  addi r29, r29, 0;
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  bne lbl_805410cc;
  cmpwi r24, 0x30;
  blt lbl_80540ff0;
  li r8, 0;
  b lbl_80540ffc;
lbl_80540ff0:
  slwi r0, r24, 2;
  addi r3, r29, 0x130;
  lwzx r8, r3, r0;
lbl_80540ffc:
  lis r4, 0;
  cmpwi r23, 0x24;
  addi r4, r4, 0;
  addi r3, r1, 8;
  addi r5, r4, 0xbf;
  li r4, 0x80;
  blt lbl_80541020;
  li r6, 0;
  b lbl_8054102c;
lbl_80541020:
  slwi r0, r23, 2;
  addi r6, r29, 0x1f0;
  lwzx r6, r6, r0;
lbl_8054102c:
  slwi r10, r25, 2;
  addi r7, r29, 0x280;
  slwi r0, r26, 2;
  addi r9, r29, 0x28c;
  lwzx r7, r7, r10;
  lwzx r9, r9, r0;
  crclr 6;
  bl unk_805553b0;
  stw r31, 0x4dc(r30);
  addi r3, r30, 0x4e8;
  addi r4, r1, 8;
  li r5, 0x40;
  bl unk_805553b0;
  lis r4, 0;
  stw r27, 0x528(r30);
  lwz r3, 0x584(r30);
  addi r4, r4, 0;
  stw r28, 0x52c(r30);
  li r5, 5;
  li r6, 0;
  bl unk_805553b0;
  mr r3, r30;
  bl process__Q26System15ResourceManagerFv;
  mr r3, r31;
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  bne lbl_805410c4;
  lis r4, 0x8000;
  lis r3, 0x1062;
  lwz r0, 0xf8(r4);
  addi r4, r3, 0x4dd3;
  li r3, 0;
  srwi r0, r0, 2;
  mulhwu r4, r4, r0;
  srwi r0, r4, 6;
  rlwinm r4, r4, 0x1e, 2, 0x1b;
  rlwimi r3, r0, 4, 0x1c, 0x1f;
  bl unk_805553b0;
lbl_805410c4:
  mr r3, r31;
  b lbl_805410d0;
lbl_805410cc:
  mr r3, r31;
lbl_805410d0:
  lmw r23, 0x8c(r1);
  lwz r0, 0xb4(r1);
  mtlr r0;
  addi r1, r1, 0xb0;
  blr;
  // clang-format on
}

// Symbol: unk_805410e4
// PAL: 0x805410e4..0x805411d4
MARK_BINARY_BLOB(unk_805410e4, 0x805410e4, 0x805411d4);
asm UNKNOWN_FUNCTION(unk_805410e4) {
  // clang-format off
  nofralloc;
  stwu r1, -0xa0(r1);
  mflr r0;
  stw r0, 0xa4(r1);
  mulli r0, r4, 0x1c;
  stmw r27, 0x8c(r1);
  mr r27, r5;
  add r3, r3, r0;
  mr r28, r6;
  addi r31, r3, 8;
  mr r29, r7;
  mr r30, r8;
  mr r3, r31;
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  bne lbl_805411bc;
  cmpwi r28, 2;
  bne lbl_80541168;
  lis r4, 0;
  cmpwi r27, 0x30;
  addi r4, r4, 0;
  addi r3, r1, 8;
  addi r5, r4, 0xd3;
  li r4, 0x80;
  blt lbl_8054114c;
  li r6, 0;
  b lbl_8054115c;
lbl_8054114c:
  lis r6, 0;
  slwi r0, r27, 2;
  addi r6, r6, 0;
  lwzx r6, r6, r0;
lbl_8054115c:
  crclr 6;
  bl unk_805553b0;
  b lbl_805411a4;
lbl_80541168:
  lis r4, 0;
  cmpwi r27, 0x30;
  addi r4, r4, 0;
  addi r3, r1, 8;
  addi r5, r4, 0xef;
  li r4, 0x80;
  blt lbl_8054118c;
  li r6, 0;
  b lbl_8054119c;
lbl_8054118c:
  lis r6, 0;
  slwi r0, r27, 2;
  addi r6, r6, 0;
  lwzx r6, r6, r0;
lbl_8054119c:
  crclr 6;
  bl unk_805553b0;
lbl_805411a4:
  mr r3, r31;
  mr r5, r29;
  mr r6, r30;
  addi r4, r1, 8;
  li r7, 0;
  bl load__Q26System15MultiDvdArchiveFPCcPQ23EGG4HeapPQ23EGG4Heapi;
lbl_805411bc:
  mr r3, r31;
  lmw r27, 0x8c(r1);
  lwz r0, 0xa4(r1);
  mtlr r0;
  addi r1, r1, 0xa0;
  blr;
  // clang-format on
}

// Symbol: unk_805411d4
// PAL: 0x805411d4..0x805411e4
MARK_BINARY_BLOB(unk_805411d4, 0x805411d4, 0x805411e4);
asm UNKNOWN_FUNCTION(unk_805411d4) {
  // clang-format off
  nofralloc;
  lwz r3, 4(r3);
  slwi r0, r4, 2;
  lwzx r3, r3, r0;
  b unmount__Q26System15MultiDvdArchiveFv;
  // clang-format on
}

// Symbol: unk_805411e4
// PAL: 0x805411e4..0x805411ec
MARK_BINARY_BLOB(unk_805411e4, 0x805411e4, 0x805411ec);
asm UNKNOWN_FUNCTION(unk_805411e4) {
  // clang-format off
  nofralloc;
  mr r3, r4;
  b unmount__Q26System15MultiDvdArchiveFv;
  // clang-format on
}

// Symbol: unk_805411ec
// PAL: 0x805411ec..0x805411fc
MARK_BINARY_BLOB(unk_805411ec, 0x805411ec, 0x805411fc);
asm UNKNOWN_FUNCTION(unk_805411ec) {
  // clang-format off
  nofralloc;
  mulli r0, r4, 0x24;
  add r3, r3, r0;
  addi r3, r3, 0x2a8;
  b unmount__Q26System10DvdArchiveFv;
  // clang-format on
}

// Symbol: ResourceManager_getFile
// PAL: 0x805411fc..0x80541278
MARK_BINARY_BLOB(ResourceManager_getFile, 0x805411fc, 0x80541278);
asm UNKNOWN_FUNCTION(ResourceManager_getFile) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  slwi r31, r4, 2;
  stw r30, 0x18(r1);
  mr r30, r6;
  stw r29, 0x14(r1);
  mr r29, r5;
  stw r28, 0x10(r1);
  mr r28, r3;
  lwz r7, 4(r3);
  lwzx r3, r7, r31;
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  beq lbl_80541254;
  lwz r3, 4(r28);
  mr r4, r29;
  mr r5, r30;
  lwzx r3, r3, r31;
  bl getFile__Q26System15MultiDvdArchiveFPCcPUl;
  b lbl_80541258;
lbl_80541254:
  li r3, 0;
lbl_80541258:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_80541278
// PAL: 0x80541278..0x80541320
MARK_BINARY_BLOB(unk_80541278, 0x80541278, 0x80541320);
asm UNKNOWN_FUNCTION(unk_80541278) {
  // clang-format off
  nofralloc;
  stwu r1, -0xa0(r1);
  mflr r0;
  stw r0, 0xa4(r1);
  stw r31, 0x9c(r1);
  mr r31, r5;
  stw r30, 0x98(r1);
  mr r30, r4;
  stw r29, 0x94(r1);
  mr r29, r3;
  lwz r6, 4(r3);
  lwz r3, 0x18(r6);
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  bne lbl_805412b8;
  li r3, 0;
  b lbl_80541304;
lbl_805412b8:
  lis r3, 0;
  cmpwi r30, 0x30;
  addi r3, r3, 0;
  li r4, 0x80;
  addi r3, r3, 0x10e;
  blt lbl_805412d8;
  li r5, 0;
  b lbl_805412e8;
lbl_805412d8:
  lis r5, 0;
  slwi r0, r30, 2;
  addi r5, r5, 0;
  lwzx r5, r5, r0;
lbl_805412e8:
  crclr 6;
  bl unk_805553b0;
  lwz r3, 4(r29);
  mr r5, r31;
  addi r4, r1, 8;
  lwz r3, 0x18(r3);
  bl getFile__Q26System15MultiDvdArchiveFPCcPUl;
lbl_80541304:
  lwz r0, 0xa4(r1);
  lwz r31, 0x9c(r1);
  lwz r30, 0x98(r1);
  lwz r29, 0x94(r1);
  mtlr r0;
  addi r1, r1, 0xa0;
  blr;
  // clang-format on
}

// Symbol: unk_80541320
// PAL: 0x80541320..0x805413c8
MARK_BINARY_BLOB(unk_80541320, 0x80541320, 0x805413c8);
asm UNKNOWN_FUNCTION(unk_80541320) {
  // clang-format off
  nofralloc;
  stwu r1, -0xa0(r1);
  mflr r0;
  stw r0, 0xa4(r1);
  mulli r0, r4, 0x1c;
  stw r31, 0x9c(r1);
  add r3, r3, r0;
  stw r30, 0x98(r1);
  addi r31, r3, 8;
  mr r30, r6;
  stw r29, 0x94(r1);
  mr r29, r5;
  mr r3, r31;
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  bne lbl_80541364;
  li r3, 0;
  b lbl_805413ac;
lbl_80541364:
  lis r3, 0;
  cmpwi r29, 0x24;
  addi r3, r3, 0;
  li r4, 0x80;
  addi r3, r3, 0x117;
  blt lbl_80541384;
  li r5, 0;
  b lbl_80541394;
lbl_80541384:
  lis r5, 0;
  slwi r0, r29, 2;
  addi r5, r5, 0;
  lwzx r5, r5, r0;
lbl_80541394:
  crclr 6;
  bl unk_805553b0;
  mr r3, r31;
  mr r5, r30;
  addi r4, r1, 8;
  bl getFile__Q26System15MultiDvdArchiveFPCcPUl;
lbl_805413ac:
  lwz r0, 0xa4(r1);
  lwz r31, 0x9c(r1);
  lwz r30, 0x98(r1);
  lwz r29, 0x94(r1);
  mtlr r0;
  addi r1, r1, 0xa0;
  blr;
  // clang-format on
}

// Symbol: unk_805413c8
// PAL: 0x805413c8..0x80541438
MARK_BINARY_BLOB(unk_805413c8, 0x805413c8, 0x80541438);
asm UNKNOWN_FUNCTION(unk_805413c8) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  mulli r0, r4, 0x1c;
  stw r31, 0x1c(r1);
  add r3, r3, r0;
  stw r30, 0x18(r1);
  addi r31, r3, 8;
  mr r30, r6;
  stw r29, 0x14(r1);
  mr r29, r5;
  mr r3, r31;
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  beq lbl_80541418;
  mr r3, r31;
  mr r4, r29;
  mr r5, r30;
  bl getFile__Q26System15MultiDvdArchiveFPCcPUl;
  b lbl_8054141c;
lbl_80541418:
  li r3, 0;
lbl_8054141c:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_80541438
// PAL: 0x80541438..0x805414a8
MARK_BINARY_BLOB(unk_80541438, 0x80541438, 0x805414a8);
asm UNKNOWN_FUNCTION(unk_80541438) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  mulli r0, r4, 0x1c;
  stw r31, 0x1c(r1);
  add r3, r3, r0;
  stw r30, 0x18(r1);
  addi r31, r3, 0x158;
  mr r30, r6;
  stw r29, 0x14(r1);
  mr r29, r5;
  mr r3, r31;
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  beq lbl_80541488;
  mr r3, r31;
  mr r4, r29;
  mr r5, r30;
  bl getFile__Q26System15MultiDvdArchiveFPCcPUl;
  b lbl_8054148c;
lbl_80541488:
  li r3, 0;
lbl_8054148c:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_805414a8
// PAL: 0x805414a8..0x8054155c
MARK_BINARY_BLOB(unk_805414a8, 0x805414a8, 0x8054155c);
asm UNKNOWN_FUNCTION(unk_805414a8) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  mulli r0, r4, 0xf0;
  lis r4, 0;
  stw r31, 0x2c(r1);
  mr r31, r5;
  stw r30, 0x28(r1);
  mr r30, r3;
  lwz r6, 0(r4);
  lis r4, 0;
  addi r4, r4, 0;
  add r3, r6, r0;
  lwz r0, 0x30(r3);
  addi r5, r4, 0x120;
  addi r3, r1, 8;
  li r4, 0x20;
  cmpwi r0, 0x24;
  blt lbl_805414fc;
  li r6, 0;
  b lbl_8054150c;
lbl_805414fc:
  lis r6, 0;
  slwi r0, r0, 2;
  addi r6, r6, 0;
  lwzx r6, r6, r0;
lbl_8054150c:
  crclr 6;
  bl unk_805553b0;
  lwz r3, 4(r30);
  lwz r3, 0(r3);
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  beq lbl_80541540;
  lwz r3, 4(r30);
  mr r5, r31;
  addi r4, r1, 8;
  lwz r3, 0(r3);
  bl getFile__Q26System15MultiDvdArchiveFPCcPUl;
  b lbl_80541544;
lbl_80541540:
  li r3, 0;
lbl_80541544:
  lwz r0, 0x34(r1);
  lwz r31, 0x2c(r1);
  lwz r30, 0x28(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: unk_8054155c
// PAL: 0x8054155c..0x805415b0
MARK_BINARY_BLOB(unk_8054155c, 0x8054155c, 0x805415b0);
asm UNKNOWN_FUNCTION(unk_8054155c) {
  // clang-format off
  nofralloc;
  mulli r10, r4, 0x24;
  li r9, 1;
  add r4, r3, r10;
  lwz r0, 0x2c8(r4);
  cmpwi r0, 4;
  beq lbl_80541584;
  lwz r0, 0x2c8(r4);
  cmpwi r0, 5;
  beq lbl_80541584;
  li r9, 0;
lbl_80541584:
  cmpwi r9, 0;
  bne lbl_80541594;
  li r3, 0;
  blr;
lbl_80541594:
  add r3, r3, r10;
  mr r4, r5;
  mr r5, r6;
  mr r6, r7;
  addi r3, r3, 0x2a8;
  extsb r7, r8;
  b getFileCopy__Q26System10DvdArchiveFPcPQ23EGG4HeapPUlSc;
  // clang-format on
}

// Symbol: unk_805415b0
// PAL: 0x805415b0..0x805415b4
MARK_BINARY_BLOB(unk_805415b0, 0x805415b0, 0x805415b4);
asm UNKNOWN_FUNCTION(unk_805415b0) {
  // clang-format off
  nofralloc;
  blr;
  // clang-format on
}

// Symbol: unk_805415b4
// PAL: 0x805415b4..0x805415c4
MARK_BINARY_BLOB(unk_805415b4, 0x805415b4, 0x805415c4);
asm UNKNOWN_FUNCTION(unk_805415b4) {
  // clang-format off
  nofralloc;
  lwz r3, 4(r3);
  slwi r0, r4, 2;
  lwzx r3, r3, r0;
  b isLoaded__Q26System15MultiDvdArchiveFv;
  // clang-format on
}

// Symbol: unk_805415c4
// PAL: 0x805415c4..0x805415d4
MARK_BINARY_BLOB(unk_805415c4, 0x805415c4, 0x805415d4);
asm UNKNOWN_FUNCTION(unk_805415c4) {
  // clang-format off
  nofralloc;
  mulli r0, r4, 0x1c;
  add r3, r3, r0;
  addi r3, r3, 8;
  b isLoaded__Q26System15MultiDvdArchiveFv;
  // clang-format on
}

// Symbol: unk_805415d4
// PAL: 0x805415d4..0x805415e4
MARK_BINARY_BLOB(unk_805415d4, 0x805415d4, 0x805415e4);
asm UNKNOWN_FUNCTION(unk_805415d4) {
  // clang-format off
  nofralloc;
  mulli r0, r4, 0x1c;
  add r3, r3, r0;
  addi r3, r3, 0x158;
  b isLoaded__Q26System15MultiDvdArchiveFv;
  // clang-format on
}

// Symbol: unk_805415e4
// PAL: 0x805415e4..0x80541614
MARK_BINARY_BLOB(unk_805415e4, 0x805415e4, 0x80541614);
asm UNKNOWN_FUNCTION(unk_805415e4) {
  // clang-format off
  nofralloc;
  mulli r0, r4, 0x24;
  li r4, 1;
  add r3, r3, r0;
  lwz r0, 0x2c8(r3);
  cmpwi r0, 4;
  beq lbl_8054160c;
  lwz r0, 0x2c8(r3);
  cmpwi r0, 5;
  beq lbl_8054160c;
  li r4, 0;
lbl_8054160c:
  mr r3, r4;
  blr;
  // clang-format on
}

// Symbol: unk_80541614
// PAL: 0x80541614..0x8054169c
MARK_BINARY_BLOB(unk_80541614, 0x80541614, 0x8054169c);
asm UNKNOWN_FUNCTION(unk_80541614) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  slwi r31, r4, 2;
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r3;
  lwz r6, 4(r3);
  lwzx r3, r6, r31;
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  bne lbl_80541654;
  li r3, 0;
  b lbl_80541680;
lbl_80541654:
  lwz r3, 4(r29);
  lwzx r3, r3, r31;
  lhz r0, 8(r3);
  cmplw r30, r0;
  bge lbl_8054167c;
  mulli r0, r30, 0x24;
  lwz r3, 4(r3);
  add r3, r3, r0;
  lwz r3, 8(r3);
  b lbl_80541680;
lbl_8054167c:
  li r3, 0;
lbl_80541680:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_8054169c
// PAL: 0x8054169c..0x80541738
MARK_BINARY_BLOB(unk_8054169c, 0x8054169c, 0x80541738);
asm UNKNOWN_FUNCTION(unk_8054169c) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stmw r27, 0xc(r1);
  slwi r31, r4, 2;
  mr r27, r3;
  mr r28, r5;
  mr r29, r6;
  mr r30, r7;
  lwz r8, 4(r3);
  lwzx r3, r8, r31;
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  bne lbl_805416dc;
  li r3, 0;
  b lbl_80541724;
lbl_805416dc:
  lwz r3, 4(r27);
  lwzx r4, r3, r31;
  lhz r0, 8(r4);
  cmplw r28, r0;
  bge lbl_80541720;
  mr r3, r29;
  bge lbl_8054170c;
  mulli r0, r28, 0x24;
  lwz r4, 4(r4);
  add r4, r4, r0;
  lwz r4, 8(r4);
  b lbl_80541710;
lbl_8054170c:
  li r4, 0;
lbl_80541710:
  mr r5, r30;
  bl unk_805553b0;
  li r3, 1;
  b lbl_80541724;
lbl_80541720:
  li r3, 0;
lbl_80541724:
  lmw r27, 0xc(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_80541738
// PAL: 0x80541738..0x80541794
MARK_BINARY_BLOB(unk_80541738, 0x80541738, 0x80541794);
asm UNKNOWN_FUNCTION(unk_80541738) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  slwi r31, r4, 2;
  stw r30, 8(r1);
  mr r30, r3;
  lwz r5, 4(r3);
  lwzx r3, r5, r31;
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  beq lbl_80541778;
  lwz r3, 4(r30);
  lwzx r3, r3, r31;
  lhz r3, 8(r3);
  b lbl_8054177c;
lbl_80541778:
  li r3, 0;
lbl_8054177c:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: ResourceManager_getMenuArchiveCount
// PAL: 0x80541794..0x805417a4
MARK_BINARY_BLOB(ResourceManager_getMenuArchiveCount, 0x80541794, 0x805417a4);
asm UNKNOWN_FUNCTION(ResourceManager_getMenuArchiveCount) {
  // clang-format off
  nofralloc;
  lwz r3, 4(r3);
  lwz r3, 8(r3);
  lhz r3, 8(r3);
  blr;
  // clang-format on
}

// Symbol: unk_805417a4
// PAL: 0x805417a4..0x80541878
MARK_BINARY_BLOB(unk_805417a4, 0x805417a4, 0x80541878);
asm UNKNOWN_FUNCTION(unk_805417a4) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r5;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  lwz r6, 4(r3);
  lwz r3, 8(r6);
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  bne lbl_805417e4;
  li r0, 0;
  b lbl_80541808;
lbl_805417e4:
  lwz r3, 4(r29);
  lwz r3, 8(r3);
  lhz r0, 8(r3);
  cmpwi r0, 0;
  beq lbl_80541804;
  lwz r3, 4(r3);
  lwz r0, 8(r3);
  b lbl_80541808;
lbl_80541804:
  li r0, 0;
lbl_80541808:
  cmpwi r0, 0;
  beq lbl_8054185c;
  lwz r3, 4(r29);
  lwz r3, 8(r3);
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  bne lbl_8054182c;
  li r4, 0;
  b lbl_80541850;
lbl_8054182c:
  lwz r3, 4(r29);
  lwz r3, 8(r3);
  lhz r0, 8(r3);
  cmpwi r0, 0;
  beq lbl_8054184c;
  lwz r3, 4(r3);
  lwz r4, 8(r3);
  b lbl_80541850;
lbl_8054184c:
  li r4, 0;
lbl_80541850:
  mr r3, r30;
  mr r5, r31;
  bl unk_805553b0;
lbl_8054185c:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: ResourceManager_attachLayoutDir
// PAL: 0x80541878..0x80541998
MARK_BINARY_BLOB(ResourceManager_attachLayoutDir, 0x80541878, 0x80541998);
asm UNKNOWN_FUNCTION(ResourceManager_attachLayoutDir) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  cmpwi r7, 0;
  stw r0, 0x24(r1);
  stmw r26, 8(r1);
  mr r27, r3;
  mr r28, r4;
  mr r29, r5;
  mr r30, r6;
  bne lbl_805418a4;
  bl getGameScene;
lbl_805418a4:
  li r31, 0;
  b lbl_80541950;
lbl_805418ac:
  lhz r0, 8(r30);
  clrlwi r3, r31, 0x10;
  cmplw r3, r0;
  bge lbl_805418cc;
  mulli r0, r3, 0xa4;
  lwz r3, 4(r30);
  add r26, r3, r0;
  b lbl_805418d0;
lbl_805418cc:
  li r26, 0;
lbl_805418d0:
  lwz r3, 4(r27);
  lwz r3, 8(r3);
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  bne lbl_805418ec;
  li r0, 0;
  b lbl_80541938;
lbl_805418ec:
  lwz r3, 4(r27);
  clrlwi r0, r31, 0x10;
  lwz r4, 8(r3);
  lhz r3, 8(r4);
  cmplw r0, r3;
  bge lbl_80541934;
  mr r3, r26;
  bge lbl_80541920;
  mulli r0, r0, 0x24;
  lwz r4, 4(r4);
  add r4, r4, r0;
  lwz r4, 8(r4);
  b lbl_80541924;
lbl_80541920:
  li r4, 0;
lbl_80541924:
  mr r5, r29;
  bl unk_805553b0;
  li r0, 1;
  b lbl_80541938;
lbl_80541934:
  li r0, 0;
lbl_80541938:
  cmpwi r0, 0;
  beq lbl_8054194c;
  mr r3, r28;
  mr r4, r26;
  bl unk_805553b0;
lbl_8054194c:
  addi r31, r31, 1;
lbl_80541950:
  lwz r3, 4(r27);
  lwz r3, 8(r3);
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  beq lbl_80541974;
  lwz r3, 4(r27);
  lwz r3, 8(r3);
  lhz r3, 8(r3);
  b lbl_80541978;
lbl_80541974:
  li r3, 0;
lbl_80541978:
  clrlwi r0, r31, 0x10;
  cmplw r0, r3;
  blt lbl_805418ac;
  lmw r26, 8(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: ResourceManager_preloadCourseTask
// PAL: 0x80541998..0x805419ac
MARK_BINARY_BLOB(ResourceManager_preloadCourseTask, 0x80541998, 0x805419ac);
asm UNKNOWN_FUNCTION(ResourceManager_preloadCourseTask) {
  // clang-format off
  nofralloc;
  lis r5, 0;
  mr r4, r3;
  lwz r3, 0(r5);
  addi r3, r3, 0x588;
  b unk_80541b58;
  // clang-format on
}

// Symbol: ResourceManager_preloadCourseAsync
// PAL: 0x805419ac..0x805419c8
MARK_BINARY_BLOB(ResourceManager_preloadCourseAsync, 0x805419ac, 0x805419c8);
asm UNKNOWN_FUNCTION(ResourceManager_preloadCourseAsync) {
  // clang-format off
  nofralloc;
  lis r6, 0x1000;
  lwz r3, 0x584(r3);
  lis r7, 0;
  mr r5, r4;
  addi r4, r7, 0;
  addi r6, r6, 2;
  b unk_805553b0;
  // clang-format on
}

// Symbol: unk_805419c8
// PAL: 0x805419c8..0x805419ec
MARK_BINARY_BLOB(unk_805419c8, 0x805419c8, 0x805419ec);
asm UNKNOWN_FUNCTION(unk_805419c8) {
  // clang-format off
  nofralloc;
  cmpwi r3, 0x30;
  blt lbl_805419d8;
  li r3, 0;
  blr;
lbl_805419d8:
  lis r4, 0;
  slwi r0, r3, 2;
  addi r4, r4, 0;
  lwzx r3, r4, r0;
  blr;
  // clang-format on
}

// Symbol: unk_805419ec
// PAL: 0x805419ec..0x80541a10
MARK_BINARY_BLOB(unk_805419ec, 0x805419ec, 0x80541a10);
asm UNKNOWN_FUNCTION(unk_805419ec) {
  // clang-format off
  nofralloc;
  cmpwi r3, 0x24;
  blt lbl_805419fc;
  li r3, 0;
  blr;
lbl_805419fc:
  lis r4, 0;
  slwi r0, r3, 2;
  addi r4, r4, 0;
  lwzx r3, r4, r0;
  blr;
  // clang-format on
}

namespace System {

CourseCache::CourseCache() {
  mBuffer = nullptr;
  mHeap = nullptr;
  mArchive = new CourseDvdArchive();
}

void CourseCache::init() {
  void* block = new (-32) u8[0x319000];
  mBuffer = block;
  mHeap = EGG::ExpHeap::create(block, 0x319000, 1);
}

CourseCache::~CourseCache() {
  mArchive->clear();
  if (mHeap) {
    mHeap->destroy();
    delete[](mBuffer);
  }
}

} // namespace System

#ifdef NON_MATCHING // requires rodata to work
namespace System {

void CourseCache::load(s32 courseId) {
  if (!mHeap)
    return;
  char buffer[128];

  mCourseId = courseId;
  if (mState == 2) {
    mArchive->clear();
  }
  mState = 1;

  snprintf(buffer, sizeof(buffer), "Race/Course/%s", TRACK_NAMES[mCourseId]);
  mArchive->rip(buffer, mHeap);

  // something is wrong - this matches but requires rippedArchiveCount() to
  // return s32, which almost certainly breaks MultiDvdArchive
  if ((u16)mArchive->rippedArchiveCount()) {
    mState = 2;
  } else {
    mArchive->clear();
    mState = 0;
  }
}

} // namespace System
#else
// Symbol: unk_80541b58
// PAL: 0x80541b58..0x80541c18
MARK_BINARY_BLOB(unk_80541b58, 0x80541b58, 0x80541c18);
asm UNKNOWN_FUNCTION(unk_80541b58) {
  // clang-format off
  nofralloc;
  stwu r1, -0x90(r1);
  mflr r0;
  stw r0, 0x94(r1);
  stw r31, 0x8c(r1);
  mr r31, r3;
  lwz r0, 0x14(r3);
  cmpwi r0, 0;
  beq lbl_80541c04;
  lwz r0, 0x1c(r3);
  stw r4, 0x18(r3);
  cmpwi r0, 2;
  bne lbl_80541b90;
  lwz r3, 0x20(r3);
  bl clear__Q26System15MultiDvdArchiveFv;
lbl_80541b90:
  lwz r0, 0x18(r31);
  li r3, 1;
  lis r4, 0;
  stw r3, 0x1c(r31);
  lis r5, 0;
  slwi r0, r0, 2;
  addi r4, r4, 0;
  addi r3, r1, 8;
  addi r5, r5, 0;
  lwzx r6, r4, r0;
  addi r5, r5, 0x12c;
  li r4, 0x80;
  crclr 6;
  bl unk_805553b0;
  lwz r3, 0x20(r31);
  addi r4, r1, 8;
  lwz r5, 0x14(r31);
  bl rip__Q26System15MultiDvdArchiveFPCcPQ23EGG4Heap;
  lwz r3, 0x20(r31);
  bl rippedArchiveCount__Q26System15MultiDvdArchiveFv;
  clrlwi. r0, r3, 0x10;
  beq lbl_80541bf4;
  li r0, 2;
  stw r0, 0x1c(r31);
  b lbl_80541c04;
lbl_80541bf4:
  lwz r3, 0x20(r31);
  bl clear__Q26System15MultiDvdArchiveFv;
  li r0, 0;
  stw r0, 0x1c(r31);
lbl_80541c04:
  lwz r0, 0x94(r1);
  lwz r31, 0x8c(r1);
  mtlr r0;
  addi r1, r1, 0x90;
  blr;
  // clang-format on
}
#endif

namespace System {

void CourseCache::loadOther(MultiDvdArchive* other, EGG::Heap* heap) {
  if (mState != 2)
    return;

  other->loadOther(mArchive, heap);
}

} // namespace System

// Symbol: unk_80541c38
// PAL: 0x80541c38..0x80541c48
MARK_BINARY_BLOB(unk_80541c38, 0x80541c38, 0x80541c48);
asm UNKNOWN_FUNCTION(unk_80541c38) {
  // clang-format off
  nofralloc;
  lis r3, 0;
  addi r3, r3, 0;
  addi r3, r3, 0x13b;
  blr;
  // clang-format on
}

// Symbol: unk_80541c48
// PAL: 0x80541c48..0x80541cbc
MARK_BINARY_BLOB(unk_80541c48, 0x80541c48, 0x80541cbc);
asm UNKNOWN_FUNCTION(unk_80541c48) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  lbz r0, 0x619(r3);
  cmpwi r0, 0;
  beq lbl_80541c8c;
  li r0, 1;
  stb r0, 0x618(r3);
  lis r6, 0x1000;
  lwz r3, 0x584(r3);
  addi r6, r6, 1;
  bl unk_805553b0;
  mr r31, r3;
  b lbl_80541c90;
lbl_80541c8c:
  li r31, 0;
lbl_80541c90:
  cmpwi r31, 0;
  beq lbl_80541ca0;
  mr r3, r30;
  bl process__Q26System15ResourceManagerFv;
lbl_80541ca0:
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_80541cbc
// PAL: 0x80541cbc..0x80541ce0
MARK_BINARY_BLOB(unk_80541cbc, 0x80541cbc, 0x80541ce0);
asm UNKNOWN_FUNCTION(unk_80541cbc) {
  // clang-format off
  nofralloc;
  lbz r0, 0x619(r3);
  cmpwi r0, 0;
  beq lbl_80541cd8;
  li r0, 1;
  stb r0, 0x618(r3);
  lwz r3, 0x584(r3);
  b unk_805553b0;
lbl_80541cd8:
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: unk_80541ce0
// PAL: 0x80541ce0..0x80541e44
MARK_BINARY_BLOB(unk_80541ce0, 0x80541ce0, 0x80541e44);
asm UNKNOWN_FUNCTION(unk_80541ce0) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  li r0, 0;
  stmw r27, 0xc(r1);
  mr r27, r3;
  li r28, 0;
  lis r31, 0;
  lis r29, 0;
  lis r30, 0;
  stb r0, 0x619(r3);
  b lbl_80541e10;
lbl_80541d10:
  lwz r3, 0(r29);
  lwz r3, 0x4c(r3);
  lwz r12, 4(r3);
  lwz r12, 0x14(r12);
  mtctr r12;
  bctrl;
  lwz r3, 0(r29);
  lwz r3, 0x4c(r3);
  lwz r12, 4(r3);
  lwz r12, 8(r12);
  mtctr r12;
  bctrl;
  lwz r3, 0(r31);
  lbz r0, 0x51(r3);
  cmpwi r0, 0;
  beq lbl_80541d7c;
  cmpwi r28, 0;
  bne lbl_80541d6c;
  li r3, 0;
  bl unk_805553b0;
  lwz r3, 0x584(r27);
  lwz r3, 8(r3);
  bl unk_805553b0;
lbl_80541d6c:
  lwz r3, 0(r31);
  li r28, 1;
  bl unk_805553b0;
  b lbl_80541dac;
lbl_80541d7c:
  cmpwi r28, 0;
  beq lbl_80541d90;
  lwz r3, 0x584(r27);
  lwz r3, 8(r3);
  bl unk_805553b0;
lbl_80541d90:
  lwz r3, 0(r29);
  li r28, 0;
  lwz r3, 0x54(r3);
  lwz r12, 0(r3);
  lwz r12, 0x24(r12);
  mtctr r12;
  bctrl;
lbl_80541dac:
  lwz r3, 0(r30);
  bl unk_805553b0;
  lwz r3, 0(r29);
  lwz r3, 0x4c(r3);
  lwz r12, 4(r3);
  lwz r12, 0xc(r12);
  mtctr r12;
  bctrl;
  cmpwi r28, 0;
  beq lbl_80541de0;
  lwz r3, 0(r31);
  bl unk_805553b0;
  b lbl_80541df8;
lbl_80541de0:
  lwz r3, 0(r29);
  lwz r3, 0x54(r3);
  lwz r12, 0(r3);
  lwz r12, 0x28(r12);
  mtctr r12;
  bctrl;
lbl_80541df8:
  lwz r3, 0(r29);
  lwz r3, 0x4c(r3);
  lwz r12, 4(r3);
  lwz r12, 0x10(r12);
  mtctr r12;
  bctrl;
lbl_80541e10:
  lwz r3, 0x584(r27);
  bl unk_805553b0;
  cmpwi r3, 0;
  bne lbl_80541d10;
  li r0, 1;
  stb r0, 0x619(r27);
  li r0, 0;
  stb r0, 0x618(r27);
  lmw r27, 0xc(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_80541e44
// PAL: 0x80541e44..0x80542030
MARK_BINARY_BLOB(unk_80541e44, 0x80541e44, 0x80542030);
asm UNKNOWN_FUNCTION(unk_80541e44) {
  // clang-format off
  nofralloc;
  stwu r1, -0xa0(r1);
  mflr r0;
  stw r0, 0xa4(r1);
  stmw r26, 0x88(r1);
  clrlwi r28, r3, 0x18;
  lis r3, 0;
  mulli r26, r28, 0x1c;
  lwz r27, 0(r3);
  add r3, r27, r26;
  addi r3, r3, 8;
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  beq lbl_80541e84;
  add r3, r27, r26;
  addi r3, r3, 8;
  bl unmount__Q26System15MultiDvdArchiveFv;
lbl_80541e84:
  mulli r28, r28, 0x18;
  li r0, 2;
  li r4, 0;
  add r31, r27, r28;
  stw r0, 0x5b8(r31);
  lwz r3, 0x5b0(r31);
  cmpwi r3, 0;
  beq lbl_80541ed4;
  lwz r6, 0x5b8(r31);
  li r5, 0;
  cmplwi r6, 4;
  bgt lbl_80541ec8;
  li r0, 1;
  slw r0, r0, r6;
  andi. r0, r0, 0x15;
  beq lbl_80541ec8;
  li r5, 1;
lbl_80541ec8:
  cmpwi r5, 0;
  beq lbl_80541ed4;
  li r4, 1;
lbl_80541ed4:
  cmpwi r4, 0;
  beq lbl_80541eec;
  bl unk_805553b0;
  add r3, r27, r28;
  lwz r3, 0x5b4(r3);
  bl unk_805553b0;
lbl_80541eec:
  li r0, 3;
  stw r0, 0x5b8(r31);
  add r4, r27, r28;
  add r3, r27, r26;
  addi r30, r3, 8;
  lwz r29, 0x5b4(r4);
  lwz r28, 0x5b0(r31);
  mr r3, r30;
  lwz r27, 0x5c0(r4);
  lwz r26, 0x5bc(r4);
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  bne lbl_80541fbc;
  cmpwi r27, 2;
  bne lbl_80541f68;
  lis r4, 0;
  cmpwi r26, 0x30;
  addi r4, r4, 0;
  addi r3, r1, 8;
  addi r5, r4, 0x13c;
  li r4, 0x80;
  blt lbl_80541f4c;
  li r6, 0;
  b lbl_80541f5c;
lbl_80541f4c:
  lis r6, 0;
  slwi r0, r26, 2;
  addi r6, r6, 0;
  lwzx r6, r6, r0;
lbl_80541f5c:
  crclr 6;
  bl unk_805553b0;
  b lbl_80541fa4;
lbl_80541f68:
  lis r4, 0;
  cmpwi r26, 0x30;
  addi r4, r4, 0;
  addi r3, r1, 8;
  addi r5, r4, 0x158;
  li r4, 0x80;
  blt lbl_80541f8c;
  li r6, 0;
  b lbl_80541f9c;
lbl_80541f8c:
  lis r6, 0;
  slwi r0, r26, 2;
  addi r6, r6, 0;
  lwzx r6, r6, r0;
lbl_80541f9c:
  crclr 6;
  bl unk_805553b0;
lbl_80541fa4:
  mr r3, r30;
  mr r5, r28;
  mr r6, r29;
  addi r4, r1, 8;
  li r7, 0;
  bl load__Q26System15MultiDvdArchiveFPCcPQ23EGG4HeapPQ23EGG4Heapi;
lbl_80541fbc:
  mr r3, r30;
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  bne lbl_80541ff8;
  lis r4, 0x8000;
  lis r3, 0x1062;
  lwz r0, 0xf8(r4);
  addi r4, r3, 0x4dd3;
  li r3, 0;
  srwi r0, r0, 2;
  mulhwu r4, r4, r0;
  srwi r0, r4, 6;
  rlwinm r4, r4, 0x1e, 2, 0x1b;
  rlwimi r3, r0, 4, 0x1c, 0x1f;
  bl unk_805553b0;
lbl_80541ff8:
  mr r3, r30;
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  beq lbl_80542014;
  li r0, 4;
  stw r0, 0x5b8(r31);
  b lbl_8054201c;
lbl_80542014:
  li r0, 0;
  stw r0, 0x5b8(r31);
lbl_8054201c:
  lmw r26, 0x88(r1);
  lwz r0, 0xa4(r1);
  mtlr r0;
  addi r1, r1, 0xa0;
  blr;
  // clang-format on
}

// Symbol: unk_80542030
// PAL: 0x80542030..0x80542210
MARK_BINARY_BLOB(unk_80542030, 0x80542030, 0x80542210);
asm UNKNOWN_FUNCTION(unk_80542030) {
  // clang-format off
  nofralloc;
  stwu r1, -0xa0(r1);
  mflr r0;
  stw r0, 0xa4(r1);
  mulli r0, r4, 0x1c;
  stmw r26, 0x88(r1);
  mr r27, r3;
  add r3, r3, r0;
  mr r26, r4;
  addi r30, r3, 8;
  mr r3, r30;
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  beq lbl_8054206c;
  mr r3, r30;
  bl unmount__Q26System15MultiDvdArchiveFv;
lbl_8054206c:
  mulli r26, r26, 0x18;
  li r0, 2;
  li r4, 0;
  add r31, r27, r26;
  stw r0, 0x5b8(r31);
  lwz r3, 0x5b0(r31);
  cmpwi r3, 0;
  beq lbl_805420bc;
  lwz r6, 0x5b8(r31);
  li r5, 0;
  cmplwi r6, 4;
  bgt lbl_805420b0;
  li r0, 1;
  slw r0, r0, r6;
  andi. r0, r0, 0x15;
  beq lbl_805420b0;
  li r5, 1;
lbl_805420b0:
  cmpwi r5, 0;
  beq lbl_805420bc;
  li r4, 1;
lbl_805420bc:
  cmpwi r4, 0;
  beq lbl_805420d4;
  bl unk_805553b0;
  add r3, r27, r26;
  lwz r3, 0x5b4(r3);
  bl unk_805553b0;
lbl_805420d4:
  li r0, 3;
  stw r0, 0x5b8(r31);
  add r4, r27, r26;
  mr r3, r30;
  lwz r26, 0x5b4(r4);
  lwz r27, 0x5b0(r31);
  lwz r28, 0x5c0(r4);
  lwz r29, 0x5bc(r4);
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  bne lbl_8054219c;
  cmpwi r28, 2;
  bne lbl_80542148;
  lis r4, 0;
  cmpwi r29, 0x30;
  addi r4, r4, 0;
  addi r3, r1, 8;
  addi r5, r4, 0x177;
  li r4, 0x80;
  blt lbl_8054212c;
  li r6, 0;
  b lbl_8054213c;
lbl_8054212c:
  lis r6, 0;
  slwi r0, r29, 2;
  addi r6, r6, 0;
  lwzx r6, r6, r0;
lbl_8054213c:
  crclr 6;
  bl unk_805553b0;
  b lbl_80542184;
lbl_80542148:
  lis r4, 0;
  cmpwi r29, 0x30;
  addi r4, r4, 0;
  addi r3, r1, 8;
  addi r5, r4, 0x193;
  li r4, 0x80;
  blt lbl_8054216c;
  li r6, 0;
  b lbl_8054217c;
lbl_8054216c:
  lis r6, 0;
  slwi r0, r29, 2;
  addi r6, r6, 0;
  lwzx r6, r6, r0;
lbl_8054217c:
  crclr 6;
  bl unk_805553b0;
lbl_80542184:
  mr r3, r30;
  mr r5, r27;
  mr r6, r26;
  addi r4, r1, 8;
  li r7, 0;
  bl load__Q26System15MultiDvdArchiveFPCcPQ23EGG4HeapPQ23EGG4Heapi;
lbl_8054219c:
  mr r3, r30;
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  bne lbl_805421d8;
  lis r4, 0x8000;
  lis r3, 0x1062;
  lwz r0, 0xf8(r4);
  addi r4, r3, 0x4dd3;
  li r3, 0;
  srwi r0, r0, 2;
  mulhwu r4, r4, r0;
  srwi r0, r4, 6;
  rlwinm r4, r4, 0x1e, 2, 0x1b;
  rlwimi r3, r0, 4, 0x1c, 0x1f;
  bl unk_805553b0;
lbl_805421d8:
  mr r3, r30;
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  beq lbl_805421f4;
  li r0, 4;
  stw r0, 0x5b8(r31);
  b lbl_805421fc;
lbl_805421f4:
  li r0, 0;
  stw r0, 0x5b8(r31);
lbl_805421fc:
  lmw r26, 0x88(r1);
  lwz r0, 0xa4(r1);
  mtlr r0;
  addi r1, r1, 0xa0;
  blr;
  // clang-format on
}

// Symbol: unk_80542210
// PAL: 0x80542210..0x805422cc
MARK_BINARY_BLOB(unk_80542210, 0x80542210, 0x805422cc);
asm UNKNOWN_FUNCTION(unk_80542210) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  mulli r9, r4, 0x18;
  mr r10, r4;
  stw r0, 0x14(r1);
  li r7, 0;
  add r4, r3, r9;
  lwz r0, 0x5b0(r4);
  cmpwi r0, 0;
  beq lbl_80542268;
  lwz r8, 0x5b8(r4);
  li r4, 0;
  cmplwi r8, 4;
  bgt lbl_8054225c;
  li r0, 1;
  slw r0, r0, r8;
  andi. r0, r0, 0x15;
  beq lbl_8054225c;
  li r4, 1;
lbl_8054225c:
  cmpwi r4, 0;
  beq lbl_80542268;
  li r7, 1;
lbl_80542268:
  cmpwi r7, 0;
  bne lbl_80542278;
  li r3, 0;
  b lbl_805422bc;
lbl_80542278:
  add r7, r3, r9;
  li r4, 1;
  stw r5, 0x5bc(r7);
  stw r6, 0x5c0(r7);
  stw r4, 0x5b8(r7);
  lbz r0, 0x619(r3);
  cmpwi r0, 0;
  beq lbl_805422b8;
  stb r4, 0x618(r3);
  lis r4, 0;
  lis r6, 0x1000;
  lwz r3, 0x584(r3);
  mr r5, r10;
  addi r4, r4, 0;
  addi r6, r6, 3;
  bl unk_805553b0;
lbl_805422b8:
  li r3, 1;
lbl_805422bc:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_805422cc
// PAL: 0x805422cc..0x805423bc
MARK_BINARY_BLOB(unk_805422cc, 0x805422cc, 0x805423bc);
asm UNKNOWN_FUNCTION(unk_805422cc) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stmw r26, 8(r1);
  mr r28, r3;
  mr r29, r4;
  mr r26, r5;
  bl getGameScene;
  slwi r31, r26, 2;
  lis r5, 0xd;
  add r3, r3, r31;
  lwz r4, 0xc94(r3);
  addi r3, r5, -32768;
  li r5, 0;
  bl unk_805553b0;
  stw r3, 0x610(r28);
  li r30, 0;
  lis r26, 0xe;
  li r27, 0;
lbl_80542318:
  clrlwi r0, r30, 0x18;
  cmplw r0, r29;
  bge lbl_80542374;
  bl getGameScene;
  mr r0, r3;
  addi r3, r26, 0x1000;
  add r4, r0, r31;
  li r5, 0;
  lwz r4, 0xc94(r4);
  bl unk_805553b0;
  clrlwi r0, r30, 0x18;
  mulli r0, r0, 0x18;
  add r4, r28, r0;
  lwz r0, 0x5b0(r4);
  cmpwi r0, 0;
  bne lbl_8054235c;
  stw r3, 0x5b0(r4);
lbl_8054235c:
  lwz r0, 0x5b4(r4);
  lwz r3, 0x610(r28);
  cmpwi r0, 0;
  bne lbl_8054239c;
  stw r3, 0x5b4(r4);
  b lbl_8054239c;
lbl_80542374:
  mulli r0, r0, 0x18;
  add r3, r28, r0;
  lwz r0, 0x5b0(r3);
  cmpwi r0, 0;
  bne lbl_8054238c;
  stw r27, 0x5b0(r3);
lbl_8054238c:
  lwz r0, 0x5b4(r3);
  cmpwi r0, 0;
  bne lbl_8054239c;
  stw r27, 0x5b4(r3);
lbl_8054239c:
  addi r30, r30, 1;
  cmplwi r30, 4;
  blt lbl_80542318;
  lmw r26, 8(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_805423bc
// PAL: 0x805423bc..0x8054247c
MARK_BINARY_BLOB(unk_805423bc, 0x805423bc, 0x8054247c);
asm UNKNOWN_FUNCTION(unk_805423bc) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stmw r26, 8(r1);
  mr r26, r3;
  li r27, 0;
  li r31, 0;
lbl_805423d8:
  clrlwi r0, r27, 0x18;
  mulli r3, r0, 0x18;
  add r28, r26, r3;
  mulli r0, r0, 0x1c;
  lwz r30, 0x5b0(r28);
  add r3, r26, r0;
  addi r29, r3, 8;
  mr r3, r29;
  bl isLoaded__Q26System15MultiDvdArchiveFv;
  cmpwi r3, 0;
  beq lbl_8054240c;
  mr r3, r29;
  bl unmount__Q26System15MultiDvdArchiveFv;
lbl_8054240c:
  cmpwi r30, 0;
  beq lbl_80542428;
  lwz r12, 0(r30);
  mr r3, r30;
  lwz r12, 0x1c(r12);
  mtctr r12;
  bctrl;
lbl_80542428:
  lwz r0, 0x5b8(r28);
  cmpwi r0, 3;
  beq lbl_80542440;
  stw r31, 0x5b0(r28);
  stw r31, 0x5b4(r28);
  stw r31, 0x5b8(r28);
lbl_80542440:
  addi r27, r27, 1;
  cmplwi r27, 4;
  blt lbl_805423d8;
  lwz r3, 0x610(r26);
  lwz r12, 0(r3);
  lwz r12, 0x1c(r12);
  mtctr r12;
  bctrl;
  li r0, 0;
  stw r0, 0x610(r26);
  lmw r26, 8(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_8054247c
// PAL: 0x8054247c..0x8054248c
MARK_BINARY_BLOB(unk_8054247c, 0x8054247c, 0x8054248c);
asm UNKNOWN_FUNCTION(unk_8054247c) {
  // clang-format off
  nofralloc;
  mulli r0, r4, 0x18;
  add r3, r3, r0;
  lwz r3, 0x5b0(r3);
  blr;
  // clang-format on
}

// Symbol: unk_8054248c
// PAL: 0x8054248c..0x80542524
MARK_BINARY_BLOB(unk_8054248c, 0x8054248c, 0x80542524);
asm UNKNOWN_FUNCTION(unk_8054248c) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  mflr r0;
  lis r4, 0;
  stw r0, 0x44(r1);
  addi r4, r4, 0;
  stw r31, 0x3c(r1);
  mr r31, r3;
  li r3, 3;
  stw r4, 0x10(r1);
  bl unk_805553b0;
  mr r4, r31;
  li r5, -32;
  bl unk_805553b0;
  mr r4, r31;
  li r5, -32;
  bl unk_805553b0;
  lis r4, 0;
  li r0, 0;
  stw r0, 8(r1);
  addi r5, r1, 8;
  lwz r4, 0(r4);
  stw r0, 0xc(r1);
  bl unk_805553b0;
  li r3, 3;
  bl unk_805553b0;
  lwz r8, 8(r1);
  mr r6, r31;
  lwz r9, 0xc(r1);
  addi r4, r1, 0x10;
  li r5, 0;
  li r7, 1;
  lis r10, 2;
  bl unk_805553b0;
  lwz r0, 0x44(r1);
  lwz r31, 0x3c(r1);
  mtlr r0;
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}

// Symbol: unk_80542524
// PAL: 0x80542524..0x80542584
MARK_BINARY_BLOB(unk_80542524, 0x80542524, 0x80542584);
asm UNKNOWN_FUNCTION(unk_80542524) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r5, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  bne lbl_80542550;
  bl getGameScene;
  lwz r5, 0xc98(r3);
lbl_80542550:
  addis r3, r31, 2;
  mr r4, r5;
  addi r0, r3, 0x41f;
  li r5, 0;
  rlwinm r3, r0, 0, 0, 0x1a;
  bl unk_805553b0;
  stw r3, 0x614(r30);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_80542584
// PAL: 0x80542584..0x805425d0
MARK_BINARY_BLOB(unk_80542584, 0x80542584, 0x805425d0);
asm UNKNOWN_FUNCTION(unk_80542584) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl unk_80541ce0;
  lwz r3, 0x614(r31);
  lwz r12, 0(r3);
  lwz r12, 0x1c(r12);
  mtctr r12;
  bctrl;
  li r0, 0;
  stw r0, 0x614(r31);
  stb r0, 0x60c(r31);
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_805425d0
// PAL: 0x805425d0..0x80542694
MARK_BINARY_BLOB(unk_805425d0, 0x805425d0, 0x80542694);
asm UNKNOWN_FUNCTION(unk_805425d0) {
  // clang-format off
  nofralloc;
  stwu r1, -0x50(r1);
  mflr r0;
  lis r4, 0;
  lis r5, 0;
  stw r0, 0x54(r1);
  addi r4, r4, 0;
  stw r31, 0x4c(r1);
  stw r30, 0x48(r1);
  stw r29, 0x44(r1);
  stw r28, 0x40(r1);
  mr r28, r3;
  li r3, 3;
  lwz r29, 0(r5);
  lwz r30, 0x614(r29);
  stw r4, 0x10(r1);
  bl unk_805553b0;
  mr r4, r30;
  li r5, -32;
  bl unk_805553b0;
  mr r4, r30;
  li r5, -32;
  bl unk_805553b0;
  lis r4, 0;
  li r31, 0;
  stw r31, 8(r1);
  addi r5, r1, 8;
  lwz r4, 0(r4);
  stw r31, 0xc(r1);
  bl unk_805553b0;
  li r3, 3;
  bl unk_805553b0;
  lwz r8, 8(r1);
  mr r6, r30;
  lwz r9, 0xc(r1);
  addi r4, r1, 0x10;
  li r5, 0;
  li r7, 1;
  lis r10, 2;
  bl unk_805553b0;
  stw r3, 0(r28);
  stb r31, 0x60c(r29);
  lwz r0, 0x54(r1);
  lwz r31, 0x4c(r1);
  lwz r30, 0x48(r1);
  lwz r29, 0x44(r1);
  lwz r28, 0x40(r1);
  mtlr r0;
  addi r1, r1, 0x50;
  blr;
  // clang-format on
}

// Symbol: unk_80542694
// PAL: 0x80542694..0x80542754
MARK_BINARY_BLOB(unk_80542694, 0x80542694, 0x80542754);
asm UNKNOWN_FUNCTION(unk_80542694) {
  // clang-format off
  nofralloc;
  stwu r1, -0x50(r1);
  mflr r0;
  lis r5, 0;
  stw r0, 0x54(r1);
  addi r5, r5, 0;
  stw r31, 0x4c(r1);
  stw r30, 0x48(r1);
  stw r29, 0x44(r1);
  mr r29, r4;
  stw r28, 0x40(r1);
  mr r28, r3;
  lwz r30, 0x614(r3);
  li r3, 3;
  stw r5, 0x10(r1);
  bl unk_805553b0;
  mr r4, r30;
  li r5, -32;
  bl unk_805553b0;
  mr r4, r30;
  li r5, -32;
  bl unk_805553b0;
  lis r4, 0;
  li r31, 0;
  stw r31, 8(r1);
  addi r5, r1, 8;
  lwz r4, 0(r4);
  stw r31, 0xc(r1);
  bl unk_805553b0;
  li r3, 3;
  bl unk_805553b0;
  lwz r8, 8(r1);
  mr r6, r30;
  lwz r9, 0xc(r1);
  addi r4, r1, 0x10;
  li r5, 0;
  li r7, 1;
  lis r10, 2;
  bl unk_805553b0;
  stw r3, 0(r29);
  stb r31, 0x60c(r28);
  lwz r0, 0x54(r1);
  lwz r31, 0x4c(r1);
  lwz r30, 0x48(r1);
  lwz r29, 0x44(r1);
  lwz r28, 0x40(r1);
  mtlr r0;
  addi r1, r1, 0x50;
  blr;
  // clang-format on
}

// Symbol: unk_80542754
// PAL: 0x80542754..0x805427bc
MARK_BINARY_BLOB(unk_80542754, 0x80542754, 0x805427bc);
asm UNKNOWN_FUNCTION(unk_80542754) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  mr r5, r4;
  stw r0, 0x14(r1);
  lbz r0, 0x60c(r3);
  cmpwi r0, 0;
  beq lbl_80542778;
  li r3, 0;
  b lbl_805427ac;
lbl_80542778:
  li r4, 1;
  stb r4, 0x60c(r3);
  lbz r0, 0x619(r3);
  cmpwi r0, 0;
  beq lbl_805427a8;
  stb r4, 0x618(r3);
  lis r4, 0;
  lis r6, 0x1000;
  lwz r3, 0x584(r3);
  addi r4, r4, 0;
  addi r6, r6, 4;
  bl unk_805553b0;
lbl_805427a8:
  li r3, 1;
lbl_805427ac:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: SaveManager_loadStaffGhostAsync
// PAL: 0x805427bc..0x80542868
MARK_BINARY_BLOB(SaveManager_loadStaffGhostAsync, 0x805427bc, 0x80542868);
asm UNKNOWN_FUNCTION(SaveManager_loadStaffGhostAsync) {
  // clang-format off
  nofralloc;
  stwu r1, -0x90(r1);
  mflr r0;
  stw r0, 0x94(r1);
  stw r31, 0x8c(r1);
  mr r31, r5;
  stw r30, 0x88(r1);
  mr r30, r3;
  mr r3, r4;
  bl getSlotForCourseId;
  cmpwi r30, 2;
  mr r0, r3;
  bne lbl_80542810;
  lis r4, 0;
  addi r3, r1, 8;
  addi r4, r4, 0;
  extsh r6, r0;
  addi r5, r4, 0x1b2;
  li r4, 0x80;
  crclr 6;
  bl unk_805553b0;
  b lbl_80542830;
lbl_80542810:
  lis r4, 0;
  addi r3, r1, 8;
  addi r4, r4, 0;
  extsh r6, r0;
  addi r5, r4, 0x1df;
  li r4, 0x80;
  crclr 6;
  bl unk_805553b0;
lbl_80542830:
  lis r3, 0;
  mr r8, r31;
  lwz r3, 0(r3);
  addi r4, r1, 8;
  li r5, 0;
  li r6, 1;
  li r7, 0;
  bl unk_805553b0;
  lwz r0, 0x94(r1);
  lwz r31, 0x8c(r1);
  lwz r30, 0x88(r1);
  mtlr r0;
  addi r1, r1, 0x90;
  blr;
  // clang-format on
}

// Symbol: unk_80542868
// PAL: 0x80542868..0x80542878
MARK_BINARY_BLOB(unk_80542868, 0x80542868, 0x80542878);
asm UNKNOWN_FUNCTION(unk_80542868) {
  // clang-format off
  nofralloc;
  stw r4, 4(r3);
  stw r5, 8(r3);
  li r3, 1;
  blr;
  // clang-format on
}
