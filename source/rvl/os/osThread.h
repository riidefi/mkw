#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  char _[0x18];
} OSMutex;

void OSInitMutex(OSMutex*);
void OSLockMutex(OSMutex*);
void OSUnlockMutex(OSMutex*);

#ifdef __cplusplus
}
#endif