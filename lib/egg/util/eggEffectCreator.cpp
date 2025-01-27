#include "eggEffectCreator.hpp"

extern "C" {
// PAL: 0x80027130
extern UNKNOWN_FUNCTION(unk_80027130);
// PAL: 0x80027310
extern UNKNOWN_FUNCTION(unk_80027310);
// PAL: 0x800275a0
extern UNKNOWN_FUNCTION(unk_800275a0);
// PAL: 0x80027630
extern UNKNOWN_FUNCTION(unk_80027630);
// PAL: 0x800276c0
extern UNKNOWN_FUNCTION(unk_800276c0);
// PAL: 0x80035940
extern UNKNOWN_FUNCTION(unk_80035940);
// PAL: 0x80035df0
extern UNKNOWN_FUNCTION(unk_80035df0);
// PAL: 0x800365d0
extern UNKNOWN_FUNCTION(unk_800365d0);
// PAL: 0x8021a0f0
extern UNKNOWN_FUNCTION(__ct__Q23EGG8DisposerFv);
// PAL: 0x8021a144
extern UNKNOWN_FUNCTION(__dt__Q23EGG8DisposerFv);
// PAL: 0x8022501c
extern UNKNOWN_FUNCTION(unk_8022501c);
// PAL: 0x8022502c
extern UNKNOWN_FUNCTION(unk_8022502c);
}

extern void* EffectCreator_Vt[];
void* EffectCreator_Vt[] = {
    nullptr,
    nullptr,
    EffectCreator_destroy,
    EffectCreator_stopAllEffect,
    EffectCreator_calcAll,
    EffectCreator_calcGroup,
    EffectCreator_draw,
    EffectCreator_createEffect,
};

// Symbol: EffectCreator_construct
// PAL: 0x80224348..0x802243b4
MARK_BINARY_BLOB(EffectCreator_construct, 0x80224348, 0x802243b4);
asm UNKNOWN_FUNCTION(EffectCreator_construct) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  bl __ct__Q23EGG8DisposerFv;
  lis r3, EffectCreator_Vt@ha;
  slwi r0, r31, 2;
  addi r3, r3, EffectCreator_Vt@l;
  stw r3, 0(r30);
  stw r31, 0x10(r30);
  stw r0, 0x14(r30);
  lwz r3, -0x5dd0(r13);
  cmpwi r3, 0;
  beq lbl_80224398;
  mr r4, r30;
  mr r5, r31;
  bl unk_8022501c;
lbl_80224398:
  mr r3, r30;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: EffectCreator_destroy
// PAL: 0x802243b4..0x8022443c
MARK_BINARY_BLOB(EffectCreator_destroy, 0x802243b4, 0x8022443c);
asm UNKNOWN_FUNCTION(EffectCreator_destroy) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  beq lbl_80224420;
  lis r12, EffectCreator_Vt@ha;
  addi r12, r12, EffectCreator_Vt@l;
  stw r12, 0(r3);
  lwz r12, 0xc(r12);
  mtctr r12;
  bctrl;
  lwz r3, -0x5dd0(r13);
  cmpwi r3, 0;
  beq lbl_80224404;
  lwz r4, 0x10(r30);
  bl unk_8022502c;
lbl_80224404:
  mr r3, r30;
  li r4, 0;
  bl __dt__Q23EGG8DisposerFv;
  cmpwi r31, 0;
  ble lbl_80224420;
  mr r3, r30;
  bl __dl__FPv;
lbl_80224420:
  mr r3, r30;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: EffectCreator_stopAllEffect
// PAL: 0x8022443c..0x802244b4
MARK_BINARY_BLOB(EffectCreator_stopAllEffect, 0x8022443c, 0x802244b4);
asm UNKNOWN_FUNCTION(EffectCreator_stopAllEffect) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  stw r28, 0x10(r1);
  mr r28, r3;
  bl unk_80027130;
  mr r31, r3;
  li r30, 0;
lbl_80224468:
  lwz r0, 0x14(r28);
  mr r3, r31;
  or r29, r0, r30;
  mr r4, r29;
  bl unk_800275a0;
  mr r3, r31;
  mr r4, r29;
  bl unk_80027630;
  addi r30, r30, 1;
  cmpwi r30, 4;
  blt lbl_80224468;
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

// Symbol: EffectCreator_calcAll
// PAL: 0x802244b4..0x8022450c
MARK_BINARY_BLOB(EffectCreator_calcAll, 0x802244b4, 0x8022450c);
asm UNKNOWN_FUNCTION(EffectCreator_calcAll) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  bl unk_80027130;
  li r31, 0;
lbl_802244d4:
  lwz r0, 0x14(r30);
  mr r3, r30;
  li r5, 0;
  or r4, r0, r31;
  bl unk_8022464c;
  addi r31, r31, 1;
  cmpwi r31, 4;
  blt lbl_802244d4;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: EffectCreator_calcGroup
// PAL: 0x8022450c..0x80224558
MARK_BINARY_BLOB(EffectCreator_calcGroup, 0x8022450c, 0x80224558);
asm UNKNOWN_FUNCTION(EffectCreator_calcGroup) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  bl unk_80027130;
  lwz r0, 0x14(r30);
  mr r3, r30;
  li r5, 0;
  or r4, r0, r31;
  bl unk_8022464c;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: EffectCreator_draw
// PAL: 0x80224558..0x802245ac
MARK_BINARY_BLOB(EffectCreator_draw, 0x80224558, 0x802245ac);
asm UNKNOWN_FUNCTION(EffectCreator_draw) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r5;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  bl unk_80027130;
  lwz r0, 0x14(r29);
  mr r4, r30;
  or r5, r0, r31;
  bl unk_800276c0;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: EffectCreator_createEffect
// PAL: 0x802245ac..0x8022464c
MARK_BINARY_BLOB(EffectCreator_createEffect, 0x802245ac, 0x8022464c);
asm UNKNOWN_FUNCTION(EffectCreator_createEffect) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r3;
  stw r30, 0x18(r1);
  mr r30, r4;
  bl unk_80035940;
  mr r4, r3;
  mr r5, r30;
  addi r3, r1, 8;
  li r6, 0;
  bl unk_80035df0;
  lwz r3, 8(r1);
  lwz r31, 0x14(r31);
  lbz r0, 0x96(r3);
  lbz r3, 0x97(r3);
  rlwimi r3, r0, 8, 0x10, 0x17;
  rlwinm. r0, r3, 0, 0x10, 0x10;
  beq lbl_80224614;
  clrlwi. r0, r3, 0x1f;
  beq lbl_8022460c;
  ori r31, r31, 3;
  b lbl_80224620;
lbl_8022460c:
  ori r31, r31, 2;
  b lbl_80224620;
lbl_80224614:
  clrlwi. r0, r3, 0x1f;
  beq lbl_80224620;
  ori r31, r31, 1;
lbl_80224620:
  bl unk_80027130;
  mr r4, r30;
  mr r5, r31;
  li r6, 0;
  bl unk_80027310;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_8022464c
// PAL: 0x8022464c..0x802246ec
MARK_BINARY_BLOB(unk_8022464c, 0x8022464c, 0x802246ec);
asm UNKNOWN_FUNCTION(unk_8022464c) {
  // clang-format off
  nofralloc;
  stwu r1, -0x1020(r1);
  mflr r0;
  stw r0, 0x1024(r1);
  stw r31, 0x101c(r1);
  stw r30, 0x1018(r1);
  stw r29, 0x1014(r1);
  mr r29, r4;
  stw r28, 0x1010(r1);
  mr r28, r5;
  bl unk_80027130;
  addis r3, r3, 1;
  addi r4, r1, 8;
  mulli r0, r29, 0x1c;
  lwz r3, -0x3fe8(r3);
  add r3, r3, r0;
  lhz r5, 8(r3);
  bl unk_800365d0;
  addi r30, r1, 8;
  clrlwi r31, r3, 0x10;
  li r29, 0;
  b lbl_802246c0;
lbl_802246a0:
  rlwinm r0, r29, 2, 0xe, 0x1d;
  mr r4, r28;
  lwzx r3, r30, r0;
  lwz r12, 0x1c(r3);
  lwz r12, 0x18(r12);
  mtctr r12;
  bctrl;
  addi r29, r29, 1;
lbl_802246c0:
  clrlwi r0, r29, 0x10;
  cmplw r0, r31;
  blt lbl_802246a0;
  lwz r0, 0x1024(r1);
  lwz r31, 0x101c(r1);
  lwz r30, 0x1018(r1);
  lwz r29, 0x1014(r1);
  lwz r28, 0x1010(r1);
  mtlr r0;
  addi r1, r1, 0x1020;
  blr;
  // clang-format on
}
