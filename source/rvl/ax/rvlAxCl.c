#include "cl.h"

#include "axAux.h"

#include <rvl/os/osCache.h>

#include "spb.h"
#include "vpb.h"

u16 _unk_802f7340[2][64] __attribute__((aligned(32)));

u32 _unk_803864f8;
u32 _unk_803864f4;
u32 _unk_803864f0;
u32 _unk_803864ec;
u16 _unk_803864e8;
u16 _unk_803864e6;
u16 _unk_803864e4;
u16 _unk_803864e2;
u16 _unk_803864e0;

// Symbol: __AXGetCommandListCycles
// PAL: 0x80125bac..0x80125bb4
MARK_BINARY_BLOB(__AXGetCommandListCycles, 0x80125bac, 0x80125bb4);
asm UNKNOWN_FUNCTION(__AXGetCommandListCycles) {
  // clang-format off
  nofralloc;
  lwz r3, _unk_803864ec;
  blr;
  // clang-format on
}

// Symbol: __AXGetCommandListAddress
// PAL: 0x80125bb4..0x80125be4
MARK_BINARY_BLOB(__AXGetCommandListAddress, 0x80125bb4, 0x80125be4);
asm UNKNOWN_FUNCTION(__AXGetCommandListAddress) {
  // clang-format off
  nofralloc;
  lwz r4, _unk_803864f8;
  lis r5, _unk_802f7340@ha;
  la r5, _unk_802f7340@l(r5);
  addi r3, r4, 1;
  slwi r6, r4, 7;
  rlwinm r0, r3, 7, 0x18, 0x18;
  clrlwi r4, r3, 0x1f;
  add r3, r5, r6;
  add r0, r5, r0;
  stw r4, _unk_803864f8;
  stw r0, _unk_803864f4;
  blr;
  // clang-format on
}

// Symbol: __AXNextFrame
// PAL: 0x80125be4..0x801265a4
MARK_BINARY_BLOB(__AXNextFrame, 0x80125be4, 0x801265a4);
asm UNKNOWN_FUNCTION(__AXNextFrame) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  li r0, 0x1e83;
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  lwz r31, _unk_803864f4;
  stw r0, _unk_803864ec;
  bl __AXGetStudio;
  stw r3, 8(r1);
  li r0, 0;
  lwz r3, _unk_803864f4;
  sth r0, 0(r3);
  lwz r3, _unk_803864f4;
  lwz r0, 8(r1);
  addi r3, r3, 2;
  stw r3, _unk_803864f4;
  srwi r0, r0, 0x10;
  sth r0, 0(r3);
  lwz r3, _unk_803864f4;
  lwz r0, 8(r1);
  addi r3, r3, 2;
  stw r3, _unk_803864f4;
  sth r0, 0(r3);
  lwz r4, _unk_803864f4;
  lwz r3, _unk_803864ec;
  lwz r0, _unk_803864f0;
  addi r4, r4, 2;
  addi r3, r3, 0x101e;
  stw r4, _unk_803864f4;
  cmpwi r0, 1;
  stw r3, _unk_803864ec;
  beq lbl_80125ce0;
  bge lbl_80125c8c;
  cmpwi r0, 0;
  bge lbl_80125c98;
  b lbl_80125d6c;
lbl_80125c8c:
  cmpwi r0, 3;
  bge lbl_80125d6c;
  b lbl_80125d28;
lbl_80125c98:
  li r3, 1;
  srwi r0, r28, 0x10;
  sth r3, 0(r4);
  lwz r3, _unk_803864f4;
  addi r3, r3, 2;
  stw r3, _unk_803864f4;
  sth r0, 0(r3);
  lwz r3, _unk_803864f4;
  addi r3, r3, 2;
  stw r3, _unk_803864f4;
  sth r28, 0(r3);
  lwz r4, _unk_803864f4;
  lwz r3, _unk_803864ec;
  addi r5, r4, 2;
  addi r0, r3, 0x2dd;
  stw r5, _unk_803864f4;
  stw r0, _unk_803864ec;
  b lbl_80125d6c;
lbl_80125ce0:
  li r3, 2;
  srwi r0, r28, 0x10;
  sth r3, 0(r4);
  lwz r3, _unk_803864f4;
  addi r3, r3, 2;
  stw r3, _unk_803864f4;
  sth r0, 0(r3);
  lwz r3, _unk_803864f4;
  addi r3, r3, 2;
  stw r3, _unk_803864f4;
  sth r28, 0(r3);
  lwz r4, _unk_803864f4;
  lwz r3, _unk_803864ec;
  addi r5, r4, 2;
  addi r0, r3, 0x33d;
  stw r5, _unk_803864f4;
  stw r0, _unk_803864ec;
  b lbl_80125d6c;
lbl_80125d28:
  li r3, 3;
  srwi r0, r28, 0x10;
  sth r3, 0(r4);
  lwz r3, _unk_803864f4;
  addi r3, r3, 2;
  stw r3, _unk_803864f4;
  sth r0, 0(r3);
  lwz r3, _unk_803864f4;
  addi r3, r3, 2;
  stw r3, _unk_803864f4;
  sth r28, 0(r3);
  lwz r4, _unk_803864f4;
  lwz r3, _unk_803864ec;
  addi r5, r4, 2;
  addi r0, r3, 0x39d;
  stw r5, _unk_803864f4;
  stw r0, _unk_803864ec;
lbl_80125d6c:
  bl __AXGetPBs;
  stw r3, 8(r1);
  li r0, 4;
  lwz r3, _unk_803864f4;
  sth r0, 0(r3);
  lwz r3, _unk_803864f4;
  lwz r0, 8(r1);
  addi r3, r3, 2;
  stw r3, _unk_803864f4;
  srwi r0, r0, 0x10;
  sth r0, 0(r3);
  lwz r3, _unk_803864f4;
  lwz r0, 8(r1);
  addi r3, r3, 2;
  stw r3, _unk_803864f4;
  sth r0, 0(r3);
  lwz r3, _unk_803864f4;
  lwz r0, _unk_803864f0;
  addi r5, r3, 2;
  cmplwi r0, 2;
  stw r5, _unk_803864f4;
  bne lbl_801260e8;
  addi r3, r1, 8;
  bl __AXGetAuxAInput;
  lwz r0, 8(r1);
  cmpwi r0, 0;
  beq lbl_80125f54;
  lwz r4, _unk_803864f4;
  li r0, 8;
  addi r3, r1, 8;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  lhz r0, _unk_803864e4;
  addi r4, r4, 2;
  stw r4, _unk_803864f4;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  lwz r0, 8(r1);
  addi r4, r4, 2;
  stw r4, _unk_803864f4;
  srwi r0, r0, 0x10;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  lwz r0, 8(r1);
  addi r4, r4, 2;
  stw r4, _unk_803864f4;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  addi r5, r4, 2;
  stw r5, _unk_803864f4;
  bl __AXGetAuxAInputDpl2;
  lwz r0, 8(r1);
  addi r3, r1, 8;
  lwz r4, _unk_803864f4;
  srwi r0, r0, 0x10;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  lwz r0, 8(r1);
  addi r4, r4, 2;
  stw r4, _unk_803864f4;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  addi r5, r4, 2;
  stw r5, _unk_803864f4;
  bl __AXGetAuxAOutput;
  lwz r0, 8(r1);
  addi r3, r1, 8;
  lwz r4, _unk_803864f4;
  srwi r0, r0, 0x10;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  lwz r0, 8(r1);
  addi r4, r4, 2;
  stw r4, _unk_803864f4;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  addi r5, r4, 2;
  stw r5, _unk_803864f4;
  bl __AXGetAuxAOutputDpl2R;
  lwz r0, 8(r1);
  addi r3, r1, 8;
  lwz r4, _unk_803864f4;
  srwi r0, r0, 0x10;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  lwz r0, 8(r1);
  addi r4, r4, 2;
  stw r4, _unk_803864f4;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  addi r5, r4, 2;
  stw r5, _unk_803864f4;
  bl __AXGetAuxAOutputDpl2Ls;
  lwz r0, 8(r1);
  addi r3, r1, 8;
  lwz r4, _unk_803864f4;
  srwi r0, r0, 0x10;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  lwz r0, 8(r1);
  addi r4, r4, 2;
  stw r4, _unk_803864f4;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  addi r5, r4, 2;
  stw r5, _unk_803864f4;
  bl __AXGetAuxAOutputDpl2Rs;
  lwz r0, 8(r1);
  lwz r3, _unk_803864f4;
  srwi r0, r0, 0x10;
  sth r0, 0(r3);
  lwz r3, _unk_803864f4;
  lwz r0, 8(r1);
  addi r3, r3, 2;
  stw r3, _unk_803864f4;
  sth r0, 0(r3);
  lwz r4, _unk_803864f4;
  lwz r3, _unk_803864ec;
  addi r5, r4, 2;
  addi r0, r3, 0xbdc;
  stw r5, _unk_803864f4;
  stw r0, _unk_803864ec;
lbl_80125f54:
  addi r3, r1, 8;
  bl __AXGetAuxBInput;
  lwz r0, 8(r1);
  cmpwi r0, 0;
  beq lbl_801262f8;
  lwz r4, _unk_803864f4;
  li r0, 9;
  addi r3, r1, 8;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  lhz r0, _unk_803864e2;
  addi r4, r4, 2;
  stw r4, _unk_803864f4;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  lwz r0, 8(r1);
  addi r4, r4, 2;
  stw r4, _unk_803864f4;
  srwi r0, r0, 0x10;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  lwz r0, 8(r1);
  addi r4, r4, 2;
  stw r4, _unk_803864f4;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  addi r5, r4, 2;
  stw r5, _unk_803864f4;
  bl __AXGetAuxBInputDpl2;
  lwz r0, 8(r1);
  addi r3, r1, 8;
  lwz r4, _unk_803864f4;
  srwi r0, r0, 0x10;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  lwz r0, 8(r1);
  addi r4, r4, 2;
  stw r4, _unk_803864f4;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  addi r5, r4, 2;
  stw r5, _unk_803864f4;
  bl __AXGetAuxBOutput;
  lwz r0, 8(r1);
  addi r3, r1, 8;
  lwz r4, _unk_803864f4;
  srwi r0, r0, 0x10;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  lwz r0, 8(r1);
  addi r4, r4, 2;
  stw r4, _unk_803864f4;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  addi r5, r4, 2;
  stw r5, _unk_803864f4;
  bl __AXGetAuxBOutputDpl2R;
  lwz r0, 8(r1);
  addi r3, r1, 8;
  lwz r4, _unk_803864f4;
  srwi r0, r0, 0x10;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  lwz r0, 8(r1);
  addi r4, r4, 2;
  stw r4, _unk_803864f4;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  addi r5, r4, 2;
  stw r5, _unk_803864f4;
  bl __AXGetAuxBOutputDpl2Ls;
  lwz r0, 8(r1);
  addi r3, r1, 8;
  lwz r4, _unk_803864f4;
  srwi r0, r0, 0x10;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  lwz r0, 8(r1);
  addi r4, r4, 2;
  stw r4, _unk_803864f4;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  addi r5, r4, 2;
  stw r5, _unk_803864f4;
  bl __AXGetAuxBOutputDpl2Rs;
  lwz r0, 8(r1);
  lwz r3, _unk_803864f4;
  srwi r0, r0, 0x10;
  sth r0, 0(r3);
  lwz r3, _unk_803864f4;
  lwz r0, 8(r1);
  addi r3, r3, 2;
  stw r3, _unk_803864f4;
  sth r0, 0(r3);
  lwz r4, _unk_803864f4;
  lwz r3, _unk_803864ec;
  addi r5, r4, 2;
  addi r0, r3, 0xbdc;
  stw r5, _unk_803864f4;
  stw r0, _unk_803864ec;
  b lbl_801262f8;
lbl_801260e8:
  addi r3, r1, 8;
  bl __AXGetAuxAInput;
  lwz r0, 8(r1);
  cmpwi r0, 0;
  beq lbl_80126198;
  lwz r4, _unk_803864f4;
  li r0, 5;
  addi r3, r1, 8;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  lhz r0, _unk_803864e4;
  addi r4, r4, 2;
  stw r4, _unk_803864f4;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  lwz r0, 8(r1);
  addi r4, r4, 2;
  stw r4, _unk_803864f4;
  srwi r0, r0, 0x10;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  lwz r0, 8(r1);
  addi r4, r4, 2;
  stw r4, _unk_803864f4;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  addi r5, r4, 2;
  stw r5, _unk_803864f4;
  bl __AXGetAuxAOutput;
  lwz r0, 8(r1);
  lwz r3, _unk_803864f4;
  srwi r0, r0, 0x10;
  sth r0, 0(r3);
  lwz r3, _unk_803864f4;
  lwz r0, 8(r1);
  addi r3, r3, 2;
  stw r3, _unk_803864f4;
  sth r0, 0(r3);
  lwz r4, _unk_803864f4;
  lwz r3, _unk_803864ec;
  addi r5, r4, 2;
  addi r0, r3, 0x8bb;
  stw r5, _unk_803864f4;
  stw r0, _unk_803864ec;
lbl_80126198:
  addi r3, r1, 8;
  bl __AXGetAuxBInput;
  lwz r0, 8(r1);
  cmpwi r0, 0;
  beq lbl_80126248;
  lwz r4, _unk_803864f4;
  li r0, 6;
  addi r3, r1, 8;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  lhz r0, _unk_803864e2;
  addi r4, r4, 2;
  stw r4, _unk_803864f4;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  lwz r0, 8(r1);
  addi r4, r4, 2;
  stw r4, _unk_803864f4;
  srwi r0, r0, 0x10;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  lwz r0, 8(r1);
  addi r4, r4, 2;
  stw r4, _unk_803864f4;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  addi r5, r4, 2;
  stw r5, _unk_803864f4;
  bl __AXGetAuxBOutput;
  lwz r0, 8(r1);
  lwz r3, _unk_803864f4;
  srwi r0, r0, 0x10;
  sth r0, 0(r3);
  lwz r3, _unk_803864f4;
  lwz r0, 8(r1);
  addi r3, r3, 2;
  stw r3, _unk_803864f4;
  sth r0, 0(r3);
  lwz r4, _unk_803864f4;
  lwz r3, _unk_803864ec;
  addi r5, r4, 2;
  addi r0, r3, 0x8bb;
  stw r5, _unk_803864f4;
  stw r0, _unk_803864ec;
lbl_80126248:
  addi r3, r1, 8;
  bl __AXGetAuxCInput;
  lwz r0, 8(r1);
  cmpwi r0, 0;
  beq lbl_801262f8;
  lwz r4, _unk_803864f4;
  li r0, 7;
  addi r3, r1, 8;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  lhz r0, _unk_803864e0;
  addi r4, r4, 2;
  stw r4, _unk_803864f4;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  lwz r0, 8(r1);
  addi r4, r4, 2;
  stw r4, _unk_803864f4;
  srwi r0, r0, 0x10;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  lwz r0, 8(r1);
  addi r4, r4, 2;
  stw r4, _unk_803864f4;
  sth r0, 0(r4);
  lwz r4, _unk_803864f4;
  addi r5, r4, 2;
  stw r5, _unk_803864f4;
  bl __AXGetAuxCOutput;
  lwz r0, 8(r1);
  lwz r3, _unk_803864f4;
  srwi r0, r0, 0x10;
  sth r0, 0(r3);
  lwz r3, _unk_803864f4;
  lwz r0, 8(r1);
  addi r3, r3, 2;
  stw r3, _unk_803864f4;
  sth r0, 0(r3);
  lwz r4, _unk_803864f4;
  lwz r3, _unk_803864ec;
  addi r5, r4, 2;
  addi r0, r3, 0x8bb;
  stw r5, _unk_803864f4;
  stw r0, _unk_803864ec;
lbl_801262f8:
  lwz r0, _unk_803864e8;
  cmpwi r0, 0;
  beq lbl_8012637c;
  lwz r5, _unk_803864f4;
  li r6, 0xa;
  lis r3, 1;
  lis r4, 0x8028; // TODO 0x802817d0 __AXCompressorTable
  sth r6, 0(r5);
  addi r4, r4, -6048;
  addi r3, r3, -32768;
  lwz r5, _unk_803864f4;
  srwi r0, r4, 0x10;
  addi r5, r5, 2;
  stw r5, _unk_803864f4;
  sth r3, 0(r5);
  lwz r3, _unk_803864f4;
  addi r3, r3, 2;
  stw r3, _unk_803864f4;
  sth r6, 0(r3);
  lwz r3, _unk_803864f4;
  addi r3, r3, 2;
  stw r3, _unk_803864f4;
  sth r0, 0(r3);
  lwz r3, _unk_803864f4;
  addi r3, r3, 2;
  stw r3, _unk_803864f4;
  sth r4, 0(r3);
  lwz r4, _unk_803864f4;
  lwz r3, _unk_803864ec;
  addi r5, r4, 2;
  addi r0, r3, 0x73a;
  stw r5, _unk_803864f4;
  stw r0, _unk_803864ec;
lbl_8012637c:
  lwz r3, _unk_803864f4;
  li r0, 0xd;
  sth r0, 0(r3);
  lwz r3, _unk_803864f4;
  addi r3, r3, 2;
  stw r3, _unk_803864f4;
  lwz r0, 0(r30);
  srwi r0, r0, 0x10;
  sth r0, 0(r3);
  lwz r3, _unk_803864f4;
  addi r3, r3, 2;
  stw r3, _unk_803864f4;
  lwz r0, 0(r30);
  sth r0, 0(r3);
  lwz r3, _unk_803864f4;
  addi r3, r3, 2;
  stw r3, _unk_803864f4;
  lwz r0, 4(r30);
  srwi r0, r0, 0x10;
  sth r0, 0(r3);
  lwz r3, _unk_803864f4;
  addi r3, r3, 2;
  stw r3, _unk_803864f4;
  lwz r0, 4(r30);
  sth r0, 0(r3);
  lwz r3, _unk_803864f4;
  addi r3, r3, 2;
  stw r3, _unk_803864f4;
  lwz r0, 8(r30);
  srwi r0, r0, 0x10;
  sth r0, 0(r3);
  lwz r3, _unk_803864f4;
  addi r3, r3, 2;
  stw r3, _unk_803864f4;
  lwz r0, 8(r30);
  sth r0, 0(r3);
  lwz r3, _unk_803864f4;
  addi r3, r3, 2;
  stw r3, _unk_803864f4;
  lwz r0, 0xc(r30);
  srwi r0, r0, 0x10;
  sth r0, 0(r3);
  lwz r3, _unk_803864f4;
  addi r3, r3, 2;
  stw r3, _unk_803864f4;
  lwz r0, 0xc(r30);
  sth r0, 0(r3);
  lwz r4, _unk_803864f4;
  lwz r3, _unk_803864ec;
  lwz r0, _unk_803864f0;
  addi r4, r4, 2;
  addi r3, r3, 0x199;
  stw r4, _unk_803864f4;
  cmplwi r0, 2;
  stw r3, _unk_803864ec;
  bne lbl_801264dc;
  li r0, 0xc;
  srwi r3, r28, 0x10;
  sth r0, 0(r4);
  srwi r0, r29, 0x10;
  lwz r5, _unk_803864f4;
  lhz r4, _unk_803864e6;
  addi r5, r5, 2;
  stw r5, _unk_803864f4;
  sth r4, 0(r5);
  lwz r4, _unk_803864f4;
  addi r4, r4, 2;
  stw r4, _unk_803864f4;
  sth r3, 0(r4);
  lwz r3, _unk_803864f4;
  addi r3, r3, 2;
  stw r3, _unk_803864f4;
  sth r28, 0(r3);
  lwz r3, _unk_803864f4;
  addi r3, r3, 2;
  stw r3, _unk_803864f4;
  sth r0, 0(r3);
  lwz r3, _unk_803864f4;
  addi r3, r3, 2;
  stw r3, _unk_803864f4;
  sth r29, 0(r3);
  lwz r4, _unk_803864f4;
  lwz r3, _unk_803864ec;
  addi r5, r4, 2;
  addi r0, r3, 0x4ab;
  stw r5, _unk_803864f4;
  stw r0, _unk_803864ec;
  b lbl_80126558;
lbl_801264dc:
  li r0, 0xb;
  srwi r3, r28, 0x10;
  sth r0, 0(r4);
  srwi r0, r29, 0x10;
  lwz r5, _unk_803864f4;
  lhz r4, _unk_803864e6;
  addi r5, r5, 2;
  stw r5, _unk_803864f4;
  sth r4, 0(r5);
  lwz r4, _unk_803864f4;
  addi r4, r4, 2;
  stw r4, _unk_803864f4;
  sth r3, 0(r4);
  lwz r3, _unk_803864f4;
  addi r3, r3, 2;
  stw r3, _unk_803864f4;
  sth r28, 0(r3);
  lwz r3, _unk_803864f4;
  addi r3, r3, 2;
  stw r3, _unk_803864f4;
  sth r0, 0(r3);
  lwz r3, _unk_803864f4;
  addi r3, r3, 2;
  stw r3, _unk_803864f4;
  sth r29, 0(r3);
  lwz r4, _unk_803864f4;
  lwz r3, _unk_803864ec;
  addi r5, r4, 2;
  addi r0, r3, 0x494;
  stw r5, _unk_803864f4;
  stw r0, _unk_803864ec;
lbl_80126558:
  li r0, 0xe;
  mr r3, r31;
  sth r0, 0(r5);
  li r4, 0x80;
  lwz r5, _unk_803864f4;
  lwz r6, _unk_803864ec;
  addi r5, r5, 2;
  addi r0, r6, 0x1e;
  stw r5, _unk_803864f4;
  stw r0, _unk_803864ec;
  bl DCFlushRange;
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

// Symbol: __AXClInit
// PAL: 0x801265a4..0x801265e0
MARK_BINARY_BLOB(__AXClInit, 0x801265a4, 0x801265e0);
asm UNKNOWN_FUNCTION(__AXClInit) {
  // clang-format off
  nofralloc;
  lis r4, _unk_802f7340@ha;
  lis r3, 1;
  addi r0, r3, -32768;
  li r5, 0;
  la r4, _unk_802f7340@l(r4);
  li r3, 1;
  stw r5, _unk_803864f0;
  stw r5, _unk_803864f8;
  stw r4, _unk_803864f4;
  stw r3, _unk_803864e8;
  sth r0, _unk_803864e6;
  sth r0, _unk_803864e4;
  sth r0, _unk_803864e2;
  sth r0, _unk_803864e0;
  blr;
  // clang-format on
}

// Symbol: AXSetMode
// PAL: 0x801265e0..0x801265e8
MARK_BINARY_BLOB(AXSetMode, 0x801265e0, 0x801265e8);
asm UNKNOWN_FUNCTION(AXSetMode) {
  // clang-format off
  nofralloc;
  stw r3, _unk_803864f0;
  blr;
  // clang-format on
}

// Symbol: AXGetMode
// PAL: 0x801265e8..0x801265f0
MARK_BINARY_BLOB(AXGetMode, 0x801265e8, 0x801265f0);
asm UNKNOWN_FUNCTION(AXGetMode) {
  // clang-format off
  nofralloc;
  lwz r3, _unk_803864f0;
  blr;
  // clang-format on
}

// Symbol: AXGetAuxAReturnVolume
// PAL: 0x801265f0..0x801265f8
MARK_BINARY_BLOB(AXGetAuxAReturnVolume, 0x801265f0, 0x801265f8);
asm UNKNOWN_FUNCTION(AXGetAuxAReturnVolume) {
  // clang-format off
  nofralloc;
  lhz r3, _unk_803864e4;
  blr;
  // clang-format on
}

// Symbol: AXGetAuxBReturnVolume
// PAL: 0x801265f8..0x80126600
MARK_BINARY_BLOB(AXGetAuxBReturnVolume, 0x801265f8, 0x80126600);
asm UNKNOWN_FUNCTION(AXGetAuxBReturnVolume) {
  // clang-format off
  nofralloc;
  lhz r3, _unk_803864e2;
  blr;
  // clang-format on
}

// Symbol: AXGetAuxCReturnVolume
// PAL: 0x80126600..0x80126608
MARK_BINARY_BLOB(AXGetAuxCReturnVolume, 0x80126600, 0x80126608);
asm UNKNOWN_FUNCTION(AXGetAuxCReturnVolume) {
  // clang-format off
  nofralloc;
  lhz r3, _unk_803864e0;
  blr;
  // clang-format on
}

// Symbol: AXSetMasterVolume
// PAL: 0x80126608..0x80126620
MARK_BINARY_BLOB(AXSetMasterVolume, 0x80126608, 0x80126620);
asm UNKNOWN_FUNCTION(AXSetMasterVolume) {
  // clang-format off
  nofralloc;
  cmplwi r3, 0x8000;
  ble lbl_80126618;
  lis r3, 1;
  addi r3, r3, -32768;
lbl_80126618:
  sth r3, _unk_803864e6;
  blr;
  // clang-format on
}

// Symbol: AXSetAuxAReturnVolume
// PAL: 0x80126620..0x80126628
MARK_BINARY_BLOB(AXSetAuxAReturnVolume, 0x80126620, 0x80126628);
asm UNKNOWN_FUNCTION(AXSetAuxAReturnVolume) {
  // clang-format off
  nofralloc;
  sth r3, _unk_803864e4;
  blr;
  // clang-format on
}

// Symbol: AXSetAuxBReturnVolume
// PAL: 0x80126628..0x80126630
MARK_BINARY_BLOB(AXSetAuxBReturnVolume, 0x80126628, 0x80126630);
asm UNKNOWN_FUNCTION(AXSetAuxBReturnVolume) {
  // clang-format off
  nofralloc;
  sth r3, _unk_803864e2;
  blr;
  // clang-format on
}

// Symbol: AXSetAuxCReturnVolume
// PAL: 0x80126630..0x80126638
MARK_BINARY_BLOB(AXSetAuxCReturnVolume, 0x80126630, 0x80126638);
asm UNKNOWN_FUNCTION(AXSetAuxCReturnVolume) {
  // clang-format off
  nofralloc;
  sth r3, _unk_803864e0;
  blr;
  // clang-format on
}
