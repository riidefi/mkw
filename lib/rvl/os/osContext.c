#include "osContext.h"

#include <rvl/db/db.h>

#include "osError.h"
#include "osException.h"
#include "osInterrupt.h"


volatile OSContext* __OSCurrentContext AT_ADDRESS(0x800000d4);
volatile OSContext* __OSFPUContext AT_ADDRESS(0x800000d8);

#ifdef __CWCC__

static asm void __OSLoadFPUContext(u32 unused, register OSContext* ctx) {
  // clang-format off
  nofralloc

  lhz r5, ctx->state
  clrlwi. r5, r5, 31
  beq _exit
  
  lfd f0, ctx->fpscr_pad
  mtfs f0
  mfspr r5, 0x398
  rlwinm. r5, r5, 3, 31, 31
  beq _load_fprs
  
  psq_l f0, OSContext.psf[0](ctx), 0, 0
  psq_l f1, OSContext.psf[1](ctx), 0, 0
  psq_l f2, OSContext.psf[2](ctx), 0, 0
  psq_l f3, OSContext.psf[3](ctx), 0, 0
  psq_l f4, OSContext.psf[4](ctx), 0, 0
  psq_l f5, OSContext.psf[5](ctx), 0, 0
  psq_l f6, OSContext.psf[6](ctx), 0, 0
  psq_l f7, OSContext.psf[7](ctx), 0, 0
  psq_l f8, OSContext.psf[8](ctx), 0, 0
  psq_l f9, OSContext.psf[9](ctx), 0, 0
  psq_l f10, OSContext.psf[10](ctx), 0, 0
  psq_l f11, OSContext.psf[11](ctx), 0, 0
  psq_l f12, OSContext.psf[12](ctx), 0, 0
  psq_l f13, OSContext.psf[13](ctx), 0, 0
  psq_l f14, OSContext.psf[14](ctx), 0, 0
  psq_l f15, OSContext.psf[15](ctx), 0, 0
  psq_l f16, OSContext.psf[16](ctx), 0, 0
  psq_l f17, OSContext.psf[17](ctx), 0, 0
  psq_l f18, OSContext.psf[18](ctx), 0, 0
  psq_l f19, OSContext.psf[19](ctx), 0, 0
  psq_l f20, OSContext.psf[20](ctx), 0, 0
  psq_l f21, OSContext.psf[21](ctx), 0, 0
  psq_l f22, OSContext.psf[22](ctx), 0, 0
  psq_l f23, OSContext.psf[23](ctx), 0, 0
  psq_l f24, OSContext.psf[24](ctx), 0, 0
  psq_l f25, OSContext.psf[25](ctx), 0, 0
  psq_l f26, OSContext.psf[26](ctx), 0, 0
  psq_l f27, OSContext.psf[27](ctx), 0, 0
  psq_l f28, OSContext.psf[28](ctx), 0, 0
  psq_l f29, OSContext.psf[29](ctx), 0, 0
  psq_l f30, OSContext.psf[30](ctx), 0, 0
  psq_l f31, OSContext.psf[31](ctx), 0, 0

_load_fprs:
  lfd f0, ctx->fpr[0]
  lfd f1, ctx->fpr[1]
  lfd f2, ctx->fpr[2]
  lfd f3, ctx->fpr[3]
  lfd f4, ctx->fpr[4]
  lfd f5, ctx->fpr[5]
  lfd f6, ctx->fpr[6]
  lfd f7, ctx->fpr[7]
  lfd f8, ctx->fpr[8]
  lfd f9, ctx->fpr[9]
  lfd f10, ctx->fpr[10]
  lfd f11, ctx->fpr[11]
  lfd f12, ctx->fpr[12]
  lfd f13, ctx->fpr[13]
  lfd f14, ctx->fpr[14]
  lfd f15, ctx->fpr[15]
  lfd f16, ctx->fpr[16]
  lfd f17, ctx->fpr[17]
  lfd f18, ctx->fpr[18]
  lfd f19, ctx->fpr[19]
  lfd f20, ctx->fpr[20]
  lfd f21, ctx->fpr[21]
  lfd f22, ctx->fpr[22]
  lfd f23, ctx->fpr[23]
  lfd f24, ctx->fpr[24]
  lfd f25, ctx->fpr[25]
  lfd f26, ctx->fpr[26]
  lfd f27, ctx->fpr[27]
  lfd f28, ctx->fpr[28]
  lfd f29, ctx->fpr[29]
  lfd f30, ctx->fpr[30]
  lfd f31, ctx->fpr[31]

_exit:
  blr
  // clang-format on
}

static asm void __OSSaveFPUContext(u32 unused, u32 unused1,
                                 register OSContext* ctx) {
  // clang-format off
  nofralloc
  
  lhz r3, ctx->state
  ori r3, r3, OS_CONTEXT_STATE_FP_SAVED
  sth r3, ctx->state

  stfd f0, ctx->fpr[0]
  stfd f1, ctx->fpr[1]
  stfd f2, ctx->fpr[2]
  stfd f3, ctx->fpr[3]
  stfd f4, ctx->fpr[4]
  stfd f5, ctx->fpr[5]
  stfd f6, ctx->fpr[6]
  stfd f7, ctx->fpr[7]
  stfd f8, ctx->fpr[8]
  stfd f9, ctx->fpr[9]
  stfd f10, ctx->fpr[10]
  stfd f11, ctx->fpr[11]
  stfd f12, ctx->fpr[12]
  stfd f13, ctx->fpr[13]
  stfd f14, ctx->fpr[14]
  stfd f15, ctx->fpr[15]
  stfd f16, ctx->fpr[16]
  stfd f17, ctx->fpr[17]
  stfd f18, ctx->fpr[18]
  stfd f19, ctx->fpr[19]
  stfd f20, ctx->fpr[20]
  stfd f21, ctx->fpr[21]
  stfd f22, ctx->fpr[22]
  stfd f23, ctx->fpr[23]
  stfd f24, ctx->fpr[24]
  stfd f25, ctx->fpr[25]
  stfd f26, ctx->fpr[26]
  stfd f27, ctx->fpr[27]
  stfd f28, ctx->fpr[28]
  stfd f29, ctx->fpr[29]
  stfd f30, ctx->fpr[30]
  stfd f31, ctx->fpr[31]

  mffs f0
  stfd f0, ctx->fpscr_pad
  lfd f0, ctx->fpr[0]
  mfspr r3, 0x398
  rlwinm. r3, r3, 3, 31, 31
  beq _exit

  psq_st f0, OSContext.psf[0](ctx), 0, 0
  psq_st f1, OSContext.psf[1](ctx), 0, 0
  psq_st f2, OSContext.psf[2](ctx), 0, 0
  psq_st f3, OSContext.psf[3](ctx), 0, 0
  psq_st f4, OSContext.psf[4](ctx), 0, 0
  psq_st f5, OSContext.psf[5](ctx), 0, 0
  psq_st f6, OSContext.psf[6](ctx), 0, 0
  psq_st f7, OSContext.psf[7](ctx), 0, 0
  psq_st f8, OSContext.psf[8](ctx), 0, 0
  psq_st f9, OSContext.psf[9](ctx), 0, 0
  psq_st f10, OSContext.psf[10](ctx), 0, 0
  psq_st f11, OSContext.psf[11](ctx), 0, 0
  psq_st f12, OSContext.psf[12](ctx), 0, 0
  psq_st f13, OSContext.psf[13](ctx), 0, 0
  psq_st f14, OSContext.psf[14](ctx), 0, 0
  psq_st f15, OSContext.psf[15](ctx), 0, 0
  psq_st f16, OSContext.psf[16](ctx), 0, 0
  psq_st f17, OSContext.psf[17](ctx), 0, 0
  psq_st f18, OSContext.psf[18](ctx), 0, 0
  psq_st f19, OSContext.psf[19](ctx), 0, 0
  psq_st f20, OSContext.psf[20](ctx), 0, 0
  psq_st f21, OSContext.psf[21](ctx), 0, 0
  psq_st f22, OSContext.psf[22](ctx), 0, 0
  psq_st f23, OSContext.psf[23](ctx), 0, 0
  psq_st f24, OSContext.psf[24](ctx), 0, 0
  psq_st f25, OSContext.psf[25](ctx), 0, 0
  psq_st f26, OSContext.psf[26](ctx), 0, 0
  psq_st f27, OSContext.psf[27](ctx), 0, 0
  psq_st f28, OSContext.psf[28](ctx), 0, 0
  psq_st f29, OSContext.psf[29](ctx), 0, 0
  psq_st f30, OSContext.psf[30](ctx), 0, 0
  psq_st f31, OSContext.psf[31](ctx), 0, 0

_exit:
  blr
  // clang-format on
}


// Symbol: OSSaveFPUContext
// PAL: 0x801a1e68..0x801a1e70
asm void OSSaveFPUContext(register OSContext* ctx) {
  nofralloc;
  addi r5, ctx, 0;
  b __OSSaveFPUContext;
}

#endif

// Symbol: OSGetCurrentContext
// PAL: 0x801a1ecc..0x801a1ed8
OSContext* OSGetCurrentContext(void) { return (OSContext*)__OSCurrentContext; }

#ifdef __CWCC__

// Symbol: OSGetStackPointer
// PAL: 0x801a2030..0x801a2038
asm u32 OSGetStackPointer(void) {
  nofralloc;
  mr r3, r1;
  blr;
}

#endif

// Symbol: OSClearContext
// PAL: 0x801a2098..0x801a20bc
void OSClearContext(OSContext* context) {
  context->mode = 0;
  context->state = 0;
  if (context == __OSFPUContext)
    __OSFPUContext = NULL;
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
