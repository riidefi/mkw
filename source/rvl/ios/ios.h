#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef s32 (*IOSCallback)(s32 errCode, void* data);

s32 IOS_Open(const char*, u32);
s32 IOS_OpenAsync(const char*, u32, IOSCallback);
s32 IOS_Close(u32);
s32 IOS_Ioctl(s32, s32, void*, u32, void*, u32);

#ifdef __cplusplus
}
#endif
