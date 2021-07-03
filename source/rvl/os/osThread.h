#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif
#ifndef RII_CLIENT

u32 OSGetTick();
u32 __OSBusClock : (0x800000F8);
#define OS_TIMER_CLOCK (__OSBusClock >> 2)

typedef struct OSThread {
  char _00[0x304];
  char* stack_high; // 304
  char* stack_low;  // 308
  u32 error;        // 30C
  char _310[0x318 - 0x310];
} OSThread;

typedef void* OSMessage;

typedef struct OSMessageQueue {
  char _[0x20];
} OSMessageQueue;

typedef struct {
  char _[0x18];
} OSMutex;

void OSInitMutex(OSMutex*);
void OSLockMutex(OSMutex*);
void OSUnlockMutex(OSMutex*);

int OSCreateThread(OSThread* thread, void* (*callable)(void*), void* user_data,
                   void* stack, u32 stack_size, s32 prio, u16 flag);

void OSCancelThread(OSThread*);
void OSDetachThread(OSThread*);
int OSIsThreadTerminated(OSThread*);
OSThread* OSGetCurrentThread();

typedef void (*OSSwitchFunction)(OSThread*, OSThread*);
OSSwitchFunction OSSetSwitchThreadCallback(OSSwitchFunction callable);

void OSInitMessageQueue(OSMessageQueue* queue, OSMessage* buffer, s32 capacity);

#endif
#ifdef __cplusplus
}
#endif
