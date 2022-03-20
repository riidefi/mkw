#pragma once

#include <rk_types.h>

#include "decomp.h"

// Stolen from ogws.
// Credit: kiwi515
// Credit: GibHaltmannKill

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*DVDAsyncCallback)(s32, struct DVDFileInfo*);
typedef void (*DVDCBAsyncCallback)(s32, struct DVDCommandBlock*);

struct DVDFileInfo {
  s32 WORD_0x0;
  s32 WORD_0x4;
  s32 WORD_0x8;
  s32 WORD_0xC;
  s32 WORD_0x10;
  s32 WORD_0x14;
  s32 WORD_0x18;
  s32 WORD_0x1C;
  s32 WORD_0x20;
  s32 WORD_0x24;
  s32 WORD_0x28;
  s32 WORD_0x2C;
  s32 WORD_0x30;
  s32 mFileSize;
  s32 WORD_0x38;
};

struct DVDCommandBlock {
  s32 WORD_0x0;
  s32 WORD_0x4;
  s32 WORD_0x8;
  s32 WORD_0xC;
  s32 WORD_0x10;
  s32 WORD_0x14;
  s32 WORD_0x18;
  s32 WORD_0x1C;
  s32 WORD_0x20;
  s32 WORD_0x24;
  s32 WORD_0x28;
  s32 WORD_0x2C;
  s32 WORD_0x30;
  s32 WORD_0x34;
  s32 WORD_0x38;
};

u32 DVDGetDriveStatus(void);

s32 DVDConvertPathToEntrynum(const char*);

s32 DVDFastOpen(s32, struct DVDFileInfo*);

s32 DVDClose(struct DVDFileInfo*);

s32 DVDReadPrio(struct DVDFileInfo*, void* addr, u32 length, s32 offset, s32);
u32 DVDReadAsyncPrio(struct DVDFileInfo*, void* addr, u32 length, s32 offset,
                     DVDAsyncCallback, s32);

u32 DVDCancel(struct DVDFileInfo*);
u32 DVDCancelAsync(struct DVDFileInfo*, DVDCBAsyncCallback);

s32 DVDGetCommandBlockStatus(struct DVDCommandBlock*);

#ifdef __cplusplus
}
#endif
