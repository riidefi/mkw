#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8015d3fc..0x8015d40c
UNKNOWN_FUNCTION(DSPCheckMailToDSP);
// PAL: 0x8015d40c..0x8015d41c
UNKNOWN_FUNCTION(DSPCheckMailFromDSP);
// PAL: 0x8015d41c..0x8015d430
UNKNOWN_FUNCTION(DSPReadMailFromDSP);
// PAL: 0x8015d430..0x8015d444
UNKNOWN_FUNCTION(DSPSendMailToDSP);
// PAL: 0x8015d444..0x8015d504
UNKNOWN_FUNCTION(DSPInit);
// PAL: 0x8015d504..0x8015d50c
UNKNOWN_FUNCTION(DSPCheckInit);
// PAL: 0x8015d50c..0x8015d57c
UNKNOWN_FUNCTION(DSPAddTask);
// PAL: 0x8015d57c..0x8015d638
UNKNOWN_FUNCTION(DSPAssertTask);

#ifdef __cplusplus
}
#endif
