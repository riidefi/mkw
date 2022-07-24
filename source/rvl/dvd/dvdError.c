#include "dvdError.h"

#include <rvl/os/os.h>
#include <rvl/os/osCache.h>
#include <rvl/nand/nand.h>

#include "dvdBroadway.h"

// Symbol: dvd_cbForNandClose
// PAL: 0x80163818..0x80163844
MARK_BINARY_BLOB(dvd_cbForNandClose, 0x80163818, 0x80163844);
asm UNKNOWN_FUNCTION(dvd_cbForNandClose) {
  // clang-format off
  nofralloc;
  lwz r12, -0x6500(r13);
  cmpwi r12, 0;
  beqlr;
  cntlzw r0, r3;
  li r4, 0;
  rlwinm r0, r0, 0x1b, 0x1f, 0x1f;
  neg r3, r0;
  addi r3, r3, 2;
  mtctr r12;
  bctr;
  blr;
  // clang-format on
}

// Symbol: dvd_cbForNandWrite
// PAL: 0x80163844..0x801638a0
MARK_BINARY_BLOB(dvd_cbForNandWrite, 0x80163844, 0x801638a0);
asm UNKNOWN_FUNCTION(dvd_cbForNandWrite) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r3, 0x8034;
  lis r4, 0x8016;
  lis r5, 0x8034;
  stw r0, 0x14(r1);
  addi r3, r3, 0x3260;
  addi r4, r4, 0x3818;
  addi r5, r5, 0x32ec;
  bl NANDCloseAsync;
  cmpwi r3, 0;
  beq lbl_80163890;
  lwz r12, -0x6500(r13);
  cmpwi r12, 0;
  beq lbl_80163890;
  li r3, 2;
  li r4, 0;
  mtctr r12;
  bctrl;
lbl_80163890:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: dvd_cbForNandSeek
// PAL: 0x801638a0..0x80163968
MARK_BINARY_BLOB(dvd_cbForNandSeek, 0x801638a0, 0x80163968);
asm UNKNOWN_FUNCTION(dvd_cbForNandSeek) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8034;
  addi r31, r31, 0x3260;
  lwz r4, -0x6504(r13);
  addi r0, r4, 1;
  slwi r0, r0, 7;
  cmplw r3, r0;
  bne lbl_80163938;
  addi r3, r31, 0x160;
  li r4, 0x80;
  bl DCFlushRange;
  lis r6, 0x8016;
  addi r3, r31, 0;
  addi r4, r31, 0x160;
  addi r7, r31, 0x8c;
  addi r6, r6, 0x3844;
  li r5, 0x80;
  bl NANDWriteAsync;
  cmpwi r3, 0;
  beq lbl_80163954;
  lis r4, 0x8016;
  addi r3, r31, 0;
  addi r4, r4, 0x3818;
  addi r5, r31, 0x8c;
  bl NANDCloseAsync;
  cmpwi r3, 0;
  beq lbl_80163954;
  lwz r12, -0x6500(r13);
  cmpwi r12, 0;
  beq lbl_80163954;
  li r3, 2;
  li r4, 0;
  mtctr r12;
  bctrl;
  b lbl_80163954;
lbl_80163938:
  lwz r12, -0x6500(r13);
  cmpwi r12, 0;
  beq lbl_80163954;
  li r3, 2;
  li r4, 0;
  mtctr r12;
  bctrl;
lbl_80163954:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: dvd_cbForNandWrite0
// PAL: 0x80163968..0x80163a88
MARK_BINARY_BLOB(dvd_cbForNandWrite0, 0x80163968, 0x80163a88);
asm UNKNOWN_FUNCTION(dvd_cbForNandWrite0) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmplwi r3, 0x80;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8034;
  addi r31, r31, 0x3260;
  bne lbl_80163a58;
  lwz r4, -0x6504(r13);
  lis r6, 0x8016;
  addi r3, r31, 0;
  addi r7, r31, 0x8c;
  addi r0, r4, 1;
  addi r6, r6, 0x38a0;
  slwi r4, r0, 7;
  li r5, 0;
  bl NANDSeekAsync;
  cmpwi r3, 0;
  beq lbl_80163a74;
  lwz r3, -0x6504(r13);
  addi r0, r3, 1;
  slwi r3, r0, 7;
  addis r0, r3, 1;
  cmplwi r0, 0xffff;
  bne lbl_80163a38;
  addi r3, r31, 0x160;
  li r4, 0x80;
  bl DCFlushRange;
  lis r6, 0x8016;
  addi r3, r31, 0;
  addi r4, r31, 0x160;
  addi r7, r31, 0x8c;
  addi r6, r6, 0x3844;
  li r5, 0x80;
  bl NANDWriteAsync;
  cmpwi r3, 0;
  beq lbl_80163a74;
  lis r4, 0x8016;
  addi r3, r31, 0;
  addi r4, r4, 0x3818;
  addi r5, r31, 0x8c;
  bl NANDCloseAsync;
  cmpwi r3, 0;
  beq lbl_80163a74;
  lwz r12, -0x6500(r13);
  cmpwi r12, 0;
  beq lbl_80163a74;
  li r3, 2;
  li r4, 0;
  mtctr r12;
  bctrl;
  b lbl_80163a74;
lbl_80163a38:
  lwz r12, -0x6500(r13);
  cmpwi r12, 0;
  beq lbl_80163a74;
  li r3, 2;
  li r4, 0;
  mtctr r12;
  bctrl;
  b lbl_80163a74;
lbl_80163a58:
  lwz r12, -0x6500(r13);
  cmpwi r12, 0;
  beq lbl_80163a74;
  li r3, 2;
  li r4, 0;
  mtctr r12;
  bctrl;
lbl_80163a74:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: dvd_cbForNandSeek2
// PAL: 0x80163a88..0x80163b44
MARK_BINARY_BLOB(dvd_cbForNandSeek2, 0x80163a88, 0x80163b44);
asm UNKNOWN_FUNCTION(dvd_cbForNandSeek2) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmplwi r3, 0x80;
  lis r7, 0x8034;
  stw r0, 0x14(r1);
  addi r7, r7, 0x3260;
  bne lbl_80163b18;
  addi r4, r7, 0x1e0;
  lis r3, 0x2492;
  lwz r5, 0x18(r4);
  addi r0, r3, 0x4925;
  lis r6, 0x8016;
  addi r3, r7, 0;
  addi r9, r5, 1;
  addi r7, r7, 0x8c;
  mulhwu r8, r0, r9;
  addi r6, r6, 0x3968;
  li r5, 0x80;
  subf r0, r8, r9;
  srwi r0, r0, 1;
  add r0, r0, r8;
  srwi r0, r0, 2;
  mulli r0, r0, 7;
  subf r0, r0, r9;
  stw r0, 0x18(r4);
  bl NANDWriteAsync;
  cmpwi r3, 0;
  beq lbl_80163b34;
  lwz r12, -0x6500(r13);
  cmpwi r12, 0;
  beq lbl_80163b34;
  li r3, 2;
  li r4, 0;
  mtctr r12;
  bctrl;
  b lbl_80163b34;
lbl_80163b18:
  lwz r12, -0x6500(r13);
  cmpwi r12, 0;
  beq lbl_80163b34;
  li r3, 2;
  li r4, 0;
  mtctr r12;
  bctrl;
lbl_80163b34:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: dvd_cbForNandRead
// PAL: 0x80163b44..0x80163c2c
MARK_BINARY_BLOB(dvd_cbForNandRead, 0x80163b44, 0x80163c2c);
asm UNKNOWN_FUNCTION(dvd_cbForNandRead) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmplwi r3, 0x80;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8034;
  addi r31, r31, 0x3260;
  bne lbl_80163bb4;
  addi r3, r31, 0x1e0;
  lis r6, 0x8016;
  lwz r0, 0x18(r3);
  addi r3, r31, 0;
  addi r6, r6, 0x3a88;
  addi r7, r31, 0x8c;
  stw r0, -0x6504(r13);
  li r4, 0x80;
  li r5, 0;
  bl NANDSeekAsync;
  cmpwi r3, 0;
  beq lbl_80163c18;
  lwz r12, -0x6500(r13);
  cmpwi r12, 0;
  beq lbl_80163c18;
  li r3, 2;
  li r4, 0;
  mtctr r12;
  bctrl;
  b lbl_80163c18;
lbl_80163bb4:
  addi r4, r31, 0x160;
  li r0, 1;
  lis r6, 0x8016;
  stw r0, 0x18(r4);
  addi r3, r31, 0;
  addi r7, r31, 0x8c;
  addi r6, r6, 0x3844;
  li r5, 0x80;
  bl NANDWriteAsync;
  cmpwi r3, 0;
  beq lbl_80163c18;
  lis r4, 0x8016;
  addi r3, r31, 0;
  addi r4, r4, 0x3818;
  addi r5, r31, 0x8c;
  bl NANDCloseAsync;
  cmpwi r3, 0;
  beq lbl_80163c18;
  lwz r12, -0x6500(r13);
  cmpwi r12, 0;
  beq lbl_80163c18;
  li r3, 2;
  li r4, 0;
  mtctr r12;
  bctrl;
lbl_80163c18:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: dvd_cbForNandSeek0
// PAL: 0x80163c2c..0x80163ccc
MARK_BINARY_BLOB(dvd_cbForNandSeek0, 0x80163c2c, 0x80163ccc);
asm UNKNOWN_FUNCTION(dvd_cbForNandSeek0) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  lis r7, 0x8034;
  stw r0, 0x14(r1);
  addi r7, r7, 0x3260;
  bne lbl_80163ca0;
  li r3, 0;
  addi r5, r7, 0x160;
  li r0, 1;
  lis r6, 0x8016;
  stw r3, -0x6504(r13);
  addi r3, r7, 0;
  addi r4, r7, 0x1e0;
  addi r6, r6, 0x3968;
  stw r0, 0x18(r5);
  addi r7, r7, 0x8c;
  li r5, 0x80;
  bl NANDWriteAsync;
  cmpwi r3, 0;
  beq lbl_80163cbc;
  lwz r12, -0x6500(r13);
  cmpwi r12, 0;
  beq lbl_80163cbc;
  li r3, 2;
  li r4, 0;
  mtctr r12;
  bctrl;
  b lbl_80163cbc;
lbl_80163ca0:
  lwz r12, -0x6500(r13);
  cmpwi r12, 0;
  beq lbl_80163cbc;
  li r3, 2;
  li r4, 0;
  mtctr r12;
  bctrl;
lbl_80163cbc:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: dvd_cbForNandSeek1
// PAL: 0x80163ccc..0x80163dcc
MARK_BINARY_BLOB(dvd_cbForNandSeek1, 0x80163ccc, 0x80163dcc);
asm UNKNOWN_FUNCTION(dvd_cbForNandSeek1) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmplwi r3, 0x80;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8034;
  addi r31, r31, 0x3260;
  bne lbl_80163d78;
  lis r6, 0x8016;
  addi r3, r31, 0;
  addi r4, r31, 0x1e0;
  addi r7, r31, 0x8c;
  addi r6, r6, 0x3b44;
  li r5, 0x80;
  bl NANDReadAsync;
  cmpwi r3, 0;
  beq lbl_80163db8;
  addi r4, r31, 0x160;
  li r0, 1;
  lis r6, 0x8016;
  stw r0, 0x18(r4);
  addi r3, r31, 0;
  addi r7, r31, 0x8c;
  addi r6, r6, 0x3844;
  li r5, 0x80;
  bl NANDWriteAsync;
  cmpwi r3, 0;
  beq lbl_80163db8;
  lis r4, 0x8016;
  addi r3, r31, 0;
  addi r4, r4, 0x3818;
  addi r5, r31, 0x8c;
  bl NANDCloseAsync;
  cmpwi r3, 0;
  beq lbl_80163db8;
  lwz r12, -0x6500(r13);
  cmpwi r12, 0;
  beq lbl_80163db8;
  li r3, 2;
  li r4, 0;
  mtctr r12;
  bctrl;
  b lbl_80163db8;
lbl_80163d78:
  lis r6, 0x8016;
  addi r3, r31, 0;
  addi r6, r6, 0x3c2c;
  addi r7, r31, 0x8c;
  li r4, 0;
  li r5, 0;
  bl NANDSeekAsync;
  cmpwi r3, 0;
  beq lbl_80163db8;
  lwz r12, -0x6500(r13);
  cmpwi r12, 0;
  beq lbl_80163db8;
  li r3, 2;
  li r4, 0;
  mtctr r12;
  bctrl;
lbl_80163db8:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: dvd_cbForNandOpen
// PAL: 0x80163dcc..0x80163ee8
MARK_BINARY_BLOB(dvd_cbForNandOpen, 0x80163dcc, 0x80163ee8);
asm UNKNOWN_FUNCTION(dvd_cbForNandOpen) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8034;
  addi r31, r31, 0x3260;
  bne lbl_80163eb8;
  lwz r0, -0x6508(r13);
  cmpwi r0, 0;
  beq lbl_80163e60;
  lis r6, 0x8016;
  addi r3, r31, 0;
  addi r6, r6, 0x3ccc;
  addi r7, r31, 0x8c;
  li r4, 0x80;
  li r5, 0;
  bl NANDSeekAsync;
  cmpwi r3, 0;
  beq lbl_80163ed4;
  lis r6, 0x8016;
  addi r3, r31, 0;
  addi r6, r6, 0x3c2c;
  addi r7, r31, 0x8c;
  li r4, 0;
  li r5, 0;
  bl NANDSeekAsync;
  cmpwi r3, 0;
  beq lbl_80163ed4;
  lwz r12, -0x6500(r13);
  cmpwi r12, 0;
  beq lbl_80163ed4;
  li r3, 2;
  li r4, 0;
  mtctr r12;
  bctrl;
  b lbl_80163ed4;
lbl_80163e60:
  li r3, 0;
  addi r5, r31, 0x160;
  li r0, 1;
  lis r6, 0x8016;
  stw r3, -0x6504(r13);
  addi r3, r31, 0;
  addi r4, r31, 0x1e0;
  addi r6, r6, 0x3968;
  stw r0, 0x18(r5);
  addi r7, r31, 0x8c;
  li r5, 0x80;
  bl NANDWriteAsync;
  cmpwi r3, 0;
  beq lbl_80163ed4;
  lwz r12, -0x6500(r13);
  cmpwi r12, 0;
  beq lbl_80163ed4;
  li r3, 2;
  li r4, 0;
  mtctr r12;
  bctrl;
  b lbl_80163ed4;
lbl_80163eb8:
  lwz r12, -0x6500(r13);
  cmpwi r12, 0;
  beq lbl_80163ed4;
  li r3, 2;
  li r4, 0;
  mtctr r12;
  bctrl;
lbl_80163ed4:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: dvd_cbForNandCreate
// PAL: 0x80163ee8..0x80163f90
MARK_BINARY_BLOB(dvd_cbForNandCreate, 0x80163ee8, 0x80163f90);
asm UNKNOWN_FUNCTION(dvd_cbForNandCreate) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  beq lbl_80163f04;
  cmpwi r3, -6;
  bne lbl_80163f64;
lbl_80163f04:
  cmpwi r3, -6;
  bne lbl_80163f14;
  li r0, 1;
  stw r0, -0x6508(r13);
lbl_80163f14:
  lis r3, 0x8029;
  lis r4, 0x8034;
  lis r6, 0x8016;
  lis r7, 0x8034;
  addi r3, r3, -30984;
  addi r4, r4, 0x3260;
  addi r6, r6, 0x3dcc;
  addi r7, r7, 0x32ec;
  li r5, 3;
  bl NANDPrivateOpenAsync;
  cmpwi r3, 0;
  beq lbl_80163f80;
  lwz r12, -0x6500(r13);
  cmpwi r12, 0;
  beq lbl_80163f80;
  li r3, 2;
  li r4, 0;
  mtctr r12;
  bctrl;
  b lbl_80163f80;
lbl_80163f64:
  lwz r12, -0x6500(r13);
  cmpwi r12, 0;
  beq lbl_80163f80;
  li r3, 2;
  li r4, 0;
  mtctr r12;
  bctrl;
lbl_80163f80:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: dvd_cbForNandCreateDir
// PAL: 0x80163f90..0x80164024
MARK_BINARY_BLOB(dvd_cbForNandCreateDir, 0x80163f90, 0x80164024);
asm UNKNOWN_FUNCTION(dvd_cbForNandCreateDir) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  beq lbl_80163fac;
  cmpwi r3, -6;
  bne lbl_80163ff8;
lbl_80163fac:
  lis r3, 0x8029;
  lis r6, 0x8016;
  lis r7, 0x8034;
  li r4, 0x3f;
  addi r3, r3, -30984;
  addi r6, r6, 0x3ee8;
  addi r7, r7, 0x32ec;
  li r5, 0;
  bl NANDPrivateCreateAsync;
  cmpwi r3, 0;
  beq lbl_80164014;
  lwz r12, -0x6500(r13);
  cmpwi r12, 0;
  beq lbl_80164014;
  li r3, 2;
  li r4, 0;
  mtctr r12;
  bctrl;
  b lbl_80164014;
lbl_80163ff8:
  lwz r12, -0x6500(r13);
  cmpwi r12, 0;
  beq lbl_80164014;
  li r3, 2;
  li r4, 0;
  mtctr r12;
  bctrl;
lbl_80164014:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: dvd_cbForPrepareStatusRegister
// PAL: 0x80164024..0x801640b4
MARK_BINARY_BLOB(dvd_cbForPrepareStatusRegister, 0x80164024, 0x801640b4);
asm UNKNOWN_FUNCTION(dvd_cbForPrepareStatusRegister) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmplwi r3, 1;
  stw r0, 0x14(r1);
  bne lbl_8016404c;
  bl DVDLowGetStatusRegister;
  lis r4, 0x8034;
  addi r4, r4, 0x33c0;
  stw r3, 0x10(r4);
  b lbl_8016405c;
lbl_8016404c:
  lis r3, 0x8034;
  li r0, -1;
  addi r3, r3, 0x33c0;
  stw r0, 0x10(r3);
lbl_8016405c:
  lis r3, 0x8029;
  lis r6, 0x8016;
  lis r7, 0x8034;
  li r4, 0x3f;
  addi r3, r3, -30956;
  addi r6, r6, 0x3f90;
  addi r7, r7, 0x32ec;
  li r5, 0;
  bl NANDPrivateCreateDirAsync;
  cmpwi r3, 0;
  beq lbl_801640a4;
  lwz r12, -0x6500(r13);
  cmpwi r12, 0;
  beq lbl_801640a4;
  li r3, 2;
  li r4, 0;
  mtctr r12;
  bctrl;
lbl_801640a4:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __DVDStoreErrorCode
// PAL: 0x801640b4..0x8016411c
MARK_BINARY_BLOB(__DVDStoreErrorCode, 0x801640b4, 0x8016411c);
asm UNKNOWN_FUNCTION(__DVDStoreErrorCode) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8034;
  addi r31, r31, 0x33c0;
  stw r30, 8(r1);
  mr r30, r4;
  stw r3, 8(r31);
  bl OSGetTime;
  lis r6, 0x8000;
  li r5, 0;
  lwz r0, 0xf8(r6);
  srwi r6, r0, 2;
  bl __div2i;
  lis r3, 0x8016;
  stw r4, 0xc(r31);
  addi r3, r3, 0x4024;
  stw r30, -0x6500(r13);
  bl DVDLowPrepareStatusRegister;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}
