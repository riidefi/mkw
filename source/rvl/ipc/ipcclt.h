#pragma once

#include <rk_types.h>

#include "decomp.h"

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80193048..0x80193074
UNKNOWN_FUNCTION(strnlen);
// PAL: 0x80193074..0x801932cc
UNKNOWN_FUNCTION(IpcReplyHandler);
// PAL: 0x801932cc..0x80193478
UNKNOWN_FUNCTION(IPCInterruptHandler);
// PAL: 0x80193478..0x8019352c
UNKNOWN_FUNCTION(IPCCltInit);
// PAL: 0x8019352c..0x801935a0
UNKNOWN_FUNCTION(IPCCltReInit);
// PAL: 0x801935a0..0x801937e0
UNKNOWN_FUNCTION(__ios_Ipc2);
// PAL: 0x801937e0..0x801938f8
UNKNOWN_FUNCTION(IOS_OpenAsync);
// PAL: 0x801938f8..0x80193a18
UNKNOWN_FUNCTION(IOS_Open);
// PAL: 0x80193a18..0x80193ad8
UNKNOWN_FUNCTION(IOS_CloseAsync);
// PAL: 0x80193ad8..0x80193b80
UNKNOWN_FUNCTION(IOS_Close);
// PAL: 0x80193b80..0x80193c80
UNKNOWN_FUNCTION(IOS_ReadAsync);
// PAL: 0x80193c80..0x80193d88
UNKNOWN_FUNCTION(IOS_Read);
// PAL: 0x80193d88..0x80193e88
UNKNOWN_FUNCTION(IOS_WriteAsync);
// PAL: 0x80193e88..0x80193f90
UNKNOWN_FUNCTION(IOS_Write);
// PAL: 0x80193f90..0x80194070
UNKNOWN_FUNCTION(IOS_SeekAsync);
// PAL: 0x80194070..0x80194158
UNKNOWN_FUNCTION(IOS_Seek);
// PAL: 0x80194158..0x80194290
UNKNOWN_FUNCTION(IOS_IoctlAsync);
// PAL: 0x80194290..0x801943c0
UNKNOWN_FUNCTION(IOS_Ioctl);
// PAL: 0x801943c0..0x801944fc
UNKNOWN_FUNCTION(__ios_Ioctlv);
// PAL: 0x801944fc..0x801945e0
UNKNOWN_FUNCTION(IOS_IoctlvAsync);
// PAL: 0x801945e0..0x801946bc
UNKNOWN_FUNCTION(IOS_Ioctlv);
// PAL: 0x801946bc..0x801949b8
UNKNOWN_FUNCTION(IOS_IoctlvReboot);

#ifdef __cplusplus
}
#endif