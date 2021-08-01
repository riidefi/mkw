#include "decomp.h"

static asm void __save_gpr(void)
{
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
}
