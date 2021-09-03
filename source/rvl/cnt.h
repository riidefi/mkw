#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

struct CNTFileInfoNAND {
  void* parent;
  u32 start;
  u32 len;
  s32 ofs;
};

int CNTConvertPathToEntrynum(void* handle, const char* path);
int contentFastOpenNAND(void* handle, int entry_num, void* file_handle);
int contentCloseNAND(void* file_handle);
int contentReadNAND(void* file_handle, void* buf, u32 len, s32 ofs);
u32 CNTGetLength(const void* file_handle);

#ifdef __cplusplus
}
#endif
