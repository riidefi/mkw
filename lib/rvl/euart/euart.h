#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80167b08..0x80167c04
UNKNOWN_FUNCTION(EUARTInit);
// PAL: 0x80167c04..0x80167c4c
UNKNOWN_FUNCTION(InitializeUART);
// PAL: 0x80167c4c..0x80167e78
UNKNOWN_FUNCTION(WriteUARTN);

#ifdef __cplusplus
}
#endif
