#include "ResourceManager.hpp"

#include <rvl/os/osThread.h>
#include <game/host_system/SystemManager.hpp>
#include <game/host_system/SystemResources.hpp>
#include <game/system/RaceConfig.hpp>
#include <egg/core/eggStreamDecomp.hpp>
#include <egg/core/eggDvdRipper.hpp>
#include <game/RKScene.hpp>

// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern function references.
// PAL: 0x801aa824
extern UNKNOWN_FUNCTION(OSSuspendThread);
// PAL: 0x8000b26c
extern UNKNOWN_FUNCTION(unk_8000b26c);
// PAL: 0x80008e74
extern UNKNOWN_FUNCTION(unk_80008e74);
// PAL: 0x80242c98
extern UNKNOWN_FUNCTION(isTaskExist__Q23EGG10TaskThreadCFv);
// PAL: 0x80008e20
extern UNKNOWN_FUNCTION(unk_80008e20);
// PAL: 0x801bab2c
extern UNKNOWN_FUNCTION(VISetBlack);
// PAL: 0x80386000
extern UNKNOWN_DATA(sInstance__Q26System13SystemManager);
// PAL: 0x80385fc8
extern UNKNOWN_DATA(lbl_80385fc8);
// PAL: 0x80385fc0
extern UNKNOWN_DATA(lbl_80385fc0);
extern UNKNOWN_DATA(spInstance__Q26System9InitScene);
}

// --- EXTERN DECLARATIONS END ---

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
extern UNKNOWN_FUNCTION(unk_805553b0);
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

} // namespace System

// Symbol: process__Q26System15ResourceManagerFv
// PAL: 0x805400a0..0x805401ec
MARK_BINARY_BLOB(process__Q26System15ResourceManagerFv, 0x805400a0, 0x805401ec);
asm UNKNOWN_FUNCTION(process__Q26System15ResourceManagerFv) {
  // clang-format off
  nofralloc
  /* 805400A0 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 805400A4 7C0802A6 */ mflr        r0
  /* 805400A8 90010024 */ stw         r0, 0x24(r1)
  /* 805400AC BF61000C */ stmw        r27, 0xc(r1)
  /* 805400B0 7C7B1B78 */ mr          r27, r3
  /* 805400B4 3B800000 */ li          r28, 0x0
  /* 805400B8 3FE08038 */ lis         r31, lbl_80385fc0@ha
  /* 805400BC 3FA08038 */ lis         r29, lbl_80385fc8@ha
  /* 805400C0 3FC08038 */ lis         r30, sInstance__Q26System13SystemManager@ha
  /* 805400C4 48000104 */ b           lbl_805401c8
  lbl_805400c8:
  /* 805400C8 807D5FC8 */ lwz         r3, lbl_80385fc8@l(r29)
  /* 805400CC 8063004C */ lwz         r3, 0x4c(r3)
  /* 805400D0 81830004 */ lwz         r12, 4(r3)
  /* 805400D4 818C0014 */ lwz         r12, 0x14(r12)
  /* 805400D8 7D8903A6 */ mtctr       r12
  /* 805400DC 4E800421 */ bctrl
  /* 805400E0 807D5FC8 */ lwz         r3, lbl_80385fc8@l(r29)
  /* 805400E4 8063004C */ lwz         r3, 0x4c(r3)
  /* 805400E8 81830004 */ lwz         r12, 4(r3)
  /* 805400EC 818C0008 */ lwz         r12, 8(r12)
  /* 805400F0 7D8903A6 */ mtctr       r12
  /* 805400F4 4E800421 */ bctrl
  /* 805400F8 807F5FC0 */ lwz         r3, lbl_80385fc0@l(r31)
  /* 805400FC 88030051 */ lbz         r0, 0x51(r3)
  /* 80540100 2C000000 */ cmpwi       r0, 0x0
  /* 80540104 41820030 */ beq-        lbl_80540134
  /* 80540108 2C1C0000 */ cmpwi       r28, 0x0
  /* 8054010C 40820018 */ bne-        lbl_80540124
  /* 80540110 38600000 */ li          r3, 0x0
  /* 80540114 4BC7AA19 */ bl          VISetBlack
  /* 80540118 807B0584 */ lwz         r3, 0x584(r27)
  /* 8054011C 80630008 */ lwz         r3, 8(r3)
  /* 80540120 4BC6A705 */ bl          OSSuspendThread
  lbl_80540124:
  /* 80540124 807F5FC0 */ lwz         r3, lbl_80385fc0@l(r31)
  /* 80540128 3B800001 */ li          r28, 0x1
  /* 8054012C 4BAC8CF5 */ bl          unk_80008e20
  /* 80540130 48000034 */ b           lbl_80540164
  lbl_80540134:
  /* 80540134 2C1C0000 */ cmpwi       r28, 0x0
  /* 80540138 41820010 */ beq-        lbl_80540148
  /* 8054013C 807B0584 */ lwz         r3, 0x584(r27)
  /* 80540140 80630008 */ lwz         r3, 8(r3)
  /* 80540144 4BC6A449 */ bl          OSResumeThread
  lbl_80540148:
  /* 80540148 807D5FC8 */ lwz         r3, lbl_80385fc8@l(r29)
  /* 8054014C 3B800000 */ li          r28, 0x0
  /* 80540150 80630054 */ lwz         r3, 0x54(r3)
  /* 80540154 81830000 */ lwz         r12, 0(r3)
  /* 80540158 818C0024 */ lwz         r12, 0x24(r12)
  /* 8054015C 7D8903A6 */ mtctr       r12
  /* 80540160 4E800421 */ bctrl
  lbl_80540164:
  /* 80540164 807E6000 */ lwz         r3, sInstance__Q26System13SystemManager@l(r30)
  /* 80540168 4BACB105 */ bl          unk_8000b26c
  /* 8054016C 807D5FC8 */ lwz         r3, lbl_80385fc8@l(r29)
  /* 80540170 8063004C */ lwz         r3, 0x4c(r3)
  /* 80540174 81830004 */ lwz         r12, 4(r3)
  /* 80540178 818C000C */ lwz         r12, 0xc(r12)
  /* 8054017C 7D8903A6 */ mtctr       r12
  /* 80540180 4E800421 */ bctrl
  /* 80540184 2C1C0000 */ cmpwi       r28, 0x0
  /* 80540188 41820010 */ beq-        lbl_80540198
  /* 8054018C 807F5FC0 */ lwz         r3, lbl_80385fc0@l(r31)
  /* 80540190 4BAC8CE5 */ bl          unk_80008e74
  /* 80540194 4800001C */ b           lbl_805401b0
  lbl_80540198:
  /* 80540198 807D5FC8 */ lwz         r3, lbl_80385fc8@l(r29)
  /* 8054019C 80630054 */ lwz         r3, 0x54(r3)
  /* 805401A0 81830000 */ lwz         r12, 0(r3)
  /* 805401A4 818C0028 */ lwz         r12, 0x28(r12)
  /* 805401A8 7D8903A6 */ mtctr       r12
  /* 805401AC 4E800421 */ bctrl
  lbl_805401b0:
  /* 805401B0 807D5FC8 */ lwz         r3, lbl_80385fc8@l(r29)
  /* 805401B4 8063004C */ lwz         r3, 0x4c(r3)
  /* 805401B8 81830004 */ lwz         r12, 4(r3)
  /* 805401BC 818C0010 */ lwz         r12, 0x10(r12)
  /* 805401C0 7D8903A6 */ mtctr       r12
  /* 805401C4 4E800421 */ bctrl
  lbl_805401c8:
  /* 805401C8 807B0584 */ lwz         r3, 0x584(r27)
  /* 805401CC 4BD02ACD */ bl          isTaskExist__Q23EGG10TaskThreadCFv
  /* 805401D0 2C030000 */ cmpwi       r3, 0x0
  /* 805401D4 4082FEF4 */ bne+        lbl_805400c8
  /* 805401D8 BB61000C */ lmw         r27, 0xc(r1)
  /* 805401DC 80010024 */ lwz         r0, 0x24(r1)
  /* 805401E0 7C0803A6 */ mtlr        r0
  /* 805401E4 38210020 */ addi        r1, r1, 0x20
  /* 805401E8 4E800020 */ blr
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

} // namespace System

// Symbol: flush__Q26System15ResourceManagerFv
// PAL: 0x80541ce0..0x80541e44
MARK_BINARY_BLOB(flush__Q26System15ResourceManagerFv, 0x80541ce0, 0x80541e44);
asm UNKNOWN_FUNCTION(flush__Q26System15ResourceManagerFv) {
  // clang-format off
  nofralloc
  /* 80541CE0 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 80541CE4 7C0802A6 */ mflr        r0
  /* 80541CE8 90010024 */ stw         r0, 0x24(r1)
  /* 80541CEC 38000000 */ li          r0, 0x0
  /* 80541CF0 BF61000C */ stmw        r27, 0xc(r1)
  /* 80541CF4 7C7B1B78 */ mr          r27, r3
  /* 80541CF8 3B800000 */ li          r28, 0x0
  /* 80541CFC 3FE08038 */ lis         r31, lbl_80385fc0@ha
  /* 80541D00 3FA08038 */ lis         r29, lbl_80385fc8@ha
  /* 80541D04 3FC08038 */ lis         r30, sInstance__Q26System13SystemManager@ha
  /* 80541D08 98030619 */ stb         r0, 0x619(r3)
  /* 80541D0C 48000104 */ b           lbl_80541e10
  lbl_80541d10:
  /* 80541D10 807D5FC8 */ lwz         r3, lbl_80385fc8@l(r29)
  /* 80541D14 8063004C */ lwz         r3, 0x4c(r3)
  /* 80541D18 81830004 */ lwz         r12, 4(r3)
  /* 80541D1C 818C0014 */ lwz         r12, 0x14(r12)
  /* 80541D20 7D8903A6 */ mtctr       r12
  /* 80541D24 4E800421 */ bctrl
  /* 80541D28 807D5FC8 */ lwz         r3, lbl_80385fc8@l(r29)
  /* 80541D2C 8063004C */ lwz         r3, 0x4c(r3)
  /* 80541D30 81830004 */ lwz         r12, 4(r3)
  /* 80541D34 818C0008 */ lwz         r12, 8(r12)
  /* 80541D38 7D8903A6 */ mtctr       r12
  /* 80541D3C 4E800421 */ bctrl
  /* 80541D40 807F5FC0 */ lwz         r3, lbl_80385fc0@l(r31)
  /* 80541D44 88030051 */ lbz         r0, 0x51(r3)
  /* 80541D48 2C000000 */ cmpwi       r0, 0x0
  /* 80541D4C 41820030 */ beq-        lbl_80541d7c
  /* 80541D50 2C1C0000 */ cmpwi       r28, 0x0
  /* 80541D54 40820018 */ bne-        lbl_80541d6c
  /* 80541D58 38600000 */ li          r3, 0x0
  /* 80541D5C 4BC78DD1 */ bl          VISetBlack
  /* 80541D60 807B0584 */ lwz         r3, 0x584(r27)
  /* 80541D64 80630008 */ lwz         r3, 8(r3)
  /* 80541D68 4BC68ABD */ bl          OSSuspendThread
  lbl_80541d6c:
  /* 80541D6C 807F5FC0 */ lwz         r3, lbl_80385fc0@l(r31)
  /* 80541D70 3B800001 */ li          r28, 0x1
  /* 80541D74 4BAC70AD */ bl          unk_80008e20
  /* 80541D78 48000034 */ b           lbl_80541dac
  lbl_80541d7c:
  /* 80541D7C 2C1C0000 */ cmpwi       r28, 0x0
  /* 80541D80 41820010 */ beq-        lbl_80541d90
  /* 80541D84 807B0584 */ lwz         r3, 0x584(r27)
  /* 80541D88 80630008 */ lwz         r3, 8(r3)
  /* 80541D8C 4BC68801 */ bl          OSResumeThread
  lbl_80541d90:
  /* 80541D90 807D5FC8 */ lwz         r3, lbl_80385fc8@l(r29)
  /* 80541D94 3B800000 */ li          r28, 0x0
  /* 80541D98 80630054 */ lwz         r3, 0x54(r3)
  /* 80541D9C 81830000 */ lwz         r12, 0(r3)
  /* 80541DA0 818C0024 */ lwz         r12, 0x24(r12)
  /* 80541DA4 7D8903A6 */ mtctr       r12
  /* 80541DA8 4E800421 */ bctrl
  lbl_80541dac:
  /* 80541DAC 807E6000 */ lwz         r3, sInstance__Q26System13SystemManager@l(r30)
  /* 80541DB0 4BAC94BD */ bl          unk_8000b26c
  /* 80541DB4 807D5FC8 */ lwz         r3, lbl_80385fc8@l(r29)
  /* 80541DB8 8063004C */ lwz         r3, 0x4c(r3)
  /* 80541DBC 81830004 */ lwz         r12, 4(r3)
  /* 80541DC0 818C000C */ lwz         r12, 0xc(r12)
  /* 80541DC4 7D8903A6 */ mtctr       r12
  /* 80541DC8 4E800421 */ bctrl
  /* 80541DCC 2C1C0000 */ cmpwi       r28, 0x0
  /* 80541DD0 41820010 */ beq-        lbl_80541de0
  /* 80541DD4 807F5FC0 */ lwz         r3, lbl_80385fc0@l(r31)
  /* 80541DD8 4BAC709D */ bl          unk_80008e74
  /* 80541DDC 4800001C */ b           lbl_80541df8
  lbl_80541de0:
  /* 80541DE0 807D5FC8 */ lwz         r3, lbl_80385fc8@l(r29)
  /* 80541DE4 80630054 */ lwz         r3, 0x54(r3)
  /* 80541DE8 81830000 */ lwz         r12, 0(r3)
  /* 80541DEC 818C0028 */ lwz         r12, 0x28(r12)
  /* 80541DF0 7D8903A6 */ mtctr       r12
  /* 80541DF4 4E800421 */ bctrl
  lbl_80541df8:
  /* 80541DF8 807D5FC8 */ lwz         r3, lbl_80385fc8@l(r29)
  /* 80541DFC 8063004C */ lwz         r3, 0x4c(r3)
  /* 80541E00 81830004 */ lwz         r12, 4(r3)
  /* 80541E04 818C0010 */ lwz         r12, 0x10(r12)
  /* 80541E08 7D8903A6 */ mtctr       r12
  /* 80541E0C 4E800421 */ bctrl
  lbl_80541e10:
  /* 80541E10 807B0584 */ lwz         r3, 0x584(r27)
  /* 80541E14 4BD00E85 */ bl          isTaskExist__Q23EGG10TaskThreadCFv
  /* 80541E18 2C030000 */ cmpwi       r3, 0x0
  /* 80541E1C 4082FEF4 */ bne+        lbl_80541d10
  /* 80541E20 38000001 */ li          r0, 0x1
  /* 80541E24 981B0619 */ stb         r0, 0x619(r27)
  /* 80541E28 38000000 */ li          r0, 0x0
  /* 80541E2C 981B0618 */ stb         r0, 0x618(r27)
  /* 80541E30 BB61000C */ lmw         r27, 0xc(r1)
  /* 80541E34 80010024 */ lwz         r0, 0x24(r1)
  /* 80541E38 7C0803A6 */ mtlr        r0
  /* 80541E3C 38210020 */ addi        r1, r1, 0x20
  /* 80541E40 4E800020 */ blr
  // clang-format on
}

namespace System {

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
} // namespace System

namespace System {

void ResourceManager::clear() {
  for (u8 i = 0; i < 4; i++) {
    clear(i);
  }

  mpMenuHeap->destroy();
  mpMenuHeap = nullptr;
}

} // namespace System

// Symbol: unk_8054247c
// PAL: 0x8054247c..0x8054248c
MARK_BINARY_BLOB(unk_8054247c, 0x8054247c, 0x8054248c);
asm UNKNOWN_FUNCTION(unk_8054247c) {
  // clang-format off
  nofralloc
  /* 8054247C 1C040018 */ mulli       r0, r4, 0x18
  /* 80542480 7C630214 */ add         r3, r3, r0
  /* 80542484 806305B0 */ lwz         r3, 0x5b0(r3)
  /* 80542488 4E800020 */ blr
  // clang-format on
}

namespace System {
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

// Symbol: unk_80542868
// PAL: 0x80542868..0x80542878
MARK_BINARY_BLOB(unk_80542868, 0x80542868, 0x80542878);
asm UNKNOWN_FUNCTION(unk_80542868) {
  // clang-format off
  nofralloc
  /* 80542868 90830004 */ stw         r4, 4(r3)
  /* 8054286C 90A30008 */ stw         r5, 8(r3)
  /* 80542870 38600001 */ li          r3, 0x1
  /* 80542874 4E800020 */ blr
  // clang-format on
}
