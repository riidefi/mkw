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

asm void __div2i(void) {
  // clang-format off
  nofralloc;
  stwu SP, -16(SP);
  rlwinm. r9, r3, 0, 0, 0;
  beq cr0, lab11;
  subfic r4, r4, 0;
  subfze r3, r3;
lab11:
  stw r9, 8(r1);
  rlwinm. r10, r5, 0, 0, 0;
  beq cr0, lab12;
  subfic r6, r6, 0;
  subfze r5, r5;
lab12:
  stw r10, 12(r1);
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
  subfe.r9, r5, r7;
  blt cr0, lab8;
  mr r8, r0;
  mr r7, r9;
  addic r0, r10, 1;
lab8:
  bdnz lab7;
  adde r4, r4, r4;
  adde r3, r3, r3;
  lwz r9, 8(r1);
  lwz r10, 12(r1);
  xor. r7, r9, r10;
  beq cr0, lab10;
  cmpwi cr0, r9, 0;
  subfic r4, r4, 0;
  subfze r3, r3;
lab10:
  b lab13;
lab9:
  li r4, 0;
  li r3, 0;
lab13:
  addi SP, SP, 16;
  blr;
  // clang-format on
}

asm void __mod2u(void) {
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
  mr r4, r8;
  mr r3, r7;
  blr;
lab9:
  blr;
  // clang-format on
}

asm void __mod2i(void) {
  // clang-format off
  nofralloc;
  cmpwi cr7, r3, 0;
  bge cr7, lab11;
  subfic r4, r4, 0;
  subfze r3, r3;
lab11:
  cmpwi cr0, r5, 0;
  bge cr0, lab12;
  subfic r6, r6, 0;
  subfze r5, r5;
lab12:
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
  mr r4, r8;
  mr r3, r7;
lab9:
  bge cr7, no_adjust;
  subfic r4, r4, 0;
  subfze r3, r3;
no_adjust:
  blr;
  // clang-format on
}

asm void __shl2i(void) {
  nofralloc;
  subfic r8, r5, 32;
  subic r9, r5, 32;
  slw r3, r3, r5;
  srw r10, r4, r8;
  or r3, r3, r10;
  slw r10, r4, r9;
  or r3, r3, r10;
  slw r4, r4, r5;
  blr;
}

asm void __shr2u(void) {
  nofralloc;
  subfic r8, r5, 32;
  subic r9, r5, 32;
  srw r4, r4, r5;
  slw r10, r3, r8;
  or r4, r4, r10;
  srw r10, r3, r9;
  or r4, r4, r10;
  srw r3, r3, r5;
  blr;
}

// PAL: 0x80021a60
asm void __cvt_ull_flt(void) {
  // clang-format off
  nofralloc;
  stwu SP, -16(SP);
  or. r7, r3, r4;
  li r6, 0;
  beq cr0, lab3;
  cntlzw r7, r3;
  cntlzw r8, r4;
  rlwinm r9, r7, 26, 0, 4;
  srawi r9, r9, 31;
  and r9, r9, r8;
  add r7, r7, r9;
  subfic r8, r7, 32;
  subic r9, r7, 32;
  slw r3, r3, r7;
  srw r10, r4, r8;
  or r3, r3, r10;
  slw r10, r4, r9;
  or r3, r3, r10;
  slw r4, r4, r7;
  sub r6, r6, r7;
  rlwinm r7, r4, 0, 21, 31;
  cmpi cr0, r7, 0x400;
  addi r6, r6, 1086;
  blt lab2;
  bgt lab1;
  rlwinm. r7, r4, 0, 20, 20;
  beq lab2;
lab1:
  addic r4, r4, 0x0800;
  addze r3, r3;
  addze r6, r6;
lab2:
  rlwinm r4, r4, 21, 0, 31;
  rlwimi r4, r3, 21, 0, 10;
  rlwinm r3, r3, 21, 12, 31;
  rlwinm r6, r6, 20, 0, 11;
  or r3, r6, r3;
lab3:
  stw r3, 8(r1);
  stw r4, 12(r1);
  lfd f1, 8(r1);
  frsp f1, f1;
  addi SP, SP, 16;
  blr;
  // clang-format on
}

asm void __cvt_dbl_ull(void) {
  // clang-format off
  nofralloc;
  stwu SP, -16(SP);
  stfd f1, 8(r1);
  lwz r3, 8(r1);
  lwz r4, 12(r1);
  rlwinm r5, r3, 12, 21, 31;
  cmpli cr0, 0, r5, 1023;
  bge cr0, lab5;
lab1:
  li r3, 0;
  li r4, 0;
  b lab4;
lab5:
  rlwinm. r6, r3, 0, 0, 0;
  bne cr0, lab1;
  rlwinm r3, r3, 0, 12, 31;
  oris r3, r3, 0x0010;
  addi r5, r5, -1075;
  cmpwi cr0, r5, 0;
  bge cr0, lab2;
  neg r5, r5;
  subfic r8, r5, 32;
  subic r9, r5, 32;
  srw r4, r4, r5;
  slw r10, r3, r8;
  or r4, r4, r10;
  srw r10, r3, r9;
  or r4, r4, r10;
  srw r3, r3, r5;
  b lab4;
lab2:
  cmpwi cr0, r5, 11;
  ble + lab3;
  li r3, -1;
  li r4, -1;
  b lab4;
lab3:
  subfic r8, r5, 32;
  subic r9, r5, 32;
  slw r3, r3, r5;
  srw r10, r4, r8;
  or r3, r3, r10;
  slw r10, r4, r9;
  or r3, r3, r10;
  slw r4, r4, r5;
lab4:
  addi SP, SP, 16;
  blr;
  // clang-format on
}
