#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8000cadc..0x8000cbb8
UNKNOWN_FUNCTION(__ull2dec);
// PAL: 0x8000cbb8..0x8000ce40
UNKNOWN_FUNCTION(__timesdec);
// PAL: 0x8000ce40..0x8000cf2c
UNKNOWN_FUNCTION(__str2dec);
// PAL: 0x8000cf2c..0x8000d298
UNKNOWN_FUNCTION(__two_exp);
// PAL: 0x8000d298..0x8000d37c
UNKNOWN_FUNCTION(__equals_dec);
// PAL: 0x8000d37c..0x8000d47c
UNKNOWN_FUNCTION(__less_dec);
// PAL: 0x8000d47c..0x8000d998
UNKNOWN_FUNCTION(__minus_dec);
// PAL: 0x8000d998..0x8000dafc
UNKNOWN_FUNCTION(__num2dec_internal);
// PAL: 0x8000dafc..0x8000dc9c
UNKNOWN_FUNCTION(__num2dec);
// PAL: 0x8000dc9c..0x8000e418
UNKNOWN_FUNCTION(__dec2num);

#ifdef __cplusplus
}
#endif
