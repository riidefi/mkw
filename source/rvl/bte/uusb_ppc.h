#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8013099c..0x801309a8
u32 __ntd_get_allocated_mem_size();
// PAL: 0x801309a8..0x80130a3c
UNKNOWN_FUNCTION(uusb_CloseDeviceCB);
// PAL: 0x80130a3c..0x80130b50
UNKNOWN_FUNCTION(uusb_ReadIntrDataCB);
// PAL: 0x80130b50..0x80130cec
UNKNOWN_FUNCTION(uusb_ReadBulkDataCB);
// PAL: 0x80130cec..0x80130db8
UNKNOWN_FUNCTION(uusb_issue_intr_read);
// PAL: 0x80130db8..0x80130ea4
UNKNOWN_FUNCTION(uusb_WriteCtrlDataCB);
// PAL: 0x80130ea4..0x80130f84
UNKNOWN_FUNCTION(uusb_WriteBulkDataCB);
// PAL: 0x80130f84..0x8013118c
UNKNOWN_FUNCTION(UUSB_Register);
// PAL: 0x8013118c..0x80131294
UNKNOWN_FUNCTION(UUSB_Open);
// PAL: 0x80131294..0x8013129c
UNKNOWN_FUNCTION(UUSB_Read);
// PAL: 0x8013129c..0x801314b0
UNKNOWN_FUNCTION(UUSB_Write);
// PAL: 0x801314b0..0x8013155c
UNKNOWN_FUNCTION(UUSB_Close);
// PAL: 0x8013155c..0x801315a0
UNKNOWN_FUNCTION(UUSB_Unregister);

#ifdef __cplusplus
}
#endif
