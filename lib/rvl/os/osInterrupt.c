#include "osInterrupt.h"

#include <hardware.h>
#include <string.h>

#include "osException.h"

static __OSInterruptHandler* OSInterruptHandlerTable;
static u32 OSInterruptPrioTable[] = {
    0x00000100, 0x00000040, 0xf8000000, 0x00000200, 0x00000080, 0x00000010,
    0x00003000, 0x00000020, 0x03ff8c00, 0x04000000, 0x00004000, 0xffffffff,
};

#define OS_INTERRUPTTABLE_ADDR 0x3040
#define OS_INTERRUPTMASK_ADDR 0x00C4
#define OS_UINTERRUPTMASK_ADDR 0x00C8

/* static */ void ExternalInterruptHandler(register u8 exception,
                                     register OSContext* context);

#ifdef __CWCC__

// Symbol: OSDisableInterrupts
asm int OSDisableInterrupts(void) {
  nofralloc;
  mfmsr r3;
  rlwinm r4, r3, 0, 0x11, 0xf;
  mtmsr r4;
  rlwinm r3, r3, 0x11, 0x1f, 0x1f;
  blr;
}

// Symbol: OSEnableInterrupts
asm int OSEnableInterrupts(void) {
  nofralloc;
  mfmsr r3;
  ori r4, r3, 0x8000;
  mtmsr r4;
  rlwinm r3, r3, 0x11, 0x1f, 0x1f;
  blr;
}

// Symbol: OSRestoreInterrupts
asm int OSRestoreInterrupts(int level) {
  nofralloc;
  cmpwi r3, 0;
  mfmsr r4;
  beq _disable;
  ori r5, r4, 0x8000;
  b _restore;
_disable:
  rlwinm r5, r4, 0, 0x11, 0xf;
_restore:
  mtmsr r5;
  rlwinm r3, r4, 0x11, 0x1f, 0x1f;
  blr;
}

#endif

// Symbol: __OSSetInterruptHandler
__OSInterruptHandler __OSSetInterruptHandler(s16 interrupt,
                                             __OSInterruptHandler handler) {
  __OSInterruptHandler old = OSInterruptHandlerTable[interrupt];
  OSInterruptHandlerTable[interrupt] = handler;
  return old;
}

// Symbol: __OSGetInterruptHandler
__OSInterruptHandler __OSGetInterruptHandler(s16 interrupt) {
  return OSInterruptHandlerTable[interrupt];
}

inline void* OSPhysicalToCached(u32 addr) { return (void*)(addr + 0x80000000); }

// Symbol: __OSInterruptInit
void __OSInterruptInit(void) {
  OSInterruptHandlerTable = (__OSInterruptHandler*)OSPhysicalToCached(0x3040);
  memset((void*)OSInterruptHandlerTable, 0, 32 * sizeof(__OSInterruptHandler));
  *(u32*)OSPhysicalToCached(0x00C4) = 0;
  *(u32*)OSPhysicalToCached(0x00C8) = 0;
  __PIRegs[0x004 / 4] = 0xf0;
  __ACRRegs[0x034 / 4] = 0x40000000;
  __OSMaskInterrupts(0xfffffff0u);
  __OSSetExceptionHandler(4, ExternalInterruptHandler);
}

/* static */ u32 SetInterruptMask(u32 type, u32 mask);

// Symbol: __OSMaskInterrupts
u32 __OSMaskInterrupts(u32 global) {
  int enabled;
  u32 prev;
  u32 local;
  u32 mask;

  enabled = OSDisableInterrupts();
  prev = *(u32*)OSPhysicalToCached(OS_INTERRUPTMASK_ADDR);
  local = *(u32*)OSPhysicalToCached(OS_UINTERRUPTMASK_ADDR);
  mask = ~(prev | local) & global;
  global |= prev;
  *(u32*)OSPhysicalToCached(OS_INTERRUPTMASK_ADDR) = global;
  while (mask)
    mask = SetInterruptMask(mask, global | local);
  OSRestoreInterrupts(enabled);
  return prev;
}

volatile OSTime __OSLastInterruptTime;
volatile s16 __OSLastInterrupt;
volatile u32 __OSLastInterruptSrr0;

// Symbol: __OSDispatchInterrupt
void __OSDispatchInterrupt(u8 exception, OSContext* context) {
  u32 intsr = __PIRegs[0];
  intsr &= ~0x00010000;
  u32 mask = __PIRegs[1];
  if (intsr == 0 || (intsr & mask) == 0)
    OSLoadContext(context);
  u32 reg;
  u32 bits = 0;
  if (intsr & 0x00000080) {
    reg = __MEMRegs[0x0000000f];
    if (reg & 0x00000001)
      bits |= (0x80000000u >> 0);
    if (reg & 0x00000002)
      bits |= (0x80000000u >> 1);
    if (reg & 0x00000004)
      bits |= (0x80000000u >> 2);
    if (reg & 0x00000008)
      bits |= (0x80000000u >> 3);
    if (reg & 0x00000010)
      bits |= (0x80000000u >> 4);
  }
  if (intsr & 0x00000040) {
    reg = __DSPRegs[0x00000005];
    if (reg & 0x00000008)
      bits |= (0x80000000u >> 5);
    if (reg & 0x00000020)
      bits |= (0x80000000u >> 6);
    if (reg & 0x00000080)
      bits |= (0x80000000u >> 7);
  }
  if (intsr & 0x00000020) {
    reg = __AIRegs[0x00000000];
    if (reg & 0x00000008)
      bits |= (0x80000000u >> 8);
  }
  if (intsr & 0x00000010) {
    reg = __EXIRegs[0x00000000];
    if (reg & 0x00000002)
      bits |= (0x80000000u >> 9);
    if (reg & 0x00000008)
      bits |= (0x80000000u >> 10);
    if (reg & 0x00000800)
      bits |= (0x80000000u >> 11);
    reg = __EXIRegs[0x00000005];
    if (reg & 0x00000002)
      bits |= (0x80000000u >> 12);
    if (reg & 0x00000008)
      bits |= (0x80000000u >> 13);
    if (reg & 0x00000800)
      bits |= (0x80000000u >> 14);
    reg = __EXIRegs[0x0000000a];
    if (reg & 0x00000002)
      bits |= (0x80000000u >> 15);
    if (reg & 0x00000008)
      bits |= (0x80000000u >> 16);
  }
  if (intsr & 0x00002000)
    bits |= (0x80000000u >> 26);
  if (intsr & 0x00001000)
    bits |= (0x80000000u >> 25);
  if (intsr & 0x00000400)
    bits |= (0x80000000u >> 19);
  if (intsr & 0x00000200)
    bits |= (0x80000000u >> 18);
  if (intsr & 0x00000100)
    bits |= (0x80000000u >> 24);
  if (intsr & 0x00000008)
    bits |= (0x80000000u >> 20);
  if (intsr & 0x00000004)
    bits |= (0x80000000u >> 21);
  if (intsr & 0x00000002)
    bits |= (0x80000000u >> 22);
  if (intsr & 0x00000800)
    bits |= (0x80000000u >> 17);
  if (intsr & 0x00000001)
    bits |= (0x80000000u >> 23);
  if (intsr & 0x00004000)
    bits |= (0x80000000u >> 27);
  u32 local5 = bits & ~(*(u32*)OSPhysicalToCached(0x00C4) |
                        *(u32*)OSPhysicalToCached(0x00C8));
  if (local5) {
    u32* prio;
    s16 interrupt;
    for (prio = OSInterruptPrioTable;; ++prio) {
      if (local5 & *prio) {
        interrupt = (u32)__cntlzw(local5 & *prio);
        break;
      }
    }
    __OSInterruptHandler handler = __OSGetInterruptHandler(interrupt);
    if (handler) {
      if (4 < interrupt) {
        __OSLastInterrupt = interrupt;
        __OSLastInterruptTime = OSGetTime();
        __OSLastInterruptSrr0 = context->srr0;
      }
      OSDisableScheduler();
      handler(interrupt, context);
      OSEnableScheduler();
      __OSReschedule();
      OSLoadContext(context);
    }
  }
  OSLoadContext(context);
}

#ifdef __CWCC__

// Symbol: ExternalInterruptHandler
static asm void ExternalInterruptHandler(register u8 exception,
                                         register OSContext* context) {
  nofralloc;
  stw r0, 0(r4);
  stw r1, 4(r4);
  stw r2, 8(r4);
  stmw r6, 0x18(r4);
  mfspr r0, 0x391;
  stw r0, 0x1a8(r4);
  mfspr r0, 0x392;
  stw r0, 0x1ac(r4);
  mfspr r0, 0x393;
  stw r0, 0x1b0(r4);
  mfspr r0, 0x394;
  stw r0, 0x1b4(r4);
  mfspr r0, 0x395;
  stw r0, 0x1b8(r4);
  mfspr r0, 0x396;
  stw r0, 0x1bc(r4);
  mfspr r0, 0x397;
  stw r0, 0x1c0(r4);
  stwu r1, -8(r1);
  b __OSDispatchInterrupt;
}

#endif
