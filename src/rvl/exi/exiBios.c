#include "exiBios.h"

#include <string.h>

#include <rvl/os/os.h>
#include <rvl/os/osContext.h>
#include <rvl/os/osInterrupt.h>

#include "exiUart.h"

// Extern function references.
// PAL: 0x8019f33c
extern UNKNOWN_FUNCTION(OSGetConsoleType);
// PAL: 0x801a04f4
extern UNKNOWN_FUNCTION(__OSGetDIConfig);

// Symbol: SetExiInterruptMask
// PAL: 0x80167e78..0x80167f68
MARK_BINARY_BLOB(SetExiInterruptMask, 0x80167e78, 0x80167f68);
asm UNKNOWN_FUNCTION(SetExiInterruptMask) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  lis r5, 0x8034;
  addi r5, r5, 0x3680;
  cmpwi r3, 1;
  beq lbl_80167ef4;
  bge lbl_80167eac;
  cmpwi r3, 0;
  bge lbl_80167eb8;
  b lbl_80167f54;
lbl_80167eac:
  cmpwi r3, 3;
  bge lbl_80167f54;
  b lbl_80167f24;
lbl_80167eb8:
  lwz r0, 0(r4);
  cmpwi r0, 0;
  bne lbl_80167ed0;
  lwz r0, 0x80(r5);
  cmpwi r0, 0;
  beq lbl_80167edc;
lbl_80167ed0:
  lwz r0, 0xc(r4);
  rlwinm. r0, r0, 0, 0x1b, 0x1b;
  beq lbl_80167ee8;
lbl_80167edc:
  lis r3, 0x41;
  bl __OSMaskInterrupts;
  b lbl_80167f54;
lbl_80167ee8:
  lis r3, 0x41;
  bl __OSUnmaskInterrupts;
  b lbl_80167f54;
lbl_80167ef4:
  lwz r0, 0(r4);
  cmpwi r0, 0;
  beq lbl_80167f0c;
  lwz r0, 0xc(r4);
  rlwinm. r0, r0, 0, 0x1b, 0x1b;
  beq lbl_80167f18;
lbl_80167f0c:
  lis r3, 8;
  bl __OSMaskInterrupts;
  b lbl_80167f54;
lbl_80167f18:
  lis r3, 8;
  bl __OSUnmaskInterrupts;
  b lbl_80167f54;
lbl_80167f24:
  li r3, 0x19;
  bl __OSGetInterruptHandler;
  cmpwi r3, 0;
  beq lbl_80167f40;
  lwz r0, 0xc(r31);
  rlwinm. r0, r0, 0, 0x1b, 0x1b;
  beq lbl_80167f4c;
lbl_80167f40:
  li r3, 0x40;
  bl __OSMaskInterrupts;
  b lbl_80167f54;
lbl_80167f4c:
  li r3, 0x40;
  bl __OSUnmaskInterrupts;
lbl_80167f54:
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: EXIImm
// PAL: 0x80167f68..0x801681e4
MARK_BINARY_BLOB(EXIImm, 0x80167f68, 0x801681e4);
asm UNKNOWN_FUNCTION(EXIImm) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_25;
  mr r26, r3;
  mr r27, r4;
  mr r28, r5;
  mr r29, r6;
  mr r25, r7;
  slwi r0, r3, 6;
  lis r3, 0x8034;
  addi r3, r3, 0x3680;
  add r31, r3, r0;
  bl OSDisableInterrupts;
  mr r30, r3;
  lwz r0, 0xc(r31);
  clrlwi. r0, r0, 0x1e;
  bne lbl_80167fc0;
  lwz r0, 0xc(r31);
  rlwinm. r0, r0, 0, 0x1d, 0x1d;
  bne lbl_80167fd0;
lbl_80167fc0:
  mr r3, r30;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_801681cc;
lbl_80167fd0:
  stw r25, 4(r31);
  cmpwi r25, 0;
  beq lbl_8016800c;
  mulli r3, r26, 0x14;
  lis r0, 0xcd00;
  add r3, r0, r3;
  lwz r0, 0x6800(r3);
  andi. r0, r0, 0x7f5;
  ori r0, r0, 8;
  stw r0, 0x6800(r3);
  lis r3, 0x20;
  slwi r0, r26, 2;
  subf r0, r26, r0;
  srw r3, r3, r0;
  bl __OSUnmaskInterrupts;
lbl_8016800c:
  lwz r0, 0xc(r31);
  ori r0, r0, 2;
  stw r0, 0xc(r31);
  cmpwi r29, 0;
  beq lbl_80168180;
  li r0, 0;
  li r4, 0;
  cmpwi cr1, r28, 0;
  ble cr1, lbl_80168170;
  addi r6, r28, -8;
  cmpwi r28, 8;
  ble lbl_8016813c;
  li r5, 0;
  blt cr1, lbl_80168058;
  lis r3, 0x8000;
  addi r3, r3, -2;
  cmpw r28, r3;
  bgt lbl_80168058;
  li r5, 1;
lbl_80168058:
  cmpwi r5, 0;
  beq lbl_8016813c;
  mr r3, r27;
  addi r5, r6, 7;
  srwi r5, r5, 3;
  mtctr r5;
  cmpwi r6, 0;
  ble lbl_8016813c;
lbl_80168078:
  lbz r6, 0(r3);
  subfic r5, r4, 3;
  slwi r5, r5, 3;
  slw r5, r6, r5;
  or r0, r0, r5;
  lbz r6, 1(r3);
  addi r5, r4, 1;
  subfic r5, r5, 3;
  slwi r5, r5, 3;
  slw r5, r6, r5;
  or r0, r0, r5;
  lbz r6, 2(r3);
  addi r5, r4, 2;
  subfic r5, r5, 3;
  slwi r5, r5, 3;
  slw r5, r6, r5;
  or r0, r0, r5;
  lbz r6, 3(r3);
  neg r5, r4;
  slwi r5, r5, 3;
  slw r5, r6, r5;
  or r0, r0, r5;
  lbz r6, 4(r3);
  addi r5, r4, 4;
  subfic r5, r5, 3;
  slwi r5, r5, 3;
  slw r5, r6, r5;
  or r0, r0, r5;
  lbz r6, 5(r3);
  addi r5, r4, 5;
  subfic r5, r5, 3;
  slwi r5, r5, 3;
  slw r5, r6, r5;
  or r0, r0, r5;
  lbz r6, 6(r3);
  addi r5, r4, 6;
  subfic r5, r5, 3;
  slwi r5, r5, 3;
  slw r5, r6, r5;
  or r0, r0, r5;
  lbz r6, 7(r3);
  addi r5, r4, 7;
  subfic r5, r5, 3;
  slwi r5, r5, 3;
  slw r5, r6, r5;
  or r0, r0, r5;
  addi r3, r3, 8;
  addi r4, r4, 8;
  bdnz lbl_80168078;
lbl_8016813c:
  add r6, r27, r4;
  subf r3, r4, r28;
  mtctr r3;
  cmpw r4, r28;
  bge lbl_80168170;
lbl_80168150:
  lbz r5, 0(r6);
  subfic r3, r4, 3;
  slwi r3, r3, 3;
  slw r3, r5, r3;
  or r0, r0, r3;
  addi r6, r6, 1;
  addi r4, r4, 1;
  bdnz lbl_80168150;
lbl_80168170:
  lis r4, 0xcd00;
  mulli r3, r26, 0x14;
  add r3, r4, r3;
  stw r0, 0x6810(r3);
lbl_80168180:
  stw r27, 0x14(r31);
  addi r3, r29, -1;
  subfic r0, r29, 1;
  or r0, r3, r0;
  srawi r0, r0, 0x1f;
  and r0, r28, r0;
  stw r0, 0x10(r31);
  slwi r0, r29, 2;
  ori r3, r0, 1;
  addi r0, r28, -1;
  slwi r0, r0, 4;
  or r4, r3, r0;
  lis r3, 0xcd00;
  mulli r0, r26, 0x14;
  add r3, r3, r0;
  stw r4, 0x680c(r3);
  mr r3, r30;
  bl OSRestoreInterrupts;
  li r3, 1;
lbl_801681cc:
  addi r11, r1, 0x30;
  bl _restgpr_25;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: EXIImmEx
// PAL: 0x801681e4..0x80168288
MARK_BINARY_BLOB(EXIImmEx, 0x801681e4, 0x80168288);
asm UNKNOWN_FUNCTION(EXIImmEx) {
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
  mr r30, r6;
  b lbl_80168264;
lbl_8016820c:
  cmpwi r29, 4;
  li r31, 4;
  bge lbl_8016821c;
  mr r31, r29;
lbl_8016821c:
  mr r3, r27;
  mr r4, r28;
  mr r5, r31;
  mr r6, r30;
  li r7, 0;
  bl EXIImm;
  cmpwi r3, 0;
  bne lbl_80168244;
  li r3, 0;
  b lbl_80168270;
lbl_80168244:
  mr r3, r27;
  bl EXISync;
  cmpwi r3, 0;
  bne lbl_8016825c;
  li r3, 0;
  b lbl_80168270;
lbl_8016825c:
  add r28, r28, r31;
  subf r29, r31, r29;
lbl_80168264:
  cmpwi r29, 0;
  bne lbl_8016820c;
  li r3, 1;
lbl_80168270:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: EXIDma
// PAL: 0x80168288..0x80168380
MARK_BINARY_BLOB(EXIDma, 0x80168288, 0x80168380);
asm UNKNOWN_FUNCTION(EXIDma) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_25;
  mr r26, r3;
  mr r27, r4;
  mr r28, r5;
  mr r29, r6;
  mr r25, r7;
  slwi r0, r3, 6;
  lis r3, 0x8034;
  addi r3, r3, 0x3680;
  add r31, r3, r0;
  bl OSDisableInterrupts;
  mr r30, r3;
  lwz r0, 0xc(r31);
  clrlwi. r0, r0, 0x1e;
  bne lbl_801682e0;
  lwz r0, 0xc(r31);
  rlwinm. r0, r0, 0, 0x1d, 0x1d;
  bne lbl_801682f0;
lbl_801682e0:
  mr r3, r30;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_80168368;
lbl_801682f0:
  stw r25, 4(r31);
  cmpwi r25, 0;
  beq lbl_8016832c;
  mulli r3, r26, 0x14;
  lis r0, 0xcd00;
  add r3, r0, r3;
  lwz r0, 0x6800(r3);
  andi. r0, r0, 0x7f5;
  ori r0, r0, 8;
  stw r0, 0x6800(r3);
  lis r3, 0x20;
  slwi r0, r26, 2;
  subf r0, r26, r0;
  srw r3, r3, r0;
  bl __OSUnmaskInterrupts;
lbl_8016832c:
  lwz r0, 0xc(r31);
  ori r0, r0, 1;
  stw r0, 0xc(r31);
  mulli r3, r26, 0x14;
  rlwinm r4, r27, 0, 0, 0x1a;
  lis r0, 0xcd00;
  add r3, r0, r3;
  stw r4, 0x6804(r3);
  stw r28, 0x6808(r3);
  slwi r0, r29, 2;
  ori r0, r0, 3;
  stw r0, 0x680c(r3);
  mr r3, r30;
  bl OSRestoreInterrupts;
  li r3, 1;
lbl_80168368:
  addi r11, r1, 0x30;
  bl _restgpr_25;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: EXISync
// PAL: 0x80168380..0x801685fc
MARK_BINARY_BLOB(EXISync, 0x80168380, 0x801685fc);
asm UNKNOWN_FUNCTION(EXISync) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  stw r28, 0x10(r1);
  slwi r0, r3, 6;
  lis r4, 0x8034;
  addi r4, r4, 0x3680;
  add r31, r4, r0;
  li r29, 0;
  mulli r30, r3, 0x14;
  lis r0, 0xcd00;
  add r3, r0, r30;
  b lbl_801685cc;
lbl_801683c0:
  lwz r0, 0x680c(r3);
  clrlwi. r0, r0, 0x1f;
  bne lbl_801685cc;
  bl OSDisableInterrupts;
  mr r28, r3;
  lwz r0, 0xc(r31);
  rlwinm. r0, r0, 0, 0x1d, 0x1d;
  beq lbl_801685c0;
  lwz r0, 0xc(r31);
  clrlwi. r0, r0, 0x1e;
  beq lbl_8016853c;
  lwz r0, 0xc(r31);
  rlwinm. r0, r0, 0, 0x1e, 0x1e;
  beq lbl_80168530;
  lwz r5, 0x10(r31);
  cmpwi cr1, r5, 0;
  beq cr1, lbl_80168530;
  lwz r4, 0x14(r31);
  lis r0, 0xcd00;
  add r3, r0, r30;
  lwz r0, 0x6810(r3);
  li r3, 0;
  ble cr1, lbl_80168530;
  addi r7, r5, -8;
  cmpwi r5, 8;
  ble lbl_80168504;
  li r8, 0;
  blt cr1, lbl_80168444;
  lis r6, 0x8000;
  addi r6, r6, -2;
  cmpw r5, r6;
  bgt lbl_80168444;
  li r8, 1;
lbl_80168444:
  cmpwi r8, 0;
  beq lbl_80168504;
  addi r6, r7, 7;
  srwi r6, r6, 3;
  mtctr r6;
  cmpwi r7, 0;
  ble lbl_80168504;
lbl_80168460:
  subfic r6, r3, 3;
  slwi r6, r6, 3;
  srw r6, r0, r6;
  stb r6, 0(r4);
  addi r6, r3, 1;
  subfic r6, r6, 3;
  slwi r6, r6, 3;
  srw r6, r0, r6;
  stb r6, 1(r4);
  addi r6, r3, 2;
  subfic r6, r6, 3;
  slwi r6, r6, 3;
  srw r6, r0, r6;
  stb r6, 2(r4);
  neg r6, r3;
  slwi r6, r6, 3;
  srw r6, r0, r6;
  stb r6, 3(r4);
  addi r6, r3, 4;
  subfic r6, r6, 3;
  slwi r6, r6, 3;
  srw r6, r0, r6;
  stb r6, 4(r4);
  addi r6, r3, 5;
  subfic r6, r6, 3;
  slwi r6, r6, 3;
  srw r6, r0, r6;
  stb r6, 5(r4);
  addi r6, r3, 6;
  subfic r6, r6, 3;
  slwi r6, r6, 3;
  srw r6, r0, r6;
  stb r6, 6(r4);
  addi r6, r3, 7;
  subfic r6, r6, 3;
  slwi r6, r6, 3;
  srw r6, r0, r6;
  stb r6, 7(r4);
  addi r4, r4, 8;
  addi r3, r3, 8;
  bdnz lbl_80168460;
lbl_80168504:
  subf r6, r3, r5;
  mtctr r6;
  cmpw r3, r5;
  bge lbl_80168530;
lbl_80168514:
  subfic r5, r3, 3;
  slwi r5, r5, 3;
  srw r5, r0, r5;
  stb r5, 0(r4);
  addi r4, r4, 1;
  addi r3, r3, 1;
  bdnz lbl_80168514;
lbl_80168530:
  lwz r0, 0xc(r31);
  rlwinm r0, r0, 0, 0, 0x1d;
  stw r0, 0xc(r31);
lbl_8016853c:
  bl __OSGetDIConfig;
  cmplwi r3, 0xff;
  bne lbl_801685bc;
  bl OSGetConsoleType;
  rlwinm r3, r3, 0, 0, 3;
  addis r0, r3, 0xe000;
  cmplwi r0, 0;
  beq lbl_801685bc;
  lwz r0, 0x10(r31);
  cmpwi r0, 4;
  bne lbl_801685bc;
  lis r0, 0xcd00;
  add r4, r0, r30;
  lwz r0, 0x6800(r4);
  rlwinm. r0, r0, 0, 0x19, 0x1b;
  bne lbl_801685bc;
  lwz r3, 0x6810(r4);
  addis r0, r3, 0xfeff;
  cmplwi r0, 0;
  beq lbl_801685ac;
  lwz r3, 0x6810(r4);
  addis r0, r3, 0xfaf9;
  cmplwi r0, 0;
  beq lbl_801685ac;
  lwz r3, 0x6810(r4);
  addis r0, r3, 0xfbde;
  cmplwi r0, 1;
  bne lbl_801685bc;
lbl_801685ac:
  lis r3, 0x8000;
  lhz r0, 0x30e6(r3);
  cmplwi r0, 0x8200;
  bne lbl_801685c0;
lbl_801685bc:
  li r29, 1;
lbl_801685c0:
  mr r3, r28;
  bl OSRestoreInterrupts;
  b lbl_801685d8;
lbl_801685cc:
  lwz r0, 0xc(r31);
  rlwinm. r0, r0, 0, 0x1d, 0x1d;
  bne lbl_801683c0;
lbl_801685d8:
  mr r3, r29;
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: EXISetExiCallback
// PAL: 0x801685fc..0x80168680
MARK_BINARY_BLOB(EXISetExiCallback, 0x801685fc, 0x80168680);
asm UNKNOWN_FUNCTION(EXISetExiCallback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_26;
  mr r26, r3;
  mr r27, r4;
  slwi r0, r3, 6;
  lis r31, 0x8034;
  addi r31, r31, 0x3680;
  add r30, r31, r0;
  bl OSDisableInterrupts;
  mr r28, r3;
  lwz r29, 0(r30);
  stw r27, 0(r30);
  cmpwi r26, 2;
  beq lbl_80168650;
  mr r3, r26;
  mr r4, r30;
  bl SetExiInterruptMask;
  b lbl_8016865c;
lbl_80168650:
  li r3, 0;
  mr r4, r31;
  bl SetExiInterruptMask;
lbl_8016865c:
  mr r3, r28;
  bl OSRestoreInterrupts;
  mr r3, r29;
  addi r11, r1, 0x20;
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: __EXIProbe
// PAL: 0x80168680..0x80168800
MARK_BINARY_BLOB(__EXIProbe, 0x80168680, 0x80168800);
asm UNKNOWN_FUNCTION(__EXIProbe) {
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
  slwi r0, r3, 6;
  lis r4, 0x8034;
  addi r4, r4, 0x3680;
  add r31, r4, r0;
  cmpwi r3, 2;
  bne lbl_801686c0;
  li r3, 1;
  b lbl_801687e0;
lbl_801686c0:
  li r29, 1;
  bl OSDisableInterrupts;
  mr r30, r3;
  mulli r3, r28, 0x14;
  lis r0, 0xcd00;
  add r3, r0, r3;
  lwz r5, 0x6800(r3);
  lwz r0, 0xc(r31);
  rlwinm. r0, r0, 0, 0x1c, 0x1c;
  bne lbl_801687a8;
  rlwinm. r0, r5, 0, 0x14, 0x14;
  beq lbl_80168718;
  lwz r0, 0x6800(r3);
  andi. r0, r0, 0x7f5;
  ori r0, r0, 0x800;
  stw r0, 0x6800(r3);
  li r4, 0;
  stw r4, 0x20(r31);
  slwi r3, r28, 2;
  lis r0, 0x8000;
  add r3, r0, r3;
  stw r4, 0x30c0(r3);
lbl_80168718:
  rlwinm. r0, r5, 0, 0x13, 0x13;
  beq lbl_80168788;
  bl OSGetTime;
  lis r31, 0x8000;
  lwz r0, 0xf8(r31);
  srwi r0, r0, 2;
  lis r5, 0x1062;
  addi r5, r5, 0x4dd3;
  mulhwu r0, r5, r0;
  srwi r6, r0, 6;
  li r5, 0;
  bl __div2i;
  li r6, 0x64;
  li r5, 0;
  bl __div2i;
  addi r4, r4, 1;
  slwi r0, r28, 2;
  add r3, r31, r0;
  lwz r0, 0x30c0(r3);
  cmpwi r0, 0;
  bne lbl_80168770;
  stw r4, 0x30c0(r3);
lbl_80168770:
  lwz r0, 0x30c0(r3);
  subf r0, r0, r4;
  cmpwi r0, 3;
  bge lbl_801687d4;
  li r29, 0;
  b lbl_801687d4;
lbl_80168788:
  li r4, 0;
  stw r4, 0x20(r31);
  slwi r3, r28, 2;
  lis r0, 0x8000;
  add r3, r0, r3;
  stw r4, 0x30c0(r3);
  li r29, 0;
  b lbl_801687d4;
lbl_801687a8:
  rlwinm. r0, r5, 0, 0x13, 0x13;
  beq lbl_801687b8;
  rlwinm. r0, r5, 0, 0x14, 0x14;
  beq lbl_801687d4;
lbl_801687b8:
  li r4, 0;
  stw r4, 0x20(r31);
  slwi r3, r28, 2;
  lis r0, 0x8000;
  add r3, r0, r3;
  stw r4, 0x30c0(r3);
  li r29, 0;
lbl_801687d4:
  mr r3, r30;
  bl OSRestoreInterrupts;
  mr r3, r29;
lbl_801687e0:
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: EXIAttach
// PAL: 0x80168800..0x80168918
MARK_BINARY_BLOB(EXIAttach, 0x80168800, 0x80168918);
asm UNKNOWN_FUNCTION(EXIAttach) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_27;
  mr r29, r3;
  mr r27, r4;
  slwi r0, r3, 6;
  lis r4, 0x8034;
  addi r4, r4, 0x3680;
  add r31, r4, r0;
  bl __EXIProbe;
  cmpwi r3, 0;
  beq lbl_80168854;
  lwz r0, 0x20(r31);
  cmpwi r0, 0;
  bne lbl_80168854;
  mr r3, r29;
  li r4, 0;
  addi r5, r1, 8;
  bl EXIGetID;
lbl_80168854:
  bl OSDisableInterrupts;
  mr r30, r3;
  lwz r0, 0x20(r31);
  cmpwi r0, 0;
  bne lbl_80168874;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_80168900;
lbl_80168874:
  bl OSDisableInterrupts;
  mr r28, r3;
  lwz r0, 0xc(r31);
  rlwinm. r0, r0, 0, 0x1c, 0x1c;
  bne lbl_80168898;
  mr r3, r29;
  bl __EXIProbe;
  cmpwi r3, 0;
  bne lbl_801688a8;
lbl_80168898:
  mr r3, r28;
  bl OSRestoreInterrupts;
  li r29, 0;
  b lbl_801688f4;
lbl_801688a8:
  mulli r3, r29, 0x14;
  lis r0, 0xcd00;
  add r3, r0, r3;
  lwz r0, 0x6800(r3);
  andi. r0, r0, 0x7f5;
  ori r0, r0, 2;
  stw r0, 0x6800(r3);
  stw r27, 8(r31);
  lis r3, 0x10;
  slwi r0, r29, 2;
  subf r0, r29, r0;
  srw r3, r3, r0;
  bl __OSUnmaskInterrupts;
  lwz r0, 0xc(r31);
  ori r0, r0, 8;
  stw r0, 0xc(r31);
  mr r3, r28;
  bl OSRestoreInterrupts;
  li r29, 1;
lbl_801688f4:
  mr r3, r30;
  bl OSRestoreInterrupts;
  mr r3, r29;
lbl_80168900:
  addi r11, r1, 0x30;
  bl _restgpr_27;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: EXIDetach
// PAL: 0x80168918..0x801689d0
MARK_BINARY_BLOB(EXIDetach, 0x80168918, 0x801689d0);
asm UNKNOWN_FUNCTION(EXIDetach) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r3;
  slwi r0, r3, 6;
  lis r3, 0x8034;
  addi r3, r3, 0x3680;
  add r31, r3, r0;
  bl OSDisableInterrupts;
  mr r30, r3;
  lwz r0, 0xc(r31);
  rlwinm. r0, r0, 0, 0x1c, 0x1c;
  bne lbl_80168964;
  bl OSRestoreInterrupts;
  li r3, 1;
  b lbl_801689b4;
lbl_80168964:
  lwz r0, 0xc(r31);
  rlwinm. r0, r0, 0, 0x1b, 0x1b;
  beq lbl_80168988;
  lwz r0, 0x18(r31);
  cmpwi r0, 0;
  bne lbl_80168988;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_801689b4;
lbl_80168988:
  lwz r0, 0xc(r31);
  rlwinm r0, r0, 0, 0x1d, 0x1b;
  stw r0, 0xc(r31);
  lis r3, 0x50;
  slwi r0, r29, 2;
  subf r0, r29, r0;
  srw r3, r3, r0;
  bl __OSMaskInterrupts;
  mr r3, r30;
  bl OSRestoreInterrupts;
  li r3, 1;
lbl_801689b4:
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: EXISelect
// PAL: 0x801689d0..0x80168b00
MARK_BINARY_BLOB(EXISelect, 0x801689d0, 0x80168b00);
asm UNKNOWN_FUNCTION(EXISelect) {
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
  slwi r0, r3, 6;
  lis r3, 0x8034;
  addi r3, r3, 0x3680;
  add r31, r3, r0;
  bl OSDisableInterrupts;
  mr r30, r3;
  lwz r0, 0xc(r31);
  rlwinm. r0, r0, 0, 0x1d, 0x1d;
  bne lbl_80168a58;
  cmpwi r27, 2;
  beq lbl_80168a68;
  cmpwi r28, 0;
  bne lbl_80168a40;
  lwz r0, 0xc(r31);
  rlwinm. r0, r0, 0, 0x1c, 0x1c;
  bne lbl_80168a40;
  mr r3, r27;
  bl __EXIProbe;
  cmpwi r3, 0;
  beq lbl_80168a58;
lbl_80168a40:
  lwz r0, 0xc(r31);
  rlwinm. r0, r0, 0, 0x1b, 0x1b;
  beq lbl_80168a58;
  lwz r0, 0x18(r31);
  cmplw r0, r28;
  beq lbl_80168a68;
lbl_80168a58:
  mr r3, r30;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_80168ae8;
lbl_80168a68:
  lwz r0, 0xc(r31);
  ori r0, r0, 4;
  stw r0, 0xc(r31);
  mulli r3, r27, 0x14;
  lis r0, 0xcd00;
  add r4, r0, r3;
  lwz r3, 0x6800(r4);
  andi. r3, r3, 0x405;
  slwi r0, r29, 4;
  or r3, r3, r0;
  li r0, 1;
  slw r0, r0, r28;
  slwi r0, r0, 7;
  or r3, r3, r0;
  stw r3, 0x6800(r4);
  lwz r0, 0xc(r31);
  rlwinm. r0, r0, 0, 0x1c, 0x1c;
  beq lbl_80168adc;
  cmpwi r27, 1;
  beq lbl_80168ad4;
  bge lbl_80168adc;
  cmpwi r27, 0;
  bge lbl_80168ac8;
  b lbl_80168adc;
lbl_80168ac8:
  lis r3, 0x10;
  bl __OSMaskInterrupts;
  b lbl_80168adc;
lbl_80168ad4:
  lis r3, 2;
  bl __OSMaskInterrupts;
lbl_80168adc:
  mr r3, r30;
  bl OSRestoreInterrupts;
  li r3, 1;
lbl_80168ae8:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: EXIDeselect
// PAL: 0x80168b00..0x80168c00
MARK_BINARY_BLOB(EXIDeselect, 0x80168b00, 0x80168c00);
asm UNKNOWN_FUNCTION(EXIDeselect) {
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
  slwi r0, r3, 6;
  lis r3, 0x8034;
  addi r3, r3, 0x3680;
  add r31, r3, r0;
  bl OSDisableInterrupts;
  mr r29, r3;
  lwz r0, 0xc(r31);
  rlwinm. r0, r0, 0, 0x1d, 0x1d;
  bne lbl_80168b50;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_80168be0;
lbl_80168b50:
  lwz r0, 0xc(r31);
  rlwinm r0, r0, 0, 0x1e, 0x1c;
  stw r0, 0xc(r31);
  mulli r3, r28, 0x14;
  lis r0, 0xcd00;
  add r3, r0, r3;
  lwz r30, 0x6800(r3);
  andi. r0, r30, 0x405;
  stw r0, 0x6800(r3);
  lwz r0, 0xc(r31);
  rlwinm. r0, r0, 0, 0x1c, 0x1c;
  beq lbl_80168bac;
  cmpwi r28, 1;
  beq lbl_80168ba4;
  bge lbl_80168bac;
  cmpwi r28, 0;
  bge lbl_80168b98;
  b lbl_80168bac;
lbl_80168b98:
  lis r3, 0x10;
  bl __OSUnmaskInterrupts;
  b lbl_80168bac;
lbl_80168ba4:
  lis r3, 2;
  bl __OSUnmaskInterrupts;
lbl_80168bac:
  mr r3, r29;
  bl OSRestoreInterrupts;
  cmpwi r28, 2;
  beq lbl_80168bdc;
  rlwinm. r0, r30, 0, 0x18, 0x18;
  beq lbl_80168bdc;
  mr r3, r28;
  bl __EXIProbe;
  neg r0, r3;
  or r0, r0, r3;
  srwi r3, r0, 0x1f;
  b lbl_80168be0;
lbl_80168bdc:
  li r3, 1;
lbl_80168be0:
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: EXIIntrruptHandler
// PAL: 0x80168c00..0x80168cb8
MARK_BINARY_BLOB(EXIIntrruptHandler, 0x80168c00, 0x80168cb8);
asm UNKNOWN_FUNCTION(EXIIntrruptHandler) {
  // clang-format off
  nofralloc;
  stwu r1, -0x2e0(r1);
  mflr r0;
  stw r0, 0x2e4(r1);
  stw r31, 0x2dc(r1);
  stw r30, 0x2d8(r1);
  stw r29, 0x2d4(r1);
  mr r29, r4;
  addi r0, r3, -9;
  lis r3, 0x5555;
  addi r3, r3, 0x5556;
  mulhw r3, r3, r0;
  srwi r0, r3, 0x1f;
  add r31, r3, r0;
  mulli r3, r31, 0x14;
  lis r0, 0xcd00;
  add r3, r0, r3;
  lwz r0, 0x6800(r3);
  andi. r0, r0, 0x7f5;
  ori r0, r0, 2;
  stw r0, 0x6800(r3);
  slwi r0, r31, 6;
  lis r3, 0x8034;
  addi r3, r3, 0x3680;
  lwzx r30, r3, r0;
  cmpwi r30, 0;
  beq lbl_80168c9c;
  addi r3, r1, 8;
  bl OSClearContext;
  addi r3, r1, 8;
  bl OSSetCurrentContext;
  mr r3, r31;
  mr r4, r29;
  mr r12, r30;
  mtctr r12;
  bctrl;
  addi r3, r1, 8;
  bl OSClearContext;
  mr r3, r29;
  bl OSSetCurrentContext;
lbl_80168c9c:
  lwz r31, 0x2dc(r1);
  lwz r30, 0x2d8(r1);
  lwz r29, 0x2d4(r1);
  lwz r0, 0x2e4(r1);
  mtlr r0;
  addi r1, r1, 0x2e0;
  blr;
  // clang-format on
}

// Symbol: TCIntrruptHandler
// PAL: 0x80168cb8..0x80168ed0
MARK_BINARY_BLOB(TCIntrruptHandler, 0x80168cb8, 0x80168ed0);
asm UNKNOWN_FUNCTION(TCIntrruptHandler) {
  // clang-format off
  nofralloc;
  stwu r1, -0x2f0(r1);
  mflr r0;
  stw r0, 0x2f4(r1);
  addi r11, r1, 0x2f0;
  bl _savegpr_27;
  mr r27, r4;
  addi r0, r3, -10;
  lis r4, 0x5555;
  addi r4, r4, 0x5556;
  mulhw r4, r4, r0;
  srwi r0, r4, 0x1f;
  add r29, r4, r0;
  slwi r0, r29, 6;
  lis r4, 0x8034;
  addi r4, r4, 0x3680;
  add r30, r4, r0;
  lis r31, 0x8000;
  srw r3, r31, r3;
  bl __OSMaskInterrupts;
  mulli r3, r29, 0x14;
  lis r0, 0xcd00;
  add r3, r0, r3;
  lwz r0, 0x6800(r3);
  andi. r0, r0, 0x7f5;
  ori r0, r0, 8;
  stw r0, 0x6800(r3);
  lwz r28, 4(r30);
  cmpwi r28, 0;
  beq lbl_80168eb8;
  li r0, 0;
  stw r0, 4(r30);
  lwz r0, 0xc(r30);
  clrlwi. r0, r0, 0x1e;
  beq lbl_80168e84;
  lwz r0, 0xc(r30);
  rlwinm. r0, r0, 0, 0x1e, 0x1e;
  beq lbl_80168e78;
  lwz r5, 0x10(r30);
  cmpwi cr1, r5, 0;
  beq cr1, lbl_80168e78;
  lwz r4, 0x14(r30);
  lwz r0, 0x6810(r3);
  li r3, 0;
  ble cr1, lbl_80168e78;
  addi r7, r5, -8;
  cmpwi r5, 8;
  ble lbl_80168e4c;
  li r8, 0;
  blt cr1, lbl_80168d8c;
  addi r6, r31, -2;
  cmpw r5, r6;
  bgt lbl_80168d8c;
  li r8, 1;
lbl_80168d8c:
  cmpwi r8, 0;
  beq lbl_80168e4c;
  addi r6, r7, 7;
  srwi r6, r6, 3;
  mtctr r6;
  cmpwi r7, 0;
  ble lbl_80168e4c;
lbl_80168da8:
  subfic r6, r3, 3;
  slwi r6, r6, 3;
  srw r6, r0, r6;
  stb r6, 0(r4);
  addi r6, r3, 1;
  subfic r6, r6, 3;
  slwi r6, r6, 3;
  srw r6, r0, r6;
  stb r6, 1(r4);
  addi r6, r3, 2;
  subfic r6, r6, 3;
  slwi r6, r6, 3;
  srw r6, r0, r6;
  stb r6, 2(r4);
  neg r6, r3;
  slwi r6, r6, 3;
  srw r6, r0, r6;
  stb r6, 3(r4);
  addi r6, r3, 4;
  subfic r6, r6, 3;
  slwi r6, r6, 3;
  srw r6, r0, r6;
  stb r6, 4(r4);
  addi r6, r3, 5;
  subfic r6, r6, 3;
  slwi r6, r6, 3;
  srw r6, r0, r6;
  stb r6, 5(r4);
  addi r6, r3, 6;
  subfic r6, r6, 3;
  slwi r6, r6, 3;
  srw r6, r0, r6;
  stb r6, 6(r4);
  addi r6, r3, 7;
  subfic r6, r6, 3;
  slwi r6, r6, 3;
  srw r6, r0, r6;
  stb r6, 7(r4);
  addi r4, r4, 8;
  addi r3, r3, 8;
  bdnz lbl_80168da8;
lbl_80168e4c:
  subf r6, r3, r5;
  mtctr r6;
  cmpw r3, r5;
  bge lbl_80168e78;
lbl_80168e5c:
  subfic r5, r3, 3;
  slwi r5, r5, 3;
  srw r5, r0, r5;
  stb r5, 0(r4);
  addi r4, r4, 1;
  addi r3, r3, 1;
  bdnz lbl_80168e5c;
lbl_80168e78:
  lwz r0, 0xc(r30);
  rlwinm r0, r0, 0, 0, 0x1d;
  stw r0, 0xc(r30);
lbl_80168e84:
  addi r3, r1, 8;
  bl OSClearContext;
  addi r3, r1, 8;
  bl OSSetCurrentContext;
  mr r3, r29;
  mr r4, r27;
  mr r12, r28;
  mtctr r12;
  bctrl;
  addi r3, r1, 8;
  bl OSClearContext;
  mr r3, r27;
  bl OSSetCurrentContext;
lbl_80168eb8:
  addi r11, r1, 0x2f0;
  bl _restgpr_27;
  lwz r0, 0x2f4(r1);
  mtlr r0;
  addi r1, r1, 0x2f0;
  blr;
  // clang-format on
}

// Symbol: EXTIntrruptHandler
// PAL: 0x80168ed0..0x80168fa0
MARK_BINARY_BLOB(EXTIntrruptHandler, 0x80168ed0, 0x80168fa0);
asm UNKNOWN_FUNCTION(EXTIntrruptHandler) {
  // clang-format off
  nofralloc;
  stwu r1, -0x2e0(r1);
  mflr r0;
  stw r0, 0x2e4(r1);
  stw r31, 0x2dc(r1);
  stw r30, 0x2d8(r1);
  stw r29, 0x2d4(r1);
  stw r28, 0x2d0(r1);
  mr r28, r4;
  addi r0, r3, -11;
  lis r3, 0x5555;
  addi r3, r3, 0x5556;
  mulhw r3, r3, r0;
  srwi r0, r3, 0x1f;
  add r31, r3, r0;
  lis r3, 0x50;
  slwi r0, r31, 2;
  subf r0, r31, r0;
  srw r3, r3, r0;
  bl __OSMaskInterrupts;
  slwi r0, r31, 6;
  lis r3, 0x8034;
  addi r3, r3, 0x3680;
  add r30, r3, r0;
  lwz r29, 8(r30);
  lwz r0, 0xc(r30);
  rlwinm r0, r0, 0, 0x1d, 0x1b;
  stw r0, 0xc(r30);
  cmpwi r29, 0;
  beq lbl_80168f80;
  addi r3, r1, 8;
  bl OSClearContext;
  addi r3, r1, 8;
  bl OSSetCurrentContext;
  li r0, 0;
  stw r0, 8(r30);
  mr r3, r31;
  mr r4, r28;
  mr r12, r29;
  mtctr r12;
  bctrl;
  addi r3, r1, 8;
  bl OSClearContext;
  mr r3, r28;
  bl OSSetCurrentContext;
lbl_80168f80:
  lwz r31, 0x2dc(r1);
  lwz r30, 0x2d8(r1);
  lwz r29, 0x2d4(r1);
  lwz r28, 0x2d0(r1);
  lwz r0, 0x2e4(r1);
  mtlr r0;
  addi r1, r1, 0x2e0;
  blr;
  // clang-format on
}

// Symbol: EXIInit
// PAL: 0x80168fa0..0x80169164
MARK_BINARY_BLOB(EXIInit, 0x80168fa0, 0x80169164);
asm UNKNOWN_FUNCTION(EXIInit) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  stw r28, 0x10(r1);
  lis r3, 0xcd00;
lbl_80168fc0:
  lwz r0, 0x680c(r3);
  clrlwi r0, r0, 0x1f;
  cmplwi r0, 1;
  beq lbl_80168fc0;
  lwz r0, 0x6820(r3);
  clrlwi r0, r0, 0x1f;
  cmplwi r0, 1;
  beq lbl_80168fc0;
  lwz r0, 0x6834(r3);
  clrlwi r0, r0, 0x1f;
  cmplwi r0, 1;
  beq lbl_80168fc0;
  lis r3, 0x80;
  addi r3, r3, -32768;
  bl __OSMaskInterrupts;
  li r28, 0;
  lis r3, 0xcd00;
  stw r28, 0x6800(r3);
  stw r28, 0x6814(r3);
  stw r28, 0x6828(r3);
  li r0, 0x2000;
  stw r0, 0x6800(r3);
  li r3, 9;
  lis r29, 0x8017;
  addi r4, r29, -29696;
  bl __OSSetInterruptHandler;
  li r3, 0xa;
  lis r30, 0x8017;
  addi r4, r30, -29512;
  bl __OSSetInterruptHandler;
  li r3, 0xb;
  lis r31, 0x8017;
  addi r4, r31, -28976;
  bl __OSSetInterruptHandler;
  li r3, 0xc;
  addi r4, r29, -29696;
  bl __OSSetInterruptHandler;
  li r3, 0xd;
  addi r4, r30, -29512;
  bl __OSSetInterruptHandler;
  li r3, 0xe;
  addi r4, r31, -28976;
  bl __OSSetInterruptHandler;
  li r3, 0xf;
  addi r4, r29, -29696;
  bl __OSSetInterruptHandler;
  li r3, 0x10;
  addi r4, r30, -29512;
  bl __OSSetInterruptHandler;
  li r3, 0;
  li r4, 2;
  addi r5, r13, -25768;
  bl EXIGetID;
  lwz r0, -0x63a8(r13);
  cmpwi r0, 0;
  beq lbl_801690d0;
  lis r3, 0x8000;
  stw r28, 0x30c4(r3);
  stw r28, 0x30c0(r3);
  lis r3, 0x8034;
  addi r3, r3, 0x3680;
  stw r28, 0x60(r3);
  stw r28, 0x20(r3);
  li r3, 0;
  bl __EXIProbe;
  li r3, 1;
  bl __EXIProbe;
  b lbl_8016913c;
lbl_801690d0:
  li r3, 0;
  li r4, 0;
  addi r5, r1, 8;
  bl EXIGetID;
  cmpwi r3, 0;
  beq lbl_80169108;
  lwz r3, 8(r1);
  addis r0, r3, 0xf8ff;
  cmplwi r0, 0;
  bne lbl_80169108;
  li r3, 1;
  li r4, 0;
  bl __OSEnableBarnacle;
  b lbl_8016913c;
lbl_80169108:
  li r3, 1;
  li r4, 0;
  addi r5, r1, 8;
  bl EXIGetID;
  cmpwi r3, 0;
  beq lbl_8016913c;
  lwz r3, 8(r1);
  addis r0, r3, 0xf8ff;
  cmplwi r0, 0;
  bne lbl_8016913c;
  li r3, 0;
  li r4, 2;
  bl __OSEnableBarnacle;
lbl_8016913c:
  lwz r3, -0x72e8(r13);
  bl OSRegisterVersion;
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: EXILock
// PAL: 0x80169164..0x80169260
MARK_BINARY_BLOB(EXILock, 0x80169164, 0x80169260);
asm UNKNOWN_FUNCTION(EXILock) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  mr r27, r3;
  mr r31, r4;
  mr r28, r5;
  slwi r0, r3, 6;
  lis r3, 0x8034;
  addi r3, r3, 0x3680;
  add r30, r3, r0;
  bl OSDisableInterrupts;
  mr r29, r3;
  lwz r0, 0xc(r30);
  rlwinm. r0, r0, 0, 0x1b, 0x1b;
  beq lbl_80169220;
  cmpwi r28, 0;
  beq lbl_80169210;
  mr r3, r30;
  lwz r4, 0x24(r30);
  mtctr r4;
  cmpwi r4, 0;
  ble lbl_801691e8;
lbl_801691c4:
  lwz r0, 0x28(r3);
  cmplw r31, r0;
  bne lbl_801691e0;
  mr r3, r29;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_80169248;
lbl_801691e0:
  addi r3, r3, 8;
  bdnz lbl_801691c4;
lbl_801691e8:
  slwi r0, r4, 3;
  add r3, r30, r0;
  stw r28, 0x2c(r3);
  lwz r0, 0x24(r30);
  slwi r0, r0, 3;
  add r3, r30, r0;
  stw r31, 0x28(r3);
  lwz r3, 0x24(r30);
  addi r0, r3, 1;
  stw r0, 0x24(r30);
lbl_80169210:
  mr r3, r29;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_80169248;
lbl_80169220:
  lwz r0, 0xc(r30);
  ori r0, r0, 0x10;
  stw r0, 0xc(r30);
  stw r31, 0x18(r30);
  mr r3, r27;
  mr r4, r30;
  bl SetExiInterruptMask;
  mr r3, r29;
  bl OSRestoreInterrupts;
  li r3, 1;
lbl_80169248:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: EXIUnlock
// PAL: 0x80169260..0x80169338
MARK_BINARY_BLOB(EXIUnlock, 0x80169260, 0x80169338);
asm UNKNOWN_FUNCTION(EXIUnlock) {
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
  slwi r0, r3, 6;
  lis r3, 0x8034;
  addi r3, r3, 0x3680;
  add r31, r3, r0;
  bl OSDisableInterrupts;
  mr r30, r3;
  lwz r0, 0xc(r31);
  rlwinm. r0, r0, 0, 0x1b, 0x1b;
  bne lbl_801692b0;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_80169318;
lbl_801692b0:
  lwz r0, 0xc(r31);
  rlwinm r0, r0, 0, 0x1c, 0x1a;
  stw r0, 0xc(r31);
  mr r3, r28;
  mr r4, r31;
  bl SetExiInterruptMask;
  lwz r3, 0x24(r31);
  cmpwi r3, 0;
  ble lbl_8016930c;
  lwz r29, 0x2c(r31);
  addic. r0, r3, -1;
  stw r0, 0x24(r31);
  ble lbl_801692f8;
  addi r3, r31, 0x28;
  addi r4, r31, 0x30;
  lwz r0, 0x24(r31);
  slwi r5, r0, 3;
  bl memmove;
lbl_801692f8:
  mr r3, r28;
  li r4, 0;
  mr r12, r29;
  mtctr r12;
  bctrl;
lbl_8016930c:
  mr r3, r30;
  bl OSRestoreInterrupts;
  li r3, 1;
lbl_80169318:
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: UnlockedHandler
// PAL: 0x80169338..0x80169360
MARK_BINARY_BLOB(UnlockedHandler, 0x80169338, 0x80169360);
asm UNKNOWN_FUNCTION(UnlockedHandler) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  li r4, 0;
  addi r5, r1, 8;
  bl EXIGetID;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: EXIGetID
// PAL: 0x80169360..0x8016970c
MARK_BINARY_BLOB(EXIGetID, 0x80169360, 0x8016970c);
asm UNKNOWN_FUNCTION(EXIGetID) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  mflr r0;
  stw r0, 0x44(r1);
  addi r11, r1, 0x40;
  bl _savegpr_23;
  mr r25, r3;
  mr r26, r4;
  mr r27, r5;
  slwi r0, r3, 6;
  lis r6, 0x8034;
  addi r6, r6, 0x3680;
  add r29, r6, r0;
  cmpwi r3, 0;
  bne lbl_801693b8;
  cmplwi r4, 2;
  bne lbl_801693b8;
  lwz r0, -0x64a8(r13);
  cmpwi r0, 0;
  beq lbl_801693b8;
  stw r0, 0(r5);
  li r3, 1;
  b lbl_801696f4;
lbl_801693b8:
  cmpwi r3, 2;
  bge lbl_801694a4;
  cmpwi r4, 0;
  bne lbl_801694a4;
  mr r3, r25;
  bl __EXIProbe;
  cmpwi r3, 0;
  bne lbl_801693e0;
  li r3, 0;
  b lbl_801696f4;
lbl_801693e0:
  slwi r3, r25, 2;
  lis r0, 0x8000;
  add r31, r0, r3;
  lwz r3, 0x20(r29);
  lwz r0, 0x30c0(r31);
  cmpw r3, r0;
  bne lbl_8016940c;
  lwz r0, 0x1c(r29);
  stw r0, 0(r27);
  lwz r3, 0x20(r29);
  b lbl_801696f4;
lbl_8016940c:
  bl OSDisableInterrupts;
  mr r30, r3;
  lwz r0, 0xc(r29);
  rlwinm. r0, r0, 0, 0x1c, 0x1c;
  bne lbl_80169430;
  mr r3, r25;
  bl __EXIProbe;
  cmpwi r3, 0;
  bne lbl_80169440;
lbl_80169430:
  mr r3, r30;
  bl OSRestoreInterrupts;
  li r0, 0;
  b lbl_80169490;
lbl_80169440:
  mulli r3, r25, 0x14;
  lis r0, 0xcd00;
  add r3, r0, r3;
  lwz r0, 0x6800(r3);
  andi. r0, r0, 0x7f5;
  ori r0, r0, 2;
  stw r0, 0x6800(r3);
  li r0, 0;
  stw r0, 8(r29);
  lis r3, 0x10;
  slwi r0, r25, 2;
  subf r0, r25, r0;
  srw r3, r3, r0;
  bl __OSUnmaskInterrupts;
  lwz r0, 0xc(r29);
  ori r0, r0, 8;
  stw r0, 0xc(r29);
  mr r3, r30;
  bl OSRestoreInterrupts;
  li r0, 1;
lbl_80169490:
  cmpwi r0, 0;
  bne lbl_801694a0;
  li r3, 0;
  b lbl_801696f4;
lbl_801694a0:
  lwz r31, 0x30c0(r31);
lbl_801694a4:
  bl OSDisableInterrupts;
  mr r28, r3;
  mr r3, r25;
  mr r4, r26;
  li r5, 0;
  cmpwi r25, 2;
  bge lbl_801694cc;
  cmpwi r26, 0;
  bne lbl_801694cc;
  li r5, 1;
lbl_801694cc:
  neg r0, r5;
  or r0, r0, r5;
  srawi r0, r0, 0x1f;
  lis r5, 0x8017;
  addi r5, r5, -27848;
  and r5, r5, r0;
  bl EXILock;
  cntlzw r0, r3;
  rlwinm. r30, r0, 0x1b, 5, 0x1f;
  bne lbl_8016961c;
  mr r3, r25;
  mr r4, r26;
  li r5, 0;
  bl EXISelect;
  cntlzw r0, r3;
  rlwinm. r30, r0, 0x1b, 5, 0x1f;
  bne lbl_8016959c;
  li r0, 0;
  stw r0, 8(r1);
  mr r3, r25;
  addi r4, r1, 8;
  li r5, 2;
  li r6, 1;
  li r7, 0;
  bl EXIImm;
  cntlzw r0, r3;
  srwi r0, r0, 5;
  or r30, r30, r0;
  mr r3, r25;
  bl EXISync;
  cntlzw r0, r3;
  srwi r0, r0, 5;
  or r30, r30, r0;
  mr r3, r25;
  mr r4, r27;
  li r5, 4;
  li r6, 0;
  li r7, 0;
  bl EXIImm;
  cntlzw r0, r3;
  srwi r0, r0, 5;
  or r30, r30, r0;
  mr r3, r25;
  bl EXISync;
  cntlzw r0, r3;
  srwi r0, r0, 5;
  or r30, r30, r0;
  mr r3, r25;
  bl EXIDeselect;
  cntlzw r0, r3;
  srwi r0, r0, 5;
  or r30, r30, r0;
lbl_8016959c:
  bl OSDisableInterrupts;
  mr r23, r3;
  lwz r0, 0xc(r29);
  rlwinm. r0, r0, 0, 0x1b, 0x1b;
  bne lbl_801695b8;
  bl OSRestoreInterrupts;
  b lbl_8016961c;
lbl_801695b8:
  lwz r0, 0xc(r29);
  rlwinm r0, r0, 0, 0x1c, 0x1a;
  stw r0, 0xc(r29);
  mr r3, r25;
  mr r4, r29;
  bl SetExiInterruptMask;
  lwz r3, 0x24(r29);
  cmpwi r3, 0;
  ble lbl_80169614;
  lwz r24, 0x2c(r29);
  addic. r0, r3, -1;
  stw r0, 0x24(r29);
  ble lbl_80169600;
  addi r3, r29, 0x28;
  addi r4, r29, 0x30;
  lwz r0, 0x24(r29);
  slwi r5, r0, 3;
  bl memmove;
lbl_80169600:
  mr r3, r25;
  li r4, 0;
  mr r12, r24;
  mtctr r12;
  bctrl;
lbl_80169614:
  mr r3, r23;
  bl OSRestoreInterrupts;
lbl_8016961c:
  mr r3, r28;
  bl OSRestoreInterrupts;
  cmpwi r25, 2;
  bge lbl_801696ec;
  cmpwi r26, 0;
  bne lbl_801696ec;
  bl OSDisableInterrupts;
  mr r23, r3;
  lwz r0, 0xc(r29);
  rlwinm. r0, r0, 0, 0x1c, 0x1c;
  bne lbl_80169650;
  bl OSRestoreInterrupts;
  b lbl_80169698;
lbl_80169650:
  lwz r0, 0xc(r29);
  rlwinm. r0, r0, 0, 0x1b, 0x1b;
  beq lbl_80169670;
  lwz r0, 0x18(r29);
  cmpwi r0, 0;
  bne lbl_80169670;
  bl OSRestoreInterrupts;
  b lbl_80169698;
lbl_80169670:
  lwz r0, 0xc(r29);
  rlwinm r0, r0, 0, 0x1d, 0x1b;
  stw r0, 0xc(r29);
  lis r3, 0x50;
  slwi r0, r25, 2;
  subf r0, r25, r0;
  srw r3, r3, r0;
  bl __OSMaskInterrupts;
  mr r3, r23;
  bl OSRestoreInterrupts;
lbl_80169698:
  bl OSDisableInterrupts;
  slwi r4, r25, 2;
  lis r0, 0x8000;
  add r4, r0, r4;
  lwz r0, 0x30c0(r4);
  subf r4, r31, r0;
  subf r0, r0, r31;
  or r0, r4, r0;
  srwi r0, r0, 0x1f;
  or. r30, r30, r0;
  bne lbl_801696d0;
  lwz r0, 0(r27);
  stw r0, 0x1c(r29);
  stw r31, 0x20(r29);
lbl_801696d0:
  bl OSRestoreInterrupts;
  cmpwi r30, 0;
  beq lbl_801696e4;
  li r3, 0;
  b lbl_801696f4;
lbl_801696e4:
  lwz r3, 0x20(r29);
  b lbl_801696f4;
lbl_801696ec:
  cntlzw r0, r30;
  srwi r3, r0, 5;
lbl_801696f4:
  addi r11, r1, 0x40;
  bl _restgpr_23;
  lwz r0, 0x44(r1);
  mtlr r0;
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}
