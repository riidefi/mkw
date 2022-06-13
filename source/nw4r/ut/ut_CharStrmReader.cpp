#include "ut_CharStrmReader.hpp"

#include <decomp.h>

namespace nw4r {
namespace ut {

// Symbol: ReadNextCharUTF8__Q34nw4r2ut14CharStrmReaderFv
// PAL: 0x800af420..0x800af4a0
MARK_BINARY_BLOB(ReadNextCharUTF8__Q34nw4r2ut14CharStrmReaderFv, 0x800af420,
                 0x800af4a0);
asm u16 CharStrmReader::ReadNextCharUTF8() {
  // clang-format off
  nofralloc;
  lwz r7, 0(r3);
  lbz r6, 0(r7);
  rlwinm. r0, r6, 0, 0x18, 0x18;
  bne lbl_800af440;
  lwz r4, 0(r3);
  addi r0, r4, 1;
  stw r0, 0(r3);
  b lbl_800af490;
lbl_800af440:
  rlwinm r0, r6, 0, 0x18, 0x1a;
  cmpwi r0, 0xc0;
  bne lbl_800af46c;
  lbz r0, 1(r7);
  lwz r4, 0(r3);
  clrlwi r5, r0, 0x1a;
  rlwimi r5, r6, 6, 0x15, 0x19;
  addi r0, r4, 2;
  stw r0, 0(r3);
  mr r6, r5;
  b lbl_800af490;
lbl_800af46c:
  lwz r4, 0(r3);
  rlwinm r5, r6, 0xc, 0xf, 0x13;
  lbz r6, 1(r7);
  lbz r7, 2(r7);
  addi r0, r4, 3;
  rlwimi r5, r6, 6, 0x14, 0x19;
  rlwimi r5, r7, 0, 0x1a, 0x1f;
  stw r0, 0(r3);
  clrlwi r6, r5, 0x10;
lbl_800af490:
  mr r3, r6;
  blr;
  // clang-format on
}

// Symbol: ReadNextCharUTF16__Q34nw4r2ut14CharStrmReaderFv
// PAL: 0x800af4a0..0x800af4c0
MARK_BINARY_BLOB(ReadNextCharUTF16__Q34nw4r2ut14CharStrmReaderFv, 0x800af4a0,
                 0x800af4c0);
asm u16 CharStrmReader::ReadNextCharUTF16() {
  // clang-format off
  nofralloc;
  lwz r5, 0(r3);
  mr r6, r3;
  lwz r4, 0(r3);
  lhz r3, 0(r5);
  addi r0, r4, 2;
  stw r0, 0(r6);
  blr;
  // clang-format on
}

// Symbol: ReadNextCharCP1252__Q34nw4r2ut14CharStrmReaderFv
// PAL: 0x800af4c0..0x800af4e0
MARK_BINARY_BLOB(ReadNextCharCP1252__Q34nw4r2ut14CharStrmReaderFv, 0x800af4c0,
                 0x800af4e0);
asm u16 CharStrmReader::ReadNextCharCP1252() {
  // clang-format off
  nofralloc;
  lwz r5, 0(r3);
  mr r6, r3;
  lwz r4, 0(r3);
  lbz r3, 0(r5);
  addi r0, r4, 1;
  stw r0, 0(r6);
  blr;
  // clang-format on
}

// Symbol: ReadNextCharSJIS__Q34nw4r2ut14CharStrmReaderFv
// PAL: 0x800af4e0..0x800af540
MARK_BINARY_BLOB(ReadNextCharSJIS__Q34nw4r2ut14CharStrmReaderFv, 0x800af4e0,
                 0x800af540);
asm u16 CharStrmReader::ReadNextCharSJIS() {
  // clang-format off
  nofralloc;
  lwz r4, 0(r3);
  li r0, 0;
  lbz r5, 0(r4);
  cmplwi r5, 0x81;
  blt lbl_800af4fc;
  cmplwi r5, 0xa0;
  blt lbl_800af504;
lbl_800af4fc:
  cmplwi r5, 0xe0;
  blt lbl_800af508;
lbl_800af504:
  li r0, 1;
lbl_800af508:
  cmpwi r0, 0;
  beq lbl_800af528;
  lbz r6, 1(r4);
  rlwimi r6, r5, 8, 0x10, 0x17;
  lwz r4, 0(r3);
  addi r0, r4, 2;
  stw r0, 0(r3);
  b lbl_800af538;
lbl_800af528:
  lwz r4, 0(r3);
  mr r6, r5;
  addi r0, r4, 1;
  stw r0, 0(r3);
lbl_800af538:
  mr r3, r6;
  blr;
  // clang-format on
}

} // namespace ut
} // namespace nw4r
