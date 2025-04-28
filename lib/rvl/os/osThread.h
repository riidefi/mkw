#pragma once

#include <decomp.h>
#include <rk_types.h>

#include "os.h"

#ifdef __cplusplus
extern "C" {
#endif
#ifndef RII_CLIENT

u32 __OSBusClock AT_ADDRESS(0x800000F8);

#define OS_TIMER_CLOCK (__OSBusClock >> 2)

#define OSMillisecondsToTicks(msec) ((msec) * (OS_TIMER_CLOCK / 1000))
#define OSSleepMilliseconds(msec)                                              \
  OSSleepTicks(OSMillisecondsToTicks((OSTime)msec))

typedef struct OSThread {
  char _00[0x304];
  char* stack_high; // 304
  char* stack_low;  // 308
  u32 error;        // 30C
  char _310[0x318 - 0x310];
} OSThread;

typedef struct OSThreadQueue OSThreadQueue;
struct OSThreadQueue {
  OSThread* head;
  OSThread* tail;
};


int OSCreateThread(OSThread* thread, void* (*callable)(void*), void* user_data,
                   void* stack, u32 stack_size, s32 prio, u16 flag);

                  
void OSCancelThread(OSThread*);

void OSDetachThread(OSThread*);

s32 OSResumeThread(OSThread*);

int OSIsThreadTerminated(OSThread*);

OSThread* OSGetCurrentThread();

typedef void (*OSSwitchFunction)(OSThread*, OSThread*);

OSSwitchFunction OSSetSwitchThreadCallback(OSSwitchFunction callable);

void OSSleepTicks(OSTime ticks);

void OSInitThreadQueue(struct OSThreadQueue*);

s32 OSDisableScheduler(void);
s32 OSEnableScheduler(void);

void __OSReschedule(void);

void OSYieldThread(void);
void OSExitThread(OSThread *thread);
BOOL OSJoinThread(OSThread *thread, void *val);

s32 OSSuspendThread(OSThread*);
void OSSleepThread(struct OSThreadQueue*);
void OSWakeupThread(struct OSThreadQueue*);

#endif
#ifdef __cplusplus
}
#endif
