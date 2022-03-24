#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80169bcc..0x80169cf4
UNKNOWN_FUNCTION(ISFS_OpenLib);
// PAL: 0x80169cf4..0x80169e74
UNKNOWN_FUNCTION(_isfsFuncCb);
// PAL: 0x80169e74..0x80169f68
UNKNOWN_FUNCTION(ISFS_CreateDir);
// PAL: 0x80169f68..0x8016a05c
UNKNOWN_FUNCTION(ISFS_CreateDirAsync);
// PAL: 0x8016a05c..0x8016a1b0
UNKNOWN_FUNCTION(ISFS_ReadDir);
// PAL: 0x8016a1b0..0x8016a2f8
UNKNOWN_FUNCTION(ISFS_ReadDirAsync);
// PAL: 0x8016a2f8..0x8016a3fc
UNKNOWN_FUNCTION(ISFS_SetAttr);
// PAL: 0x8016a3fc..0x8016a500
UNKNOWN_FUNCTION(ISFS_SetAttrAsync);
// PAL: 0x8016a500..0x8016a658
UNKNOWN_FUNCTION(ISFS_GetAttr);
// PAL: 0x8016a658..0x8016a78c
UNKNOWN_FUNCTION(ISFS_GetAttrAsync);
// PAL: 0x8016a78c..0x8016a864
UNKNOWN_FUNCTION(ISFS_Delete);
// PAL: 0x8016a864..0x8016a934
UNKNOWN_FUNCTION(ISFS_DeleteAsync);
// PAL: 0x8016a934..0x8016aa38
UNKNOWN_FUNCTION(ISFS_Rename);
// PAL: 0x8016aa38..0x8016ab3c
UNKNOWN_FUNCTION(ISFS_RenameAsync);
// PAL: 0x8016ab3c..0x8016ac74
UNKNOWN_FUNCTION(ISFS_GetUsage);
// PAL: 0x8016ac74..0x8016ad68
UNKNOWN_FUNCTION(ISFS_CreateFile);
// PAL: 0x8016ad68..0x8016ae5c
UNKNOWN_FUNCTION(ISFS_CreateFileAsync);
// PAL: 0x8016ae5c..0x8016af24
UNKNOWN_FUNCTION(ISFS_Open);
// PAL: 0x8016af24..0x8016afdc
UNKNOWN_FUNCTION(ISFS_OpenAsync);
// PAL: 0x8016afdc..0x8016b0ac
UNKNOWN_FUNCTION(ISFS_GetFileStats);
// PAL: 0x8016b0ac..0x8016b16c
UNKNOWN_FUNCTION(ISFS_GetFileStatsAsync);
// PAL: 0x8016b16c..0x8016b170
UNKNOWN_FUNCTION(ISFS_Seek);
// PAL: 0x8016b170..0x8016b1fc
UNKNOWN_FUNCTION(ISFS_SeekAsync);
// PAL: 0x8016b1fc..0x8016b21c
UNKNOWN_FUNCTION(ISFS_Read);
// PAL: 0x8016b21c..0x8016b2c0
UNKNOWN_FUNCTION(ISFS_ReadAsync);
// PAL: 0x8016b2c0..0x8016b2e0
UNKNOWN_FUNCTION(ISFS_Write);
// PAL: 0x8016b2e0..0x8016b384
UNKNOWN_FUNCTION(ISFS_WriteAsync);
// PAL: 0x8016b384..0x8016b388
UNKNOWN_FUNCTION(ISFS_Close);
// PAL: 0x8016b388..0x8016b40c
UNKNOWN_FUNCTION(ISFS_CloseAsync);
// PAL: 0x8016b40c..0x8016b49c
UNKNOWN_FUNCTION(ISFS_ShutdownAsync);

#ifdef __cplusplus
}
#endif
