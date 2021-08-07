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

// PAL: 0x801ae5d8
void PAD_ClampCircle(s8*, s8*, s8, s8);
// PAL: 0x801ae6f4
void PADClampCircle(PADStatus*);
// PAL: 0x801ae7dc
void PADClampCircle2(PADStatus*, u32);
// PAL: 0x801ae880
void PAD_UpdateOrigin(s32);
// PAL: 0x801aea24
void PADOriginCallback(s32, u32, void*);
// PAL: 0x801aeae4
void PADOriginUpdateCallback(s32, u32, void*);
// PAL: 0x801aebac
void PADProbeCallback(s32, u32, void*);
// PAL: 0x801aec80
void PADTypeAndStatusCallback(s32, u32);
// PAL: 0x801aefa0
void PADReceiveCheckCallback(s32, u32);
// PAL: 0x801af0dc
int PADReset(u32);
// PAL: 0x801af1e4
int PADRecalibrate(u32);
// PAL: 0x801af2f0
int PADInit(void);
// PAL: 0x801af44c
u32 PADRead(PADStatus*);
// PAL: 0x801af908
void PADControlMotor(s32, u32);
// PAL: 0x801af9c0
void SPEC0_MakeStatus(s32, PADStatus*, u32[2]);
// PAL: 0x801afad8
void SPEC1_MakeStatus(s32, PADStatus*, u32[2]);
// PAL: 0x801afbf0
void SPEC2_MakeStatus(s32, PADStatus*, u32[2]);
// PAL: 0x801afffc
int PAD_OnReset(int);
// PAL: 0x801b00c4
void PAD_SamplingHandler(s32, OSContext*);
// PAL: 0x801b0124
int __PADDisableRecalibration(int);
// PAL: 0x801b0124
// PADSetSamplingCallback

void PADSetSpec(u32 model);
u32 PADGetSpec(void);

typedef void (*PADSamplingCallback)(void);

#ifdef __cplusplus
} // extern "C"
#endif
