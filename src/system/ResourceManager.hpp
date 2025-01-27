#pragma once

#include <rk_types.h>

#include <decomp.h>

#include <egg/core/eggDisposer.hpp>
#include <egg/core/eggExpHeap.hpp>
#include <system/DvdArchive.hpp>
#include <system/LocalizedArchive.hpp>
#include <system/MultiDvdArchive.hpp>
#include <system/GhostFile.hpp>

namespace System {

struct JobContext {
  MultiDvdArchive* mpMultiArchive;
  DvdArchive* mpArchive;
  unk _08;
  char mFilename[64];
  EGG::Heap* mpArchiveHeap;
  EGG::Heap* mpFileHeap;
};

// Enums that represent indices in vehicle name specifiers arrays.
typedef enum {
  MARIO = 0x0,
  BABY_PEACH = 0x1,
  WALUIGI = 0x2,
  BOWSER = 0x3,
  BABY_DAISY = 0x4,
  DRY_BONES = 0x5,
  BABY_MARIO = 0x6,
  LUIGI = 0x7,
  TOAD = 0x8,
  DONKEY_KONG = 0x9,
  YOSHI = 0xA,
  WARIO = 0xB,
  BABY_LUIGI = 0xC,
  TOADETTE = 0xD,
  KOOPA_TROOPA = 0xE,
  DAISY = 0xF,
  PEACH = 0x10,
  BIRDO = 0x11,
  DIDDY_KONG = 0x12,
  KING_BOO = 0x13,
  BOWSER_JR = 0x14,
  DRY_BOWSER = 0x15,
  FUNKY_KONG = 0x16,
  ROSALINA = 0x17,
  MII_S_A_MALE = 0x18,
  MII_S_A_FEMALE = 0x19,
  MII_S_B_MALE = 0x1A,
  MII_S_B_FEMALE = 0x1B,
  MII_S_C_MALE = 0x1C,
  MII_S_C_FEMALE = 0x1D,
  MII_M_A_MALE = 0x1E,
  MII_M_A_FEMALE = 0x1F,
  MII_M_B_MALE = 0x20,
  MII_M_B_FEMALE = 0x21,
  MII_M_C_MALE = 0x22,
  MII_M_C_FEMALE = 0x23,
  MII_L_A_MALE = 0x24,
  MII_L_A_FEMALE = 0x25,
  MII_L_B_MALE = 0x26,
  MII_L_B_FEMALE = 0x27,
  MII_L_C_MALE = 0x28,
  MII_L_C_FEMALE = 0x29,
  MII_M = 0x2A,
  MII_S = 0x2B,
  MII_L = 0x2C,
  PEACH_BIKER = 0x2D,
  DAISY_BIKER = 0x2E,
  ROSALINA_BIKER = 0x2F
} CharacterId;

typedef enum {
  STANDARD_KART_S = 0x0,
  STANDARD_KART_M = 0x1,
  STANDARD_KART_L = 0x2,
  BABY_BOOSTER = 0x3,
  CLASSIC_DRAGSTER = 0x4,
  OFFROADER = 0x5,
  MINI_BEAST = 0x6,
  WILD_WING = 0x7,
  FLAME_FLYER = 0x8,
  CHEEP_CHARGER = 0x9,
  SUPER_BLOOPER = 0xA,
  PIRANHA_PROWLER = 0xB,
  RALLY_ROMPER = 0xC,
  ROYAL_RACER = 0xD,
  JETSETTER = 0xE,
  BLUE_FALCON = 0xF,
  SPRINTER = 0x10,
  HONEYCOUPE = 0x11,
  STANDARD_BIKE_S = 0x12,
  STANDARD_BIKE_M = 0x13,
  STANDARD_BIKE_L = 0x14,
  BULLET_BIKE = 0x15,
  MACH_BIKE = 0x16,
  BOWSER_BIKE = 0x17,
  BIT_BIKE = 0x18,
  BON_BON = 0x19,
  WARIO_BIKE = 0x1A,
  QUACKER = 0x1B,
  RAPIDE = 0x1C,
  SHOOTING_STAR = 0x1D,
  MAGIKRUISER = 0x1E,
  NITROCYCLE = 0x1F,
  SPEAR = 0x20,
  JET_BUBBLE = 0x21,
  DOLPHIN_DASHER = 0x22,
  PHANTOM = 0x23
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
  // Race courses

  // Nitro tracks
  MARIO_CIRCUIT = 0x0,
  MOO_MOO_MEADOWS = 0x1,
  MUSHROOM_GORGE = 0x2,
  GRUMBLE_VOLCANO = 0x3,
  TOADS_FACTORY = 0x4,
  COCONUT_MALL = 0x5,
  DK_SUMMIT = 0x6, // "snowboard cross" enjoyers punching air
  WARIOS_GOLD_MINE = 0x7,
  LUIGI_CIRCUIT = 0x8,
  DAISY_CIRCUIT = 0x9,
  MOONVIEW_HIGHWAY = 0xA,
  MAPLE_TREEWAY = 0xB,
  BOWSERS_CASTLE = 0xC,
  RAINBOW_ROAD = 0xD,
  DRY_DRY_RUINS = 0xE,
  KOOPA_CAPE = 0xF,

  // Retro tracks
  GCN_PEACH_BEACH = 0x10,
  GCN_MARIO_CIRCUIT = 0x11,
  GCN_WALUIGI_STADIUM = 0x12,
  GCN_DK_MOUNTAIN = 0x13,
  DS_YOSHI_FALLS = 0x14,
  DS_DESERT_HILLS = 0x15,
  DS_PEACH_GARDENS = 0x16,
  DS_DELFINO_SQUARE = 0x17,
  SNES_MARIO_CIRCUIT_3 = 0x18,
  SNES_GHOST_VALLEY_2 = 0x19,
  N64_MARIO_RACEWAY = 0x1A,
  N64_SHERBET_LAND = 0x1B,
  N64_BOWSERS_CASTLE = 0x1C,
  N64_DKS_JUNGLE_PARKWAY = 0x1D,
  GBA_BOWSER_CASTLE_3 = 0x1E,
  GBA_SHY_GUY_BEACH = 0x1F,

  // Battle courses
  DELFINO_PIER = 0x20,
  BLOCK_PLAZA = 0x21,
  CHAIN_CHOMP_ROULETTE = 0x22,
  FUNKY_STADIUM = 0x23,
  THWOMP_DESERT = 0x24,
  GCN_COOKIE_LAND = 0x25,
  DS_TWILIGHT_HOUSE = 0x26,
  SNES_BATTLE_COURSE_4 = 0x27,
  GBA_BATTLE_COURSE_3 = 0x28,
  N64_SKYSCRAPER = 0x29,

  // Other courses
  GALAXY_COLOSSEUM = 0x36,
  WINNING_DEMO = 0x37,
  LOSING_DEMO = 0x38,
  DRAW_DEMO = 0x39,
  SUNSET_LUIGI_CIRCUIT = 0x3A
} CourseId;

typedef enum {
  MENU_CHARACTER_MANAGER_STATE_CLEARED = 0,
  MENU_CHARACTER_MANAGER_STATE_UNK1 = 1,
  MENU_CHARACTER_MANAGER_STATE_UNK2 = 2,
  MENU_CHARACTER_MANAGER_STATE_UNK3 = 3,
  MENU_CHARACTER_MANAGER_STATE_UNK4 = 4
} MenuCharacterManagerState;

typedef enum {
  COURSE_CACHE_STATE_UNK0 = 0,
  COURSE_CACHE_STATE_UNK1 = 1,
  COURSE_CACHE_STATE_UNK2 = 2,
  COURSE_CACHE_STATE_UNK3 = 3
} CourseCacheState;

class CourseCache : EGG::Disposer {
public:
  CourseCache();
  void init();
  virtual ~CourseCache();
  void load(CourseId courseId);
  void loadOther(MultiDvdArchive* other, EGG::Heap* heap);

  // private: // idk if rii prefers to befriend every class over public-ing
  // everything
  void* mpBuffer;
  EGG::ExpHeap* mpHeap;
  CourseId mCourseId;
  CourseCacheState mState;
  MultiDvdArchive* mpArchive;
};

// begrudging riidefi magic
struct S {
  virtual ~S();
};
inline S::~S() {}
struct T {
public:
  T() {
    mpArchiveHeap = nullptr;
    mpFileHeap = nullptr;
    mState = MENU_CHARACTER_MANAGER_STATE_CLEARED;
  }
  EGG::ExpHeap* mpArchiveHeap;
  EGG::ExpHeap* mpFileHeap;
  MenuCharacterManagerState mState;

  // what am I looking at
  inline bool SOME_CHECK() const {
    return mpArchiveHeap && ((mState <= 4u && (((1 << mState) & 0x15U) != 0)));
  }
  inline void destroy() {
    if (SOME_CHECK()) {
      mpArchiveHeap->freeAll();
      mpFileHeap->freeAll();
    }
    mState = MENU_CHARACTER_MANAGER_STATE_UNK3;
  }
  inline void setArchiveHeap(EGG::ExpHeap* heapSrc) {
    if (!mpArchiveHeap) {
      mpArchiveHeap = heapSrc;
    }
  }
  inline void setFileHeap(EGG::ExpHeap* heapSrc) {
    if (!mpFileHeap) {
      mpFileHeap = heapSrc;
    }
  }
};

class MenuCharacterManager : S, public T {
  friend class ResourceManager;

public:
  MenuCharacterManager() {
    mCharacter = MARIO;
    mTeam = BATTLE_TEAM_NONE;
  }
  virtual ~MenuCharacterManager() {}
  CharacterId mCharacter;
  BattleTeam mTeam;
};

void preloadCourseTask(void* courseId);
const char* getCharacterName(CharacterId charId);
const char* getVehicleName(VehicleId vehicleId);

// unknown structs
struct Whatever {
  u32 _00;
  u8 _04[0xa4 - 0x4];
};
struct Whatever2 {
  u8 _00[0x4 - 0x0];
  Whatever* _04;
  u16 _08; // ...
};

class ResourceManager {
  virtual ~ResourceManager();

public:
  static volatile ResourceManager* createInstance();
  static void destroyInstance();

  // Pretty sure this is actual source code
  union ResMgrInstance {
    volatile ResourceManager* vol;
    ResourceManager* nonvol;
  };
  static ResMgrInstance spInstance;
  static inline ResourceManager* getInstance() { return spInstance.nonvol; }
  // static volatile ResourceManager* spInstance;
  // static ResourceManager* spInstance_REAL;

  ResourceManager();

  MultiDvdArchive** mppSceneArchives;
  MultiDvdArchive mKartArchives[12];
  MultiDvdArchive mBackupKartArchives[12]; // TODO: better name
  DvdArchive mSystemArchives[4];
  JobContext mJobContexts[7];
  EGG::TaskThread* mpTaskThread;
  CourseCache mCourseCache;
  MenuCharacterManager mMenuManagers[4];
  bool mIsGlobeLoadingBusy;
  bool _60d; // this variable is only used in GameScene
  EGG::ExpHeap* mpMenuHeap;
  EGG::Heap* mpGlobeHeap;
  bool mRequestPending;
  bool mRequestsEnabled;

  void foo() volatile {
    mRequestPending = false;
    mRequestsEnabled = true;
  }
  void bar() volatile {
    mpGlobeHeap = nullptr;
    mIsGlobeLoadingBusy = false;
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
  void* getKartArchiveFile(s32 idx, const char* filename, size_t* size);
  void* getBackupKartArchiveFile(s32 idx, const char* filename, size_t* size);
  void* getBspFile(s32 playerIdx, size_t* size);
  void* getFileCopy(s32 archiveIdx, char* filename, EGG::Heap* heap,
                    size_t* size, s8 param_5);
  bool isSceneArchiveLoaded(s32 idx) volatile;
  bool isKartArchiveLoaded(s32 idx);
  bool isBackupKartArchiveLoaded(s32 idx);
  bool isSystemArchiveLoaded(s32 idx);
  bool setArcResourceLink(s32 multiIdx, u16 archiveIdx, void* arcResource,
                          const char* dirname);
  u16 getLoadedArchiveCount(s32 idx);
  // I need this terribleness to match attachArcResourceAccessor
  inline u16 getLoadedArchiveCountInverse(u32 idx) volatile {
    return !isSceneArchiveLoaded(idx) ? 0 : mppSceneArchives[idx]->archiveCount;
  }
  u16 getMenuArchiveCount();
  bool tryRequestTask(EGG::TaskThread::TFunction mainFunction, void* arg);
  bool requestTask(EGG::TaskThread::TFunction mainFunction, void* arg,
                   void* _8);

  void attatchLayoutDir(void* accessor, const char* dirname, Whatever2* param_3,
                        bool param_4);
  void attachArcResourceAccessor(void* arcResourceAccessor,
                                 const char* dirname);
  void preloadCourseAsync(CourseId courseId);
  void initGlobeHeap(size_t size, EGG::Heap* heap);
  // to match flush
  inline void enableRequests() volatile {
    mRequestsEnabled = true;
    mRequestPending = false;
  }
  void flush() NEVER_INLINE;
  void deinitGlobeHeap();
  static void doLoadCharacterKartModel(void* idxs);
  void doLoadCharacterKartModelPriv(s32 idxs);
  bool loadKartMenuModelAsync(s32 idx, CharacterId characterId,
                              BattleTeam battleTeam);
  void createMenuHeaps(u32 count, s32 heapIdx);
  EGG::ExpHeap* getMenuManagerHeap(int managerIdx);
  static u8* loadGlobe(EGG::Heap* globeHeap);
  static void doLoadGlobe(void* globeBlob);
  void doLoadGlobeImpl(u8** glodeBlob) volatile;
  // for matching purposes
  inline bool requestGlobeTaskHelper(void* arg, void* arg2) volatile {
    mIsGlobeLoadingBusy = true;
    if (mRequestsEnabled) {
      mRequestPending = true;
      mpTaskThread->request(ResourceManager::doLoadGlobe, arg, arg2);
    }
    return true;
  }
  bool loadGlobeAsync(void* arg);
  void clear();
  void process() NEVER_INLINE;
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
    mJobContexts[idx].mpMultiArchive = m;
    strncpy(mJobContexts[idx].mFilename, p,
            sizeof(mJobContexts[idx].mFilename));
    mJobContexts[idx].mpArchiveHeap = archiveHeap;
    mJobContexts[idx].mpFileHeap = fileHeap;

    mpTaskThread->request(ResourceManager::doLoadTask, (void*)idx, 0);
    process();

    if (!m->isLoaded()) {
      OSSleepMilliseconds(16);
    }
  }
  inline void requestLoadFile(s32 idx, DvdArchive* archive,
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
  inline void clear(s32 i) {
    MultiDvdArchive* archive;
    EGG::ExpHeap* heap;

    heap = mMenuManagers[i].mpArchiveHeap;
    archive = &mKartArchives[i];

    if (archive->isLoaded()) {
      archive->unmount();
    }
    if (heap) {
      heap->destroy();
    }

    if (mMenuManagers[i].mState != MENU_CHARACTER_MANAGER_STATE_UNK3) {
      mMenuManagers[i].mpArchiveHeap = nullptr;
      mMenuManagers[i].mpFileHeap = nullptr;
      mMenuManagers[i].mState = MENU_CHARACTER_MANAGER_STATE_CLEARED;
    }
  }
  // needed to prevent duplicate code in flush and process
  inline void _process();
};

} // namespace System
