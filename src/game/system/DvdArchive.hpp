#pragma once

#include <rk_types.h>
#include <stdio.h>
#include <egg/core/eggArchive.hpp>
#include <egg/core/eggHeap.hpp>

namespace System {
enum ArchiveState {
  DVD_ARCHIVE_STATE_CLEARED = 0,
  DVD_ARCHIVE_STATE_RIPPED = 2,
  DVD_ARCHIVE_STATE_DECOMPRESSED = 3,
  DVD_ARCHIVE_STATE_MOUNTED = 4,
  DVD_ARCHIVE_STATE_UNKN5 = 5
};

class DvdArchive {
  friend class MultiDvdArchive;
  friend class ResourceManager;

public:
  DvdArchive();
  virtual ~DvdArchive();

  void mount(EGG::Heap* archiveHeap);
  void load(const char* path, EGG::Heap* archiveHeap, bool isCompressed,
            s32 align, EGG::Heap* fileHeap, u32 param_6);
  void load(const char* path, u32 _unused, EGG::Heap* archiveHeap);
  void loadBuffer(void* fileStart, u32 fileSize, EGG::Heap* archiveHeap,
                  s32 param_4);
  void* getFileCopy(char* filename, EGG::Heap* heap, size_t* size, s8 param_4);
  void ripFile(const char* path, EGG::Heap* fileHeap, u8 align);
  bool tryRipFile(const char* path, EGG::Heap* fileHeap, s8 align);
  void clear();
  void unmount();
  void clearArchive();
  void clearFile();
  void* getFile(const char* filename, size_t* size);
  void decompress(const char* path, EGG::Heap* archiveHeap, u32 _unused);
  void move();
  void loadOther(const DvdArchive* other, EGG::Heap* heap);

  bool isLoaded() const {
    return mStatus == DVD_ARCHIVE_STATE_MOUNTED ||
           mStatus == DVD_ARCHIVE_STATE_UNKN5;
  }
  bool isRipped() const { return mStatus == DVD_ARCHIVE_STATE_RIPPED; }

private:
  void _UNKNOWN();
  void _UNKNOWN2(int, u8* p);
  void _UNKNOWN3();

  void* getArchiveEnd() const {
    return (void*)(mArchiveSize + (u32)mArchiveStart);
  }

  EGG::Archive* mArchive;
  void* mArchiveStart;
  u32 mArchiveSize;
  EGG::Heap* mArchiveHeap;
  void* mFileStart;
  u32 mFileSize;
  EGG::Heap* mFileHeap;
  volatile ArchiveState mStatus;
};

} // namespace System
