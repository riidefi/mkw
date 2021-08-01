#include <string.h>

#include <decomp.h>

// Extern function references.
// PAL: 0x8000f360
extern UNKNOWN_FUNCTION(unk_8000f360);
// PAL: 0x8000f41c
extern UNKNOWN_FUNCTION(unk_8000f41c);
// PAL: 0x8000f4c4
extern UNKNOWN_FUNCTION(unk_8000f4c4);
// PAL: 0x8000f584
extern UNKNOWN_FUNCTION(unk_8000f584);

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
  bl unk_8000f4c4;
  b lbl_8000f250;
lbl_8000f234:
  bl unk_8000f584;
  b lbl_8000f250;
lbl_8000f23c:
  cmpwi r7, 0;
  bne lbl_8000f24c;
  bl unk_8000f360;
  b lbl_8000f250;
lbl_8000f24c:
  bl unk_8000f41c;
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
MARK_BINARY_BLOB(memchr, 0x8000f2bc, 0x8000f2e8);
asm void* memchr(void* ptr, int value, size_t num) {
  // clang-format off
  nofralloc;
  clrlwi r4, r4, 0x18;
  addi r3, r3, -1;
  addi r5, r5, 1;
  b lbl_8000f2d8;
lbl_8000f2cc:
  lbzu r0, 1(r3);
  cmplw r0, r4;
  beqlr;
lbl_8000f2d8:
  addic. r5, r5, -1;
  bne lbl_8000f2cc;
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: __memrchr
// PAL: 0x8000f2e8..0x8000f314
MARK_BINARY_BLOB(__memrchr, 0x8000f2e8, 0x8000f314);
asm void * __memrchr(const void *ptr, int value, size_t num) {
  // clang-format off
  nofralloc;
  add r3, r3, r5;
  clrlwi r4, r4, 0x18;
  addi r5, r5, 1;
  b lbl_8000f304;
lbl_8000f2f8:
  lbzu r0, -1(r3);
  cmplw r0, r4;
  beqlr;
lbl_8000f304:
  addic. r5, r5, -1;
  bne lbl_8000f2f8;
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: memcmp
// PAL: 0x8000f314..0x8000f360
MARK_BINARY_BLOB(memcmp, 0x8000f314, 0x8000f360);
asm int memcmp(const void* s1, const void* s2, size_t n) {
  // clang-format off
  nofralloc;
  addi r7, r4, -1;
  addi r6, r3, -1;
  addi r4, r5, 1;
  b lbl_8000f350;
lbl_8000f324:
  lbzu r3, 1(r6);
  lbzu r0, 1(r7);
  cmplw r3, r0;
  beq lbl_8000f350;
  lbz r4, 0(r6);
  li r3, 1;
  lbz r0, 0(r7);
  cmplw r4, r0;
  bgelr;
  li r3, -1;
  blr;
lbl_8000f350:
  addic. r4, r4, -1;
  bne lbl_8000f324;
  li r3, 0;
  blr;
  // clang-format on
}
