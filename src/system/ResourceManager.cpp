#include "ResourceManager.hpp"

#include <rvl/os/osThread.h>
#include <rvl/vi.h>
#include <host_system/RKSystem.hpp>
#include <host_system/SystemManager.hpp>
#include <host_system/SystemResources.hpp>
#include <host_system/eggAsyncDvdStatus.hpp>
#include <system/RaceConfig.hpp>
#include <egg/core/eggStreamDecomp.hpp>
#include <egg/core/eggDvdRipper.hpp>
#include <egg/core/eggDisplay.hpp>
#include <host_system/RKScene.hpp>

#pragma dont_reuse_strings on
#pragma legacy_struct_alignment off

extern void ArcResourceLink_set(void* arcResource, void* archiveStart,
                                const char* dirname);
extern void ArcResourceAccessor_attach(void* arcResourceAccessor,
                                       void* archiveStart, const char* dirname);
extern void MultiArcResourceAccessor_attach(void* multiArcResourceAccessor,
                                            void* param_2);
extern "C" s16 getSlotForCourseId(System::CourseId courseId);

extern const char* EarthResourceListing;

// TODO: Define externally
struct GameScene {
  u8 _00[0xc94 - 0x0];
  HeapCollection mDynamicHeaps;
  inline EGG::ExpHeap*& getHeap(s32 heapIdx) {
    return mDynamicHeaps.mpHeaps[heapIdx];
  }
};
extern "C" GameScene* getGameScene();

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
// extern UNKNOWN_FUNCTION(getGameScene);
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
// PAL: 0x805553b0
extern UNKNOWN_FUNCTION(_unresolved);
}

namespace System {

// .bss
ResourceManager::ResMgrInstance ResourceManager::spInstance;

volatile ResourceManager* ResourceManager::createInstance() {
  if (!spInstance.vol) {
    spInstance.vol = new ResourceManager();
  }

  return spInstance.vol;
}

void ResourceManager::destroyInstance() {
  if (spInstance.vol) {
    delete spInstance.vol;
  }
  spInstance.vol = nullptr;
}

ResourceManager::ResourceManager() {
  foo();
  mpTaskThread =
      EGG::TaskThread::create(14, 24, 0xC800, InitScene::spInstance->getA());
  mpTaskThread->mTaskEndMessageQueue = &System::SystemManager::sInstance->_B8;
  mppSceneArchives = new MultiDvdArchive*[9];
  for (u16 i = 0; i < 9; ++i) {
    mppSceneArchives[i] = createMultiDvdArchive((ResourceChannelID)i);
  }
  bar();
}

System::ResourceManager::~ResourceManager() {
  mpTaskThread->destroy();
  mpTaskThread = nullptr;
}

void ResourceManager::doLoadTask(void* jobContext) {
  JobContext* context =
      (JobContext*)&spInstance.vol->mJobContexts[(s32)jobContext];

  switch ((s32)jobContext) {
  case 6:
    context->mpArchive->load(context->mFilename, context->_08,
                             context->mpArchiveHeap);
    return;
  case 5:
    context->mpMultiArchive->load(context->mFilename, context->mpArchiveHeap,
                                  context->mpFileHeap, 0);
    return;
  default:
    context->mpMultiArchive->load(context->mFilename, context->mpArchiveHeap, 0,
                                  0);
    return;
  }
}

void ResourceManager::process() { _process(); }

void ResourceManager::_process() {
  bool isSuspended = false;
  while (mpTaskThread->isTaskExist()) {
    RKSystem::spInstance->mDisplay->endFrame();
    RKSystem::spInstance->mDisplay->beginFrame();
    if (EGG::AsyncDvdStatus::sInstance->_51) {
      if (!isSuspended) {
        VISetBlack(0);
        OSSuspendThread(mpTaskThread->getOSThread());
      }
      isSuspended = true;
      EGG::AsyncDvdStatus::sInstance->halt();
    } else {
      if (isSuspended) {
        OSResumeThread(mpTaskThread->getOSThread());
      }
      isSuspended = false;
      ((RKSceneManager*)RKSystem::spInstance->mSceneMgr)->doCalcFader();
    }
    SystemManager::sInstance->handlePowerState();
    RKSystem::spInstance->mDisplay->beginRender();
    if (isSuspended) {
      EGG::AsyncDvdStatus::sInstance->printError();
    } else {
      ((RKSceneManager*)RKSystem::spInstance->mSceneMgr)->doDrawFader();
    }
    RKSystem::spInstance->mDisplay->endRender();
  }
}

} // namespace System

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
  mJobContexts[idx].mpMultiArchive = m;
  strncpy(mJobContexts[idx].mFilename, p, 0x40);
  mJobContexts[idx].mpArchiveHeap = archiveHeap;

  mpTaskThread->request(ResourceManager::doLoadTask, (void*)idx, 0);
  process();

  if (!m->isLoaded()) {
    OSSleepMilliseconds(16);
  }
}

void ResourceManager::requestLoad(s32 idx, DvdArchive* archive,
                                  const char* filename, u32 unk,
                                  EGG::Heap* archiveHeap) {
  mJobContexts[idx].mpArchive = archive;
  strncpy(mJobContexts[idx].mFilename, filename, 0x40);
  mJobContexts[idx].mpArchiveHeap = archiveHeap;
  mJobContexts[idx]._08 = unk;

  mpTaskThread->request(ResourceManager::doLoadTask, (void*)idx, 0);
  process();

  if (!archive->isLoaded()) {
    OSSleepMilliseconds(16);
  }
}

void ResourceManager::requestLoad(s32 idx, MultiDvdArchive* archive,
                                  const char* filename, EGG::Heap* archiveHeap,
                                  EGG::Heap* fileHeap) {
  mJobContexts[idx].mpMultiArchive = archive;
  strncpy(mJobContexts[idx].mFilename, filename, 0x40);
  mJobContexts[idx].mpArchiveHeap = archiveHeap;
  mJobContexts[idx].mpFileHeap = fileHeap;

  mpTaskThread->request(ResourceManager::doLoadTask, (void*)idx, 0);
  process();

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

  if (!isSceneArchiveLoaded(channelId) && filename[0]) {
    requestLoad(0, mppSceneArchives[channelId], filename, archiveHeap);
  }

  return mppSceneArchives[channelId];
}

DvdArchive* ResourceManager::loadSystemResource(s32 idx,
                                                EGG::Heap* archiveHeap) {
  if (!isSystemArchiveLoaded(idx)) {
    const char* resourcePath = Resource::GetResourcePath((eSystemResource)idx);

    if (resourcePath[0] != 0) {
      requestLoadFile(6, &mSystemArchives[idx],
                      Resource::GetResourcePath((eSystemResource)idx),
                      Resource::GetResourceID((eSystemResource)idx),
                      archiveHeap);
    }
  }

  return &mSystemArchives[idx];
}

MultiDvdArchive* ResourceManager::loadUI(const char* filename,
                                         EGG::Heap* archiveHeap) {
  if (!isSceneArchiveLoaded(2) && filename) {
    requestLoad(1, mppSceneArchives[2], filename, archiveHeap);
  }
  return mppSceneArchives[2];
}

MultiDvdArchive* ResourceManager::loadCourse(CourseId courseId,
                                             EGG::Heap* param_3,
                                             bool splitScreen) {
  char courseName[128];

  if (!isSceneArchiveLoaded(1)) {
    mppSceneArchives[1]->init();

    if (!splitScreen && mCourseCache.mState == 2 &&
        courseId == mCourseCache.mCourseId) {
      MultiDvdArchive* m = mppSceneArchives[1];

      if (mCourseCache.mState == 2)
        m->loadOther(mCourseCache.mpArchive, param_3);
    } else {
      if (splitScreen) {
        snprintf(courseName, sizeof(courseName), "Race/Course/%s_d",
                 COURSE_NAMES[courseId]);

        if (!mppSceneArchives[1]->exists(courseName)) {
          splitScreen = false;
        }
      }
      if (!splitScreen) {
        snprintf(courseName, sizeof(courseName), "Race/Course/%s",
                 COURSE_NAMES[courseId]);
      }
      requestLoad(2, mppSceneArchives[1], courseName, param_3);
    }
  }
  return mppSceneArchives[1];
}

MultiDvdArchive* ResourceManager::loadMission(CourseId courseId, s32 missionNum,
                                              EGG::Heap* param_3,
                                              bool splitScreen) {
  char missionPath[128];
  char courseName[128];

  if (!isSceneArchiveLoaded(1)) {
    mppSceneArchives[1]->init();

    snprintf(missionPath, sizeof(missionPath), "Race/MissionRun/mr%02d.szs",
             missionNum);

    MultiDvdArchive* archive = mppSceneArchives[1];

    if (archive->archiveCount > 1) {
      archive->kinds[1] = RES_KIND_FILE_SINGLE_FORMAT;
      strncpy(archive->suffixes[1], missionPath, sizeof(missionPath));
    }

    if (!splitScreen && mCourseCache.mState == 2 &&
        courseId == mCourseCache.mCourseId) {
      MultiDvdArchive* m = mppSceneArchives[1];

      if (mCourseCache.mState == 2)
        m->loadOther(mCourseCache.mpArchive, param_3);
    } else {
      if (splitScreen) {
        snprintf(courseName, sizeof(courseName), "Race/Course/%s_d",
                 COURSE_NAMES[courseId]);

        if (!mppSceneArchives[1]->exists(courseName)) {
          splitScreen = false;
        }
      }
      if (!splitScreen) {
        snprintf(courseName, sizeof(courseName), "Race/Course/%s",
                 COURSE_NAMES[courseId]);
      }
      requestLoad(3, mppSceneArchives[1], courseName, param_3);
    }
  }
  return mppSceneArchives[1];
}

MultiDvdArchive* ResourceManager::loadCompetition(CourseId courseId,
                                                  void* fileStart, u32 fileSize,
                                                  EGG::Heap* heap, u8 param6) {
  char competitionPath[128];
  char courseName[128];

  if (!isSceneArchiveLoaded(1)) {
    mppSceneArchives[1]->init();

    u16 objCount = 1;
    u16 var4 = 0;

    for (u8 i = 0; i < 0x10; i++) {
      if ((param6 & (1 << i)) != 0) {
        snprintf(competitionPath, sizeof(competitionPath),
                 "Race/Competition/CommonObj/CommonObj%02d.szs", i + 1);
        MultiDvdArchive* archive = mppSceneArchives[1];

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

    if (objCount < mppSceneArchives[1]->archiveCount) {
      MultiDvdArchive* archive = mppSceneArchives[1];
      archive->kinds[objCount] = RES_KIND_BUFFER;
      archive->fileStarts[objCount] = fileStart;
      archive->fileSizes[objCount] = fileSize;
    }

    snprintf(courseName, sizeof(courseName), "Race/Course/%s",
             COURSE_NAMES[courseId]);
    requestLoad(4, mppSceneArchives[1], courseName, heap);
  }
  return mppSceneArchives[1];
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
  MultiDvdArchive* archive = &mKartArchives[archiveIdx];
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
  MultiDvdArchive* archive = &mBackupKartArchives[archiveIdx];
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

  if (!isKartArchiveLoaded(archiveIdx)) {
    if (battleTeam == BATTLE_TEAM_NONE) {
      characterName = getCharacterName(characterId);
      snprintf(buffer, sizeof(buffer), "Scene/Model/Kart/%s-allkart",
               characterName);
    } else {
      characterName = getCharacterName(characterId);
      snprintf(buffer, sizeof(buffer), "Scene/Model/Kart/%s-allkart_BT",
               characterName);
    }
    mKartArchives[archiveIdx].load(buffer, archiveHeap, fileHeap, 0);
  }
  return &mKartArchives[archiveIdx];
}

void ResourceManager::unmountMulti(s32 archiveIdx) {
  mppSceneArchives[archiveIdx]->unmount();
}

void ResourceManager::unmountMulti(MultiDvdArchive* other) { other->unmount(); }

void ResourceManager::unmountArchive(s32 archiveIdx) {
  mSystemArchives[archiveIdx].unmount();
}

void* ResourceManager::getFile(s32 archiveIdx, const char* filename,
                               size_t* size) {
  return isSceneArchiveLoaded(archiveIdx)
             ? mppSceneArchives[archiveIdx]->getFile(filename, size)
             : nullptr;
}

void* ResourceManager::getCharacterFile(CharacterId characterId, size_t* size) {
  char buffer[128];

  if (!isSceneArchiveLoaded(6)) {
    return nullptr;
  }

  const char* character = getCharacterName(characterId);
  // I can't believe this compiles
  snprintf("%s.brres", sizeof(buffer), character);
  return mppSceneArchives[6]->getFile(buffer, size);
}

void* ResourceManager::getVehicleFile(s32 archiveIdx, VehicleId vehicleId,
                                      size_t* size) {
  char buffer[128];

  if (!isKartArchiveLoaded(archiveIdx)) {
    return nullptr;
  }

  const char* vehicle = getVehicleName(vehicleId);
  // I can't believe this compiles
  snprintf("%s.brres", sizeof(buffer), vehicle);
  return mKartArchives[archiveIdx].getFile(buffer, size);
}

void* ResourceManager::getKartArchiveFile(s32 idx, const char* filename,
                                          size_t* size) {
  return isKartArchiveLoaded(idx)
             ? this->mKartArchives[idx].getFile(filename, size)
             : nullptr;
}

void* ResourceManager::getBackupKartArchiveFile(s32 idx, const char* filename,
                                                size_t* size) {
  return isBackupKartArchiveLoaded(idx)
             ? this->mBackupKartArchives[idx].getFile(filename, size)
             : nullptr;
}

void* ResourceManager::getBspFile(s32 playerIdx, size_t* size) {
  char buffer[32];

  const char* vehicle = getVehicleName(
      (VehicleId)RaceConfig::spInstance->mRaceScenario.mPlayers[playerIdx]
          .mVehicleId);
  snprintf(buffer, sizeof(buffer), "/bsp/%s.bsp", vehicle);

  return (isSceneArchiveLoaded(0)) ? mppSceneArchives[0]->getFile(buffer, size)
                                   : nullptr;
}

void* ResourceManager::getFileCopy(s32 archiveIdx, char* filename,
                                   EGG::Heap* heap, size_t* size, s8 param_5) {
  return !isSystemArchiveLoaded(archiveIdx)
             ? nullptr
             : mSystemArchives[archiveIdx].getFileCopy(filename, heap, size,
                                                       param_5);
}

bool ResourceManager::isSceneArchiveLoaded(s32 idx) volatile {
  return mppSceneArchives[idx]->isLoaded();
}

bool ResourceManager::isKartArchiveLoaded(s32 idx) {
  return mKartArchives[idx].isLoaded();
}

bool ResourceManager::isBackupKartArchiveLoaded(s32 idx) {
  return mBackupKartArchives[idx].isLoaded();
}

bool ResourceManager::isSystemArchiveLoaded(s32 idx) {
  return mSystemArchives[idx].isLoaded();
}

void* ResourceManager::getArchiveStart(ResourceChannelID resId,
                                       u32 archiveIdx) {
  if (!isSceneArchiveLoaded(resId)) {
    return nullptr;
  } else if (archiveIdx < mppSceneArchives[resId]->archiveCount) {
    return mppSceneArchives[resId]->archives[archiveIdx].mArchiveStart;
  }
  return nullptr;
}

bool ResourceManager::setArcResourceLink(s32 multiIdx, u16 archiveIdx,
                                         void* arcResource,
                                         const char* dirname) {
  void* archiveStart;

  if (!mppSceneArchives[multiIdx]->isLoaded()) {
    return false;
  }

  if (archiveIdx < mppSceneArchives[multiIdx]->archiveCount) {
    archiveStart =
        (archiveIdx < mppSceneArchives[multiIdx]->archiveCount)
            ? mppSceneArchives[multiIdx]->archives[archiveIdx].mArchiveStart
            : nullptr;
    ArcResourceLink_set(arcResource, archiveStart, dirname);
    return true;
  }

  return false;
}

u16 ResourceManager::getLoadedArchiveCount(s32 idx) {
  return isSceneArchiveLoaded(idx) ? mppSceneArchives[idx]->archiveCount : 0;
}

u16 ResourceManager::getMenuArchiveCount() {
  return mppSceneArchives[2]->archiveCount;
}

void ResourceManager::attachArcResourceAccessor(void* arcResourceAccessor,
                                                const char* dirname) {
  // look, it's 6am, this horribleness matches perfectly and I'm tired
  // ping me tomorrow to clean this up
  void* archiveStart;

  if (!isSceneArchiveLoaded(2)) {
    archiveStart = nullptr;
  } else if (mppSceneArchives[2]->archiveCount != 0) {
    archiveStart = mppSceneArchives[2]->archives->mArchiveStart;
  } else {
    archiveStart = nullptr;
  }

  if (!archiveStart) {
    return;
  }

  if (!isSceneArchiveLoaded(2)) {
    archiveStart = nullptr;
  } else if (mppSceneArchives[2]->archiveCount != 0) {
    archiveStart = mppSceneArchives[2]->archives->mArchiveStart;
  } else {
    archiveStart = nullptr;
  }

  ArcResourceAccessor_attach(arcResourceAccessor, archiveStart, dirname);
}

void ResourceManager::attatchLayoutDir(void* accessor, const char* dirname,
                                       Whatever2* whatever2, bool param_5) {
  if (!param_5) {
    getGameScene();
  }

  for (u16 i = 0; i < this->getLoadedArchiveCountInverse(RES_CHAN_UI); i++) {
    void* arcResource;

    if (i < whatever2->_08) {
      arcResource = &whatever2->_04[i];
    } else {
      arcResource = nullptr;
    }

    if (setArcResourceLink(RES_CHAN_UI, i, arcResource, dirname)) {
      MultiArcResourceAccessor_attach(accessor, arcResource);
    }
  }
}

// force not inline CourseCache::load
#ifdef __CWCC__
#pragma dont_inline on
#endif
void preloadCourseTask(void* courseId) {
  // programming
  ((ResourceManager*)ResourceManager::spInstance.vol)
      ->mCourseCache.load((CourseId)courseId);
}
#ifdef __CWCC__
#pragma dont_inline off
#endif

void ResourceManager::preloadCourseAsync(CourseId courseId) {
  mpTaskThread->request(preloadCourseTask, (void*)courseId, (void*)0x10000002);
}

const char* getCharacterName(CharacterId charId) {
  return charId >= CHAR_NAMES_SIZE ? nullptr : CHARACTER_NAMES[charId];
}

const char* getVehicleName(VehicleId vehicleId) {
  return vehicleId >= VEHICLE_NAMES_SIZE ? nullptr : VEHICLE_NAMES[vehicleId];
}

CourseCache::CourseCache() {
  mpBuffer = nullptr;
  mpHeap = nullptr;
  mpArchive = new CourseDvdArchive();
}

void CourseCache::init() {
  void* block = new (-32) u8[0x319000];
  mpBuffer = block;
  mpHeap = EGG::ExpHeap::create(block, 0x319000, 1);
}

CourseCache::~CourseCache() {
  mpArchive->clear();
  if (mpHeap) {
    mpHeap->destroy();
    delete[]((u8*)mpBuffer);
  }
}

void CourseCache::load(CourseId courseId) {
  if (!mpHeap)
    return;
  char buffer[128];

  mCourseId = courseId;
  if (mState == 2) {
    mpArchive->clear();
  }
  mState = COURSE_CACHE_STATE_UNK1;

  snprintf(buffer, sizeof(buffer), "Race/Course/%s", COURSE_NAMES[mCourseId]);
  mpArchive->rip(buffer, mpHeap);

  if ((u16)mpArchive->rippedArchiveCount()) {
    mState = COURSE_CACHE_STATE_UNK2;
  } else {
    mpArchive->clear();
    mState = COURSE_CACHE_STATE_UNK0;
  }
}

void CourseCache::loadOther(MultiDvdArchive* other, EGG::Heap* heap) {
  if (mState != 2)
    return;

  other->loadOther(mpArchive, heap);
}

} // namespace System

char* _unk_getNullString() { return ""; }

namespace System {

bool ResourceManager::tryRequestTask(EGG::TaskThread::TFunction fun,
                                     void* arg) {
  bool res = this->requestTask(fun, arg, (void*)0x10000001);
  if (res) {
    process();
  }
  return res;
}

bool ResourceManager::requestTask(EGG::TaskThread::TFunction fun, void* arg,
                                  void* _8) {
  if (mRequestsEnabled) {
    mRequestPending = true;
    return mpTaskThread->request(fun, arg, _8);
  }
  return false;
}

void ResourceManager::flush() {
  mRequestsEnabled = false;
  _process();
  enableRequests();
}

namespace {

void RloadMenuKartModel(MultiDvdArchive* m, CharacterId characterId,
                        BattleTeam battleTeam, EGG::Heap* archiveHeap,
                        EGG::Heap* fileHeap) {
  char buffer[128];

  if (!m->isLoaded()) {
    if (battleTeam == BATTLE_TEAM_NONE) { // not in battle mode
      snprintf(buffer, sizeof(buffer), "Scene/Model/Kart/%s-allkart",
               getCharacterName(characterId));
    } else {
      snprintf(buffer, sizeof(buffer), "Scene/Model/Kart/%s-allkart_BT",
               getCharacterName(characterId));
    }
    m->load(buffer, archiveHeap, fileHeap, 0);
  }
}

void RloadMenuKartModel(MultiDvdArchive* m, MenuCharacterManager* c) {
  RloadMenuKartModel(m, c->mCharacter, c->mTeam, c->mpArchiveHeap,
                     c->mpFileHeap);
}

} // namespace

#pragma warn_ptr_int_conv off
void ResourceManager::doLoadCharacterKartModel(void* idxs) {
  ResourceManager* resMgr = ResourceManager::spInstance.nonvol;
  const u8 idx = (const u8)idxs;
  if (resMgr->mKartArchives[idx].isLoaded()) {
    resMgr->mKartArchives[idx].unmount();
  }
  resMgr->mMenuManagers[idx].mState = MENU_CHARACTER_MANAGER_STATE_UNK2;
  resMgr->mMenuManagers[idx].destroy();

  MultiDvdArchive* archive = &resMgr->mKartArchives[idx];
  RloadMenuKartModel(archive, &resMgr->mMenuManagers[idx]);
  if (!archive->isLoaded()) {
    OSSleepMilliseconds(16);
  }
  if (archive->isLoaded()) {
    resMgr->mMenuManagers[idx].mState = MENU_CHARACTER_MANAGER_STATE_UNK4;
  } else {
    resMgr->mMenuManagers[idx].mState = MENU_CHARACTER_MANAGER_STATE_CLEARED;
  }
}
#pragma warn_ptr_int_conv on

void ResourceManager::doLoadCharacterKartModelPriv(s32 idx) {
  if (mKartArchives[idx].isLoaded()) {
    mKartArchives[idx].unmount();
  }
  mMenuManagers[idx].mState = MENU_CHARACTER_MANAGER_STATE_UNK2;
  mMenuManagers[idx].destroy();

  MultiDvdArchive* archive = &mKartArchives[idx];
  RloadMenuKartModel(archive, mMenuManagers[idx].mCharacter,
                     mMenuManagers[idx].mTeam, mMenuManagers[idx].mpArchiveHeap,
                     mMenuManagers[idx].mpFileHeap);
  if (!archive->isLoaded()) {
    OSSleepMilliseconds(16);
  }
  if (archive->isLoaded()) {
    mMenuManagers[idx].mState = MENU_CHARACTER_MANAGER_STATE_UNK4;
  } else {
    mMenuManagers[idx].mState = MENU_CHARACTER_MANAGER_STATE_CLEARED;
  }
}

bool ResourceManager::loadKartMenuModelAsync(s32 idx, CharacterId characterId,
                                             BattleTeam battleTeam) {
  if (!mMenuManagers[idx].SOME_CHECK()) {
    return false;
  } else {
    mMenuManagers[idx].mCharacter = characterId;
    mMenuManagers[idx].mTeam = battleTeam;
    mMenuManagers[idx].mState = MENU_CHARACTER_MANAGER_STATE_UNK1;
    this->requestTask(ResourceManager::doLoadCharacterKartModel, (void*)idx,
                      (void*)0x10000003);
    return true;
  }
}

static inline EGG::ExpHeap* createExpHeap(u32 size, s32 heapIdx) {
  return EGG::ExpHeap::create(size, getGameScene()->getHeap(heapIdx), 0);
}

static inline void setHeap(EGG::ExpHeap** heapDest, EGG::ExpHeap* heapSrc) {
  if (*heapDest == 0) {
    *heapDest = heapSrc;
  }
}

void ResourceManager::createMenuHeaps(u32 count, s32 heapIdx) {
  mpMenuHeap = createExpHeap(0xc8000, heapIdx);
  for (u8 i = 0; i < 4; i++) {
    if (i < count) {
      EGG::ExpHeap* heap = createExpHeap(0xe1000, heapIdx);
      mMenuManagers[i].setArchiveHeap(heap);
      mMenuManagers[i].setFileHeap(mpMenuHeap);
    } else {
      mMenuManagers[i].setArchiveHeap(nullptr);
      mMenuManagers[i].setFileHeap(nullptr);
    }
  }
}

void ResourceManager::clear() {
  for (u8 i = 0; i < 4; i++) {
    clear(i);
  }

  mpMenuHeap->destroy();
  mpMenuHeap = nullptr;
}

EGG::ExpHeap* ResourceManager::getMenuManagerHeap(int managerIdx) {
  return this->mMenuManagers[managerIdx].mpArchiveHeap;
}

u8* ResourceManager::loadGlobe(EGG::Heap* globeHeap) {
  EGG::LZStreamDecomp lzstream;

  const char* globePath = Resource::GetResourcePath(SYS_RES_GLOBE);
  EGG::Archive* globeArchive = (EGG::Archive*)EGG::Archive::loadFromDisc(
      globePath, globeHeap, 0xffffffe0);
  globeArchive =
      EGG::Archive::mountNoFastGet(globeArchive, globeHeap, 0xffffffe0);

  EGG::Archive::FileInfo globeInfo;
  globeInfo.startOffset = 0;
  globeInfo.length = 0;
  globeArchive->getFile(EarthResourceListing, &globeInfo);
  globePath = Resource::GetResourcePath(SYS_RES_GLOBE);

  return EGG::DvdRipper::loadToMainRAMDecomp(
      globePath, &lzstream, 0, globeHeap, EGG::DvdRipper::ALLOC_DIR_TOP,
      globeInfo.startOffset, globeInfo.length, 0x20000);
}

void ResourceManager::initGlobeHeap(size_t size, EGG::Heap* heap) {
  if (heap == nullptr) {
    GameScene* gameScene = getGameScene();
    heap = gameScene->mDynamicHeaps.mpHeaps[1];
  }
  mpGlobeHeap = EGG::ExpHeap::create(size + 0x2041fU & 0xffffffe0, heap, 0);
}

void ResourceManager::deinitGlobeHeap() {
  flush();
  mpGlobeHeap->destroy();
  bar();
}

void ResourceManager::doLoadGlobe(void* globeBlob) {
  volatile ResourceManager* inst = ResourceManager::spInstance.vol;
  inst->doLoadGlobeImpl((u8**)globeBlob);
}

void ResourceManager::doLoadGlobeImpl(u8** globeBlob) volatile {
  *globeBlob = ResourceManager::loadGlobe(mpGlobeHeap);
  mIsGlobeLoadingBusy = false;
}

bool ResourceManager::loadGlobeAsync(void* arg) {
  return mIsGlobeLoadingBusy ? false
                             : requestGlobeTaskHelper(arg, (void*)0x10000004);
}

void ResourceManager::loadStaffGhostAsync(
    GhostFileGroup::GhostGroupType ghostType, CourseId courseId,
    u8* destBuffer) {
  char filename[128];

  s16 slot = getSlotForCourseId(courseId);
  // TODO: 2->slow staff ghost
  if (ghostType == 2) {
    snprintf(filename, sizeof(filename),
             "/Race/TimeAttack/ghost1/ghost1_comp_%02d.rkg", (s32)slot);
  } else {
    snprintf(filename, sizeof(filename),
             "/Race/TimeAttack/ghost2/ghost2_comp_%02d.rkg", (s32)slot);
  }

  SystemManager::sInstance->ripFromDiscAsync(filename, nullptr, true, nullptr,
                                             destBuffer);
}
} // namespace System
