#pragma once

#include <rk_types.h>

#include <decomp.h>

// Credit: riidefi
// Credit: terorie
// Credit: kiwi515
// Credit: GibHaltmannKill

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

u32 DVDGetDriveStatus(void);

s32 DVDConvertPathToEntrynum(const char*);

#define DVD_RESULT_CANCELED -3

int DVDOpen(const char* fileName, DVDFileInfo* fileInfo);
int DVDFastOpen(s32, struct DVDFileInfo*);

int DVDClose(DVDFileInfo* fileInfo);

#define DVDRead(fileInfo, addr, length, offset)                                \
  DVDReadPrio((fileInfo), (addr), (length), (offset), 2)
s32 DVDReadPrio(struct DVDFileInfo*, void* addr, u32 length, s32 offset, s32);
u32 DVDReadAsyncPrio(struct DVDFileInfo*, void* addr, u32 length, s32 offset,
                     DVDAsyncCallback, s32);

u32 DVDCancel(struct DVDFileInfo*);
u32 DVDCancelAsync(struct DVDFileInfo*, DVDCBAsyncCallback);
s32 DVDCancelAll(void);

s32 DVDGetCommandBlockStatus(struct DVDCommandBlock*);

#define DVDGetFileInfoStatus(fileinfo) DVDGetCommandBlockStatus(&(fileinfo)->cb)

#ifdef __cplusplus
}
#endif
