#include "rfl_init.h"

#include <string.h>

#include <rvl/os/os.h>
#include <rvl/mem/expHeap.h>

char __RFL_VERSION[] = "<< RVL_SDK - RFL \trelease build: Jan 28 2008 15:34:44 "
                       "(0x4201_127) >>\x00\x00";

// Extern function references.
// PAL: 0x800bc6f0
extern UNKNOWN_FUNCTION(RFLiInitLoader);
// PAL: 0x800bd6d0
extern UNKNOWN_FUNCTION(RFLFreeCachedResource);
// PAL: 0x800bd740
extern UNKNOWN_FUNCTION(RFLIsResourceCached);
// PAL: 0x800bd790
extern UNKNOWN_FUNCTION(RFLiInitAccessInfo);
// PAL: 0x800bd810
extern UNKNOWN_FUNCTION(RFLiExitAccessInfo);
// PAL: 0x800bd860
extern UNKNOWN_FUNCTION(RFLiIsWorking);
// PAL: 0x800c53a0
extern UNKNOWN_FUNCTION(unk_800c53a0);
// PAL: 0x800c63e0
extern UNKNOWN_FUNCTION(unk_800c63e0);
// PAL: 0x800c6700
extern UNKNOWN_FUNCTION(unk_800c6700);
// PAL: 0x800c7ee0
extern UNKNOWN_FUNCTION(unk_800c7ee0);

// Symbol: RFLGetWorkSize
// PAL: 0x800bbb80..0x800bbba0
MARK_BINARY_BLOB(RFLGetWorkSize, 0x800bbb80, 0x800bbba0);
asm UNKNOWN_FUNCTION(RFLGetWorkSize) {
  // clang-format off
  nofralloc;
  cmpwi r3, 0;
  lis r3, 5;
  addi r3, r3, -12512;
  beqlr;
  lis r3, 6;
  addi r3, r3, 0x5f20;
  blr;
  // clang-format on
}

// Symbol: RFLInitResAsync
// PAL: 0x800bbba0..0x800bbf08
MARK_BINARY_BLOB(RFLInitResAsync, 0x800bbba0, 0x800bbf08);
asm UNKNOWN_FUNCTION(RFLInitResAsync) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_27;
  cmpwi r4, 0;
  mr r27, r3;
  mr r29, r4;
  mr r30, r5;
  mr r31, r6;
  bne lbl_800bbbd4;
  li r3, 5;
  b lbl_800bbef0;
lbl_800bbbd4:
  lwz r0, -0x6968(r13);
  cmpwi r0, 0;
  bne lbl_800bbee8;
  lwz r3, -0x7e28(r13);
  bl OSRegisterVersion;
  cmpwi r31, 0;
  lis r5, 5;
  mr r3, r27;
  li r4, 0;
  addi r5, r5, -20480;
  beq lbl_800bbc08;
  lis r5, 6;
  addi r5, r5, 0x4000;
lbl_800bbc08:
  bl memset;
  li r5, 0;
  li r4, 1;
  stw r27, -0x6968(r13);
  cmpwi r31, 0;
  lis r3, 5;
  addi r0, r27, 0x1f20;
  stw r4, -0x7e24(r13);
  addi r4, r3, -28448;
  stw r5, -0x6964(r13);
  stb r5, -0x6960(r13);
  stw r0, 0(r27);
  beq lbl_800bbc44;
  lis r3, 6;
  addi r4, r3, 0x20e0;
lbl_800bbc44:
  lwz r27, -0x6968(r13);
  li r5, 1;
  lwz r3, 0(r27);
  bl MEMCreateExpHeapEx;
  stw r3, 4(r27);
  lis r28, 2;
  addi r4, r28, 0x4800;
  li r5, 0x20;
  lwz r3, -0x6968(r13);
  lwz r3, 4(r3);
  bl MEMAllocFromExpHeapEx;
  lwz r27, -0x6968(r13);
  addi r4, r28, 0x4800;
  li r5, 1;
  bl MEMCreateExpHeapEx;
  stw r3, 8(r27);
  li r4, 4;
  lwz r3, -0x6968(r13);
  lwz r3, 4(r3);
  bl MEMGetAllocatableSizeForExpHeapEx;
  lwz r6, -0x6968(r13);
  mr r27, r3;
  mr r4, r27;
  li r5, 8;
  lwz r3, 4(r6);
  bl MEMAllocFromExpHeapEx;
  lwz r28, -0x6968(r13);
  mr r4, r27;
  li r5, 1;
  bl MEMCreateExpHeapEx;
  stw r3, 0xc(r28);
  li r0, 0;
  lwz r3, -0x6968(r13);
  stw r0, 0x1b40(r3);
  lwz r3, -0x6968(r13);
  stw r0, 0x1b44(r3);
  lwz r3, -0x6968(r13);
  stw r0, 0x1b48(r3);
  lwz r3, -0x6968(r13);
  stw r0, 0x1b4c(r3);
  lwz r3, -0x6968(r13);
  stw r31, 0x1b38(r3);
  lwz r3, -0x6968(r13);
  stb r0, 0x1b3c(r3);
  lwz r3, -0x6968(r13);
  stw r0, 0x1b34(r3);
  lwz r3, -0x6968(r13);
  lwz r3, 8(r3);
  bl unk_800c63e0;
  bl RFLiInitLoader;
  lwz r3, -0x6968(r13);
  lwz r3, 8(r3);
  bl unk_800c7ee0;
  bl unk_800c53a0;
  lwz r3, -0x6968(r13);
  lwz r3, 8(r3);
  bl RFLiInitAccessInfo;
  cmpwi r29, 0;
  beq lbl_800bbd58;
  lwz r3, -0x6968(r13);
  cmpwi r3, 0;
  beq lbl_800bbd44;
  addi r3, r3, 0xc0;
  b lbl_800bbd48;
lbl_800bbd44:
  li r3, 0;
lbl_800bbd48:
  li r0, 1;
  stw r0, 0x98(r3);
  stw r30, 0x90(r3);
  stw r29, 0x94(r3);
lbl_800bbd58:
  lis r3, 0x800c;
  addi r3, r3, -16064;
  bl unk_800c6700;
  cmpwi r3, 6;
  mr r31, r3;
  beq lbl_800bbeec;
  cmpwi r3, 0;
  beq lbl_800bbeec;
  lwz r0, -0x6968(r13);
  cmpwi r0, 0;
  beq lbl_800bbeec;
lbl_800bbd84:
  lwz r0, -0x6968(r13);
  cmpwi r0, 0;
  bne lbl_800bbd98;
  lwz r0, -0x7e24(r13);
  b lbl_800bbdf0;
lbl_800bbd98:
  bl RFLiIsWorking;
  cmpwi r3, 0;
  beq lbl_800bbdac;
  li r0, 6;
  b lbl_800bbdf0;
lbl_800bbdac:
  lwz r5, -0x6968(r13);
  addi r3, r13, -26976;
  cmpwi r5, 0;
  beq lbl_800bbdc0;
  addi r3, r5, 0x1b3c;
lbl_800bbdc0:
  lbz r4, 0(r3);
  li r3, 1;
  rlwinm. r0, r4, 0, 0x1d, 0x1d;
  bne lbl_800bbddc;
  rlwinm. r0, r4, 0, 0x1c, 0x1c;
  bne lbl_800bbddc;
  li r3, 0;
lbl_800bbddc:
  cmpwi r3, 0;
  beq lbl_800bbdec;
  li r0, 5;
  b lbl_800bbdf0;
lbl_800bbdec:
  lwz r0, 0x1b40(r5);
lbl_800bbdf0:
  stw r0, 8(r1);
  lwz r0, 8(r1);
  cmpwi r0, 6;
  beq lbl_800bbd84;
  lwz r0, -0x6968(r13);
  lwz r3, 8(r1);
  cmpwi r0, 0;
  bne lbl_800bbe18;
  lwz r0, -0x7e24(r13);
  b lbl_800bbe70;
lbl_800bbe18:
  bl RFLiIsWorking;
  cmpwi r3, 0;
  beq lbl_800bbe2c;
  li r0, 6;
  b lbl_800bbe70;
lbl_800bbe2c:
  lwz r5, -0x6968(r13);
  addi r3, r13, -26976;
  cmpwi r5, 0;
  beq lbl_800bbe40;
  addi r3, r5, 0x1b3c;
lbl_800bbe40:
  lbz r4, 0(r3);
  li r3, 1;
  rlwinm. r0, r4, 0, 0x1d, 0x1d;
  bne lbl_800bbe5c;
  rlwinm. r0, r4, 0, 0x1c, 0x1c;
  bne lbl_800bbe5c;
  li r3, 0;
lbl_800bbe5c:
  cmpwi r3, 0;
  beq lbl_800bbe6c;
  li r0, 5;
  b lbl_800bbe70;
lbl_800bbe6c:
  lwz r0, 0x1b40(r5);
lbl_800bbe70:
  lwz r3, -0x6968(r13);
  stw r0, -0x7e24(r13);
  cmpwi r3, 0;
  beq lbl_800bbe94;
  beq lbl_800bbe8c;
  lwz r0, 0x1b48(r3);
  b lbl_800bbe98;
lbl_800bbe8c:
  li r0, 0;
  b lbl_800bbe98;
lbl_800bbe94:
  lwz r0, -0x6964(r13);
lbl_800bbe98:
  stw r0, -0x6964(r13);
  lbz r0, 0x1b3c(r3);
  stb r0, -0x6960(r13);
  bl RFLIsResourceCached;
  cmpwi r3, 0;
  beq lbl_800bbeb4;
  bl RFLFreeCachedResource;
lbl_800bbeb4:
  bl RFLiExitAccessInfo;
  lwz r3, -0x6968(r13);
  lwz r3, 0xc(r3);
  bl MEMDestroyExpHeap;
  lwz r3, -0x6968(r13);
  lwz r3, 8(r3);
  bl MEMDestroyExpHeap;
  lwz r3, -0x6968(r13);
  lwz r3, 4(r3);
  bl MEMDestroyExpHeap;
  li r0, 0;
  stw r0, -0x6968(r13);
  b lbl_800bbeec;
lbl_800bbee8:
  li r31, 0;
lbl_800bbeec:
  mr r3, r31;
lbl_800bbef0:
  addi r11, r1, 0x30;
  bl _restgpr_27;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}
