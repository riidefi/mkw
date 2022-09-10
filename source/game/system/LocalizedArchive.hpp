#pragma once

#include "MultiDvdArchive.hpp"

namespace System {

MultiDvdArchive* createMultiDvdArchive(ResourceChannelID kind);

class CourseDvdArchive : public MultiDvdArchive {
public:
  CourseDvdArchive();
  void init() override;
};

class UIDvdArchive : public MultiDvdArchive {
public:
  UIDvdArchive();
  void init() override;
};

class RaceSysDvdArchive : public MultiDvdArchive {
public:
  RaceSysDvdArchive();
  void init() override;
};

} // namespace System
