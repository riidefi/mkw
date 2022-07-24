#include "dvdFs.h"

#include <rvl/os/osError.h>
#include <rvl/os/osInterrupt.h>
#include <rvl/os/osThread.h>

#include "dvdMain.h"

// Symbol: __DVDFSInit
// PAL: 0x8015df1c..0x8015df4c
MARK_BINARY_BLOB(__DVDFSInit, 0x8015df1c, 0x8015df4c);
asm UNKNOWN_FUNCTION(__DVDFSInit) {
  // clang-format off
  nofralloc;
  lis r3, 0x8000;
  stw r3, -0x65bc(r13);
  lwz r4, 0x38(r3);
  cmpwi r4, 0;
  stw r4, -0x65c0(r13);
  beqlr;
  lwz r3, 8(r4);
  mulli r0, r3, 0xc;
  stw r3, -0x65c8(r13);
  add r0, r4, r0;
  stw r0, -0x65c4(r13);
  blr;
  // clang-format on
}

// Symbol: DVDConvertPathToEntrynum
// PAL: 0x8015df4c..0x8015e254
MARK_BINARY_BLOB(DVDConvertPathToEntrynum, 0x8015df4c, 0x8015e254);
asm UNKNOWN_FUNCTION(DVDConvertPathToEntrynum) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_24;
  mr r26, r3;
  lis r31, 0x8027;
  lwz r29, -0x65d8(r13);
  mr r28, r26;
  addi r31, r31, 0x1148;
  lis r30, 0x8029;
lbl_8015df78:
  lbz r0, 0(r26);
  extsb. r0, r0;
  bne lbl_8015df8c;
  mr r3, r29;
  b lbl_8015e23c;
lbl_8015df8c:
  cmpwi r0, 0x2f;
  bne lbl_8015dfa0;
  li r29, 0;
  addi r26, r26, 1;
  b lbl_8015df78;
lbl_8015dfa0:
  cmpwi r0, 0x2e;
  bne lbl_8015e01c;
  lbz r0, 1(r26);
  extsb r0, r0;
  cmpwi r0, 0x2e;
  bne lbl_8015dffc;
  lbz r0, 2(r26);
  extsb r0, r0;
  cmpwi r0, 0x2f;
  bne lbl_8015dfe0;
  mulli r0, r29, 0xc;
  lwz r3, -0x65c0(r13);
  addi r26, r26, 3;
  add r3, r3, r0;
  lwz r29, 4(r3);
  b lbl_8015df78;
lbl_8015dfe0:
  cmpwi r0, 0;
  bne lbl_8015e01c;
  mulli r0, r29, 0xc;
  lwz r3, -0x65c0(r13);
  add r3, r3, r0;
  lwz r3, 4(r3);
  b lbl_8015e23c;
lbl_8015dffc:
  cmpwi r0, 0x2f;
  bne lbl_8015e00c;
  addi r26, r26, 2;
  b lbl_8015df78;
lbl_8015e00c:
  cmpwi r0, 0;
  bne lbl_8015e01c;
  mr r3, r29;
  b lbl_8015e23c;
lbl_8015e01c:
  lwz r0, -0x7348(r13);
  cmpwi r0, 0;
  bne lbl_8015e0cc;
  mr r24, r26;
  li r5, 0;
  li r4, 0;
  b lbl_8015e07c;
lbl_8015e038:
  extsb r0, r3;
  cmpwi r0, 0x2e;
  bne lbl_8015e06c;
  subf r0, r26, r24;
  cmpwi r0, 8;
  bgt lbl_8015e058;
  cmpwi r5, 1;
  bne lbl_8015e060;
lbl_8015e058:
  li r4, 1;
  b lbl_8015e090;
lbl_8015e060:
  addi r27, r24, 1;
  li r5, 1;
  b lbl_8015e078;
lbl_8015e06c:
  cmpwi r0, 0x20;
  bne lbl_8015e078;
  li r4, 1;
lbl_8015e078:
  addi r24, r24, 1;
lbl_8015e07c:
  lbz r3, 0(r24);
  extsb. r0, r3;
  beq lbl_8015e090;
  cmpwi r0, 0x2f;
  bne lbl_8015e038;
lbl_8015e090:
  cmpwi r5, 1;
  bne lbl_8015e0a8;
  subf r0, r27, r24;
  cmpwi r0, 3;
  ble lbl_8015e0a8;
  li r4, 1;
lbl_8015e0a8:
  cmpwi r4, 0;
  beq lbl_8015e0ec;
  mr r6, r28;
  addi r5, r30, -32224;
  addi r3, r13, -29504;
  li r4, 0x1bb;
  crclr 6;
  bl OSPanic;
  b lbl_8015e0ec;
lbl_8015e0cc:
  mr r24, r26;
  b lbl_8015e0d8;
lbl_8015e0d4:
  addi r24, r24, 1;
lbl_8015e0d8:
  lbz r0, 0(r24);
  extsb. r0, r0;
  beq lbl_8015e0ec;
  cmpwi r0, 0x2f;
  bne lbl_8015e0d4;
lbl_8015e0ec:
  lbz r3, 0(r24);
  mulli r0, r29, 0xc;
  lwz r8, -0x65c0(r13);
  subf r9, r26, r24;
  extsb r6, r3;
  lwz r4, -0x65c4(r13);
  neg r5, r6;
  add r3, r8, r0;
  lwz r12, 0x38(r31);
  or r0, r5, r6;
  lwz r5, 8(r3);
  srwi r0, r0, 0x1f;
  addi r3, r29, 1;
  b lbl_8015e210;
lbl_8015e124:
  mulli r6, r3, 0xc;
  lwzux r10, r6, r8;
  rlwinm. r7, r10, 0, 0, 7;
  bne lbl_8015e13c;
  cmpwi r0, 1;
  beq lbl_8015e1fc;
lbl_8015e13c:
  clrlwi r10, r10, 8;
  mr r29, r26;
  add r25, r4, r10;
  b lbl_8015e1c4;
lbl_8015e14c:
  lbz r11, 0(r25);
  li r10, 0;
  addi r25, r25, 1;
  extsb. r24, r11;
  blt lbl_8015e168;
  cmpwi r24, 0x100;
  blt lbl_8015e16c;
lbl_8015e168:
  li r10, 1;
lbl_8015e16c:
  cmpwi r10, 0;
  beq lbl_8015e178;
  b lbl_8015e180;
lbl_8015e178:
  lwz r10, 0x10(r12);
  lbzx r24, r10, r24;
lbl_8015e180:
  lbz r11, 0(r29);
  li r10, 0;
  addi r29, r29, 1;
  extsb. r11, r11;
  blt lbl_8015e19c;
  cmpwi r11, 0x100;
  blt lbl_8015e1a0;
lbl_8015e19c:
  li r10, 1;
lbl_8015e1a0:
  cmpwi r10, 0;
  beq lbl_8015e1ac;
  b lbl_8015e1b4;
lbl_8015e1ac:
  lwz r10, 0x10(r12);
  lbzx r11, r10, r11;
lbl_8015e1b4:
  cmpw r11, r24;
  beq lbl_8015e1c4;
  li r10, 0;
  b lbl_8015e1f4;
lbl_8015e1c4:
  lbz r10, 0(r25);
  extsb. r10, r10;
  bne lbl_8015e14c;
  lbz r10, 0(r29);
  extsb r10, r10;
  cmpwi r10, 0x2f;
  beq lbl_8015e1e8;
  cmpwi r10, 0;
  bne lbl_8015e1f0;
lbl_8015e1e8:
  li r10, 1;
  b lbl_8015e1f4;
lbl_8015e1f0:
  li r10, 0;
lbl_8015e1f4:
  cmpwi r10, 1;
  beq lbl_8015e220;
lbl_8015e1fc:
  cmpwi r7, 0;
  beq lbl_8015e20c;
  lwz r3, 8(r6);
  b lbl_8015e210;
lbl_8015e20c:
  addi r3, r3, 1;
lbl_8015e210:
  cmplw r3, r5;
  blt lbl_8015e124;
  li r3, -1;
  b lbl_8015e23c;
lbl_8015e220:
  cmpwi r0, 0;
  bne lbl_8015e22c;
  b lbl_8015e23c;
lbl_8015e22c:
  add r4, r9, r26;
  mr r29, r3;
  addi r26, r4, 1;
  b lbl_8015df78;
lbl_8015e23c:
  addi r11, r1, 0x30;
  bl _restgpr_24;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: DVDFastOpen
// PAL: 0x8015e254..0x8015e2bc
MARK_BINARY_BLOB(DVDFastOpen, 0x8015e254, 0x8015e2bc);
asm UNKNOWN_FUNCTION(DVDFastOpen) {
  // clang-format off
  nofralloc;
  cmpwi r3, 0;
  blt lbl_8015e27c;
  lwz r0, -0x65c8(r13);
  cmplw r3, r0;
  bge lbl_8015e27c;
  mulli r7, r3, 0xc;
  lwz r3, -0x65c0(r13);
  lwzx r0, r3, r7;
  rlwinm. r0, r0, 0, 0, 7;
  beq lbl_8015e284;
lbl_8015e27c:
  li r3, 0;
  blr;
lbl_8015e284:
  add r3, r3, r7;
  lwz r5, -0x6564(r13);
  lwz r6, 4(r3);
  li r0, 0;
  li r3, 1;
  srw r5, r6, r5;
  stw r5, 0x30(r4);
  lwz r5, -0x65c0(r13);
  add r5, r5, r7;
  lwz r5, 8(r5);
  stw r5, 0x34(r4);
  stw r0, 0x38(r4);
  stw r0, 0xc(r4);
  blr;
  // clang-format on
}

// Symbol: DVDOpen
// PAL: 0x8015e2bc..0x8015e568
MARK_BINARY_BLOB(DVDOpen, 0x8015e2bc, 0x8015e568);
asm UNKNOWN_FUNCTION(DVDOpen) {
  // clang-format off
  nofralloc;
  stwu r1, -0xa0(r1);
  mflr r0;
  stw r0, 0xa4(r1);
  addi r11, r1, 0xa0;
  bl _savegpr_27;
  mr r28, r3;
  mr r27, r4;
  bl DVDConvertPathToEntrynum;
  cmpwi r3, 0;
  bge lbl_8015e500;
  lwz r29, -0x65d8(r13);
  cmpwi r29, 0;
  bne lbl_8015e2f8;
  li r4, 0;
  b lbl_8015e484;
lbl_8015e2f8:
  lwz r8, -0x65c0(r13);
  mulli r0, r29, 0xc;
  lwz r7, -0x65c4(r13);
  addi r6, r8, 4;
  lwzx r3, r6, r0;
  lwzx r0, r8, r0;
  cmpwi r3, 0;
  clrlwi r0, r0, 8;
  add r30, r7, r0;
  bne lbl_8015e328;
  li r4, 0;
  b lbl_8015e428;
lbl_8015e328:
  mulli r0, r3, 0xc;
  lwzx r3, r6, r0;
  lwzx r0, r8, r0;
  cmpwi r3, 0;
  clrlwi r0, r0, 8;
  add r31, r7, r0;
  bne lbl_8015e34c;
  li r4, 0;
  b lbl_8015e3cc;
lbl_8015e34c:
  mulli r3, r3, 0xc;
  addi r4, r1, 8;
  li r5, 0x80;
  lwzx r0, r8, r3;
  lwzx r3, r6, r3;
  clrlwi r0, r0, 8;
  add r27, r7, r0;
  bl dvd_entryToPath_0;
  cmplwi r3, 0x80;
  mr r4, r3;
  bne lbl_8015e37c;
  b lbl_8015e3cc;
lbl_8015e37c:
  addi r4, r3, 1;
  addi r5, r1, 8;
  li r0, 0x2f;
  stbx r0, r5, r3;
  subfic r6, r4, 0x80;
  mr r3, r6;
  add r5, r5, r4;
  b lbl_8015e3b0;
lbl_8015e39c:
  lbz r0, 0(r27);
  addi r3, r3, -1;
  addi r27, r27, 1;
  stb r0, 0(r5);
  addi r5, r5, 1;
lbl_8015e3b0:
  cmpwi r3, 0;
  beq lbl_8015e3c4;
  lbz r0, 0(r27);
  extsb. r0, r0;
  bne lbl_8015e39c;
lbl_8015e3c4:
  subf r0, r3, r6;
  add r4, r4, r0;
lbl_8015e3cc:
  cmplwi r4, 0x80;
  bne lbl_8015e3d8;
  b lbl_8015e428;
lbl_8015e3d8:
  addi r5, r4, 1;
  addi r3, r1, 8;
  li r0, 0x2f;
  stbx r0, r3, r4;
  subfic r6, r5, 0x80;
  mr r4, r6;
  add r3, r3, r5;
  b lbl_8015e40c;
lbl_8015e3f8:
  lbz r0, 0(r31);
  addi r4, r4, -1;
  addi r31, r31, 1;
  stb r0, 0(r3);
  addi r3, r3, 1;
lbl_8015e40c:
  cmpwi r4, 0;
  beq lbl_8015e420;
  lbz r0, 0(r31);
  extsb. r0, r0;
  bne lbl_8015e3f8;
lbl_8015e420:
  subf r0, r4, r6;
  add r4, r5, r0;
lbl_8015e428:
  cmplwi r4, 0x80;
  bne lbl_8015e434;
  b lbl_8015e484;
lbl_8015e434:
  addi r5, r4, 1;
  addi r3, r1, 8;
  li r0, 0x2f;
  stbx r0, r3, r4;
  subfic r6, r5, 0x80;
  mr r4, r6;
  add r3, r3, r5;
  b lbl_8015e468;
lbl_8015e454:
  lbz r0, 0(r30);
  addi r4, r4, -1;
  addi r30, r30, 1;
  stb r0, 0(r3);
  addi r3, r3, 1;
lbl_8015e468:
  cmpwi r4, 0;
  beq lbl_8015e47c;
  lbz r0, 0(r30);
  extsb. r0, r0;
  bne lbl_8015e454;
lbl_8015e47c:
  subf r0, r4, r6;
  add r4, r5, r0;
lbl_8015e484:
  cmplwi r4, 0x80;
  bne lbl_8015e498;
  li r0, 0;
  stb r0, 0x87(r1);
  b lbl_8015e4e0;
lbl_8015e498:
  mulli r0, r29, 0xc;
  lwz r3, -0x65c0(r13);
  lwzx r0, r3, r0;
  rlwinm. r0, r0, 0, 0, 7;
  beq lbl_8015e4d4;
  cmplwi r4, 0x7f;
  bne lbl_8015e4c4;
  addi r3, r1, 8;
  li r0, 0;
  stbx r0, r3, r4;
  b lbl_8015e4e0;
lbl_8015e4c4:
  addi r3, r1, 8;
  li r0, 0x2f;
  stbx r0, r3, r4;
  addi r4, r4, 1;
lbl_8015e4d4:
  addi r3, r1, 8;
  li r0, 0;
  stbx r0, r3, r4;
lbl_8015e4e0:
  lis r3, 0x8029;
  mr r4, r28;
  addi r3, r3, -32024;
  addi r5, r1, 8;
  crclr 6;
  bl OSReport;
  li r3, 0;
  b lbl_8015e550;
lbl_8015e500:
  mulli r6, r3, 0xc;
  lwz r3, -0x65c0(r13);
  lwzx r0, r3, r6;
  rlwinm. r0, r0, 0, 0, 7;
  beq lbl_8015e51c;
  li r3, 0;
  b lbl_8015e550;
lbl_8015e51c:
  add r3, r3, r6;
  lwz r4, -0x6564(r13);
  lwz r5, 4(r3);
  li r0, 0;
  li r3, 1;
  srw r4, r5, r4;
  stw r4, 0x30(r27);
  lwz r4, -0x65c0(r13);
  add r4, r4, r6;
  lwz r4, 8(r4);
  stw r4, 0x34(r27);
  stw r0, 0x38(r27);
  stw r0, 0xc(r27);
lbl_8015e550:
  addi r11, r1, 0xa0;
  bl _restgpr_27;
  lwz r0, 0xa4(r1);
  mtlr r0;
  addi r1, r1, 0xa0;
  blr;
  // clang-format on
}

// Symbol: DVDClose
// PAL: 0x8015e568..0x8015e58c
MARK_BINARY_BLOB(DVDClose, 0x8015e568, 0x8015e58c);
asm UNKNOWN_FUNCTION(DVDClose) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  bl DVDCancel;
  lwz r0, 0x14(r1);
  li r3, 1;
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: dvd_entryToPath_0
// PAL: 0x8015e58c..0x8015e74c
MARK_BINARY_BLOB(dvd_entryToPath_0, 0x8015e58c, 0x8015e74c);
asm UNKNOWN_FUNCTION(dvd_entryToPath_0) {
  // clang-format off
  nofralloc;
lbl_8015e58c:
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  cmpwi r3, 0;
  mr r28, r4;
  mr r29, r5;
  bne lbl_8015e5b8;
  li r3, 0;
  b lbl_8015e734;
lbl_8015e5b8:
  lwz r8, -0x65c0(r13);
  mulli r0, r3, 0xc;
  lwz r7, -0x65c4(r13);
  addi r6, r8, 4;
  lwzx r3, r6, r0;
  lwzx r0, r8, r0;
  cmpwi r3, 0;
  clrlwi r0, r0, 8;
  add r30, r7, r0;
  bne lbl_8015e5e8;
  li r4, 0;
  b lbl_8015e6d8;
lbl_8015e5e8:
  mulli r0, r3, 0xc;
  lwzx r3, r6, r0;
  lwzx r0, r8, r0;
  cmpwi r3, 0;
  clrlwi r0, r0, 8;
  add r31, r7, r0;
  bne lbl_8015e60c;
  li r4, 0;
  b lbl_8015e680;
lbl_8015e60c:
  mulli r3, r3, 0xc;
  lwzx r0, r8, r3;
  lwzx r3, r6, r3;
  clrlwi r0, r0, 8;
  add r27, r7, r0;
  bl lbl_8015e58c;
  cmplw r3, r29;
  mr r4, r3;
  bne lbl_8015e634;
  b lbl_8015e680;
lbl_8015e634:
  addi r4, r3, 1;
  li r0, 0x2f;
  subf r6, r4, r29;
  stbx r0, r28, r3;
  add r3, r28, r4;
  mr r5, r6;
  b lbl_8015e664;
lbl_8015e650:
  lbz r0, 0(r27);
  addi r5, r5, -1;
  addi r27, r27, 1;
  stb r0, 0(r3);
  addi r3, r3, 1;
lbl_8015e664:
  cmpwi r5, 0;
  beq lbl_8015e678;
  lbz r0, 0(r27);
  extsb. r0, r0;
  bne lbl_8015e650;
lbl_8015e678:
  subf r0, r5, r6;
  add r4, r4, r0;
lbl_8015e680:
  cmplw r4, r29;
  bne lbl_8015e68c;
  b lbl_8015e6d8;
lbl_8015e68c:
  addi r3, r4, 1;
  li r0, 0x2f;
  subf r6, r3, r29;
  stbx r0, r28, r4;
  add r4, r28, r3;
  mr r5, r6;
  b lbl_8015e6bc;
lbl_8015e6a8:
  lbz r0, 0(r31);
  addi r5, r5, -1;
  addi r31, r31, 1;
  stb r0, 0(r4);
  addi r4, r4, 1;
lbl_8015e6bc:
  cmpwi r5, 0;
  beq lbl_8015e6d0;
  lbz r0, 0(r31);
  extsb. r0, r0;
  bne lbl_8015e6a8;
lbl_8015e6d0:
  subf r0, r5, r6;
  add r4, r3, r0;
lbl_8015e6d8:
  cmplw r4, r29;
  bne lbl_8015e6e8;
  mr r3, r4;
  b lbl_8015e734;
lbl_8015e6e8:
  addi r6, r4, 1;
  li r0, 0x2f;
  subf r5, r6, r29;
  stbx r0, r28, r4;
  add r3, r28, r6;
  mr r4, r5;
  b lbl_8015e718;
lbl_8015e704:
  lbz r0, 0(r30);
  addi r4, r4, -1;
  addi r30, r30, 1;
  stb r0, 0(r3);
  addi r3, r3, 1;
lbl_8015e718:
  cmpwi r4, 0;
  beq lbl_8015e72c;
  lbz r0, 0(r30);
  extsb. r0, r0;
  bne lbl_8015e704;
lbl_8015e72c:
  subf r0, r4, r5;
  add r3, r6, r0;
lbl_8015e734:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: DVDReadAsyncPrio
// PAL: 0x8015e74c..0x8015e834
MARK_BINARY_BLOB(DVDReadAsyncPrio, 0x8015e74c, 0x8015e834);
asm UNKNOWN_FUNCTION(DVDReadAsyncPrio) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_26;
  cmpwi r6, 0;
  mr r26, r3;
  mr r27, r4;
  mr r28, r5;
  mr r29, r6;
  mr r30, r7;
  mr r31, r8;
  blt lbl_8015e78c;
  lwz r0, 0x34(r3);
  cmplw r6, r0;
  ble lbl_8015e7a4;
lbl_8015e78c:
  lis r5, 0x8029;
  addi r3, r13, -29504;
  addi r5, r5, -31968;
  li r4, 0x337;
  crclr 6;
  bl OSPanic;
lbl_8015e7a4:
  add. r4, r29, r28;
  blt lbl_8015e7bc;
  lwz r3, 0x34(r26);
  addi r0, r3, 0x20;
  cmplw r4, r0;
  blt lbl_8015e7d4;
lbl_8015e7bc:
  lis r5, 0x8029;
  addi r3, r13, -29504;
  addi r5, r5, -31968;
  li r4, 0x33d;
  crclr 6;
  bl OSPanic;
lbl_8015e7d4:
  lwz r6, 0x30(r26);
  srawi r0, r29, 2;
  lis r7, 0x8016;
  stw r30, 0x38(r26);
  mr r3, r26;
  mr r4, r27;
  mr r5, r28;
  mr r8, r31;
  add r6, r6, r0;
  addi r7, r7, -6116;
  bl DVDReadAbsAsyncPrio;
  addi r11, r1, 0x20;
  li r3, 1;
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  lwz r12, 0x38(r4);
  cmpwi r12, 0;
  beqlr;
  mtctr r12;
  bctr;
  blr;
  // clang-format on
}

// Symbol: DVDReadPrio
// PAL: 0x8015e834..0x8015e964
MARK_BINARY_BLOB(DVDReadPrio, 0x8015e834, 0x8015e964);
asm UNKNOWN_FUNCTION(DVDReadPrio) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  cmpwi r6, 0;
  mr r27, r3;
  mr r28, r4;
  mr r29, r5;
  mr r31, r6;
  mr r30, r7;
  blt lbl_8015e870;
  lwz r0, 0x34(r3);
  cmplw r6, r0;
  ble lbl_8015e888;
lbl_8015e870:
  lis r5, 0x8029;
  addi r3, r13, -29504;
  addi r5, r5, -31916;
  li r4, 0x37d;
  crclr 6;
  bl OSPanic;
lbl_8015e888:
  add. r4, r31, r29;
  blt lbl_8015e8a0;
  lwz r3, 0x34(r27);
  addi r0, r3, 0x20;
  cmplw r4, r0;
  blt lbl_8015e8b8;
lbl_8015e8a0:
  lis r5, 0x8029;
  addi r3, r13, -29504;
  addi r5, r5, -31916;
  li r4, 0x383;
  crclr 6;
  bl OSPanic;
lbl_8015e8b8:
  lwz r6, 0x30(r27);
  srawi r0, r31, 2;
  lis r7, 0x8016;
  mr r3, r27;
  mr r4, r28;
  mr r5, r29;
  mr r8, r30;
  add r6, r6, r0;
  addi r7, r7, -5796;
  bl DVDReadAbsAsyncPrio;
  cmpwi r3, 0;
  bne lbl_8015e8f0;
  li r3, -1;
  b lbl_8015e944;
lbl_8015e8f0:
  bl OSDisableInterrupts;
  mr r31, r3;
lbl_8015e8f8:
  lwz r0, 0xc(r27);
  cmpwi r0, 0;
  bne lbl_8015e90c;
  lwz r30, 0x20(r27);
  b lbl_8015e938;
lbl_8015e90c:
  cmpwi r0, -1;
  bne lbl_8015e91c;
  li r30, -1;
  b lbl_8015e938;
lbl_8015e91c:
  cmpwi r0, 0xa;
  bne lbl_8015e92c;
  li r30, -3;
  b lbl_8015e938;
lbl_8015e92c:
  addi r3, r13, -26064;
  bl OSSleepThread;
  b lbl_8015e8f8;
lbl_8015e938:
  mr r3, r31;
  bl OSRestoreInterrupts;
  mr r3, r30;
lbl_8015e944:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  addi r3, r13, -26064;
  b OSWakeupThread;
  // clang-format on
}
