#include "eggIScnProc.hpp"

extern "C" {
extern UNKNOWN_FUNCTION(unk_800603b0);
extern UNKNOWN_FUNCTION(
    SetMtx__Q34nw4r3g3d6ScnObjFQ44nw4r3g3d6ScnObj13ScnObjMtxTypeRCQ34nw4r4math5MTX34);
extern UNKNOWN_FUNCTION(SetPriorityDrawOpa__Q34nw4r3g3d6ScnObjFi);
extern UNKNOWN_FUNCTION(SetPriorityDrawXlu__Q34nw4r3g3d6ScnObjFi);
extern UNKNOWN_FUNCTION(
    Construct__Q34nw4r3g3d7ScnProcFP12MEMAllocatorPUlPFPQ34nw4r3g3d7ScnProcb_vbbUl);
extern UNKNOWN_FUNCTION(PSMTXIdentity);
extern UNKNOWN_FUNCTION(unk_8022947c);
extern UNKNOWN_FUNCTION(__nwa__FUl);
extern UNKNOWN_FUNCTION(__dla__FPv);
extern UNKNOWN_FUNCTION(unk_802415e8);
}

// Symbol: unk_80229fac
// PAL: 0x80229fac..0x8022a05c
MARK_BINARY_BLOB(unk_80229fac, 0x80229fac, 0x8022a05c);
asm UNKNOWN_FUNCTION(unk_80229fac) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x24(r1);
  stmw r27, 0xc(r1);
  mr r27, r3;
  mr r28, r4;
  beq lbl_8022a044;
  lwz r0, 0(r3);
  lis r4, 0x802a;
  addi r4, r4, 0x30f0;
  stw r4, 8(r3);
  cmpwi r0, 0;
  beq lbl_8022a034;
  li r29, 0;
  li r30, 0;
  li r31, 0;
  b lbl_8022a018;
lbl_80229ff4:
  lwz r0, 0(r27);
  add r3, r0, r30;
  lwz r3, 4(r3);
  bl unk_800603b0;
  lwz r0, 0(r27);
  addi r29, r29, 1;
  add r3, r0, r30;
  addi r30, r30, 0xc;
  stw r31, 4(r3);
lbl_8022a018:
  lhz r0, 4(r27);
  cmpw r29, r0;
  blt lbl_80229ff4;
  lwz r3, 0(r27);
  bl __dla__FPv;
  li r0, 0;
  stw r0, 0(r27);
lbl_8022a034:
  cmpwi r28, 0;
  ble lbl_8022a044;
  mr r3, r27;
  bl __dl__FPv;
lbl_8022a044:
  mr r3, r27;
  lmw r27, 0xc(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_8022a05c
// PAL: 0x8022a05c..0x8022a164
MARK_BINARY_BLOB(unk_8022a05c, 0x8022a05c, 0x8022a164);
asm UNKNOWN_FUNCTION(unk_8022a05c) {
  // clang-format off
  nofralloc;
  stwu r1, -0x60(r1);
  mflr r0;
  stw r0, 0x64(r1);
  clrlwi r0, r4, 0x10;
  stmw r26, 0x48(r1);
  mr r28, r3;
  mr r29, r5;
  sth r4, 4(r3);
  mulli r3, r0, 0xc;
  bl __nwa__FUl;
  stw r3, 0(r28);
  addi r3, r1, 0x10;
  bl PSMTXIdentity;
  li r30, 0;
  lis r31, 0x8023;
  li r27, 1;
  b lbl_8022a140;
lbl_8022a0a0:
  cmpwi r29, 0;
  bne lbl_8022a0b0;
  lwz r3, -0x5d9c(r13);
  b lbl_8022a0b4;
lbl_8022a0b0:
  mr r3, r29;
lbl_8022a0b4:
  clrlwi r0, r30, 0x10;
  addi r4, r1, 8;
  mulli r26, r0, 0xc;
  addi r5, r31, -23788;
  li r6, 1;
  li r7, 0;
  li r8, 0;
  bl Construct__Q34nw4r3g3d7ScnProcFP12MEMAllocatorPUlPFPQ34nw4r3g3d7ScnProcb_vbbUl;
  lwz r0, 0(r28);
  addi r5, r1, 0x10;
  li r4, 0;
  add r6, r0, r26;
  stw r3, 4(r6);
  lwz r0, 0(r28);
  add r6, r0, r26;
  lwz r3, 4(r6);
  stw r6, 0xf0(r3);
  lwz r0, 0(r28);
  add r3, r0, r26;
  lwz r3, 4(r3);
  bl SetMtx__Q34nw4r3g3d6ScnObjFQ44nw4r3g3d6ScnObj13ScnObjMtxTypeRCQ34nw4r4math5MTX34;
  lwz r0, 0(r28);
  mr r3, r28;
  clrlwi r4, r30, 0x10;
  clrlwi r5, r30, 0x18;
  add r7, r0, r26;
  li r6, 1;
  sth r30, 8(r7);
  lwz r7, 0(r28);
  stwx r28, r7, r26;
  lwz r0, 0(r28);
  add r7, r0, r26;
  stb r27, 0xa(r7);
  bl unk_8022a164;
  addi r30, r30, 1;
lbl_8022a140:
  lhz r0, 4(r28);
  clrlwi r3, r30, 0x10;
  cmplw r3, r0;
  blt lbl_8022a0a0;
  lmw r26, 0x48(r1);
  lwz r0, 0x64(r1);
  mtlr r0;
  addi r1, r1, 0x60;
  blr;
  // clang-format on
}

// Symbol: unk_8022a164
// PAL: 0x8022a164..0x8022a210
MARK_BINARY_BLOB(unk_8022a164, 0x8022a164, 0x8022a210);
asm UNKNOWN_FUNCTION(unk_8022a164) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  cmpwi r6, 0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mulli r31, r4, 0xc;
  stw r30, 0x18(r1);
  mr r30, r6;
  stw r29, 0x14(r1);
  mr r29, r3;
  lwz r0, 0(r3);
  add r3, r0, r31;
  lwz r3, 4(r3);
  beq lbl_8022a1c4;
  lis r4, 0x8023;
  addi r4, r4, -23788;
  stw r4, 0xec(r3);
  mr r4, r5;
  lwz r0, 0xe8(r3);
  ori r0, r0, 1;
  rlwinm r0, r0, 0, 0x1f, 0x1d;
  stw r0, 0xe8(r3);
  bl SetPriorityDrawOpa__Q34nw4r3g3d6ScnObjFi;
  b lbl_8022a1e8;
lbl_8022a1c4:
  lis r4, 0x8023;
  addi r4, r4, -23788;
  stw r4, 0xec(r3);
  mr r4, r5;
  lwz r0, 0xe8(r3);
  rlwinm r0, r0, 0, 0, 0x1e;
  ori r0, r0, 2;
  stw r0, 0xe8(r3);
  bl SetPriorityDrawXlu__Q34nw4r3g3d6ScnObjFi;
lbl_8022a1e8:
  lwz r0, 0(r29);
  add r3, r0, r31;
  stb r30, 0xa(r3);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: pushToScnGroup__Q23EGG8IScnProcFPQ34nw4r3g3d8ScnGroup
// PAL: 0x8022a210..0x8022a294
MARK_BINARY_BLOB(pushToScnGroup__Q23EGG8IScnProcFPQ34nw4r3g3d8ScnGroup,
                 0x8022a210, 0x8022a294);
asm UNKNOWN_FUNCTION(pushToScnGroup__Q23EGG8IScnProcFPQ34nw4r3g3d8ScnGroup) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  li r31, 0;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  b lbl_8022a268;
lbl_8022a238:
  clrlwi r0, r31, 0x10;
  lwz r12, 0(r30);
  mulli r0, r0, 0xc;
  lwz r4, 0(r29);
  lwz r12, 0x34(r12);
  mr r3, r30;
  add r5, r4, r0;
  lwz r4, 0xe4(r30);
  lwz r5, 4(r5);
  mtctr r12;
  bctrl;
  addi r31, r31, 1;
lbl_8022a268:
  lhz r0, 4(r29);
  clrlwi r3, r31, 0x10;
  cmplw r3, r0;
  blt lbl_8022a238;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: removeFromScnGroup__Q23EGG8IScnProcFPQ34nw4r3g3d8ScnGroup
// PAL: 0x8022a294..0x8022a314
MARK_BINARY_BLOB(removeFromScnGroup__Q23EGG8IScnProcFPQ34nw4r3g3d8ScnGroup,
                 0x8022a294, 0x8022a314);
asm UNKNOWN_FUNCTION(
    removeFromScnGroup__Q23EGG8IScnProcFPQ34nw4r3g3d8ScnGroup) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  li r31, 0;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  b lbl_8022a2e8;
lbl_8022a2bc:
  clrlwi r0, r31, 0x10;
  lwz r12, 0(r30);
  mulli r0, r0, 0xc;
  lwz r4, 0(r29);
  lwz r12, 0x3c(r12);
  mr r3, r30;
  add r4, r4, r0;
  lwz r4, 4(r4);
  mtctr r12;
  bctrl;
  addi r31, r31, 1;
lbl_8022a2e8:
  lhz r0, 4(r29);
  clrlwi r3, r31, 0x10;
  cmplw r3, r0;
  blt lbl_8022a2bc;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_8022a314
// PAL: 0x8022a314..0x8022a38c
MARK_BINARY_BLOB(unk_8022a314, 0x8022a314, 0x8022a38c);
asm UNKNOWN_FUNCTION(unk_8022a314) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r4;
  li r4, 0;
  lwz r31, 0xf0(r3);
  mr r3, r30;
  bl unk_8022947c;
  lhz r0, -0x6c48(r13);
  rlwinm r0, r0, 0, 0x1a, 0x18;
  sth r0, -0x6c48(r13);
  lwz r3, 0(r31);
  lhz r4, 8(r31);
  lwz r12, 8(r3);
  lwz r12, 8(r12);
  mtctr r12;
  bctrl;
  bl unk_802415e8;
  lhz r0, -0x6c48(r13);
  mr r3, r30;
  rlwinm r4, r0, 0x1a, 0x1f, 0x1f;
  bl unk_8022947c;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}
