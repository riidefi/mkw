#pragma once

#include <stdio.h>

#include <decomp.h>
#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x800100e4..0x800104b4
UNKNOWN_FUNCTION(double2hex);
// PAL: 0x800104b4..0x800105dc
UNKNOWN_FUNCTION(round_decimal);
// PAL: 0x800105dc..0x80010d74
UNKNOWN_FUNCTION(float2str);
// PAL: 0x80010d74..0x80011620
UNKNOWN_FUNCTION(__pformatter);
// PAL: 0x80011620..0x80011678
UNKNOWN_FUNCTION(__FileWrite);
// PAL: 0x80011678..0x800116e4
UNKNOWN_FUNCTION(__StringWrite);

#ifdef __cplusplus
}
#endif
