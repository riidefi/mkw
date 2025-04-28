#pragma once

#include <decomp.h>
#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  char _[0x18];
} OSMutex;

void OSInitMutex(OSMutex*);
void OSLockMutex(OSMutex*);
void OSUnlockMutex(OSMutex*);
s32 OSTryLockMutex(OSMutex*);

#ifdef __cplusplus
}
#endif
