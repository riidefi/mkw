#pragma once

#include <rk_types.h>

#include "os.h"

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

typedef struct OSThreadQueue OSThreadQueue;
struct OSThreadQueue {
  OSThread* head;
  OSThread* tail;
};

typedef struct OSContext {
  // General-purpose registers
  u32 gpr[32];

  u32 cr;
  u32 lr;
  u32 ctr;
  u32 xer;

  // Floating-point registers
  f64 fpr[32];

  u32 fpscr_pad;
  u32 fpscr;

  // Exception handling registers
  u32 srr0;
  u32 srr1;

  // Context mode
  u16 mode;  // since UIMM is 16 bits in PPC
  u16 state; // OR-ed OS_CONTEXT_STATE_*

  // Place Gekko regs at the end so we have minimal changes to
  // existing code
  u32 gqr[8];
  u32 psf_pad;
  f64 psf[32];

} OSContext;

void OSInitMutex(OSMutex*);
void OSLockMutex(OSMutex*);
void OSUnlockMutex(OSMutex*);

int OSCreateThread(OSThread* thread, void* (*callable)(void*), void* user_data,
                   void* stack, u32 stack_size, s32 prio, u16 flag);
void OSCancelThread(OSThread*);
void OSDetachThread(OSThread*);
s32 OSResumeThread(OSThread*);
int OSIsThreadTerminated(OSThread*);
OSThread* OSGetCurrentThread();

typedef void (*OSSwitchFunction)(OSThread*, OSThread*);
OSSwitchFunction OSSetSwitchThreadCallback(OSSwitchFunction callable);

void OSInitMessageQueue(OSMessageQueue* queue, OSMessage* buffer, s32 capacity);

void OSSleepTicks(OSTime ticks);

#endif
#ifdef __cplusplus
}
#endif
