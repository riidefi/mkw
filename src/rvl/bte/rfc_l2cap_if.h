#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80151bac..0x80151c28
UNKNOWN_FUNCTION(rfcomm_l2cap_if_init);
// PAL: 0x80151c28..0x80151cb4
UNKNOWN_FUNCTION(RFCOMM_ConnectInd);
// PAL: 0x80151cb4..0x80151db8
UNKNOWN_FUNCTION(RFCOMM_ConnectCnf);
// PAL: 0x80151db8..0x80151ec0
UNKNOWN_FUNCTION(RFCOMM_ConfigInd);
// PAL: 0x80151ec0..0x80151fc8
UNKNOWN_FUNCTION(RFCOMM_ConfigCnf);
// PAL: 0x80151fc8..0x80151fcc
UNKNOWN_FUNCTION(RFCOMM_QoSViolationInd);
// PAL: 0x80151fcc..0x801520f0
UNKNOWN_FUNCTION(RFCOMM_DisconnectInd);
// PAL: 0x801520f0..0x80152390
UNKNOWN_FUNCTION(RFCOMM_BufDataInd);
// PAL: 0x80152390..0x801524c4
UNKNOWN_FUNCTION(RFCOMM_CongestionStatusInd);
// PAL: 0x801524c4..0x801524e0
UNKNOWN_FUNCTION(rfc_save_lcid_mcb);

#ifdef __cplusplus
}
#endif
