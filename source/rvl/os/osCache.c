#include "osCache.h"

#include "osContext.h"
#include "osError.h"
#include "osInterrupt.h"

// Extern function references.
// PAL: 0x8012e564
extern UNKNOWN_FUNCTION(unk_8012e564);
// PAL: 0x8012e56c
extern UNKNOWN_FUNCTION(unk_8012e56c);
// PAL: 0x8012e574
extern UNKNOWN_FUNCTION(unk_8012e574);
// PAL: 0x8012e584
extern UNKNOWN_FUNCTION(unk_8012e584);
// PAL: 0x8012e58c
extern UNKNOWN_FUNCTION(unk_8012e58c);
// PAL: 0x8012e5a4
extern UNKNOWN_FUNCTION(unk_8012e5a4);
// PAL: 0x8012e630
extern UNKNOWN_FUNCTION(unk_8012e630);
// PAL: 0x8012e638
extern UNKNOWN_FUNCTION(unk_8012e638);
// PAL: 0x8015d3ac
extern UNKNOWN_FUNCTION(DBPrintf);

// Symbol: DCEnable
// PAL: 0x801a15ec..0x801a1600
asm void DCEnable(void) {
  nofralloc;
  sync;
  mfspr r3, 0x3f0;
  ori r3, r3, 0x4000;
  mtspr 0x3f0, r3;
  blr;
}

// Symbol: DCInvalidateRange
// PAL: 0x801a1600..0x801a162c
asm void DCInvalidateRange(register void* addr, register u32 size) {
  nofralloc;
  cmplwi size, 0;
  blelr;
  clrlwi r5, addr, 0x1b;
  add size, size, r5;
  addi size, size, 0x1f;
  srwi size, size, 5;
  mtctr size;
_again:
  dcbi 0, addr;
  addi addr, addr, 0x20;
  bdnz _again;
  blr;
}

// Symbol: DCFlushRange
// PAL: 0x801a162c..0x801a165c
asm void DCFlushRange(register void* addr, register u32 size) {
  nofralloc;
  cmplwi size, 0;
  blelr;
  clrlwi r5, addr, 0x1b;
  add size, size, r5;
  addi size, size, 0x1f;
  srwi size, size, 5;
  mtctr size;
_again:
  dcbf 0, addr;
  addi addr, addr, 0x20;
  bdnz _again;
  sc;
  blr;
}

// Symbol: DCStoreRange
// PAL: 0x801a165c..0x801a168c
asm void DCStoreRange(register void* addr, register u32 size) {
  nofralloc;
  cmplwi size, 0;
  blelr;
  clrlwi r5, addr, 0x1b;
  add size, size, r5;
  addi size, size, 0x1f;
  srwi size, size, 5;
  mtctr size;
_again:
  dcbst 0, addr;
  addi addr, addr, 0x20;
  bdnz _again;
  sc;
  blr;
}

// Symbol: DCFlushRangeNoSync
// PAL: 0x801a168c..0x801a16b8
asm void DCFlushRangeNoSync(register void* addr, register u32 size) {
  nofralloc;
  cmplwi size, 0;
  blelr;
  clrlwi r5, addr, 0x1b;
  add size, size, r5;
  addi size, size, 0x1f;
  srwi size, size, 5;
  mtctr size;
_again:
  dcbf 0, addr;
  addi addr, addr, 0x20;
  bdnz _again;
  blr;
}

// Symbol: DCStoreRangeNoSync
// PAL: 0x801a16b8..0x801a16e4
asm void DCStoreRangeNoSync(register void* addr, register u32 size) {
  nofralloc;
  cmplwi size, 0;
  blelr;
  clrlwi r5, addr, 0x1b;
  add size, size, r5;
  addi size, size, 0x1f;
  srwi size, size, 5;
  mtctr size;
_again:
  dcbst 0, addr;
  addi addr, addr, 0x20;
  bdnz _again;
  blr;
}

// Symbol: DCZeroRange
// PAL: 0x801a16e4..0x801a1710
asm void DCZeroRange(register void* addr, register u32 size) {
  nofralloc;
  cmplwi size, 0;
  blelr;
  clrlwi r5, addr, 0x1b;
  add size, size, r5;
  addi size, size, 0x1f;
  srwi size, size, 5;
  mtctr size;
_again:
  dcbz 0, addr;
  addi addr, addr, 0x20;
  bdnz _again;
  blr;
}

// Symbol: ICInvalidateRange
// PAL: 0x801a1710..0x801a1744
asm void ICInvalidateRange(register void* addr, register u32 size) {
  nofralloc;
  cmplwi size, 0;
  blelr;
  clrlwi r5, addr, 0x1b;
  add size, size, r5;
  addi size, size, 0x1f;
  srwi size, size, 5;
  mtctr size;
_again:
  icbi 0, addr;
  addi addr, addr, 0x20;
  bdnz _again;
  sync;
  isync;
  blr;
}

// Symbol: ICFlashInvalidate
// PAL: 0x801a1744..0x801a1754
asm void ICFlashInvalidate(void) {
  nofralloc;
  mfspr r3, 0x3f0;
  ori r3, r3, 0x800;
  mtspr 0x3f0, r3;
  blr;
}

// Symbol: ICEnable
// PAL: 0x801a1754..0x801a1768
asm void ICEnable(void) {
  nofralloc;
  isync;
  mfspr r3, 0x3f0;
  ori r3, r3, 0x8000;
  mtspr 0x3f0, r3;
  blr;
}

// Symbol: __LCEnable
// PAL: 0x801a1768..0x801a1834
asm void __LCEnable(void) {
  nofralloc;
  mfmsr r5;
  ori r5, r5, 0x1000;
  mtmsr r5;
  lis r3, 0x8000;
  li r4, 0x400;
  mtctr r4;
lbl_801a1780:
  dcbt 0, r3;
  dcbst 0, r3;
  addi r3, r3, 0x20;
  bdnz lbl_801a1780;
  mfspr r4, 0x398;
  oris r4, r4, 0x100f;
  mtspr 0x398, r4;
  nop;
  nop;
  nop;
  nop;
  nop;
  nop;
  nop;
  nop;
  nop;
  nop;
  nop;
  nop;
  lis r3, 0xe000;
  ori r3, r3, 2;
  mtdbatl 3, r3;
  ori r3, r3, 0x1fe;
  mtdbatu 3, r3;
  isync;
  lis r3, 0xe000;
  li r6, 0x200;
  mtctr r6;
  li r6, 0;
lbl_801a17f4:
  dcbz_l r6, r3;
  addi r3, r3, 0x20;
  bdnz lbl_801a17f4;
  nop;
  nop;
  nop;
  nop;
  nop;
  nop;
  nop;
  nop;
  nop;
  nop;
  nop;
  nop;
  blr;
}

// Symbol: LCEnable
// PAL: 0x801a1834..0x801a186c
void LCEnable(void) {
  int interrupts = OSDisableInterrupts();
  __LCEnable();
  OSRestoreInterrupts(interrupts);
}

// Symbol: LCDisable
// PAL: 0x801a186c..0x801a1894
asm void LCDisable(void) {
  nofralloc;
  lis r3, 0xe000;
  li r4, 0x200;
  mtctr r4;
_again:
  dcbi 0, r3;
  addi r3, r3, 0x20;
  bdnz _again;
  mfspr r4, 0x398;
  rlwinm r4, r4, 0, 4, 2;
  mtspr 0x398, r4;
  blr;
}

// Symbol: LCLoadBlocks
// PAL: 0x801a1894..0x801a18b8
asm void LCLoadBlocks(register void* dst, register void* src,
                      register u32 num) {
  nofralloc;
  rlwinm r6, num, 0x1e, 0x1b, 0x1f;
  clrlwi src, src, 3;
  or r6, r6, src;
  mtspr 0x39a, r6;
  rlwinm r6, num, 2, 0x1c, 0x1d;
  or r6, r6, dst;
  ori r6, r6, 0x12;
  mtspr 0x39b, r6;
  blr;
}

// Symbol: LCStoreBlocks
// PAL: 0x801a18b8..0x801a18dc
asm void LCStoreBlocks(register void* dst, register void* src,
                       register u32 num) {
  nofralloc;
  rlwinm r6, num, 0x1e, 0x1b, 0x1f;
  clrlwi dst, dst, 3;
  or r6, r6, dst;
  mtspr 0x39a, r6;
  rlwinm r6, num, 2, 0x1c, 0x1d;
  or r6, r6, src;
  ori r6, r6, 2;
  mtspr 0x39b, r6;
  blr;
}

// Symbol: LCStoreData
// PAL: 0x801a18dc..0x801a197c
u32 LCStoreData(void* dst, void* src, u32 size) {
  u32 blocks = (size + 31) / 32;
  u32 txs = (blocks + 0x7f) >> 7;
  while (blocks > 0) {
    if (blocks < 0x80) {
      LCStoreBlocks(dst, src, blocks);
      blocks = 0;
    } else {
      LCStoreBlocks(dst, src, 0);
      blocks -= 0x80;
      dst = (void*)((u32)dst + 0x1000);
      src = (void*)((u32)src + 0x1000);
    }
  }
  return txs;
}

// Symbol: LCQueueLength
// PAL: 0x801a197c..0x801a1988
asm u32 LCQueueLength(void) {
  nofralloc;
  mfspr r4, 0x398;
  rlwinm r3, r4, 8, 0x1c, 0x1f;
  blr;
}

// Symbol: LCQueueWait
// PAL: 0x801a1988..0x801a199c
asm void LCQueueWait(register u32 size) {
  nofralloc;
_again:
  mfspr r4, 0x398;
  rlwinm r4, r4, 8, 0x1c, 0x1f;
  cmpw r4, size;
  bgt _again;
  blr;
}

// Symbol: DMAErrorHandler
// Function signature is unknown.
// PAL: 0x801a199c..0x801a1ae4
MARK_BINARY_BLOB(DMAErrorHandler, 0x801a199c, 0x801a1ae4);
asm UNKNOWN_FUNCTION(DMAErrorHandler) {
  // clang-format off
  nofralloc;
  stwu r1, -0x80(r1);
  mflr r0;
  stw r0, 0x84(r1);
  stw r31, 0x7c(r1);
  stw r30, 0x78(r1);
  stw r29, 0x74(r1);
  mr r29, r4;
  bne cr1, lbl_801a19dc;
  stfd f1, 0x28(r1);
  stfd f2, 0x30(r1);
  stfd f3, 0x38(r1);
  stfd f4, 0x40(r1);
  stfd f5, 0x48(r1);
  stfd f6, 0x50(r1);
  stfd f7, 0x58(r1);
  stfd f8, 0x60(r1);
lbl_801a19dc:
  lis r31, 0x8029;
  stw r3, 8(r1);
  addi r31, r31, -3864;
  stw r4, 0xc(r1);
  stw r5, 0x10(r1);
  stw r6, 0x14(r1);
  stw r7, 0x18(r1);
  stw r8, 0x1c(r1);
  stw r9, 0x20(r1);
  stw r10, 0x24(r1);
  bl unk_8012e630;
  mr r30, r3;
  addi r3, r31, 0x30;
  crclr 6;
  bl OSReport;
  lwz r5, 0x19c(r29);
  mr r4, r30;
  addi r3, r31, 0x48;
  crclr 6;
  bl OSReport;
  rlwinm. r0, r30, 0, 8, 0xb;
  beq lbl_801a1a40;
  lwz r0, 0x19c(r29);
  rlwinm. r0, r0, 0, 0xa, 0xa;
  bne lbl_801a1a58;
lbl_801a1a40:
  addi r3, r31, 0x68;
  crclr 6;
  bl OSReport;
  mr r3, r29;
  bl OSDumpContext;
  bl unk_8012e5a4;
lbl_801a1a58:
  addi r3, r31, 0x98;
  crclr 6;
  bl OSReport;
  addi r3, r31, 0xd4;
  crclr 6;
  bl OSReport;
  rlwinm. r0, r30, 0, 8, 8;
  beq lbl_801a1a84;
  addi r3, r31, 0x10c;
  crclr 6;
  bl OSReport;
lbl_801a1a84:
  rlwinm. r0, r30, 0, 9, 9;
  beq lbl_801a1a98;
  addi r3, r31, 0x14c;
  crclr 6;
  bl OSReport;
lbl_801a1a98:
  rlwinm. r0, r30, 0, 0xa, 0xa;
  beq lbl_801a1aac;
  addi r3, r31, 0x178;
  crclr 6;
  bl OSReport;
lbl_801a1aac:
  rlwinm. r0, r30, 0, 0xb, 0xb;
  beq lbl_801a1ac0;
  addi r3, r31, 0x198;
  crclr 6;
  bl OSReport;
lbl_801a1ac0:
  mr r3, r30;
  bl unk_8012e638;
  lwz r0, 0x84(r1);
  lwz r31, 0x7c(r1);
  lwz r30, 0x78(r1);
  lwz r29, 0x74(r1);
  mtlr r0;
  addi r1, r1, 0x80;
  blr;
  // clang-format on
}

// Symbol: __OSCacheInit
// Function signature is unknown.
// PAL: 0x801a1ae4..0x801a1c1c
MARK_BINARY_BLOB(__OSCacheInit, 0x801a1ae4, 0x801a1c1c);
asm UNKNOWN_FUNCTION(__OSCacheInit) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8029;
  addi r31, r31, -3864;
  stw r30, 8(r1);
  bl unk_8012e574;
  rlwinm. r0, r3, 0, 0x10, 0x10;
  bne lbl_801a1b1c;
  bl ICEnable;
  addi r3, r31, 0x1b4;
  crclr 6;
  bl DBPrintf;
lbl_801a1b1c:
  bl unk_8012e574;
  rlwinm. r0, r3, 0, 0x11, 0x11;
  bne lbl_801a1b38;
  bl DCEnable;
  addi r3, r31, 0x1d0;
  crclr 6;
  bl DBPrintf;
lbl_801a1b38:
  bl unk_8012e584;
  rlwinm. r0, r3, 0, 0, 0;
  bne lbl_801a1be8;
  bl unk_8012e564;
  mr r30, r3;
  sync;
  li r3, 0x30;
  bl unk_8012e56c;
  sync;
  sync;
  bl unk_8012e584;
  clrlwi r3, r3, 1;
  bl unk_8012e58c;
  sync;
  sync;
  bl unk_8012e584;
  clrlwi r3, r3, 1;
  bl unk_8012e58c;
  sync;
  bl unk_8012e584;
  oris r3, r3, 0x20;
  bl unk_8012e58c;
lbl_801a1b90:
  bl unk_8012e584;
  clrlwi. r0, r3, 0x1f;
  bne lbl_801a1b90;
  bl unk_8012e584;
  rlwinm r3, r3, 0, 0xb, 9;
  bl unk_8012e58c;
  b lbl_801a1bb8;
lbl_801a1bac:
  addi r3, r31, 0;
  crclr 6;
  bl DBPrintf;
lbl_801a1bb8:
  bl unk_8012e584;
  clrlwi. r0, r3, 0x1f;
  bne lbl_801a1bac;
  mr r3, r30;
  bl unk_8012e56c;
  bl unk_8012e584;
  oris r0, r3, 0x8000;
  rlwinm r3, r0, 0, 0xb, 9;
  bl unk_8012e58c;
  addi r3, r31, 0x1ec;
  crclr 6;
  bl DBPrintf;
lbl_801a1be8:
  lis r4, 0x801a;
  li r3, 1;
  addi r4, r4, 0x199c;
  bl OSSetErrorHandler;
  addi r3, r31, 0x204;
  crclr 6;
  bl DBPrintf;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}
