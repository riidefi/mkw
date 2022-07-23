#include "GhostFile.hpp"

#include <rvl/mem/heapi.h>
#include <rvl/net.h>
#include <rvl/os/os.h>
#include <egg/core/eggCompress.hpp>

#include <decomp.h>

// Extern function references.
// PAL: 0x8052758c
extern "C" UNKNOWN_FUNCTION(unk_8052758c);
// PAL: 0x805336a4
extern "C" UNKNOWN_FUNCTION(unk_805336a4);
// PAL: 0x8053572c
extern "C" UNKNOWN_FUNCTION(unk_8053572c);
// PAL: 0x8054a9b8
extern "C" UNKNOWN_FUNCTION(unk_8054a9b8);

extern "C" UNKNOWN_FUNCTION(encodeSZS__Q23EGG4CompFPCUcPUcUl);
extern "C" UNKNOWN_FUNCTION(getExpandSize__Q23EGG6DecompFPUc);
extern "C" UNKNOWN_FUNCTION(decodeSZS__Q23EGG6DecompFPUcPUc);

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

Time::~Time() {}

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

#ifdef NON_MATCHING
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
#else
MARK_BINARY_BLOB(writeHeader__Q26System9GhostFileCFRQ26System12RawGhostFile,
                 0x8051c7f4, 0x8051ca0c);
asm void GhostFile::writeHeader(RawGhostFile& raw) const {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  li r5, 0x14;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r4;
  stw r30, 0x18(r1);
  mr r30, r3;
  addi r3, r4, 0x20;
  addi r4, r30, 2;
  bl memcpy;
  lbz r3, 0xc0(r30);
  li r0, 0x26;
  lwz r6, 8(r31);
  addi r5, r31, 0x3b;
  rlwimi r6, r3, 0xd, 0xc, 0x12;
  stw r6, 8(r31);
  addi r4, r30, 0x17;
  lbz r3, 0xc1(r30);
  rlwimi r6, r3, 9, 0x13, 0x16;
  stw r6, 8(r31);
  lbz r3, 0xc2(r30);
  rlwimi r6, r3, 4, 0x17, 0x1b;
  stw r6, 8(r31);
  mtctr r0;
lbl_8051c858:
  lbz r3, 1(r4);
  lbzu r0, 2(r4);
  stb r3, 1(r5);
  stbu r0, 2(r5);
  bdnz lbl_8051c858;
  lbz r0, 0x64(r30);
  li r7, 0;
  stb r0, 0x10(r31);
  cmpwi r0, 0;
  beq lbl_8051c928;
  b lbl_8051c918;
lbl_8051c884:
  clrlwi r0, r7, 0x18;
  li r3, 0x63;
  mulli r0, r0, 0xc;
  add r6, r30, r0;
  lhz r0, 0x6c(r6);
  cmplwi r0, 0x63;
  bgt lbl_8051c8a4;
  mr r3, r0;
lbl_8051c8a4:
  lhz r0, 0x6c(r6);
  rlwinm r4, r3, 0x11, 8, 0xe;
  cmplwi r0, 0x63;
  ble lbl_8051c8bc;
  li r3, 0x3b;
  b lbl_8051c8c0;
lbl_8051c8bc:
  lbz r3, 0x6e(r6);
lbl_8051c8c0:
  lhz r0, 0x6c(r6);
  rlwinm r3, r3, 0xa, 0xf, 0x15;
  or r5, r4, r3;
  cmplwi r0, 0x63;
  ble lbl_8051c8dc;
  li r0, 0x3e7;
  b lbl_8051c8e0;
lbl_8051c8dc:
  lhz r0, 0x70(r6);
lbl_8051c8e0:
  clrlwi r4, r0, 0x16;
  clrlwi r3, r7, 0x18;
  rlwinm r0, r7, 2, 0x16, 0x1d;
  addi r7, r7, 1;
  or r4, r5, r4;
  stw r4, 8(r1);
  subf r0, r3, r0;
  add r3, r31, r0;
  lbz r0, 9(r1);
  stb r0, 0x11(r3);
  lbz r0, 0xa(r1);
  stb r0, 0x12(r3);
  lbz r0, 0xb(r1);
  stb r0, 0x13(r3);
lbl_8051c918:
  lbz r0, 0x10(r31);
  clrlwi r3, r7, 0x18;
  cmplw r3, r0;
  blt lbl_8051c884;
lbl_8051c928:
  lhz r0, 0xa8(r30);
  li r3, 0x63;
  cmplwi r0, 0x63;
  bgt lbl_8051c93c;
  mr r3, r0;
lbl_8051c93c:
  lwz r0, 4(r31);
  rlwimi r0, r3, 0x19, 0, 6;
  stw r0, 4(r31);
  lhz r0, 0xa8(r30);
  cmplwi r0, 0x63;
  ble lbl_8051c95c;
  li r3, 0x3b;
  b lbl_8051c960;
lbl_8051c95c:
  lbz r3, 0xaa(r30);
lbl_8051c960:
  lwz r0, 4(r31);
  rlwimi r0, r3, 0x12, 7, 0xd;
  stw r0, 4(r31);
  lhz r0, 0xa8(r30);
  cmplwi r0, 0x63;
  ble lbl_8051c980;
  li r0, 0x3e7;
  b lbl_8051c984;
lbl_8051c980:
  lhz r0, 0xac(r30);
lbl_8051c984:
  lwz r7, 4(r31);
  rlwimi r7, r0, 8, 0xe, 0x17;
  stw r7, 4(r31);
  lis r3, 0x524b;
  addi r0, r3, 0x4744;
  lwz r5, 8(r31);
  lwz r6, 0xb8(r30);
  lhz r4, 0xc(r31);
  rlwimi r7, r6, 2, 0x18, 0x1d;
  stw r7, 4(r31);
  lwz r3, 0xb0(r30);
  rlwimi r5, r3, 0x14, 6, 0xb;
  stw r5, 8(r31);
  lwz r3, 0xb4(r30);
  rlwimi r5, r3, 0x1a, 0, 5;
  stw r5, 8(r31);
  lwz r3, 0xbc(r30);
  rlwimi r5, r3, 0, 0x1c, 0x1f;
  stw r5, 8(r31);
  lbz r3, 0xc8(r30);
  rlwimi r4, r3, 1, 0x1e, 0x1e;
  sth r4, 0xc(r31);
  lwz r3, 0xcc(r30);
  stw r3, 0x34(r31);
  lwz r3, 0xc4(r30);
  rlwimi r4, r3, 2, 0x17, 0x1d;
  sth r4, 0xc(r31);
  stw r0, 0(r31);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}
#endif

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

MARK_BINARY_BLOB(init__Q26System9GhostFileFUc, 0x8051cb1c, 0x8051ce7c);
asm void GhostFile::init(u8 playerId) {
  // clang-format off
  nofralloc;
  stwu r1, -0x70(r1);
  mflr r0;
  stw r0, 0x74(r1);
  stmw r27, 0x5c(r1);
  lis r31, 0;
  mr r29, r3;
  mr r30, r4;
  lwz r3, 0(r31);
  bl unk_805336a4;
  stb r3, 0x64(r29);
  li r0, 0;
  lis r4, 0;
  lis r3, 0;
  addi r4, r4, 0;
  stw r4, 0x18(r1);
  lwz r3, 0(r3);
  stb r0, 0x22(r1);
  sth r0, 0x1c(r1);
  stb r0, 0x1e(r1);
  sth r0, 0x20(r1);
  lwz r0, 0xb90(r3);
  rlwinm. r0, r0, 0, 0x1d, 0x1d;
  bne lbl_8051cbe0;
  rlwinm r28, r30, 2, 0x16, 0x1d;
  li r27, 0;
  b lbl_8051cbd0;
lbl_8051cb84:
  lwz r3, 0(r31);
  addi r0, r27, 1;
  clrlwi r4, r0, 0x18;
  addi r5, r1, 0x18;
  lwz r0, 0xc(r3);
  lwzx r3, r28, r0;
  bl unk_8053572c;
  clrlwi r3, r27, 0x18;
  lhz r0, 0x1c(r1);
  mulli r3, r3, 0xc;
  addi r27, r27, 1;
  add r3, r29, r3;
  sth r0, 0x6c(r3);
  lbz r0, 0x1e(r1);
  stb r0, 0x6e(r3);
  lhz r0, 0x20(r1);
  sth r0, 0x70(r3);
  lbz r0, 0x22(r1);
  stb r0, 0x72(r3);
lbl_8051cbd0:
  lbz r0, 0x64(r29);
  clrlwi r3, r27, 0x18;
  cmplw r3, r0;
  blt lbl_8051cb84;
lbl_8051cbe0:
  lis r3, 0;
  rlwinm r0, r30, 2, 0x16, 0x1d;
  lwz r3, 0(r3);
  mulli r31, r30, 0xf0;
  lis r5, 0;
  lwz r4, 0xc(r3);
  lis r3, 0;
  lwzx r4, r4, r0;
  lwz r6, 0x40(r4);
  lhz r4, 4(r6);
  sth r4, 0x1c(r1);
  lbz r0, 6(r6);
  stb r0, 0x1e(r1);
  lhz r0, 8(r6);
  sth r0, 0x20(r1);
  lbz r0, 0xa(r6);
  stb r0, 0x22(r1);
  sth r4, 0xa8(r29);
  lbz r0, 0x1e(r1);
  stb r0, 0xaa(r29);
  lhz r0, 0x20(r1);
  sth r0, 0xac(r29);
  lbz r0, 0x22(r1);
  stb r0, 0xae(r29);
  lwz r0, 0(r5);
  add r4, r0, r31;
  lwz r0, 0x34(r4);
  stw r0, 0xb0(r29);
  lwz r0, 0(r5);
  add r4, r0, r31;
  lwz r0, 0x30(r4);
  stw r0, 0xb4(r29);
  lwz r4, 0(r5);
  lwz r0, 0xb68(r4);
  stw r0, 0xb8(r29);
  lwz r3, 0(r3);
  lwz r3, 8(r3);
  cmpwi r3, 0;
  beq lbl_8051cc90;
  lwz r12, 0(r3);
  lwz r12, 0x10(r12);
  mtctr r12;
  bctrl;
  b lbl_8051cc94;
lbl_8051cc90:
  li r3, -1;
lbl_8051cc94:
  stw r3, 0xbc(r29);
  lis r3, 0;
  lwz r3, 0(r3);
  lwz r3, 8(r3);
  cmpwi r3, 0;
  beq lbl_8051ccb4;
  lbz r3, 0x51(r3);
  b lbl_8051ccb8;
lbl_8051ccb4:
  li r3, 0;
lbl_8051ccb8:
  li r0, 1;
  stb r3, 0xc8(r29);
  stw r0, 0xc4(r29);
  bl OSGetTime;
  addi r5, r1, 0x28;
  bl OSTicksToCalendarTime;
  lwz r3, 0x3c(r1);
  cmpwi r3, 0x7d0;
  bge lbl_8051cce8;
  li r0, 0x7d0;
  stw r0, 0x3c(r1);
  b lbl_8051ccf0;
lbl_8051cce8:
  addi r0, r3, -2000;
  stw r0, 0x3c(r1);
lbl_8051ccf0:
  lwz r0, 0x3c(r1);
  cmpwi r0, 0x63;
  ble lbl_8051cd04;
  li r0, 0x63;
  stw r0, 0x3c(r1);
lbl_8051cd04:
  lbz r0, 0xc0(r29);
  li r3, 1;
  lwz r5, 0x34(r1);
  lwz r4, 0x38(r1);
  cmplwi r0, 0x63;
  lwz r0, 0x3c(r1);
  clrlwi r5, r5, 0x18;
  addi r4, r4, 1;
  stb r3, 0xc3(r29);
  clrlwi r6, r4, 0x18;
  clrlwi r3, r0, 0x18;
  ble lbl_8051cd3c;
  li r0, 0x63;
  stb r0, 0xc0(r29);
lbl_8051cd3c:
  lbz r0, 0xc1(r29);
  cmplwi r0, 0xc;
  ble lbl_8051cd50;
  li r0, 0xc;
  stb r0, 0xc1(r29);
lbl_8051cd50:
  lbz r0, 0xc2(r29);
  cmplwi r0, 0x1f;
  ble lbl_8051cd64;
  li r0, 0x1f;
  stb r0, 0xc2(r29);
lbl_8051cd64:
  stb r3, 0xc0(r29);
  lis r3, 0;
  addi r4, r1, 8;
  stb r6, 0xc1(r29);
  stb r5, 0xc2(r29);
  lwz r3, 0(r3);
  bl unk_8054a9b8;
  lwz r0, 8(r1);
  lis r3, 0;
  stw r0, 0xcc(r29);
  lwz r0, 0(r3);
  add r4, r0, r31;
  lbz r0, 0xcd0(r4);
  cmpwi r0, 0;
  beq lbl_8051cde8;
  lbz r3, 0xcc0(r4);
  li r5, 1;
  lbz r0, 0xcc1(r4);
  stb r0, 0x11(r1);
  stb r3, 0x10(r1);
  lbz r3, 0xcc2(r4);
  lbz r0, 0xcc3(r4);
  stb r0, 0x13(r1);
  stb r3, 0x12(r1);
  lbz r3, 0xcc4(r4);
  lbz r0, 0xcc5(r4);
  stb r0, 0x15(r1);
  stb r3, 0x14(r1);
  lbz r3, 0xcc6(r4);
  lbz r0, 0xcc7(r4);
  stb r0, 0x17(r1);
  stb r3, 0x16(r1);
  b lbl_8051cdec;
lbl_8051cde8:
  li r5, 0;
lbl_8051cdec:
  cmpwi r5, 0;
  beq lbl_8051ce00;
  addi r3, r29, 0x18;
  addi r4, r1, 0x10;
  bl unk_8052758c;
lbl_8051ce00:
  lis r3, 0;
  lwz r0, 0(r3);
  add r3, r0, r31;
  lbz r0, 0x2e(r3);
  extsb. r0, r0;
  blt lbl_8051ce60;
  clrlwi r0, r0, 0x18;
  lis r3, 0;
  mulli r0, r0, 0xec;
  lwz r3, 0(r3);
  add r3, r3, r0;
  addi r30, r3, 4;
  lwz r12, 0(r30);
  mr r3, r30;
  lwz r12, 0x18(r12);
  mtctr r12;
  bctrl;
  stw r3, 0xd4(r29);
  mr r3, r30;
  lwz r12, 0(r30);
  lwz r12, 0x1c(r12);
  mtctr r12;
  bctrl;
  stw r3, 0xd0(r29);
lbl_8051ce60:
  li r0, 1;
  stb r0, 0(r29);
  lmw r27, 0x5c(r1);
  lwz r0, 0x74(r1);
  mtlr r0;
  addi r1, r1, 0x70;
  blr;
  // clang-format on
}

// Symbol: Controller_vf10
// PAL: 0x8051ce7c..0x8051ce84
MARK_BINARY_BLOB(Controller_vf10, 0x8051ce7c, 0x8051ce84);
asm UNKNOWN_FUNCTION(Controller_vf10) {
  // clang-format off
  nofralloc;
  li r3, -1;
  blr;
  // clang-format on
}

// Symbol: Input_vf18
// PAL: 0x8051ce84..0x8051ce8c
MARK_BINARY_BLOB(Input_vf18, 0x8051ce84, 0x8051ce8c);
asm UNKNOWN_FUNCTION(Input_vf18) {
  // clang-format off
  nofralloc;
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: Input_vf1c
// PAL: 0x8051ce8c..0x8051ce94
MARK_BINARY_BLOB(Input_vf1c, 0x8051ce8c, 0x8051ce94);
asm UNKNOWN_FUNCTION(Input_vf1c) {
  // clang-format off
  nofralloc;
  li r3, 0;
  blr;
  // clang-format on
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

  return true
}

MARK_BINARY_BLOB(
    decompress__Q26System12RawGhostFileFRCQ26System12RawGhostFileRQ26System12RawGhostFile,
    0x8051d1b4, 0x8051d388);
asm bool RawGhostFile::decompress(const RawGhostFile& src, RawGhostFile& dst) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r4;
  stw r30, 0x18(r1);
  mr r30, r3;
  stw r29, 0x14(r1);
  lhz r0, 0xc(r3);
  rlwinm r6, r0, 0x15, 0x1f, 0x1f;
  cmplwi r6, 1;
  beq lbl_8051d1f4;
  li r0, 0;
  stw r0, 0(r4);
  li r3, 0;
  b lbl_8051d36c;
lbl_8051d1f4:
  lwz r4, 0(r3);
  addis r0, r4, 0xadb5;
  cmplwi r0, 0x4744;
  beq lbl_8051d20c;
  li r0, 0;
  b lbl_8051d27c;
lbl_8051d20c:
  lwz r4, 8(r3);
  srwi r0, r4, 0x1a;
  cmplwi r0, 0x24;
  blt lbl_8051d224;
  li r0, 0;
  b lbl_8051d27c;
lbl_8051d224:
  rlwinm r0, r4, 0xc, 0x1a, 0x1f;
  cmplwi r0, 0x30;
  blt lbl_8051d238;
  li r0, 0;
  b lbl_8051d27c;
lbl_8051d238:
  rlwinm r0, r4, 0x13, 0x19, 0x1f;
  cmplwi r0, 0x63;
  ble lbl_8051d24c;
  li r0, 0;
  b lbl_8051d27c;
lbl_8051d24c:
  rlwinm r0, r4, 0x1c, 0x1b, 0x1f;
  cmplwi r0, 0x1f;
  ble lbl_8051d260;
  li r0, 0;
  b lbl_8051d27c;
lbl_8051d260:
  rlwinm r5, r4, 0x17, 0x1c, 0x1f;
  li r4, 0xc;
  subfic r0, r5, 0xc;
  orc r4, r4, r5;
  srwi r0, r0, 1;
  subf r0, r0, r4;
  srwi r0, r0, 0x1f;
lbl_8051d27c:
  cmpwi r0, 0;
  bne lbl_8051d28c;
  li r0, 0;
  b lbl_8051d2d8;
lbl_8051d28c:
  cmplwi r6, 1;
  bne lbl_8051d2bc;
  lwz r4, 0x88(r3);
  mr r3, r30;
  addi r29, r4, 0x8c;
  mr r4, r29;
  bl NETCalcCRC32;
  lwzx r0, r30, r29;
  subf r0, r0, r3;
  cntlzw r0, r0;
  srwi r0, r0, 5;
  b lbl_8051d2d8;
lbl_8051d2bc:
  mr r3, r30;
  li r4, 0x27fc;
  bl NETCalcCRC32;
  lwz r0, 0x27fc(r30);
  subf r0, r0, r3;
  cntlzw r0, r0;
  srwi r0, r0, 5;
lbl_8051d2d8:
  cmpwi r0, 0;
  bne lbl_8051d2f0;
  li r0, 0;
  stw r0, 0(r31);
  li r3, 0;
  b lbl_8051d36c;
lbl_8051d2f0:
  mr r3, r31;
  li r4, 0;
  li r5, 0x2800;
  bl memset;
  mr r3, r31;
  mr r4, r30;
  li r5, 0x88;
  bl memcpy;
  lhz r0, 0xc(r31);
  addi r3, r30, 0x8c;
  rlwinm r0, r0, 0, 0x15, 0x13;
  sth r0, 0xc(r31);
  bl getExpandSize__Q23EGG6DecompFPUc;
  cmpwi r3, 0;
  mr r29, r3;
  beq lbl_8051d338;
  cmplwi r3, 0x2774;
  ble lbl_8051d348;
lbl_8051d338:
  li r0, 0;
  stw r0, 0(r31);
  li r3, 0;
  b lbl_8051d36c;
lbl_8051d348:
  addi r3, r30, 0x8c;
  addi r4, r31, 0x88;
  bl decodeSZS__Q23EGG6DecompFPUcPUc;
  sth r29, 0xe(r31);
  mr r3, r31;
  li r4, 0x27fc;
  bl NETCalcCRC32;
  stw r3, 0x27fc(r31);
  li r3, 1;
lbl_8051d36c:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
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
