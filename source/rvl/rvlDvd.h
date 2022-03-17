#pragma once

#ifdef __cplusplus
extern "C" {
#endif

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

typedef struct DVDCommandBlock DVDCommandBlock;
typedef void (*DVDCBCallback)(s32 result, DVDCommandBlock* block);

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
  DVDCBCallback callback;
  void* userData;
} DVDCommandBlock;

typedef struct DVDFileInfo DVDFileInfo;

typedef void (*DVDCallback)(s32 result, DVDFileInfo* fileInfo);

struct DVDFileInfo {
  DVDCommandBlock cb;
  u32 startAddr;
  u32 length;
  DVDCallback callback;
};

#define DVD_RESULT_CANCELED -3

int DVDOpen(const char* fileName, DVDFileInfo* fileInfo);
int DVDFastOpen(s32 entrynum, DVDFileInfo* fileInfo);
s32 DVDReadPrio(DVDFileInfo* fileInfo, void* addr, s32 length, s32 offset,
                s32 prio);
#define DVDRead(fileInfo, addr, length, offset)                                \
  DVDReadPrio((fileInfo), (addr), (length), (offset), 2)
int DVDReadAsyncPrio(DVDFileInfo* fileInfo, void* addr, s32 length, s32 offset,
                     DVDCallback callback, s32 prio);
int DVDClose(DVDFileInfo* fileInfo);
s32 DVDGetCommandBlockStatus(const DVDCommandBlock* block);
#define DVDGetFileInfoStatus(fileinfo) DVDGetCommandBlockStatus(&(fileinfo)->cb)
s32 DVDConvertPathToEntrynum(const char* pathPtr);

s32 DVDCancelAll(void);

#ifdef __cplusplus
}
#endif
