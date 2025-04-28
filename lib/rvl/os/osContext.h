#pragma once

#include <decomp.h>
#include <rk_types.h>

#include "osThread.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  OS_CONTEXT_STATE_FP_SAVED = (1 << 0),
} OSContextState;

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

void OSLoadFPUContext(OSContext*);
void OSSaveFPUContext(OSContext* ctx);
void OSSetCurrentContext(OSContext* context);
OSContext* OSGetCurrentContext(void);
void OSLoadContext(OSContext* context);
u32 OSGetStackPointer(void);
void OSClearContext(OSContext* context);
void OSInitContext(OSContext* context, u32 pc, u32 sp);
void OSDumpContext(OSContext*);

#ifdef __cplusplus
}
#endif
