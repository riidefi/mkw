#include "MultiDvdArchive.hpp"

// TODO: Hack to disable string pooling
#pragma dont_reuse_strings on

#include <string.h>

#include "host_system/SystemManager.hpp"

const char* const SZS = ".szs\0";

extern const int _tmp;
const int _tmp = 0;

namespace System {

MultiDvdArchive::MultiDvdArchive(u16 archiveCount) {
  this->archives = nullptr;
  this->archiveCount = archiveCount;
  this->suffixes = nullptr;

  this->archives = new DvdArchive[archiveCount];
  this->suffixes = new char*[archiveCount];
  this->fileStarts = new void*[archiveCount];
  this->kinds = new EResourceKind[archiveCount];
  this->fileSizes = new u32[archiveCount];

  for (u16 i = 0; i < this->archiveCount; i++) {
    this->suffixes[i] = new char[SUFFIX_SIZE];
    strncpy(this->suffixes[i], SZS, SUFFIX_SIZE);
    this->kinds[i] = RES_KIND_DEFAULT;
    this->fileSizes[i] = 0;
    this->fileStarts[i] = nullptr;
  }
}

void MultiDvdArchive::init() {
  const char* suffix = SZS;
  for (u16 i = 0; i < this->archiveCount; i++) {
    // matches less for some reason if this unneccesary extra comparison is
    // removed
    if (i < this->archiveCount) {
      this->kinds[i] = RES_KIND_DEFAULT;
      strncpy(this->suffixes[i], suffix, 128);
    }
  }
}

MultiDvdArchive::~MultiDvdArchive() {
  delete[] this->archives;
  delete[] this->suffixes;
  // Memory leak: entries of this->suffixes
  // Memory leak: this->fileStarts
  delete[] this->kinds;
  delete[] this->fileSizes;
}

void* MultiDvdArchive::getFile(const char* filename, size_t* size) {
  DvdArchive* archive;
  bool loaded;
  void* file = nullptr;

  for (int i = this->archiveCount - 1; i >= 0; i--) {
    archive = &this->archives[i];

    loaded = archive->isLoaded();
    if (!loaded) {
      continue;
    }

    file = archive->getFile(filename, size);
    if (file != nullptr) {
      break;
    }
  }

  return file;
}

bool MultiDvdArchive::isLoaded() {
  for (u16 i = 0; i < this->archiveCount; i++) {
    if (this->archives[i].isLoaded())
      return true;
  }
  return false;
}

bool MultiDvdArchive::exists(const char* name) {
  char fullname[256];

  for (u16 i = 0; i < this->archiveCount; i++) {
    switch (this->kinds[i]) {
    case RES_KIND_FILE_DOUBLE_FORMAT:
      snprintf(fullname, sizeof(fullname), "%s%s", name, this->suffixes[i]);
      break;
    case RES_KIND_FILE_SINGLE_FORMAT:
      snprintf(fullname, sizeof(fullname), "%s", this->suffixes[i]);
      break;
    case RES_KIND_BUFFER:
      if (this->fileStarts[i] != 0) {
        return true;
      }
      break;
    case RES_KIND_3:
    case RES_KIND_4:
    default:
      continue;
    }
    if (DVDConvertPathToEntrynum(fullname) != -1) {
      return true;
    }
  }
  return false;
}

void MultiDvdArchive::load(const char* filename, EGG::Heap* archiveHeap,
                           EGG::Heap* fileHeap, unk32 param_5) {
  bool kindFile;
  char fullname[256];

  for (u16 i = 0; i < this->archiveCount; i++) {
    kindFile = true;

    switch (this->kinds[i]) {
    case RES_KIND_FILE_DOUBLE_FORMAT:
      snprintf(fullname, sizeof(fullname), "%s%s", filename, this->suffixes[i]);
      break;
    case RES_KIND_FILE_SINGLE_FORMAT:
      snprintf(fullname, sizeof(fullname), "%s", this->suffixes[i]);
      break;
    case RES_KIND_BUFFER:
      kindFile = false;
      break;
    case RES_KIND_3:
    case RES_KIND_4:
    default:
      continue;
    }
    if (kindFile) {
      this->archives[i].load(fullname, archiveHeap, true, 8, fileHeap, param_5);
    } else {
      this->archives[i].loadBuffer(this->fileStarts[i], this->fileSizes[i],
                                   archiveHeap, 1);
    }
  }
}

void MultiDvdArchive::unmount() {
  for (u16 i = 0; i < this->archiveCount; i++) {
    this->archives[i].unmount();
  }
}

void MultiDvdArchive::loadOther(MultiDvdArchive* other, EGG::Heap* heap) {
  for (u16 i = 0; i < this->archiveCount; i++) {
    this->archives[i].loadOther(&other->archives[i], heap);
  }
}

void MultiDvdArchive::rip(const char* name, EGG::Heap* heap) {
  char fullname[256];

  for (u16 i = 0; i < this->archiveCount; i++) {
    switch (this->kinds[i]) {
    case RES_KIND_FILE_DOUBLE_FORMAT:
      snprintf(fullname, sizeof(fullname), "%s%s", name, this->suffixes[i]);
      break;
    case RES_KIND_FILE_SINGLE_FORMAT:
      snprintf(fullname, sizeof(fullname), "%s", this->suffixes[i]);
      break;
    case RES_KIND_BUFFER:
    case RES_KIND_3:
    case RES_KIND_4:
    default:
      continue;
    }
    this->archives[i].ripFile(fullname, heap, 8);
  }
}

void MultiDvdArchive::clear() {
  for (u16 i = 0; i < this->archiveCount; i++) {
    this->archives[i].clear();
  }
}

int MultiDvdArchive::totalArchiveSize() {
  u32 sum = 0;

  for (u16 i = 0; i < this->archiveCount; i++) {
    if (this->archives[i].isLoaded()) {
      sum += this->archives[i].mArchiveSize;
    }
  }

  return sum;
}

void* MultiDvdArchive::getEarliestResBufInMem() {
  void* ret = nullptr;
  for (u16 i = 0; i < this->archiveCount; i++) {
    DvdArchive* archive = &this->archives[i];

    if (archive->isLoaded()) {
      if (ret == nullptr || ret < archive->mArchiveStart) {
        ret = archive->mArchiveStart;
      }
    }
  }

  return ret;
}

void* MultiDvdArchive::getFarthestResBufInMem() {
  void* ret = nullptr;
  for (u16 i = 0; i < this->archiveCount; i++) {
    DvdArchive* archive = &this->archives[i];

    if (archive->isLoaded()) {
      if (ret == nullptr || ret > archive->getArchiveEnd()) {
        ret = archive->getArchiveEnd();
      }
    }
  }
  return ret;
}

u16 MultiDvdArchive::rippedArchiveCount() {
  u16 count = 0;

  for (u16 i = 0; i < this->archiveCount; i++) {
    if (this->archives[i].isRipped()) {
      count++;
    }
  }

  return count;
}

} // namespace System
