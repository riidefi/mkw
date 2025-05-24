#include "GhostFile.hpp"

#include <rvl/mem/heapi.h>
#include <rvl/net.h>
#include <rvl/os/os.h>
#include <egg/core/eggCompress.hpp>
#include <egg/core/eggDecomp.hpp>

#include <decomp.h>

// Extern function references.
// PAL: 0x8052758c
extern "C" UNKNOWN_FUNCTION(unk_8052758c);
// PAL: 0x805336a4
extern "C" u8 getLapCount();
// PAL: 0x8053572c
extern "C" UNKNOWN_FUNCTION(RaceinfoPlayer_getLapSplit);
// PAL: 0x8054a9b8
extern "C" UNKNOWN_FUNCTION(SaveManager_getLocation);
extern "C" UNKNOWN_DATA(spInstance__Q26System11RaceManager);
extern "C" UNKNOWN_DATA(__vt__Q26System4Time);
extern "C" UNKNOWN_DATA(spInstance__Q26System10RaceConfig);
extern "C" UNKNOWN_DATA(spInstance__Q26System12KPadDirector);
extern "C" UNKNOWN_DATA(lbl_809bd748);

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

#if 0
void GhostFile::init(u8 playerId) {
  mLapCount = getLapCount();
  Time raceTime = Time();
  raceTime.set(0, 0, 0, false);
}
#else
MARK_BINARY_BLOB(init__Q26System9GhostFileFUc, 0x8051cb1c, 0x8051ce7c);
asm void GhostFile::init(u8 playerId) {
  // clang-format off
  nofralloc;
/* 8051CB1C 9421FF90 */ stwu        r1, -0x70(r1)
/* 8051CB20 7C0802A6 */ mflr        r0
/* 8051CB24 90010074 */ stw         r0, 0x74(r1)
/* 8051CB28 BF61005C */ stmw        r27, 0x5c(r1)
/* 8051CB2C 3FE0809C */ lis         r31, spInstance__Q26System11RaceManager@ha
/* 8051CB30 7C7D1B78 */ mr          r29, r3
/* 8051CB34 7C9E2378 */ mr          r30, r4
/* 8051CB38 807FD730 */ lwz         r3, spInstance__Q26System11RaceManager@l(r31)
/* 8051CB3C 48016B69 */ bl          getLapCount
/* 8051CB40 987D0064 */ stb         r3, 0x64(r29)
/* 8051CB44 38000000 */ li          r0, 0x0
/* 8051CB48 3C80808B */ lis         r4, __vt__Q26System4Time@ha
/* 8051CB4C 3C60809C */ lis         r3, spInstance__Q26System10RaceConfig@ha
/* 8051CB50 38842D44 */ addi        r4, r4, __vt__Q26System4Time@l
/* 8051CB54 90810018 */ stw         r4, 0x18(r1)
/* 8051CB58 8063D728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r3)
/* 8051CB5C 98010022 */ stb         r0, 0x22(r1)
/* 8051CB60 B001001C */ sth         r0, 0x1c(r1)
/* 8051CB64 9801001E */ stb         r0, 0x1e(r1)
/* 8051CB68 B0010020 */ sth         r0, 0x20(r1)
/* 8051CB6C 80030B90 */ lwz         r0, 0xb90(r3)
/* 8051CB70 5400077B */ rlwinm.     r0, r0, 0, 0x1d, 0x1d
/* 8051CB74 4082006C */ bne-        lbl_8051cbe0
/* 8051CB78 57DC15BA */ rlwinm      r28, r30, 2, 0x16, 0x1d
/* 8051CB7C 3B600000 */ li          r27, 0x0
/* 8051CB80 48000050 */ b           lbl_8051cbd0
lbl_8051cb84:
/* 8051CB84 807FD730 */ lwz         r3, spInstance__Q26System11RaceManager@l(r31)
/* 8051CB88 381B0001 */ addi        r0, r27, 0x1
/* 8051CB8C 5404063E */ clrlwi      r4, r0, 0x18
/* 8051CB90 38A10018 */ addi        r5, r1, 0x18
/* 8051CB94 8003000C */ lwz         r0, 0xc(r3)
/* 8051CB98 7C7C002E */ lwzx        r3, r28, r0
/* 8051CB9C 48018B91 */ bl          RaceinfoPlayer_getLapSplit
/* 8051CBA0 5763063E */ clrlwi      r3, r27, 0x18
/* 8051CBA4 A001001C */ lhz         r0, 0x1c(r1)
/* 8051CBA8 1C63000C */ mulli       r3, r3, 0xc
/* 8051CBAC 3B7B0001 */ addi        r27, r27, 0x1
/* 8051CBB0 7C7D1A14 */ add         r3, r29, r3
/* 8051CBB4 B003006C */ sth         r0, 0x6c(r3)
/* 8051CBB8 8801001E */ lbz         r0, 0x1e(r1)
/* 8051CBBC 9803006E */ stb         r0, 0x6e(r3)
/* 8051CBC0 A0010020 */ lhz         r0, 0x20(r1)
/* 8051CBC4 B0030070 */ sth         r0, 0x70(r3)
/* 8051CBC8 88010022 */ lbz         r0, 0x22(r1)
/* 8051CBCC 98030072 */ stb         r0, 0x72(r3)
lbl_8051cbd0:
/* 8051CBD0 881D0064 */ lbz         r0, 0x64(r29)
/* 8051CBD4 5763063E */ clrlwi      r3, r27, 0x18
/* 8051CBD8 7C030040 */ cmplw       r3, r0
/* 8051CBDC 4180FFA8 */ blt+        lbl_8051cb84
lbl_8051cbe0:
/* 8051CBE0 3C60809C */ lis         r3, spInstance__Q26System11RaceManager@ha
/* 8051CBE4 57C015BA */ rlwinm      r0, r30, 2, 0x16, 0x1d
/* 8051CBE8 8063D730 */ lwz         r3, spInstance__Q26System11RaceManager@l(r3)
/* 8051CBEC 1FFE00F0 */ mulli       r31, r30, 0xf0
/* 8051CBF0 3CA0809C */ lis         r5, spInstance__Q26System10RaceConfig@ha
/* 8051CBF4 8083000C */ lwz         r4, 0xc(r3)
/* 8051CBF8 3C60809C */ lis         r3, spInstance__Q26System12KPadDirector@ha
/* 8051CBFC 7C84002E */ lwzx        r4, r4, r0
/* 8051CC00 80C40040 */ lwz         r6, 0x40(r4)
/* 8051CC04 A0860004 */ lhz         r4, 4(r6)
/* 8051CC08 B081001C */ sth         r4, 0x1c(r1)
/* 8051CC0C 88060006 */ lbz         r0, 6(r6)
/* 8051CC10 9801001E */ stb         r0, 0x1e(r1)
/* 8051CC14 A0060008 */ lhz         r0, 8(r6)
/* 8051CC18 B0010020 */ sth         r0, 0x20(r1)
/* 8051CC1C 8806000A */ lbz         r0, 0xa(r6)
/* 8051CC20 98010022 */ stb         r0, 0x22(r1)
/* 8051CC24 B09D00A8 */ sth         r4, 0xa8(r29)
/* 8051CC28 8801001E */ lbz         r0, 0x1e(r1)
/* 8051CC2C 981D00AA */ stb         r0, 0xaa(r29)
/* 8051CC30 A0010020 */ lhz         r0, 0x20(r1)
/* 8051CC34 B01D00AC */ sth         r0, 0xac(r29)
/* 8051CC38 88010022 */ lbz         r0, 0x22(r1)
/* 8051CC3C 981D00AE */ stb         r0, 0xae(r29)
/* 8051CC40 8005D728 */ lwz         r0, spInstance__Q26System10RaceConfig@l(r5)
/* 8051CC44 7C80FA14 */ add         r4, r0, r31
/* 8051CC48 80040034 */ lwz         r0, 0x34(r4)
/* 8051CC4C 901D00B0 */ stw         r0, 0xb0(r29)
/* 8051CC50 8005D728 */ lwz         r0, spInstance__Q26System10RaceConfig@l(r5)
/* 8051CC54 7C80FA14 */ add         r4, r0, r31
/* 8051CC58 80040030 */ lwz         r0, 0x30(r4)
/* 8051CC5C 901D00B4 */ stw         r0, 0xb4(r29)
/* 8051CC60 8085D728 */ lwz         r4, spInstance__Q26System10RaceConfig@l(r5)
/* 8051CC64 80040B68 */ lwz         r0, 0xb68(r4)
/* 8051CC68 901D00B8 */ stw         r0, 0xb8(r29)
/* 8051CC6C 8063D70C */ lwz         r3, spInstance__Q26System12KPadDirector@l(r3)
/* 8051CC70 80630008 */ lwz         r3, 8(r3)
/* 8051CC74 2C030000 */ cmpwi       r3, 0x0
/* 8051CC78 41820018 */ beq-        lbl_8051cc90
/* 8051CC7C 81830000 */ lwz         r12, 0(r3)
/* 8051CC80 818C0010 */ lwz         r12, 0x10(r12)
/* 8051CC84 7D8903A6 */ mtctr       r12
/* 8051CC88 4E800421 */ bctrl
/* 8051CC8C 48000008 */ b           lbl_8051cc94
lbl_8051cc90:
/* 8051CC90 3860FFFF */ li          r3, -0x1
lbl_8051cc94:
/* 8051CC94 907D00BC */ stw         r3, 0xbc(r29)
/* 8051CC98 3C60809C */ lis         r3, spInstance__Q26System12KPadDirector@ha
/* 8051CC9C 8063D70C */ lwz         r3, spInstance__Q26System12KPadDirector@l(r3)
/* 8051CCA0 80630008 */ lwz         r3, 8(r3)
/* 8051CCA4 2C030000 */ cmpwi       r3, 0x0
/* 8051CCA8 4182000C */ beq-        lbl_8051ccb4
/* 8051CCAC 88630051 */ lbz         r3, 0x51(r3)
/* 8051CCB0 48000008 */ b           lbl_8051ccb8
lbl_8051ccb4:
/* 8051CCB4 38600000 */ li          r3, 0x0
lbl_8051ccb8:
/* 8051CCB8 38000001 */ li          r0, 0x1
/* 8051CCBC 987D00C8 */ stb         r3, 0xc8(r29)
/* 8051CCC0 901D00C4 */ stw         r0, 0xc4(r29)
/* 8051CCC4 4BC8E099 */ bl          OSGetTime
/* 8051CCC8 38A10028 */ addi        r5, r1, 0x28
/* 8051CCCC 4BC8E2DD */ bl          OSTicksToCalendarTime
/* 8051CCD0 8061003C */ lwz         r3, 0x3c(r1)
/* 8051CCD4 2C0307D0 */ cmpwi       r3, 0x7d0
/* 8051CCD8 40800010 */ bge-        lbl_8051cce8
/* 8051CCDC 380007D0 */ li          r0, 0x7d0
/* 8051CCE0 9001003C */ stw         r0, 0x3c(r1)
/* 8051CCE4 4800000C */ b           lbl_8051ccf0
lbl_8051cce8:
/* 8051CCE8 3803F830 */ addi        r0, r3, -0x7d0
/* 8051CCEC 9001003C */ stw         r0, 0x3c(r1)
lbl_8051ccf0:
/* 8051CCF0 8001003C */ lwz         r0, 0x3c(r1)
/* 8051CCF4 2C000063 */ cmpwi       r0, 0x63
/* 8051CCF8 4081000C */ ble-        lbl_8051cd04
/* 8051CCFC 38000063 */ li          r0, 0x63
/* 8051CD00 9001003C */ stw         r0, 0x3c(r1)
lbl_8051cd04:
/* 8051CD04 881D00C0 */ lbz         r0, 0xc0(r29)
/* 8051CD08 38600001 */ li          r3, 0x1
/* 8051CD0C 80A10034 */ lwz         r5, 0x34(r1)
/* 8051CD10 80810038 */ lwz         r4, 0x38(r1)
/* 8051CD14 28000063 */ cmplwi      r0, 0x63
/* 8051CD18 8001003C */ lwz         r0, 0x3c(r1)
/* 8051CD1C 54A5063E */ clrlwi      r5, r5, 0x18
/* 8051CD20 38840001 */ addi        r4, r4, 0x1
/* 8051CD24 987D00C3 */ stb         r3, 0xc3(r29)
/* 8051CD28 5486063E */ clrlwi      r6, r4, 0x18
/* 8051CD2C 5403063E */ clrlwi      r3, r0, 0x18
/* 8051CD30 4081000C */ ble-        lbl_8051cd3c
/* 8051CD34 38000063 */ li          r0, 0x63
/* 8051CD38 981D00C0 */ stb         r0, 0xc0(r29)
lbl_8051cd3c:
/* 8051CD3C 881D00C1 */ lbz         r0, 0xc1(r29)
/* 8051CD40 2800000C */ cmplwi      r0, 0xc
/* 8051CD44 4081000C */ ble-        lbl_8051cd50
/* 8051CD48 3800000C */ li          r0, 0xc
/* 8051CD4C 981D00C1 */ stb         r0, 0xc1(r29)
lbl_8051cd50:
/* 8051CD50 881D00C2 */ lbz         r0, 0xc2(r29)
/* 8051CD54 2800001F */ cmplwi      r0, 0x1f
/* 8051CD58 4081000C */ ble-        lbl_8051cd64
/* 8051CD5C 3800001F */ li          r0, 0x1f
/* 8051CD60 981D00C2 */ stb         r0, 0xc2(r29)
lbl_8051cd64:
/* 8051CD64 987D00C0 */ stb         r3, 0xc0(r29)
/* 8051CD68 3C60809C */ lis         r3, lbl_809bd748@ha
/* 8051CD6C 38810008 */ addi        r4, r1, 0x8
/* 8051CD70 98DD00C1 */ stb         r6, 0xc1(r29)
/* 8051CD74 98BD00C2 */ stb         r5, 0xc2(r29)
/* 8051CD78 8063D748 */ lwz         r3, lbl_809bd748@l(r3)
/* 8051CD7C 4802DC3D */ bl          SaveManager_getLocation
/* 8051CD80 80010008 */ lwz         r0, 8(r1)
/* 8051CD84 3C60809C */ lis         r3, spInstance__Q26System10RaceConfig@ha
/* 8051CD88 901D00CC */ stw         r0, 0xcc(r29)
/* 8051CD8C 8003D728 */ lwz         r0, spInstance__Q26System10RaceConfig@l(r3)
/* 8051CD90 7C80FA14 */ add         r4, r0, r31
/* 8051CD94 88040CD0 */ lbz         r0, 0xcd0(r4)
/* 8051CD98 2C000000 */ cmpwi       r0, 0x0
/* 8051CD9C 4182004C */ beq-        lbl_8051cde8
/* 8051CDA0 88640CC0 */ lbz         r3, 0xcc0(r4)
/* 8051CDA4 38A00001 */ li          r5, 0x1
/* 8051CDA8 88040CC1 */ lbz         r0, 0xcc1(r4)
/* 8051CDAC 98010011 */ stb         r0, 0x11(r1)
/* 8051CDB0 98610010 */ stb         r3, 0x10(r1)
/* 8051CDB4 88640CC2 */ lbz         r3, 0xcc2(r4)
/* 8051CDB8 88040CC3 */ lbz         r0, 0xcc3(r4)
/* 8051CDBC 98010013 */ stb         r0, 0x13(r1)
/* 8051CDC0 98610012 */ stb         r3, 0x12(r1)
/* 8051CDC4 88640CC4 */ lbz         r3, 0xcc4(r4)
/* 8051CDC8 88040CC5 */ lbz         r0, 0xcc5(r4)
/* 8051CDCC 98010015 */ stb         r0, 0x15(r1)
/* 8051CDD0 98610014 */ stb         r3, 0x14(r1)
/* 8051CDD4 88640CC6 */ lbz         r3, 0xcc6(r4)
/* 8051CDD8 88040CC7 */ lbz         r0, 0xcc7(r4)
/* 8051CDDC 98010017 */ stb         r0, 0x17(r1)
/* 8051CDE0 98610016 */ stb         r3, 0x16(r1)
/* 8051CDE4 48000008 */ b           lbl_8051cdec
lbl_8051cde8:
/* 8051CDE8 38A00000 */ li          r5, 0x0
lbl_8051cdec:
/* 8051CDEC 2C050000 */ cmpwi       r5, 0x0
/* 8051CDF0 41820010 */ beq-        lbl_8051ce00
/* 8051CDF4 387D0018 */ addi        r3, r29, 0x18
/* 8051CDF8 38810010 */ addi        r4, r1, 0x10
/* 8051CDFC 4800A791 */ bl          unk_8052758c
lbl_8051ce00:
/* 8051CE00 3C60809C */ lis         r3, spInstance__Q26System10RaceConfig@ha
/* 8051CE04 8003D728 */ lwz         r0, spInstance__Q26System10RaceConfig@l(r3)
/* 8051CE08 7C60FA14 */ add         r3, r0, r31
/* 8051CE0C 8803002E */ lbz         r0, 0x2e(r3)
/* 8051CE10 7C000775 */ extsb.      r0, r0
/* 8051CE14 4180004C */ blt-        lbl_8051ce60
/* 8051CE18 5400063E */ clrlwi      r0, r0, 0x18
/* 8051CE1C 3C60809C */ lis         r3, spInstance__Q26System12KPadDirector@ha
/* 8051CE20 1C0000EC */ mulli       r0, r0, 0xec
/* 8051CE24 8063D70C */ lwz         r3, spInstance__Q26System12KPadDirector@l(r3)
/* 8051CE28 7C630214 */ add         r3, r3, r0
/* 8051CE2C 3BC30004 */ addi        r30, r3, 0x4
/* 8051CE30 819E0000 */ lwz         r12, 0(r30)
/* 8051CE34 7FC3F378 */ mr          r3, r30
/* 8051CE38 818C0018 */ lwz         r12, 0x18(r12)
/* 8051CE3C 7D8903A6 */ mtctr       r12
/* 8051CE40 4E800421 */ bctrl
/* 8051CE44 907D00D4 */ stw         r3, 0xd4(r29)
/* 8051CE48 7FC3F378 */ mr          r3, r30
/* 8051CE4C 819E0000 */ lwz         r12, 0(r30)
/* 8051CE50 818C001C */ lwz         r12, 0x1c(r12)
/* 8051CE54 7D8903A6 */ mtctr       r12
/* 8051CE58 4E800421 */ bctrl
/* 8051CE5C 907D00D0 */ stw         r3, 0xd0(r29)
lbl_8051ce60:
/* 8051CE60 38000001 */ li          r0, 0x1
/* 8051CE64 981D0000 */ stb         r0, 0(r29)
/* 8051CE68 BB61005C */ lmw         r27, 0x5c(r1)
/* 8051CE6C 80010074 */ lwz         r0, 0x74(r1)
/* 8051CE70 7C0803A6 */ mtlr        r0
/* 8051CE74 38210070 */ addi        r1, r1, 0x70
/* 8051CE78 4E800020 */ blr
  // clang-format on
}
#endif

// Symbol: Controller_vf10
// PAL: 0x8051ce7c..0x8051ce84
MARK_BINARY_BLOB(Controller_vf10, 0x8051ce7c, 0x8051ce84);
asm UNKNOWN_FUNCTION(Controller_vf10){
    // clang-format off
  nofralloc
  /* 8051CE7C 3860FFFF */ li          r3, -0x1
  /* 8051CE80 4E800020 */ blr
    // clang-format on
}

// Symbol: Input_vf18
// PAL: 0x8051ce84..0x8051ce8c
MARK_BINARY_BLOB(Input_vf18, 0x8051ce84, 0x8051ce8c);
asm UNKNOWN_FUNCTION(Input_vf18){
    // clang-format off
  nofralloc
  /* 8051CE84 38600000 */ li          r3, 0x0
  /* 8051CE88 4E800020 */ blr
    // clang-format on
}

// Symbol: Input_vf1c
// PAL: 0x8051ce8c..0x8051ce94
MARK_BINARY_BLOB(Input_vf1c, 0x8051ce8c, 0x8051ce94);
asm UNKNOWN_FUNCTION(Input_vf1c){
    // clang-format off
  nofralloc
  /* 8051CE8C 38600000 */ li          r3, 0x0
  /* 8051CE90 4E800020 */ blr
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
