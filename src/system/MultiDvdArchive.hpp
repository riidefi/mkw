#pragma once

#include "DvdArchive.hpp"
#include <host_system/SystemManager.hpp>

#include <rk_types.h>
#include <rvl/dvd/dvd.h>

namespace System {

enum ResourceChannelID {
  RES_CHAN_RACE_SYS, //!< [0] Localized: /Race/Common.szs and such
  RES_CHAN_COURSE,   //!< [1] Diff'd: Track file
  RES_CHAN_UI,       //!< [2] Localized: 2D UI
  RES_CHAN_FONT,     //!< [3] Fonts
  RES_CHAN_EARTH,    //!< [4] Globe (Async LZ)
  RES_CHAN_MII,      //!< [5] Mii Parts
  RES_CHAN_DRIVER,   //!< [6] Driver
  RES_CHAN_DEMO,     //!< [7] Cutscenes
  RES_CHAN_UI_MODEL, //!< [8] BackModel et al

  RES_CHAN_NUM
};

enum EResourceKind {
  RES_KIND_FILE_DOUBLE_FORMAT, // 0 %s%s Supports prefix
  RES_KIND_FILE_SINGLE_FORMAT, // 1 %s
  RES_KIND_BUFFER,             // 2
  RES_KIND_3,                  // unseen
  RES_KIND_4,                  // _Dif loader

  RES_KIND_DEFAULT = RES_KIND_FILE_DOUBLE_FORMAT
};

class MultiDvdArchive {
  friend class ResourceManager;

public:
  MultiDvdArchive(u16 archiveCount = 1);
  virtual ~MultiDvdArchive();

  virtual void init();
  void clear();

  bool exists(const char* name);
  void* getFile(const char* filename, size_t* size);
  void unmount();
  void rip(const char* name, EGG::Heap* heap);
  void load(const char* filename, EGG::Heap* archiveHeap, EGG::Heap* fileHeap,
            unk32 param_5);
  void loadOther(MultiDvdArchive* other, EGG::Heap* heap);
  bool isLoaded();

  int totalArchiveSize();
  u16 rippedArchiveCount();

protected:
  void* getEarliestResBufInMem();
  void* getFarthestResBufInMem();

  enum { SUFFIX_SIZE = 128 };
  DvdArchive* archives;
  u16 archiveCount;
  u32* fileSizes;
  char** suffixes;
  void** fileStarts;
  EResourceKind* kinds;
};

} // namespace System
