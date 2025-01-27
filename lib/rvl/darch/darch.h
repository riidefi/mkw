#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8015c320..0x8015c37c
UNKNOWN_FUNCTION(darch_AddItem);
// PAL: 0x8015c37c..0x8015c868
UNKNOWN_FUNCTION(darch_MergeDirStructure);
// PAL: 0x8015c868..0x8015c954
UNKNOWN_FUNCTION(darch_DecideOrderInFst);
// PAL: 0x8015c954..0x8015cb18
UNKNOWN_FUNCTION(darch_GetFileChar);
// PAL: 0x8015cb18..0x8015ce0c
UNKNOWN_FUNCTION(darch_CreateDirStructure);
// PAL: 0x8015ce0c..0x8015d0fc
UNKNOWN_FUNCTION(darch_ConstructFSTFromStructure);
// PAL: 0x8015d0fc..0x8015d254
UNKNOWN_FUNCTION(DARCHGetArcSize);
// PAL: 0x8015d254..0x8015d314
UNKNOWN_FUNCTION(DARCHCreate);

#ifdef __cplusplus
}
#endif
