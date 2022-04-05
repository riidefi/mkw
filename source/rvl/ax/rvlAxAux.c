#include "axAux.h"

#include <string.h>

#include <rvl/os/osCache.h>
#include <rvl/os/osInterrupt.h>

u32 _unk_803864dc;
u32 _unk_803864d8;
u32 _unk_803864d4;
u32 _unk_803864d0;
u32 _unk_803864cc;
u32 _unk_803864c8;
u32 _unk_803864c4;
u32 _unk_803864c0;
u32 _unk_803864bc;
u32 _unk_803864b8;
u32 _unk_803864b4;
u32 _unk_803864b0;
u32 _unk_803864ac;
u32 _unk_803864a8;
u32 _unk_803864a4;
u32 _unk_803864a0;
u32 _unk_8038649c;
u32 _unk_80386498;

extern u32 _unk_803864f0;

// Symbol: __AXAuxInit
// PAL: 0x80125394..0x801254a8
MARK_BINARY_BLOB(__AXAuxInit, 0x80125394, 0x801254a8);
asm UNKNOWN_FUNCTION(__AXAuxInit) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r6, 0x802f;
  li r5, 0;
  stw r0, 0x14(r1);
  addi r6, r6, 0x41c0;
  li r4, 1;
  li r3, 2;
  li r0, 0x20;
  stw r5, _unk_803864d0;
  addi r7, r6, 0;
  addi r8, r6, 0x1200;
  stw r5, _unk_803864cc;
  addi r6, r6, 0x2400;
  stw r5, _unk_803864c8;
  stw r5, _unk_803864c4;
  stw r5, _unk_803864c0;
  stw r5, _unk_803864bc;
  stw r5, _unk_803864a0;
  stw r4, _unk_8038649c;
  stw r3, _unk_80386498;
  mtctr r0;
lbl_801253ec:
  stw r5, 0(r7);
  stw r5, 0(r8);
  stw r5, 0(r6);
  stw r5, 4(r7);
  stw r5, 4(r8);
  stw r5, 4(r6);
  stw r5, 8(r7);
  stw r5, 8(r8);
  stw r5, 8(r6);
  stw r5, 0xc(r7);
  stw r5, 0xc(r8);
  stw r5, 0xc(r6);
  stw r5, 0x10(r7);
  stw r5, 0x10(r8);
  stw r5, 0x10(r6);
  stw r5, 0x14(r7);
  stw r5, 0x14(r8);
  stw r5, 0x14(r6);
  stw r5, 0x18(r7);
  stw r5, 0x18(r8);
  stw r5, 0x18(r6);
  stw r5, 0x1c(r7);
  stw r5, 0x1c(r8);
  stw r5, 0x1c(r6);
  stw r5, 0x20(r7);
  addi r7, r7, 0x24;
  stw r5, 0x20(r8);
  addi r8, r8, 0x24;
  stw r5, 0x20(r6);
  addi r6, r6, 0x24;
  bdnz lbl_801253ec;
  la r3, _unk_803864dc;
  li r4, 0;
  li r5, 3;
  bl memset;
  la r3, _unk_803864d8;
  li r4, 0;
  li r5, 3;
  bl memset;
  la r3, _unk_803864d4;
  li r4, 0;
  li r5, 3;
  bl memset;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __AXGetAuxAInput
// PAL: 0x801254a8..0x801254dc
MARK_BINARY_BLOB(__AXGetAuxAInput, 0x801254a8, 0x801254dc);
asm UNKNOWN_FUNCTION(__AXGetAuxAInput) {
  // clang-format off
  nofralloc;
  lwz r0, _unk_803864d0;
  cmpwi r0, 0;
  beq lbl_801254d0;
  lwz r0, _unk_803864a0;
  lis r4, 0x802f;
  addi r4, r4, 0x41c0;
  mulli r0, r0, 0x600;
  add r0, r4, r0;
  stw r0, 0(r3);
  blr;
lbl_801254d0:
  li r0, 0;
  stw r0, 0(r3);
  blr;
  // clang-format on
}

// Symbol: __AXGetAuxAOutput
// PAL: 0x801254dc..0x801254f8
MARK_BINARY_BLOB(__AXGetAuxAOutput, 0x801254dc, 0x801254f8);
asm UNKNOWN_FUNCTION(__AXGetAuxAOutput) {
  // clang-format off
  nofralloc;
  lwz r0, _unk_8038649c;
  lis r4, 0x802f;
  addi r4, r4, 0x41c0;
  mulli r0, r0, 0x600;
  add r0, r4, r0;
  stw r0, 0(r3);
  blr;
  // clang-format on
}

// Symbol: __AXGetAuxAInputDpl2
// PAL: 0x801254f8..0x80125518
MARK_BINARY_BLOB(__AXGetAuxAInputDpl2, 0x801254f8, 0x80125518);
asm UNKNOWN_FUNCTION(__AXGetAuxAInputDpl2) {
  // clang-format off
  nofralloc;
  lwz r0, _unk_803864a0;
  lis r4, 0x802f;
  addi r4, r4, 0x41c0;
  mulli r0, r0, 0x600;
  add r4, r4, r0;
  addi r0, r4, 0x480;
  stw r0, 0(r3);
  blr;
  // clang-format on
}

// Symbol: __AXGetAuxAOutputDpl2R
// PAL: 0x80125518..0x80125538
MARK_BINARY_BLOB(__AXGetAuxAOutputDpl2R, 0x80125518, 0x80125538);
asm UNKNOWN_FUNCTION(__AXGetAuxAOutputDpl2R) {
  // clang-format off
  nofralloc;
  lwz r0, _unk_8038649c;
  lis r4, 0x802f;
  addi r4, r4, 0x41c0;
  mulli r0, r0, 0x600;
  add r4, r4, r0;
  addi r0, r4, 0x180;
  stw r0, 0(r3);
  blr;
  // clang-format on
}

// Symbol: __AXGetAuxAOutputDpl2Ls
// PAL: 0x80125538..0x80125558
MARK_BINARY_BLOB(__AXGetAuxAOutputDpl2Ls, 0x80125538, 0x80125558);
asm UNKNOWN_FUNCTION(__AXGetAuxAOutputDpl2Ls) {
  // clang-format off
  nofralloc;
  lwz r0, _unk_8038649c;
  lis r4, 0x802f;
  addi r4, r4, 0x41c0;
  mulli r0, r0, 0x600;
  add r4, r4, r0;
  addi r0, r4, 0x300;
  stw r0, 0(r3);
  blr;
  // clang-format on
}

// Symbol: __AXGetAuxAOutputDpl2Rs
// PAL: 0x80125558..0x80125578
MARK_BINARY_BLOB(__AXGetAuxAOutputDpl2Rs, 0x80125558, 0x80125578);
asm UNKNOWN_FUNCTION(__AXGetAuxAOutputDpl2Rs) {
  // clang-format off
  nofralloc;
  lwz r0, _unk_8038649c;
  lis r4, 0x802f;
  addi r4, r4, 0x41c0;
  mulli r0, r0, 0x600;
  add r4, r4, r0;
  addi r0, r4, 0x480;
  stw r0, 0(r3);
  blr;
  // clang-format on
}

// Symbol: __AXGetAuxBInput
// PAL: 0x80125578..0x801255ac
MARK_BINARY_BLOB(__AXGetAuxBInput, 0x80125578, 0x801255ac);
asm UNKNOWN_FUNCTION(__AXGetAuxBInput) {
  // clang-format off
  nofralloc;
  lwz r0, _unk_803864cc;
  cmpwi r0, 0;
  beq lbl_801255a0;
  lwz r0, _unk_803864a0;
  lis r4, 0x802f;
  addi r4, r4, 0x53c0;
  mulli r0, r0, 0x600;
  add r0, r4, r0;
  stw r0, 0(r3);
  blr;
lbl_801255a0:
  li r0, 0;
  stw r0, 0(r3);
  blr;
  // clang-format on
}

// Symbol: __AXGetAuxBOutput
// PAL: 0x801255ac..0x801255c8
MARK_BINARY_BLOB(__AXGetAuxBOutput, 0x801255ac, 0x801255c8);
asm UNKNOWN_FUNCTION(__AXGetAuxBOutput) {
  // clang-format off
  nofralloc;
  lwz r0, _unk_8038649c;
  lis r4, 0x802f;
  addi r4, r4, 0x53c0;
  mulli r0, r0, 0x600;
  add r0, r4, r0;
  stw r0, 0(r3);
  blr;
  // clang-format on
}

// Symbol: __AXGetAuxBInputDpl2
// PAL: 0x801255c8..0x801255e8
MARK_BINARY_BLOB(__AXGetAuxBInputDpl2, 0x801255c8, 0x801255e8);
asm UNKNOWN_FUNCTION(__AXGetAuxBInputDpl2) {
  // clang-format off
  nofralloc;
  lwz r0, _unk_803864a0;
  lis r4, 0x802f;
  addi r4, r4, 0x53c0;
  mulli r0, r0, 0x600;
  add r4, r4, r0;
  addi r0, r4, 0x480;
  stw r0, 0(r3);
  blr;
  // clang-format on
}

// Symbol: __AXGetAuxBOutputDpl2R
// PAL: 0x801255e8..0x80125608
MARK_BINARY_BLOB(__AXGetAuxBOutputDpl2R, 0x801255e8, 0x80125608);
asm UNKNOWN_FUNCTION(__AXGetAuxBOutputDpl2R) {
  // clang-format off
  nofralloc;
  lwz r0, _unk_8038649c;
  lis r4, 0x802f;
  addi r4, r4, 0x53c0;
  mulli r0, r0, 0x600;
  add r4, r4, r0;
  addi r0, r4, 0x180;
  stw r0, 0(r3);
  blr;
  // clang-format on
}

// Symbol: __AXGetAuxBOutputDpl2Ls
// PAL: 0x80125608..0x80125628
MARK_BINARY_BLOB(__AXGetAuxBOutputDpl2Ls, 0x80125608, 0x80125628);
asm UNKNOWN_FUNCTION(__AXGetAuxBOutputDpl2Ls) {
  // clang-format off
  nofralloc;
  lwz r0, _unk_8038649c;
  lis r4, 0x802f;
  addi r4, r4, 0x53c0;
  mulli r0, r0, 0x600;
  add r4, r4, r0;
  addi r0, r4, 0x300;
  stw r0, 0(r3);
  blr;
  // clang-format on
}

// Symbol: __AXGetAuxBOutputDpl2Rs
// PAL: 0x80125628..0x80125648
MARK_BINARY_BLOB(__AXGetAuxBOutputDpl2Rs, 0x80125628, 0x80125648);
asm UNKNOWN_FUNCTION(__AXGetAuxBOutputDpl2Rs) {
  // clang-format off
  nofralloc;
  lwz r0, _unk_8038649c;
  lis r4, 0x802f;
  addi r4, r4, 0x53c0;
  mulli r0, r0, 0x600;
  add r4, r4, r0;
  addi r0, r4, 0x480;
  stw r0, 0(r3);
  blr;
  // clang-format on
}

// Symbol: __AXGetAuxCInput
// PAL: 0x80125648..0x8012567c
MARK_BINARY_BLOB(__AXGetAuxCInput, 0x80125648, 0x8012567c);
asm UNKNOWN_FUNCTION(__AXGetAuxCInput) {
  // clang-format off
  nofralloc;
  lwz r0, _unk_803864c8;
  cmpwi r0, 0;
  beq lbl_80125670;
  lwz r0, _unk_803864a0;
  lis r4, 0x802f;
  addi r4, r4, 0x65c0;
  mulli r0, r0, 0x480;
  add r0, r4, r0;
  stw r0, 0(r3);
  blr;
lbl_80125670:
  li r0, 0;
  stw r0, 0(r3);
  blr;
  // clang-format on
}

// Symbol: __AXGetAuxCOutput
// PAL: 0x8012567c..0x80125698
MARK_BINARY_BLOB(__AXGetAuxCOutput, 0x8012567c, 0x80125698);
asm UNKNOWN_FUNCTION(__AXGetAuxCOutput) {
  // clang-format off
  nofralloc;
  lwz r0, _unk_8038649c;
  lis r4, 0x802f;
  addi r4, r4, 0x65c0;
  mulli r0, r0, 0x480;
  add r0, r4, r0;
  stw r0, 0(r3);
  blr;
  // clang-format on
}

// Symbol: __AXProcessAux
// PAL: 0x80125698..0x80125a44
MARK_BINARY_BLOB(__AXProcessAux, 0x80125698, 0x80125a44);
asm UNKNOWN_FUNCTION(__AXProcessAux) {
  // clang-format off
  nofralloc;
  stwu r1, -0x60(r1);
  mflr r0;
  stw r0, 0x64(r1);
  stw r31, 0x5c(r1);
  lis r31, 0x802f;
  addi r31, r31, 0x41c0;
  stw r30, 0x58(r1);
  addi r10, r31, 0;
  addi r6, r31, 0x1200;
  addi r5, r31, 0x2400;
  stw r29, 0x54(r1);
  lwz r7, _unk_803864a0;
  lwz r9, _unk_8038649c;
  mulli r3, r7, 0x600;
  lwz r0, _unk_803864d0;
  cmpwi r0, 0;
  add r4, r10, r3;
  add r3, r6, r3;
  stw r4, _unk_803864b8;
  mulli r8, r9, 0x600;
  stw r3, _unk_803864b0;
  mulli r4, r7, 0x480;
  add r7, r10, r8;
  add r6, r6, r8;
  stw r7, _unk_803864b4;
  mulli r3, r9, 0x480;
  add r4, r5, r4;
  stw r6, _unk_803864ac;
  add r0, r5, r3;
  stw r4, _unk_803864a8;
  stw r0, _unk_803864a4;
  beq lbl_801257c4;
  lwz r0, _unk_803864f0;
  cmplwi r0, 2;
  bne lbl_80125778;
  lwz r0, _unk_80386498;
  li r4, 0x600;
  mulli r0, r0, 0x600;
  add r3, r10, r0;
  addi r6, r3, 0x180;
  stw r3, 0x40(r1);
  addi r5, r3, 0x300;
  addi r0, r3, 0x480;
  stw r6, 0x44(r1);
  stw r5, 0x48(r1);
  stw r0, 0x4c(r1);
  bl DCInvalidateRange;
  lwz r12, _unk_803864d0;
  addi r3, r1, 0x40;
  lwz r4, _unk_803864c4;
  mtctr r12;
  bctrl;
  lwz r3, 0x40(r1);
  li r4, 0x600;
  bl DCFlushRangeNoSync;
  b lbl_80125808;
lbl_80125778:
  lwz r0, _unk_80386498;
  li r4, 0x480;
  mulli r0, r0, 0x600;
  add r3, r10, r0;
  addi r5, r3, 0x180;
  stw r3, 0x30(r1);
  addi r0, r3, 0x300;
  stw r5, 0x34(r1);
  stw r0, 0x38(r1);
  bl DCInvalidateRange;
  lwz r12, _unk_803864d0;
  addi r3, r1, 0x30;
  lwz r4, _unk_803864c4;
  mtctr r12;
  bctrl;
  lwz r3, 0x30(r1);
  li r4, 0x480;
  bl DCFlushRangeNoSync;
  b lbl_80125808;
lbl_801257c4:
  lwz r3, _unk_80386498;
  la r30, _unk_803864dc;
  lbzx r0, r30, r3;
  cmpwi r0, 0;
  beq lbl_80125808;
  mulli r0, r3, 0x600;
  li r4, 0;
  li r5, 0x600;
  add r29, r10, r0;
  mr r3, r29;
  bl memset;
  mr r3, r29;
  li r4, 0x600;
  bl DCFlushRange;
  lwz r0, _unk_80386498;
  li r3, 0;
  stbx r3, r30, r0;
lbl_80125808:
  lwz r0, _unk_803864cc;
  cmpwi r0, 0;
  beq lbl_801258c8;
  lwz r0, _unk_803864f0;
  cmplwi r0, 2;
  bne lbl_80125878;
  lwz r3, _unk_80386498;
  addi r0, r31, 0x1200;
  li r4, 0x600;
  mulli r3, r3, 0x600;
  add r3, r0, r3;
  addi r6, r3, 0x180;
  stw r3, 0x20(r1);
  addi r5, r3, 0x300;
  addi r0, r3, 0x480;
  stw r6, 0x24(r1);
  stw r5, 0x28(r1);
  stw r0, 0x2c(r1);
  bl DCInvalidateRange;
  lwz r12, _unk_803864cc;
  addi r3, r1, 0x20;
  lwz r4, _unk_803864c0;
  mtctr r12;
  bctrl;
  lwz r3, 0x20(r1);
  li r4, 0x600;
  bl DCFlushRangeNoSync;
  b lbl_80125910;
lbl_80125878:
  lwz r3, _unk_80386498;
  addi r0, r31, 0x1200;
  li r4, 0x480;
  mulli r3, r3, 0x600;
  add r3, r0, r3;
  addi r5, r3, 0x180;
  stw r3, 0x14(r1);
  addi r0, r3, 0x300;
  stw r5, 0x18(r1);
  stw r0, 0x1c(r1);
  bl DCInvalidateRange;
  lwz r12, _unk_803864cc;
  addi r3, r1, 0x14;
  lwz r4, _unk_803864c0;
  mtctr r12;
  bctrl;
  lwz r3, 0x14(r1);
  li r4, 0x480;
  bl DCFlushRangeNoSync;
  b lbl_80125910;
lbl_801258c8:
  lwz r3, _unk_80386498;
  la r30, _unk_803864d8;
  lbzx r0, r30, r3;
  cmpwi r0, 0;
  beq lbl_80125910;
  mulli r3, r3, 0x600;
  addi r0, r31, 0x1200;
  li r4, 0;
  li r5, 0x600;
  add r29, r0, r3;
  mr r3, r29;
  bl memset;
  mr r3, r29;
  li r4, 0x600;
  bl DCFlushRange;
  lwz r0, _unk_80386498;
  li r3, 0;
  stbx r3, r30, r0;
lbl_80125910:
  lwz r0, _unk_803864c8;
  cmpwi r0, 0;
  beq lbl_80125978;
  lwz r0, _unk_803864f0;
  cmplwi r0, 2;
  beq lbl_80125978;
  lwz r3, _unk_80386498;
  addi r0, r31, 0x2400;
  li r4, 0x480;
  mulli r3, r3, 0x480;
  add r3, r0, r3;
  addi r5, r3, 0x180;
  stw r3, 8(r1);
  addi r0, r3, 0x300;
  stw r5, 0xc(r1);
  stw r0, 0x10(r1);
  bl DCInvalidateRange;
  lwz r12, _unk_803864c8;
  addi r3, r1, 8;
  lwz r4, _unk_803864bc;
  mtctr r12;
  bctrl;
  lwz r3, 8(r1);
  li r4, 0x480;
  bl DCFlushRangeNoSync;
  b lbl_801259cc;
lbl_80125978:
  lwz r0, _unk_803864c8;
  cmpwi r0, 0;
  bne lbl_801259cc;
  lwz r3, _unk_80386498;
  la r30, _unk_803864d4;
  lbzx r0, r30, r3;
  cmpwi r0, 0;
  beq lbl_801259cc;
  mulli r3, r3, 0x480;
  addi r0, r31, 0x2400;
  li r4, 0;
  li r5, 0x480;
  add r29, r0, r3;
  mr r3, r29;
  bl memset;
  mr r3, r29;
  li r4, 0x480;
  bl DCFlushRange;
  lwz r0, _unk_80386498;
  li r3, 0;
  stbx r3, r30, r0;
lbl_801259cc:
  lis r3, 0xaaab;
  lwz r5, _unk_803864a0;
  addi r0, r3, -21845;
  lwz r3, _unk_80386498;
  lwz r4, _unk_8038649c;
  addi r7, r5, 1;
  addi r3, r3, 1;
  addi r5, r4, 1;
  mulhwu r6, r0, r7;
  mulhwu r4, r0, r5;
  srwi r6, r6, 1;
  mulhwu r0, r0, r3;
  srwi r4, r4, 1;
  mulli r6, r6, 3;
  srwi r0, r0, 1;
  mulli r4, r4, 3;
  subf r6, r6, r7;
  stw r6, _unk_803864a0;
  mulli r0, r0, 3;
  subf r4, r4, r5;
  stw r4, _unk_8038649c;
  subf r0, r0, r3;
  stw r0, _unk_80386498;
  lwz r31, 0x5c(r1);
  lwz r30, 0x58(r1);
  lwz r29, 0x54(r1);
  lwz r0, 0x64(r1);
  mtlr r0;
  addi r1, r1, 0x60;
  blr;
  // clang-format on
}

// Symbol: AXRegisterAuxACallback
// PAL: 0x80125a44..0x80125aa8
MARK_BINARY_BLOB(AXRegisterAuxACallback, 0x80125a44, 0x80125aa8);
asm UNKNOWN_FUNCTION(AXRegisterAuxACallback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  stw r30, 8(r1);
  mr r30, r4;
  bl OSDisableInterrupts;
  cmpwi r31, 0;
  stw r31, _unk_803864d0;
  mr r31, r3;
  stw r30, _unk_803864c4;
  bne lbl_80125a88;
  la r3, _unk_803864dc;
  li r4, 1;
  li r5, 3;
  bl memset;
lbl_80125a88:
  mr r3, r31;
  bl OSRestoreInterrupts;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: AXRegisterAuxBCallback
// PAL: 0x80125aa8..0x80125b0c
MARK_BINARY_BLOB(AXRegisterAuxBCallback, 0x80125aa8, 0x80125b0c);
asm UNKNOWN_FUNCTION(AXRegisterAuxBCallback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  stw r30, 8(r1);
  mr r30, r4;
  bl OSDisableInterrupts;
  cmpwi r31, 0;
  stw r31, _unk_803864cc;
  mr r31, r3;
  stw r30, _unk_803864c0;
  bne lbl_80125aec;
  la r3, _unk_803864d8;
  li r4, 1;
  li r5, 3;
  bl memset;
lbl_80125aec:
  mr r3, r31;
  bl OSRestoreInterrupts;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: AXRegisterAuxCCallback
// PAL: 0x80125b0c..0x80125b70
MARK_BINARY_BLOB(AXRegisterAuxCCallback, 0x80125b0c, 0x80125b70);
asm UNKNOWN_FUNCTION(AXRegisterAuxCCallback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  stw r30, 8(r1);
  mr r30, r4;
  bl OSDisableInterrupts;
  cmpwi r31, 0;
  stw r31, _unk_803864c8;
  mr r31, r3;
  stw r30, _unk_803864bc;
  bne lbl_80125b50;
  la r3, _unk_803864d4;
  li r4, 1;
  li r5, 3;
  bl memset;
lbl_80125b50:
  mr r3, r31;
  bl OSRestoreInterrupts;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: AXGetAuxACallback
// PAL: 0x80125b70..0x80125b84
MARK_BINARY_BLOB(AXGetAuxACallback, 0x80125b70, 0x80125b84);
asm UNKNOWN_FUNCTION(AXGetAuxACallback) {
  // clang-format off
  nofralloc;
  lwz r0, _unk_803864d0;
  stw r0, 0(r3);
  lwz r0, _unk_803864c4;
  stw r0, 0(r4);
  blr;
  // clang-format on
}

// Symbol: AXGetAuxBCallback
// PAL: 0x80125b84..0x80125b98
MARK_BINARY_BLOB(AXGetAuxBCallback, 0x80125b84, 0x80125b98);
asm UNKNOWN_FUNCTION(AXGetAuxBCallback) {
  // clang-format off
  nofralloc;
  lwz r0, _unk_803864cc;
  stw r0, 0(r3);
  lwz r0, _unk_803864c0;
  stw r0, 0(r4);
  blr;
  // clang-format on
}

// Symbol: AXGetAuxCCallback
// PAL: 0x80125b98..0x80125bac
MARK_BINARY_BLOB(AXGetAuxCCallback, 0x80125b98, 0x80125bac);
asm UNKNOWN_FUNCTION(AXGetAuxCCallback) {
  // clang-format off
  nofralloc;
  lwz r0, _unk_803864c8;
  stw r0, 0(r3);
  lwz r0, _unk_803864bc;
  stw r0, 0(r4);
  blr;
  // clang-format on
}
