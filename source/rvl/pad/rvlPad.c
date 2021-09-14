#include "pad.h"

#include <rvl/os/os.h>
#include <rvl/os/osContext.h>

// TODO: Move to osMisc.h
typedef int (*OSResetFunction)(int final);
typedef struct OSResetFunctionInfo {
  OSResetFunction func; // 0x00
  u32 priority;         // 0x04
  u32 unk_08;
  u32 unk_0A;
} OSResetFunctionInfo;

void OSRegisterShutdownFunction(OSResetFunctionInfo* info);

// Broadway / IOS global locations: https://wiibrew.org/wiki/Memory_Map
u8 oslow_30e3 : (0x800030e3);
u16 oslow_30e0 : (0x800030e0);

#include "rvl/si/si.h"

#include <string.h>

// PAL: 0x80385b08 @sdata (pointer)
// PAL: 0x8029cc80 @data (string literal)
static const char* __PAD_VERSION =
    "<< RVL_SDK - PAD \trelease build: Oct  3 2007 01:00:54 (0x4199_60831) >>";

// PAL: 0x803869c0 @sbss
static u32 PADInitialized;
// PAL: 0x803869bc @sbss
static u32 PADEnabledBits;
// PAL: 0x803869b8 @sbss
static u32 PADResetBits;
// PAL: 0x80385b0c @sdata
static s32 PADResetChan = 32;
// PAL: 0x803869b4 @sbss
static u32 PADUnk803869b4;
// PAL: 0x803869b0 @sbss
static u32 PADUnk803869b0;
// PAL: 0x803869ac @sbss
static u32 PADUnk803869ac;
// PAL: 0x803869a8 @sbss
static u32 PADUnk803869a8;
// PAL: 0x803869a4 @sbss
static u32 PADUnk803869a4;

// PAL: 0x80385b10 @sdata
static u32 PAD_StickXResetBit = 0xf0000000;
// PAL: 0x80385b14 @sdata
static u32 PAD_AnalogMode = 0x00000300u;

// PAL: 0x803869a0
u32 PAD_Spec;
// From rvl/si/siBios.c
extern u32 __PADFixBits;
// PAL: 0x80385b18 @sdata
static u32 Spec = 5;
// PAL: 0x80385b1c @sdata
static void (*PAD_MakeStatus)(s32, PADStatus*, u32[2]) = SPEC2_MakeStatus;

// PAL: 0x803481e0 @bss
static u32 Type[4];
// PAL: 0x803481b0 @bss
static PADStatus Origin[4];

static u32 unk_padding = 0;
// PAL: 0x80385b20 @sdata
static u32 PAD_Unk80385b20 = 0x41u << 24;
// PAL: 0x80385b24 @sdata
static u32 PAD_Unk80385b24 = 0x42u << 24;
// PAL: 0x803481f0 @bss
static u32 PAD_Unk803481f0[4];

// PAL: 0x80348200 => 0x80348230 @bss
static PADStatus PAD_AltStatus[4];

// PAL: 0x8029ccc8 => 0x8029ccd8
static OSResetFunctionInfo PAD_ResetFunctionInfo = {PAD_OnReset, 127};

// PAL: 0x8038699c
static void (*PAD_SamplingCallback)(void);

void PAD_UpdateOrigin(s32 chan) {
  PADStatus* orig;
  u32 chanBit = 0x80000000 >> chan;
  orig = &Origin[chan];
  switch (PAD_AnalogMode & 0x00000700u) {
  case 0x00000000u:
  case 0x00000500u:
  case 0x00000600u:
  case 0x00000700u:
    orig->triggerL &= ~15;
    orig->triggerR &= ~15;
    orig->analogA &= ~15;
    orig->analogB &= ~15;
    break;
  case 0x00000100u:
    orig->substickX &= ~15;
    orig->substickY &= ~15;
    orig->analogA &= ~15;
    orig->analogB &= ~15;
    break;
  case 0x00000200u:
    orig->substickX &= ~15;
    orig->substickY &= ~15;
    orig->triggerL &= ~15;
    orig->triggerR &= ~15;
    break;
  case 0x00000300u:
    break;
  case 0x00000400u:
    break;
  }
  orig->stickX -= 128;
  orig->stickY -= 128;
  orig->substickX -= 128;
  orig->substickY -= 128;
  if (PAD_StickXResetBit & chanBit) {
    if (64 < orig->stickX &&
        (SIGetType(chan) & 0xffff0000) == (0x08000000u | 0x01000000u)) {
      orig->stickX = 0;
    }
  }
}

inline static void PADEnable(s32 chan) {
  u32 cmd;
  u32 chanBit;
  u32 resp[2];
  chanBit = 0x80000000 >> chan;
  PADEnabledBits |= chanBit;
  SIGetResponse(chan, resp);
  cmd = (0x40u << 16) | PAD_AnalogMode;
  SISetCommand(chan, cmd);
  SIEnablePolling(PADEnabledBits);
}

int OSDisableInterrupts(void);
int OSEnableInterrupts(void);
int OSRestoreInterrupts(int);

void OSSetWirelessID(s32, u16);

inline static void PADDisable(s32 chan) {
  int interrupts;
  u32 chanBit;
  interrupts = OSDisableInterrupts();
  chanBit = 0x80000000 >> chan;
  SIDisablePolling(chanBit);
  PADEnabledBits &= ~chanBit;
  PADUnk803869b0 &= ~chanBit;
  PADUnk803869ac &= ~chanBit;
  PADUnk803869a8 &= ~chanBit;
  PADUnk803869a4 &= ~chanBit;
  OSSetWirelessID(chan, 0);
  OSRestoreInterrupts(interrupts);
}

inline static void DoReset(void) {
  u32 chanBit;
  PADResetChan = __cntlzw(PADResetBits);
  if (PADResetChan == 32)
    return;
  chanBit = 0x80000000 >> PADResetChan;
  PADResetBits &= ~chanBit;
  memset(&Origin[PADResetChan], 0, sizeof(PADStatus));
  SIGetTypeAsync(PADResetChan, PADTypeAndStatusCallback);
}

void PADOriginCallback(s32 chan, u32 error, void* context) {
#pragma unused(chan, context)
  if (!(error & (0x0001 | 0x0002 | 0x0008 | 0x0004))) {
    PAD_UpdateOrigin(PADResetChan);
    PADEnable(PADResetChan);
  }
  DoReset();
}

void PADOriginUpdateCallback(s32 chan, u32 error, void* context) {
#pragma unused(context)
  if (!(PADEnabledBits & (0x80000000 >> chan)))
    return;
  if (!(error & (0x0001 | 0x0002 | 0x0008 | 0x0004)))
    PAD_UpdateOrigin(chan);
  if (error & 0x0008)
    PADDisable(chan);
}

void PADProbeCallback(s32 chan, u32 error, void* context) {
#pragma unused(chan, context)
  if (!(error & (0x0001 | 0x0002 | 0x0008 | 0x0004))) {
    PADEnable(PADResetChan);
    PADUnk803869b0 |= 0x80000000 >> PADResetChan;
  }
  DoReset();
}

void PADTypeAndStatusCallback(s32 chan, u32 type) {
#pragma unused(chan)
  u32 chanBit;
  u32 variant1;
  int ok = true;
  u32 error;
  chanBit = 0x80000000 >> PADResetChan;
  error = type & 0xff;
  variant1 = PADUnk803869b4 & chanBit;
  PADUnk803869b4 &= ~chanBit;
  if (error & (0x0001 | 0x0002 | 0x0008 | 0x0004)) {
    DoReset();
    return;
  }
  type &= ~0xff;
  Type[PADResetChan] = type;
  if ((type & 0x18000000u) != 0x08000000u || !(type & 0x01000000u)) {
    DoReset();
    return;
  }
  if (Spec < 2) {
    PADEnable(PADResetChan);
    DoReset();
    return;
  }
  if (!(type & 0x80000000u) || (type & 0x04000000u)) {
    if (variant1) {
      ok = SITransfer(PADResetChan, &PAD_Unk80385b24, 3, &Origin[PADResetChan],
                      10, PADOriginCallback, 0);
    } else {
      ok = SITransfer(PADResetChan, &PAD_Unk80385b20, 1, &Origin[PADResetChan],
                      10, PADOriginCallback, 0);
    }
  } else if ((type & 0x00100000u) && (type & 0x00080000u) == 0x00000000u &&
             !(type & 0x00040000u)) {
    if (type & 0x40000000u) {
      ok = SITransfer(PADResetChan, &PAD_Unk80385b20, 1, &Origin[PADResetChan],
                      10, PADOriginCallback, 0);
    } else {
      ok = SITransfer(PADResetChan, &PAD_Unk803481f0[PADResetChan], 3,
                      &Origin[PADResetChan], 8, PADProbeCallback, 0);
    }
  }
  if (!ok) {
    PADUnk803869a8 |= chanBit;
    DoReset();
    return;
  }
}

static void PADReceiveCheckCallback(s32 chan, u32 type) {
  u32 error;
  u32 chanBit;
  chanBit = 0x80000000 >> chan;
  if (!(PADEnabledBits & chanBit)) {
    return;
  }
  error = type & 0xff;
  type &= ~0xff;
  PADUnk803869b0 &= ~chanBit;
  PADUnk803869ac &= ~chanBit;
  if (!(error & 0x000f) && (type & 0x80000000u) && (type & 0x00100000u) &&
      (type & 0x40000000u) && !(type & 0x04000000u) &&
      (type & 0x00080000u) == 0x00000000u && !(type & 0x00040000u)) {
    SITransfer(chan, &PAD_Unk80385b20, 1, &Origin[chan], 10,
               PADOriginUpdateCallback, 0);
  } else {
    PADDisable(chan);
  }
}

int PADReset(u32 mask) {
  int enabled;
  u32 disableBits;
  enabled = OSDisableInterrupts();
  mask |= PADUnk803869a8;
  PADUnk803869a8 = 0;
  mask &= ~(PADUnk803869b0 | PADUnk803869ac);
  PADResetBits |= mask;
  disableBits = PADResetBits & PADEnabledBits;
  PADEnabledBits &= ~mask;
  PADUnk803869a4 &= ~mask;
  if (Spec == 4) {
    PADUnk803869b4 |= mask;
  }
  SIDisablePolling(disableBits);
  if (PADResetChan == 32)
    DoReset();
  OSRestoreInterrupts(enabled);
  return true;
}

int PADRecalibrate(u32 mask) {
  int interrupts;
  u32 disableBits;
  interrupts = OSDisableInterrupts();
  mask |= PADUnk803869a8;
  PADUnk803869a8 = 0;
  mask &= ~(PADUnk803869b0 | PADUnk803869ac);
  PADResetBits |= mask;
  disableBits = PADResetBits & PADEnabledBits;
  PADEnabledBits &= ~mask;
  PADUnk803869a4 &= ~mask;
  if (!(oslow_30e3 & 0x40))
    PADUnk803869b4 |= mask;
  SIDisablePolling(disableBits);
  if (PADResetChan == 32)
    DoReset();
  OSRestoreInterrupts(interrupts);
  return true;
}

int PADInit(void) {
  s32 chan;
  if (PADInitialized) {
    return true;
  }
  OSRegisterVersion(__PAD_VERSION);
  if (PAD_Spec) {
    PADSetSpec(PAD_Spec);
  }
  PADInitialized = true;
  if (__PADFixBits != 0) {
    s64 time = OSGetTime();
    oslow_30e0 = (u16)((((time)&0xffff) + ((time >> 16) & 0xffff) +
                        ((time >> 32) & 0xffff) + ((time >> 48) & 0xffff)) &
                       0x3fffu);
    PADUnk803869b4 = 0xf0000000;
  }
  for (chan = 0; chan < 4; ++chan) {
    PAD_Unk803481f0[chan] =
        (0x4du << 24) | (chan << 22) | ((oslow_30e0 & 0x3fffu) << 8);
  }
  SIRefreshSamplingRate();
  OSRegisterShutdownFunction(&PAD_ResetFunctionInfo);
  return PADReset(0xf0000000);
}

void sub_801BB0D0(void);

u32 PADRead(PADStatus* status) {
  int interrupts;
  s32 i;
  u32 data[2];
  u32 chanBit;
  u32 statusNum;
  int chanShift;
  u32 motor;
  interrupts = OSDisableInterrupts();
  motor = 0;
  for (i = 0; i < 4; i++, status++) {
    chanBit = 0x80000000 >> i;
    chanShift = 8 * (4 - 1 - i);
    if (PADUnk803869a8 & chanBit) {
      PADReset(0);
      status->err = -2;
      memset(status, 0, 0xa);
      continue;
    }
    if ((PADResetBits & chanBit) || PADResetChan == i) {
      status->err = -2;
      memset(status, 0, 0xa);
      continue;
    }
    if (!(PADEnabledBits & chanBit)) {
      status->err = (s8)-1;
      memset(status, 0, 0xa);
      continue;
    }
    if (SIIsChanBusy(i)) {
      status->err = -3;
      memset(status, 0, 0xa);
      continue;
    }
    statusNum = SIGetStatus(i);
    if (statusNum & 0x0008) {
      SIGetResponse(i, data);
      if (PADUnk803869b0 & chanBit) {
        status->err = (s8)0;
        memset(status, 0, 0xa);
        if (!(PADUnk803869ac & chanBit)) {
          PADUnk803869ac |= chanBit;
          SIGetTypeAsync(i, PADReceiveCheckCallback);
        }
        continue;
      }
      PADDisable(i);
      status->err = (s8)-1;
      memset(status, 0, 0xa);
      continue;
    }
    if (!(SIGetType(i) & 0x20000000u)) {
      motor |= chanBit;
    }
    if (!SIGetResponse(i, data)) {
      status->err = -3;
      memset(status, 0, 0xa);
      continue;
    }
    if (data[0] & 0x80000000) {
      status->err = -3;
      memset(status, 0, 0xa);
      continue;
    }
    // 0x801af690
    PAD_MakeStatus(i, status, data);
    s32 thres;
    if (((Type[i] & 0xffff0000) == 0x09000000u) &&
        ((status->button & 0x0080) ^ 0x0080)) {
      thres = 10;
    } else {
      thres = 3;
    }
// TODO add proper stdlib.h
#define abs __abs
    if ((abs(abs(status->stickX) - abs(PAD_AltStatus[i].stickX))) >= thres ||
        (abs(abs(status->stickY) - abs(PAD_AltStatus[i].stickY))) >= thres ||
        (abs(abs(status->substickX) - abs(PAD_AltStatus[i].substickX))) >=
            thres ||
        (abs(abs(status->substickY) - abs(PAD_AltStatus[i].substickY))) >=
            thres ||
        (abs(abs(status->triggerL) - abs(PAD_AltStatus[i].triggerL))) >=
            thres ||
        (abs(abs(status->triggerR) - abs(PAD_AltStatus[i].triggerR))) >=
            thres ||
        status->button != PAD_AltStatus[i].button) {
      sub_801BB0D0();
    }
#undef abs
    memcpy(&PAD_AltStatus[i], status, 0xc);
    if (status->button & 0x2000) {
      status->err = -3;
      memset(status, 0, 0xa);
      SITransfer(i, &PAD_Unk80385b20, 1, &Origin[i], 10,
                 PADOriginUpdateCallback, 0);
      continue;
    }
    status->err = 0;
    status->button &= ~0x0080;
  }
  OSRestoreInterrupts(interrupts);
  return motor;
}

void PADControlMotor(s32 chan, u32 command) {
  int interrupts;
  u32 chanBit;
  interrupts = OSDisableInterrupts();
  chanBit = 0x80000000 >> chan;
  if ((PADEnabledBits & chanBit) && !(SIGetType(chan) & 0x20000000u)) {
    if (Spec < 2 && command == 2) {
      command = 0;
    }
    if (oslow_30e3 & 0x20) {
      command = 0;
    }
    SISetCommand(chan, (0x40u << 16) | PAD_AnalogMode |
                           (command & (0x00000001u | 0x00000002u)));
    SITransferCommands();
  }
  OSRestoreInterrupts(interrupts);
}

inline void PADSetSpec(u32 spec) {
  PAD_Spec = 0;
  switch (spec) {
  case 0:
    PAD_MakeStatus = SPEC0_MakeStatus;
    break;
  case 1:
    PAD_MakeStatus = SPEC1_MakeStatus;
    break;
  case 2:
  case 3:
  case 4:
  case 5:
    PAD_MakeStatus = SPEC2_MakeStatus;
    break;
  }
  Spec = spec;
}

static void SPEC0_MakeStatus(s32 chan, PADStatus* status, u32 data[2]) {
#pragma unused(chan)
  status->button = 0;
  status->button |= ((data[0] >> 16) & 0x0008) ? 0x0100 : 0;
  status->button |= ((data[0] >> 16) & 0x0020) ? 0x0200 : 0;
  status->button |= ((data[0] >> 16) & 0x0100) ? 0x0400 : 0;
  status->button |= ((data[0] >> 16) & 0x0001) ? 0x0800 : 0;
  status->button |= ((data[0] >> 16) & 0x0010) ? 0x1000 : 0;
  status->stickX = (s8)(data[1] >> 16);
  status->stickY = (s8)(data[1] >> 24);
  status->substickX = (s8)(data[1]);
  status->substickY = (s8)(data[1] >> 8);
  status->triggerL = (u8)(data[0] >> 8);
  status->triggerR = (u8)data[0];
  status->analogA = 0;
  status->analogB = 0;
  if (170u <= status->triggerL) {
    status->button |= 0x0040;
  }
  if (170u <= status->triggerR) {
    status->button |= 0x0020;
  }
  status->stickX -= 128;
  status->stickY -= 128;
  status->substickX -= 128;
  status->substickY -= 128;
}

static void SPEC1_MakeStatus(s32 chan, PADStatus* status, u32 data[2]) {
#pragma unused(chan)
  status->button = 0;
  status->button |= ((data[0] >> 16) & 0x0080) ? 0x0100 : 0;
  status->button |= ((data[0] >> 16) & 0x0100) ? 0x0200 : 0;
  status->button |= ((data[0] >> 16) & 0x0020) ? 0x0400 : 0;
  status->button |= ((data[0] >> 16) & 0x0010) ? 0x0800 : 0;
  status->button |= ((data[0] >> 16) & 0x0200) ? 0x1000 : 0;
  status->stickX = (s8)(data[1] >> 16);
  status->stickY = (s8)(data[1] >> 24);
  status->substickX = (s8)(data[1]);
  status->substickY = (s8)(data[1] >> 8);
  status->triggerL = (u8)(data[0] >> 8);
  status->triggerR = (u8)data[0];
  status->analogA = 0;
  status->analogB = 0;
  if (170u <= status->triggerL) {
    status->button |= 0x0040;
  }
  if (170u <= status->triggerR) {
    status->button |= 0x0020;
  }
  status->stickX -= 128;
  status->stickY -= 128;
  status->substickX -= 128;
  status->substickY -= 128;
}

inline static s8 ClampS8(s8 arg1, s8 arg2) {
  if (0 < arg2) {
    s8 min = (s8)(-128 + arg2);
    if (arg1 < min) {
      arg1 = min;
    }
  } else if (arg2 < 0) {
    s8 max = (s8)(127 + arg2);
    if (max < arg1) {
      arg1 = max;
    }
  }
  return arg1 -= arg2;
}

inline static u8 ClampU8(u8 arg1, u8 arg2) {
  if (arg1 < arg2) {
    arg1 = arg2;
  }
  return arg1 -= arg2;
}

static void SPEC2_MakeStatus(s32 chan, PADStatus* status, u32 data[2]) {
  PADStatus* origin;
  status->button = (u16)((data[0] >> 16) & 0x00003fff);
  status->stickX = (s8)(data[0] >> 8);
  status->stickY = (s8)(data[0]);
  switch (PAD_AnalogMode & 0x00000700u) {
  case 0x00000000u:
  case 0x00000500u:
  case 0x00000600u:
  case 0x00000700u:
    status->substickX = (s8)(data[1] >> 24);
    status->substickY = (s8)(data[1] >> 16);
    status->triggerL = (u8)(((data[1] >> 12) & 0x0f) << 4);
    status->triggerR = (u8)(((data[1] >> 8) & 0x0f) << 4);
    status->analogA = (u8)(((data[1] >> 4) & 0x0f) << 4);
    status->analogB = (u8)(((data[1] >> 0) & 0x0f) << 4);
    break;
  case 0x00000100u:
    status->substickX = (s8)(((data[1] >> 28) & 0x0f) << 4);
    status->substickY = (s8)(((data[1] >> 24) & 0x0f) << 4);
    status->triggerL = (u8)(data[1] >> 16);
    status->triggerR = (u8)(data[1] >> 8);
    status->analogA = (u8)(((data[1] >> 4) & 0x0f) << 4);
    status->analogB = (u8)(((data[1] >> 0) & 0x0f) << 4);
    break;
  case 0x00000200u:
    status->substickX = (s8)(((data[1] >> 28) & 0x0f) << 4);
    status->substickY = (s8)(((data[1] >> 24) & 0x0f) << 4);
    status->triggerL = (u8)(((data[1] >> 20) & 0x0f) << 4);
    status->triggerR = (u8)(((data[1] >> 16) & 0x0f) << 4);
    status->analogA = (u8)(data[1] >> 8);
    status->analogB = (u8)(data[1] >> 0);
    break;
  case 0x00000300u:
    status->substickX = (s8)(data[1] >> 24);
    status->substickY = (s8)(data[1] >> 16);
    status->triggerL = (u8)(data[1] >> 8);
    status->triggerR = (u8)(data[1] >> 0);
    status->analogA = 0;
    status->analogB = 0;
    break;
  case 0x00000400u:
    status->substickX = (s8)(data[1] >> 24);
    status->substickY = (s8)(data[1] >> 16);
    status->triggerL = 0;
    status->triggerR = 0;
    status->analogA = (u8)(data[1] >> 8);
    status->analogB = (u8)(data[1] >> 0);
    break;
  }
  status->stickX -= 128;
  status->stickY -= 128;
  status->substickX -= 128;
  status->substickY -= 128;
  if (((Type[chan] & 0xffff0000) == 0x09000000u) &&
      ((status->button & 0x0080) ^ 0x0080)) {
    PADUnk803869a4 |= (0x80000000 >> chan);
    status->stickX = 0;
    status->stickY = 0;
    status->substickX = 0;
    status->substickY = 0;
    return;
  } else {
    PADUnk803869a4 &= ~(0x80000000 >> chan);
  }
  origin = &Origin[chan];
  status->stickX = ClampS8(status->stickX, origin->stickX);
  status->stickY = ClampS8(status->stickY, origin->stickY);
  status->substickX = ClampS8(status->substickX, origin->substickX);
  status->substickY = ClampS8(status->substickY, origin->substickY);
  status->triggerL = ClampU8(status->triggerL, origin->triggerL);
  status->triggerR = ClampU8(status->triggerR, origin->triggerR);
}

inline int PADSync(void) {
  return PADResetBits == 0 && PADResetChan == 32 && !SIBusy();
}

PADSamplingCallback PADSetSamplingCallback(PADSamplingCallback);

int PAD_OnReset(int final) {
  // PAL: 0x80386998
  static int isCalibrated = false;
  int sync;
  if (PAD_SamplingCallback)
    PADSetSamplingCallback(NULL);
  if (!final) {
    sync = PADSync();
    if (!isCalibrated && sync) {
      isCalibrated = PADRecalibrate(0xf0000000);
      return false;
    }
    return sync;
  } else {
    isCalibrated = false;
  }
  return true;
}

void PAD_SamplingHandler(s32 interrupt, OSContext* context) {
#pragma unused(interrupt)
  OSContext context2;
  if (PAD_SamplingCallback) {
    OSClearContext(&context2);
    OSSetCurrentContext(&context2);
    PAD_SamplingCallback();
    OSClearContext(&context2);
    OSSetCurrentContext(context);
  }
}

inline static PADSamplingCallback
PADSetSamplingCallback(PADSamplingCallback callback) {
  PADSamplingCallback prev;
  prev = PAD_SamplingCallback;
  PAD_SamplingCallback = callback;
  if (callback) {
    // Never used.
    // SIRegisterPollingHandler(PAD_SamplingHandler);
  } else {
    SIUnregisterPollingHandler(PAD_SamplingHandler);
  }
  return prev;
}

int __PADDisableRecalibration(int disable) {
  int interrupts;
  int prev;
  interrupts = OSDisableInterrupts();
  prev = (oslow_30e3 & 0x40) ? true : false;
  oslow_30e3 &= ~0x40;
  if (disable)
    oslow_30e3 |= 0x40;
  OSRestoreInterrupts(interrupts);
  return prev;
}
