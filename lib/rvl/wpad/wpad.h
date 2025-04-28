#pragma once

#include <rk_types.h>
#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// Size: 0x7 (padded to 0x8)
typedef struct DPDObject {
  s16 x;
  s16 y;
  u16 size;
  u8 traceId;
} DPDObject;

// Size: 0x2a (padded to 0x2c)
typedef struct WPADStatus {
  u16 button;
  s16 accX;
  s16 accY;
  s16 accZ;
  DPDObject obj[4];
  u8 dev; // controller type
  s8 err; // error status
} WPADStatus;

// Size: 0x32
typedef struct WPADFSStatus {
  u16 button;
  s16 accX;
  s16 accY;
  s16 accZ;
  DPDObject obj[4];
  u8 dev; // controller type
  s8 err; // error status
  s16 fsAccX;
  s16 fsAccY;
  s16 fsAccZ;
  s8 fsStickX;
  s8 fsStickY;
} WPADFSStatus;

// Size: 0x36 (padded to 0x38)
typedef struct WPADCLStatus {
  u16 button;
  s16 accX;
  s16 accY;
  s16 accZ;
  DPDObject obj[4];
  u8 dev; // controller type
  s8 err; // error status
  u16 clButton;
  s16 clLStickX;
  s16 clLStickY;
  s16 clRStickX;
  s16 clRStickY;
  u8 clTriggerL;
  u8 clTriggerR;
} WPADCLStatus;

// Size: 0x18
typedef struct WPADInfo {
  s32 dpd;
  s32 speaker;
  s32 attach;
  s32 lowBat;
  s32 nearempty;
  u8 battery;
  u8 led;
  u8 protocol;
  u8 firmware;
} WPADInfo;

#ifdef __cplusplus
}
#endif
