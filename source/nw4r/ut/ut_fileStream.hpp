#pragma once

#include <rk_types.h>

#include "decomp.h"

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x800afef0..0x800aff00
UNKNOWN_FUNCTION(nw4r_ut_FilePosition_Cancel);
// PAL: 0x800aff00..0x800aff10
UNKNOWN_FUNCTION(nw4r_ut_FileStream_CancelAsync);
// PAL: 0x800aff10..0x800aff80
UNKNOWN_FUNCTION(nw4r_ut_FilePosition_Skip);
// PAL: 0x800aff80..0x800affd0
UNKNOWN_FUNCTION(nw4r_ut_FilePosition_Append);
// PAL: 0x800affd0..0x800b0058
UNKNOWN_FUNCTION(nw4r_ut_FilePosition_Seek);

#ifdef __cplusplus
}
#endif
