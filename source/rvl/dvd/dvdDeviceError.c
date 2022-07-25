#include "dvdDeviceError.h"

#include <rvl/os/osFatal.h>
#include <rvl/os/osFont.h>
#include <rvl/os/osMemory.h>

#include "dvdBroadway.h"
#include "dvdFatal.h"

// Extern function references.
// PAL: 0x8019f2d0
extern UNKNOWN_FUNCTION(__OSGetIOSRev);
// PAL: 0x801b1d0c
extern UNKNOWN_FUNCTION(SCGetLanguage);

// Symbol: lowCallback
// PAL: 0x801643ec..0x801643fc
MARK_BINARY_BLOB(lowCallback, 0x801643ec, 0x801643fc);
asm UNKNOWN_FUNCTION(lowCallback) {
  // clang-format off
  nofralloc;
  li r0, 1;
  stw r3, -0x64f0(r13);
  stw r0, -0x7320(r13);
  blr;
  // clang-format on
}

// Symbol: __DVDCheckDevice
// PAL: 0x801643fc..0x80164684
MARK_BINARY_BLOB(__DVDCheckDevice, 0x801643fc, 0x80164684);
asm UNKNOWN_FUNCTION(__DVDCheckDevice) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  stw r31, 0x2c(r1);
  stw r30, 0x28(r1);
  lis r30, 0x460a;
  bl OSGetPhysicalMem2Size;
  addis r0, r3, 0xf800;
  cmplwi r0, 0;
  bne lbl_8016442c;
  li r3, 1;
  b lbl_8016466c;
lbl_8016442c:
  addi r3, r1, 0x18;
  bl __OSGetIOSRev;
  lbz r0, 0x19(r1);
  cmplwi r0, 0x1e;
  blt lbl_80164448;
  cmplwi r0, 0xfe;
  blt lbl_80164450;
lbl_80164448:
  li r3, 1;
  b lbl_8016466c;
lbl_80164450:
  lis r3, 0x8000;
  lbz r0, 0x319c(r3);
  cmplwi r0, 0x81;
  bne lbl_80164464;
  lis r30, 0x7ed4;
lbl_80164464:
  li r0, 0;
  lis r3, 0x8034;
  lis r6, 0x8016;
  stw r0, -0x7320(r13);
  mr r5, r30;
  addi r3, r3, 0x34c0;
  addi r6, r6, 0x43ec;
  li r4, 0x20;
  bl DVDLowUnencryptedRead;
lbl_80164488:
  lwz r0, -0x7320(r13);
  cmpwi r0, 0;
  beq lbl_80164488;
  lwz r0, -0x64f0(r13);
  cmpwi r0, 2;
  beq lbl_801644b0;
  bge lbl_80164664;
  cmpwi r0, 1;
  bge lbl_801645cc;
  b lbl_80164664;
lbl_801644b0:
  li r0, 0;
  lis r3, 0x8016;
  stw r0, -0x7320(r13);
  addi r3, r3, 0x43ec;
  bl DVDLowRequestError;
lbl_801644c4:
  lwz r0, -0x7320(r13);
  cmpwi r0, 0;
  beq lbl_801644c4;
  bl DVDLowGetImmBufferReg;
  lwz r0, -0x64f0(r13);
  cmpwi r0, 1;
  beq lbl_801644e4;
  b lbl_80164664;
lbl_801644e4:
  bl DVDLowGetImmBufferReg;
  rlwinm. r0, r3, 0, 0, 7;
  bne lbl_8016465c;
  bl DVDLowGetImmBufferReg;
  lis r4, 5;
  clrlwi r3, r3, 8;
  addi r0, r4, 0x2100;
  cmpw r3, r0;
  beq lbl_8016450c;
  b lbl_801645cc;
lbl_8016450c:
  li r0, 0;
  lis r3, 0x8034;
  lis r6, 0x8016;
  stw r0, -0x7320(r13);
  addi r3, r3, 0x34c0;
  lis r4, 4;
  addi r6, r6, 0x43ec;
  li r5, 0;
  bl DVDLowReportKey;
lbl_80164530:
  lwz r0, -0x7320(r13);
  cmpwi r0, 0;
  beq lbl_80164530;
  lwz r0, -0x64f0(r13);
  cmpwi r0, 2;
  beq lbl_80164558;
  bge lbl_80164664;
  cmpwi r0, 1;
  bge lbl_801645cc;
  b lbl_80164664;
lbl_80164558:
  li r0, 0;
  lis r3, 0x8016;
  stw r0, -0x7320(r13);
  addi r3, r3, 0x43ec;
  bl DVDLowRequestError;
lbl_8016456c:
  lwz r0, -0x7320(r13);
  cmpwi r0, 0;
  beq lbl_8016456c;
  bl DVDLowGetImmBufferReg;
  lwz r0, -0x64f0(r13);
  cmpwi r0, 1;
  beq lbl_8016458c;
  b lbl_80164664;
lbl_8016458c:
  bl DVDLowGetImmBufferReg;
  rlwinm. r0, r3, 0, 0, 7;
  bne lbl_8016465c;
  bl DVDLowGetImmBufferReg;
  lis r4, 5;
  clrlwi r3, r3, 8;
  addi r0, r4, 0x3100;
  cmpw r3, r0;
  beq lbl_801645c4;
  bge lbl_801645cc;
  addi r0, r4, 0x2000;
  cmpw r3, r0;
  beq lbl_801645c4;
  b lbl_801645cc;
lbl_801645c4:
  li r3, 1;
  b lbl_8016466c;
lbl_801645cc:
  lbz r5, -0x731c(r13);
  li r31, 0;
  lbz r4, -0x731b(r13);
  lbz r3, -0x731a(r13);
  lbz r0, -0x7319(r13);
  stb r5, 8(r1);
  stb r4, 9(r1);
  stb r3, 0xa(r1);
  stb r0, 0xb(r1);
  bl SCGetLanguage;
  clrlwi. r0, r3, 0x18;
  bne lbl_80164608;
  li r3, 1;
  bl OSSetFontEncode;
  b lbl_80164610;
lbl_80164608:
  li r3, 0;
  bl OSSetFontEncode;
lbl_80164610:
  lis r30, 0x8025;
  addi r30, r30, -12792;
  bl SCGetLanguage;
  clrlwi r0, r3, 0x18;
  cmplwi r0, 6;
  ble lbl_80164630;
  lwz r5, 4(r30);
  b lbl_8016463c;
lbl_80164630:
  bl SCGetLanguage;
  rlwinm r0, r3, 2, 0x16, 0x1d;
  lwzx r5, r30, r0;
lbl_8016463c:
  lwz r0, 8(r1);
  addi r4, r1, 0x10;
  stw r31, 0x10(r1);
  addi r3, r1, 0xc;
  stw r0, 0xc(r1);
  bl OSFatal;
  li r3, 0;
  b lbl_8016466c;
lbl_8016465c:
  li r3, 0;
  b lbl_8016466c;
lbl_80164664:
  bl __DVDShowFatalMessage;
  li r3, 0;
lbl_8016466c:
  lwz r0, 0x34(r1);
  lwz r31, 0x2c(r1);
  lwz r30, 0x28(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}
