#pragma once

#include <rk_types.h>

s32 IOS_Open(const char*, u32);
s32 IOS_Close(u32);
s32 IOS_Ioctl(s32, s32, void*, u32, void*, u32);
