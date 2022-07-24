#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8015df1c..0x8015df4c
UNKNOWN_FUNCTION(__DVDFSInit);
// PAL: 0x8015df4c..0x8015e254
UNKNOWN_FUNCTION(DVDConvertPathToEntrynum);
// PAL: 0x8015e254..0x8015e2bc
UNKNOWN_FUNCTION(DVDFastOpen);
// PAL: 0x8015e2bc..0x8015e568
UNKNOWN_FUNCTION(DVDOpen);
// PAL: 0x8015e568..0x8015e58c
UNKNOWN_FUNCTION(DVDClose);
// PAL: 0x8015e58c..0x8015e74c
UNKNOWN_FUNCTION(dvd_entryToPath_0);
// PAL: 0x8015e74c..0x8015e834
UNKNOWN_FUNCTION(DVDReadAsyncPrio);
// PAL: 0x8015e834..0x8015e964
UNKNOWN_FUNCTION(DVDReadPrio);

#ifdef __cplusplus
}
#endif
