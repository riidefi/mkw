#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80163818..0x80163844
UNKNOWN_FUNCTION(dvd_cbForNandClose);
// PAL: 0x80163844..0x801638a0
UNKNOWN_FUNCTION(dvd_cbForNandWrite);
// PAL: 0x801638a0..0x80163968
UNKNOWN_FUNCTION(dvd_cbForNandSeek);
// PAL: 0x80163968..0x80163a88
UNKNOWN_FUNCTION(dvd_cbForNandWrite0);
// PAL: 0x80163a88..0x80163b44
UNKNOWN_FUNCTION(dvd_cbForNandSeek2);
// PAL: 0x80163b44..0x80163c2c
UNKNOWN_FUNCTION(dvd_cbForNandRead);
// PAL: 0x80163c2c..0x80163ccc
UNKNOWN_FUNCTION(dvd_cbForNandSeek0);
// PAL: 0x80163ccc..0x80163dcc
UNKNOWN_FUNCTION(dvd_cbForNandSeek1);
// PAL: 0x80163dcc..0x80163ee8
UNKNOWN_FUNCTION(dvd_cbForNandOpen);
// PAL: 0x80163ee8..0x80163f90
UNKNOWN_FUNCTION(dvd_cbForNandCreate);
// PAL: 0x80163f90..0x80164024
UNKNOWN_FUNCTION(dvd_cbForNandCreateDir);
// PAL: 0x80164024..0x801640b4
UNKNOWN_FUNCTION(dvd_cbForPrepareStatusRegister);
// PAL: 0x801640b4..0x8016411c
UNKNOWN_FUNCTION(__DVDStoreErrorCode);

#ifdef __cplusplus
}
#endif
