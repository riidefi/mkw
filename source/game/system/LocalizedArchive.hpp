#pragma once
#include "MultiDvdArchive.hpp"

namespace System {

class RaceArchive : public MultiDvdArchive {
public:
  RaceArchive();
  virtual void init();
};

class Unk2Archive : public MultiDvdArchive {
public:
  Unk2Archive();
  virtual void init();
};

class CourseArchive : public MultiDvdArchive {
public:
  CourseArchive();
  virtual void init();
};

MultiDvdArchive* createMultiDvdArchive(SLoaderKind kind);

} // namespace System