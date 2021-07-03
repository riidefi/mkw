#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*SO_FreeFunc)(u32, u32, u32);

typedef struct SOSysWork {
  char _unk00[0x4];     // 0x00
  SO_FreeFunc freeFunc; // 0x04
  s32 rmState;          // 0x08
  char _unk0C[0x4];     // 0x0C
  u32 _unk10;           // 0x10
  s32 allocCount;       // 0x14
} SOSysWork;

// PAL: 0x801ec088
int SOFinish(void);

#ifdef __cplusplus
}
#endif
