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

// PAL: 0x80127250..0x80127258
u32 __AXGetNumVoices(void);
// PAL: 0x80127258..0x801277a8
UNKNOWN_FUNCTION(__AXServiceVPB);
// PAL: 0x801277a8..0x80127ab8
UNKNOWN_FUNCTION(__AXSyncPBs);
// PAL: 0x80127ab8..0x80127ac0
AXPB* __AXGetPBs(void);
// PAL: 0x80127ac0..0x80127b00
UNKNOWN_FUNCTION(__AXSetPBDefault);
// PAL: 0x80127b00..0x80127db8
UNKNOWN_FUNCTION(__AXVPBInit);
// PAL: 0x80127db8..0x80127e28
UNKNOWN_FUNCTION(AXSetVoiceState);
// PAL: 0x80127e28..0x80127f20
UNKNOWN_FUNCTION(AXSetVoiceAddr);
// PAL: 0x80127f20..0x80127fdc
UNKNOWN_FUNCTION(AXGetLpfCoefs);
// PAL: 0x80127fdc..0x80127fe4
UNKNOWN_FUNCTION(AXSetMaxDspCycles);
// PAL: 0x80127fe4..0x80127fec
UNKNOWN_FUNCTION(AXGetMaxVoices);

#ifdef __cplusplus
}
#endif
