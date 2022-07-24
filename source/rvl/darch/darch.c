#include "darch.h"

#include <string.h>

#include <rvl/os/osError.h>

static u32 unk_803865f8;

// Symbol: darch_AddItem
// PAL: 0x8015c320..0x8015c37c
MARK_BINARY_BLOB(darch_AddItem, 0x8015c320, 0x8015c37c);
asm UNKNOWN_FUNCTION(darch_AddItem) {
  // clang-format off
  nofralloc;
  lwz r0, 0x18(r4);
  stw r3, 8(r4);
  cmpwi r0, 0;
  beq lbl_8015c338;
  addi r5, r3, 4;
  b lbl_8015c33c;
lbl_8015c338:
  addi r5, r3, 0xc;
lbl_8015c33c:
  lwz r3, 0(r5);
  cmpwi r3, 0;
  bne lbl_8015c360;
  stw r4, 0(r5);
  li r0, 0;
  stw r0, 0(r4);
  blr;
  b lbl_8015c360;
lbl_8015c35c:
  mr r3, r0;
lbl_8015c360:
  lwz r0, 0(r3);
  cmpwi r0, 0;
  bne lbl_8015c35c;
  stw r4, 0(r3);
  li r0, 0;
  stw r0, 0(r4);
  blr;
  // clang-format on
}

// Symbol: darch_MergeDirStructure
// PAL: 0x8015c37c..0x8015c868
MARK_BINARY_BLOB(darch_MergeDirStructure, 0x8015c37c, 0x8015c868);
asm UNKNOWN_FUNCTION(darch_MergeDirStructure) {
  // clang-format off
  nofralloc;
lbl_8015c37c:
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_24;
  lis r30, 0x8027;
  lwz r26, 4(r4);
  mr r24, r3;
  mr r25, r4;
  addi r30, r30, 0x1148;
  b lbl_8015c5e8;
lbl_8015c3a8:
  lwz r29, 0x14(r26);
  mr r3, r29;
  bl strlen;
  lwz r27, 4(r24);
  mr r31, r3;
  lwz r28, 0x38(r30);
  b lbl_8015c498;
lbl_8015c3c4:
  lwz r3, 0x14(r27);
  cmpwi r31, 0;
  mr r6, r29;
  mr r7, r3;
  bne lbl_8015c3e0;
  li r0, 1;
  b lbl_8015c47c;
lbl_8015c3e0:
  mtctr r31;
  cmplwi r31, 0;
  ble lbl_8015c478;
lbl_8015c3ec:
  lbz r8, 0(r6);
  li r0, 0;
  extsb. r8, r8;
  blt lbl_8015c404;
  cmpwi r8, 0x100;
  blt lbl_8015c408;
lbl_8015c404:
  li r0, 1;
lbl_8015c408:
  cmpwi r0, 0;
  beq lbl_8015c414;
  b lbl_8015c41c;
lbl_8015c414:
  lwz r4, 0x10(r28);
  lbzx r8, r4, r8;
lbl_8015c41c:
  lbz r9, 0(r7);
  li r0, 0;
  extsb. r5, r9;
  blt lbl_8015c434;
  cmpwi r5, 0x100;
  blt lbl_8015c438;
lbl_8015c434:
  li r0, 1;
lbl_8015c438:
  cmpwi r0, 0;
  beq lbl_8015c444;
  b lbl_8015c44c;
lbl_8015c444:
  lwz r4, 0x10(r28);
  lbzx r5, r4, r5;
lbl_8015c44c:
  cmpw r5, r8;
  beq lbl_8015c45c;
  li r0, 1;
  b lbl_8015c47c;
lbl_8015c45c:
  extsb. r0, r9;
  bne lbl_8015c46c;
  li r0, 0;
  b lbl_8015c47c;
lbl_8015c46c:
  addi r7, r7, 1;
  addi r6, r6, 1;
  bdnz lbl_8015c3ec;
lbl_8015c478:
  li r0, 0;
lbl_8015c47c:
  cmpwi r0, 0;
  bne lbl_8015c494;
  bl strlen;
  cmplw r31, r3;
  bne lbl_8015c494;
  b lbl_8015c588;
lbl_8015c494:
  lwz r27, 0(r27);
lbl_8015c498:
  cmpwi r27, 0;
  bne lbl_8015c3c4;
  lwz r27, 0xc(r24);
  b lbl_8015c57c;
lbl_8015c4a8:
  lwz r3, 0x14(r27);
  cmpwi r31, 0;
  mr r6, r29;
  mr r7, r3;
  bne lbl_8015c4c4;
  li r0, 1;
  b lbl_8015c560;
lbl_8015c4c4:
  mtctr r31;
  cmplwi r31, 0;
  ble lbl_8015c55c;
lbl_8015c4d0:
  lbz r8, 0(r6);
  li r0, 0;
  extsb. r8, r8;
  blt lbl_8015c4e8;
  cmpwi r8, 0x100;
  blt lbl_8015c4ec;
lbl_8015c4e8:
  li r0, 1;
lbl_8015c4ec:
  cmpwi r0, 0;
  beq lbl_8015c4f8;
  b lbl_8015c500;
lbl_8015c4f8:
  lwz r4, 0x10(r28);
  lbzx r8, r4, r8;
lbl_8015c500:
  lbz r9, 0(r7);
  li r0, 0;
  extsb. r5, r9;
  blt lbl_8015c518;
  cmpwi r5, 0x100;
  blt lbl_8015c51c;
lbl_8015c518:
  li r0, 1;
lbl_8015c51c:
  cmpwi r0, 0;
  beq lbl_8015c528;
  b lbl_8015c530;
lbl_8015c528:
  lwz r4, 0x10(r28);
  lbzx r5, r4, r5;
lbl_8015c530:
  cmpw r5, r8;
  beq lbl_8015c540;
  li r0, 1;
  b lbl_8015c560;
lbl_8015c540:
  extsb. r0, r9;
  bne lbl_8015c550;
  li r0, 0;
  b lbl_8015c560;
lbl_8015c550:
  addi r7, r7, 1;
  addi r6, r6, 1;
  bdnz lbl_8015c4d0;
lbl_8015c55c:
  li r0, 0;
lbl_8015c560:
  cmpwi r0, 0;
  bne lbl_8015c578;
  bl strlen;
  cmplw r31, r3;
  bne lbl_8015c578;
  b lbl_8015c588;
lbl_8015c578:
  lwz r27, 0(r27);
lbl_8015c57c:
  cmpwi r27, 0;
  bne lbl_8015c4a8;
  li r27, 0;
lbl_8015c588:
  cmpwi r27, 0;
  bne lbl_8015c5a0;
  mr r3, r24;
  mr r4, r26;
  bl darch_AddItem;
  b lbl_8015c5e4;
lbl_8015c5a0:
  lwz r0, 0x18(r27);
  cmpwi r0, 0;
  beq lbl_8015c5c8;
  mr r3, r27;
  mr r4, r26;
  bl lbl_8015c37c;
  cmpwi r3, 0;
  bne lbl_8015c5e4;
  li r3, 0;
  b lbl_8015c850;
lbl_8015c5c8:
  lis r3, 0x8028;
  lwz r4, 0x14(r24);
  addi r3, r3, 0x7fa0;
  crclr 6;
  bl OSReport;
  li r3, 0;
  b lbl_8015c850;
lbl_8015c5e4:
  lwz r26, 0(r26);
lbl_8015c5e8:
  cmpwi r26, 0;
  bne lbl_8015c3a8;
  lis r31, 0x8027;
  lwz r27, 0xc(r25);
  addi r31, r31, 0x1148;
  b lbl_8015c844;
lbl_8015c600:
  lwz r28, 0x14(r27);
  lwz r25, 0(r27);
  mr r3, r28;
  bl strlen;
  lwz r26, 4(r24);
  mr r30, r3;
  lwz r29, 0x38(r31);
  b lbl_8015c6f4;
lbl_8015c620:
  lwz r3, 0x14(r26);
  cmpwi r30, 0;
  mr r6, r28;
  mr r7, r3;
  bne lbl_8015c63c;
  li r0, 1;
  b lbl_8015c6d8;
lbl_8015c63c:
  mtctr r30;
  cmplwi r30, 0;
  ble lbl_8015c6d4;
lbl_8015c648:
  lbz r8, 0(r6);
  li r0, 0;
  extsb. r8, r8;
  blt lbl_8015c660;
  cmpwi r8, 0x100;
  blt lbl_8015c664;
lbl_8015c660:
  li r0, 1;
lbl_8015c664:
  cmpwi r0, 0;
  beq lbl_8015c670;
  b lbl_8015c678;
lbl_8015c670:
  lwz r4, 0x10(r29);
  lbzx r8, r4, r8;
lbl_8015c678:
  lbz r9, 0(r7);
  li r0, 0;
  extsb. r5, r9;
  blt lbl_8015c690;
  cmpwi r5, 0x100;
  blt lbl_8015c694;
lbl_8015c690:
  li r0, 1;
lbl_8015c694:
  cmpwi r0, 0;
  beq lbl_8015c6a0;
  b lbl_8015c6a8;
lbl_8015c6a0:
  lwz r4, 0x10(r29);
  lbzx r5, r4, r5;
lbl_8015c6a8:
  cmpw r5, r8;
  beq lbl_8015c6b8;
  li r0, 1;
  b lbl_8015c6d8;
lbl_8015c6b8:
  extsb. r0, r9;
  bne lbl_8015c6c8;
  li r0, 0;
  b lbl_8015c6d8;
lbl_8015c6c8:
  addi r7, r7, 1;
  addi r6, r6, 1;
  bdnz lbl_8015c648;
lbl_8015c6d4:
  li r0, 0;
lbl_8015c6d8:
  cmpwi r0, 0;
  bne lbl_8015c6f0;
  bl strlen;
  cmplw r30, r3;
  bne lbl_8015c6f0;
  b lbl_8015c7e4;
lbl_8015c6f0:
  lwz r26, 0(r26);
lbl_8015c6f4:
  cmpwi r26, 0;
  bne lbl_8015c620;
  lwz r26, 0xc(r24);
  b lbl_8015c7d8;
lbl_8015c704:
  lwz r3, 0x14(r26);
  cmpwi r30, 0;
  mr r6, r28;
  mr r7, r3;
  bne lbl_8015c720;
  li r0, 1;
  b lbl_8015c7bc;
lbl_8015c720:
  mtctr r30;
  cmplwi r30, 0;
  ble lbl_8015c7b8;
lbl_8015c72c:
  lbz r8, 0(r6);
  li r0, 0;
  extsb. r8, r8;
  blt lbl_8015c744;
  cmpwi r8, 0x100;
  blt lbl_8015c748;
lbl_8015c744:
  li r0, 1;
lbl_8015c748:
  cmpwi r0, 0;
  beq lbl_8015c754;
  b lbl_8015c75c;
lbl_8015c754:
  lwz r4, 0x10(r29);
  lbzx r8, r4, r8;
lbl_8015c75c:
  lbz r9, 0(r7);
  li r0, 0;
  extsb. r5, r9;
  blt lbl_8015c774;
  cmpwi r5, 0x100;
  blt lbl_8015c778;
lbl_8015c774:
  li r0, 1;
lbl_8015c778:
  cmpwi r0, 0;
  beq lbl_8015c784;
  b lbl_8015c78c;
lbl_8015c784:
  lwz r4, 0x10(r29);
  lbzx r5, r4, r5;
lbl_8015c78c:
  cmpw r5, r8;
  beq lbl_8015c79c;
  li r0, 1;
  b lbl_8015c7bc;
lbl_8015c79c:
  extsb. r0, r9;
  bne lbl_8015c7ac;
  li r0, 0;
  b lbl_8015c7bc;
lbl_8015c7ac:
  addi r7, r7, 1;
  addi r6, r6, 1;
  bdnz lbl_8015c72c;
lbl_8015c7b8:
  li r0, 0;
lbl_8015c7bc:
  cmpwi r0, 0;
  bne lbl_8015c7d4;
  bl strlen;
  cmplw r30, r3;
  bne lbl_8015c7d4;
  b lbl_8015c7e4;
lbl_8015c7d4:
  lwz r26, 0(r26);
lbl_8015c7d8:
  cmpwi r26, 0;
  bne lbl_8015c704;
  li r26, 0;
lbl_8015c7e4:
  cmpwi r26, 0;
  bne lbl_8015c7fc;
  mr r3, r24;
  mr r4, r27;
  bl darch_AddItem;
  b lbl_8015c840;
lbl_8015c7fc:
  lwz r0, 0x18(r26);
  cmpwi r0, 0;
  beq lbl_8015c824;
  lis r3, 0x8028;
  lwz r4, 0x14(r24);
  addi r3, r3, 0x7fc0;
  crclr 6;
  bl OSReport;
  li r3, 0;
  b lbl_8015c850;
lbl_8015c824:
  lis r3, 0x8028;
  lwz r4, 0x14(r24);
  addi r3, r3, 0x7fa0;
  crclr 6;
  bl OSReport;
  li r3, 0;
  b lbl_8015c850;
lbl_8015c840:
  mr r27, r25;
lbl_8015c844:
  cmpwi r27, 0;
  bne lbl_8015c600;
  li r3, 1;
lbl_8015c850:
  addi r11, r1, 0x30;
  bl _restgpr_24;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: darch_DecideOrderInFst
// PAL: 0x8015c868..0x8015c954
MARK_BINARY_BLOB(darch_DecideOrderInFst, 0x8015c868, 0x8015c954);
asm UNKNOWN_FUNCTION(darch_DecideOrderInFst) {
  // clang-format off
  nofralloc;
lbl_8015c868:
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_26;
  mr r26, r3;
  lwz r3, 0x14(r3);
  mr r27, r4;
  mr r28, r5;
  li r29, 1;
  bl strlen;
  lwz r30, 0xc(r26);
  addi r31, r3, 1;
  cmpwi r30, 0;
  beq lbl_8015c8a8;
  b lbl_8015c928;
lbl_8015c8a8:
  lwz r30, 4(r26);
  b lbl_8015c928;
lbl_8015c8b0:
  stw r30, 0x10(r26);
  lwz r0, 0x18(r30);
  cmpwi r0, 0;
  beq lbl_8015c8f4;
  mr r3, r30;
  addi r4, r1, 0xc;
  addi r5, r1, 8;
  bl lbl_8015c868;
  lwz r0, 0xc(r1);
  mr r26, r3;
  stw r0, 0x20(r30);
  lwz r3, 0xc(r1);
  lwz r0, 8(r1);
  lwz r30, 0(r30);
  add r29, r29, r3;
  add r31, r31, r0;
  b lbl_8015c928;
lbl_8015c8f4:
  lwz r3, 0x14(r30);
  mr r26, r30;
  addi r29, r29, 1;
  bl strlen;
  lwz r0, 0(r30);
  add r3, r3, r31;
  addi r31, r3, 1;
  cmpwi r0, 0;
  beq lbl_8015c920;
  mr r30, r0;
  b lbl_8015c928;
lbl_8015c920:
  lwz r3, 8(r30);
  lwz r30, 4(r3);
lbl_8015c928:
  cmpwi r30, 0;
  bne lbl_8015c8b0;
  stw r29, 0(r27);
  addi r11, r1, 0x30;
  mr r3, r26;
  stw r31, 0(r28);
  bl _restgpr_26;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: darch_GetFileChar
// PAL: 0x8015c954..0x8015cb18
MARK_BINARY_BLOB(darch_GetFileChar, 0x8015c954, 0x8015cb18);
asm UNKNOWN_FUNCTION(darch_GetFileChar) {
  // clang-format off
  nofralloc;
  stwu r1, -0x260(r1);
  mflr r0;
  stw r0, 0x264(r1);
  addi r11, r1, 0x260;
  bl _savegpr_14;
  mr r16, r5;
  mr r15, r3;
  mr r14, r4;
  mr r17, r6;
  mr r26, r16;
  addi r28, r1, 0x10c;
  addi r30, r1, 8;
  li r22, 1;
  li r21, 1;
  li r24, 0;
  li r31, 0;
  b lbl_8015caec;
lbl_8015c998:
  lwz r19, 0(r26);
  mr r3, r19;
  bl strlen;
  cmplwi r3, 0x104;
  blt lbl_8015c9c8;
  lis r3, 0x8028;
  mr r4, r24;
  addi r3, r3, 0x7fe8;
  crclr 6;
  bl OSReport;
  li r3, 0;
  b lbl_8015cb00;
lbl_8015c9c8:
  mr r3, r19;
  bl strlen;
  cmpwi r3, 0;
  bne lbl_8015c9f4;
  lis r3, 0x8029;
  mr r4, r24;
  addi r3, r3, -32760;
  crclr 6;
  bl OSReport;
  li r3, 0;
  b lbl_8015cb00;
lbl_8015c9f4:
  mr r20, r19;
  b lbl_8015cac4;
lbl_8015c9fc:
  extsb r0, r3;
  cmpwi r0, 0x2f;
  bne lbl_8015ca0c;
  addi r20, r20, 1;
lbl_8015ca0c:
  lbz r0, 0(r20);
  extsb. r0, r0;
  bne lbl_8015ca20;
  li r27, -1;
  b lbl_8015ca48;
lbl_8015ca20:
  mr r3, r20;
  b lbl_8015ca2c;
lbl_8015ca28:
  addi r3, r3, 1;
lbl_8015ca2c:
  lbz r0, 0(r3);
  extsb r0, r0;
  cmpwi r0, 0x2f;
  beq lbl_8015ca44;
  cmpwi r0, 0;
  bne lbl_8015ca28;
lbl_8015ca44:
  subf r27, r20, r3;
lbl_8015ca48:
  mr r4, r19;
  addi r3, r1, 0x10c;
  bl strcpy;
  subf r0, r19, r20;
  mr r25, r16;
  add r29, r27, r0;
  li r18, 1;
  stbx r31, r28, r29;
  li r23, 0;
  b lbl_8015caa4;
lbl_8015ca70:
  lwz r4, 0(r25);
  addi r3, r1, 8;
  bl strcpy;
  stbx r31, r30, r29;
  addi r3, r1, 0x10c;
  addi r4, r1, 8;
  bl strcmp;
  cmpwi r3, 0;
  bne lbl_8015ca9c;
  li r18, 0;
  b lbl_8015caac;
lbl_8015ca9c:
  addi r25, r25, 0xc;
  addi r23, r23, 1;
lbl_8015caa4:
  cmpw r23, r24;
  blt lbl_8015ca70;
lbl_8015caac:
  cmpwi r18, 0;
  beq lbl_8015cac0;
  add r3, r27, r22;
  addi r21, r21, 1;
  addi r22, r3, 1;
lbl_8015cac0:
  add r20, r20, r27;
lbl_8015cac4:
  lbz r3, 0(r20);
  extsb. r0, r3;
  beq lbl_8015cae4;
  cmpwi r0, 0x2f;
  bne lbl_8015c9fc;
  lbz r0, 1(r20);
  extsb. r0, r0;
  bne lbl_8015c9fc;
lbl_8015cae4:
  addi r26, r26, 0xc;
  addi r24, r24, 1;
lbl_8015caec:
  cmplw r24, r17;
  blt lbl_8015c998;
  stw r22, 0(r15);
  li r3, 1;
  stw r21, 0(r14);
lbl_8015cb00:
  addi r11, r1, 0x260;
  bl _restgpr_14;
  lwz r0, 0x264(r1);
  mtlr r0;
  addi r1, r1, 0x260;
  blr;
  // clang-format on
}

// Symbol: darch_CreateDirStructure
// PAL: 0x8015cb18..0x8015ce0c
MARK_BINARY_BLOB(darch_CreateDirStructure, 0x8015cb18, 0x8015ce0c);
asm UNKNOWN_FUNCTION(darch_CreateDirStructure) {
  // clang-format off
  nofralloc;
  stwu r1, -0x50(r1);
  mflr r0;
  stw r0, 0x54(r1);
  addi r11, r1, 0x50;
  bl _savegpr_17;
  addi r8, r5, -1;
  mr r17, r3;
  cmplwi r8, 0;
  mr r18, r5;
  mr r10, r4;
  li r24, 0;
  ble lbl_8015cc00;
  rlwinm. r0, r8, 0x1d, 3, 0x1f;
  mtctr r0;
  beq lbl_8015cbe4;
lbl_8015cb54:
  lwz r9, 8(r10);
  addi r3, r9, 0x1f;
  lwz r9, 0x14(r10);
  rlwinm r0, r3, 0, 0, 0x1a;
  addi r3, r9, 0x1f;
  lwz r9, 0x20(r10);
  add r24, r24, r0;
  rlwinm r0, r3, 0, 0, 0x1a;
  addi r3, r9, 0x1f;
  lwz r9, 0x2c(r10);
  add r24, r24, r0;
  rlwinm r0, r3, 0, 0, 0x1a;
  addi r3, r9, 0x1f;
  lwz r9, 0x38(r10);
  add r24, r24, r0;
  rlwinm r0, r3, 0, 0, 0x1a;
  addi r3, r9, 0x1f;
  add r24, r24, r0;
  lwz r9, 0x44(r10);
  rlwinm r0, r3, 0, 0, 0x1a;
  addi r3, r9, 0x1f;
  lwz r9, 0x50(r10);
  add r24, r24, r0;
  rlwinm r0, r3, 0, 0, 0x1a;
  addi r3, r9, 0x1f;
  lwz r9, 0x5c(r10);
  add r24, r24, r0;
  rlwinm r0, r3, 0, 0, 0x1a;
  addi r10, r10, 0x60;
  addi r3, r9, 0x1f;
  add r24, r24, r0;
  rlwinm r0, r3, 0, 0, 0x1a;
  add r24, r24, r0;
  bdnz lbl_8015cb54;
  andi. r8, r8, 7;
  beq lbl_8015cc00;
lbl_8015cbe4:
  mtctr r8;
lbl_8015cbe8:
  lwz r9, 8(r10);
  addi r10, r10, 0xc;
  addi r3, r9, 0x1f;
  rlwinm r0, r3, 0, 0, 0x1a;
  add r24, r24, r0;
  bdnz lbl_8015cbe8;
lbl_8015cc00:
  mulli r0, r5, 0xc;
  mr r27, r4;
  add r22, r6, r7;
  addi r29, r1, 8;
  add r3, r4, r0;
  li r26, 0;
  lwz r0, -4(r3);
  li r30, 1;
  li r31, 0;
  add r24, r24, r0;
  b lbl_8015cde8;
lbl_8015cc2c:
  lwz r3, unk_803865f8;
  addi r0, r3, 0x24;
  cmplw r0, r24;
  stw r0, unk_803865f8;
  subf r21, r0, r22;
  blt lbl_8015cc48;
  li r21, 0;
lbl_8015cc48:
  cmpwi r21, 0;
  bne lbl_8015cc58;
  li r3, 0;
  b lbl_8015cdf4;
lbl_8015cc58:
  stb r31, 8(r1);
  mr r20, r21;
  lwz r23, 0(r27);
  stw r31, 0(r21);
  stw r31, 4(r21);
  stw r21, 8(r21);
  stw r29, 0x14(r21);
  stw r31, 0xc(r21);
  stw r30, 0x18(r21);
  stw r31, 0x1c(r21);
  b lbl_8015cd90;
lbl_8015cc84:
  lwz r3, unk_803865f8;
  addi r0, r3, 0x24;
  cmplw r0, r24;
  stw r0, unk_803865f8;
  subf r19, r0, r22;
  blt lbl_8015cca0;
  li r19, 0;
lbl_8015cca0:
  cmpwi r19, 0;
  bne lbl_8015ccb0;
  li r3, 0;
  b lbl_8015cdf4;
lbl_8015ccb0:
  lbz r0, 0(r23);
  cmpwi r0, 0x2f;
  bne lbl_8015ccc0;
  addi r23, r23, 1;
lbl_8015ccc0:
  lbz r0, 0(r23);
  extsb. r0, r0;
  bne lbl_8015ccd4;
  li r28, -1;
  b lbl_8015ccfc;
lbl_8015ccd4:
  mr r3, r23;
  b lbl_8015cce0;
lbl_8015ccdc:
  addi r3, r3, 1;
lbl_8015cce0:
  lbz r0, 0(r3);
  extsb r0, r0;
  cmpwi r0, 0x2f;
  beq lbl_8015ccf8;
  cmpwi r0, 0;
  bne lbl_8015ccdc;
lbl_8015ccf8:
  subf r28, r23, r3;
lbl_8015ccfc:
  lwz r3, 0(r27);
  bl strlen;
  lwz r0, unk_803865f8;
  addi r3, r3, 1;
  add r0, r0, r3;
  cmplw r0, r24;
  stw r0, unk_803865f8;
  subf r0, r0, r22;
  blt lbl_8015cd24;
  li r0, 0;
lbl_8015cd24:
  cmpwi r0, 0;
  stw r0, 0x14(r19);
  bne lbl_8015cd38;
  li r3, 0;
  b lbl_8015cdf4;
lbl_8015cd38:
  stw r30, 0x18(r19);
  lwz r4, 0(r27);
  stw r31, 0(r19);
  subf r25, r4, r23;
  stw r31, 4(r19);
  stw r20, 8(r19);
  stw r31, 0xc(r19);
  lwz r3, 0x14(r19);
  bl strcpy;
  cmpwi r3, 0;
  bne lbl_8015cd6c;
  li r3, 0;
  b lbl_8015cdf4;
lbl_8015cd6c:
  lwz r3, 0x14(r19);
  add r0, r28, r25;
  add r23, r23, r28;
  stbx r31, r3, r0;
  lwz r0, 0x14(r19);
  add r0, r0, r25;
  stw r0, 0x14(r19);
  stw r19, 4(r20);
  mr r20, r19;
lbl_8015cd90:
  lbz r0, 0(r23);
  extsb. r0, r0;
  beq lbl_8015cdb0;
  cmpwi r0, 0x2f;
  bne lbl_8015cc84;
  lbz r0, 1(r23);
  extsb. r0, r0;
  bne lbl_8015cc84;
lbl_8015cdb0:
  lwz r5, 8(r20);
  mr r3, r17;
  mr r4, r21;
  stw r31, 4(r5);
  lwz r5, 8(r20);
  stw r20, 0xc(r5);
  stw r31, 0x18(r20);
  bl darch_MergeDirStructure;
  cmpwi r3, 0;
  bne lbl_8015cde0;
  li r3, 0;
  b lbl_8015cdf4;
lbl_8015cde0:
  addi r27, r27, 0xc;
  addi r26, r26, 1;
lbl_8015cde8:
  cmplw r26, r18;
  blt lbl_8015cc2c;
  li r3, 1;
lbl_8015cdf4:
  addi r11, r1, 0x50;
  bl _restgpr_17;
  lwz r0, 0x54(r1);
  mtlr r0;
  addi r1, r1, 0x50;
  blr;
  // clang-format on
}

// Symbol: darch_ConstructFSTFromStructure
// PAL: 0x8015ce0c..0x8015d0fc
MARK_BINARY_BLOB(darch_ConstructFSTFromStructure, 0x8015ce0c, 0x8015d0fc);
asm UNKNOWN_FUNCTION(darch_ConstructFSTFromStructure) {
  // clang-format off
  nofralloc;
  stwu r1, -0x70(r1);
  mflr r0;
  stw r0, 0x74(r1);
  addi r11, r1, 0x70;
  bl _savegpr_19;
  li r0, 0;
  mr r20, r4;
  stb r0, 8(r1);
  addi r0, r1, 8;
  mr r21, r5;
  mr r19, r3;
  stw r0, 0x14(r3);
  mr r22, r6;
  addi r4, r1, 0xc;
  addi r5, r1, 0x10;
  bl darch_DecideOrderInFst;
  lwz r0, 0xc(r1);
  addi r23, r21, 0x20;
  mr r31, r20;
  li r29, 0;
  stw r0, 0x20(r19);
  li r30, 0;
  lwz r3, 0xc(r1);
  lwz r0, 0x10(r1);
  mulli r3, r3, 0xc;
  add r27, r0, r3;
  addi r0, r27, 0x3f;
  add r25, r23, r3;
  rlwinm r28, r0, 0, 0, 0x1a;
  mr r24, r25;
  mr r26, r28;
  b lbl_8015cfb4;
lbl_8015ce8c:
  stw r30, 0x1c(r19);
  subf r6, r25, r24;
  rlwinm r4, r6, 0x10, 0x18, 0x1f;
  mr r3, r24;
  lwz r5, 0x18(r19);
  rlwinm r0, r6, 0x18, 0x18, 0x1f;
  stb r5, 0(r23);
  stb r4, 1(r23);
  stb r0, 2(r23);
  stb r6, 3(r23);
  lwz r4, 0x14(r19);
  bl strcpy;
  lwz r3, 0x14(r19);
  bl strlen;
  lwz r0, 0x18(r19);
  add r3, r3, r24;
  addi r24, r3, 1;
  cmpwi r0, 0;
  beq lbl_8015cf54;
  lwz r3, 8(r19);
  lwz r0, 0x1c(r3);
  srwi r0, r0, 0x18;
  stb r0, 4(r23);
  lwz r3, 8(r19);
  lwz r0, 0x1c(r3);
  rlwinm r0, r0, 0x10, 0x18, 0x1f;
  stb r0, 5(r23);
  lwz r3, 8(r19);
  lwz r0, 0x1c(r3);
  rlwinm r0, r0, 0x18, 0x18, 0x1f;
  stb r0, 6(r23);
  lwz r3, 8(r19);
  lwz r0, 0x1c(r3);
  stb r0, 7(r23);
  lwz r0, 0x20(r19);
  add r0, r30, r0;
  srwi r0, r0, 0x18;
  stb r0, 8(r23);
  lwz r0, 0x20(r19);
  add r0, r30, r0;
  rlwinm r0, r0, 0x10, 0x18, 0x1f;
  stb r0, 9(r23);
  lwz r0, 0x20(r19);
  add r0, r30, r0;
  rlwinm r0, r0, 0x18, 0x18, 0x1f;
  stb r0, 0xa(r23);
  lwz r0, 0x20(r19);
  add r0, r30, r0;
  stb r0, 0xb(r23);
  b lbl_8015cfa8;
lbl_8015cf54:
  srwi r0, r26, 0x18;
  lwz r4, 8(r31);
  stb r0, 4(r23);
  rlwinm r5, r26, 0x10, 0x18, 0x1f;
  addi r0, r4, 0x1f;
  lwz r3, 8(r31);
  stb r5, 5(r23);
  rlwinm r7, r26, 0x18, 0x18, 0x1f;
  srwi r6, r4, 0x18;
  rlwinm r5, r4, 0x10, 0x18, 0x1f;
  stb r7, 6(r23);
  rlwinm r4, r4, 0x18, 0x18, 0x1f;
  rlwinm r0, r0, 0, 0, 0x1a;
  addi r31, r31, 0xc;
  stb r26, 7(r23);
  add r26, r26, r0;
  addi r29, r29, 1;
  stb r6, 8(r23);
  stb r5, 9(r23);
  stb r4, 0xa(r23);
  stb r3, 0xb(r23);
lbl_8015cfa8:
  lwz r19, 0x10(r19);
  addi r30, r30, 1;
  addi r23, r23, 0xc;
lbl_8015cfb4:
  lwz r0, 0xc(r1);
  cmpw r30, r0;
  blt lbl_8015ce8c;
  subf. r6, r28, r22;
  add r7, r21, r22;
  li r5, 0;
  mr r3, r6;
  beq lbl_8015d060;
  rlwinm. r0, r6, 0x1d, 3, 0x1f;
  mtctr r0;
  beq lbl_8015d04c;
lbl_8015cfe0:
  subf r4, r6, r7;
  addi r6, r6, -1;
  stb r5, 0(r4);
  subf r4, r6, r7;
  addi r6, r6, -1;
  stb r5, 0(r4);
  subf r4, r6, r7;
  addi r6, r6, -1;
  stb r5, 0(r4);
  subf r4, r6, r7;
  addi r6, r6, -1;
  stb r5, 0(r4);
  subf r4, r6, r7;
  addi r6, r6, -1;
  stb r5, 0(r4);
  subf r4, r6, r7;
  addi r6, r6, -1;
  stb r5, 0(r4);
  subf r4, r6, r7;
  addi r6, r6, -1;
  stb r5, 0(r4);
  subf r4, r6, r7;
  addi r6, r6, -1;
  stb r5, 0(r4);
  bdnz lbl_8015cfe0;
  andi. r3, r3, 7;
  beq lbl_8015d060;
lbl_8015d04c:
  mtctr r3;
lbl_8015d050:
  subf r4, r6, r7;
  addi r6, r6, -1;
  stb r5, 0(r4);
  bdnz lbl_8015d050;
lbl_8015d060:
  mr r19, r28;
  li r22, 0;
  b lbl_8015d094;
lbl_8015d06c:
  lwz r4, 4(r20);
  add r3, r21, r19;
  lwz r5, 8(r20);
  bl memcpy;
  lwz r3, 8(r20);
  addi r20, r20, 0xc;
  addi r22, r22, 1;
  addi r0, r3, 0x1f;
  rlwinm r0, r0, 0, 0, 0x1a;
  add r19, r19, r0;
lbl_8015d094:
  cmpw r22, r29;
  blt lbl_8015d06c;
  lis r3, 0x55aa;
  li r19, 0;
  addi r3, r3, 0x382d;
  li r0, 0x20;
  stw r3, 0x18(r1);
  mr r3, r21;
  addi r4, r1, 0x18;
  li r5, 0x20;
  stw r0, 0x1c(r1);
  stw r27, 0x20(r1);
  stw r28, 0x24(r1);
  stw r19, 0x28(r1);
  stw r19, 0x2c(r1);
  stw r19, 0x30(r1);
  stw r19, 0x34(r1);
  bl memcpy;
  stw r19, unk_803865f8;
  addi r11, r1, 0x70;
  li r3, 1;
  bl _restgpr_19;
  lwz r0, 0x74(r1);
  mtlr r0;
  addi r1, r1, 0x70;
  blr;
  // clang-format on
}

// Symbol: DARCHGetArcSize
// PAL: 0x8015d0fc..0x8015d254
MARK_BINARY_BLOB(DARCHGetArcSize, 0x8015d0fc, 0x8015d254);
asm UNKNOWN_FUNCTION(DARCHGetArcSize) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r4;
  mr r6, r31;
  addi r4, r1, 8;
  stw r30, 0x18(r1);
  mr r30, r3;
  mr r5, r30;
  addi r3, r1, 0xc;
  bl darch_GetFileChar;
  cmpwi r3, 0;
  bne lbl_8015d14c;
  lis r3, 0x8029;
  addi r3, r3, -32732;
  crclr 6;
  bl OSReport;
  li r3, 0;
  b lbl_8015d23c;
lbl_8015d14c:
  lwz r0, 8(r1);
  addi r3, r31, -1;
  lwz r4, 0xc(r1);
  cmplwi r3, 0;
  mulli r0, r0, 0xc;
  mr r6, r30;
  add r4, r4, r0;
  addi r0, r4, 0x3f;
  rlwinm r7, r0, 0, 0, 0x1a;
  ble lbl_8015d22c;
  rlwinm. r0, r3, 0x1d, 3, 0x1f;
  mtctr r0;
  beq lbl_8015d210;
lbl_8015d180:
  lwz r5, 8(r6);
  addi r4, r5, 0x1f;
  lwz r5, 0x14(r6);
  rlwinm r0, r4, 0, 0, 0x1a;
  addi r4, r5, 0x1f;
  lwz r5, 0x20(r6);
  add r7, r7, r0;
  rlwinm r0, r4, 0, 0, 0x1a;
  addi r4, r5, 0x1f;
  lwz r5, 0x2c(r6);
  add r7, r7, r0;
  rlwinm r0, r4, 0, 0, 0x1a;
  addi r4, r5, 0x1f;
  lwz r5, 0x38(r6);
  add r7, r7, r0;
  rlwinm r0, r4, 0, 0, 0x1a;
  addi r4, r5, 0x1f;
  add r7, r7, r0;
  lwz r5, 0x44(r6);
  rlwinm r0, r4, 0, 0, 0x1a;
  addi r4, r5, 0x1f;
  lwz r5, 0x50(r6);
  add r7, r7, r0;
  rlwinm r0, r4, 0, 0, 0x1a;
  addi r4, r5, 0x1f;
  lwz r5, 0x5c(r6);
  add r7, r7, r0;
  rlwinm r0, r4, 0, 0, 0x1a;
  addi r6, r6, 0x60;
  addi r4, r5, 0x1f;
  add r7, r7, r0;
  rlwinm r0, r4, 0, 0, 0x1a;
  add r7, r7, r0;
  bdnz lbl_8015d180;
  andi. r3, r3, 7;
  beq lbl_8015d22c;
lbl_8015d210:
  mtctr r3;
lbl_8015d214:
  lwz r5, 8(r6);
  addi r6, r6, 0xc;
  addi r4, r5, 0x1f;
  rlwinm r0, r4, 0, 0, 0x1a;
  add r7, r7, r0;
  bdnz lbl_8015d214;
lbl_8015d22c:
  mulli r0, r31, 0xc;
  add r3, r30, r0;
  lwz r0, -4(r3);
  add r3, r7, r0;
lbl_8015d23c:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: DARCHCreate
// PAL: 0x8015d254..0x8015d314
MARK_BINARY_BLOB(DARCHCreate, 0x8015d254, 0x8015d314);
asm UNKNOWN_FUNCTION(DARCHCreate) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  mflr r0;
  li r9, 0;
  stw r0, 0x44(r1);
  addi r8, r1, 8;
  li r0, 1;
  stw r31, 0x3c(r1);
  addi r31, r1, 0xc;
  stw r30, 0x38(r1);
  mr r30, r5;
  mr r5, r6;
  stw r29, 0x34(r1);
  mr r29, r4;
  mr r4, r30;
  stw r28, 0x30(r1);
  mr r28, r3;
  mr r3, r31;
  mr r7, r29;
  stb r9, 8(r1);
  mr r6, r28;
  stw r9, 0xc(r1);
  stw r9, 0x10(r1);
  stw r31, 0x14(r1);
  stw r8, 0x20(r1);
  stw r9, 0x18(r1);
  stw r0, 0x24(r1);
  stw r9, 0x28(r1);
  bl darch_CreateDirStructure;
  cmpwi r3, 0;
  bne lbl_8015d2d4;
  li r3, 0;
  b lbl_8015d2f4;
lbl_8015d2d4:
  mr r3, r31;
  mr r4, r30;
  mr r5, r28;
  mr r6, r29;
  bl darch_ConstructFSTFromStructure;
  neg r0, r3;
  or r0, r0, r3;
  srwi r3, r0, 0x1f;
lbl_8015d2f4:
  lwz r0, 0x44(r1);
  lwz r31, 0x3c(r1);
  lwz r30, 0x38(r1);
  lwz r29, 0x34(r1);
  lwz r28, 0x30(r1);
  mtlr r0;
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}
