#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x801399a0..0x80139b28
UNKNOWN_FUNCTION(BTM_SecAddDevice);
// PAL: 0x80139b28..0x80139bd4
UNKNOWN_FUNCTION(BTM_SecDeleteDevice);
// PAL: 0x80139bd4..0x80139c74
UNKNOWN_FUNCTION(BTM_SecReadDevName);
// PAL: 0x80139c74..0x80139d94
UNKNOWN_FUNCTION(btm_sec_alloc_dev);
// PAL: 0x80139d94..0x80139e4c
UNKNOWN_FUNCTION(btm_find_dev_by_handle);
// PAL: 0x80139e4c..0x80139ed4
UNKNOWN_FUNCTION(btm_find_dev);
// PAL: 0x80139ed4..0x8013a06c
UNKNOWN_FUNCTION(btm_find_oldest_dev);

#ifdef __cplusplus
}
#endif
