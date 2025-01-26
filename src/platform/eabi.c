#include <decomp.h>

static asm void __save_gpr(void) {
  // clang-format off
  nofralloc;
entry _savegpr_14
  stw r14,-72(r11);
entry _savegpr_15
  stw r15,-68(r11);
entry _savegpr_16
  stw r16,-64(r11);
entry _savegpr_17
  stw r17,-60(r11);
entry _savegpr_18
  stw r18,-56(r11);
entry _savegpr_19
  stw r19,-52(r11);
entry _savegpr_20
  stw r20,-48(r11);
entry _savegpr_21
  stw r21,-44(r11);
entry _savegpr_22
  stw r22,-40(r11);
entry _savegpr_23
  stw r23,-36(r11);
entry _savegpr_24
  stw r24,-32(r11);
entry _savegpr_25
  stw r25,-28(r11);
entry _savegpr_26
  stw r26,-24(r11);
entry _savegpr_27
  stw r27,-20(r11);
  stw r28,-16(r11);
  stw r29,-12(r11);
  stw r30,-8(r11);
  stw r31,-4(r11);
  blr;
  // clang-format on
}

static asm void __rest_gpr(void) {
  // clang-format off
  nofralloc;
entry _restgpr_14
  lwz r14,-72(r11);
entry _restgpr_15
  lwz r15,-68(r11);
entry _restgpr_16
  lwz r16,-64(r11);
entry _restgpr_17
  lwz r17,-60(r11);
entry _restgpr_18
  lwz r18,-56(r11);
entry _restgpr_19
  lwz r19,-52(r11);
entry _restgpr_20
  lwz r20,-48(r11);
entry _restgpr_21
  lwz r21,-44(r11);
entry _restgpr_22
  lwz r22,-40(r11);
entry _restgpr_23
  lwz r23,-36(r11);
entry _restgpr_24
  lwz r24,-32(r11);
entry _restgpr_25
  lwz r25,-28(r11);
entry _restgpr_26
  lwz r26,-24(r11);
entry _restgpr_27
  lwz r27,-20(r11);
  lwz r28,-16(r11);
  lwz r29,-12(r11);
  lwz r30,-8(r11);
  lwz r31,-4(r11);
  blr;
  // clang-format on
}
