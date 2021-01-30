/*!
 * @file
 * @brief TODO
 */

#include <egg/core/eggArchive.hpp>
#include <rvl/arc/binary_format.h>

struct rvlDvdFile {
  char _[0x3c];
};
extern "C" unk32 DVDOpen(const char*, rvlDvdFile*);
extern "C" u32 DVDReadPrio(rvlDvdFile*, void*, u32, unk32, unk32);
extern "C" unk32 DVDClose(rvlDvdFile*);

namespace EGG {

bool Archive::sIsArchiveListInitialized;
nw4r::ut::List Archive::sArchiveList;

Archive::~Archive() { removeList(this); }

void Archive::removeList(Archive* pArchive) {
  nw4r::ut::List_Remove(&sArchiveList, pArchive);
}

Archive* Archive::mount(void* arcStart, Heap* pHeap, int align) {
  Archive* wArchive = findArchive(arcStart); // r30, INLINE archive wrapper
  if (wArchive == nullptr) {
    wArchive = new (pHeap, align) Archive(); // INLINE
    EGG_ASSERT(wArchive, "eggArchive.cpp", 159, "archive != NULL");

    bool bInitSuccess = wArchive->initHandle(arcStart);
    if (bInitSuccess)
      wArchive->mStatus = LOADED_AND_CAN_FAST_READ;
    else
      wArchive->mStatus = NOT_LOADED;
    EGG_ASSERT(bInitSuccess, "eggArchive.cpp", 166, "false");
    // If we failed, clean up
    if (!bInitSuccess) // INLINE
    {
      delete wArchive;
      wArchive = nullptr;
    }
  } else {
    wArchive->_14++;
  }

  return wArchive;
}
// exact same as above but _10 set to 2 not 1
Archive* Archive::mountNoFastGet(void* arcStart, Heap* pHeap, int align) {
  Archive* wArchive = findArchive(arcStart); // r30, INLINE archive wrapper
  if (wArchive == nullptr) {
    wArchive = new (pHeap, align) Archive(); // INLINE
    EGG_ASSERT(wArchive, "eggArchive.cpp", 159, "archive != NULL");

    bool bInitSuccess = wArchive->initHandle(arcStart);
    if (bInitSuccess)
      wArchive->mStatus = LOADED;
    else
      wArchive->mStatus = NOT_LOADED;
    EGG_ASSERT(bInitSuccess, "eggArchive.cpp", 166, "false");
    // If we failed, clean up
    if (!bInitSuccess) // INLINE
    {
      delete wArchive;
      wArchive = nullptr;
    }
  } else {
    wArchive->_14++;
  }

  return wArchive;
}
void Archive::unmount() {
  if (_14 != 0 && --_14 == 0) {
    mStatus = NOT_LOADED;
    delete this;
  }
}
int Archive::convertPathToEntryID(const char* path) {
  return ARCConvertPathToEntrynum(&this->mArcHandle, path);
}
void* Archive::getFileFast(int entryNum, FileInfo* pInfo) {
  rvlArchiveFile fileInfo; // col
  void* result = nullptr;
  if (mStatus == LOADED_AND_CAN_FAST_READ) {
    if (mArcHandle.open(entryNum, fileInfo)) {
      result = ARCGetStartAddrInMem(&fileInfo);
      if (pInfo) {
        pInfo->startOffset = ARCGetStartOffset(&fileInfo);
        pInfo->length = ARCGetLength(&fileInfo);
      }
    }
    ARCClose(&fileInfo);
  }
  return result;
}
void Archive::getFile(const char* path, FileInfo* pInfo) {
  rvlArchiveFile fileInfo; // col
  if (mArcHandle.open(path, fileInfo)) {
    pInfo->startOffset = ARCGetStartOffset(&fileInfo);
    pInfo->length = ARCGetLength(&fileInfo);
  }
  ARCClose(&fileInfo);
}

// Reads header from u8 file on disc. Then reads header and allocates file based
// on that filesize.
void* Archive::loadFromDisc(const char* path, Heap* pHeap, int align) {
  rvlDvdFile dvdFileInfo;
  int alignRounded = align > 0 ? -32 : 32; // r31
  if (!DVDOpen(path, &dvdFileInfo))
    return nullptr;

  void* ARC = nullptr;
  rvlArchiveHeader* readHeader = (rvlArchiveHeader*)pHeap->alloc(
      sizeof(rvlArchiveHeader), alignRounded); // r30

  if (readHeader != nullptr) {
    if (DVDReadPrio(&dvdFileInfo, readHeader, 32, 0, 2) >= 32) {
      u32 arcSize =
          ROUND_UP(readHeader->nodes.size + sizeof(rvlArchiveHeader), 32);
      ARC = pHeap->alloc(arcSize, align); // r31

      if (ARC) {
        // needed for match
        u32 res = DVDReadPrio(&dvdFileInfo, ARC, arcSize, 0, 2);
        if (res != arcSize) {
          pHeap->free(ARC); // If we failed to read fst
          ARC = nullptr;
        }
      }
    }
    pHeap->free(readHeader);
  }
  DVDClose(&dvdFileInfo);
  return ARC;
}

} // namespace EGG
