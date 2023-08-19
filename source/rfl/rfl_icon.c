#include "rfl_icon.h"

typedef struct rflCharInfo_ {
  u8 x[88];
} rflCharInfo;

extern s32 RFLiPickupCharInfo(rflCharInfo *);
extern s32 RFLiMakeIcon(s32, rflCharInfo *, s32, s32);

// Symbol: RFLMakeIcon
s32 RFLMakeIcon(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
  rflCharInfo info;
  s32 temp_r3;

  temp_r3 = RFLiPickupCharInfo(&info);
  if (temp_r3 == 0)
    RFLiMakeIcon(arg0, &info, arg4, arg5);
  return temp_r3;
}
