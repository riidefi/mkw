#pragma once

#include <decomp.h>
#include <rk_types.h>

#include "osThread.h"

#ifdef __cplusplus
extern "C" {
#endif

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

// PAL: 0x801a1c1c..0x801a1d40
UNKNOWN_FUNCTION(__OSLoadFPUContext);
// PAL: 0x801a1d40..0x801a1e68
UNKNOWN_FUNCTION(__OSSaveFPUContext);
// PAL: 0x801a1e68..0x801a1e70
void OSLoadFPUContext(OSContext*);
// PAL: 0x801a1e68..0x801a1e70
void OSSaveFPUContext(OSContext* ctx);
// PAL: 0x801a1e70..0x801a1ecc
void OSSetCurrentContext(OSContext* context);
// PAL: 0x801a1ecc..0x801a1ed8
OSContext* OSGetCurrentContext(void);
// PAL: 0x801a1ed8..0x801a1f58
UNKNOWN_FUNCTION(OSSaveContext);
// PAL: 0x801a1f58..0x801a2030
void OSLoadContext(OSContext* context);
// PAL: 0x801a2030..0x801a2038
u32 OSGetStackPointer(void);
// PAL: 0x801a2038..0x801a2068
UNKNOWN_FUNCTION(OSSwitchFiber);
// PAL: 0x801a2068..0x801a2098
UNKNOWN_FUNCTION(OSSwitchFiberEx);
// PAL: 0x801a2098..0x801a20bc
void OSClearContext(OSContext* context);
// PAL: 0x801a20bc..0x801a2178
void OSInitContext(OSContext* context, u32 pc, u32 sp);
// PAL: 0x801a2178..0x801a23d8
void OSDumpContext(OSContext*);
// PAL: 0x801a23d8..0x801a245c
UNKNOWN_FUNCTION(OSSwitchFPUContext);
// PAL: 0x801a245c..0x801a24a4
UNKNOWN_FUNCTION(__OSContextInit);
// PAL: 0x801a24a4..0x801a25d0
UNKNOWN_FUNCTION(OSFillFPUContext);

#ifdef __cplusplus
}
#endif
