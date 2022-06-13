#pragma once

#include <rk_types.h>

#include <decomp.h>

#include <stdio.h>
#include <egg/core/eggArchive.hpp>
#include <egg/core/eggHeap.hpp>

// TODO: when DvdRipper is decompiled, replace the function call in load() and
// remove this line
extern void* DvdRipper_loadToMainRAM(char* path, u8* dst, EGG::Heap* heap,
                                     s32 allocDirection, u32 offset,
                                     s32* param_6, u32* fileSize);

enum ArchiveState {
  DVD_ARCHIVE_STATE_CLEARED = 0,
  DVD_ARCHIVE_STATE_RIPPED = 2,
  DVD_ARCHIVE_STATE_DECOMPRESSED = 3,
  DVD_ARCHIVE_STATE_MOUNTED = 4
};

class DvdArchive {
public:
  DvdArchive();
  virtual ~DvdArchive();
  virtual void init() = 0;
  void _mount(EGG::Heap* archiveHeap);
  void _UNKNOWN();
  void load(char* path, EGG::Heap* archiveHeap, int decompress, s32 param_4,
            EGG::Heap* filePath, u32 param_6);
  //! loads uncompressed archives
  void load(char* path, u32 _unused, EGG::Heap* archiveHeap);
  void loadBuffer(void* fileStart, u32 fileSize, EGG::Heap* archiveHeap,
                  s32 param_4);
  void* getFileCopy(char* filename, EGG::Heap* heap, size_t* size, s8 param_4);
  void _UNKNOWN3(int, void* p);
  void ripFile(char* path, EGG::Heap* fileHeap, u8 align);
  bool _tryRipFile(char* path, EGG::Heap* fileHeap, u8 align);
  void clear();
  void _UNKNOWN2();
  void unmount();
  void _clearArchive();
  void _clearFile();
  void* getFile(char* filename, size_t* size);
  void decompress(char* path, EGG::Heap* archiveHeap, u32 _unused);
  void _move();

private:
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
    return;
  }
  inline void clearFile() {
    if (!mFileStart)
      return;

    mFileHeap->free(mFileStart);
    mFileStart = nullptr;
    mFileSize = NULL;
    mFileHeap = nullptr;
    return;
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
  inline bool tryRipFile(char* path, EGG::Heap* fileHeap, char align) {
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
  volatile bool isRipped() const { return mStatus == 2; }
};

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80518cc0..0x80518cf4
UNKNOWN_FUNCTION(DvdArchive_ct);
// PAL: 0x80518cf4..0x80518dcc
UNKNOWN_FUNCTION(DvdArchive_dt);
// PAL: 0x80518dcc..0x80518e0c
UNKNOWN_FUNCTION(DvdArchive_mount);
// PAL: 0x80518e0c..0x80518e10
UNKNOWN_FUNCTION(FUN_80518e0c);
// PAL: 0x80518e10..0x80518fa4
UNKNOWN_FUNCTION(load__10DvdArchiveFPcPQ23EGG4HeapilPQ23EGG4HeapUl);
// PAL: 0x80518fa4..0x80518fbc
UNKNOWN_FUNCTION(SArchive_load);
// PAL: 0x80518fbc..0x80519040
UNKNOWN_FUNCTION(loadBuffer__10DvdArchiveFPvUlPQ23EGG4Heapl);
// PAL: 0x80519040..0x805190e8
UNKNOWN_FUNCTION(unk_80519040);
// PAL: 0x805190e8..0x805190f0
UNKNOWN_FUNCTION(unk_805190e8);
// PAL: 0x805190f0..0x805191a4
UNKNOWN_FUNCTION(ripFile__10DvdArchiveFPcPQ23EGG4HeapUc);
// PAL: 0x805191a4..0x80519240
UNKNOWN_FUNCTION(unk_805191a4);
// PAL: 0x80519240..0x805192cc
UNKNOWN_FUNCTION(clear__10DvdArchiveFv);
// PAL: 0x805192cc..0x80519370
UNKNOWN_FUNCTION(unmount__10DvdArchiveFv);
// PAL: 0x80519370..0x805193c8
UNKNOWN_FUNCTION(unk_80519370);
// PAL: 0x805193c8..0x80519420
UNKNOWN_FUNCTION(unk_805193c8);
// PAL: 0x80519420..0x80519508
UNKNOWN_FUNCTION(getFile__10DvdArchiveFPcPUl);
// PAL: 0x80519508..0x805195a4
UNKNOWN_FUNCTION(decompress__10DvdArchiveFPcPQ23EGG4HeapUl);
// PAL: 0x805195a4..0x805195d8
UNKNOWN_FUNCTION(unk_805195a4);
// PAL: 0x805195d8..0x80519670
UNKNOWN_FUNCTION(SArchive_loadOther);

#ifdef __cplusplus
}
#endif
