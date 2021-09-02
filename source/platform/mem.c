#include <string.h>

#include <decomp.h>
#include <rk_types.h>

#include "mem_cpy.h"

// Symbol: memmove
// PAL: 0x8000f1f0..0x8000f2bc
MARK_BINARY_BLOB(memmove, 0x8000f1f0, 0x8000f2bc);
asm void* memmove(void*, const void*, size_t) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  xor r6, r3, r4;
  cmplwi r5, 0x20;
  stw r0, 0x14(r1);
  cntlzw r0, r6;
  slw r0, r3, r0;
  stw r31, 0xc(r1);
  mr r31, r3;
  srwi r7, r0, 0x1f;
  blt lbl_8000f258;
  clrlwi. r0, r6, 0x1e;
  beq lbl_8000f23c;
  cmpwi r7, 0;
  bne lbl_8000f234;
  bl __copy_longs_unaligned;
  b lbl_8000f250;
lbl_8000f234:
  bl __copy_longs_rev_unaligned;
  b lbl_8000f250;
lbl_8000f23c:
  cmpwi r7, 0;
  bne lbl_8000f24c;
  bl __copy_longs_aligned;
  b lbl_8000f250;
lbl_8000f24c:
  bl __copy_longs_rev_aligned;
lbl_8000f250:
  mr r3, r31;
  b lbl_8000f2a8;
lbl_8000f258:
  cmpwi r7, 0;
  bne lbl_8000f284;
  addi r4, r4, -1;
  addi r3, r3, -1;
  addi r5, r5, 1;
  b lbl_8000f278;
lbl_8000f270:
  lbzu r0, 1(r4);
  stbu r0, 1(r3);
lbl_8000f278:
  addic. r5, r5, -1;
  bne lbl_8000f270;
  b lbl_8000f2a4;
lbl_8000f284:
  add r4, r4, r5;
  add r3, r3, r5;
  addi r5, r5, 1;
  b lbl_8000f29c;
lbl_8000f294:
  lbzu r0, -1(r4);
  stbu r0, -1(r3);
lbl_8000f29c:
  addic. r5, r5, -1;
  bne lbl_8000f294;
lbl_8000f2a4:
  mr r3, r31;
lbl_8000f2a8:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: memchr
// PAL: 0x8000f2bc..0x8000f2e8
void* memchr(const void* ptr, int value, size_t num) {
  const u8* str;
  u32 v = value & 0xff;
  for (str = (u8*)ptr - 1, num++; --num;)
    if ((*++str & 0xff) == v)
      return (void*)str;
  return NULL;
}

// Symbol: __memrchr
// PAL: 0x8000f2e8..0x8000f314
void* __memrchr(const void* ptr, int value, size_t num) {
  const u8* str;
  u32 v = value & 0xff;
  for (str = (u8*)(ptr) + num, num++; --num;)
    if (*--str == v)
      return (void*)str;
  return NULL;
}

// Symbol: memcmp
// PAL: 0x8000f314..0x8000f360
int memcmp(const void* s1, const void* s2, size_t n) {
  const u8* p1;
  const u8* p2;
  for (p1 = (const u8*)(s1)-1, p2 = (const u8*)(s2)-1, n++; --n;)
    if (*++p1 != *++p2)
      return *p1 < *p2 ? -1 : 1;
  return 0;
}
