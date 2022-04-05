#include "vpb.h"

#include <math.h>
#include <string.h>

#include <rvl/os/osCache.h>
#include <rvl/os/osInterrupt.h>

#include "alloc.h"
#include "cl.h"
#include "spb.h"

AXPB* __AXPB = NULL;
AXPBITDBUFFER* __AXITD = NULL;
AXVPB* __AXVPB = NULL;
u32 __AXMaxDspCycles;
u32 __AXRecDspCycles;
u32 __AXNumVoices;
u32 __AXMaxVoices;

const f32 _lit_803884a8 = 2.0f;
const f32 _lit_803884ac = 6.2831855f;
const f32 _lit_803884b0 = 32000.0f;
const f32 _lit_803884b4 = 1.0f;
sdata2_ps_f32 _lit_803884b8 = {32768.0f};
sdata2_ps_f32 _lit_803884c0 = {176.0f};

extern void* unk_8027e840;
extern void* unk_8027e7c0;

extern void* __s_AXPB;
extern void* __s_AXVPB;
extern void* __s_AXITD;

// Symbol: __AXGetNumVoices
// PAL: 0x80127250..0x80127258
u32 __AXGetNumVoices() { return __AXNumVoices; }

// Symbol: __AXServiceVPB
// PAL: 0x80127258..0x801277a8
MARK_BINARY_BLOB(__AXServiceVPB, 0x80127258, 0x801277a8);
asm UNKNOWN_FUNCTION(__AXServiceVPB) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  addi r30, r3, 0x28;
  stw r29, 0x14(r1);
  stw r28, 0x10(r1);
  mr r28, r3;
  lwz r5, __AXNumVoices;
  lwz r4, __AXPB;
  addi r0, r5, 1;
  stw r0, __AXNumVoices;
  lwz r0, 0x18(r3);
  lwz r29, 0x1c(r3);
  mulli r0, r0, 0x140;
  cmpwi r29, 0;
  add r31, r4, r0;
  bne lbl_801272c8;
  lhz r0, 0x10(r31);
  sth r0, 0x10(r30);
  lhz r0, 0x6a(r31);
  sth r0, 0x6a(r30);
  lhz r0, 0x7a(r31);
  sth r0, 0x7a(r30);
  lhz r0, 0x7c(r31);
  sth r0, 0x7c(r30);
  b lbl_80127788;
lbl_801272c8:
  rlwinm. r0, r29, 0, 0, 0;
  beq lbl_801272e4;
  mr r3, r31;
  mr r4, r30;
  li r5, 0x140;
  bl memcpy;
  b lbl_80127788;
lbl_801272e4:
  clrlwi. r0, r29, 0x1f;
  beq lbl_801272fc;
  lhz r0, 8(r30);
  sth r0, 8(r31);
  lhz r0, 0xa(r30);
  sth r0, 0xa(r31);
lbl_801272fc:
  rlwinm. r0, r29, 0, 0x1e, 0x1e;
  beq lbl_8012730c;
  lwz r0, 0xc(r30);
  stw r0, 0xc(r31);
lbl_8012730c:
  rlwinm. r0, r29, 0, 0x1d, 0x1d;
  beq lbl_80127320;
  lhz r0, 0x10(r30);
  sth r0, 0x10(r31);
  b lbl_80127328;
lbl_80127320:
  lhz r0, 0x10(r31);
  sth r0, 0x10(r30);
lbl_80127328:
  rlwinm. r0, r29, 0, 0x1c, 0x1c;
  beq lbl_80127338;
  lhz r0, 0x12(r30);
  sth r0, 0x12(r31);
lbl_80127338:
  rlwinm. r0, r29, 0, 0x1b, 0x1b;
  beq lbl_80127350;
  addi r3, r31, 0x14;
  addi r4, r30, 0x14;
  li r5, 0x30;
  bl memcpy;
lbl_80127350:
  rlwinm. r0, r29, 0, 0x19, 0x19;
  beq lbl_8012736c;
  lhz r0, 0x4e(r30);
  sth r0, 0x4e(r31);
  lhz r0, 0x50(r30);
  sth r0, 0x50(r31);
  b lbl_801273f4;
lbl_8012736c:
  rlwinm. r0, r29, 0, 0x1a, 0x1a;
  beq lbl_801273f4;
  lhz r3, 0x44(r30);
  li r0, 0;
  sth r3, 0x44(r31);
  lhz r3, 0x46(r30);
  sth r3, 0x46(r31);
  lhz r3, 0x48(r30);
  sth r3, 0x48(r31);
  lhz r3, 0x4a(r30);
  sth r3, 0x4a(r31);
  lhz r3, 0x4c(r30);
  sth r3, 0x4c(r31);
  lhz r3, 0x4e(r30);
  sth r3, 0x4e(r31);
  lhz r3, 0x50(r30);
  sth r3, 0x50(r31);
  lwz r3, 0x24(r28);
  stw r0, 0(r3);
  stw r0, 4(r3);
  stw r0, 8(r3);
  stw r0, 0xc(r3);
  stw r0, 0x10(r3);
  stw r0, 0x14(r3);
  stw r0, 0x18(r3);
  stw r0, 0x1c(r3);
  stw r0, 0x20(r3);
  stw r0, 0x24(r3);
  stw r0, 0x28(r3);
  stw r0, 0x2c(r3);
  stw r0, 0x30(r3);
  stw r0, 0x34(r3);
  stw r0, 0x38(r3);
  stw r0, 0x3c(r3);
lbl_801273f4:
  rlwinm. r0, r29, 0, 0x18, 0x18;
  beq lbl_8012740c;
  addi r3, r31, 0x52;
  addi r4, r30, 0x52;
  li r5, 0x18;
  bl memcpy;
lbl_8012740c:
  rlwinm. r0, r29, 0, 0x16, 0x16;
  beq lbl_80127428;
  lhz r3, 0x6a(r31);
  lha r0, 0x6c(r30);
  sth r3, 0x6a(r30);
  sth r0, 0x6c(r31);
  b lbl_80127440;
lbl_80127428:
  rlwinm. r0, r29, 0, 0x17, 0x17;
  beq lbl_80127440;
  lhz r0, 0x6a(r30);
  sth r0, 0x6a(r31);
  lha r0, 0x6c(r30);
  sth r0, 0x6c(r31);
lbl_80127440:
  rlwinm. r0, r29, 0, 0x11, 0x14;
  beq lbl_80127498;
  rlwinm. r0, r29, 0, 0x14, 0x14;
  beq lbl_80127458;
  lhz r0, 0x6e(r30);
  sth r0, 0x6e(r31);
lbl_80127458:
  rlwinm. r0, r29, 0, 0x13, 0x13;
  beq lbl_80127468;
  lwz r0, 0x72(r30);
  stw r0, 0x72(r31);
lbl_80127468:
  rlwinm. r0, r29, 0, 0x12, 0x12;
  beq lbl_80127478;
  lwz r0, 0x76(r30);
  stw r0, 0x76(r31);
lbl_80127478:
  rlwinm. r0, r29, 0, 0x11, 0x11;
  beq lbl_8012748c;
  lwz r0, 0x7a(r30);
  stw r0, 0x7a(r31);
  b lbl_801274d4;
lbl_8012748c:
  lwz r0, 0x7a(r31);
  stw r0, 0x7a(r30);
  b lbl_801274d4;
lbl_80127498:
  rlwinm. r0, r29, 0, 0x15, 0x15;
  beq lbl_801274c4;
  lwz r0, 0x6e(r30);
  stw r0, 0x6e(r31);
  lwz r0, 0x72(r30);
  stw r0, 0x72(r31);
  lwz r0, 0x76(r30);
  stw r0, 0x76(r31);
  lwz r0, 0x7a(r30);
  stw r0, 0x7a(r31);
  b lbl_801274d4;
lbl_801274c4:
  lhz r0, 0x7a(r31);
  sth r0, 0x7a(r30);
  lhz r0, 0x7c(r31);
  sth r0, 0x7c(r30);
lbl_801274d4:
  rlwinm. r0, r29, 0, 0x10, 0x10;
  beq lbl_8012752c;
  lwz r0, 0x7e(r30);
  stw r0, 0x7e(r31);
  lwz r0, 0x82(r30);
  stw r0, 0x82(r31);
  lwz r0, 0x86(r30);
  stw r0, 0x86(r31);
  lwz r0, 0x8a(r30);
  stw r0, 0x8a(r31);
  lwz r0, 0x8e(r30);
  stw r0, 0x8e(r31);
  lwz r0, 0x92(r30);
  stw r0, 0x92(r31);
  lwz r0, 0x96(r30);
  stw r0, 0x96(r31);
  lwz r0, 0x9a(r30);
  stw r0, 0x9a(r31);
  lwz r0, 0x9e(r30);
  stw r0, 0x9e(r31);
  lwz r0, 0xa2(r30);
  stw r0, 0xa2(r31);
lbl_8012752c:
  rlwinm. r0, r29, 0, 0xe, 0xe;
  beq lbl_80127548;
  lhz r0, 0xa6(r30);
  sth r0, 0xa6(r31);
  lhz r0, 0xa8(r30);
  sth r0, 0xa8(r31);
  b lbl_80127588;
lbl_80127548:
  rlwinm. r0, r29, 0, 0xf, 0xf;
  beq lbl_80127588;
  lhz r0, 0xa6(r30);
  sth r0, 0xa6(r31);
  lhz r0, 0xa8(r30);
  sth r0, 0xa8(r31);
  lhz r0, 0xaa(r30);
  sth r0, 0xaa(r31);
  lhz r0, 0xac(r30);
  sth r0, 0xac(r31);
  lhz r0, 0xae(r30);
  sth r0, 0xae(r31);
  lhz r0, 0xb0(r30);
  sth r0, 0xb0(r31);
  lhz r0, 0xb2(r30);
  sth r0, 0xb2(r31);
lbl_80127588:
  rlwinm. r0, r29, 0, 0xd, 0xd;
  beq lbl_801275a8;
  lhz r0, 0xb4(r30);
  sth r0, 0xb4(r31);
  lhz r0, 0xb6(r30);
  sth r0, 0xb6(r31);
  lhz r0, 0xb8(r30);
  sth r0, 0xb8(r31);
lbl_801275a8:
  rlwinm. r0, r29, 0, 0xb, 0xb;
  beq lbl_801275c4;
  lhz r0, 0xbe(r30);
  sth r0, 0xbe(r31);
  lhz r0, 0xc0(r30);
  sth r0, 0xc0(r31);
  b lbl_801275ec;
lbl_801275c4:
  rlwinm. r0, r29, 0, 0xc, 0xc;
  beq lbl_801275ec;
  lhz r0, 0xba(r30);
  sth r0, 0xba(r31);
  lhz r0, 0xbc(r30);
  sth r0, 0xbc(r31);
  lhz r0, 0xbe(r30);
  sth r0, 0xbe(r31);
  lhz r0, 0xc0(r30);
  sth r0, 0xc0(r31);
lbl_801275ec:
  rlwinm. r0, r29, 0, 9, 9;
  beq lbl_80127620;
  lhz r0, 0xcc(r30);
  sth r0, 0xcc(r31);
  lhz r0, 0xce(r30);
  sth r0, 0xce(r31);
  lhz r0, 0xd0(r30);
  sth r0, 0xd0(r31);
  lhz r0, 0xd2(r30);
  sth r0, 0xd2(r31);
  lhz r0, 0xd4(r30);
  sth r0, 0xd4(r31);
  b lbl_80127678;
lbl_80127620:
  rlwinm. r0, r29, 0, 0xa, 0xa;
  beq lbl_80127678;
  lhz r0, 0xc2(r30);
  sth r0, 0xc2(r31);
  lhz r0, 0xc4(r30);
  sth r0, 0xc4(r31);
  lhz r0, 0xc6(r30);
  sth r0, 0xc6(r31);
  lhz r0, 0xc8(r30);
  sth r0, 0xc8(r31);
  lhz r0, 0xca(r30);
  sth r0, 0xca(r31);
  lhz r0, 0xcc(r30);
  sth r0, 0xcc(r31);
  lhz r0, 0xce(r30);
  sth r0, 0xce(r31);
  lhz r0, 0xd0(r30);
  sth r0, 0xd0(r31);
  lhz r0, 0xd2(r30);
  sth r0, 0xd2(r31);
  lhz r0, 0xd4(r30);
  sth r0, 0xd4(r31);
lbl_80127678:
  rlwinm. r0, r29, 0, 8, 8;
  beq lbl_80127688;
  lhz r0, 0xd6(r30);
  sth r0, 0xd6(r31);
lbl_80127688:
  rlwinm. r0, r29, 0, 7, 7;
  beq lbl_80127698;
  lhz r0, 0xd8(r30);
  sth r0, 0xd8(r31);
lbl_80127698:
  rlwinm. r0, r29, 0, 6, 6;
  beq lbl_801276b0;
  addi r3, r31, 0xda;
  addi r4, r30, 0xda;
  li r5, 0x20;
  bl memcpy;
lbl_801276b0:
  rlwinm. r0, r29, 0, 5, 5;
  beq lbl_801276c8;
  addi r3, r31, 0xfa;
  addi r4, r30, 0xfa;
  li r5, 0x10;
  bl memcpy;
lbl_801276c8:
  rlwinm. r0, r29, 0, 4, 4;
  beq lbl_801276e0;
  addi r3, r31, 0x10a;
  addi r4, r30, 0x10a;
  li r5, 0xa;
  bl memcpy;
lbl_801276e0:
  rlwinm. r0, r29, 0, 2, 2;
  beq lbl_801276fc;
  lhz r0, 0x118(r30);
  sth r0, 0x118(r31);
  lhz r0, 0x11a(r30);
  sth r0, 0x11a(r31);
  b lbl_80127788;
lbl_801276fc:
  rlwinm. r0, r29, 0, 1, 1;
  beq lbl_80127730;
  lhz r0, 0x11e(r30);
  sth r0, 0x11e(r31);
  lhz r0, 0x120(r30);
  sth r0, 0x120(r31);
  lhz r0, 0x122(r30);
  sth r0, 0x122(r31);
  lhz r0, 0x124(r30);
  sth r0, 0x124(r31);
  lhz r0, 0x126(r30);
  sth r0, 0x126(r31);
  b lbl_80127788;
lbl_80127730:
  rlwinm. r0, r29, 0, 3, 3;
  beq lbl_80127788;
  lhz r0, 0x114(r30);
  sth r0, 0x114(r31);
  lhz r0, 0x116(r30);
  sth r0, 0x116(r31);
  lhz r0, 0x118(r30);
  sth r0, 0x118(r31);
  lhz r0, 0x11a(r30);
  sth r0, 0x11a(r31);
  lhz r0, 0x11c(r30);
  sth r0, 0x11c(r31);
  lhz r0, 0x11e(r30);
  sth r0, 0x11e(r31);
  lhz r0, 0x120(r30);
  sth r0, 0x120(r31);
  lhz r0, 0x122(r30);
  sth r0, 0x122(r31);
  lhz r0, 0x124(r30);
  sth r0, 0x124(r31);
  lhz r0, 0x126(r30);
  sth r0, 0x126(r31);
lbl_80127788:
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

// Symbol: __AXSyncPBs
// PAL: 0x801277a8..0x80127ab8
MARK_BINARY_BLOB(__AXSyncPBs, 0x801277a8, 0x80127ab8);
asm UNKNOWN_FUNCTION(__AXSyncPBs) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_25;
  lwz r0, __AXMaxVoices;
  li r29, 0;
  mr r25, r3;
  stw r29, __AXNumVoices;
  mulli r4, r0, 0x140;
  lwz r3, __AXPB;
  bl DCInvalidateRange;
  lwz r0, __AXMaxVoices;
  lwz r3, __AXITD;
  slwi r4, r0, 6;
  bl DCInvalidateRange;
  bl __AXGetCommandListCycles;
  lwz r0, __AXMaxVoices;
  lis r31, unk_8027e840@ha;
  lis r30, unk_8027e7c0@ha;
  li r27, 0x1f;
  mulli r0, r0, 0x258;
  la r31, unk_8027e840@l(r31); // 0x8027e840
  la r30, unk_8027e7c0@l(r30); // 0x8027e7c0
  add r0, r3, r0;
  add r3, r0, r25;
  addi r28, r3, 0x20;
lbl_80127814:
  mr r3, r27;
  bl __AXGetStackHead;
  mr r26, r3;
  b lbl_80127a14;
lbl_80127824:
  lhz r0, 0x6c(r26);
  cmplwi r0, 1;
  bne lbl_80127834;
  addi r28, r28, 0x81;
lbl_80127834:
  lwz r0, 0x20(r26);
  cmpwi r0, 0;
  beq lbl_80127854;
  lwz r0, 0x18(r26);
  lwz r3, __AXPB;
  mulli r0, r0, 0x140;
  add r3, r3, r0;
  bl __AXDepopVoice;
lbl_80127854:
  lhz r0, 0x38(r26);
  cmplwi r0, 1;
  bne lbl_80127a00;
  lhz r0, 0xe2(r26);
  addi r28, r28, 0x183;
  cmpwi r0, 0;
  beq lbl_80127874;
  addi r28, r28, 0x135;
lbl_80127874:
  lhz r0, 0xea(r26);
  cmpwi r0, 0;
  beq lbl_80127884;
  addi r28, r28, 0x400;
lbl_80127884:
  lhz r0, 0x6c(r26);
  cmplwi r0, 1;
  bne lbl_80127894;
  addi r28, r28, 0x1b;
lbl_80127894:
  lhz r3, 0x30(r26);
  lhz r0, 0xce(r26);
  cmpwi r3, 0;
  lhz r4, 0xd0(r26);
  rlwimi r4, r0, 0x10, 0, 0xf;
  bne lbl_801278c4;
  slwi r3, r4, 9;
  addis r3, r3, 1;
  addi r0, r3, -32768;
  srwi r3, r0, 0x10;
  addi r0, r3, 0x619;
  b lbl_801278e4;
lbl_801278c4:
  cmplwi r3, 1;
  li r0, 0x25d;
  bne lbl_801278e4;
  slwi r3, r4, 9;
  addis r3, r3, 1;
  addi r0, r3, -32768;
  srwi r3, r0, 0x10;
  addi r0, r3, 0x5ba;
lbl_801278e4:
  lwz r4, 0x34(r26);
  add r28, r28, r0;
  lhz r0, 0xfe(r26);
  rlwinm r5, r4, 0xd, 0x19, 0x1d;
  rlwinm r3, r4, 2, 0x19, 0x1d;
  rlwinm r6, r4, 8, 0x19, 0x1d;
  rlwinm r4, r4, 0x12, 0x19, 0x1d;
  cmplwi r0, 1;
  lwzx r5, r30, r5;
  lwzx r0, r30, r3;
  lwzx r6, r30, r6;
  lwzx r4, r30, r4;
  add r0, r5, r0;
  add r3, r28, r6;
  add r0, r4, r0;
  add r28, r3, r0;
  bne lbl_801279b0;
  lhz r0, 0x13c(r26);
  addi r28, r28, 0x265;
  cmplwi r0, 1;
  bne lbl_80127940;
  addi r28, r28, 0x76;
  b lbl_8012794c;
lbl_80127940:
  cmplwi r0, 2;
  bne lbl_8012794c;
  addi r28, r28, 0x342;
lbl_8012794c:
  lhz r3, 0x100(r26);
  rlwinm r4, r3, 0x1e, 0x1c, 0x1d;
  rlwinm r0, r3, 2, 0x1c, 0x1d;
  lwzx r4, r31, r4;
  rlwinm r9, r3, 0x14, 0x1c, 0x1d;
  lwzx r0, r31, r0;
  rlwinm r8, r3, 0x16, 0x1c, 0x1d;
  rlwinm r7, r3, 0x18, 0x1c, 0x1d;
  rlwinm r6, r3, 0x1a, 0x1c, 0x1d;
  rlwinm r5, r3, 0x1c, 0x1c, 0x1d;
  rlwinm r3, r3, 0, 0x1c, 0x1d;
  lwzx r7, r31, r7;
  add r0, r4, r0;
  lwzx r3, r31, r3;
  lwzx r9, r31, r9;
  add r7, r28, r7;
  lwzx r8, r31, r8;
  add r0, r3, r0;
  lwzx r6, r31, r6;
  lwzx r4, r31, r5;
  add r8, r9, r8;
  add r3, r8, r7;
  add r4, r6, r4;
  add r0, r4, r0;
  add r28, r3, r0;
lbl_801279b0:
  lwz r0, __AXMaxDspCycles;
  cmplw r0, r28;
  ble lbl_801279c8;
  mr r3, r26;
  bl __AXServiceVPB;
  b lbl_80127a08;
lbl_801279c8:
  lwz r0, 0x18(r26);
  lwz r3, __AXPB;
  mulli r0, r0, 0x140;
  add r25, r3, r0;
  lhz r0, 0x10(r25);
  cmplwi r0, 1;
  bne lbl_801279ec;
  mr r3, r25;
  bl __AXDepopVoice;
lbl_801279ec:
  sth r29, 0x38(r26);
  mr r3, r26;
  sth r29, 0x10(r25);
  bl __AXPushCallbackStack;
  b lbl_80127a08;
lbl_80127a00:
  mr r3, r26;
  bl __AXServiceVPB;
lbl_80127a08:
  stw r29, 0x1c(r26);
  stw r29, 0x20(r26);
  lwz r26, 0(r26);
lbl_80127a14:
  cmpwi r26, 0;
  bne lbl_80127824;
  addic. r27, r27, -1;
  bne lbl_80127814;
  stw r28, __AXRecDspCycles;
  li r3, 0;
  bl __AXGetStackHead;
  mr r25, r3;
  li r26, 0;
  b lbl_80127a78;
lbl_80127a3c:
  lwz r0, 0x20(r25);
  cmpwi r0, 0;
  beq lbl_80127a5c;
  lwz r0, 0x18(r25);
  lwz r3, __AXPB;
  mulli r0, r0, 0x140;
  add r3, r3, r0;
  bl __AXDepopVoice;
lbl_80127a5c:
  stw r26, 0x20(r25);
  lwz r0, 0x18(r25);
  lwz r3, __AXPB;
  mulli r0, r0, 0x140;
  add r3, r3, r0;
  sth r26, 0x10(r3);
  lwz r25, 0(r25);
lbl_80127a78:
  cmpwi r25, 0;
  bne lbl_80127a3c;
  lwz r0, __AXMaxVoices;
  lwz r3, __AXPB;
  mulli r4, r0, 0x140;
  bl DCFlushRange;
  lwz r0, __AXMaxVoices;
  lwz r3, __AXITD;
  slwi r4, r0, 6;
  bl DCFlushRange;
  addi r11, r1, 0x30;
  bl _restgpr_25;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: __AXGetPBs
// PAL: 0x80127ab8..0x80127ac0
AXPB* __AXGetPBs() { return __AXPB; }

// Symbol: __AXSetPBDefault
// PAL: 0x80127ac0..0x80127b00
MARK_BINARY_BLOB(__AXSetPBDefault, 0x80127ac0, 0x80127b00);
asm UNKNOWN_FUNCTION(__AXSetPBDefault) {
  // clang-format off
  nofralloc;
  lis r4, 0x18a8;
  li r5, 0;
  addi r0, r4, 0x24;
  sth r5, 0x38(r3);
  sth r5, 0x6c(r3);
  stw r0, 0x1c(r3);
  sth r5, 0xe2(r3);
  sth r5, 0xea(r3);
  sth r5, 0xfe(r3);
  sth r5, 0x13c(r3);
  sth r5, 0x132(r3);
  sth r5, 0x134(r3);
  sth r5, 0x136(r3);
  sth r5, 0x138(r3);
  sth r5, 0x13a(r3);
  blr;
  // clang-format on
}

// Symbol: __AXVPBInit
// PAL: 0x80127b00..0x80127db8
MARK_BINARY_BLOB(__AXVPBInit, 0x80127b00, 0x80127db8);
asm UNKNOWN_FUNCTION(__AXVPBInit) {
  // clang-format off
  nofralloc;
  lis r5, __s_AXPB@ha;
  lis r4, __s_AXITD@ha;
  lis r3, __s_AXVPB@ha;
  li r0, 0x60;
  la r5, __s_AXPB@l(r5);
  la r4, __s_AXITD@l(r4);
  la r3, __s_AXVPB@l(r3);
  stw r0, __AXMaxVoices;
  stw r5, __AXPB;
  stw r4, __AXITD;
  stw r3, __AXVPB;
  b lbl_80127b30;
lbl_80127b30:
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_25;
  lis r4, 0x8000;
  lis r3, 0x8905;
  lwz r4, 0xf8(r4);
  addi r5, r3, -687;
  lwz r0, __AXMaxVoices;
  li r3, 0;
  mulhwu r5, r5, r4;
  stw r3, __AXRecDspCycles;
  lwz r7, __AXPB;
  mulli r6, r0, 0x50;
  subf r0, r5, r4;
  srwi r0, r0, 1;
  add r0, r0, r5;
  cmpwi r6, 0;
  srwi r0, r0, 9;
  stw r0, __AXMaxDspCycles;
  beq lbl_80127bd4;
  rlwinm. r0, r6, 0x1d, 3, 0x1f;
  mtctr r0;
  beq lbl_80127bc4;
lbl_80127b94:
  stw r3, 0(r7);
  stw r3, 4(r7);
  stw r3, 8(r7);
  stw r3, 0xc(r7);
  stw r3, 0x10(r7);
  stw r3, 0x14(r7);
  stw r3, 0x18(r7);
  stw r3, 0x1c(r7);
  addi r7, r7, 0x20;
  bdnz lbl_80127b94;
  andi. r6, r6, 7;
  beq lbl_80127bd4;
lbl_80127bc4:
  mtctr r6;
lbl_80127bc8:
  stw r3, 0(r7);
  addi r7, r7, 4;
  bdnz lbl_80127bc8;
lbl_80127bd4:
  lwz r0, __AXMaxVoices;
  li r3, 0;
  lwz r4, __AXITD;
  rlwinm. r5, r0, 4, 0, 0x1b;
  beq lbl_80127c34;
  rlwinm. r0, r5, 0x1d, 3, 0x1f;
  mtctr r0;
  beq lbl_80127c24;
lbl_80127bf4:
  stw r3, 0(r4);
  stw r3, 4(r4);
  stw r3, 8(r4);
  stw r3, 0xc(r4);
  stw r3, 0x10(r4);
  stw r3, 0x14(r4);
  stw r3, 0x18(r4);
  stw r3, 0x1c(r4);
  addi r4, r4, 0x20;
  bdnz lbl_80127bf4;
  andi. r5, r5, 7;
  beq lbl_80127c34;
lbl_80127c24:
  mtctr r5;
lbl_80127c28:
  stw r3, 0(r4);
  addi r4, r4, 4;
  bdnz lbl_80127c28;
lbl_80127c34:
  lwz r0, __AXMaxVoices;
  li r3, 0;
  lwz r4, __AXVPB;
  mulli r5, r0, 0x5a;
  cmpwi r5, 0;
  beq lbl_80127c98;
  rlwinm. r0, r5, 0x1d, 3, 0x1f;
  mtctr r0;
  beq lbl_80127c88;
lbl_80127c58:
  stw r3, 0(r4);
  stw r3, 4(r4);
  stw r3, 8(r4);
  stw r3, 0xc(r4);
  stw r3, 0x10(r4);
  stw r3, 0x14(r4);
  stw r3, 0x18(r4);
  stw r3, 0x1c(r4);
  addi r4, r4, 0x20;
  bdnz lbl_80127c58;
  andi. r5, r5, 7;
  beq lbl_80127c98;
lbl_80127c88:
  mtctr r5;
lbl_80127c8c:
  stw r3, 0(r4);
  addi r4, r4, 4;
  bdnz lbl_80127c8c;
lbl_80127c98:
  lis r3, 0x18a8;
  li r31, 0;
  addi r29, r3, 0x24;
  li r27, 0;
  li r26, 0;
  li r25, 0;
  li r28, 0;
  li r30, 1;
  b lbl_80127d88;
lbl_80127cbc:
  lwz r0, __AXVPB;
  lwz r5, __AXPB;
  lwz r4, __AXITD;
  add r3, r0, r25;
  add r5, r5, r27;
  stw r31, 0x18(r3);
  add r6, r4, r26;
  stw r6, 0x24(r3);
  sth r28, 0x38(r3);
  sth r28, 0x6c(r3);
  stw r29, 0x1c(r3);
  sth r28, 0xe2(r3);
  sth r28, 0xea(r3);
  sth r28, 0xfe(r3);
  sth r28, 0x13c(r3);
  sth r28, 0x132(r3);
  sth r28, 0x134(r3);
  sth r28, 0x136(r3);
  sth r28, 0x138(r3);
  sth r28, 0x13a(r3);
  lwz r4, __AXMaxVoices;
  addi r0, r4, -1;
  cmplw r31, r0;
  bne lbl_80127d30;
  sth r28, 2(r5);
  sth r28, 0(r5);
  sth r28, 0x2a(r3);
  sth r28, 0x28(r3);
  b lbl_80127d48;
lbl_80127d30:
  addi r0, r5, 0x140;
  srwi r4, r0, 0x10;
  sth r4, 0x28(r3);
  sth r0, 0x2a(r3);
  sth r4, 0(r5);
  sth r0, 2(r5);
lbl_80127d48:
  srwi r0, r5, 0x10;
  srwi r4, r6, 0x10;
  sth r0, 0x2c(r3);
  sth r5, 0x2e(r3);
  sth r0, 4(r5);
  sth r5, 6(r5);
  sth r4, 0x6e(r3);
  sth r6, 0x70(r3);
  sth r4, 0x46(r5);
  sth r6, 0x48(r5);
  stw r30, 0xc(r3);
  bl __AXPushFreeStack;
  addi r27, r27, 0x140;
  addi r26, r26, 0x40;
  addi r25, r25, 0x168;
  addi r31, r31, 1;
lbl_80127d88:
  lwz r0, __AXMaxVoices;
  cmplw r31, r0;
  blt lbl_80127cbc;
  mulli r4, r0, 0x140;
  lwz r3, __AXPB;
  bl DCFlushRange;
  addi r11, r1, 0x30;
  bl _restgpr_25;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: AXSetVoiceState
// PAL: 0x80127db8..0x80127e28
MARK_BINARY_BLOB(AXSetVoiceState, 0x80127db8, 0x80127e28);
asm UNKNOWN_FUNCTION(AXSetVoiceState) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  bl OSDisableInterrupts;
  lhz r0, 0x38(r30);
  cmplw r0, r31;
  bne lbl_80127dec;
  bl OSRestoreInterrupts;
  b lbl_80127e10;
lbl_80127dec:
  lwz r0, 0x1c(r30);
  cmpwi r31, 0;
  sth r31, 0x38(r30);
  ori r0, r0, 4;
  stw r0, 0x1c(r30);
  bne lbl_80127e0c;
  li r0, 1;
  stw r0, 0x20(r30);
lbl_80127e0c:
  bl OSRestoreInterrupts;
lbl_80127e10:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: AXSetVoiceAddr
// PAL: 0x80127e28..0x80127f20
MARK_BINARY_BLOB(AXSetVoiceAddr, 0x80127e28, 0x80127f20);
asm UNKNOWN_FUNCTION(AXSetVoiceAddr) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  bl OSDisableInterrupts;
  lwz r0, 0(r31);
  stw r0, 0x96(r30);
  lwz r0, 4(r31);
  stw r0, 0x9a(r30);
  lwz r0, 8(r31);
  stw r0, 0x9e(r30);
  lwz r0, 0xc(r31);
  stw r0, 0xa2(r30);
  lhz r0, 2(r31);
  cmpwi r0, 0xa;
  beq lbl_80127e90;
  bge lbl_80127e84;
  cmpwi r0, 0;
  beq lbl_80127ef4;
  b lbl_80127ef4;
lbl_80127e84:
  cmpwi r0, 0x19;
  beq lbl_80127ec4;
  b lbl_80127ef4;
lbl_80127e90:
  li r4, 0;
  lis r0, 0x800;
  stw r4, 0xa6(r30);
  stw r4, 0xaa(r30);
  stw r4, 0xae(r30);
  stw r4, 0xb2(r30);
  stw r4, 0xb6(r30);
  stw r4, 0xba(r30);
  stw r4, 0xbe(r30);
  stw r4, 0xc2(r30);
  stw r0, 0xc6(r30);
  stw r4, 0xca(r30);
  b lbl_80127ef4;
lbl_80127ec4:
  li r4, 0;
  lis r0, 0x100;
  stw r4, 0xa6(r30);
  stw r4, 0xaa(r30);
  stw r4, 0xae(r30);
  stw r4, 0xb2(r30);
  stw r4, 0xb6(r30);
  stw r4, 0xba(r30);
  stw r4, 0xbe(r30);
  stw r4, 0xc2(r30);
  stw r0, 0xc6(r30);
  stw r4, 0xca(r30);
lbl_80127ef4:
  lwz r0, 0x1c(r30);
  rlwinm r0, r0, 0, 0x15, 0x10;
  ori r0, r0, 0x8400;
  stw r0, 0x1c(r30);
  bl OSRestoreInterrupts;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: AXGetLpfCoefs
// PAL: 0x80127f20..0x80127fdc
MARK_BINARY_BLOB(AXGetLpfCoefs, 0x80127f20, 0x80127fdc);
asm UNKNOWN_FUNCTION(AXGetLpfCoefs) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  stfd f31, 0x20(r1);
  psq_st f31, 40(r1), 0, 0;
  lis r0, 0x4330;
  lfd f3, _lit_803884c0;
  stw r3, 0xc(r1);
  lfs f1, _lit_803884ac;
  stw r0, 8(r1);
  lfs f0, _lit_803884b0;
  lfd f2, 8(r1);
  stw r31, 0x1c(r1);
  mr r31, r5;
  fsubs f2, f2, f3;
  stw r30, 0x18(r1);
  mr r30, r4;
  fmuls f1, f1, f2;
  fdivs f1, f1, f0;
  bl cos;
  frsp f2, f1;
  lfs f1, _lit_803884a8;
  lfs f0, _lit_803884b4;
  fsubs f31, f1, f2;
  fmuls f1, f31, f31;
  fsubs f1, f1, f0;
  bl sqrt;
  frsp f1, f1;
  lfs f0, _lit_803884b8;
  fsubs f1, f1, f31;
  fneg f1, f1;
  fmuls f0, f0, f1;
  fctiwz f0, f0;
  stfd f0, 0x10(r1);
  lwz r3, 0x14(r1);
  clrlwi r0, r3, 0x10;
  sth r3, 0(r31);
  subfic r0, r0, 0x7fff;
  sth r0, 0(r30);
  psq_l f31, 40(r1), 0, 0;
  lfd f31, 0x20(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: AXSetMaxDspCycles
// PAL: 0x80127fdc..0x80127fe4
MARK_BINARY_BLOB(AXSetMaxDspCycles, 0x80127fdc, 0x80127fe4);
asm UNKNOWN_FUNCTION(AXSetMaxDspCycles) {
  // clang-format off
  nofralloc;
  stw r3, __AXMaxDspCycles;
  blr;
  // clang-format on
}

// Symbol: AXGetMaxVoices
// PAL: 0x80127fe4..0x80127fec
MARK_BINARY_BLOB(AXGetMaxVoices, 0x80127fe4, 0x80127fec);
asm UNKNOWN_FUNCTION(AXGetMaxVoices) {
  // clang-format off
  nofralloc;
  lwz r3, __AXMaxVoices;
  blr;
  // clang-format on
}
