#pragma once

#include <rk_types.h>

#include <decomp.h>

#include <stdio.h>
#include <rvl/os/osCache.h>
#include <egg/core/eggArchive.hpp>
#include <egg/core/eggDecomp.hpp>
#include <egg/core/eggHeap.hpp>

// TODO: when DvdRipper is decompiled, replace the function call in load() and
// remove this line
extern void* DvdRipper_loadToMainRAM(const char* path, u8* dst, EGG::Heap* heap,
                                     s32 allocDirection, u32 offset,
                                     s32* param_6, u32* fileSize);

namespace System {

class DvdArchive {
public:
  DvdArchive();
  virtual ~DvdArchive();

  void _mount(EGG::Heap* archiveHeap);
  void _UNKNOWN();
  void load(const char* path, EGG::Heap* archiveHeap, int decompress,
            s32 param_4, EGG::Heap* filePath, u32 param_6);
  //! loads uncompressed archives
  void load(const char* path, u32 _unused, EGG::Heap* archiveHeap);
  void loadBuffer(void* fileStart, u32 fileSize, EGG::Heap* archiveHeap,
                  s32 param_4);
  void* getFileCopy(char* filename, EGG::Heap* heap, size_t* size, s8 param_4);
  void _UNKNOWN2(int, u8* p);
  void ripFile(const char* path, EGG::Heap* fileHeap, u8 align);
  bool _tryRipFile(const char* path, EGG::Heap* fileHeap, u8 align);
  void clear();
  void _UNKNOWN3();
  void unmount();
  void _clearArchive();
  void _clearFile();
  void* getFile(const char* filename, size_t* size);
  void decompress(const char* path, EGG::Heap* archiveHeap, u32 _unused);
  void _move();
  void loadOther(const DvdArchive* other, EGG::Heap* heap);

private:
  enum ArchiveState {
    DVD_ARCHIVE_STATE_CLEARED = 0,
    DVD_ARCHIVE_STATE_RIPPED = 2,
    DVD_ARCHIVE_STATE_DECOMPRESSED = 3,
    DVD_ARCHIVE_STATE_MOUNTED = 4
  };
  EGG::Archive* mArchive;
  void* mArchiveStart;
  u32 mArchiveSize;
  EGG::Heap* mArchiveHeap;
  void* mFileStart;
  u32 mFileSize;
  EGG::Heap* mFileHeap;
  volatile ArchiveState mStatus;

  inline void clearArchive() {
    if (!mArchiveStart)
      return;

    mArchiveHeap->free(mArchiveStart);
    mArchiveStart = nullptr;
    mArchiveSize = NULL;
    mArchiveHeap = nullptr;
  }
  inline void clearFile() {
    if (!mFileStart)
      return;

    mFileHeap->free(mFileStart);
    mFileStart = nullptr;
    mFileSize = NULL;
    mFileHeap = nullptr;
  }
  inline void mount(EGG::Heap* archiveHeap) {
    mArchive = EGG::Archive::mount(mArchiveStart, archiveHeap, 4);
    mStatus = DVD_ARCHIVE_STATE_MOUNTED;
  }
  inline void move() {
    mArchiveStart = mFileStart;
    mArchiveSize = mFileSize;
    mArchiveHeap = mFileHeap;
    mFileStart = 0;
    mFileSize = 0;
    mFileHeap = 0;
    mStatus = DVD_ARCHIVE_STATE_DECOMPRESSED;
  }
  inline bool tryRipFile(const char* path, EGG::Heap* fileHeap, char align) {
    s32 allocDirection = 1;
    bool ripped = false;

    if (align < 0) {
      allocDirection = 2;
    }

    mFileStart = DvdRipper_loadToMainRAM(path, 0, fileHeap, allocDirection, 0,
                                         0, &mFileSize);
    if (mFileSize && mFileStart) {
      mFileHeap = fileHeap;
      ripped = true;
    } else {
      mFileSize = 0;
    }
    return ripped;
  }
  bool isRipped() const volatile { return mStatus == DVD_ARCHIVE_STATE_RIPPED; }
};

} // namespace System
