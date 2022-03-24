#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OSShutdownFunctionInfo {
  u32 func;
  u32 priority;
  u32 succ;
  u32 prev;
} OSShutdownFunctionInfo;

// PAL: 0x801a8238..0x801a82c0
extern void OSRegisterShutdownFunction(OSShutdownFunctionInfo* info);
// PAL: 0x801a82c0..0x801a8370
UNKNOWN_FUNCTION(__OSCallShutdownFunctions);
// PAL: 0x801a8370..0x801a8500
UNKNOWN_FUNCTION(__OSShutdownDevices);
// PAL: 0x801a8500..0x801a856c
UNKNOWN_FUNCTION(__OSGetDiscState);
// PAL: 0x801a856c..0x801a8688
UNKNOWN_FUNCTION(OSShutdownSystem);
// PAL: 0x801a8688..0x801a8758
UNKNOWN_FUNCTION(OSRestart);
// PAL: 0x801a8758..0x801a8858
UNKNOWN_FUNCTION(__OSReturnToMenu);
// PAL: 0x801a8858..0x801a8898
UNKNOWN_FUNCTION(OSReturnToMenu);
// PAL: 0x801a8898..0x801a8954
UNKNOWN_FUNCTION(OSReturnToSetting);
// PAL: 0x801a8954..0x801a89f8
UNKNOWN_FUNCTION(__OSReturnToMenuForError);
// PAL: 0x801a89f8..0x801a8a50
UNKNOWN_FUNCTION(__OSHotResetForError);
// PAL: 0x801a8a50..0x801a8a80
UNKNOWN_FUNCTION(OSGetResetCode);

#ifdef __cplusplus
}
#endif
