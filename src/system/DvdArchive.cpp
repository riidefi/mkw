#include "DvdArchive.hpp"
#include <egg/core/eggDvdRipper.hpp>
#include <rvl/os/osCache.h>
#include <egg/core/eggDecomp.hpp>

namespace System {

extern const int int_8088FAA0;
const int int_8088FAA0 = 0x4B000;

DvdArchive::DvdArchive() {
  mArchive = nullptr;
  mArchiveStart = nullptr;
  mArchiveSize = 0;
  mArchiveHeap = nullptr;
  mFileStart = nullptr;
  mFileSize = 0;
  mFileHeap = nullptr;
  mStatus = DVD_ARCHIVE_STATE_CLEARED;
}

DvdArchive::~DvdArchive() {
  if (mStatus == DVD_ARCHIVE_STATE_MOUNTED) {
    mArchive->unmount();
  }
  DvdArchive::clearArchive();
  DvdArchive::clearFile();
  mStatus = DVD_ARCHIVE_STATE_CLEARED;
}

void DvdArchive::mount(EGG::Heap* archiveHeap) {
  mArchive = EGG::Archive::mount(mArchiveStart, archiveHeap, 4);
  mStatus = DVD_ARCHIVE_STATE_MOUNTED;
}

void DvdArchive::_UNKNOWN() {}

void DvdArchive::load(const char* path, EGG::Heap* archiveHeap,
                      bool isCompressed, s32 align_, EGG::Heap* fileHeap,
                      u32 param_7) {
  if (!isCompressed || !fileHeap) {
    fileHeap = archiveHeap;
  }

  if (mStatus == DVD_ARCHIVE_STATE_CLEARED) {
    bool ripped = false;
    EGG::DvdRipper::EAllocDirection allocDirection =
        EGG::DvdRipper::ALLOC_DIR_TOP;
    s8 align = -8;

    if (isCompressed == false) {
      align = align_;
    }
    if (align < 0) {
      allocDirection = EGG::DvdRipper::ALLOC_DIR_BOTTOM;
    }

    mFileStart = EGG::DvdRipper::loadToMainRAM(
        path, nullptr, fileHeap, allocDirection, 0, nullptr, &mFileSize);
    if (mFileSize != 0 && mFileStart != nullptr) {
      mFileHeap = fileHeap;
      ripped = true;
    } else {
      mFileSize = 0;
    }

    if (ripped) {
      mStatus = DVD_ARCHIVE_STATE_RIPPED;
    } else {
      mStatus = DVD_ARCHIVE_STATE_CLEARED;
    }
  }

  if (isRipped()) {
    if (isCompressed) {
      DvdArchive::decompress(path, archiveHeap, param_7);
      DvdArchive::clearFile();
    } else {
      DvdArchive::move();
    }
    DvdArchive::mount(archiveHeap);
  }
}

void DvdArchive::load(const char* path, u32 param_2, EGG::Heap* archiveHeap) {
  (void)param_2;
  DvdArchive::load(path, archiveHeap, false, -8, 0, 0);
}

void DvdArchive::loadBuffer(void* fileStart, u32 fileSize,
                            EGG::Heap* archiveHeap, s32 param_4) {
  mFileStart = fileStart;
  mFileSize = fileSize;
  if (param_4 != 0) {
    DvdArchive::decompress("buffer_data", archiveHeap, 0);
    mFileStart = 0;
    mFileSize = 0;
    mFileHeap = 0;
  }
  DvdArchive::mount(archiveHeap);
}

void* DvdArchive::getFileCopy(char* filename, EGG::Heap* heap, size_t* size,
                              s8 align) {
  size_t fileSize;
  void* file = DvdArchive::getFile(filename, &fileSize);
  void* result = file;

  if (file) {
    void* buffer = heap->alloc(fileSize, align);
    memcpy(buffer, file, fileSize);
    result = buffer;
    if (buffer && size) {
      *size = fileSize;
    }
  }
  return result;
}

void DvdArchive::_UNKNOWN2(int, u8* p) { delete[] p; }

void DvdArchive::ripFile(const char* path, EGG::Heap* fileHeap, u8 align) {
  bool ripped = DvdArchive::tryRipFile(path, fileHeap, align);
  if (ripped) {
    mStatus = DVD_ARCHIVE_STATE_RIPPED;
  } else {
    mStatus = DVD_ARCHIVE_STATE_CLEARED;
  }
}

bool DvdArchive::tryRipFile(const char* path, EGG::Heap* fileHeap, s8 align) {
  EGG::DvdRipper::EAllocDirection allocDirection =
      EGG::DvdRipper::ALLOC_DIR_TOP;
  bool ripped = false;

  if (align < 0) {
    allocDirection = EGG::DvdRipper::ALLOC_DIR_BOTTOM;
  }

  mFileStart = EGG::DvdRipper::loadToMainRAM(path, 0, fileHeap, allocDirection,
                                             0, 0, &mFileSize);
  if (mFileSize && mFileStart) {
    mFileHeap = fileHeap;
    ripped = true;
  } else {
    mFileSize = 0;
  }
  return ripped;
}

void DvdArchive::clear() {
  DvdArchive::clearArchive();
  DvdArchive::clearFile();
}

void DvdArchive::_UNKNOWN3() {}

void DvdArchive::unmount() {
  if (mStatus == DVD_ARCHIVE_STATE_MOUNTED) {
    mArchive->unmount();
  }
  DvdArchive::clearArchive();
  DvdArchive::clearFile();
  mStatus = DVD_ARCHIVE_STATE_CLEARED;
}

void DvdArchive::clearArchive() {
  if (!mArchiveStart)
    return;

  mArchiveHeap->free(mArchiveStart);
  mArchiveStart = nullptr;
  mArchiveSize = NULL;
  mArchiveHeap = nullptr;
}

void DvdArchive::clearFile() {
  if (!mFileStart)
    return;

  mFileHeap->free(mFileStart);
  mFileStart = nullptr;
  mFileSize = NULL;
  mFileHeap = nullptr;
}

void* DvdArchive::getFile(const char* filename, size_t* size) {
  void* result;
  int entryId;
  EGG::Archive::FileInfo fileInfo;
  char buffer[256];

  if (mStatus != DVD_ARCHIVE_STATE_MOUNTED) {
    return 0;
  }

  if (filename[0] == '/') {
    snprintf(buffer, sizeof(buffer), "%s", filename);
  } else {
    snprintf(buffer, sizeof(buffer), "/%s", filename);
  }
  buffer[sizeof(buffer) - 1] = 0;

  fileInfo.startOffset = 0;
  fileInfo.length = 0;
  entryId = mArchive->convertPathToEntryID(buffer);
  result = nullptr;

  if (entryId != -1) {
    result = mArchive->getFileFast(entryId, &fileInfo);
    if (result && size) {
      *size = fileInfo.length;
    }
  }

  return result;
}

void DvdArchive::decompress(const char* path, EGG::Heap* archiveHeap,
                            u32 _unused) {
  (void)path;
  s32 expandSize = EGG::Decomp::getExpandSize((u8*)mFileStart);
  void* archive = archiveHeap->alloc(expandSize, 0x20);
  EGG::Decomp::decodeSZS((u8*)mFileStart, (u8*)archive);
  mArchiveSize = expandSize;
  mArchiveStart = archive;
  mArchiveHeap = archiveHeap;
  DCStoreRange(archive, expandSize);
  mStatus = DVD_ARCHIVE_STATE_DECOMPRESSED;
  // The function will automatically inline unless we do this
  // How wonderfully convenient that we have an unused parameter!
  (void)_unused;
  (void)_unused;
  (void)_unused;
  (void)_unused;
  (void)_unused;
  (void)_unused;
  (void)_unused;
}

void DvdArchive::move() {
  mArchiveStart = mFileStart;
  mArchiveSize = mFileSize;
  mArchiveHeap = mFileHeap;
  mFileStart = 0;
  mFileSize = 0;
  mFileHeap = 0;
  mStatus = DVD_ARCHIVE_STATE_DECOMPRESSED;
}

void DvdArchive::loadOther(const DvdArchive* other, EGG::Heap* heap) {
  if (other->isRipped()) {
    mFileStart = other->mFileStart;
    mStatus = DVD_ARCHIVE_STATE_RIPPED;
    DvdArchive::decompress((char*)0, heap, 0);
    DvdArchive::mount(heap);
    mFileStart = 0;
    mFileSize = 0;
  } else {
    mStatus = DVD_ARCHIVE_STATE_CLEARED;
  }
}

} // namespace System
