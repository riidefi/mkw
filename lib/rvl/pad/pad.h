#pragma once

#include <rk_types.h>
#include <stdbool.h>

#include <rvl/os/osContext.h>

#ifdef __cplusplus
extern "C" {
#endif

// https://github.com/devkitPro/libogc/blob/bc4b778d558915aa40676e33514c4c9ba2af66b8/gc/ogc/pad.h#L46
// Size: 0x0B (arrays padded to 0x0C)
typedef struct PADStatus {
  // 0x00
  u16 button;
  // 0x02
  s8 stickX;
  // 0x03
  s8 stickY;
  // 0x04
  s8 substickX;
  // 0x05
  s8 substickY;
  // 0x06
  u8 triggerL;
  // 0x07
  u8 triggerR;
  // 0x08
  u8 analogA;
  // 0x09
  u8 analogB;
  // 0x0A
  s8 err;
} PADStatus;

// Size: 0x0A
typedef struct PADClampRegion {
  u8 unk_00;
  u8 unk_01;
  s8 stickMin; // 0x02
  s8 unk_03;
  s8 unk_04;
  s8 substickMin; // 0x05
  s8 unk_06;
  s8 unk_07;
  s8 stickRad;    // 0x08
  s8 substickRad; // 0x09
} PADClampRegion;

void PAD_ClampCircle(s8*, s8*, s8, s8);
void PADClampCircle(PADStatus*);
void PADClampCircle2(PADStatus*, u32);
void PAD_UpdateOrigin(s32);
void PADOriginCallback(s32, u32, void*);
void PADOriginUpdateCallback(s32, u32, void*);
void PADProbeCallback(s32, u32, void*);
void PADTypeAndStatusCallback(s32, u32);
int PADReset(u32);
int PADRecalibrate(u32);
int PADInit(void);
u32 PADRead(PADStatus*);
void PADControlMotor(s32, u32);
int PAD_OnReset(int);
void PAD_SamplingHandler(s32, OSContext*);
int __PADDisableRecalibration(int);
// PADSetSamplingCallback

void PADSetSpec(u32 model);
u32 PADGetSpec(void);

typedef void (*PADSamplingCallback)(void);

#ifdef __cplusplus
} // extern "C"
#endif
