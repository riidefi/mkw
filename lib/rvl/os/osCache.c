#include "osCache.h"

#include <rvl/base/ppcArch.h>
#include <rvl/db/db.h>

#include "osContext.h"
#include "osError.h"
#include "osInterrupt.h"

#ifdef __CWCC__

// Symbol: DCEnable
asm void DCEnable(void) {
  nofralloc;
  sync;
  mfspr r3, 0x3f0;
  ori r3, r3, 0x4000;
  mtspr 0x3f0, r3;
  blr;
}

// Symbol: DCInvalidateRange
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
asm void ICFlashInvalidate(void) {
  nofralloc;
  mfspr r3, 0x3f0;
  ori r3, r3, 0x800;
  mtspr 0x3f0, r3;
  blr;
}

// Symbol: ICEnable
asm void ICEnable(void) {
  nofralloc;
  isync;
  mfspr r3, 0x3f0;
  ori r3, r3, 0x8000;
  mtspr 0x3f0, r3;
  blr;
}

// Symbol: __LCEnable
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
void LCEnable(void) {
  int interrupts = OSDisableInterrupts();
  __LCEnable();
  OSRestoreInterrupts(interrupts);
}

// Symbol: LCDisable
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
asm u32 LCQueueLength(void) {
  nofralloc;
  mfspr r4, 0x398;
  rlwinm r3, r4, 8, 0x1c, 0x1f;
  blr;
}

// Symbol: LCQueueWait
asm void LCQueueWait(register u32 size) {
  nofralloc;
_again:
  mfspr r4, 0x398;
  rlwinm r4, r4, 8, 0x1c, 0x1f;
  cmpw r4, size;
  bgt _again;
  blr;
}

#endif
