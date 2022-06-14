#include "DvdArchive.hpp"

namespace System {

// ??????
__declspec(section ".rodata") int int_8088FAA0 = 0x4B000;

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

// inline function that's been compiled
void DvdArchive::_mount(EGG::Heap* archiveHeap) {
  DvdArchive::mount(archiveHeap);
}

// haven't got a clue
void DvdArchive::_UNKNOWN() {}

void DvdArchive::load(const char* path, EGG::Heap* archiveHeap, int decompress,
                      s32 align_, EGG::Heap* fileHeap, u32 param_7) {
  if ((decompress == 0) || !fileHeap) {
    fileHeap = archiveHeap;
  }

  if (mStatus == DVD_ARCHIVE_STATE_CLEARED) {
    bool ripped = false;
    s32 allocDirection = 1;
    s8 align = -8;

    if (decompress == 0) {
      align = align_;
    }
    if (align < 0) {
      allocDirection = 2;
    }

    mFileStart = DvdRipper_loadToMainRAM(path, 0, fileHeap, allocDirection, 0,
                                         0, &mFileSize);
    if (mFileSize != 0 && mFileStart != nullptr) {
      mFileHeap = fileHeap;
      ripped = true;
    } else {
      mFileSize = 0;
    }

    // ternary doesn't work here for some reason
    if (ripped) {
      mStatus = DVD_ARCHIVE_STATE_RIPPED;
    } else {
      mStatus = DVD_ARCHIVE_STATE_CLEARED;
    }
  }

  if (isRipped()) {
    if (decompress != 0) {
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
  DvdArchive::load(path, archiveHeap, 0, -8, 0, 0);
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

bool DvdArchive::_tryRipFile(const char* path, EGG::Heap* fileHeap, u8 align) {
  return DvdArchive::tryRipFile(path, fileHeap, align);
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

void DvdArchive::_clearArchive() { DvdArchive::clearArchive(); }

void DvdArchive::_clearFile() { DvdArchive::clearFile(); }

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
  buffer[255] = 0;

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

void DvdArchive::_move() { DvdArchive::move(); }

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
