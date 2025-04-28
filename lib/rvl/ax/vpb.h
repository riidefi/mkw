#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct AXPB {
  u32 _unk00;
} AXPB;

typedef struct AXPBITDBUFFER {
  char data[64];
} AXPBITDBUFFER;

typedef struct AXVPB {
  u32 _unk00;
  u32 _unk04;
  u32 _unk08;
  u32 _unk0c;
  u32 _unk10;
  u32 _unk14;
  u32 _unk18;
  u32 _unk1c;
  u32 _unk20;
  u32 _unk24;
  AXPB pb;
} AXVPB;

u32 __AXGetNumVoices(void);
AXPB* __AXGetPBs(void);

#ifdef __cplusplus
}
#endif
