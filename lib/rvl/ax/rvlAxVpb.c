#include "vpb.h"

#include <math.h>
#include <string.h>

#include <rvl/os/osCache.h>
#include <rvl/os/osInterrupt.h>

#include "alloc.h"
#include "cl.h"
#include "spb.h"

AXPB* __AXPB = NULL;
AXPBITDBUFFER* __AXITD = NULL;
AXVPB* __AXVPB = NULL;
u32 __AXMaxDspCycles;
u32 __AXRecDspCycles;
u32 __AXNumVoices;
u32 __AXMaxVoices;

const f32 _lit_803884a8 = 2.0f;
const f32 _lit_803884ac = 6.2831855f;
const f32 _lit_803884b0 = 32000.0f;
const f32 _lit_803884b4 = 1.0f;
sdata2_ps_f32 _lit_803884b8 = {32768.0f};
sdata2_ps_f32 _lit_803884c0 = {176.0f};

extern void* unk_8027e840;
extern void* unk_8027e7c0;

extern void* __s_AXPB;
extern void* __s_AXVPB;
extern void* __s_AXITD;

u32 __AXGetNumVoices() { return __AXNumVoices; }

AXPB* __AXGetPBs() { return __AXPB; }
