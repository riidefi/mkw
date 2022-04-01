#pragma once

#include <rk_types.h>
#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x801bf5c4
extern UNKNOWN_FUNCTION(WPADInit);
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
