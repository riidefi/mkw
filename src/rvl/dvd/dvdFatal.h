#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80164294..0x80164364
UNKNOWN_FUNCTION(__DVDShowFatalMessage);
// PAL: 0x80164364..0x801643c0
UNKNOWN_FUNCTION(DVDSetAutoFatalMessaging);
// PAL: 0x801643c0..0x801643d4
UNKNOWN_FUNCTION(__DVDGetAutoFatalMessaging);
// PAL: 0x801643d4..0x801643ec
UNKNOWN_FUNCTION(__DVDPrintFatalMessage);

#ifdef __cplusplus
}
#endif
