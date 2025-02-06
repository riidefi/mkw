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

s32 DVDConvertPathToEntrynum(const char*);

int DVDOpen(const char* fileName, DVDFileInfo* fileInfo);
int DVDFastOpen(s32, struct DVDFileInfo*);

int DVDClose(DVDFileInfo* fileInfo);

#ifdef __cplusplus
}
#endif
