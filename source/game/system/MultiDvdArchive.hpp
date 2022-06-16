#pragma once

#include "DvdArchive.hpp"
#include <game/host_system/SystemManager.hpp>

#include <rk_types.h>
#include <decomp.h>
#include <rvl/dvd/dvd.h>

// TODO: Move somewhere more appropriate
typedef enum {
  RACE_COMMON = 0,
  SCENE_UI_FONT = 3,
  SCENE_MODEL_EARTH = 4,
  SCENE_MODEL_MII_BODY = 5,
  SCENE_MODEL_DRIVER = 6,
  DEMO = 7,
  SCENE_MODEL_BACKMODEL = 8
} SLoaderKind;

namespace System {

class MultiDvdArchive {
public:
  MultiDvdArchive(u16 archiveCount);
  void clear();
  bool exists(const char* name);
  void* getFile(const char* filename, size_t* size);
  void unmount();
  void rip(const char* name, EGG::Heap* heap);
  void load(const char* filename, EGG::Heap* param_3, EGG::Heap* heap,
            unk32 param_5);
  void loadOther(MultiDvdArchive* other, EGG::Heap* heap);
  bool isLoaded();
  void* getEarliestResBufInMem();
  void* getFarthestResBufInMem();
  int totalArchiveSize();
  u16 rippedArchiveCount();
  virtual ~MultiDvdArchive();
  virtual void init();

protected:
  DvdArchive* archives;
  u16 archiveCount;
  u32* fileSizes;
  char** suffixes;
  void** fileStarts;
  u32* kinds;
};

} // namespace System
