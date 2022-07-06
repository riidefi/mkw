#pragma once

#include <rk_types.h>

#include <decomp.h>

#include <egg/core/eggDisposer.hpp>
#include <egg/core/eggExpHeap.hpp>
#include <game/system/DvdArchive.hpp>
#include <game/system/LocalizedArchive.hpp>
#include <game/system/MultiDvdArchive.hpp>
#include <game/system/RaceConfig.hpp>
#include <game/system/GhostFile.hpp>
#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8053fc4c..0x8053fc9c
UNKNOWN_FUNCTION(ResourceManager_createInstance);
// PAL: 0x8053fc9c..0x8053fcec
UNKNOWN_FUNCTION(ResourceManager_destroyInstance);
// PAL: 0x8053fcec..0x8053fe68
UNKNOWN_FUNCTION(__ct__Q26System15ResourceManagerFv);
// PAL: 0x8053fe68..0x8053fe94
UNKNOWN_FUNCTION(__ct__Q26System20MenuCharacterManagerFv);
// PAL: 0x8053fe94..0x8053fed4
UNKNOWN_FUNCTION(unk_8053fe94);
// PAL: 0x8053fed4..0x8053ff14
UNKNOWN_FUNCTION(unk_8053fed4);
// PAL: 0x8053ff14..0x8053ff1c
UNKNOWN_FUNCTION(unk_8053ff14);
// PAL: 0x8053ff1c..0x80540038
UNKNOWN_FUNCTION(ResourceManager_destroy);
// PAL: 0x80540038..0x805400a0
UNKNOWN_FUNCTION(unk_80540038);
// PAL: 0x805400a0..0x805401ec
UNKNOWN_FUNCTION(process__Q26System15ResourceManagerFv);
// PAL: 0x805401ec..0x805401fc
UNKNOWN_FUNCTION(unk_805401ec);
// PAL: 0x805401fc..0x8054020c
UNKNOWN_FUNCTION(unk_805401fc);
// PAL: 0x8054020c..0x805402c0
UNKNOWN_FUNCTION(unk_8054020c);
// PAL: 0x805402c0..0x80540394
UNKNOWN_FUNCTION(unk_805402c0);
// PAL: 0x80540394..0x80540450
UNKNOWN_FUNCTION(unk_80540394);
// PAL: 0x80540450..0x80540558
UNKNOWN_FUNCTION(ResourceManager_load);
// PAL: 0x80540558..0x80540680
UNKNOWN_FUNCTION(unk_80540558);
// PAL: 0x80540680..0x80540760
UNKNOWN_FUNCTION(ResourceManager_loadUI);
// PAL: 0x80540760..0x80540918
UNKNOWN_FUNCTION(ResourceManager_loadCourse);
// PAL: 0x80540cfc..0x80540e3c
UNKNOWN_FUNCTION(unk_80540cfc);
// PAL: 0x80540e3c..0x80540f90
UNKNOWN_FUNCTION(unk_80540e3c);
// PAL: 0x80540f90..0x805410e4
UNKNOWN_FUNCTION(unk_80540f90);
// PAL: 0x805410e4..0x805411d4
UNKNOWN_FUNCTION(unk_805410e4);
// PAL: 0x805411d4..0x805411e4
UNKNOWN_FUNCTION(unk_805411d4);
// PAL: 0x805411e4..0x805411ec
UNKNOWN_FUNCTION(unk_805411e4);
// PAL: 0x805411ec..0x805411fc
UNKNOWN_FUNCTION(unk_805411ec);
// PAL: 0x805411fc..0x80541278
UNKNOWN_FUNCTION(ResourceManager_getFile);
// PAL: 0x80541278..0x80541320
UNKNOWN_FUNCTION(unk_80541278);
// PAL: 0x80541320..0x805413c8
UNKNOWN_FUNCTION(unk_80541320);
// PAL: 0x805413c8..0x80541438
UNKNOWN_FUNCTION(unk_805413c8);
// PAL: 0x80541438..0x805414a8
UNKNOWN_FUNCTION(unk_80541438);
// PAL: 0x805414a8..0x8054155c
UNKNOWN_FUNCTION(ResourceManager_loadBSP);
// PAL: 0x8054155c..0x805415b0
UNKNOWN_FUNCTION(unk_8054155c);
// PAL: 0x805415b0..0x805415b4
UNKNOWN_FUNCTION(unk_805415b0);
// PAL: 0x805415b4..0x805415c4
UNKNOWN_FUNCTION(unk_805415b4);
// PAL: 0x805415c4..0x805415d4
UNKNOWN_FUNCTION(unk_805415c4);
// PAL: 0x805415d4..0x805415e4
UNKNOWN_FUNCTION(unk_805415d4);
// PAL: 0x805415e4..0x80541614
UNKNOWN_FUNCTION(unk_805415e4);
// PAL: 0x8054169c..0x80541738
UNKNOWN_FUNCTION(unk_8054169c);
// PAL: 0x80541738..0x80541794
UNKNOWN_FUNCTION(unk_80541738);
// PAL: 0x80541794..0x805417a4
UNKNOWN_FUNCTION(ResourceManager_getMenuArchiveCount);
// PAL: 0x805417a4..0x80541878
UNKNOWN_FUNCTION(unk_805417a4);
// PAL: 0x80541878..0x80541998
UNKNOWN_FUNCTION(ResourceManager_attachLayoutDir);
// PAL: 0x80541998..0x805419ac
UNKNOWN_FUNCTION(ResourceManager_preloadCourseTask);
// PAL: 0x805419ac..0x805419c8
UNKNOWN_FUNCTION(ResourceManager_preloadCourseAsync);
// PAL: 0x805419c8..0x805419ec
UNKNOWN_FUNCTION(unk_805419c8);
// PAL: 0x805419ec..0x80541a10
UNKNOWN_FUNCTION(unk_805419ec);
// PAL: 0x80541a10..0x80541a70
UNKNOWN_FUNCTION(unk_80541a10);
// PAL: 0x80541a70..0x80541ac4
UNKNOWN_FUNCTION(unk_80541a70);
// PAL: 0x80541ac4..0x80541b58
UNKNOWN_FUNCTION(unk_80541ac4);
// PAL: 0x80541b58..0x80541c18
UNKNOWN_FUNCTION(load__Q26System11CourseCacheFl);
// PAL: 0x80541c18..0x80541c38
UNKNOWN_FUNCTION(unk_80541c18);
// PAL: 0x80541c38..0x80541c48
UNKNOWN_FUNCTION(unk_80541c38);
// PAL: 0x80541c48..0x80541cbc
UNKNOWN_FUNCTION(unk_80541c48);
// PAL: 0x80541cbc..0x80541ce0
UNKNOWN_FUNCTION(unk_80541cbc);
// PAL: 0x80541ce0..0x80541e44
// UNKNOWN_FUNCTION(flush__Q26System15ResourceManagerFv);
// PAL: 0x80541e44..0x80542030
UNKNOWN_FUNCTION(unk_80541e44);
// PAL: 0x80542030..0x80542210
UNKNOWN_FUNCTION(unk_80542030);
// PAL: 0x80542210..0x805422cc
UNKNOWN_FUNCTION(unk_80542210);
// PAL: 0x805422cc..0x805423bc
UNKNOWN_FUNCTION(unk_805422cc);
// PAL: 0x805423bc..0x8054247c
UNKNOWN_FUNCTION(unk_805423bc);
// PAL: 0x8054247c..0x8054248c
UNKNOWN_FUNCTION(unk_8054247c);
// PAL: 0x8054248c..0x80542524
UNKNOWN_FUNCTION(unk_8054248c);
// PAL: 0x80542524..0x80542584
UNKNOWN_FUNCTION(unk_80542524);
// PAL: 0x80542584..0x805425d0
UNKNOWN_FUNCTION(unk_80542584);
// PAL: 0x805425d0..0x80542694
UNKNOWN_FUNCTION(unk_805425d0);
// PAL: 0x80542694..0x80542754
UNKNOWN_FUNCTION(unk_80542694);
// PAL: 0x80542754..0x805427bc
UNKNOWN_FUNCTION(unk_80542754);
// PAL: 0x805427bc..0x80542868
UNKNOWN_FUNCTION(SaveManager_loadStaffGhostAsync);
// PAL: 0x80542868..0x80542878
UNKNOWN_FUNCTION(unk_80542868);
UNKNOWN_FUNCTION(flush__Q26System15ResourceManagerFv);
#ifdef __cplusplus
}
#endif

namespace System {

struct JobContext {
  MultiDvdArchive* multiArchive;
  DvdArchive* archive;
  unk _08;
  char filename[64];
  EGG::Heap* archiveHeap;
  EGG::Heap* fileHeap;
};

// Enums that represent indices in vehicle name specifiers arrays.
typedef enum {
  // TODO: Fill
  MARIO = 0
} CharacterId;

typedef enum {
  // TODO: Fill
} VehicleId;

// name of battle mode team
typedef enum {
  BATTLE_TEAM_RED = 0,
  BATTLE_TEAM_BLUE = 1,
  BATTLE_TEAM_NONE = 2 // not in battle mode
} BattleTeam;

// single player/number of multiplayer
typedef enum {
  PLAYER_MODE_FOUR = 0,
  PLAYER_MODE_TWO = 1,
  PLAYER_MODE_SINGLE = 2
} PlayMode;

typedef enum {
  // TODO: Fill
} CourseId;

// begrudging riidefi magic
struct S {
  virtual ~S() = 0;
};
inline S::~S() {}
struct T {
public:
  T() {
    archiveHeap = 0;
    fileHeap = 0;
    _unk = 0;
  }
  EGG::ExpHeap* archiveHeap;
  EGG::ExpHeap* fileHeap;
  s32 _unk;
  inline bool SOME_CHECK() const {
    return archiveHeap && ((_unk <= 4u && (((1 << _unk) & 0x15U) != 0)));
  }
  inline void destroy() {
    if (SOME_CHECK()) {
      archiveHeap->freeAll();
      fileHeap->freeAll();
    }
    _unk = 3;
  }
};

class MenuCharacterManager : S, public T {
  friend class ResourceManager;

public:
  MenuCharacterManager() {
    mCharacter = MARIO;
    mModelType = BATTLE_TEAM_NONE;
  }
  virtual ~MenuCharacterManager() {}
  CharacterId mCharacter;
  BattleTeam mModelType;
};

class CourseCache : EGG::Disposer {
public:
  CourseCache();
  void init();
  virtual ~CourseCache();
  void load(CourseId courseId);
  void loadOther(MultiDvdArchive* other, EGG::Heap* heap);

  // private: // idk if rii prefers to befriend every class over public-ing
  // everything
  void* mBuffer;
  EGG::ExpHeap* mHeap;
  s32 mCourseId;
  s32 mState;
  MultiDvdArchive* mArchive;
};

void preloadCourseTask(void* courseId);
const char* getCharacterName(CharacterId charId);
const char* getVehicleName(VehicleId vehicleId);

// unknown structs
struct Whatever {
  u32 _00;
  u8 _04[0xa4 - 0x04];
};
struct Whatever2 {
  u8 _00[0x4 - 0x0];
  Whatever* _04;
  u16 _08; /* ... */
};

class ResourceManager {
  virtual ~ResourceManager();

public:
  static volatile ResourceManager* createInstance();
  static void destroyInstance();

  static volatile ResourceManager* spInstance;
  static ResourceManager* spInstance_REAL;

  ResourceManager();

  MultiDvdArchive** multiArchives1;
  MultiDvdArchive multiArchives2[12];
  MultiDvdArchive multiArchives3[12];
  DvdArchive dvdArchives[4];
  JobContext jobContexts[7];
  EGG::TaskThread* taskThread;
  CourseCache courseCache;
  MenuCharacterManager menuManagers[4];
  bool isGlobeLoadingBusy;
  bool _60d; // these variables don't have names yet, but are used
  EGG::ExpHeap* _610;
  EGG::Heap* globeHeap;
  bool requestPending;
  bool requestsEnabled;

  void foo() volatile {
    requestPending = false;
    requestsEnabled = true;
  }
  void bar() volatile {
    globeHeap = nullptr;
    isGlobeLoadingBusy = false;
  }

  MultiDvdArchive* load(ResourceChannelID channelId, EGG::Heap* archiveHeap,
                        const char* filename);
  DvdArchive* loadSystemResource(s32 idx, EGG::Heap* archiveHeap);
  MultiDvdArchive* loadUI(const char* filename, EGG::Heap* archiveHeap);
  MultiDvdArchive* loadCourse(CourseId courseId, EGG::Heap* param_3,
                              bool splitScreen);
  MultiDvdArchive* loadMission(CourseId courseId, s32 missionNum,
                               EGG::Heap* param_3, bool splitScreen);
  MultiDvdArchive* loadCompetition(CourseId courseId, void* fileStart,
                                   u32 fileSize, EGG::Heap* heap, u8 unk6);
  MultiDvdArchive* loadKartFromArchive(MultiDvdArchive* archive, u32 unu,
                                       VehicleId vehicleId,
                                       CharacterId characterId,
                                       BattleTeam battleTeam, PlayMode playMode,
                                       EGG::Heap* archiveHeap,
                                       EGG::Heap* fileHeap);
  MultiDvdArchive* loadKartFromArchive2(s32 archiveIdx, VehicleId vehicleId,
                                        CharacterId characterId,
                                        BattleTeam battleTeamId,
                                        PlayMode playMode,
                                        EGG::Heap* archiveHeap,
                                        EGG::Heap* fileHeap);
  MultiDvdArchive* loadKartFromArchive3(s32 archiveIdx, VehicleId vehicleId,
                                        CharacterId characterId,
                                        BattleTeam battleTeamId,
                                        PlayMode playMode,
                                        EGG::Heap* archiveHeap,
                                        EGG::Heap* fileHeap);
  MultiDvdArchive* loadMenuKartModel(s32 archiveIdx, CharacterId characterId,
                                     BattleTeam battleTeam,
                                     EGG::Heap* archiveHeap,
                                     EGG::Heap* fileHeap);
  void unmountMulti(s32 archiveIdx);
  void unmountMulti(MultiDvdArchive* other);
  void unmountArchive(s32 archiveIdx);
  void* getFile(s32 archiveIdx, const char* filename, size_t* size);
  void* getCharacterFile(CharacterId characterId, size_t* size);
  void* getVehicleFile(s32 archiveIdx, VehicleId vehicleId, size_t* size);
  // TODO: Better name
  void* getMultiFile2(s32 idx, const char* filename, size_t* size);
  void* getMultiFile3(s32 idx, const char* filename, size_t* size);
  void* getBspFile(s32 playerIdx, size_t* size);
  void* getFileCopy(s32 archiveIdx, char* filename, EGG::Heap* heap,
                    size_t* size, s8 param_5);
  // TODO: Better names
  bool isMultiArchive1Loaded(s32 idx) volatile;
  bool isMultiArchive2Loaded(s32 idx);
  bool isMultiArchive3Loaded(s32 idx);
  bool isDvdArchiveLoaded(s32 idx);
  bool setArcResourceLink(s32 multiIdx, u16 archiveIdx, void* arcResource,
                          const char* dirname);
  u16 getLoadedArchiveCount(s32 idx);
  // I need this terribleness to match attachArcResourceAccessor
  inline u16 getLoadedArchiveCountInverse(u32 idx) volatile {
    return !isMultiArchive1Loaded(idx)
               ? 0
               : this->multiArchives1[idx]->archiveCount;
  }
  u16 getMenuArchiveCount();
  bool tryRequestTask(EGG::TaskThread::TFunction mainFunction, void* arg);
  bool requestTask(EGG::TaskThread::TFunction mainFunction, void* arg,
                   void* _8);

  void attatchLayoutDir(void* accessor, const char* dirname, Whatever2* param_4,
                        bool param_5);
  void attachArcResourceAccessor(void* arcResourceAccessor,
                                 const char* dirname);
  void preloadCourseAsync(CourseId courseId);
  void initGlobeHeap(size_t size, EGG::Heap* heap);
  void flush() volatile;
  void deinitGlobeHeap() volatile;
  static void doLoadCharacterKartModel(s32 idxs);
  static void doLoadGlobe(void* glodeBlob);
  void doLoadGlobeImpl(u8** glodeBlob) volatile;
  // for matching purposes
  inline bool requestGlobeTaskHelper(void* arg, void* arg2) volatile {
    this->isGlobeLoadingBusy = true;
    if (this->requestsEnabled) {
      this->requestPending = true;
      this->taskThread->request(ResourceManager::doLoadGlobe, arg, arg2);
    }
    return true;
  }
  static u8* FUN_8054248c(EGG::Heap* globeHeap);
  bool loadGlobeAsync(void* arg);
  void clear();
  void process();
  static void doLoadTask(void* jobContext);
  void requestLoad(s32 idx, MultiDvdArchive* m, const char* p,
                   EGG::Heap* archiveHeap);
  void requestLoad(s32 idx, DvdArchive* archive, const char* filename, u32 unk,
                   EGG::Heap* archiveHeap);
  void requestLoad(s32 idx, MultiDvdArchive* archive, const char* filename,
                   EGG::Heap* archiveHeap, EGG::Heap* fileHeap);
  void* getArchiveStart(ResourceChannelID resId, u32 archiveIdx);
  static void loadStaffGhostAsync(GhostFileGroup::GhostGroupType ghostType,
                                  CourseId courseId, u8* destBuffer);

  // TODO: check if actually inline
  inline void requestLoadFile(s32 idx, MultiDvdArchive* m, const char* p,
                              EGG::Heap* archiveHeap, EGG::Heap* fileHeap) {
    this->jobContexts[idx].multiArchive = m;
    strncpy(this->jobContexts[idx].filename, p,
            sizeof(this->jobContexts[idx].filename));
    this->jobContexts[idx].archiveHeap = archiveHeap;
    this->jobContexts[idx].fileHeap = fileHeap;

    this->taskThread->request(ResourceManager::doLoadTask, (void*)idx, 0);
    this->process();

    if (!m->isLoaded()) {
      OSSleepMilliseconds(16);
    }
  }
  inline void requestLoadFile(s32 idx, DvdArchive* archive,
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
  inline void clear(s32 i) {
    MultiDvdArchive* archive;
    EGG::ExpHeap* heap;

    heap = menuManagers[i].archiveHeap;
    archive = &multiArchives2[i];

    if (archive->isLoaded()) {
      archive->unmount();
    }
    if (heap) {
      heap->destroy();
    }

    if (menuManagers[i]._unk != 3) {
      menuManagers[i].archiveHeap = 0;
      menuManagers[i].fileHeap = 0;
      menuManagers[i]._unk = 0;
    }
  }
};

} // namespace System
