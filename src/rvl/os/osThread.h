#pragma once

#include <decomp.h>
#include <rk_types.h>

#include "os.h"

#ifdef __cplusplus
extern "C" {
#endif
#ifndef RII_CLIENT

#ifdef __CWCC__
u32 __OSBusClock : (0x800000F8);
#else
u32* const __OSBusClock = (u32*)0x800000F8;
#endif

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

// PAL: 0x801a9e84..0x801aa0f0
int OSCreateThread(OSThread* thread, void* (*callable)(void*), void* user_data,
                   void* stack, u32 stack_size, s32 prio, u16 flag);
// PAL: 0x801aa1d4..0x801aa3ac
void OSCancelThread(OSThread*);
// PAL: 0x801aa4ec..0x801aa58c
void OSDetachThread(OSThread*);
// PAL: 0x801aa58c..0x801aa824
s32 OSResumeThread(OSThread*);
// PAL: 0x801a98bc..0x801a98e8
int OSIsThreadTerminated(OSThread*);
// PAL: 0x801a98b0..0x801a98b4
OSThread* OSGetCurrentThread();

typedef void (*OSSwitchFunction)(OSThread*, OSThread*);
// PAL: 0x801a95ac..0x801a961c
OSSwitchFunction OSSetSwitchThreadCallback(OSSwitchFunction callable);

// PAL: 0x801aaca8..0x801aad5c
void OSSleepTicks(OSTime ticks);

// PAL: 0x801a961c..0x801a98a0
UNKNOWN_FUNCTION(__OSThreadInit);
// PAL: 0x801a98a0..0x801a98b0
void OSInitThreadQueue(struct OSThreadQueue*);
// PAL: 0x801a98b4..0x801a98bc
UNKNOWN_FUNCTION(GetFont__Q34nw4r3lyt7TextBoxCFv);
// PAL: 0x801a98e8..0x801a9924
UNKNOWN_FUNCTION(OSDisableScheduler);
// PAL: 0x801a9924..0x801a9960
UNKNOWN_FUNCTION(OSEnableScheduler);
// PAL: 0x801a9960..0x801a99c8
UNKNOWN_FUNCTION(UnsetRun);
// PAL: 0x801a99c8..0x801a9a04
UNKNOWN_FUNCTION(__OSGetEffectivePriority);
// PAL: 0x801a9a04..0x801a9bb8
UNKNOWN_FUNCTION(SetEffectivePriority);
// PAL: 0x801a9bb8..0x801a9c08
UNKNOWN_FUNCTION(__OSPromoteThread);
// PAL: 0x801a9c08..0x801a9e30
UNKNOWN_FUNCTION(SelectThread);
// PAL: 0x801a9e30..0x801a9e48
UNKNOWN_FUNCTION(__OSReschedule);
// PAL: 0x801a9e48..0x801a9e84
UNKNOWN_FUNCTION(OSYieldThread);
// PAL: 0x801aa0f0..0x801aa1d4
UNKNOWN_FUNCTION(OSExitThread);
// PAL: 0x801aa3ac..0x801aa4ec
UNKNOWN_FUNCTION(OSJoinThread);
// PAL: 0x801aa824..0x801aa9b8
s32 OSSuspendThread(OSThread*);
// PAL: 0x801aa9b8..0x801aaaa4
void OSSleepThread(struct OSThreadQueue*);
// PAL: 0x801aaaa4..0x801aab98
void OSWakeupThread(struct OSThreadQueue*);
// PAL: 0x801aab98..0x801aaca8
UNKNOWN_FUNCTION(OSSetThreadPriority);

#endif
#ifdef __cplusplus
}
#endif
