#pragma once

#include <rk_types.h>

#include <decomp.h>

#include <egg/core/eggDisposer.hpp>
#include <egg/core/eggExpHeap.hpp>
#include <game/system/DvdArchive.hpp>
#include <game/system/LocalizedArchive.hpp>
#include <game/system/MultiDvdArchive.hpp>
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
// PAL: 0x80540918..0x80540b14
UNKNOWN_FUNCTION(
    loadMission__Q26System15ResourceManagerF8CourseIdlPQ23EGG4Heapb);
// PAL: 0x80540b14..0x80540cfc
UNKNOWN_FUNCTION(
    loadCompetition__Q26System15ResourceManagerF8CourseIdPvUlPQ23EGG4HeapUc);
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
UNKNOWN_FUNCTION(unk_805414a8);
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
// PAL: 0x80541614..0x8054169c
UNKNOWN_FUNCTION(unk_80541614);
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
UNKNOWN_FUNCTION(unk_80541b58);
// PAL: 0x80541c18..0x80541c38
UNKNOWN_FUNCTION(unk_80541c18);
// PAL: 0x80541c38..0x80541c48
UNKNOWN_FUNCTION(unk_80541c38);
// PAL: 0x80541c48..0x80541cbc
UNKNOWN_FUNCTION(unk_80541c48);
// PAL: 0x80541cbc..0x80541ce0
UNKNOWN_FUNCTION(unk_80541cbc);
// PAL: 0x80541ce0..0x80541e44
UNKNOWN_FUNCTION(unk_80541ce0);
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

// begrudging riidefi magic
struct S {
  virtual ~S() = 0;
};
inline S::~S() {}
struct T {
  T() {
    mHeap1 = 0;
    mHeap2 = 0;
    _unk = 0;
  }
  EGG::ExpHeap* mHeap1;
  EGG::ExpHeap* mHeap2;
  s32 _unk;
};

class MenuCharacterManager : S, T {
public:
  MenuCharacterManager() {
    mCharacter = 0;
    mModelType = 2;
  }
  virtual ~MenuCharacterManager() {}
  s32 mCharacter;
  s32 mModelType;
};

class CourseCache : EGG::Disposer {
public:
  CourseCache();
  void init();
  virtual ~CourseCache();
  void load(u32 courseId);
  void loadOther(MultiDvdArchive* other, EGG::Heap* heap);

  // private: // idk if rii prefers to befriend every class over public-ing
  // everything
  void* mBuffer;
  EGG::ExpHeap* mHeap;
  s32 mCourseId;
  s32 mState;
  MultiDvdArchive* mArchive;
};

typedef enum {

} CourseId;

class ResourceManager {
  virtual ~ResourceManager();

public:
  static ResourceManager* createInstance();
  static void destroyInstance();

  static ResourceManager* spInstance;

  ResourceManager();

  MultiDvdArchive** multiArchives1;
  MultiDvdArchive multiArchives2[12];
  MultiDvdArchive MultiArchives3[12];
  DvdArchive dvdArchive[4];
  JobContext jobContexts[7];
  EGG::TaskThread* taskThread;
  CourseCache courseCache;
  MenuCharacterManager menuCharacterManager[4];
  bool isGlobeLoadingBusy;
  bool _60d; // these variables don't have names yet, but are used
  EGG::ExpHeap* _610;
  EGG::Heap* _614;
  bool _618;
  bool _619;

  void foo() volatile {
    _618 = 0;
    _619 = 1;
  }
  void bar() volatile {
    _614 = 0;
    isGlobeLoadingBusy = false;
  }

  MultiDvdArchive* loadCourse(CourseId courseId, EGG::Heap* param_3,
                              bool splitScreen);
  MultiDvdArchive* loadMission(CourseId courseId, s32 missionNum,
                               EGG::Heap* param_3, bool splitScreen);
  MultiDvdArchive* loadCompetition(CourseId courseId, void* fileStart,
                                   u32 fileSize, EGG::Heap* heap, u8 unk6);
  void process();
  static void doLoadTask(void* jobContext);
  void requestLoad(s32 idx, MultiDvdArchive* m, const char* p,
                   EGG::Heap* archiveHeap);
  void requestLoad(s32 idx, DvdArchive* archive, const char* filename, u32 unk,
                   EGG::Heap* archiveHeap);
};

} // namespace System
