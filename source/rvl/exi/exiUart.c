#include "exiUart.h"

#include "exiBios.h"

// Symbol: ProbeBarnacle
// PAL: 0x8016970c..0x80169884
MARK_BINARY_BLOB(ProbeBarnacle, 0x8016970c, 0x80169884);
asm UNKNOWN_FUNCTION(ProbeBarnacle) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  cmpwi r3, 2;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r5;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  stw r28, 0x10(r1);
  beq lbl_8016975c;
  cmpwi r4, 0;
  bne lbl_8016975c;
  li r4, 0;
  bl EXIAttach;
  cmpwi r3, 0;
  bne lbl_8016975c;
  li r3, 0;
  b lbl_80169864;
lbl_8016975c:
  mr r3, r29;
  mr r4, r30;
  li r5, 0;
  bl EXILock;
  cntlzw r0, r3;
  rlwinm. r28, r0, 0x1b, 5, 0x1f;
  bne lbl_80169828;
  mr r3, r29;
  mr r4, r30;
  li r5, 0;
  bl EXISelect;
  cntlzw r0, r3;
  rlwinm. r28, r0, 0x1b, 5, 0x1f;
  bne lbl_80169820;
  lis r4, 0x2001;
  mr r3, r29;
  addi r0, r4, 0x1300;
  li r5, 4;
  stw r0, 8(r1);
  addi r4, r1, 8;
  li r6, 1;
  li r7, 0;
  bl EXIImm;
  cntlzw r0, r3;
  mr r3, r29;
  srwi r28, r0, 5;
  bl EXISync;
  cntlzw r0, r3;
  mr r3, r29;
  srwi r0, r0, 5;
  mr r4, r31;
  or r28, r28, r0;
  li r5, 4;
  li r6, 0;
  li r7, 0;
  bl EXIImm;
  cntlzw r0, r3;
  mr r3, r29;
  srwi r0, r0, 5;
  or r28, r28, r0;
  bl EXISync;
  cntlzw r0, r3;
  mr r3, r29;
  srwi r0, r0, 5;
  or r28, r28, r0;
  bl EXIDeselect;
  cntlzw r0, r3;
  srwi r0, r0, 5;
  or r28, r28, r0;
lbl_80169820:
  mr r3, r29;
  bl EXIUnlock;
lbl_80169828:
  cmpwi r29, 2;
  beq lbl_80169840;
  cmpwi r30, 0;
  bne lbl_80169840;
  mr r3, r29;
  bl EXIDetach;
lbl_80169840:
  cmpwi r28, 0;
  beq lbl_80169850;
  li r3, 0;
  b lbl_80169864;
lbl_80169850:
  lwz r4, 0(r31);
  subfic r3, r4, -1;
  addi r0, r4, 1;
  or r0, r3, r0;
  srwi r3, r0, 0x1f;
lbl_80169864:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: __OSEnableBarnacle
// PAL: 0x80169884..0x80169a40
MARK_BINARY_BLOB(__OSEnableBarnacle, 0x80169884, 0x80169a40);
asm UNKNOWN_FUNCTION(__OSEnableBarnacle) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r5, r1, 8;
  stw r31, 0x1c(r1);
  mr r31, r4;
  stw r30, 0x18(r1);
  mr r30, r3;
  bl EXIGetID;
  cmpwi r3, 0;
  beq lbl_80169a28;
  lwz r4, 8(r1);
  lis r0, 0x102;
  cmpw r4, r0;
  beq lbl_80169a28;
  bge lbl_80169954;
  cmpwi r4, 4;
  beq lbl_80169a28;
  bge lbl_80169920;
  lis r3, 0x8000;
  addi r0, r3, 0x10;
  cmpw r4, r0;
  beq lbl_80169a28;
  bge lbl_80169904;
  addi r0, r3, 8;
  cmpw r4, r0;
  beq lbl_80169a28;
  bge lbl_801699f8;
  addi r0, r3, 4;
  cmpw r4, r0;
  beq lbl_80169a28;
  b lbl_801699f8;
lbl_80169904:
  cmpwi r4, -1;
  beq lbl_80169a28;
  bge lbl_801699f8;
  addi r0, r3, 0x20;
  cmpw r4, r0;
  beq lbl_80169a28;
  b lbl_801699f8;
lbl_80169920:
  cmpwi r4, 0x20;
  beq lbl_80169a28;
  bge lbl_80169944;
  cmpwi r4, 0x10;
  beq lbl_80169a28;
  bge lbl_801699f8;
  cmpwi r4, 8;
  beq lbl_80169a28;
  b lbl_801699f8;
lbl_80169944:
  lis r0, 0x101;
  cmpw r4, r0;
  beq lbl_80169a28;
  b lbl_801699f8;
lbl_80169954:
  lis r3, 0x404;
  addi r0, r3, 0x404;
  cmpw r4, r0;
  beq lbl_80169a28;
  bge lbl_801699bc;
  lis r3, 0x402;
  addi r0, r3, 0x100;
  cmpw r4, r0;
  beq lbl_80169a28;
  bge lbl_8016999c;
  lis r0, 0x301;
  cmpw r4, r0;
  beq lbl_80169a28;
  bge lbl_801699f8;
  lis r0, 0x202;
  cmpw r4, r0;
  beq lbl_80169a28;
  b lbl_801699f8;
lbl_8016999c:
  addi r0, r3, 0x300;
  cmpw r4, r0;
  beq lbl_80169a28;
  bge lbl_801699f8;
  addi r0, r3, 0x200;
  cmpw r4, r0;
  beq lbl_80169a28;
  b lbl_801699f8;
lbl_801699bc:
  lis r0, 0x413;
  cmpw r4, r0;
  beq lbl_80169a28;
  bge lbl_801699ec;
  lis r0, 0x412;
  cmpw r4, r0;
  beq lbl_80169a28;
  bge lbl_801699f8;
  lis r0, 0x406;
  cmpw r4, r0;
  beq lbl_80169a28;
  b lbl_801699f8;
lbl_801699ec:
  lis r0, 0x422;
  cmpw r4, r0;
  beq lbl_80169a28;
lbl_801699f8:
  mr r3, r30;
  mr r4, r31;
  addi r5, r1, 8;
  bl ProbeBarnacle;
  cmpwi r3, 0;
  beq lbl_80169a28;
  lis r3, 0xa5ff;
  stw r30, -0x6494(r13);
  addi r0, r3, 0x5a;
  stw r31, -0x6498(r13);
  stw r0, -0x649c(r13);
  stw r0, -0x64a0(r13);
lbl_80169a28:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}
