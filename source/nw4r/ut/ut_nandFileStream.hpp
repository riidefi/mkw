#pragma once

#include <rk_types.h>

#include "decomp.h"

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x800b0ad0..0x800b0b40
UNKNOWN_FUNCTION(NANDFileStream_ct1);
// PAL: 0x800b0b40..0x800b0bb0
UNKNOWN_FUNCTION(NANDFileStream_ct2);
// PAL: 0x800b0bb0..0x800b0c30
UNKNOWN_FUNCTION(NANDFileStream_dt);
// PAL: 0x800b0c30..0x800b0d20
UNKNOWN_FUNCTION(NANDFileStream_Open1);
// PAL: 0x800b0d20..0x800b14a0
UNKNOWN_FUNCTION(NANDFileStream_Open2);
// PAL: 0x800b14a0..0x800b14f0
UNKNOWN_FUNCTION(NANDFileStream_Close);
// PAL: 0x800b14f0..0x800b1570
UNKNOWN_FUNCTION(NANDFileStream_Read);
// PAL: 0x800b1570..0x800b1620
UNKNOWN_FUNCTION(NANDFileStream_ReadAsync);
// PAL: 0x800b1620..0x800b16a0
UNKNOWN_FUNCTION(NANDFileStream_Write);
// PAL: 0x800b16a0..0x800b1750
UNKNOWN_FUNCTION(NANDFileStream_WriteAsync);
// PAL: 0x800b1750..0x800b1758
UNKNOWN_FUNCTION(NANDFileStream_Seek);

#ifdef __cplusplus
}
#endif
