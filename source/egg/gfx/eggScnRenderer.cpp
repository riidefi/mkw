#include "eggScnRenderer.hpp"

extern "C" {
extern UNKNOWN_FUNCTION(SetPriorityDrawOpa__Q34nw4r3g3d6ScnObjFi);
extern UNKNOWN_FUNCTION(SetPriorityDrawXlu__Q34nw4r3g3d6ScnObjFi);
extern UNKNOWN_FUNCTION(DrawPathBase_createSceneProc);
extern UNKNOWN_FUNCTION(unk_8021c4bc);
extern UNKNOWN_FUNCTION(unk_8021c56c);
extern UNKNOWN_FUNCTION(unk_8021e8cc);
extern UNKNOWN_FUNCTION(unk_8021ebc8);
extern UNKNOWN_FUNCTION(unk_80220a44);
extern UNKNOWN_FUNCTION(unk_80220ce8);
extern UNKNOWN_FUNCTION(unk_8022183c);
extern UNKNOWN_FUNCTION(__nw__FUl);
extern UNKNOWN_FUNCTION(__nwa__FUl);
extern UNKNOWN_FUNCTION(__dla__FPv);
extern UNKNOWN_FUNCTION(unk_80229fac);
extern UNKNOWN_FUNCTION(unk_8022a05c);
extern UNKNOWN_FUNCTION(unk_8022a164);
extern UNKNOWN_FUNCTION(pushToScnGroup__Q23EGG8IScnProcFPQ34nw4r3g3d8ScnGroup);
extern UNKNOWN_FUNCTION(
    removeFromScnGroup__Q23EGG8IScnProcFPQ34nw4r3g3d8ScnGroup);
extern UNKNOWN_FUNCTION(__ct__Q23EGG9ScnRootExFPQ34nw4r3g3d7ScnRoot);
extern UNKNOWN_FUNCTION(unk_8023c748);
extern UNKNOWN_FUNCTION(unk_8023c828);
extern UNKNOWN_FUNCTION(unk_8023ccd4);
extern UNKNOWN_FUNCTION(unk_8023cec8);
extern UNKNOWN_FUNCTION(unk_8023d840);
extern UNKNOWN_FUNCTION(unk_80240358);
extern UNKNOWN_FUNCTION(unk_80240844);
}

extern u8 unk_80389018, unk_80389019, unk_8038901a;

// Symbol: __ct__Q23EGG11ScnRendererFPQ34nw4r3g3d7ScnRoot
// PAL: 0x8023b980..0x8023ba18
MARK_BINARY_BLOB(__ct__Q23EGG11ScnRendererFPQ34nw4r3g3d7ScnRoot, 0x8023b980,
                 0x8023ba18);
asm UNKNOWN_FUNCTION(__ct__Q23EGG11ScnRendererFPQ34nw4r3g3d7ScnRoot) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl __ct__Q23EGG9ScnRootExFPQ34nw4r3g3d7ScnRoot;
  lis r7, 0x802a;
  li r8, 0;
  addi r7, r7, 0x3e58;
  li r0, 1;
  addi r6, r7, 0x38;
  stw r8, 0xb8(r31);
  addi r3, r31, 0xb8;
  li r4, 2;
  sth r8, 0xbc(r31);
  li r5, 0;
  stw r7, 0xb4(r31);
  stw r6, 0xc0(r31);
  stw r8, 0xc4(r31);
  stw r8, 0xc8(r31);
  sth r0, 0xcc(r31);
  bl unk_8022a05c;
  addi r3, r31, 0xb8;
  li r4, 0;
  li r5, 0x65;
  li r6, 0;
  bl unk_8022a164;
  addi r3, r31, 0xb8;
  li r4, 1;
  li r5, 0x84;
  li r6, 0;
  bl unk_8022a164;
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_8023ba18
// PAL: 0x8023ba18..0x8023bb10
MARK_BINARY_BLOB(unk_8023ba18, 0x8023ba18, 0x8023bb10);
asm UNKNOWN_FUNCTION(unk_8023ba18) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x24(r1);
  stmw r27, 0xc(r1);
  mr r27, r3;
  mr r28, r4;
  beq lbl_8023baf8;
  lis r4, 0x802a;
  li r29, 0;
  addi r4, r4, 0x3e58;
  stw r4, 0xb4(r3);
  addi r0, r4, 0x38;
  li r30, 0;
  stw r0, 0xc0(r3);
  li r31, 0;
  b lbl_8023ba94;
lbl_8023ba5c:
  lwz r3, 0xc4(r27);
  lwzx r3, r3, r30;
  cmpwi r3, 0;
  beq lbl_8023ba8c;
  beq lbl_8023ba84;
  lwz r12, 4(r3);
  li r4, 1;
  lwz r12, 8(r12);
  mtctr r12;
  bctrl;
lbl_8023ba84:
  lwz r3, 0xc4(r27);
  stwx r31, r3, r30;
lbl_8023ba8c:
  addi r30, r30, 4;
  addi r29, r29, 1;
lbl_8023ba94:
  lwz r12, 0xb4(r27);
  mr r3, r27;
  lwz r12, 0x4c(r12);
  mtctr r12;
  bctrl;
  clrlwi r0, r3, 0x10;
  cmpw r29, r0;
  blt lbl_8023ba5c;
  lwz r3, 0xc4(r27);
  bl __dla__FPv;
  li r31, 0;
  stw r31, 0xc4(r27);
  lwz r3, 0xc8(r27);
  bl __dla__FPv;
  stw r31, 0xc8(r27);
  addi r3, r27, 0xb8;
  li r4, 0;
  bl unk_80229fac;
  mr r3, r27;
  li r4, 0;
  bl unk_8023c748;
  cmpwi r28, 0;
  ble lbl_8023baf8;
  mr r3, r27;
  bl __dl__FPv;
lbl_8023baf8:
  mr r3, r27;
  lmw r27, 0xc(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_8023bb10
// PAL: 0x8023bb10..0x8023bb18
MARK_BINARY_BLOB(unk_8023bb10, 0x8023bb10, 0x8023bb18);
asm UNKNOWN_FUNCTION(unk_8023bb10) {
  // clang-format off
  nofralloc;
  li r3, 6;
  blr;
  // clang-format on
}

// Symbol: unk_8023bb18
// PAL: 0x8023bb18..0x8023bd38
MARK_BINARY_BLOB(unk_8023bb18, 0x8023bb18, 0x8023bd38);
asm UNKNOWN_FUNCTION(unk_8023bb18) {
  // clang-format off
  nofralloc;
  stwu r1, -0x60(r1);
  mflr r0;
  stw r0, 0x64(r1);
  stmw r14, 0x18(r1);
  mr r15, r3;
  bl unk_8023c828;
  lwz r12, 0xb4(r15);
  mr r3, r15;
  lwz r12, 0x4c(r12);
  mtctr r12;
  bctrl;
  rlwinm r3, r3, 2, 0xe, 0x1d;
  bl __nwa__FUl;
  stw r3, 0xc4(r15);
  li r17, 0;
  li r16, 0;
  li r14, 0;
  b lbl_8023bb70;
lbl_8023bb60:
  lwz r3, 0xc4(r15);
  addi r17, r17, 1;
  stwx r14, r3, r16;
  addi r16, r16, 4;
lbl_8023bb70:
  lwz r12, 0xb4(r15);
  mr r3, r15;
  lwz r12, 0x4c(r12);
  mtctr r12;
  bctrl;
  clrlwi r0, r3, 0x10;
  cmpw r17, r0;
  blt lbl_8023bb60;
  lwz r12, 0xb4(r15);
  mr r3, r15;
  lwz r12, 0x50(r12);
  mtctr r12;
  bctrl;
  clrlwi r4, r3, 0x10;
  rlwinm r0, r3, 2, 0xe, 0x1d;
  subf r3, r4, r0;
  bl __nwa__FUl;
  stw r3, 0xc8(r15);
  li r16, 0;
  li r31, 0;
  li r30, 0x1a;
  li r14, 0x31;
  li r28, 1;
  li r29, 0x18;
  li r26, 0x33;
  li r27, 0x4a;
  li r24, 0x4d;
  li r25, 0x64;
  li r22, 0x34;
  li r23, 0x4b;
  li r20, 0x1b;
  li r21, 0x32;
  li r18, 2;
  li r19, 0x19;
  lis r17, 0x802a;
  b lbl_8023bcf8;
lbl_8023bc00:
  clrlwi r5, r16, 0x10;
  rlwinm r0, r16, 2, 0xe, 0x1d;
  lbz r6, unk_80389019;
  subf r0, r5, r0;
  lbz r4, unk_8038901a;
  cmplwi r5, 9;
  lbz r7, unk_80389018;
  lwz r3, 0xc8(r15);
  stb r7, 8(r1);
  stbux r7, r3, r0;
  stb r6, 1(r3);
  stb r6, 9(r1);
  stb r4, 0xa(r1);
  stb r4, 2(r3);
  bgt lbl_8023bcf4;
  addi r4, r17, 0x3e30;
  slwi r0, r5, 2;
  lwzx r4, r4, r0;
  mtctr r4;
  bctr;
  stb r18, 0(r3);
  stb r19, 1(r3);
  b lbl_8023bcf4;
  stb r20, 0(r3);
  stb r21, 1(r3);
  b lbl_8023bcf4;
  stb r22, 0(r3);
  stb r23, 1(r3);
  b lbl_8023bcf4;
  stb r24, 0(r3);
  stb r25, 1(r3);
  b lbl_8023bcf4;
  stb r26, 0(r3);
  stb r27, 1(r3);
  stb r31, 2(r3);
  b lbl_8023bcf4;
  stb r28, 0(r3);
  stb r29, 1(r3);
  stb r31, 2(r3);
  b lbl_8023bcf4;
  stb r30, 0(r3);
  stb r14, 1(r3);
  stb r31, 2(r3);
  b lbl_8023bcf4;
  li r0, 0x4c;
  stb r0, 0(r3);
  li r0, 0x63;
  stb r0, 1(r3);
  stb r31, 2(r3);
  b lbl_8023bcf4;
  li r0, 0x66;
  stb r0, 0(r3);
  li r0, 0x7d;
  stb r0, 1(r3);
  stb r31, 2(r3);
  b lbl_8023bcf4;
  li r0, 0x87;
  stb r0, 0(r3);
  li r0, 0x9e;
  stb r0, 1(r3);
  stb r31, 2(r3);
lbl_8023bcf4:
  addi r16, r16, 1;
lbl_8023bcf8:
  lwz r12, 0xb4(r15);
  mr r3, r15;
  lwz r12, 0x50(r12);
  mtctr r12;
  bctrl;
  clrlwi r3, r3, 0x10;
  clrlwi r0, r16, 0x10;
  cmplw r0, r3;
  blt lbl_8023bc00;
  lmw r14, 0x18(r1);
  lwz r0, 0x64(r1);
  mtlr r0;
  addi r1, r1, 0x60;
  blr;
  li r3, 0xa;
  blr;
  // clang-format on
}

// Symbol: ScnRenderer_createPath
// PAL: 0x8023bd38..0x8023c04c
MARK_BINARY_BLOB(ScnRenderer_createPath, 0x8023bd38, 0x8023c04c);
asm UNKNOWN_FUNCTION(ScnRenderer_createPath) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stmw r26, 8(r1);
  mr r27, r3;
  mr r28, r4;
  mr r29, r5;
  li r30, 0;
  li r31, 1;
  b lbl_8023c008;
lbl_8023bd60:
  clrlwi r3, r30, 0x10;
  slw r0, r31, r3;
  and. r0, r28, r0;
  beq lbl_8023c004;
  addi r0, r3, -1;
  cmplwi r0, 1;
  ble lbl_8023bdc4;
  cmpwi r3, 0;
  beq lbl_8023bda0;
  cmpwi r3, 3;
  beq lbl_8023bde8;
  cmpwi r3, 4;
  beq lbl_8023be0c;
  cmpwi r3, 5;
  beq lbl_8023be30;
  b lbl_8023be50;
lbl_8023bda0:
  li r3, 0x34;
  bl __nw__FUl;
  cmpwi r3, 0;
  beq lbl_8023bdb4;
  bl unk_8022183c;
lbl_8023bdb4:
  lwz r4, 0xc4(r27);
  rlwinm r0, r30, 2, 0xe, 0x1d;
  stwx r3, r4, r0;
  b lbl_8023be50;
lbl_8023bdc4:
  li r3, 0x34;
  bl __nw__FUl;
  cmpwi r3, 0;
  beq lbl_8023bdd8;
  bl unk_80220ce8;
lbl_8023bdd8:
  lwz r4, 0xc4(r27);
  rlwinm r0, r30, 2, 0xe, 0x1d;
  stwx r3, r4, r0;
  b lbl_8023be50;
lbl_8023bde8:
  li r3, 0x18;
  bl __nw__FUl;
  cmpwi r3, 0;
  beq lbl_8023bdfc;
  bl unk_80220a44;
lbl_8023bdfc:
  lwz r4, 0xc4(r27);
  rlwinm r0, r30, 2, 0xe, 0x1d;
  stwx r3, r4, r0;
  b lbl_8023be50;
lbl_8023be0c:
  li r3, 0xcc;
  bl __nw__FUl;
  cmpwi r3, 0;
  beq lbl_8023be20;
  bl unk_8021c56c;
lbl_8023be20:
  lwz r4, 0xc4(r27);
  rlwinm r0, r30, 2, 0xe, 0x1d;
  stwx r3, r4, r0;
  b lbl_8023be50;
lbl_8023be30:
  li r3, 0x8c;
  bl __nw__FUl;
  cmpwi r3, 0;
  beq lbl_8023be44;
  bl unk_8021e8cc;
lbl_8023be44:
  lwz r4, 0xc4(r27);
  rlwinm r0, r30, 2, 0xe, 0x1d;
  stwx r3, r4, r0;
lbl_8023be50:
  lwz r3, 0xc4(r27);
  rlwinm r0, r30, 2, 0xe, 0x1d;
  mr r4, r29;
  lwzx r26, r3, r0;
  mr r3, r26;
  bl DrawPathBase_createSceneProc;
  clrlwi. r0, r30, 0x10;
  beq lbl_8023be9c;
  cmpwi r0, 1;
  beq lbl_8023bedc;
  cmpwi r0, 3;
  beq lbl_8023bf1c;
  cmpwi r0, 2;
  beq lbl_8023bf48;
  cmpwi r0, 4;
  beq lbl_8023bf88;
  cmpwi r0, 5;
  beq lbl_8023bfc8;
  b lbl_8023c004;
lbl_8023be9c:
  addi r3, r26, 8;
  li r4, 0;
  li r5, 1;
  li r6, 1;
  bl unk_8022a164;
  addi r3, r26, 8;
  li r4, 1;
  li r5, 0x1a;
  li r6, 1;
  bl unk_8022a164;
  addi r3, r26, 8;
  li r4, 2;
  li r5, 0x4b;
  li r6, 0;
  bl unk_8022a164;
  b lbl_8023c004;
lbl_8023bedc:
  addi r3, r26, 8;
  li r4, 0;
  li r5, 0;
  li r6, 1;
  bl unk_8022a164;
  addi r3, r26, 8;
  li r4, 1;
  li r5, 0x33;
  li r6, 1;
  bl unk_8022a164;
  addi r3, r26, 8;
  li r4, 2;
  li r5, 0x4c;
  li r6, 1;
  bl unk_8022a164;
  b lbl_8023c004;
lbl_8023bf1c:
  addi r3, r26, 8;
  li r4, 0;
  li r5, 0x7e;
  li r6, 0;
  bl unk_8022a164;
  addi r3, r26, 8;
  li r4, 1;
  li r5, 0x81;
  li r6, 0;
  bl unk_8022a164;
  b lbl_8023c004;
lbl_8023bf48:
  addi r3, r26, 8;
  li r4, 0;
  li r5, 0;
  li r6, 0;
  bl unk_8022a164;
  addi r3, r26, 8;
  li r4, 1;
  li r5, 0x19;
  li r6, 0;
  bl unk_8022a164;
  addi r3, r26, 8;
  li r4, 2;
  li r5, 0x32;
  li r6, 0;
  bl unk_8022a164;
  b lbl_8023c004;
lbl_8023bf88:
  addi r3, r26, 8;
  li r4, 0;
  li r5, 0x7f;
  li r6, 0;
  bl unk_8022a164;
  addi r3, r26, 8;
  li r4, 1;
  li r5, 0x82;
  li r6, 0;
  bl unk_8022a164;
  addi r3, r26, 8;
  li r4, 2;
  li r5, 0x86;
  li r6, 0;
  bl unk_8022a164;
  b lbl_8023c004;
lbl_8023bfc8:
  addi r3, r26, 8;
  li r4, 0;
  li r5, 0x80;
  li r6, 0;
  bl unk_8022a164;
  addi r3, r26, 8;
  li r4, 1;
  li r5, 0x83;
  li r6, 0;
  bl unk_8022a164;
  addi r3, r26, 8;
  li r4, 2;
  li r5, 0x85;
  li r6, 0;
  bl unk_8022a164;
lbl_8023c004:
  addi r30, r30, 1;
lbl_8023c008:
  lwz r12, 0xb4(r27);
  mr r3, r27;
  lwz r12, 0x4c(r12);
  mtctr r12;
  bctrl;
  clrlwi r3, r3, 0x10;
  clrlwi r0, r30, 0x10;
  cmplw r0, r3;
  blt lbl_8023bd60;
  lhz r0, 0x14(r27);
  rlwinm r0, r0, 0, 0x1c, 0x1a;
  sth r0, 0x14(r27);
  lmw r26, 8(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: attach__Q23EGG11ScnRendererFv
// PAL: 0x8023c04c..0x8023c0d8
MARK_BINARY_BLOB(attach__Q23EGG11ScnRendererFv, 0x8023c04c, 0x8023c0d8);
asm UNKNOWN_FUNCTION(attach__Q23EGG11ScnRendererFv) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  li r31, 0;
  stw r30, 8(r1);
  mr r30, r3;
  b lbl_8023c090;
lbl_8023c06c:
  lwz r3, 0xc4(r30);
  rlwinm r0, r31, 2, 0xe, 0x1d;
  lwzx r3, r3, r0;
  cmpwi r3, 0;
  beq lbl_8023c08c;
  lwz r4, 0(r30);
  addi r3, r3, 8;
  bl pushToScnGroup__Q23EGG8IScnProcFPQ34nw4r3g3d8ScnGroup;
lbl_8023c08c:
  addi r31, r31, 1;
lbl_8023c090:
  lwz r12, 0xb4(r30);
  mr r3, r30;
  lwz r12, 0x4c(r12);
  mtctr r12;
  bctrl;
  clrlwi r3, r3, 0x10;
  clrlwi r0, r31, 0x10;
  cmplw r0, r3;
  blt lbl_8023c06c;
  lwz r4, 0(r30);
  addi r3, r30, 0xb8;
  bl pushToScnGroup__Q23EGG8IScnProcFPQ34nw4r3g3d8ScnGroup;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_8023c0d8
// PAL: 0x8023c0d8..0x8023c164
MARK_BINARY_BLOB(unk_8023c0d8, 0x8023c0d8, 0x8023c164);
asm UNKNOWN_FUNCTION(unk_8023c0d8) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  li r31, 0;
  stw r30, 8(r1);
  mr r30, r3;
  b lbl_8023c11c;
lbl_8023c0f8:
  lwz r3, 0xc4(r30);
  rlwinm r0, r31, 2, 0xe, 0x1d;
  lwzx r3, r3, r0;
  cmpwi r3, 0;
  beq lbl_8023c118;
  lwz r4, 0(r30);
  addi r3, r3, 8;
  bl removeFromScnGroup__Q23EGG8IScnProcFPQ34nw4r3g3d8ScnGroup;
lbl_8023c118:
  addi r31, r31, 1;
lbl_8023c11c:
  lwz r12, 0xb4(r30);
  mr r3, r30;
  lwz r12, 0x4c(r12);
  mtctr r12;
  bctrl;
  clrlwi r3, r3, 0x10;
  clrlwi r0, r31, 0x10;
  cmplw r0, r3;
  blt lbl_8023c0f8;
  lwz r4, 0(r30);
  addi r3, r30, 0xb8;
  bl removeFromScnGroup__Q23EGG8IScnProcFPQ34nw4r3g3d8ScnGroup;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_8023c164
// PAL: 0x8023c164..0x8023c280
MARK_BINARY_BLOB(unk_8023c164, 0x8023c164, 0x8023c280);
asm UNKNOWN_FUNCTION(unk_8023c164) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  lwz r0, 0(r3);
  cmplw r4, r0;
  beq lbl_8023c260;
  li r31, 0;
  b lbl_8023c1bc;
lbl_8023c198:
  lwz r3, 0xc4(r29);
  rlwinm r0, r31, 2, 0xe, 0x1d;
  lwzx r3, r3, r0;
  cmpwi r3, 0;
  beq lbl_8023c1b8;
  lwz r4, 0(r29);
  addi r3, r3, 8;
  bl removeFromScnGroup__Q23EGG8IScnProcFPQ34nw4r3g3d8ScnGroup;
lbl_8023c1b8:
  addi r31, r31, 1;
lbl_8023c1bc:
  lwz r12, 0xb4(r29);
  mr r3, r29;
  lwz r12, 0x4c(r12);
  mtctr r12;
  bctrl;
  clrlwi r3, r3, 0x10;
  clrlwi r0, r31, 0x10;
  cmplw r0, r3;
  blt lbl_8023c198;
  lwz r4, 0(r29);
  addi r3, r29, 0xb8;
  bl removeFromScnGroup__Q23EGG8IScnProcFPQ34nw4r3g3d8ScnGroup;
  mr r3, r29;
  mr r4, r30;
  bl unk_8023cec8;
  mr r30, r3;
  li r31, 0;
  b lbl_8023c228;
lbl_8023c204:
  lwz r3, 0xc4(r29);
  rlwinm r0, r31, 2, 0xe, 0x1d;
  lwzx r3, r3, r0;
  cmpwi r3, 0;
  beq lbl_8023c224;
  lwz r4, 0(r29);
  addi r3, r3, 8;
  bl pushToScnGroup__Q23EGG8IScnProcFPQ34nw4r3g3d8ScnGroup;
lbl_8023c224:
  addi r31, r31, 1;
lbl_8023c228:
  lwz r12, 0xb4(r29);
  mr r3, r29;
  lwz r12, 0x4c(r12);
  mtctr r12;
  bctrl;
  clrlwi r3, r3, 0x10;
  clrlwi r0, r31, 0x10;
  cmplw r0, r3;
  blt lbl_8023c204;
  lwz r4, 0(r29);
  addi r3, r29, 0xb8;
  bl pushToScnGroup__Q23EGG8IScnProcFPQ34nw4r3g3d8ScnGroup;
  mr r3, r30;
  b lbl_8023c264;
lbl_8023c260:
  mr r3, r30;
lbl_8023c264:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_8023c280
// PAL: 0x8023c280..0x8023c328
MARK_BINARY_BLOB(unk_8023c280, 0x8023c280, 0x8023c328);
asm UNKNOWN_FUNCTION(unk_8023c280) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r4, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  beq lbl_8023c2a8;
  cmpwi r4, 1;
  beq lbl_8023c2fc;
  b lbl_8023c314;
lbl_8023c2a8:
  lhz r0, 0xcc(r3);
  rlwinm. r0, r0, 0, 0x1d, 0x1d;
  beq lbl_8023c314;
  lwz r3, 0xc4(r3);
  li r4, 0;
  lwz r3, 0x10(r3);
  cmpwi r3, 0;
  beq lbl_8023c2d8;
  lhz r0, 0x18(r3);
  rlwinm. r0, r0, 0, 0x1c, 0x1c;
  beq lbl_8023c2d8;
  li r4, 1;
lbl_8023c2d8:
  mr r5, r31;
  li r3, 3;
  bl unk_80240358;
  lwz r12, 0x10(r3);
  addi r4, r31, 0xd0;
  lwz r12, 0x10(r12);
  mtctr r12;
  bctrl;
  b lbl_8023c314;
lbl_8023c2fc:
  lhz r0, 0xcc(r3);
  rlwinm. r0, r0, 0, 0x1d, 0x1d;
  beq lbl_8023c314;
  mr r4, r31;
  li r3, 3;
  bl unk_80240844;
lbl_8023c314:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_8023c328
// PAL: 0x8023c328..0x8023c394
MARK_BINARY_BLOB(unk_8023c328, 0x8023c328, 0x8023c394);
asm UNKNOWN_FUNCTION(unk_8023c328) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  addic. r0, r1, 9;
  beq lbl_8023c350;
  slwi r0, r5, 2;
  lwz r7, 0xc8(r3);
  subf r0, r5, r0;
  lbzx r0, r7, r0;
  stb r0, 9(r1);
lbl_8023c350:
  addic. r0, r1, 8;
  beq lbl_8023c370;
  slwi r0, r5, 2;
  lwz r3, 0xc8(r3);
  subf r0, r5, r0;
  add r3, r3, r0;
  lbz r0, 1(r3);
  stb r0, 8(r1);
lbl_8023c370:
  lbz r0, 9(r1);
  mr r3, r4;
  add r0, r0, r6;
  clrlwi r4, r0, 0x18;
  bl SetPriorityDrawOpa__Q34nw4r3g3d6ScnObjFi;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_8023c394
// PAL: 0x8023c394..0x8023c400
MARK_BINARY_BLOB(unk_8023c394, 0x8023c394, 0x8023c400);
asm UNKNOWN_FUNCTION(unk_8023c394) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  addic. r0, r1, 9;
  beq lbl_8023c3bc;
  slwi r0, r5, 2;
  lwz r7, 0xc8(r3);
  subf r0, r5, r0;
  lbzx r0, r7, r0;
  stb r0, 9(r1);
lbl_8023c3bc:
  addic. r0, r1, 8;
  beq lbl_8023c3dc;
  slwi r0, r5, 2;
  lwz r3, 0xc8(r3);
  subf r0, r5, r0;
  add r3, r3, r0;
  lbz r0, 1(r3);
  stb r0, 8(r1);
lbl_8023c3dc:
  lbz r0, 9(r1);
  mr r3, r4;
  add r0, r0, r6;
  clrlwi r4, r0, 0x18;
  bl SetPriorityDrawXlu__Q34nw4r3g3d6ScnObjFi;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_8023c400
// PAL: 0x8023c400..0x8023c49c
MARK_BINARY_BLOB(unk_8023c400, 0x8023c400, 0x8023c49c);
asm UNKNOWN_FUNCTION(unk_8023c400) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  addic. r0, r1, 9;
  beq lbl_8023c428;
  slwi r0, r5, 2;
  lwz r8, 0xc8(r3);
  subf r0, r5, r0;
  lbzx r0, r8, r0;
  stb r0, 9(r1);
lbl_8023c428:
  addic. r0, r1, 8;
  beq lbl_8023c448;
  slwi r0, r5, 2;
  lwz r8, 0xc8(r3);
  subf r0, r5, r0;
  add r8, r8, r0;
  lbz r0, 1(r8);
  stb r0, 8(r1);
lbl_8023c448:
  slwi r0, r5, 2;
  lwz r3, 0xc8(r3);
  subf r0, r5, r0;
  lbz r8, 9(r1);
  add r5, r3, r0;
  mr r3, r4;
  add r0, r8, r6;
  lbz r6, 2(r5);
  mr r4, r7;
  clrlwi r5, r0, 0x18;
  bl unk_8022a164;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  lwz r3, 0xc4(r3);
  lwz r3, 0x14(r3);
  cmpwi r3, 0;
  beqlr;
  b unk_8021ebc8;
  blr;
  // clang-format on
}

// Symbol: unk_8023c49c
// PAL: 0x8023c49c..0x8023c694
MARK_BINARY_BLOB(unk_8023c49c, 0x8023c49c, 0x8023c694);
asm UNKNOWN_FUNCTION(unk_8023c49c) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  stw r30, 8(r1);
  bl unk_8023ccd4;
  lwz r3, 0xc4(r31);
  lwz r4, 0x10(r3);
  cmpwi r4, 0;
  beq lbl_8023c524;
  lhz r0, 0xcc(r31);
  clrlwi. r0, r0, 0x1f;
  beq lbl_8023c518;
  lwz r3, 0x14(r3);
  cmpwi r3, 0;
  beq lbl_8023c508;
  lbz r0, 0(r3);
  clrlwi. r0, r0, 0x1f;
  beq lbl_8023c508;
  lhz r0, 0x18(r3);
  rlwinm. r0, r0, 0, 0x1d, 0x1d;
  bne lbl_8023c508;
  lhz r0, 0x18(r4);
  ori r0, r0, 8;
  sth r0, 0x18(r4);
  b lbl_8023c524;
lbl_8023c508:
  lhz r0, 0x18(r4);
  rlwinm r0, r0, 0, 0x1d, 0x1b;
  sth r0, 0x18(r4);
  b lbl_8023c524;
lbl_8023c518:
  lhz r0, 0x18(r4);
  rlwinm r0, r0, 0, 0x1d, 0x1b;
  sth r0, 0x18(r4);
lbl_8023c524:
  lis r3, 0x8038;
  addi r4, r31, 0x48;
  addi r3, r3, 0x4418;
  bl unk_8023d840;
  li r30, 0;
  b lbl_8023c558;
lbl_8023c53c:
  lwz r3, 0xc4(r31);
  rlwinm r0, r30, 2, 0xe, 0x1d;
  lwzx r3, r3, r0;
  cmpwi r3, 0;
  beq lbl_8023c554;
  bl unk_8021c4bc;
lbl_8023c554:
  addi r30, r30, 1;
lbl_8023c558:
  lwz r12, 0xb4(r31);
  mr r3, r31;
  lwz r12, 0x4c(r12);
  mtctr r12;
  bctrl;
  clrlwi r3, r3, 0x10;
  clrlwi r0, r30, 0x10;
  cmplw r0, r3;
  blt lbl_8023c53c;
  lwz r3, 0xc4(r31);
  lwz r3, 0(r3);
  cmpwi r3, 0;
  beq lbl_8023c5a8;
  lwz r0, 0x20(r3);
  addi r5, r2, -24452;
  addi r3, r3, 8;
  li r4, 2;
  lbzx r5, r5, r0;
  li r6, 0;
  bl unk_8022a164;
lbl_8023c5a8:
  lwz r3, 0xc4(r31);
  li r4, 0;
  lwz r5, 8(r3);
  cmpwi r5, 0;
  beq lbl_8023c5cc;
  lbz r0, 0(r5);
  clrlwi. r0, r0, 0x1f;
  beq lbl_8023c5cc;
  li r4, 1;
lbl_8023c5cc:
  lwz r5, 4(r3);
  cmpwi r5, 0;
  beq lbl_8023c618;
  cmpwi r4, 0;
  li r3, 0;
  beq lbl_8023c5f4;
  lhz r0, 0xcc(r31);
  rlwinm. r0, r0, 0, 0x1e, 0x1e;
  beq lbl_8023c5f4;
  li r3, 1;
lbl_8023c5f4:
  cmpwi r3, 0;
  beq lbl_8023c60c;
  lhz r0, 0x14(r5);
  ori r0, r0, 0x10;
  sth r0, 0x14(r5);
  b lbl_8023c618;
lbl_8023c60c:
  lhz r0, 0x14(r5);
  rlwinm r0, r0, 0, 0x1c, 0x1a;
  sth r0, 0x14(r5);
lbl_8023c618:
  cmpwi r4, 0;
  beq lbl_8023c650;
  lhz r0, 0xcc(r31);
  lwz r3, 0xc4(r31);
  rlwinm. r0, r0, 0, 0x1e, 0x1e;
  lwz r3, 8(r3);
  bne lbl_8023c644;
  lhz r0, 0x14(r3);
  ori r0, r0, 4;
  sth r0, 0x14(r3);
  b lbl_8023c650;
lbl_8023c644:
  lhz r0, 0x14(r3);
  rlwinm r0, r0, 0, 0x1e, 0x1c;
  sth r0, 0x14(r3);
lbl_8023c650:
  lhz r3, 0xcc(r31);
  lwz r0, -0x6c50(r13);
  rlwinm. r3, r3, 0, 0x1c, 0x1c;
  rlwinm r3, r0, 0, 0x1d, 0x1b;
  beq lbl_8023c668;
  ori r3, r0, 8;
lbl_8023c668:
  stw r3, -0x6c50(r13);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  addi r3, r3, -184;
  b unk_8023ba18;
  addi r3, r3, -184;
  b unk_8023c280;
  // clang-format on
}
