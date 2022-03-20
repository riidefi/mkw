#pragma once

#include <decomp.h>
#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  char _[0x18];
} OSMutex;

// PAL: 0x801a7eac..0x801a7ee4
void OSInitMutex(OSMutex*);
// PAL: 0x801a7ee4..0x801a7fc0
void OSLockMutex(OSMutex*);
// PAL: 0x801a7fc0..0x801a8088
void OSUnlockMutex(OSMutex*);
// PAL: 0x801a8088..0x801a80f4
UNKNOWN_FUNCTION(__OSUnlockAllMutex);
// PAL: 0x801a80f4..0x801a81b0
s32 OSTryLockMutex(OSMutex*);
// PAL: 0x801a81b0..0x801a81b4
UNKNOWN_FUNCTION(OSInitCond);
// PAL: 0x801a81b4..0x801a81b8
UNKNOWN_FUNCTION(OSSignalCond);

#ifdef __cplusplus
}
#endif
