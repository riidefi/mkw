#include "alloc.h"

#include <rvl/os/osInterrupt.h>

#include "vpb.h"

u32 _unk_802f40c0[32];
u32 _unk_802f4140[32];

u32 _unk_80386490;

// Symbol: __AXGetStackHead
// PAL: 0x80124edc..0x80124ef0
MARK_BINARY_BLOB(__AXGetStackHead, 0x80124edc, 0x80124ef0);
asm UNKNOWN_FUNCTION(__AXGetStackHead) {
  // clang-format off
  nofralloc;
  lis r4, _unk_802f40c0@ha;
  slwi r0, r3, 2;
  la r4, _unk_802f40c0@l(r4);
  lwzx r3, r4, r0;
  blr;
  // clang-format on
}

// Symbol: __AXServiceCallbackStack
// PAL: 0x80124ef0..0x80124f9c
MARK_BINARY_BLOB(__AXServiceCallbackStack, 0x80124ef0, 0x80124f9c);
asm UNKNOWN_FUNCTION(__AXServiceCallbackStack) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  lwz r29, _unk_80386490;
  cmpwi r29, 0;
  beq lbl_80124f1c;
  lwz r0, 8(r29);
  stw r0, _unk_80386490;
lbl_80124f1c:
  lis r30, _unk_802f40c0@ha;
  li r31, 0;
  b lbl_80124f78;
lbl_80124f28:
  lwz r0, 0xc(r29);
  cmpwi r0, 0;
  beq lbl_80124f64;
  lwz r12, 0x10(r29);
  cmpwi r12, 0;
  beq lbl_80124f4c;
  mr r3, r29;
  mtctr r12;
  bctrl;
lbl_80124f4c:
  mr r3, r29;
  bl __AXRemoveFromStack;
  lwz r0, _unk_802f40c0@l(r30);
  stw r0, 0(r29);
  stw r29, _unk_802f40c0@l(r30);
  stw r31, 0xc(r29);
lbl_80124f64:
  lwz r29, _unk_80386490;
  cmpwi r29, 0;
  beq lbl_80124f78;
  lwz r0, 8(r29);
  stw r0, _unk_80386490;
lbl_80124f78:
  cmpwi r29, 0;
  bne lbl_80124f28;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: __AXAllocInit
// PAL: 0x80124f9c..0x8012504c
MARK_BINARY_BLOB(__AXAllocInit, 0x80124f9c, 0x8012504c);
asm void __AXAllocInit() {
  // clang-format off
  nofralloc;
  li r3, 0;
  lis r4, _unk_802f4140@ha;
  lis r5, _unk_802f40c0@ha;
  li r0, 2;
  stw r3, _unk_80386490;
  la r4, _unk_802f4140@l(r4);
  la r5, _unk_802f40c0@l(r5);
  mtctr r0;
lbl_80124fbc:
  stw r3, 0(r4);
  stw r3, 0(r5);
  stw r3, 4(r4);
  stw r3, 4(r5);
  stw r3, 8(r4);
  stw r3, 8(r5);
  stw r3, 0xc(r4);
  stw r3, 0xc(r5);
  stw r3, 0x10(r4);
  stw r3, 0x10(r5);
  stw r3, 0x14(r4);
  stw r3, 0x14(r5);
  stw r3, 0x18(r4);
  stw r3, 0x18(r5);
  stw r3, 0x1c(r4);
  stw r3, 0x1c(r5);
  stw r3, 0x20(r4);
  stw r3, 0x20(r5);
  stw r3, 0x24(r4);
  stw r3, 0x24(r5);
  stw r3, 0x28(r4);
  stw r3, 0x28(r5);
  stw r3, 0x2c(r4);
  stw r3, 0x2c(r5);
  stw r3, 0x30(r4);
  stw r3, 0x30(r5);
  stw r3, 0x34(r4);
  stw r3, 0x34(r5);
  stw r3, 0x38(r4);
  stw r3, 0x38(r5);
  stw r3, 0x3c(r4);
  addi r4, r4, 0x40;
  stw r3, 0x3c(r5);
  addi r5, r5, 0x40;
  bdnz lbl_80124fbc;
  blr;
  // clang-format on
}

// Symbol: __AXPushFreeStack
// PAL: 0x8012504c..0x80125068
MARK_BINARY_BLOB(__AXPushFreeStack, 0x8012504c, 0x80125068);
asm UNKNOWN_FUNCTION(__AXPushFreeStack) {
  // clang-format off
  nofralloc;
  lis r5, _unk_802f40c0@ha;
  li r0, 0;
  lwz r4, _unk_802f40c0@l(r5);
  stw r4, 0(r3);
  stw r3, _unk_802f40c0@l(r5);
  stw r0, 0xc(r3);
  blr;
  // clang-format on
}

// Symbol: __AXPushCallbackStack
// PAL: 0x80125068..0x80125078
MARK_BINARY_BLOB(__AXPushCallbackStack, 0x80125068, 0x80125078);
asm UNKNOWN_FUNCTION(__AXPushCallbackStack) {
  // clang-format off
  nofralloc;
  lwz r0, _unk_80386490;
  stw r0, 8(r3);
  stw r3, _unk_80386490;
  blr;
  // clang-format on
}

// Symbol: __AXRemoveFromStack
// PAL: 0x80125078..0x801250fc
MARK_BINARY_BLOB(__AXRemoveFromStack, 0x80125078, 0x801250fc);
asm UNKNOWN_FUNCTION(__AXRemoveFromStack) {
  // clang-format off
  nofralloc;
  lwz r0, 0xc(r3);
  lis r5, _unk_802f40c0@ha;
  lis r4, _unk_802f4140@ha;
  slwi r6, r0, 2;
  la r5, _unk_802f40c0@l(r5);
  la r4, _unk_802f4140@l(r4);
  lwzx r0, r5, r6;
  lwzx r7, r4, r6;
  cmplw r0, r7;
  bne lbl_801250b0;
  li r0, 0;
  stwx r0, r4, r6;
  stwx r0, r5, r6;
  blr;
lbl_801250b0:
  cmplw r3, r0;
  bne lbl_801250cc;
  lwz r3, 0(r3);
  li r0, 0;
  stwx r3, r5, r6;
  stw r0, 4(r3);
  blr;
lbl_801250cc:
  cmplw r3, r7;
  bne lbl_801250e8;
  lwz r3, 4(r3);
  li r0, 0;
  stwx r3, r4, r6;
  stw r0, 0(r3);
  blr;
lbl_801250e8:
  lwz r4, 4(r3);
  lwz r3, 0(r3);
  stw r3, 0(r4);
  stw r4, 4(r3);
  blr;
  // clang-format on
}

// Symbol: AXFreeVoice
// PAL: 0x801250fc..0x80125178
MARK_BINARY_BLOB(AXFreeVoice, 0x801250fc, 0x80125178);
asm UNKNOWN_FUNCTION(AXFreeVoice) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  bl OSDisableInterrupts;
  mr r31, r3;
  mr r3, r30;
  bl __AXRemoveFromStack;
  lhz r0, 0x38(r30);
  cmplwi r0, 1;
  bne lbl_80125138;
  li r0, 1;
  stw r0, 0x20(r30);
lbl_80125138:
  mr r3, r30;
  bl __AXSetPBDefault;
  lis r5, _unk_802f40c0@ha;
  li r0, 0;
  lwz r4, _unk_802f40c0@l(r5);
  mr r3, r31;
  stw r4, 0(r30);
  stw r30, _unk_802f40c0@l(r5);
  stw r0, 0xc(r30);
  bl OSRestoreInterrupts;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: AXAcquireVoice
// PAL: 0x80125178..0x801252f8
MARK_BINARY_BLOB(AXAcquireVoice, 0x80125178, 0x801252f8);
asm UNKNOWN_FUNCTION(AXAcquireVoice) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  mr r27, r3;
  mr r28, r4;
  mr r29, r5;
  bl OSDisableInterrupts;
  lis r4, _unk_802f40c0@ha;
  mr r31, r3;
  lwz r30, _unk_802f40c0@l(r4);
  cmpwi r30, 0;
  beq lbl_801251b8;
  lwz r0, 0(r30);
  stw r0, _unk_802f40c0@l(r4);
lbl_801251b8:
  cmpwi r30, 0;
  bne lbl_80125274;
  lis r3, _unk_802f40c0@ha;
  lis r4, _unk_802f4140@ha;
  la r3, _unk_802f40c0@l(r3);
  addi r0, r27, -1;
  la r4, _unk_802f4140@l(r4);
  addi r5, r3, 4;
  li r3, 0;
  addi r6, r4, 4;
  mtctr r0;
  cmplwi r27, 1;
  ble lbl_80125274;
lbl_801251ec:
  lwz r0, 0(r5);
  li r30, 0;
  cmpwi r0, 0;
  beq lbl_80125230;
  lwz r7, 0(r6);
  cmplw r0, r7;
  bne lbl_80125218;
  stw r3, 0(r6);
  mr r30, r0;
  stw r3, 0(r5);
  b lbl_80125230;
lbl_80125218:
  cmpwi r7, 0;
  beq lbl_80125230;
  lwz r4, 4(r7);
  mr r30, r7;
  stw r4, 0(r6);
  stw r3, 0(r4);
lbl_80125230:
  cmpwi r30, 0;
  beq lbl_80125268;
  lhz r0, 0x38(r30);
  cmplwi r0, 1;
  bne lbl_8012524c;
  li r0, 1;
  stw r0, 0x20(r30);
lbl_8012524c:
  lwz r12, 0x10(r30);
  cmpwi r12, 0;
  beq lbl_80125274;
  mr r3, r30;
  mtctr r12;
  bctrl;
  b lbl_80125274;
lbl_80125268:
  addi r5, r5, 4;
  addi r6, r6, 4;
  bdnz lbl_801251ec;
lbl_80125274:
  cmpwi r30, 0;
  beq lbl_801252d4;
  lis r4, _unk_802f40c0@ha;
  slwi r5, r27, 2;
  la r4, _unk_802f40c0@l(r4);
  li r0, 0;
  lwzx r3, r4, r5;
  stw r3, 0(r30);
  cmpwi r3, 0;
  stw r0, 4(r30);
  beq lbl_801252b0;
  lwzx r3, r4, r5;
  stw r30, 4(r3);
  stwx r30, r4, r5;
  b lbl_801252c0;
lbl_801252b0:
  lis r3, _unk_802f4140@ha;
  stwx r30, r4, r5;
  la r3, _unk_802f4140@l(r3);
  stwx r30, r3, r5;
lbl_801252c0:
  stw r27, 0xc(r30);
  mr r3, r30;
  stw r28, 0x10(r30);
  stw r29, 0x14(r30);
  bl __AXSetPBDefault;
lbl_801252d4:
  mr r3, r31;
  bl OSRestoreInterrupts;
  addi r11, r1, 0x20;
  mr r3, r30;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: AXSetVoicePriority
// PAL: 0x801252f8..0x80125394
MARK_BINARY_BLOB(AXSetVoicePriority, 0x801252f8, 0x80125394);
asm UNKNOWN_FUNCTION(AXSetVoicePriority) {
  // clang-format off
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  bl OSDisableInterrupts;
  mr r31, r3;
  mr r3, r29;
  bl __AXRemoveFromStack;
  lis r4, _unk_802f40c0@ha;
  slwi r5, r30, 2;
  la r4, _unk_802f40c0@l(r4);
  li r0, 0;
  lwzx r3, r4, r5;
  cmpwi r3, 0;
  stw r3, 0(r29);
  stw r0, 4(r29);
  beq lbl_8012535c;
  lwzx r3, r4, r5;
  stw r29, 4(r3);
  stwx r29, r4, r5;
  b lbl_8012536c;
lbl_8012535c:
  lis r3, _unk_802f4140@ha;
  stwx r29, r4, r5;
  la r3, _unk_802f4140@l(r3);
  stwx r29, r3, r5;
lbl_8012536c:
  stw r30, 0xc(r29);
  mr r3, r31;
  bl OSRestoreInterrupts;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}
