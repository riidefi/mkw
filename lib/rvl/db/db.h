#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8015d314..0x8015d33c
UNKNOWN_FUNCTION(DBInit);
// PAL: 0x8015d33c..0x8015d384
UNKNOWN_FUNCTION(__DBExceptionDestinationAux);
// PAL: 0x8015d384..0x8015d394
UNKNOWN_FUNCTION(__DBExceptionDestination);
// PAL: 0x8015d394..0x8015d3ac
UNKNOWN_FUNCTION(__DBIsExceptionMarked);

#ifdef __cplusplus
}
#endif
