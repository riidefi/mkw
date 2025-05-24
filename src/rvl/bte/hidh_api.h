#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x801472a0..0x80147368
UNKNOWN_FUNCTION(HID_HostGetSDPRecord);
// PAL: 0x80147368..0x801477b8
UNKNOWN_FUNCTION(hidh_search_callback);
// PAL: 0x801477b8..0x801477fc
UNKNOWN_FUNCTION(HID_HostInit);
// PAL: 0x801477fc..0x80147878
UNKNOWN_FUNCTION(HID_HostRegister);
// PAL: 0x80147878..0x8014795c
UNKNOWN_FUNCTION(HID_HostDeregister);
// PAL: 0x8014795c..0x80147aec
UNKNOWN_FUNCTION(HID_HostAddDev);
// PAL: 0x80147aec..0x80147bb4
UNKNOWN_FUNCTION(HID_HostRemoveDev);
// PAL: 0x80147bb4..0x80147c18
UNKNOWN_FUNCTION(HID_HostOpenDev);
// PAL: 0x80147c18..0x80147d58
UNKNOWN_FUNCTION(HID_HostWriteDev);
// PAL: 0x80147d58..0x80147df8
UNKNOWN_FUNCTION(HID_HostCloseDev);
// PAL: 0x80147df8..0x80148020
UNKNOWN_FUNCTION(HID_HostSetSecurityLevel);

#ifdef __cplusplus
}
#endif
