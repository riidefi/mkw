#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x801a1138..0x801a1358
UNKNOWN_FUNCTION(__AIClockInit);
// PAL: 0x801a1358..0x801a1520
UNKNOWN_FUNCTION(__OSInitAudioSystem);
// PAL: 0x801a1520..0x801a15ec
UNKNOWN_FUNCTION(__OSStopAudioSystem);

#ifdef __cplusplus
}
#endif
