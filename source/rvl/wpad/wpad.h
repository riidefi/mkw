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

// PAL: 0x801bf5c4
extern UNKNOWN_FUNCTION(WPADInit);
// PAL: 0x801bf634
extern UNKNOWN_FUNCTION(WPADStartSyncSimple);
// PAL: 0x801bf63c
extern UNKNOWN_FUNCTION(WPADStopSimpleSync);
// PAL: 0x801bf640
extern UNKNOWN_FUNCTION(WPADSetSyncDeviceCallback);
// PAL: 0x801bf64c
extern UNKNOWN_FUNCTION(WPADGetStatus);
// PAL: 0x801bf714
extern UNKNOWN_FUNCTION(WPADGetSensorBarPosition);
// PAL: 0x801c07d0
extern UNKNOWN_FUNCTION(WPADGetAccGravityUnit);
// PAL: 0x801c0990
extern UNKNOWN_FUNCTION(WPADProbe);
// PAL: 0x801c0a1c
extern UNKNOWN_FUNCTION(WPADSetSamplingCallback);
// PAL: 0x801c0b54
extern UNKNOWN_FUNCTION(WPADGetDataFormat);
// PAL: 0x801c0b9c
extern UNKNOWN_FUNCTION(WPADSetDataFormat);
// PAL: 0x801c0ca4
extern UNKNOWN_FUNCTION(WPADGetInfoAsync);
// PAL: 0x801c0ec4
extern UNKNOWN_FUNCTION(WPADControlMotor);
// PAL: 0x801c128c
extern UNKNOWN_FUNCTION(WPADRead);
// PAL: 0x801c329c
extern UNKNOWN_FUNCTION(WPADGetDpdSensitivity);
// PAL: 0x801c32a4
extern UNKNOWN_FUNCTION(WPADIsDpdEnabled);
// PAL: 0x801c3318
extern UNKNOWN_FUNCTION(WPADControlDpd);

#ifdef __cplusplus
}
#endif
