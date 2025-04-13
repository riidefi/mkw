#pragma once

#include <rk_types.h>

#include <decomp.h>

#include <rvl/dvd/dvd.h>

// https://github.com/DarkRTA/rb3/blob/4ca788a7e7b5470eb54644a9bda318e675bcd4d3/src/sdk/RVL_SDK/revolution/dvd/dvd.h

#ifdef __cplusplus
extern "C" {
#endif

typedef struct DVDDir{
    u32 entryNum;
    u32 location;
    u32 next;
} DVDDir;

typedef struct DVDDirEntry{
    u32 entryNum;
    BOOL isDir;
    char* name;
} DVDDirEntry;

typedef void (*DVDCallback)(s32 result, struct DVDFileInfo* fileInfo);

extern BOOL __DVDLongFileNameFlag;

s32 DVDConvertPathToEntrynum(const char* pathPtr);
int DVDOpen(const char* fileName, DVDFileInfo* fileInfo);
BOOL DVDFastOpen(s32 entrynum, DVDFileInfo* fileInfo);
BOOL DVDClose(DVDFileInfo* fileInfo);
BOOL DVDGetCurrentDir(char* path, u32 maxlen);
BOOL DVDReadAsyncPrio(DVDFileInfo* fileInfo, void* addr, s32 length, s32 offset, DVDCallback callback, s32 prio);
s32 DVDReadPrio(DVDFileInfo* fileInfo, void* addr, s32 length, s32 offset, s32 prio);
u32 DVDGetTransferredSize(DVDCommandBlock* block);


#ifdef __cplusplus
}
#endif
