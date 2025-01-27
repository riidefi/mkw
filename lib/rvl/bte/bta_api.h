#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8013485c..0x801348e4
UNKNOWN_FUNCTION(BTA_EnableBluetooth);
// PAL: 0x801348e4..0x8013491c
UNKNOWN_FUNCTION(BTA_DisableBluetooth);
// PAL: 0x8013491c..0x80134954
UNKNOWN_FUNCTION(BTA_DmIsDeviceUp);
// PAL: 0x80134954..0x801349b8
UNKNOWN_FUNCTION(BTA_DmSetDeviceName);
// PAL: 0x801349b8..0x80134a10
UNKNOWN_FUNCTION(BTA_DmSetVisibility);
// PAL: 0x80134a10..0x80134a94
UNKNOWN_FUNCTION(BTA_DmSearch);
// PAL: 0x80134a94..0x80134acc
UNKNOWN_FUNCTION(BTA_DmSearchCancel);
// PAL: 0x80134acc..0x80134b58
UNKNOWN_FUNCTION(BTA_DmPinReply);
// PAL: 0x80134b58..0x80134c48
UNKNOWN_FUNCTION(BTA_DmAddDevice);
// PAL: 0x80134c48..0x80134c90
UNKNOWN_FUNCTION(BTA_DmRemoveDevice);
// PAL: 0x80134c90..0x80134cc8
UNKNOWN_FUNCTION(BTA_DmSendHciReset);

#ifdef __cplusplus
}
#endif
