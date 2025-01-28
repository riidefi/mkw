#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*DVDAsyncCallback)(s32, struct DVDFileInfo*);
typedef void (*DVDCBAsyncCallback)(s32, struct DVDCommandBlock*);

typedef struct DVDDiskID {
  char gameName[4];
  char company[2];
  u8 diskNumber;
  u8 gameVersion;
  u8 streaming;
  u8 streamingBufSize;
  u8 padding[14];
  u32 rvlMagic;
  u32 gcMagic;
} DVDDiskID;

typedef struct DVDCommandBlock {
  DVDCommandBlock* next;
  DVDCommandBlock* prev;
  u32 command;
  s32 state;
  u32 offset;
  u32 length;
  void* addr;
  u32 currTransferSize;
  u32 transferredSize;
  DVDDiskID* id;
  DVDCBAsyncCallback callback;
  void* userData;
} DVDCommandBlock;

typedef struct DVDFileInfo {
  DVDCommandBlock cb;
  u32 startAddr;
  u32 length;
  DVDAsyncCallback callback;
} DVDFileInfo;


s32 DVDConvertPathToEntrynum(const char*);

#define DVD_RESULT_CANCELED -3

// PAL: 0x8015e964..0x8015ea18
void dvd_StampCommand();
// PAL: 0x8015ea18..0x8015ea1c
void dvd_defaultOptionalCommandChecker();
// PAL: 0x8015ea1c..0x8015eb70
void DVDInit();
// PAL: 0x8015eb70..0x8015ece8
void dvd_stateReadingFST();
// PAL: 0x8015ece8..0x8015ee70
void cbForStateReadingFST();
// PAL: 0x8015ee70..0x8015ef94
void dvd_cbForStateError();
// PAL: 0x8015ef94..0x8015efd0
void dvd_cbForStoreErrorCode2();
// PAL: 0x8015efd0..0x8015f0c4
void unk_8015efd0();
// PAL: 0x8015f0c4..0x8015f188
void dvd_cbForStoreErrorCode3();
// PAL: 0x8015f188..0x8015f68c
void dvd_cbForStateGettingError();
// PAL: 0x8015f68c..0x8015f86c
void dvd_cbForUnrecoveredError();
// PAL: 0x8015f86c..0x8015f940
void dvd_cbForUnrecoveredErrorRetry();
// PAL: 0x8015f940..0x8015fb80
void dvd_cbForStateGoToRetry();
// PAL: 0x8015fb80..0x8015feb8
void dvd_stateCheckID();
// PAL: 0x8015feb8..0x80160058
void dvd_cbForStateReadingTOC();
// PAL: 0x80160058..0x801604d0
void dvd_cbForStateReadingPartitionInfo();
// PAL: 0x801604d0..0x80160658
void dvd_cbForStateOpenPartition();
// PAL: 0x80160658..0x801607bc
void dvd_cbForStateOpenPartition2();
// PAL: 0x801607bc..0x80160984
void dvd_cbForStateCheckID1();
// PAL: 0x80160984..0x80160b18
void dvd_cbForStateCheckID2();
// PAL: 0x80160b18..0x80160bdc
void dvd_stateCoverClosed();
// PAL: 0x80160bdc..0x80160e2c
void dvd_ResetAlarmHandler();
// PAL: 0x80160e2c..0x80160f10
void dvd_cbForStateReset();
// PAL: 0x80160f10..0x80160fd8
void dvd_stateDownRotation();
// PAL: 0x80160fd8..0x80161218
void dvd_cbForStateDownRotation();
// PAL: 0x80161218..0x80161390
void dvd_stateCoverClosed_CMD();
// PAL: 0x80161390..0x80161468
void dvd_cbForStateCoverClosed();
// PAL: 0x80161468..0x80161614
void dvd_cbForPrepareCoverRegister();
// PAL: 0x80161614..0x8016193c
void stateReady();
// PAL: 0x8016193c..0x80161eec
void stateBusy();
// PAL: 0x80161eec..0x801628cc
void dvd_cbForStateBusy();
// PAL: 0x801628cc..0x801629b0
void DVDReadAbsAsyncPrio();
// PAL: 0x801629b0..0x80162a88
void DVDInquiryAsync();
// PAL: 0x80162a88..0x80162b50
s32 DVDGetCommandBlockStatus(struct DVDCommandBlock*);
// PAL: 0x80162b50..0x80162bec
void DVDGetDriveStatus();
// PAL: 0x80162bec..0x80162bfc
void DVDSetAutoInvalidation();
// PAL: 0x80162bfc..0x80162c38
void DVDPause();
// PAL: 0x80162c38..0x80162c88
void DVDResume();
// PAL: 0x80162c88..0x80162fec
u32 DVDCancelAsync(struct DVDFileInfo*, DVDCBAsyncCallback);
// PAL: 0x80162fec..0x801630d0
u32 DVDCancel(struct DVDFileInfo*);
// PAL: 0x801630d0..0x8016321c
s32 DVDCancelAll(void);
// PAL: 0x8016321c..0x80163224
void DVDGetCurrentDiskID();
// PAL: 0x80163224..0x8016322c
void __BS2DVDLowCallback();
// PAL: 0x8016322c..0x801632f4
void __DVDGetCoverStatus();
// PAL: 0x801632f4..0x80163338
void __DVDResetWithNoSpinup();
// PAL: 0x80163338..0x80163460
void __DVDPrepareResetAsync();
// PAL: 0x80163460..0x80163594
void __DVDPrepareReset();
// PAL: 0x80163594..0x801635b4
void __DVDTestAlarm();
// PAL: 0x801635b4..0x801635bc
void __DVDStopMotorAsync();

#define DVDRead(fileInfo, addr, length, offset)                                \
  DVDReadPrio((fileInfo), (addr), (length), (offset), 2)
#define DVDGetFileInfoStatus(fileinfo) DVDGetCommandBlockStatus(&(fileinfo)->cb)
#define DVD_RESULT_CANCELED -3


#ifdef __cplusplus
}
#endif
