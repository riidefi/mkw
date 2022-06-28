#include "ResourceManager.hpp"

#include <rvl/os/osThread.h>
#include <game/host_system/SystemManager.hpp>
#include <game/host_system/SystemResources.hpp>
#include <game/RKScene.hpp>

#pragma dont_reuse_strings on
#pragma legacy_struct_alignment off

extern RKScene* scenePtr;

extern const char* EarthResourceListing;

// .rodata
const char* RESOURCES[] = {
    // clang-format off
    "/Race/Common",
    "",
    "",
    "/Scene/UI/Font",
    "/Scene/Model/Earth",
    "/Scene/Model/MiiBody",
    "/Scene/Model/Driver",
    "/Demo/Award",
    "/Scene/Model/BackModel"
    // clang-format on
};

const char* COURSE_NAMES[] = {
    // clang-format off
    "castle_course",
    "farm_course",
    "kinoko_course",
    "volcano_course",
    "factory_course",
    "shopping_course",
    "boardcross_course",
    "truck_course",
    "beginner_course",
    "senior_course",
    "ridgehighway_course",
    "treehouse_course",
    "koopa_course",
    "rainbow_course",
    "desert_course",
    "water_course",
    "old_peach_gc",
    "old_mario_gc",
    "old_waluigi_gc",
    "old_donkey_gc",
    "old_falls_ds",
    "old_desert_ds",
    "old_garden_ds",
    "old_town_ds",
    "old_mario_sfc",
    "old_obake_sfc",
    "old_mario_64",
    "old_sherbet_64",
    "old_koopa_64",
    "old_donkey_64",
    "old_koopa_gba",
    "old_heyho_gba",
    "venice_battle",
    "block_battle",
    "casino_battle",
    "skate_battle",
    "sand_battle",
    "old_CookieLand_gc",
    "old_House_ds",
    "old_battle4_sfc",
    "old_battle3_gba",
    "old_matenro_64",
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    "ring_mission",
    "winningrun_demo",
    "loser_demo",
    "draw_dmeo",
    "ending_demo",
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr
    // clang-format on
};
const s32 COURSE_NAMES_SIZE = sizeof(COURSE_NAMES) / sizeof(COURSE_NAMES[0]);

const char* CHARACTER_NAMES[] = {
    "mr",       "bpc",      "wl",       "kp",       "bds",      "ka",
    "bmr",      "lg",       "ko",       "dk",       "ys",       "wr",
    "blg",      "kk",       "nk",       "ds",       "pc",       "ca",
    "dd",       "kt",       "jr",       "bk",       "fk",       "rs",
    "sa_mii_m", "sa_mii_f", "sb_mii_m", "sb_mii_f", "sc_mii_m", "sc_mii_f",
    "ma_mii_m", "ma_mii_f", "mb_mii_m", "mb_mii_f", "mc_mii_m", "mc_mii_f",
    "la_mii_m", "la_mii_f", "lb_mii_m", "lb_mii_f", "lc_mii_m", "lc_mii_f",
    "m_mii",    "s_mii",    "l_mii",    "pc_menu",  "ds_menu",  "rs_menu"};

const s32 CHAR_NAMES_SIZE =
    sizeof(CHARACTER_NAMES) / sizeof(CHARACTER_NAMES[0]);

const char* VEHICLE_NAMES[] = {
    "sdf_kart", "mdf_kart", "ldf_kart", "sa_kart", "ma_kart", "la_kart",
    "sb_kart",  "mb_kart",  "lb_kart",  "sc_kart", "mc_kart", "lc_kart",
    "sd_kart",  "md_kart",  "ld_kart",  "se_kart", "me_kart", "le_kart",
    "sdf_bike", "mdf_bike", "ldf_bike", "sa_bike", "ma_bike", "la_bike",
    "sb_bike",  "mb_bike",  "lb_bike",  "sc_bike", "mc_bike", "lc_bike",
    "sd_bike",  "md_bike",  "ld_bike",  "se_bike", "me_bike", "le_bike",
};
const s32 VEHICLE_NAMES_SIZE = sizeof(VEHICLE_NAMES) / sizeof(VEHICLE_NAMES[0]);

const char* TEAM_SUFFIXES[] = {"_red", "_blue", ""};
const char* LOD_RES_SUFFIXES[] = {"", "_2", "_4"};

const char* EarthResourceListing = "/earth.brres.LZ";

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

void ResourceManager::doLoadTask(void* jobContext) {
  JobContext* context = &spInstance->jobContexts[(s32)jobContext];

  switch ((s32)jobContext) {
  case 6:
    context->archive->load(context->filename, context->_08,
                           context->archiveHeap);
    return;
  case 5:
    context->multiArchive->load(context->filename, context->archiveHeap,
                                context->fileHeap, 0);
    return;
  default:
    context->multiArchive->load(context->filename, context->archiveHeap, 0, 0);
    return;
  }
}

} // namespace System

// Symbol: process__Q26System15ResourceManagerFv
// PAL: 0x805400a0..0x805401ec
// Notes: we cannot decompile this without DiscCheckThread
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

class Dummy {
public:
  Dummy();
  virtual void _08() = 0;
  virtual void _0c() = 0;
  virtual void _10() = 0;
  virtual void _14() = 0;
  virtual void _18() = 0;
  virtual void _1C() = 0;
};

// no clue what class this is supposed to be so here are two dummy functions
void _unk_call14(Dummy* dummy) { dummy->_14(); }

void _unk_call1c(Dummy* dummy) { dummy->_1C(); }

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

void ResourceManager::requestLoad(s32 idx, DvdArchive* archive,
                                  const char* filename, u32 unk,
                                  EGG::Heap* archiveHeap) {
  this->jobContexts[idx].archive = archive;
  strncpy(this->jobContexts[idx].filename, filename, 0x40);
  this->jobContexts[idx].archiveHeap = archiveHeap;
  this->jobContexts[idx]._08 = unk;

  this->taskThread->request(ResourceManager::doLoadTask, (void*)idx, 0);
  this->process();

  if (!archive->isLoaded()) {
    OSSleepMilliseconds(16);
  }
}

void ResourceManager::requestLoad(s32 idx, MultiDvdArchive* archive,
                                  const char* filename, EGG::Heap* archiveHeap,
                                  EGG::Heap* fileHeap) {
  this->jobContexts[idx].multiArchive = archive;
  strncpy(this->jobContexts[idx].filename, filename, 0x40);
  this->jobContexts[idx].archiveHeap = archiveHeap;
  this->jobContexts[idx].fileHeap = fileHeap;

  this->taskThread->request(ResourceManager::doLoadTask, (void*)idx, 0);
  this->process();

  if (!archive->isLoaded()) {
    OSSleepMilliseconds(16);
  }
}

MultiDvdArchive* ResourceManager::load(ResourceChannelID channelId,
                                       EGG::Heap* archiveHeap,
                                       const char* filename) {
  if (!filename) {
    filename = RESOURCES[channelId];
  }

  if (!multiArchives1[channelId]->isLoaded() && filename[0]) {
    requestLoad(0, this->multiArchives1[channelId], filename, archiveHeap);
  }

  return this->multiArchives1[channelId];
}

DvdArchive* ResourceManager::loadSystemResource(s32 idx,
                                                EGG::Heap* archiveHeap) {
  if (!dvdArchives[idx].isLoaded()) {
    const char* resourcePath = Resource::GetResourcePath((eSystemResource)idx);
    if (resourcePath[0] != 0) {
      requestLoadFile(
          6, &dvdArchives[idx], Resource::GetResourcePath((eSystemResource)idx),
          Resource::GetResourceID((eSystemResource)idx), archiveHeap);
    }
  }
  return &dvdArchives[idx];
}

MultiDvdArchive* ResourceManager::loadUI(const char* filename,
                                         EGG::Heap* archiveHeap) {
  if (!this->multiArchives1[2]->isLoaded() && filename) {
    requestLoad(1, this->multiArchives1[2], filename, archiveHeap);
  }
  return this->multiArchives1[2];
}

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

MultiDvdArchive* ResourceManager::loadMission(CourseId courseId, s32 missionNum,
                                              EGG::Heap* param_3,
                                              bool splitScreen) {
  char missionPath[128];
  char courseName[128];

  if (!this->multiArchives1[1]->isLoaded()) {
    this->multiArchives1[1]->init();
    snprintf(missionPath, sizeof(missionPath), "Race/MissionRun/mr%02d.szs",
             missionNum);
    MultiDvdArchive* archive = this->multiArchives1[1];
    if (archive->archiveCount > 1) {
      archive->kinds[1] = RES_KIND_FILE_SINGLE_FORMAT;
      strncpy(archive->suffixes[1], missionPath, sizeof(missionPath));
    }

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
      requestLoad(3, this->multiArchives1[1], courseName, param_3);
    }
  }
  return this->multiArchives1[1];
}

MultiDvdArchive* ResourceManager::loadCompetition(CourseId courseId,
                                                  void* fileStart, u32 fileSize,
                                                  EGG::Heap* heap, u8 param6) {
  char competitionPath[128];
  char courseName[128];

  if (!this->multiArchives1[1]->isLoaded()) {
    this->multiArchives1[1]->init();

    u16 objCount = 1;
    u16 var4 = 0;
    for (u8 i = 0; i < 0x10; i++) {
      if ((param6 & (1 << i)) != 0) {
        snprintf(competitionPath, sizeof(competitionPath),
                 "Race/Competition/CommonObj/CommonObj%02d.szs", i + 1);
        MultiDvdArchive* archive = this->multiArchives1[1];

        if (objCount < archive->archiveCount) {
          archive->kinds[objCount] = RES_KIND_FILE_SINGLE_FORMAT;
          strncpy(archive->suffixes[objCount], competitionPath,
                  sizeof(competitionPath));
        }

        objCount++;
        var4++;
        if (var4 > 1)
          break;
      }
    }

    if (objCount < this->multiArchives1[1]->archiveCount) {
      MultiDvdArchive* archive = this->multiArchives1[1];
      archive->kinds[objCount] = RES_KIND_BUFFER;
      archive->fileStarts[objCount] = fileStart;
      archive->fileSizes[objCount] = fileSize;
    }

    snprintf(courseName, sizeof(courseName), "Race/Course/%s",
             COURSE_NAMES[courseId]);
    requestLoad(4, this->multiArchives1[1], courseName, heap);
  }
  return this->multiArchives1[1];
}

MultiDvdArchive* ResourceManager::loadKartFromArchive(
    MultiDvdArchive* archive, u32 unu, VehicleId vehicleId,
    CharacterId characterId, BattleTeam battleTeamId, PlayMode playMode,
    EGG::Heap* archiveHeap, EGG::Heap* fileHeap) {
  char path[128];
  const char* driver = getCharacterName(characterId);
  const char* kart = getVehicleName(vehicleId);

  snprintf(path, sizeof(path), "Race/Kart/%s%s-%s%s", kart,
           TEAM_SUFFIXES[battleTeamId], driver, LOD_RES_SUFFIXES[playMode]);
  requestLoadFile(5, archive, path, archiveHeap, fileHeap);
  return archive;
}

MultiDvdArchive* ResourceManager::loadKartFromArchive2(
    s32 archiveIdx, VehicleId vehicleId, CharacterId characterId,
    BattleTeam battleTeamId, PlayMode playMode, EGG::Heap* archiveHeap,
    EGG::Heap* fileHeap) {
  MultiDvdArchive* archive = &this->multiArchives2[archiveIdx];
  char path[128];

  if (!archive->isLoaded()) {
    const char* driver = getCharacterName(characterId);
    const char* kart = getVehicleName(vehicleId);
    snprintf(path, sizeof(path), "Race/Kart/%s%s-%s%s", kart,
             TEAM_SUFFIXES[battleTeamId], driver, LOD_RES_SUFFIXES[playMode]);
    requestLoadFile(5, archive, path, archiveHeap, fileHeap);
    return archive;
  }
  return archive;
}

MultiDvdArchive* ResourceManager::loadKartFromArchive3(
    s32 archiveIdx, VehicleId vehicleId, CharacterId characterId,
    BattleTeam battleTeamId, PlayMode playMode, EGG::Heap* archiveHeap,
    EGG::Heap* fileHeap) {
  MultiDvdArchive* archive = &this->multiArchives3[archiveIdx];
  char path[128];

  if (!archive->isLoaded()) {
    const char* driver = getCharacterName(characterId);
    const char* kart = getVehicleName(vehicleId);
    snprintf(path, sizeof(path), "Race/Kart/%s%s-%s%s", kart,
             TEAM_SUFFIXES[battleTeamId], driver, LOD_RES_SUFFIXES[playMode]);
    requestLoadFile(5, archive, path, archiveHeap, fileHeap);
    return archive;
  }
  return archive;
}

MultiDvdArchive* ResourceManager::loadMenuKartModel(s32 archiveIdx,
                                                    CharacterId characterId,
                                                    BattleTeam battleTeam,
                                                    EGG::Heap* archiveHeap,
                                                    EGG::Heap* fileHeap) {
  const char* characterName;
  char buffer[128];

  if (!multiArchives2[archiveIdx].isLoaded()) {
    if (battleTeam == 2) { // not in battle mode
      characterName = getCharacterName(characterId);
      snprintf(buffer, sizeof(buffer), "Scene/Model/Kart/%s-allkart",
               characterName);
    } else {
      characterName = getCharacterName(characterId);
      snprintf(buffer, sizeof(buffer), "Scene/Model/Kart/%s-allkart_BT",
               characterName);
    }
    multiArchives2[archiveIdx].load(buffer, archiveHeap, fileHeap, 0);
  }
  return &multiArchives2[archiveIdx];
}

void ResourceManager::unmountMulti(s32 archiveIdx) {
  multiArchives1[archiveIdx]->unmount();
}

void ResourceManager::unmountMulti(MultiDvdArchive* other) { other->unmount(); }

void ResourceManager::unmountArchive(s32 archiveIdx) {
  dvdArchives[archiveIdx].unmount();
}

void* ResourceManager::getFile(s32 archiveIdx, const char* filename,
                               size_t* size) {
  return (multiArchives1[archiveIdx]->isLoaded())
             ? multiArchives1[archiveIdx]->getFile(filename, size)
             : nullptr;
}

void* ResourceManager::getCharacterFile(CharacterId characterId, size_t* size) {
  char buffer[128];

  if (!multiArchives1[6]->isLoaded()) {
    return nullptr;
  }
  const char* character = getCharacterName(characterId);
  // I can't believe this compiles
  snprintf("%s.brres", sizeof(buffer), character);
  return multiArchives1[6]->getFile(buffer, size);
}

void* ResourceManager::getVehicleFile(s32 archiveIdx, VehicleId vehicleId,
                                      size_t* size) {
  char buffer[128];

  if (!multiArchives2[archiveIdx].isLoaded()) {
    return nullptr;
  }
  const char* vehicle = getVehicleName(vehicleId);
  // I can't believe this compiles
  snprintf("%s.brres", sizeof(buffer), vehicle);
  return multiArchives2[archiveIdx].getFile(buffer, size);
}

void* ResourceManager::getMultiFile2(u16 idx, const char* filename,
                                     size_t* size) {
  return this->multiArchives2[idx].isLoaded()
             ? this->multiArchives2[idx].getFile(filename, size)
             : nullptr;
}

void* ResourceManager::getMultiFile3(u16 idx, const char* filename,
                                     size_t* size) {
  return this->multiArchives3[idx].isLoaded()
             ? this->multiArchives3[idx].getFile(filename, size)
             : nullptr;
}
} // namespace System

// Symbol: ResourceManager_loadBSP
// PAL: 0x805414a8..0x8054155c
// Notes: requires Racedata decomp
MARK_BINARY_BLOB(ResourceManager_loadBSP, 0x805414a8, 0x8054155c);
asm UNKNOWN_FUNCTION(ResourceManager_loadBSP) {
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

namespace System {
void* ResourceManager::getFileCopy(s32 archiveIdx, char* filename,
                                   EGG::Heap* heap, size_t* size, s8 param_5) {
  return (!dvdArchives[archiveIdx].isLoaded())
             ? 0
             : dvdArchives[archiveIdx].getFileCopy(filename, heap, size,
                                                   param_5);
}

bool ResourceManager::isMultiArchive1Loaded(int idx) {
  return this->multiArchives1[idx]->isLoaded();
}

bool ResourceManager::isMultiArchive2Loaded(int idx) {
  return this->multiArchives2[idx].isLoaded();
}

bool ResourceManager::isMultiArchive3Loaded(int idx) {
  return this->multiArchives3[idx].isLoaded();
}

bool ResourceManager::isDvdArchiveLoaded(int idx) {
  return this->dvdArchives[idx].isLoaded();
}

void* ResourceManager::getArchiveStart(ResourceChannelID resId,
                                       u32 archiveIdx) {
  if (!this->multiArchives1[resId]->isLoaded()) {
    return nullptr;
  } else if (archiveIdx < this->multiArchives1[resId]->archiveCount) {
    return this->multiArchives1[resId]->archives[archiveIdx].mArchiveStart;
  }
  return nullptr;
}

} // namespace System

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

namespace System {
u16 ResourceManager::getLoadedArchiveCount(int idx) {
  return this->multiArchives1[idx]->isLoaded()
             ? this->multiArchives1[idx]->archiveCount
             : 0;
}

u16 ResourceManager::getMenuArchiveCount() {
  return this->multiArchives1[2]->archiveCount;
}
} // namespace System

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
/*namespace System {
void ResourceManager::preloadCourseTask(u32 courseId) {
ResourceManager::spInstance->courseCache.load(courseId); }
}*/

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

namespace System {

const char* getCharacterName(CharacterId charId) {
  return (charId >= CHAR_NAMES_SIZE) ? nullptr : CHARACTER_NAMES[charId];
}

const char* getVehicleName(VehicleId vehicleId) {
  return (vehicleId >= VEHICLE_NAMES_SIZE) ? nullptr : VEHICLE_NAMES[vehicleId];
}

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
