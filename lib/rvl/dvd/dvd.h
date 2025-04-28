#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct DVDCommandBlock DVDCommandBlock;
typedef struct DVDFileInfo DVDFileInfo;

typedef void (*DVDAsyncCallback)(s32, DVDFileInfo*);
typedef void (*DVDCBAsyncCallback)(s32, DVDCommandBlock*);

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

void dvd_StampCommand();
void dvd_defaultOptionalCommandChecker();
void DVDInit();
void dvd_stateReadingFST();
void cbForStateReadingFST();
void dvd_cbForStateError();
void dvd_cbForStoreErrorCode2();
void unk_8015efd0();
void dvd_cbForStoreErrorCode3();
void dvd_cbForStateGettingError();
void dvd_cbForUnrecoveredError();
void dvd_cbForUnrecoveredErrorRetry();
void dvd_cbForStateGoToRetry();
void dvd_stateCheckID();
void dvd_cbForStateReadingTOC();
void dvd_cbForStateReadingPartitionInfo();
void dvd_cbForStateOpenPartition();
void dvd_cbForStateOpenPartition2();
void dvd_cbForStateCheckID1();
void dvd_cbForStateCheckID2();
void dvd_stateCoverClosed();
void dvd_ResetAlarmHandler();
void dvd_cbForStateReset();
void dvd_stateDownRotation();
void dvd_cbForStateDownRotation();
void dvd_stateCoverClosed_CMD();
void dvd_cbForStateCoverClosed();
void dvd_cbForPrepareCoverRegister();
void stateReady();
void stateBusy();
void dvd_cbForStateBusy();
void DVDReadAbsAsyncPrio();
void DVDInquiryAsync();
s32 DVDGetCommandBlockStatus(DVDCommandBlock*);
void DVDGetDriveStatus();
void DVDSetAutoInvalidation();
void DVDPause();
void DVDResume();
u32 DVDCancelAsync(DVDFileInfo*, DVDCBAsyncCallback);
u32 DVDCancel(DVDFileInfo*);
s32 DVDCancelAll(void);
void DVDGetCurrentDiskID();
void __BS2DVDLowCallback();
void __DVDGetCoverStatus();
void __DVDResetWithNoSpinup();
void __DVDPrepareResetAsync();
void __DVDPrepareReset();
void __DVDTestAlarm();
void __DVDStopMotorAsync();

#define DVDRead(fileInfo, addr, length, offset)                                \
  DVDReadPrio((fileInfo), (addr), (length), (offset), 2)
#define DVDGetFileInfoStatus(fileinfo) DVDGetCommandBlockStatus(&(fileinfo)->cb)
#define DVD_RESULT_CANCELED -3


#ifdef __cplusplus
}
#endif
