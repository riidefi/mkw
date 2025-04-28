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

typedef struct AXPROFILE {
  char content[56];
} AXPROFILE;

typedef struct DSPTaskInfo {
  char content[80];
} DSPTaskInfo;

extern s16 __AXOutBuffer[3][192] __attribute__((aligned(32)));
extern s32 __AXOutSBuffer[192] __attribute__((aligned(32)));

volatile u32 __AXOutFrame;
volatile u32 __AXAiDmaFrame;
volatile u32 __AXOutDspReady;
u32 __AXUserFrameCallback;

extern AXPROFILE __AXLocalProfile;

volatile int __AXDSPInitFlag;
volatile int __AXDSPDoneFlag;
volatile u32 __AXDebugSteppingMode;
OSThreadQueue __AXOutThreadQueue;
u32 __AXOutputBufferMode;

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
