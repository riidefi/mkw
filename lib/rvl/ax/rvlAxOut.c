#include "out.h"

#include <rvl/os/os.h>
#include <rvl/os/osCache.h>
#include <rvl/os/osInterrupt.h>
#include <rvl/os/osThread.h>

#include "alloc.h"
#include "axAux.h"
#include "cl.h"
#include "spb.h"
#include "vpb.h"

// Extern function references.
// PAL: 0x80123f88
extern UNKNOWN_FUNCTION(AIRegisterDMACallback);
// PAL: 0x80123fcc
extern UNKNOWN_FUNCTION(AIInitDMA);
// PAL: 0x80124048
extern UNKNOWN_FUNCTION(AIStartDMA);
// PAL: 0x8012405c
extern UNKNOWN_FUNCTION(AIGetDMABytesLeft);
// PAL: 0x80127fec
extern UNKNOWN_FUNCTION(__AXGetCurrentProfile);
// PAL: 0x8015d3fc
extern UNKNOWN_FUNCTION(DSPCheckMailToDSP);
// PAL: 0x8015d430
extern UNKNOWN_FUNCTION(DSPSendMailToDSP);
// PAL: 0x8015d444
extern UNKNOWN_FUNCTION(DSPInit);
// PAL: 0x8015d504
extern UNKNOWN_FUNCTION(DSPCheckInit);
// PAL: 0x8015d50c
extern UNKNOWN_FUNCTION(DSPAddTask);
// PAL: 0x8015d57c
extern UNKNOWN_FUNCTION(DSPAssertTask);

typedef struct AXPROFILE {
  char content[56];
} AXPROFILE;

typedef struct DSPTaskInfo {
  char content[80];
} DSPTaskInfo;

// PAL: 0x802f7d20..0x802f81a0
extern s16 __AXOutBuffer[3][192] __attribute__((aligned(32)));
// PAL: 0x802f7a20..0x802f7d20
extern s32 __AXOutSBuffer[192] __attribute__((aligned(32)));

volatile u32 __AXOutFrame;
volatile u32 __AXAiDmaFrame;
volatile u32 __AXOutDspReady;
u32 __AXUserFrameCallback;

// PAL: 0x802f7440..0x802f7480
extern AXPROFILE __AXLocalProfile;

volatile int __AXDSPInitFlag;
volatile int __AXDSPDoneFlag;
volatile u32 __AXDebugSteppingMode;
OSThreadQueue __AXOutThreadQueue;
u32 __AXOutputBufferMode;

// PAL: 0x802f7480..0x802f7a20
extern s16 __AXRmtOutBuffer[4][180] __attribute__((aligned(32)));
s32 __AXRmtBuffLen;
s32 __AXRmtDspPtr;
s32 __AXRmtCpuPtr;
u32 __AXExceedCallback;

extern u16 axDspInitVector;
extern u16 axDspResumeVector;
extern u16 axDspSlave[];
extern u16 axDspSlaveLength;

extern u8 __AXDramImage[64] __attribute__((aligned(32)));
extern DSPTaskInfo __AXDSPTask;
