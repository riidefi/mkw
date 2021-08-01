#include "decomp.h"

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

asm void __div2u(void) {
  // clang-format off
  nofralloc;
  cmpwi cr0, r3, 0;
  cntlzw r0, r3;
  cntlzw r9, r4;
  bne cr0, lab1;
  addi r0, r9, 32;
lab1:
  cmpwi cr0, r5, 0;
  cntlzw r9, r5;
  cntlzw r10, r6;
  bne cr0, lab2;
  addi r9, r10, 32;
lab2:
  cmpw cr0, r0, r9;
  subfic r10, r0, 64;
  bgt cr0, lab9;
  addi r9, r9, 1;
  subfic r9, r9, 64;
  add r0, r0, r9;
  subf r9, r9, r10;
  mtctr r9;
  cmpwi cr0, r9, 32;
  addi r7, r9, -32;
  blt cr0, lab3;
  srw r8, r3, r7;
  li r7, 0;
  b lab4;
lab3:
  srw r8, r4, r9;
  subfic r7, r9, 32;
  slw r7, r3, r7;
  or r8, r8, r7;
  srw r7, r3, r9;
lab4:
  cmpwi cr0, r0, 32;
  addic r9, r0, -32;
  blt cr0, lab5;
  slw r3, r4, r9;
  li r4, 0;
  b lab6;
lab5:
  slw r3, r3, r0;
  subfic r9, r0, 32;
  srw r9, r4, r9;
  or r3, r3, r9;
  slw r4, r4, r0;
lab6:
  li r10, -1;
  addic r7, r7, 0;
lab7:
  adde r4, r4, r4;
  adde r3, r3, r3;
  adde r8, r8, r8;
  adde r7, r7, r7;
  subfc r0, r6, r8;
  subfe. r9, r5, r7;
  blt cr0, lab8;
  mr r8, r0;
  mr r7, r9;
  addic r0, r10, 1;
lab8:
  bdnz lab7;
  adde r4, r4, r4;
  adde r3, r3, r3;
  blr;
lab9:
  li r4, 0;
  li r3, 0;
  blr;
  // clang-format on
}
