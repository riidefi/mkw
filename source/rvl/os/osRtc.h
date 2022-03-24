#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x801a8a9c..0x801a8bd4
UNKNOWN_FUNCTION(WriteSramCallback);
// PAL: 0x801a8bd4..0x801a8dd4
UNKNOWN_FUNCTION(__OSInitSram);
// PAL: 0x801a8dd4..0x801a90b4
UNKNOWN_FUNCTION(UnlockSram);
// PAL: 0x801a90b4..0x801a90c4
UNKNOWN_FUNCTION(__OSSyncSram);
// PAL: 0x801a90c4..0x801a91e8
UNKNOWN_FUNCTION(__OSReadROM);
// PAL: 0x801a91e8..0x801a9260
UNKNOWN_FUNCTION(OSGetWirelessID);
// PAL: 0x801a9260..0x801a92fc
UNKNOWN_FUNCTION(OSSetWirelessID);
// PAL: 0x801a92fc..0x801a9418
UNKNOWN_FUNCTION(__OSGetRTCFlags);
// PAL: 0x801a9418..0x801a9528
UNKNOWN_FUNCTION(__OSClearRTCFlags);

#ifdef __cplusplus
}
#endif
