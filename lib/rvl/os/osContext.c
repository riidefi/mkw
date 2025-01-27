#include "osContext.h"

#include "osError.h"
#include "osException.h"
#include "osInterrupt.h"

// Extern function references.
// PAL: 0x8015d3ac
extern UNKNOWN_FUNCTION(DBPrintf);

volatile OSContext* __OSCurrentContext : 0x800000d4;
volatile OSContext* __OSFPUContext : 0x800000d8;

// Symbol: __OSLoadFPUContext
// PAL: 0x801a1c1c..0x801a1d40
MARK_BINARY_BLOB(__OSLoadFPUContext, 0x801a1c1c, 0x801a1d40);
asm UNKNOWN_FUNCTION(__OSLoadFPUContext) {
  // clang-format off
  nofralloc;
  lhz r5, 0x1a2(r4);
  clrlwi. r5, r5, 0x1f;
  beq lbl_801a1d3c;
  lfd f0, 0x190(r4);
  mtfsf 0xff, f0;
  mfspr r5, 0x398;
  rlwinm. r5, r5, 3, 0x1f, 0x1f;
  beq lbl_801a1cbc;
  psq_l f0, 456(r4), 0, 0;
  psq_l f1, 464(r4), 0, 0;
  psq_l f2, 472(r4), 0, 0;
  psq_l f3, 480(r4), 0, 0;
  psq_l f4, 488(r4), 0, 0;
  psq_l f5, 496(r4), 0, 0;
  psq_l f6, 504(r4), 0, 0;
  psq_l f7, 512(r4), 0, 0;
  psq_l f8, 520(r4), 0, 0;
  psq_l f9, 528(r4), 0, 0;
  psq_l f10, 536(r4), 0, 0;
  psq_l f11, 544(r4), 0, 0;
  psq_l f12, 552(r4), 0, 0;
  psq_l f13, 560(r4), 0, 0;
  psq_l f14, 568(r4), 0, 0;
  psq_l f15, 576(r4), 0, 0;
  psq_l f16, 584(r4), 0, 0;
  psq_l f17, 592(r4), 0, 0;
  psq_l f18, 600(r4), 0, 0;
  psq_l f19, 608(r4), 0, 0;
  psq_l f20, 616(r4), 0, 0;
  psq_l f21, 624(r4), 0, 0;
  psq_l f22, 632(r4), 0, 0;
  psq_l f23, 640(r4), 0, 0;
  psq_l f24, 648(r4), 0, 0;
  psq_l f25, 656(r4), 0, 0;
  psq_l f26, 664(r4), 0, 0;
  psq_l f27, 672(r4), 0, 0;
  psq_l f28, 680(r4), 0, 0;
  psq_l f29, 688(r4), 0, 0;
  psq_l f30, 696(r4), 0, 0;
  psq_l f31, 704(r4), 0, 0;
lbl_801a1cbc:
  lfd f0, 0x90(r4);
  lfd f1, 0x98(r4);
  lfd f2, 0xa0(r4);
  lfd f3, 0xa8(r4);
  lfd f4, 0xb0(r4);
  lfd f5, 0xb8(r4);
  lfd f6, 0xc0(r4);
  lfd f7, 0xc8(r4);
  lfd f8, 0xd0(r4);
  lfd f9, 0xd8(r4);
  lfd f10, 0xe0(r4);
  lfd f11, 0xe8(r4);
  lfd f12, 0xf0(r4);
  lfd f13, 0xf8(r4);
  lfd f14, 0x100(r4);
  lfd f15, 0x108(r4);
  lfd f16, 0x110(r4);
  lfd f17, 0x118(r4);
  lfd f18, 0x120(r4);
  lfd f19, 0x128(r4);
  lfd f20, 0x130(r4);
  lfd f21, 0x138(r4);
  lfd f22, 0x140(r4);
  lfd f23, 0x148(r4);
  lfd f24, 0x150(r4);
  lfd f25, 0x158(r4);
  lfd f26, 0x160(r4);
  lfd f27, 0x168(r4);
  lfd f28, 0x170(r4);
  lfd f29, 0x178(r4);
  lfd f30, 0x180(r4);
  lfd f31, 0x188(r4);
lbl_801a1d3c:
  blr;
  // clang-format on
}

// Symbol: __OSSaveFPUContext
// PAL: 0x801a1d40..0x801a1e68
MARK_BINARY_BLOB(__OSSaveFPUContext, 0x801a1d40, 0x801a1e68);
asm UNKNOWN_FUNCTION(__OSSaveFPUContext) {
  // clang-format off
  nofralloc;
  lhz r3, 0x1a2(r5);
  ori r3, r3, 1;
  sth r3, 0x1a2(r5);
  stfd f0, 0x90(r5);
  stfd f1, 0x98(r5);
  stfd f2, 0xa0(r5);
  stfd f3, 0xa8(r5);
  stfd f4, 0xb0(r5);
  stfd f5, 0xb8(r5);
  stfd f6, 0xc0(r5);
  stfd f7, 0xc8(r5);
  stfd f8, 0xd0(r5);
  stfd f9, 0xd8(r5);
  stfd f10, 0xe0(r5);
  stfd f11, 0xe8(r5);
  stfd f12, 0xf0(r5);
  stfd f13, 0xf8(r5);
  stfd f14, 0x100(r5);
  stfd f15, 0x108(r5);
  stfd f16, 0x110(r5);
  stfd f17, 0x118(r5);
  stfd f18, 0x120(r5);
  stfd f19, 0x128(r5);
  stfd f20, 0x130(r5);
  stfd f21, 0x138(r5);
  stfd f22, 0x140(r5);
  stfd f23, 0x148(r5);
  stfd f24, 0x150(r5);
  stfd f25, 0x158(r5);
  stfd f26, 0x160(r5);
  stfd f27, 0x168(r5);
  stfd f28, 0x170(r5);
  stfd f29, 0x178(r5);
  stfd f30, 0x180(r5);
  stfd f31, 0x188(r5);
  mffs f0;
  stfd f0, 0x190(r5);
  lfd f0, 0x90(r5);
  mfspr r3, 0x398;
  rlwinm. r3, r3, 3, 0x1f, 0x1f;
  beq lbl_801a1e64;
  psq_st f0, 456(r5), 0, 0;
  psq_st f1, 464(r5), 0, 0;
  psq_st f2, 472(r5), 0, 0;
  psq_st f3, 480(r5), 0, 0;
  psq_st f4, 488(r5), 0, 0;
  psq_st f5, 496(r5), 0, 0;
  psq_st f6, 504(r5), 0, 0;
  psq_st f7, 512(r5), 0, 0;
  psq_st f8, 520(r5), 0, 0;
  psq_st f9, 528(r5), 0, 0;
  psq_st f10, 536(r5), 0, 0;
  psq_st f11, 544(r5), 0, 0;
  psq_st f12, 552(r5), 0, 0;
  psq_st f13, 560(r5), 0, 0;
  psq_st f14, 568(r5), 0, 0;
  psq_st f15, 576(r5), 0, 0;
  psq_st f16, 584(r5), 0, 0;
  psq_st f17, 592(r5), 0, 0;
  psq_st f18, 600(r5), 0, 0;
  psq_st f19, 608(r5), 0, 0;
  psq_st f20, 616(r5), 0, 0;
  psq_st f21, 624(r5), 0, 0;
  psq_st f22, 632(r5), 0, 0;
  psq_st f23, 640(r5), 0, 0;
  psq_st f24, 648(r5), 0, 0;
  psq_st f25, 656(r5), 0, 0;
  psq_st f26, 664(r5), 0, 0;
  psq_st f27, 672(r5), 0, 0;
  psq_st f28, 680(r5), 0, 0;
  psq_st f29, 688(r5), 0, 0;
  psq_st f30, 696(r5), 0, 0;
  psq_st f31, 704(r5), 0, 0;
lbl_801a1e64:
  blr;
  // clang-format on
}

// Symbol: OSSaveFPUContext
// PAL: 0x801a1e68..0x801a1e70
asm void OSSaveFPUContext(register OSContext* ctx) {
  nofralloc;
  addi r5, ctx, 0;
  b __OSSaveFPUContext;
}

// Symbol: OSSetCurrentContext
// PAL: 0x801a1e70..0x801a1ecc
MARK_BINARY_BLOB(OSSetCurrentContext, 0x801a1e70, 0x801a1ecc);
asm void OSSetCurrentContext(OSContext* context) {
  // clang-format off
  nofralloc;
  lis r4, 0x8000;
  stw r3, 0xd4(r4);
  clrlwi r5, r3, 2;
  stw r5, 0xc0(r4);
  lwz r5, 0xd8(r4);
  cmpw r5, r3;
  bne lbl_801a1ea8;
  lwz r6, 0x19c(r3);
  ori r6, r6, 0x2000;
  stw r6, 0x19c(r3);
  mfmsr r6;
  ori r6, r6, 2;
  mtmsr r6;
  blr;
lbl_801a1ea8:
  lwz r6, 0x19c(r3);
  rlwinm r6, r6, 0, 0x13, 0x11;
  stw r6, 0x19c(r3);
  mfmsr r6;
  rlwinm r6, r6, 0, 0x13, 0x11;
  ori r6, r6, 2;
  mtmsr r6;
  isync;
  blr;
  // clang-format on
}

// Symbol: OSGetCurrentContext
// PAL: 0x801a1ecc..0x801a1ed8
OSContext* OSGetCurrentContext(void) { return (OSContext*)__OSCurrentContext; }

// Symbol: OSSaveContext
// PAL: 0x801a1ed8..0x801a1f58
MARK_BINARY_BLOB(OSSaveContext, 0x801a1ed8, 0x801a1f58);
asm UNKNOWN_FUNCTION(OSSaveContext) {
  // clang-format off
  nofralloc;
  stmw r13, 0x34(r3);
  mfspr r0, 0x391;
  stw r0, 0x1a8(r3);
  mfspr r0, 0x392;
  stw r0, 0x1ac(r3);
  mfspr r0, 0x393;
  stw r0, 0x1b0(r3);
  mfspr r0, 0x394;
  stw r0, 0x1b4(r3);
  mfspr r0, 0x395;
  stw r0, 0x1b8(r3);
  mfspr r0, 0x396;
  stw r0, 0x1bc(r3);
  mfspr r0, 0x397;
  stw r0, 0x1c0(r3);
  mfcr r0;
  stw r0, 0x80(r3);
  mflr r0;
  stw r0, 0x84(r3);
  stw r0, 0x198(r3);
  mfmsr r0;
  stw r0, 0x19c(r3);
  mfctr r0;
  stw r0, 0x88(r3);
  mfxer r0;
  stw r0, 0x8c(r3);
  stw r1, 4(r3);
  stw r2, 8(r3);
  li r0, 1;
  stw r0, 0xc(r3);
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: OSLoadContext
// PAL: 0x801a1f58..0x801a2030
MARK_BINARY_BLOB(OSLoadContext, 0x801a1f58, 0x801a2030);
asm void OSLoadContext(OSContext* context) {
  // clang-format off
  nofralloc;
  lis r4, 0x801a;
  lwz r6, 0x198(r3);
  addi r5, r4, 0x65ac;
  cmplw r6, r5;
  ble lbl_801a1f80;
  lis r4, 0x801a;
  addi r0, r4, 0x65b8;
  cmplw r6, r0;
  bge lbl_801a1f80;
  stw r5, 0x198(r3);
lbl_801a1f80:
  lwz r0, 0(r3);
  lwz r1, 4(r3);
  lwz r2, 8(r3);
  lhz r4, 0x1a2(r3);
  rlwinm. r5, r4, 0, 0x1e, 0x1e;
  beq lbl_801a1fa8;
  rlwinm r4, r4, 0, 0x1f, 0x1d;
  sth r4, 0x1a2(r3);
  lmw r5, 0x14(r3);
  b lbl_801a1fac;
lbl_801a1fa8:
  lmw r13, 0x34(r3);
lbl_801a1fac:
  lwz r4, 0x1a8(r3);
  mtspr 0x391, r4;
  lwz r4, 0x1ac(r3);
  mtspr 0x392, r4;
  lwz r4, 0x1b0(r3);
  mtspr 0x393, r4;
  lwz r4, 0x1b4(r3);
  mtspr 0x394, r4;
  lwz r4, 0x1b8(r3);
  mtspr 0x395, r4;
  lwz r4, 0x1bc(r3);
  mtspr 0x396, r4;
  lwz r4, 0x1c0(r3);
  mtspr 0x397, r4;
  lwz r4, 0x80(r3);
  mtcrf 0xff, r4;
  lwz r4, 0x84(r3);
  mtlr r4;
  lwz r4, 0x88(r3);
  mtctr r4;
  lwz r4, 0x8c(r3);
  mtxer r4;
  mfmsr r4;
  rlwinm r4, r4, 0, 0x11, 0xf;
  rlwinm r4, r4, 0, 0x1f, 0x1d;
  mtmsr r4;
  lwz r4, 0x198(r3);
  mtspr 0x1a, r4;
  lwz r4, 0x19c(r3);
  mtspr 0x1b, r4;
  lwz r4, 0x10(r3);
  lwz r3, 0xc(r3);
  rfi;
  // clang-format on
}

// Symbol: OSGetStackPointer
// PAL: 0x801a2030..0x801a2038
asm u32 OSGetStackPointer(void) {
  nofralloc;
  mr r3, r1;
  blr;
}

// Symbol: OSSwitchFiber
// PAL: 0x801a2038..0x801a2068
MARK_BINARY_BLOB(OSSwitchFiber, 0x801a2038, 0x801a2068);
asm UNKNOWN_FUNCTION(OSSwitchFiber) {
  // clang-format off
  nofralloc;
  mflr r0;
  mr r5, r1;
  stwu r5, -8(r4);
  mr r1, r4;
  stw r0, 4(r5);
  mtlr r3;
  blrl;
  lwz r5, 0(r1);
  lwz r0, 4(r5);
  mtlr r0;
  mr r1, r5;
  blr;
  // clang-format on
}

// Symbol: OSSwitchFiberEx
// PAL: 0x801a2068..0x801a2098
MARK_BINARY_BLOB(OSSwitchFiberEx, 0x801a2068, 0x801a2098);
asm UNKNOWN_FUNCTION(OSSwitchFiberEx) {
  // clang-format off
  nofralloc;
  mflr r0;
  mr r9, r1;
  stwu r9, -8(r8);
  mr r1, r8;
  stw r0, 4(r9);
  mtlr r7;
  blrl;
  lwz r5, 0(r1);
  lwz r0, 4(r5);
  mtlr r0;
  mr r1, r5;
  blr;
  // clang-format on
}

// Symbol: OSClearContext
// PAL: 0x801a2098..0x801a20bc
void OSClearContext(OSContext* context) {
  context->mode = 0;
  context->state = 0;
  if (context == __OSFPUContext)
    __OSFPUContext = NULL;
}

// Symbol: OSInitContext
// PAL: 0x801a20bc..0x801a2178
MARK_BINARY_BLOB(OSInitContext, 0x801a20bc, 0x801a2178);
asm void OSInitContext(OSContext* context, u32 pc, u32 sp) {
  // clang-format off
  nofralloc;
  stw r4, 0x198(r3);
  stw r5, 4(r3);
  li r11, 0;
  ori r11, r11, 0x9032;
  stw r11, 0x19c(r3);
  li r0, 0;
  stw r0, 0x80(r3);
  stw r0, 0x8c(r3);
  stw r2, 8(r3);
  stw r13, 0x34(r3);
  stw r0, 0xc(r3);
  stw r0, 0x10(r3);
  stw r0, 0x14(r3);
  stw r0, 0x18(r3);
  stw r0, 0x1c(r3);
  stw r0, 0x20(r3);
  stw r0, 0x24(r3);
  stw r0, 0x28(r3);
  stw r0, 0x2c(r3);
  stw r0, 0x30(r3);
  stw r0, 0x38(r3);
  stw r0, 0x3c(r3);
  stw r0, 0x40(r3);
  stw r0, 0x44(r3);
  stw r0, 0x48(r3);
  stw r0, 0x4c(r3);
  stw r0, 0x50(r3);
  stw r0, 0x54(r3);
  stw r0, 0x58(r3);
  stw r0, 0x5c(r3);
  stw r0, 0x60(r3);
  stw r0, 0x64(r3);
  stw r0, 0x68(r3);
  stw r0, 0x6c(r3);
  stw r0, 0x70(r3);
  stw r0, 0x74(r3);
  stw r0, 0x78(r3);
  stw r0, 0x7c(r3);
  stw r0, 0x1a4(r3);
  stw r0, 0x1a8(r3);
  stw r0, 0x1ac(r3);
  stw r0, 0x1b0(r3);
  stw r0, 0x1b4(r3);
  stw r0, 0x1b8(r3);
  stw r0, 0x1bc(r3);
  stw r0, 0x1c0(r3);
  b OSClearContext;
  // clang-format on
}

// Symbol: OSDumpContext
// PAL: 0x801a2178..0x801a23d8
void OSDumpContext(OSContext* context) {
  OSReport(
      "------------------------- Context 0x%08x -------------------------\n",
      context);
  for (u32 i = 0; i < 16; ++i)
    OSReport("r%-2d  = 0x%08x (%14d)  r%-2d  = 0x%08x (%14d)\n", i,
             context->gpr[i], context->gpr[i], i + 16, context->gpr[i + 16],
             context->gpr[i + 16]);
  OSReport("LR   = 0x%08x                   CR   = 0x%08x\n", context->lr,
           context->cr);
  OSReport("SRR0 = 0x%08x                   SRR1 = 0x%08x\n", context->srr0,
           context->srr1);
  OSReport("\nGQRs----------\n");
  for (u32 i = 0; i < 4; ++i)
    OSReport("gqr%d = 0x%08x \t gqr%d = 0x%08x\n", i, context->gqr[i], i + 4,
             context->gqr[i + 4]);
  u32 i;
  if (context->state & 0x1u) {
    int interrupts = OSDisableInterrupts();
    OSContext* oldCtx = OSGetCurrentContext();
    OSContext newCtx;
    OSClearContext(&newCtx);
    OSSetCurrentContext(&newCtx);
    OSReport("\n\nFPRs----------\n");
    for (i = 0; i < 32; i += 2)
      OSReport("fr%d \t= %d \t fr%d \t= %d\n", i, (u32)context->fpr[i], i + 1,
               (u32)context->fpr[i + 1]);
    OSReport("\n\nPSFs----------\n");
    for (i = 0; i < 32; i += 2)
      OSReport("ps%d \t= 0x%x \t ps%d \t= 0x%x\n", i, (u32)context->psf[i],
               i + 1, (u32)context->psf[i + 1]);
    OSClearContext(&newCtx);
    OSSetCurrentContext(oldCtx);
    OSRestoreInterrupts(interrupts);
  }
  OSReport("\nAddress:      Back Chain    LR Save\n");
  u32* p;
  for (i = 0, p = (u32*)context->gpr[1]; p && (u32)p != 0xffffffff && i++ < 16;
       p = (u32*)*p) {
    OSReport("0x%08x:   0x%08x    0x%08x\n", p, p[0], p[1]);
  }
}

// Symbol: OSSwitchFPUContext
// PAL: 0x801a23d8..0x801a245c
MARK_BINARY_BLOB(OSSwitchFPUContext, 0x801a23d8, 0x801a245c);
asm UNKNOWN_FUNCTION(OSSwitchFPUContext) {
  // clang-format off
  nofralloc;
  mfmsr r5;
  ori r5, r5, 0x2000;
  mtmsr r5;
  isync;
  lwz r5, 0x19c(r4);
  ori r5, r5, 0x2000;
  mtspr 0x1b, r5;
  lis r3, 0x8000;
  lwz r5, 0xd8(r3);
  stw r4, 0xd8(r3);
  cmpw r5, r4;
  beq lbl_801a2418;
  cmpwi r5, 0;
  beq lbl_801a2414;
  bl __OSSaveFPUContext;
lbl_801a2414:
  bl __OSLoadFPUContext;
lbl_801a2418:
  lwz r3, 0x80(r4);
  mtcrf 0xff, r3;
  lwz r3, 0x84(r4);
  mtlr r3;
  lwz r3, 0x198(r4);
  mtspr 0x1a, r3;
  lwz r3, 0x88(r4);
  mtctr r3;
  lwz r3, 0x8c(r4);
  mtxer r3;
  lhz r3, 0x1a2(r4);
  rlwinm r3, r3, 0, 0x1f, 0x1d;
  sth r3, 0x1a2(r4);
  lwz r5, 0x14(r4);
  lwz r3, 0xc(r4);
  lwz r4, 0x10(r4);
  rfi;
  // clang-format on
}

// Symbol: __OSContextInit
// PAL: 0x801a245c..0x801a24a4
MARK_BINARY_BLOB(__OSContextInit, 0x801a245c, 0x801a24a4);
asm UNKNOWN_FUNCTION(__OSContextInit) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, 0x801a;
  li r3, 7;
  stw r0, 0x14(r1);
  addi r4, r4, 0x23d8;
  bl __OSSetExceptionHandler;
  li r0, 0;
  lis r4, 0x8000;
  lis r3, 0x8029;
  stw r0, 0xd8(r4);
  addi r3, r3, -2856;
  crclr 6;
  bl DBPrintf;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: OSFillFPUContext
// PAL: 0x801a24a4..0x801a25d0
MARK_BINARY_BLOB(OSFillFPUContext, 0x801a24a4, 0x801a25d0);
asm UNKNOWN_FUNCTION(OSFillFPUContext) {
  // clang-format off
  nofralloc;
  mfmsr r5;
  ori r5, r5, 0x2000;
  mtmsr r5;
  isync;
  stfd f0, 0x90(r3);
  stfd f1, 0x98(r3);
  stfd f2, 0xa0(r3);
  stfd f3, 0xa8(r3);
  stfd f4, 0xb0(r3);
  stfd f5, 0xb8(r3);
  stfd f6, 0xc0(r3);
  stfd f7, 0xc8(r3);
  stfd f8, 0xd0(r3);
  stfd f9, 0xd8(r3);
  stfd f10, 0xe0(r3);
  stfd f11, 0xe8(r3);
  stfd f12, 0xf0(r3);
  stfd f13, 0xf8(r3);
  stfd f14, 0x100(r3);
  stfd f15, 0x108(r3);
  stfd f16, 0x110(r3);
  stfd f17, 0x118(r3);
  stfd f18, 0x120(r3);
  stfd f19, 0x128(r3);
  stfd f20, 0x130(r3);
  stfd f21, 0x138(r3);
  stfd f22, 0x140(r3);
  stfd f23, 0x148(r3);
  stfd f24, 0x150(r3);
  stfd f25, 0x158(r3);
  stfd f26, 0x160(r3);
  stfd f27, 0x168(r3);
  stfd f28, 0x170(r3);
  stfd f29, 0x178(r3);
  stfd f30, 0x180(r3);
  stfd f31, 0x188(r3);
  mffs f0;
  stfd f0, 0x190(r3);
  lfd f0, 0x90(r3);
  mfspr r5, 0x398;
  rlwinm. r5, r5, 3, 0x1f, 0x1f;
  beq lbl_801a25cc;
  psq_st f0, 456(r3), 0, 0;
  psq_st f1, 464(r3), 0, 0;
  psq_st f2, 472(r3), 0, 0;
  psq_st f3, 480(r3), 0, 0;
  psq_st f4, 488(r3), 0, 0;
  psq_st f5, 496(r3), 0, 0;
  psq_st f6, 504(r3), 0, 0;
  psq_st f7, 512(r3), 0, 0;
  psq_st f8, 520(r3), 0, 0;
  psq_st f9, 528(r3), 0, 0;
  psq_st f10, 536(r3), 0, 0;
  psq_st f11, 544(r3), 0, 0;
  psq_st f12, 552(r3), 0, 0;
  psq_st f13, 560(r3), 0, 0;
  psq_st f14, 568(r3), 0, 0;
  psq_st f15, 576(r3), 0, 0;
  psq_st f16, 584(r3), 0, 0;
  psq_st f17, 592(r3), 0, 0;
  psq_st f18, 600(r3), 0, 0;
  psq_st f19, 608(r3), 0, 0;
  psq_st f20, 616(r3), 0, 0;
  psq_st f21, 624(r3), 0, 0;
  psq_st f22, 632(r3), 0, 0;
  psq_st f23, 640(r3), 0, 0;
  psq_st f24, 648(r3), 0, 0;
  psq_st f25, 656(r3), 0, 0;
  psq_st f26, 664(r3), 0, 0;
  psq_st f27, 672(r3), 0, 0;
  psq_st f28, 680(r3), 0, 0;
  psq_st f29, 688(r3), 0, 0;
  psq_st f30, 696(r3), 0, 0;
  psq_st f31, 704(r3), 0, 0;
lbl_801a25cc:
  blr;
  // clang-format on
}
