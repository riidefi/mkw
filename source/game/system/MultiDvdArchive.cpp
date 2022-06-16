#include "MultiDvdArchive.hpp"
#pragma dont_reuse_strings on

#include <string.h>

#include "game/host_system/SystemManager.hpp"

#define SUFFIX_SIZE 128
const char* const SZS = ".szs\0";

extern const int _tmp;
const int _tmp = 0;

namespace System {

MultiDvdArchive::MultiDvdArchive(u16 archiveCount) {
  this->archives = nullptr;
  this->archiveCount = archiveCount;
  this->suffixes = nullptr;

  this->archives = new DvdArchive[archiveCount];
  this->suffixes = (char**)new char*[archiveCount];
  this->fileStarts = (void**)new u32[archiveCount];
  this->kinds = new u32[archiveCount];
  this->fileSizes = new u32[archiveCount];

  for (u16 i = 0; i < this->archiveCount; i++) {
    this->suffixes[i] = new char[SUFFIX_SIZE];
    strncpy(this->suffixes[i], SZS, SUFFIX_SIZE);
    this->kinds[i] = 0;
    this->fileSizes[i] = 0;
    this->fileStarts[i] = nullptr;
  }
}

void MultiDvdArchive::init() {
  const char* suffix = SZS;
  for (unsigned short i = 0; i < this->archiveCount; i++) {
    // matches less for some reason if this unneccesary extra comparison is
    // removed
    if (i < this->archiveCount) {
      this->kinds[i] = 0;
      strncpy(this->suffixes[i], suffix, 128);
    }
  }
}

MultiDvdArchive::~MultiDvdArchive() {
  delete[] this->archives;
  delete[] this->suffixes;
  delete[] this->kinds;
  delete[] this->fileSizes;
}

void* MultiDvdArchive::getFile(const char* filename, size_t* size) {
  DvdArchive* archive;
  bool loaded;
  void* file = nullptr;

  for (int i = this->archiveCount - 1; i >= 0; i--) {
    loaded = false;
    archive = &this->archives[i];
    if ((archive->mStatus == DVD_ARCHIVE_STATE_MOUNTED) ||
        (archive->mStatus == DVD_ARCHIVE_STATE_UNKN5)) {
      loaded = true;
    }
    if (loaded && ((file = archive->getFile(filename, size)) != NULL))
      break;
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
    s32 kind = this->kinds[i];

    switch (kind) {
    case 0:
      snprintf(fullname, sizeof(fullname), "%s%s", name, this->suffixes[i]);
      break;
    case 1:
      snprintf(fullname, sizeof(fullname), "%s", this->suffixes[i]);
      break;
    case 2:
      if (this->fileStarts[i] != 0) {
        return true;
      }
      break;
    default:
      continue;
    }
    // from RVL
    if (DVDConvertPathToEntrynum(fullname) != -1) {
      return true;
    }
  }
  return false;
}

void MultiDvdArchive::load(const char* filename, EGG::Heap* param_3,
                           EGG::Heap* heap, unk32 param_5) {
  bool kindFile;
  char fullname[256];

  for (u16 i = 0; i < this->archiveCount; i++) {
    kindFile = true;
    s32 kind = this->kinds[i];

    switch (kind) {
    case 0:
      snprintf(fullname, sizeof(fullname), "%s%s", filename, this->suffixes[i]);
      break;
    case 1:
      snprintf(fullname, sizeof(fullname), "%s", this->suffixes[i]);
      break;
    case 2:
      kindFile = false;
      break;
    default:
      continue;
    }
    if (kindFile) {
      this->archives[i].load(fullname, param_3, 1, '\b', heap, param_5);
    } else {
      this->archives[i].loadBuffer(this->fileStarts[i], this->fileSizes[i],
                                   param_3, 1);
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
    s32 kind = this->kinds[i];

    switch (kind) {
    case 0:
      snprintf(fullname, sizeof(fullname), "%s%s", name, this->suffixes[i]);
      break;
    case 1:
      snprintf(fullname, sizeof(fullname), "%s", this->suffixes[i]);
      break;
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
  DvdArchive* archive;

  for (u16 i = 0; i < this->archiveCount; i++) {
    archive = &this->archives[i];
    if (archive->isLoaded()) {
      sum += archive->mArchiveSize;
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
