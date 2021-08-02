#pragma once

#include <rk_types.h>

#include "decomp.h"

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x801a65ac..0x801a65c0
int OSDisableInterrupts(void);
// PAL: 0x801a65c0..0x801a65d4
int OSEnableInterrupts(void);
// PAL: 0x801a65d4..0x801a65f8
int OSRestoreInterrupts(int level);
// PAL: 0x801a65f8..0x801a660c
UNKNOWN_FUNCTION(__OSSetInterruptHandler);
// PAL: 0x801a660c..0x801a661c
UNKNOWN_FUNCTION(__OSGetInterruptHandler);
// PAL: 0x801a661c..0x801a66e0
UNKNOWN_FUNCTION(__OSInterruptInit);
// PAL: 0x801a66e0..0x801a693c
UNKNOWN_FUNCTION(SetInterruptMask);
// PAL: 0x801a693c..0x801a69bc
UNKNOWN_FUNCTION(__OSMaskInterrupts);
// PAL: 0x801a69bc..0x801a6a3c
UNKNOWN_FUNCTION(__OSUnmaskInterrupts);
// PAL: 0x801a6a3c..0x801a6ce0
UNKNOWN_FUNCTION(__OSDispatchInterrupt);
// PAL: 0x801a6ce0..0x801a6d30
UNKNOWN_FUNCTION(ExternalInterruptHandler);

#ifdef __cplusplus
}
#endif