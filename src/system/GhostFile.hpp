#pragma once

#include "system/Mii.hpp"

#include <egg/core/eggHeap.hpp>

#include <rk_types.h>

namespace System {

class Time {
public:
  Time();

#pragma warn_unusedvar on
  virtual ~Time() { u8 i; } // Trust me bro
#pragma warn_unusedvar off

  u16 getClampedMinutes() const {
    if (mMinutes > 99) {
      return 99;
    }

    return mMinutes;
  }

  u16 getClampedSeconds() const {
    if (mMinutes > 99) {
      return 59;
    }

    return mSeconds;
  }

  u16 getClampedMilliseconds() const {
    if (mMinutes > 99) {
      return 999;
    }

    return mMilliseconds;
  }

  void setIsValid(bool isValid) { mIsValid = isValid; }

  void set(u16 minutes, u8 seconds, u16 milliseconds, bool isValid = true) {
    mIsValid = isValid;
    mMinutes = minutes;
    mSeconds = seconds;
    mMilliseconds = milliseconds;
  }
  void set2(u16 minutes, u8 seconds, u16 milliseconds, bool isValid) {
    mMinutes = minutes;
    mSeconds = seconds;
    mMilliseconds = milliseconds;
    mIsValid = isValid;
  }

private:
  u16 mMinutes;
  u8 mSeconds;
  u16 mMilliseconds;
  bool mIsValid;
};

class Date {
public:
  Date() {
    mIsValid = false;

    clamp();

    mYear = 0;
    mMonth = 0;
    mDay = 0;
  }

  void set(u8 year, u8 month, u8 day) {
    mIsValid = true;

    clamp();

    mYear = year;
    mMonth = month;
    mDay = day;
  }

  u8 getYear() const { return mYear; }

  u8 getMonth() const { return mMonth; }

  u8 getDay() const { return mDay; }

private:
  void clamp() {
    if (mYear > 99) {
      mYear = 99;
    }

    if (mMonth > 12) {
      mMonth = 12;
    }

    if (mDay > 31) {
      mDay = 31;
    }
  }

  u8 mYear;
  u8 mMonth;
  u8 mDay;
  bool mIsValid;
};

MW_PRAG_PACKED
struct RawGhostFile {
  friend class GhostFile;

public:
  // RawGhostFile() { reset(); }

  //~RawGhostFile() {}

  void reset();

  bool isHeaderValid() const;

  bool isValid() const;

  static bool compress(const RawGhostFile& src, RawGhostFile& dst);

  static bool decompress(const RawGhostFile& src, RawGhostFile& dst);

  u32 getSize() const;

private:
  void updateCrc32Uncompressed();

  union {
    u8 buffer[0x2800];
    struct {
      u32 fourcc;

      u32 raceMinutes : 7;
      u32 raceSeconds : 7;
      u32 raceMilliseconds : 10;
      u32 courseId : 6;
      u32 _pad0 : 2;

      u32 vehicleId : 6;
      u32 characterId : 6;
      u32 year : 7;
      u32 month : 4;
      u32 day : 5;
      u32 controllerId : 4;

      u16 _pad1 : 4;
      u16 isCompressed : 1;
      u16 _pad2 : 2;
      u16 type : 7;
      u16 driftIsAuto : 1;
      u16 _pad3 : 1;

      u16 inputsSize;
      u8 lapCount;
      struct {
        u32 minutes : 7;
        u32 seconds : 7;
        u32 milliseconds : 10;
      } lapTimes[5];
      wchar_t userData[10];
      u32 location;
      u32 _38;
      RawMii mii;

      u32 compressedInputsSize;
    };
  };
};
MW_PRAG_END

class GhostFile {
  friend class GhostFileGroup;

public:
  GhostFile();

  GhostFile(const RawGhostFile& raw);

  bool read(const RawGhostFile& raw);

  bool writeHeaderUncompressed(RawGhostFile& raw) const;

  bool writeUncompressed(RawGhostFile& raw) const;

  void init(u8 playerId);

  bool isValid() const { return mHeaderIsValid; }

  void invalidate() { mHeaderIsValid = false; }

  u8 getLapCount() const { return mLapCount; }

private:
  void reset();

  bool readHeader_thunk(const RawGhostFile& raw); // Unused

  bool readHeader(const RawGhostFile& raw);

  void writeHeader(RawGhostFile& raw) const;

public:
  bool mHeaderIsValid;
  wchar_t mUserData[11];
  RawMii mMii;
  u8 mLapCount;
  Time mLapTimes[5];
  Time mRaceTime;
  u32 mCharacterId;
  u32 mVehicleId;
  s32 mCourseId;
  u32 mControllerId;
  Date mDate;
  u32 mType;
  bool mDriftIsAuto;
  u32 mLocation;
  u32 mInputsSize;
  const u8* mInputs;
};

class GhostFileGroup {
public:
  enum GhostGroupType {
    GHOST_GROUP_TYPE_SAVED = 0x0,
    GHOST_GROUP_TYPE_DOWNLOADED = 0x1,
    GHOST_GROUP_TYPE_SLOW_STAFF = 0x2,
    GHOST_GROUP_TYPE_FAST_STAFF = 0x3,
    GHOST_GROUP_TYPE_GHOST_RACE = 0x4,
    GHOST_GROUP_TYPE_COMPETITION = 0x5
  };

  GhostFileGroup(EGG::Heap* heap, s32 type);

  virtual ~GhostFileGroup();

  void invalidate(u16 idx);

  GhostFile* get(u16 idx);

  void readHeader(u16 idx, const RawGhostFile& raw);

private:
  u16 mCount;
  s32 mType;
  GhostFile* mFiles;
  bool* _10;
};

} // namespace System
