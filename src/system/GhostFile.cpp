#include "GhostFile.hpp"

#include <rvl/mem/heapi.h>
#include <rvl/net.h>
#include <rvl/os/os.h>
#include <egg/core/eggCompress.hpp>
#include <egg/core/eggDecomp.hpp>

#include <decomp.h>

namespace System {

void RawGhostFile::reset() { memset(buffer, 0, sizeof(RawGhostFile)); }

bool RawGhostFile::isHeaderValid() const {
  if (fourcc != 'RKGD') {
    return false;
  }

  if (vehicleId >= 0x24) {
    return false;
  }

  if (characterId >= 0x30) {
    return false;
  }

  if (year > 99) {
    return false;
  }

  if (day > 31) {
    return false;
  }

  if (month > 12) {
    return false;
  }

  return true;
}

bool RawGhostFile::isValid() const {
  if (!isHeaderValid()) {
    return false;
  }

  if ((u32)isCompressed == true) {
    u32 size = 0x88 + 0x04 + compressedInputsSize;
    u32 actualCrc32 = NETCalcCRC32(buffer, size);
    u32 expectedCrc32 = *reinterpret_cast<const u32*>(buffer + size);
    return expectedCrc32 == actualCrc32;
  }

  u32 size = sizeof(buffer) - 0x4;
  u32 actualCrc32 = NETCalcCRC32(buffer, size);
  u32 expectedCrc32 = *reinterpret_cast<const u32*>(buffer + size);
  return expectedCrc32 == actualCrc32;
}

void RawGhostFile::updateCrc32Uncompressed() {
  u32 size = sizeof(buffer) - 0x4;
  u32 crc32 = NETCalcCRC32(buffer, size);
  *reinterpret_cast<u32*>(buffer + size) = crc32;
}

GhostFile::GhostFile() { reset(); }

Time::Time() : mIsValid(false) {
  mMinutes = 0;
  mSeconds = 0;
  mMilliseconds = 0;
}

GhostFile::GhostFile(const RawGhostFile& raw) {
  reset();

  if (readHeader(raw)) {
    mInputsSize = raw.inputsSize;
    mInputs = raw.buffer + 0x88;
  } else {
    mInputsSize = 0;
    mInputs = nullptr;
  }
}

void GhostFile::reset() {
  mHeaderIsValid = false;

  memset(mUserData, 0, sizeof(mUserData));
  mMii.reset();

  mLapCount = 0;
  for (u32 i = 0; i < 5; i++) {
    mLapTimes[i].setIsValid(false);
  }
  mRaceTime.setIsValid(false);

  mCharacterId = 0;
  mVehicleId = 0;
  mCourseId = 0;

  mInputsSize = 0;
  mInputs = nullptr;

  mDriftIsAuto = false;
}

bool GhostFile::readHeader_thunk(const RawGhostFile& raw) {
  return readHeader(raw);
}

bool GhostFile::readHeader(const RawGhostFile& raw) {
  mHeaderIsValid = false;

  if (raw.isHeaderValid()) {
    memset(mUserData, 0, sizeof(mUserData));
    memcpy(mUserData, raw.userData, sizeof(raw.userData));
    mUserData[11 - 1] = '\0';

    mDate.set(raw.year, raw.month, raw.day);

    mMii = raw.mii;

    mLapCount = raw.lapCount;
    for (u8 i = 0; i < mLapCount; i++) {
      u32 minutes = raw.lapTimes[i].minutes;
      u32 seconds = raw.lapTimes[i].seconds;
      u32 milliseconds = raw.lapTimes[i].milliseconds;
      mLapTimes[i].set(minutes, seconds, milliseconds);
      mLapTimes[i].setIsValid(true); // Redundant
    }
    mRaceTime.set(raw.raceMinutes, raw.raceSeconds, raw.raceMilliseconds);

    mCourseId = raw.courseId;
    mCharacterId = raw.characterId;
    mVehicleId = raw.vehicleId;
    mControllerId = raw.controllerId;
    mType = raw.type;
    mLocation = raw.location;
    mDriftIsAuto = !!raw.driftIsAuto;

    mHeaderIsValid = true;
  }

  return mHeaderIsValid;
}

bool GhostFile::read(const RawGhostFile& raw) {
  if (readHeader(raw)) {
    mInputsSize = raw.inputsSize;
    mInputs = raw.buffer + 0x88;
  } else {
    mInputsSize = 0;
    mInputs = nullptr;
  }

  return mHeaderIsValid;
}

void GhostFile::writeHeader(RawGhostFile& raw) const {
  memcpy(raw.userData, mUserData, sizeof(raw.userData));

  raw.year = mDate.getYear();
  raw.month = mDate.getMonth();
  raw.day = mDate.getDay();

  raw.mii = mMii;

  raw.lapCount = mLapCount;
  for (u8 i = 0; i < raw.lapCount; i++) {
    raw.lapTimes[i].minutes = mLapTimes[i].getClampedMinutes();
    raw.lapTimes[i].seconds = mLapTimes[i].getClampedSeconds();
    raw.lapTimes[i].milliseconds = mLapTimes[i].getClampedMilliseconds();
  }
  raw.raceMinutes = mRaceTime.getClampedMinutes();
  raw.raceSeconds = mRaceTime.getClampedSeconds();
  raw.raceMilliseconds = mRaceTime.getClampedMilliseconds();

  raw.courseId = mCourseId;
  raw.characterId = mCharacterId;
  raw.vehicleId = mVehicleId;
  raw.controllerId = mControllerId;
  raw.driftIsAuto = mDriftIsAuto;
  raw.location = mLocation;
  raw.type = mType;
  raw.fourcc = 'RKGD';
}

bool GhostFile::writeHeaderUncompressed(RawGhostFile& raw) const {
  bool ret = false;
  bool isValid = mHeaderIsValid && mInputs != nullptr;

  if (isValid) {
    writeHeader(raw);
    raw.updateCrc32Uncompressed();

    ret = true;
  }

  return ret;
}

bool GhostFile::writeUncompressed(RawGhostFile& raw) const {
  bool ret = false;
  bool isValid = mHeaderIsValid && mInputs != nullptr;

  if (isValid) {
    writeHeader(raw);
    raw.inputsSize = mInputsSize;
    memcpy(raw.buffer + 0x88, mInputs, sizeof(raw.buffer) - (0x88 + 0x4));
    raw.updateCrc32Uncompressed();

    ret = true;
  }

  return ret;
}

void GhostFile::init(u8 playerId) {
  mLapCount = getLapCount();
  Time raceTime = Time();
  raceTime.set(0, 0, 0, false);
}

GhostFileGroup::GhostFileGroup(EGG::Heap* heap, s32 type) {
  switch (type) {
  case GHOST_GROUP_TYPE_SAVED:
    mCount = 32;
    break;
  case GHOST_GROUP_TYPE_DOWNLOADED:
    mCount = 32;
    break;
  case GHOST_GROUP_TYPE_SLOW_STAFF:
  case GHOST_GROUP_TYPE_FAST_STAFF:
    mCount = 32;
    break;
  case GHOST_GROUP_TYPE_COMPETITION:
    mCount = 1;
    break;
  default:
    mCount = 0;
    break;
  }
  mType = type;
  mFiles = new (heap, 4) GhostFile[mCount];
  _10 = new (heap, 4) bool[mCount];
}

GhostFileGroup::~GhostFileGroup() { delete[] mFiles; }

void GhostFileGroup::invalidate(u16 idx) {
  if (idx >= mCount) {
    return;
  }

  mFiles[idx].invalidate();
}

GhostFile* GhostFileGroup::get(u16 idx) {
  if (idx >= mCount) {
    return nullptr;
  }

#ifdef NON_MATCHING
  bool isValid = mFiles[idx].isHeaderValid;
#else
  bool isValid = ((u8*)mFiles)[idx * 0xd8];
#endif
  if (!isValid) {
    return nullptr;
  }

  return mFiles + idx;
}

void GhostFileGroup::readHeader(u16 idx, const RawGhostFile& raw) {
  if (idx >= mCount) {
    return;
  }

  mFiles[idx].readHeader(raw);
}

bool RawGhostFile::compress(const RawGhostFile& src, RawGhostFile& dst) {
  if ((u32)src.isCompressed == true) {
    dst.fourcc = 0;
    return false;
  }

  // Copy over RKG header
  dst.reset();
  memcpy(dst.buffer, src.buffer, 0x88);

  dst.isCompressed = true;
  const u8* srcInputsStart = src.buffer + 0x88;
  // The destination inputs start 4 bytes earlier to include YAZ1 magic
  u8* dstInputsStart = dst.buffer + 0x8c;
  int compressedSize =
      EGG::encodeSZS(srcInputsStart, dstInputsStart, src.inputsSize);

  if (compressedSize <= 0) {
    dst.fourcc = 0;
    return false;
  }

  // Compressed data is padded to multiple of 4 bytes in length
  u32 paddedCompressedSize = fastceil_u32(compressedSize, 0x4);
  dst.compressedInputsSize = paddedCompressedSize;
  u32 fileCRC32 = NETCalcCRC32(dst.buffer, paddedCompressedSize + 0x8c);

#ifdef NON_MATCHING
  *reinterpret_cast<u32*>(inputsStart + paddedCompressedSize) = fileCRC32;
#else
  *reinterpret_cast<u32*>(dstInputsStart + fastceil_u32(compressedSize, 0x4)) =
      fileCRC32;
#endif

  return true;
}

bool RawGhostFile::decompress(const RawGhostFile& src, RawGhostFile& dst) {
  if ((u32)src.isCompressed != true) {
    dst.fourcc = 0;
    return false;
  }

  if (!src.isValid()) {
    dst.fourcc = 0;
    return false;
  }

  dst.reset();
  memcpy(dst.buffer, src.buffer, 0x88);
  dst.isCompressed = false;

  s32 expandSize = EGG::Decomp::getExpandSize(src.buffer + 0x8c);
  if (expandSize == 0 || expandSize > sizeof(src.buffer) - 0x8c) {
    dst.fourcc = 0;
    return false;
  }

  EGG::Decomp::decodeSZS(src.buffer + 0x8c, dst.buffer + 0x88);
  dst.inputsSize = expandSize;
  u32 fileCRC32 = NETCalcCRC32(dst.buffer, sizeof(dst.buffer) - 0x4);
  *reinterpret_cast<u32*>(dst.buffer + sizeof(dst.buffer) - 0x4) = fileCRC32;
  return true;
}

u32 RawGhostFile::getSize() const {
  if (!isValid()) {
    return nullptr;
  }

  if ((u32)isCompressed == true) {
    return compressedInputsSize + 0x90;
  }

  return sizeof(buffer);
}

} // namespace System
