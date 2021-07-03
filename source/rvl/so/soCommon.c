#include "so.h"

#include <rvl/os/osThread.h>

// PAL: 0x80386d30 @sbss
static u8 soState = 0;
// PAL: 0x80357220 @sdata
static SOSysWork soWork;
// PAL: 0x80386d34 @sbss
static s32 soError = 0;

u32 OSDisableInterrupts(void);
u32 OSEnableInterrupts(void);
u32 OSRestoreInterrupts(u32 level);

int SOFinish(void) {
  int result = 0;
  int enabled = OSDisableInterrupts();

  switch (soState) {
  case 0:
    result = -7;
    break;
  case 1:
    if (soWork.rmState > -2) {
      result = -10;
      break;
    } else if (soWork.allocCount > 1) {
      result = -6;
      break;
    }
    soState = 0;
    if (soWork._unk10 != 0 && soWork.freeFunc) {
      soWork.allocCount--;
      soWork.freeFunc(0x0b, soWork._unk10, 0x460);
    }
    break;
  case 2:
    result = -26;
    break;
  }
  OSThread* cur = OSGetCurrentThread();
  if (cur)
    cur->error = result;
  else
    soError = result;
  OSRestoreInterrupts(enabled);
  return result;
}
