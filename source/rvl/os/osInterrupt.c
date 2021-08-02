#include "osInterrupt.h"

#include <hardware.h>
#include <string.h>

#include "osException.h"

// Extern function references.
// PAL: 0x801a1f58
extern void OSLoadContext(OSContext* context);
// PAL: 0x801a98e8
extern UNKNOWN_FUNCTION(OSDisableScheduler);
// PAL: 0x801a9924
extern UNKNOWN_FUNCTION(OSEnableScheduler);
// PAL: 0x801a9e30
extern UNKNOWN_FUNCTION(__OSReschedule);

static __OSInterruptHandler* OSInterruptHandlerTable;
static u32 OSInterruptPrioTable[] = {
    0x00000100, 0x00000040, 0xf8000000, 0x00000200, 0x00000080, 0x00000010,
    0x00003000, 0x00000020, 0x03ff8c00, 0x04000000, 0x00004000, 0xffffffff,
};

#define OS_INTERRUPTTABLE_ADDR 0x3040
#define OS_INTERRUPTMASK_ADDR 0x00C4
#define OS_UINTERRUPTMASK_ADDR 0x00C8

static void ExternalInterruptHandler(register u8 exception,
                                     register OSContext* context);

// Symbol: OSDisableInterrupts
// PAL: 0x801a65ac..0x801a65c0
asm int OSDisableInterrupts(void) {
  nofralloc;
  mfmsr r3;
  rlwinm r4, r3, 0, 0x11, 0xf;
  mtmsr r4;
  rlwinm r3, r3, 0x11, 0x1f, 0x1f;
  blr;
}

// Symbol: OSEnableInterrupts
// PAL: 0x801a65c0..0x801a65d4
asm int OSEnableInterrupts(void) {
  nofralloc;
  mfmsr r3;
  ori r4, r3, 0x8000;
  mtmsr r4;
  rlwinm r3, r3, 0x11, 0x1f, 0x1f;
  blr;
}

// Symbol: OSRestoreInterrupts
// PAL: 0x801a65d4..0x801a65f8
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

// Symbol: __OSSetInterruptHandler
// PAL: 0x801a65f8..0x801a660c
__OSInterruptHandler __OSSetInterruptHandler(s16 interrupt,
                                             __OSInterruptHandler handler) {
  __OSInterruptHandler old = OSInterruptHandlerTable[interrupt];
  OSInterruptHandlerTable[interrupt] = handler;
  return old;
}

// Symbol: __OSGetInterruptHandler
// PAL: 0x801a660c..0x801a661c
__OSInterruptHandler __OSGetInterruptHandler(s16 interrupt) {
  return OSInterruptHandlerTable[interrupt];
}

inline void* OSPhysicalToCached(u32 addr) { return (void*)(addr + 0x80000000); }

// Symbol: __OSInterruptInit
// PAL: 0x801a661c..0x801a66e0
void __OSInterruptInit(void) {
  OSInterruptHandlerTable =
      (__OSInterruptHandler*)OSPhysicalToCached(OS_INTERRUPTTABLE_ADDR);
  memset((void*)OSInterruptHandlerTable, 0, 32 * sizeof(__OSInterruptHandler));
  *(u32*)OSPhysicalToCached(OS_INTERRUPTMASK_ADDR) = 0;
  *(u32*)OSPhysicalToCached(OS_UINTERRUPTMASK_ADDR) = 0;
  __PIRegs[PI_REG_INTMSK / 4] =
      PI_INTMSK_REG_EXMSK_MASK | PI_INTMSK_REG_AIMSK_MASK |
      PI_INTMSK_REG_DSPMSK_MASK | PI_INTMSK_REG_MEMMSK_MASK;
  __ACRRegs[ACRPPCINTEN_OFFSET / 4] = ACRINTSTS_ACRIPCPPC_MASK;
  __OSMaskInterrupts(OS_INTERRUPTMASK_MEM | OS_INTERRUPTMASK_DSP |
                     OS_INTERRUPTMASK_AI | OS_INTERRUPTMASK_EXI |
                     OS_INTERRUPTMASK_PI);
  __OSSetExceptionHandler(4, ExternalInterruptHandler);
}

// Symbol: SetInterruptMask
// PAL: 0x801a66e0..0x801a693c
MARK_BINARY_BLOB(SetInterruptMask, 0x801a66e0, 0x801a693c);
static asm u32 SetInterruptMask(u32 mask, u32 current) {
  // clang-format off
  nofralloc;
  cntlzw r0, r3;
  cmpwi r0, 0xc;
  bge lbl_801a670c;
  cmpwi r0, 8;
  beq lbl_801a67bc;
  bge lbl_801a67e8;
  cmpwi r0, 5;
  bge lbl_801a677c;
  cmpwi r0, 0;
  bge lbl_801a672c;
  blr;
lbl_801a670c:
  cmpwi r0, 0x11;
  bge lbl_801a6720;
  cmpwi r0, 0xf;
  bge lbl_801a6870;
  b lbl_801a682c;
lbl_801a6720:
  cmpwi r0, 0x1c;
  bgelr;
  b lbl_801a68a4;
lbl_801a672c:
  rlwinm. r0, r4, 0, 0, 0;
  li r5, 0;
  bne lbl_801a673c;
  ori r5, r5, 1;
lbl_801a673c:
  rlwinm. r0, r4, 0, 1, 1;
  bne lbl_801a6748;
  ori r5, r5, 2;
lbl_801a6748:
  rlwinm. r0, r4, 0, 2, 2;
  bne lbl_801a6754;
  ori r5, r5, 4;
lbl_801a6754:
  rlwinm. r0, r4, 0, 3, 3;
  bne lbl_801a6760;
  ori r5, r5, 8;
lbl_801a6760:
  rlwinm. r0, r4, 0, 4, 4;
  bne lbl_801a676c;
  ori r5, r5, 0x10;
lbl_801a676c:
  lis r4, 0xcc00;
  clrlwi r3, r3, 5;
  sth r5, 0x401c(r4);
  blr;
lbl_801a677c:
  lis r5, 0xcc00;
  rlwinm. r0, r4, 0, 5, 5;
  lhz r5, 0x500a(r5);
  rlwinm r5, r5, 0, 0x1d, 0x16;
  bne lbl_801a6794;
  ori r5, r5, 0x10;
lbl_801a6794:
  rlwinm. r0, r4, 0, 6, 6;
  bne lbl_801a67a0;
  ori r5, r5, 0x40;
lbl_801a67a0:
  rlwinm. r0, r4, 0, 7, 7;
  bne lbl_801a67ac;
  ori r5, r5, 0x100;
lbl_801a67ac:
  lis r4, 0xcc00;
  rlwinm r3, r3, 0, 8, 4;
  sth r5, 0x500a(r4);
  blr;
lbl_801a67bc:
  rlwinm. r0, r4, 0, 8, 8;
  lis r4, 0xcd00;
  lwz r5, 0x6c00(r4);
  li r0, -45;
  and r5, r5, r0;
  bne lbl_801a67d8;
  ori r5, r5, 4;
lbl_801a67d8:
  lis r4, 0xcd00;
  rlwinm r3, r3, 0, 9, 7;
  stw r5, 0x6c00(r4);
  blr;
lbl_801a67e8:
  rlwinm. r0, r4, 0, 9, 9;
  lis r5, 0xcd00;
  lwz r5, 0x6800(r5);
  li r0, -11280;
  and r5, r5, r0;
  bne lbl_801a6804;
  ori r5, r5, 1;
lbl_801a6804:
  rlwinm. r0, r4, 0, 0xa, 0xa;
  bne lbl_801a6810;
  ori r5, r5, 4;
lbl_801a6810:
  rlwinm. r0, r4, 0, 0xb, 0xb;
  bne lbl_801a681c;
  ori r5, r5, 0x400;
lbl_801a681c:
  lis r4, 0xcd00;
  rlwinm r3, r3, 0, 0xc, 8;
  stw r5, 0x6800(r4);
  blr;
lbl_801a682c:
  rlwinm. r0, r4, 0, 0xc, 0xc;
  lis r5, 0xcd00;
  lwz r5, 0x6814(r5);
  li r0, -3088;
  and r5, r5, r0;
  bne lbl_801a6848;
  ori r5, r5, 1;
lbl_801a6848:
  rlwinm. r0, r4, 0, 0xd, 0xd;
  bne lbl_801a6854;
  ori r5, r5, 4;
lbl_801a6854:
  rlwinm. r0, r4, 0, 0xe, 0xe;
  bne lbl_801a6860;
  ori r5, r5, 0x400;
lbl_801a6860:
  lis r4, 0xcd00;
  rlwinm r3, r3, 0, 0xf, 0xb;
  stw r5, 0x6814(r4);
  blr;
lbl_801a6870:
  lis r5, 0xcd00;
  rlwinm. r0, r4, 0, 0xf, 0xf;
  lwz r5, 0x6828(r5);
  rlwinm r5, r5, 0, 0, 0x1b;
  bne lbl_801a6888;
  ori r5, r5, 1;
lbl_801a6888:
  rlwinm. r0, r4, 0, 0x10, 0x10;
  bne lbl_801a6894;
  ori r5, r5, 4;
lbl_801a6894:
  lis r4, 0xcd00;
  rlwinm r3, r3, 0, 0x11, 0xe;
  stw r5, 0x6828(r4);
  blr;
lbl_801a68a4:
  rlwinm. r0, r4, 0, 0x11, 0x11;
  li r5, 0xf0;
  bne lbl_801a68b4;
  ori r5, r5, 0x800;
lbl_801a68b4:
  rlwinm. r0, r4, 0, 0x14, 0x14;
  bne lbl_801a68c0;
  ori r5, r5, 8;
lbl_801a68c0:
  rlwinm. r0, r4, 0, 0x15, 0x15;
  bne lbl_801a68cc;
  ori r5, r5, 4;
lbl_801a68cc:
  rlwinm. r0, r4, 0, 0x16, 0x16;
  bne lbl_801a68d8;
  ori r5, r5, 2;
lbl_801a68d8:
  rlwinm. r0, r4, 0, 0x17, 0x17;
  bne lbl_801a68e4;
  ori r5, r5, 1;
lbl_801a68e4:
  rlwinm. r0, r4, 0, 0x18, 0x18;
  bne lbl_801a68f0;
  ori r5, r5, 0x100;
lbl_801a68f0:
  rlwinm. r0, r4, 0, 0x19, 0x19;
  bne lbl_801a68fc;
  ori r5, r5, 0x1000;
lbl_801a68fc:
  rlwinm. r0, r4, 0, 0x12, 0x12;
  bne lbl_801a6908;
  ori r5, r5, 0x200;
lbl_801a6908:
  rlwinm. r0, r4, 0, 0x13, 0x13;
  bne lbl_801a6914;
  ori r5, r5, 0x400;
lbl_801a6914:
  rlwinm. r0, r4, 0, 0x1a, 0x1a;
  bne lbl_801a6920;
  ori r5, r5, 0x2000;
lbl_801a6920:
  rlwinm. r0, r4, 0, 0x1b, 0x1b;
  bne lbl_801a692c;
  ori r5, r5, 0x4000;
lbl_801a692c:
  lis r4, 0xcc00;
  rlwinm r3, r3, 0, 0x1c, 0x10;
  stw r5, 0x3004(r4);
  blr;
  // clang-format on
}

// Symbol: __OSMaskInterrupts
// PAL: 0x801a693c..0x801a69bc
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

// Symbol: __OSUnmaskInterrupts
// PAL: 0x801a69bc..0x801a6a3c
MARK_BINARY_BLOB(__OSUnmaskInterrupts, 0x801a69bc, 0x801a6a3c);
asm u32 __OSUnmaskInterrupts(u32) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r3;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  bl OSDisableInterrupts;
  lis r4, 0x8000;
  mr r30, r3;
  lwz r29, 0xc4(r4);
  lwz r5, 0xc8(r4);
  or r0, r29, r5;
  and r3, r31, r0;
  andc r31, r29, r31;
  stw r31, 0xc4(r4);
  or r31, r31, r5;
  b lbl_801a6a0c;
lbl_801a6a04:
  mr r4, r31;
  bl SetInterruptMask;
lbl_801a6a0c:
  cmpwi r3, 0;
  bne lbl_801a6a04;
  mr r3, r30;
  bl OSRestoreInterrupts;
  lwz r31, 0x1c(r1);
  mr r3, r29;
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

volatile OSTime __OSLastInterruptTime;
volatile s16 __OSLastInterrupt;
volatile u32 __OSLastInterruptSrr0;

// Symbol: __OSDispatchInterrupt
// PAL: 0x801a6a3c..0x801a6ce0
void __OSDispatchInterrupt(u8, OSContext* context) {
  u32 intsr = __PIRegs[PI_REG_INTSR / 4];
  intsr &= ~PI_INTSR_REG_RSTVAL_MASK;
  u32 mask = __PIRegs[PI_REG_INTMSK / 4];
  if (intsr == 0 || (intsr & mask) == 0)
    OSLoadContext(context);
  u32 reg;
  u32 bits = 0;
  if (intsr & PI_INTSR_REG_MEMINT_MASK) {
    reg = __MEMRegs[MEM_INT_STAT_IDX];
    if (reg & MEM_INT_STAT_INT0_MASK)
      bits |= OS_INTERRUPTMASK_MEM_0;
    if (reg & MEM_INT_STAT_INT1_MASK)
      bits |= OS_INTERRUPTMASK_MEM_1;
    if (reg & MEM_INT_STAT_INT2_MASK)
      bits |= OS_INTERRUPTMASK_MEM_2;
    if (reg & MEM_INT_STAT_INT3_MASK)
      bits |= OS_INTERRUPTMASK_MEM_3;
    if (reg & MEM_INT_STAT_ADRERR_MASK)
      bits |= OS_INTERRUPTMASK_MEM_ADDRESS;
  }
  if (intsr & PI_INTSR_REG_DSPINT_MASK) {
    reg = __DSPRegs[DSP_CDCR_IDX];
    if (reg & DSP_CDCR_AIINT_MASK)
      bits |= OS_INTERRUPTMASK_DSP_AI;
    if (reg & DSP_CDCR_ARAMINT_MASK)
      bits |= OS_INTERRUPTMASK_DSP_ARAM;
    if (reg & DSP_CDCR_DSPINT_MASK)
      bits |= OS_INTERRUPTMASK_DSP_DSP;
  }
  if (intsr & PI_INTSR_REG_AIINT_MASK) {
    reg = __AIRegs[AI_CR_IDX];
    if (reg & AI_CR_AIINT_MASK)
      bits |= OS_INTERRUPTMASK_AI_AI;
  }
  if (intsr & PI_INTSR_REG_EXINT_MASK) {
    reg = __EXIRegs[EXI_0CPR_IDX];
    if (reg & EXI_0CPR_EXIINT_MASK)
      bits |= OS_INTERRUPTMASK_EXI_0_EXI;
    if (reg & EXI_0CPR_TCINT_MASK)
      bits |= OS_INTERRUPTMASK_EXI_0_TC;
    if (reg & EXI_0CPR_EXTINT_MASK)
      bits |= OS_INTERRUPTMASK_EXI_0_EXT;
    reg = __EXIRegs[EXI_1CPR_IDX];
    if (reg & EXI_1CPR_EXIINT_MASK)
      bits |= OS_INTERRUPTMASK_EXI_1_EXI;
    if (reg & EXI_1CPR_TCINT_MASK)
      bits |= OS_INTERRUPTMASK_EXI_1_TC;
    if (reg & EXI_1CPR_EXTINT_MASK)
      bits |= OS_INTERRUPTMASK_EXI_1_EXT;
    reg = __EXIRegs[EXI_2CPR_IDX];
    if (reg & EXI_2CPR_EXIINT_MASK)
      bits |= OS_INTERRUPTMASK_EXI_2_EXI;
    if (reg & EXI_2CPR_TCINT_MASK)
      bits |= OS_INTERRUPTMASK_EXI_2_TC;
  }
  if (intsr & PI_INTSR_REG_SDINT_MASK)
    bits |= OS_INTERRUPTMASK_PI_HSP;
  if (intsr & PI_INTSR_REG_DBGINT_MASK)
    bits |= OS_INTERRUPTMASK_PI_DEBUG;
  if (intsr & PI_INTSR_REG_PEINT1_MASK)
    bits |= OS_INTERRUPTMASK_PI_PE_FINISH;
  if (intsr & PI_INTSR_REG_PEINT0_MASK)
    bits |= OS_INTERRUPTMASK_PI_PE_TOKEN;
  if (intsr & PI_INTSR_REG_VIINT_MASK)
    bits |= OS_INTERRUPTMASK_PI_VI;
  if (intsr & PI_INTSR_REG_SIINT_MASK)
    bits |= OS_INTERRUPTMASK_PI_SI;
  if (intsr & PI_INTSR_REG_DIINT_MASK)
    bits |= OS_INTERRUPTMASK_PI_DI;
  if (intsr & PI_INTSR_REG_RSWINT_MASK)
    bits |= OS_INTERRUPTMASK_PI_RSW;
  if (intsr & PI_INTSR_REG_CPINT_MASK)
    bits |= OS_INTERRUPTMASK_PI_CP;
  if (intsr & PI_INTSR_REG_PIINT_MASK)
    bits |= OS_INTERRUPTMASK_PI_ERROR;
  if (intsr & PI_INTSR_REG_ACRINT_MASK)
    bits |= OS_INTERRUPTMASK_PI_ACR;
  u32 local5 = bits & ~(*(u32*)OSPhysicalToCached(OS_INTERRUPTMASK_ADDR) |
                        *(u32*)OSPhysicalToCached(OS_UINTERRUPTMASK_ADDR));
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
      if (__OS_INTERRUPT_MEM_ADDRESS < interrupt) {
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

// Symbol: ExternalInterruptHandler
// PAL: 0x801a6ce0..0x801a6d30
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
