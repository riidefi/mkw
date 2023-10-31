#include "so.h"

#include <stdbool.h>

#include <rvl/ipc/ipcclt.h>
#include <rvl/os/osInterrupt.h>
#include <rvl/os/osThread.h>

// PAL: 0x80385ee0 @sdata (pointer)
// PAL: 0x802a2318 @data (string literal)
const char* __SO_VERSION =
    "<< RVL_SDK - SO \trelease build: Dec 10 2007 10:02:35 (0x4199_60831) >>";

// PAL: 0x80386d30 @sbss
u8 soState = 0;
// PAL: 0x80357220 @bss
SOSysWork soWork;
// PAL: 0x80386d34 @sbss
s32 soError = 0;
// ???
static int soRegistered = false;
// PAL: 0x80385ee4 @sdata
int soBufAddrCheck = true;
// PAL: 0x802a2360 @data
static char NET_RM_SOCK[] = "/dev/net/ip/top";

void OSSleepTicks(s64);
s64 __OSGetSystemTime(void);

s32 NCDGetLinkStatus(void);
s32 NWC24iStartupSocket(s32*);
s32 NWC24iCleanupSocket(s32*);
s32 NWC24iLockSocket();
s32 NWC24iUnlockSocket();

int SOFinish(void) {
  int result = 0;
  int enabled = OSDisableInterrupts();

  switch (soState) {
  case SO_INTERNAL_STATE_TERMINATED:
    result = SO_EALREADY;
    break;
  case SO_INTERNAL_STATE_READY:
    if (soWork.rmState > SO_INTERNAL_RM_STATE_CLOSED) {
      result = SO_EBUSY;
      break;
    } else if (soWork.allocCount > 1) {
      result = SO_EAGAIN;
      break;
    }
    soState = SO_INTERNAL_STATE_TERMINATED;
    if (soWork._unk10 != 0 && soWork.freeFunc) {
      soWork.allocCount--;
      soWork.freeFunc(0x0b, (void*)soWork._unk10, 0x460);
    }
    break;
  case SO_INTERNAL_STATE_ACTIVE:
    result = SO_EINPROGRESS;
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

int SOStartup(void) { return SOStartupEx(0xea60); }

inline int SO_Startup_ErrWtf(s32 errNwc24, s32 exErr) {
  s32 result = -0x1c;
  switch (errNwc24) {
  case 0:
    result = 0;
    break;
  case -0x16:
  case -0xd:
    result = -0x30;
    break;
  case -0x21:
  case -2:
    result = exErr;
    break;
  case -1:
    result = -0x80000000;
    break;
  case -0x1d:
    result = -0x1a;
    break;
  }
  return result;
}

int SOStartupEx(int timeout) {
  int result;
  int enabled;
  s32 exErr;
  s64 limitTime;
  s32 linkupRetryCount;

  limitTime = 0;
  if (timeout != 0)
    limitTime = __OSGetSystemTime() + ((timeout) * ((__OSBusClock / 4) / 1000));

  linkupRetryCount = 4;

begin_startup:
  result = SO_SUCCESS;

  enabled = OSDisableInterrupts();

  switch (soState) {
  case SO_INTERNAL_STATE_TERMINATED:
  default:
    result = SO_ENETRESET;
    break;
  case SO_INTERNAL_STATE_ACTIVE:
    result = SO_EALREADY;
    break;
  case SO_INTERNAL_STATE_READY:
    if (soWork.rmState > SO_INTERNAL_RM_STATE_CLOSED) {
      result = SO_EBUSY;
      break;
    } else if (!OSGetCurrentThread()) {
      result = SO_EFATAL;
      break;
    } else {
      int resultNCD;

      soWork.rmState = SO_INTERNAL_RM_STATE_WORKING;
      (void)OSRestoreInterrupts(enabled);

      while (true) {
        resultNCD = NCDGetLinkStatus();
        if (resultNCD != NCD_RESULT_INPROGRESS &&
            resultNCD != NCD_LINKSTATUS_WORKING)
          break;
        OSSleepTicks((((s64)100) * ((__OSBusClock / 4) / 1000)));
        if (limitTime != 0 && limitTime < __OSGetSystemTime()) {
          if (resultNCD == NCD_LINKSTATUS_WORKING)
            result = SO_ERR_LINK_UP_TIMEOUT;
          else
            result = SO_EFATAL;
          goto change_state;
        }
      }
      if (resultNCD < NCD_RESULT_SUCCESS) {
        result = SO_EFATAL;
        goto change_state;
      } else if (resultNCD == NCD_LINKSTATUS_NONE) {
        result = SO_ENOENT;
        goto change_state;
      }

      // 0x801ec334
      while (true) {
        soWork.rmFd = IOS_Open(NET_RM_SOCK, 0);
        if (soWork.rmFd != -6)
          break;
        OSSleepTicks((((s64)100) * ((__OSBusClock / 4) / 1000)));
        if (limitTime != 0 && limitTime < __OSGetSystemTime()) {
          result = SO_EFATAL;
          goto change_state;
        }
      };

      if (soWork.rmFd < 0) {
        result = SO_EFATAL;
        goto change_state;
      } else {
        s32 errNwc24;

        result = SO_SUCCESS;
        exErr = SO_SUCCESS;

        // PAL: 0x801ec3c0
        while (true) {
          errNwc24 = NWC24iStartupSocket(&exErr);
          if (errNwc24 != NWC24_ERR_INPROGRESS)
            break;
          OSSleepTicks((((s64)100) * ((__OSBusClock / 4) / 1000)));
          if (limitTime != 0 && limitTime < __OSGetSystemTime()) {
            result = SO_EFATAL;
            break;
          }
        }
        // PAL: 0x801ec41c
        if (result == SO_SUCCESS)
          result = SO_Startup_ErrWtf(errNwc24, exErr);
        // PAL: 0x801ec470
        if (result != SO_SUCCESS) {
          // PAL: 0x801ec478
          if (IOS_Close(soWork.rmFd) < 0) {
            result = SO_EFATAL;
            goto change_state;
          } else {
            soWork.rmFd = -1;
          }
        }
      }

      // PAL: 0x801ec494
    change_state:
      enabled = OSDisableInterrupts();
      if (result == SO_SUCCESS) {
        soState = SO_INTERNAL_STATE_ACTIVE;
        soWork.rmState = SO_INTERNAL_RM_STATE_OPENED;
      } else {
        soState = 1;
        if (result != SO_EFATAL)
          soWork.rmState = SO_INTERNAL_RM_STATE_CLOSED;
      }
    }
    break;
  }

  {
    OSThread* cur = OSGetCurrentThread();
    if (cur)
      cur->error = result;
    else
      soError = result;
  }

  // PAL: 0x801ec4e4
  (void)OSRestoreInterrupts(enabled);

  if (result == 0) {
    s64 dhcpTimeOutTicks;

    if (limitTime != 0) {
      dhcpTimeOutTicks = limitTime - __OSGetSystemTime();
    } else {
      dhcpTimeOutTicks = 0;
    }
    if (limitTime != 0 && dhcpTimeOutTicks <= 0) {
      result = -76;
    } else {
      result = SOiWaitForDHCPEx(
          (int)((dhcpTimeOutTicks) / ((__OSBusClock / 4) / 1000)));
    }

    if (result != 0) {
      (void)SOCleanup();
    }
  }

  {
    OSThread* cur = OSGetCurrentThread();
    if (cur)
      cur->error = result;
    else
      soError = result;
  }

  if (result == -112) {
    linkupRetryCount--;
    if (linkupRetryCount >= 0) {
      goto begin_startup;
    }
  }

  return result;
}

int SOCleanup(void) {
  int result = SO_SUCCESS;
  int enabled = OSDisableInterrupts();
  s32 exErr = SO_SUCCESS;
  int errNwc24;

  switch (soState) {
  case SO_INTERNAL_STATE_TERMINATED:
  default:
    result = SO_ENETRESET;
    break;
  case SO_INTERNAL_STATE_READY:
    result = SO_EALREADY;
    break;
  case SO_INTERNAL_STATE_ACTIVE:
    if (soWork.rmState < SO_INTERNAL_RM_STATE_OPENED) {
      result = SO_EBUSY;
      break;
    } else if (!OSGetCurrentThread()) {
      result = SO_EFATAL;
      break;
    } else {
      soWork.rmState = SO_INTERNAL_RM_STATE_WORKING;
      (void)OSRestoreInterrupts(enabled);

      errNwc24 = NWC24iCleanupSocket(&exErr);
      result = SO_Startup_ErrWtf(errNwc24, exErr);
      if (result != SO_SUCCESS) {
      } else {
        if (IOS_Close(soWork.rmFd) < 0)
          result = SO_EFATAL;
        else
          soWork.rmFd = -1;
      }

      enabled = OSDisableInterrupts();
      if (result == SO_SUCCESS) {
        soState = SO_INTERNAL_STATE_READY;
        soWork.rmState = SO_INTERNAL_RM_STATE_CLOSED;
      } else {
        if (result != SO_EFATAL) {
          soState = SO_INTERNAL_STATE_ACTIVE;
          soWork.rmState = SO_INTERNAL_RM_STATE_OPENED;
        }
      }
    }
    break;
  }

  {
    OSThread* cur = OSGetCurrentThread();
    if (cur)
      cur->error = result;
    else
      soError = result;
  }

  OSRestoreInterrupts(enabled);
  return result;
}

SOSysWork* SOiGetSysWork(void) { return &soWork; }

int SOiIsBufferAddrCheck(void) { return soBufAddrCheck; }

int SOiIsInitialized(void) {
  int result = false;
  int enabled = OSDisableInterrupts();
  switch (soState) {
  case SO_INTERNAL_STATE_READY:
  case SO_INTERNAL_STATE_ACTIVE:
    result = true;
    break;
  }
  OSRestoreInterrupts(enabled);
  return result;
}

void* SOiAlloc(u32 name, s32 size) {
  if (size > 0 && soWork.allocFunc) {
    void* ptr = soWork.allocFunc(name, size);
    if (ptr) {
      soWork.allocCount++;
      if (SOiIsBufferAddrCheck() && !(((u32)ptr & 0x1fffffff) >= 0x10000000 &&
                                      ((u32)ptr & 0x1fffffff) < 0x18000000)) {
        SOiFree(name, ptr, size);
        ptr = NULL;
      }
    }
    return ptr;
  }
  return NULL;
}

void SOiFree(u32 name, void* ptr, s32 size) {
  if ((ptr != NULL) && (soWork.freeFunc != NULL)) {
    soWork.allocCount--;
    soWork.freeFunc(name, ptr, size);
  }
}

int SOiPrepare(const char* /* funcName */, s32* pRmId) {
  int result = SO_SUCCESS;
  int enabled = OSDisableInterrupts();

  switch (soState) {
  case SO_INTERNAL_STATE_TERMINATED:
    result = SO_ENETRESET;
    break;
  case SO_INTERNAL_STATE_READY:
  default:
    result = SO_EINVAL;
    break;
  case SO_INTERNAL_STATE_ACTIVE:
    if (soWork.rmState < SO_INTERNAL_RM_STATE_OPENED) {
      result = SO_EBUSY;
      break;
    } else if (!OSGetCurrentThread()) {
      result = SO_EFATAL;
      break;
    }
    *pRmId = soWork.rmFd;
    break;
  }

  if (result != SO_SUCCESS) {
    OSThread* cur = OSGetCurrentThread();
    if (cur)
      cur->error = result;
    else
      soError = result;
  }
  (void)OSRestoreInterrupts(enabled);
  return result;
}

int SOiConclude(const char* /* funcName */, int result) {
  int enabled = OSDisableInterrupts();
  OSThread* cur = OSGetCurrentThread();
  if (cur)
    cur->error = result;
  else
    soError = result;
  (void)OSRestoreInterrupts(enabled);
  return result;
}

int SOiPrepareTempRm(const char* funcName, s32* pRmId, int* pIsTempRm) {
  int result = SO_SUCCESS;
  int enabled = OSDisableInterrupts();
  int errNwc24;

  switch (soState) {
  case SO_INTERNAL_STATE_TERMINATED:
    result = SO_ENETRESET;
    break;
  case SO_INTERNAL_STATE_READY:
  default:
    if (soWork.rmState > SO_INTERNAL_RM_STATE_CLOSED) {
      result = SO_EBUSY;
      break;
    } else if (!OSGetCurrentThread()) {
      result = SO_EFATAL;
      break;
    }
    soWork.rmState = SO_INTERNAL_RM_STATE_WORKING;
    (void)OSRestoreInterrupts(enabled);
    soWork.rmFd = IOS_Open(NET_RM_SOCK, 0);
    if (soWork.rmFd < 0) {
      enabled = OSDisableInterrupts();
      if (soWork.rmFd == -6) {
        result = SO_EINPROGRESS;
        soWork.rmState = SO_INTERNAL_RM_STATE_CLOSED;
      } else {
        result = SO_EFATAL;
      }
    } else {
      *pRmId = soWork.rmFd;
      if ((errNwc24 = NWC24iLockSocket()) == NWC24_OK) {
        s32 errNcd = NCDGetLinkStatus();
        switch (errNcd) {
        case 3:
        case 4:
        case 5:
          result = (int)IOS_Ioctl(soWork.rmFd, 0x1f, NULL, 0, NULL, 0);
          if (result == SO_SUCCESS) {
            *pIsTempRm = true;
          } else {
            result = SOiConcludeTempRm(funcName, result, true);
          }
          break;
        case -8:
          result = SOiConcludeTempRm(funcName, SO_EINPROGRESS, true);
          break;
        case -1:
        case -2:
          result = SOiConcludeTempRm(funcName, SO_EFATAL, true);
          break;
        default:
          result = SOiConcludeTempRm(funcName, SO_ENOLINK, true);
        }
        enabled = OSDisableInterrupts();
      } else {
        switch (errNwc24) {
        case NWC24_ERR_INPROGRESS:
          result = SO_EINPROGRESS;
          break;
        case NWC24_ERR_FAILED:
          result = SO_ENETRESET;
          break;
        case NWC24_ERR_DONE:
          result = SO_ENOLINK;
          break;
        case NWC24_ERR_MUTEX:
        case NWC24_ERR_FATAL:
        default:
          result = SO_EFATAL;
          break;
        }
        if (IOS_Close(soWork.rmFd) < 0) {
          result = SO_EFATAL;
        }
        enabled = OSDisableInterrupts();
        if (result != SO_EFATAL) {
          soWork.rmFd = -1;
          soWork.rmState = SO_INTERNAL_RM_STATE_CLOSED;
        }
      }
    }
    break;
  case SO_INTERNAL_STATE_ACTIVE:
    if (soWork.rmState < SO_INTERNAL_RM_STATE_OPENED) {
      result = SO_EBUSY;
      break;
    } else if (!OSGetCurrentThread()) {
      result = SO_EFATAL;
      break;
    }
    *pIsTempRm = false;
    *pRmId = soWork.rmFd;
    break;
  }

  if (result != SO_SUCCESS) {
    OSThread* cur = OSGetCurrentThread();
    if (cur)
      cur->error = result;
    else
      soError = result;
  }
  (void)OSRestoreInterrupts(enabled);
  return result;
}

int SOiConcludeTempRm(const char* /* funcName */, int result, int isTempRm) {
  int enabled;

  if (isTempRm == true) {
    switch (NWC24iUnlockSocket()) {
    case NWC24_OK:
      break;
    case NWC24_ERR_INPROGRESS:
      result = SO_EINPROGRESS;
      break;
    case NWC24_ERR_FATAL:
    default:
      result = SO_EFATAL;
    }
    if (IOS_Close(soWork.rmFd) < 0) {
      result = SO_EFATAL;
    }
    enabled = OSDisableInterrupts();
    if (result != SO_EFATAL) {
      soWork.rmFd = -1;
      soWork.rmState = SO_INTERNAL_RM_STATE_CLOSED;
    }
  } else {
    enabled = OSDisableInterrupts();
  }
  OSThread* cur = OSGetCurrentThread();
  if (cur)
    cur->error = result;
  else
    soError = result;
  (void)OSRestoreInterrupts(enabled);
  return result;
}

int SOiWaitForDHCPEx(int timeout) {
  int result = SO_SUCCESS;
  int gioResult;
  int ifError;
  int ifErrorSize;
  s64 limitTime;

  limitTime = 0;
  if (timeout != 0)
    limitTime = __OSGetSystemTime() + ((timeout) * ((__OSBusClock / 4) / 1000));

  while (true) {
    OSSleepTicks((((s64)10) * ((__OSBusClock / 4) / 1000)));

    ifErrorSize = sizeof(ifError);
    gioResult = SOGetInterfaceOpt(NULL, 0xfffe, 0x1003, &ifError, &ifErrorSize);
    if (gioResult != SO_SUCCESS) {
      result = gioResult;
      break;
    }
    if (gioResult == SO_SUCCESS && ifError != SO_SUCCESS) {
      result = ifError;
      break;
    }
    if (SOGetHostID() != 0)
      break;
    if (limitTime != 0 && limitTime < __OSGetSystemTime()) {
      result = SO_ETIMEDOUT;
      break;
    }
  }

  return result;
}
