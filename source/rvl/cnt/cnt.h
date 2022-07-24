#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8015bc80..0x8015bcec
UNKNOWN_FUNCTION(contentFastOpenNAND);
// PAL: 0x8015bcec..0x8015bcf0
UNKNOWN_FUNCTION(CNTConvertPathToEntrynum);
// PAL: 0x8015bcf0..0x8015bcf8
UNKNOWN_FUNCTION(CNTGetLength);
// PAL: 0x8015bcf8..0x8015bd98
UNKNOWN_FUNCTION(contentReadNAND);
// PAL: 0x8015bd98..0x8015bda0
UNKNOWN_FUNCTION(contentCloseNAND);
// PAL: 0x8015bda0..0x8015bef0
UNKNOWN_FUNCTION(__CNTConvertErrorCode);

#ifdef __cplusplus
}
#endif
