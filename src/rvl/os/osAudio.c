#include "osAudio.h"

#include <string.h>

#include "os.h"
#include "osArena.h"
#include "osCache.h"

// Symbol: __AIClockInit
// PAL: 0x801a1138..0x801a1358
MARK_BINARY_BLOB(__AIClockInit, 0x801a1138, 0x801a1358);
asm UNKNOWN_FUNCTION(__AIClockInit) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r4, 0xcd80;
  stw r0, 0x24(r1);
  slwi r0, r3, 8;
  stw r31, 0x1c(r1);
  mr r31, r3;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  stw r28, 0x10(r1);
  lwz r5, 0x180(r4);
  rlwinm r5, r5, 0, 0x18, 0x16;
  or r5, r5, r0;
  rlwinm r0, r5, 0, 0x19, 0x17;
  stw r0, 0x180(r4);
  lwz r0, 0x1d0(r4);
  clrlwi r0, r0, 2;
  stw r0, 0x1d0(r4);
  bl OSGetTick;
  lis r4, 0x431c;
  mr r28, r3;
  addi r30, r4, -8573;
  lis r29, 0x8000;
lbl_801a1194:
  bl OSGetTick;
  lwz r0, 0xf8(r29);
  subf r3, r28, r3;
  slwi r3, r3, 3;
  srwi r0, r0, 2;
  mulhwu r0, r30, r0;
  srwi r0, r0, 0xf;
  divwu r0, r3, r0;
  cmplwi r0, 0x64;
  blt lbl_801a1194;
  cmpwi r31, 0;
  bne lbl_801a11ec;
  lis r4, 0xcd80;
  lis r3, 0xf804;
  lwz r5, 0x1cc(r4);
  addi r0, r3, -64;
  rlwinm r3, r5, 0, 0x1a, 0xd;
  ori r3, r3, 0xfc0;
  and r0, r3, r0;
  oris r0, r0, 0x464;
  stw r0, 0x1cc(r4);
  b lbl_801a1210;
lbl_801a11ec:
  lis r3, 0xcd80;
  lwz r0, 0x1cc(r3);
  rlwinm r0, r0, 0, 0x1a, 0xd;
  ori r0, r0, 0xffc0;
  rlwinm r0, r0, 0, 0, 0x19;
  ori r0, r0, 0xe;
  rlwinm r0, r0, 0, 0xe, 4;
  oris r0, r0, 0x4b0;
  stw r0, 0x1cc(r3);
lbl_801a1210:
  bl OSGetTick;
  lis r4, 0x431c;
  mr r31, r3;
  addi r30, r4, -8573;
  lis r29, 0x8000;
lbl_801a1224:
  bl OSGetTick;
  lwz r0, 0xf8(r29);
  subf r3, r31, r3;
  slwi r3, r3, 3;
  srwi r0, r0, 2;
  mulhwu r0, r30, r0;
  srwi r0, r0, 0xf;
  divwu r0, r3, r0;
  cmplwi r0, 0x64;
  blt lbl_801a1224;
  lis r3, 0xcd80;
  lwz r0, 0x1d0(r3);
  rlwinm r0, r0, 0, 4, 2;
  stw r0, 0x1d0(r3);
  bl OSGetTick;
  lis r4, 0x431c;
  mr r31, r3;
  addi r30, r4, -8573;
  lis r29, 0x8000;
lbl_801a1270:
  bl OSGetTick;
  lwz r0, 0xf8(r29);
  subf r3, r31, r3;
  slwi r3, r3, 3;
  srwi r0, r0, 2;
  mulhwu r0, r30, r0;
  srwi r0, r0, 0xf;
  divwu r0, r3, r0;
  cmplwi r0, 0x3e8;
  blt lbl_801a1270;
  lis r3, 0xcd80;
  lwz r0, 0x1d0(r3);
  rlwinm r0, r0, 0, 2, 0;
  oris r0, r0, 0x4000;
  stw r0, 0x1d0(r3);
  bl OSGetTick;
  lis r4, 0x431c;
  mr r31, r3;
  addi r30, r4, -8573;
  lis r29, 0x8000;
lbl_801a12c0:
  bl OSGetTick;
  lwz r0, 0xf8(r29);
  subf r3, r31, r3;
  slwi r3, r3, 3;
  srwi r0, r0, 2;
  mulhwu r0, r30, r0;
  srwi r0, r0, 0xf;
  divwu r0, r3, r0;
  cmplwi r0, 0x3e8;
  blt lbl_801a12c0;
  lis r3, 0xcd80;
  lwz r0, 0x1d0(r3);
  clrlwi r0, r0, 1;
  oris r0, r0, 0x8000;
  stw r0, 0x1d0(r3);
  bl OSGetTick;
  lis r4, 0x431c;
  mr r29, r3;
  addi r30, r4, -8573;
  lis r31, 0x8000;
lbl_801a1310:
  bl OSGetTick;
  lwz r0, 0xf8(r31);
  subf r3, r29, r3;
  slwi r3, r3, 3;
  srwi r0, r0, 2;
  mulhwu r0, r30, r0;
  srwi r0, r0, 0xf;
  divwu r0, r3, r0;
  cmplwi r0, 0x3e8;
  blt lbl_801a1310;
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

// Symbol: __OSInitAudioSystem
// PAL: 0x801a1358..0x801a1520
MARK_BINARY_BLOB(__OSInitAudioSystem, 0x801a1358, 0x801a1520);
asm UNKNOWN_FUNCTION(__OSInitAudioSystem) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lwz r0, -0x63a8(r13);
  cmpwi r0, 0;
  bne lbl_801a137c;
  li r3, 1;
  bl __AIClockInit;
lbl_801a137c:
  bl OSGetArenaHi;
  lis r4, 0x8100;
  li r5, 0x80;
  addi r3, r3, -128;
  bl memcpy;
  lis r4, 0x8029;
  lis r3, 0x8100;
  addi r4, r4, -3992;
  li r5, 0x80;
  bl memcpy;
  lis r3, 0x8100;
  li r4, 0x80;
  bl DCFlushRange;
  lis r3, 0xcc00;
  li r0, 0x43;
  sth r0, 0x5012(r3);
  li r0, 0x8ac;
  sth r0, 0x500a(r3);
  lhz r0, 0x500a(r3);
  ori r0, r0, 1;
  sth r0, 0x500a(r3);
lbl_801a13d0:
  lhz r0, 0x500a(r3);
  clrlwi. r0, r0, 0x1f;
  bne lbl_801a13d0;
  li r0, 0;
  lis r4, 0xcc00;
  sth r0, 0x5000(r4);
lbl_801a13e8:
  lhz r3, 0x5004(r4);
  lhz r0, 0x5006(r4);
  rlwimi r0, r3, 0x10, 0, 0xf;
  rlwinm. r0, r0, 0, 0, 0;
  bne lbl_801a13e8;
  lis r4, 0xcc00;
  lis r0, 0x100;
  stw r0, 0x5020(r4);
  li r3, 0;
  li r0, 0x20;
  stw r3, 0x5024(r4);
  stw r0, 0x5028(r4);
  lhz r5, 0x500a(r4);
  b lbl_801a1424;
lbl_801a1420:
  lhz r5, 0x500a(r4);
lbl_801a1424:
  rlwinm. r0, r5, 0, 0x1a, 0x1a;
  beq lbl_801a1420;
  lis r3, 0xcc00;
  sth r5, 0x500a(r3);
  bl OSGetTick;
  mr r31, r3;
lbl_801a143c:
  bl OSGetTick;
  subf r0, r31, r3;
  cmpwi r0, 0x892;
  blt lbl_801a143c;
  lis r4, 0xcc00;
  lis r0, 0x100;
  stw r0, 0x5020(r4);
  li r3, 0;
  li r0, 0x20;
  stw r3, 0x5024(r4);
  stw r0, 0x5028(r4);
  lhz r5, 0x500a(r4);
  b lbl_801a1474;
lbl_801a1470:
  lhz r5, 0x500a(r4);
lbl_801a1474:
  rlwinm. r0, r5, 0, 0x1a, 0x1a;
  beq lbl_801a1470;
  lis r3, 0xcc00;
  sth r5, 0x500a(r3);
  lhz r0, 0x500a(r3);
  rlwinm r0, r0, 0, 0x15, 0x13;
  sth r0, 0x500a(r3);
lbl_801a1490:
  lhz r0, 0x500a(r3);
  rlwinm. r0, r0, 0, 0x15, 0x15;
  bne lbl_801a1490;
  lis r3, 0xcc00;
  lhz r0, 0x500a(r3);
  rlwinm r0, r0, 0, 0x1e, 0x1c;
  sth r0, 0x500a(r3);
  lhz r0, 0x5004(r3);
  b lbl_801a14b8;
lbl_801a14b4:
  lhz r0, 0x5004(r3);
lbl_801a14b8:
  rlwinm. r0, r0, 0, 0x10, 0x10;
  beq lbl_801a14b4;
  lis r4, 0xcc00;
  li r0, 0x8ac;
  lhz r3, 0x5006(r4);
  lhz r3, 0x500a(r4);
  ori r3, r3, 4;
  sth r3, 0x500a(r4);
  sth r0, 0x500a(r4);
  lhz r0, 0x500a(r4);
  ori r0, r0, 1;
  sth r0, 0x500a(r4);
lbl_801a14e8:
  lhz r0, 0x500a(r4);
  clrlwi. r0, r0, 0x1f;
  bne lbl_801a14e8;
  bl OSGetArenaHi;
  mr r4, r3;
  lis r3, 0x8100;
  addi r4, r4, -128;
  li r5, 0x80;
  bl memcpy;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __OSStopAudioSystem
// PAL: 0x801a1520..0x801a15ec
MARK_BINARY_BLOB(__OSStopAudioSystem, 0x801a1520, 0x801a15ec);
asm UNKNOWN_FUNCTION(__OSStopAudioSystem) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r3, 0xcc00;
  stw r0, 0x14(r1);
  li r0, 0x804;
  stw r31, 0xc(r1);
  sth r0, 0x500a(r3);
  lhz r0, 0x5036(r3);
  clrlwi r0, r0, 0x11;
  sth r0, 0x5036(r3);
  lhz r0, 0x500a(r3);
  b lbl_801a1554;
lbl_801a1550:
  lhz r0, 0x500a(r3);
lbl_801a1554:
  rlwinm. r0, r0, 0, 0x15, 0x15;
  bne lbl_801a1550;
  lis r3, 0xcc00;
  lhz r0, 0x500a(r3);
  b lbl_801a156c;
lbl_801a1568:
  lhz r0, 0x500a(r3);
lbl_801a156c:
  rlwinm. r0, r0, 0, 0x16, 0x16;
  bne lbl_801a1568;
  lis r4, 0xcc00;
  li r0, 0x8ac;
  sth r0, 0x500a(r4);
  li r0, 0;
  sth r0, 0x5000(r4);
lbl_801a1588:
  lhz r3, 0x5004(r4);
  lhz r0, 0x5006(r4);
  rlwimi r0, r3, 0x10, 0, 0xf;
  rlwinm. r0, r0, 0, 0, 0;
  bne lbl_801a1588;
  bl OSGetTick;
  mr r31, r3;
lbl_801a15a4:
  bl OSGetTick;
  subf r0, r31, r3;
  cmpwi r0, 0x2c;
  blt lbl_801a15a4;
  lis r3, 0xcc00;
  lhz r0, 0x500a(r3);
  ori r0, r0, 1;
  sth r0, 0x500a(r3);
  lhz r0, 0x500a(r3);
  b lbl_801a15d0;
lbl_801a15cc:
  lhz r0, 0x500a(r3);
lbl_801a15d0:
  clrlwi. r0, r0, 0x1f;
  bne lbl_801a15cc;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}
