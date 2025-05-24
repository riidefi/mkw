#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8014a060..0x8014a1fc
UNKNOWN_FUNCTION(L2CA_Register);
// PAL: 0x8014a1fc..0x8014a28c
UNKNOWN_FUNCTION(L2CA_Deregister);
// PAL: 0x8014a28c..0x8014a4c0
UNKNOWN_FUNCTION(L2CA_ConnectReq);
// PAL: 0x8014a4c0..0x8014a650
UNKNOWN_FUNCTION(L2CA_ConnectRsp);
// PAL: 0x8014a650..0x8014a708
UNKNOWN_FUNCTION(L2CA_ConfigReq);
// PAL: 0x8014a708..0x8014a7d8
UNKNOWN_FUNCTION(L2CA_ConfigRsp);
// PAL: 0x8014a7d8..0x8014a87c
UNKNOWN_FUNCTION(L2CA_DisconnectReq);
// PAL: 0x8014a87c..0x8014a920
UNKNOWN_FUNCTION(L2CA_DisconnectRsp);
// PAL: 0x8014a920..0x8014aa44
UNKNOWN_FUNCTION(L2CA_DataWrite);
// PAL: 0x8014aa44..0x8014ab0c
UNKNOWN_FUNCTION(L2CA_SetIdleTimeout);
// PAL: 0x8014ab0c..0x8014ac0c
UNKNOWN_FUNCTION(L2CA_SetIdleTimeoutByBdAddr);
// PAL: 0x8014ac0c..0x8014ac28
UNKNOWN_FUNCTION(L2CA_SetTraceLevel);
// PAL: 0x8014ac28..0x8014ac2c
UNKNOWN_FUNCTION(L2CA_RegisterCompression);

#ifdef __cplusplus
}
#endif
