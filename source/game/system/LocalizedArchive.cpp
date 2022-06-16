#include "LocalizedArchive.hpp"

const char* LOCALIZED_SZS[] = {"\0\0\0", "_E.szs\0", "_G.szs\0", "_F.szs\0",
                               "_S.szs\0", "_I.szs\0", "_N.szs\0", nullptr};
const char DIF_SZS[] = "_Dif.szs";

namespace System {

MultiDvdArchive* createMultiDvdArchive(SLoaderKind kind) {
  MultiDvdArchive* archive = nullptr;

  switch (kind) {
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
    archive = new MultiDvdArchive(1);
    break;
  case RACE_COMMON:
    archive = new RaceArchive;
    break;
  case 1:
    archive = new CourseArchive;
    break;
  case 2:
    archive = new Unk2Archive;
    break;
  }

  return archive;
}

CourseArchive::CourseArchive() : MultiDvdArchive(4) { init(); }

void CourseArchive::init() {
  MultiDvdArchive::init();
  const char* dif = DIF_SZS;

  if (this->archiveCount > 1) {
    this->kinds[1] = 0;
    strncpy(this->suffixes[1], dif, 0x80);
  }
  if (this->archiveCount > 2) {
    this->kinds[2] = 4;
  }
  if (this->archiveCount > 3) {
    this->kinds[3] = 4;
  }
}

Unk2Archive::Unk2Archive() : MultiDvdArchive(2) { init(); }

void Unk2Archive::init() {
  MultiDvdArchive::init();
  const char* localization = LOCALIZED_SZS[SystemManager::sInstance->mLanguage];

  if (this->archiveCount > 1) {
    this->kinds[1] = 0;
    strncpy(this->suffixes[1], localization, 0x80);
  }
}

RaceArchive::RaceArchive() : MultiDvdArchive(2) { init(); }

void RaceArchive::init() {
  MultiDvdArchive::init();
  const char* localization = LOCALIZED_SZS[SystemManager::sInstance->mLanguage];

  if (this->archiveCount > 1) {
    this->kinds[1] = 0;
    strncpy(this->suffixes[1], localization, 0x80);
  }
}

} // namespace System