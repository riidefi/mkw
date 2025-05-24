#include "LocalizedArchive.hpp"

namespace System {

// TODO: Hack to re-enable string alignment
#pragma legacy_struct_alignment off

static const char* LOCALIZED_SZS[] = {"",       "_E.szs", "_G.szs", "_F.szs",
                                      "_S.szs", "_I.szs", "_N.szs", nullptr};

MultiDvdArchive* createMultiDvdArchive(ResourceChannelID kind) {
  MultiDvdArchive* archive = nullptr;

  switch (kind) {
  case RES_CHAN_FONT:
  case RES_CHAN_EARTH:
  case RES_CHAN_MII:
  case RES_CHAN_DRIVER:
  case RES_CHAN_DEMO:
  case RES_CHAN_UI_MODEL:
    archive = new MultiDvdArchive(1);
    break;
  case RES_CHAN_RACE_SYS:
    archive = new RaceSysDvdArchive();
    break;
  case RES_CHAN_COURSE:
    archive = new CourseDvdArchive();
    break;
  case RES_CHAN_UI:
    archive = new UIDvdArchive();
    break;
  }

  return archive;
}

CourseDvdArchive::CourseDvdArchive() : MultiDvdArchive(4) { init(); }

void CourseDvdArchive::init() {
  MultiDvdArchive::init();
  const char* dif = "_Dif.szs";

  if (this->archiveCount > 1) {
    this->kinds[1] = RES_KIND_FILE_DOUBLE_FORMAT;
    strncpy(this->suffixes[1], dif, SUFFIX_SIZE);
  }
  if (this->archiveCount > 2) {
    this->kinds[2] = RES_KIND_4;
  }
  if (this->archiveCount > 3) {
    this->kinds[3] = RES_KIND_4;
  }
}

UIDvdArchive::UIDvdArchive() : MultiDvdArchive(2) { init(); }

void UIDvdArchive::init() {
  MultiDvdArchive::init();
  const char* localization = LOCALIZED_SZS[SystemManager::sInstance->mLanguage];

  if (this->archiveCount > 1) {
    this->kinds[1] = RES_KIND_FILE_DOUBLE_FORMAT;
    strncpy(this->suffixes[1], localization, SUFFIX_SIZE);
  }
}

RaceSysDvdArchive::RaceSysDvdArchive() : MultiDvdArchive(2) { init(); }

void RaceSysDvdArchive::init() {
  MultiDvdArchive::init();
  const char* localization = LOCALIZED_SZS[SystemManager::sInstance->mLanguage];

  if (this->archiveCount > 1) {
    this->kinds[1] = RES_KIND_FILE_DOUBLE_FORMAT;
    strncpy(this->suffixes[1], localization, SUFFIX_SIZE);
  }
}

} // namespace System
