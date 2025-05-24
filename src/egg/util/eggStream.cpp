#include <egg/util/eggStream.hpp>
#include <stdio.h>

#include <decomp.h>

#pragma dont_reuse_strings off

namespace EGG {

// char Stream::sTextBuffer[0x400];

#ifdef NON_MATCHING
Dummy::~Dummy() {}

extern const char* bruh;
const char* bruh = "%d";

u32 Stream::read_u32() {
  if (m_flag & STREAM_TEXT) {
    u32 readValue;
    sscanf(getNextToken(), "%d", &readValue);
    return readValue;
  }

  u32 readValue;
  safeRead(&readValue, sizeof(u32));
  return readValue;
}

void Stream::readString(char* data, int size) {
  if (m_flag & STREAM_TEXT) {
    snprintf(data, size, "%s", getNextToken());
    return;
  }

  safeRead(data, size);
}

void Stream::safeRead(void* data, u32 size) {
  // (PROBABLY) from an assert that got stripped on release build
  eof();

  read(data, size);
  m_position += size;
}

void Stream::copyToTextBuffer() {
  m_textBuffer[0] = skipSpace();

  s32 r29 = 1; // size
  do {
    if (eof())
      return;

    if (r29 >= _14)
      return;

    eof();

    char read = _readByte();
    if (isSpace(read)) {
      m_textBuffer[0] = '\0';

      if (_1c || read != '#')
        return;

      while (true) {
        if (eof())
          return;

        eof();
        char read2 = _readByte();
        if (isUpperSJIS(read2))
          _readByte();
        else if (read2 == '\r' || read2 == '\n')
          return;
      }
    } else {
      if (!(m_textBuffer[r29++]))
        return;
    }
  } while (true);
}

char* Stream::getNextToken() {
  if (m_flag & STREAM_TEXT)
    return nullptr;

  if (_04) {
    _04 = false;
    return m_textBuffer;
  } else {
    copyToTextBuffer();
    return m_textBuffer;
  }
}

unsigned char Add0xF7(u8 in) { return in + 0xF7; }

bool Stream::isSpace(u8 toCheck) {
  // TODO: Fix start of the function to be 1:1
  bool r7 = true;
  bool r8 = true;
  bool r9 = false;

  u32 r6 = Add0xF7(toCheck);
  if (toCheck + 0xf7 <= 0x17) {
    if (0x800013 & (1 << r6))
      r9 = true;
  }

  if (r9) {
    bool r4Unk = false;
    if (_1c == 0 && (u32)toCheck == '#')
      r4Unk = true;

    if (!r4Unk)
      r8 = false;
  }

  if (!r8 && (u32)toCheck != 0x21)
    r7 = false;

  return r7;
}

bool Stream::isUpperSJIS(u8 toCheck) {
  if (toCheck >= 0x81 && toCheck < 0x9F)
    return true;

  if (toCheck < 0xe0 || toCheck > 0xfc)
    return false;
  return true;
}

bool Stream::skipSpace() {
  if (m_flag & STREAM_TEXT)
    return false;

  if (eof())
    return false;
}

Stream::Stream(u8* data, u32 size)
    : _04(false), m_flag(STREAM_BINARY), m_position(0), _18(0), _14(0x400),
      m_textBuffer(sTextBuffer), _1c(0) {
  m_binaryData = data;
  m_dataSize = size;
}

void Stream::read(void* r4, u32 r5) {
  u32 r7 = 0;
  if (r5 <= 0)
    return;

  do {

  } while (r5 / 8 && r5 & 7);

  do {
    m_binaryData[r7++] = ((char*)r4)[m_position];
    r4 = (char*)r4 + 1;
  } while (r5--);
}

u32 Stream::peek_u32() {
  u8 data[4] = {m_binaryData[m_position], m_binaryData[m_position + 1],
                m_binaryData[m_position + 2], m_binaryData[m_position + 3]};

  return *reinterpret_cast<u32*>(data);
}

void Stream::write(void* data, u32 size) {}
}
#else
}

// Symbol: __dt__Q23EGG6StreamFv
// PAL: 0x80241b60..0x80241ba0
MARK_BINARY_BLOB(__dt__Q23EGG6StreamFv, 0x80241b60, 0x80241ba0);
asm UNKNOWN_FUNCTION(__dt__Q23EGG6StreamFv) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  beq lbl_80241b88;
  cmpwi r4, 0;
  ble lbl_80241b88;
  bl __dl__FPv;
lbl_80241b88:
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: read_u32__Q23EGG6StreamFv
// PAL: 0x80241ba0..0x80241bfc
MARK_BINARY_BLOB(read_u32__Q23EGG6StreamFv, 0x80241ba0, 0x80241bfc);
asm UNKNOWN_FUNCTION(read_u32__Q23EGG6StreamFv) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  lhz r0, 0xc(r3);
  clrlwi. r0, r0, 0x1f;
  beq lbl_80241bdc;
  bl getNextToken__Q23EGG6StreamFv;
  lis r4, 0x8026;
  addi r5, r1, 8;
  addi r4, r4, -32208;
  addi r4, r4, 0x1c;
  crclr 6;
  bl sscanf;
  lwz r3, 8(r1);
  b lbl_80241bec;
lbl_80241bdc:
  addi r4, r1, 0xc;
  li r5, 4;
  bl saferead__Q23EGG6StreamFPvUl;
  lwz r3, 0xc(r1);
lbl_80241bec:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: readString__Q23EGG6StreamFPci
// PAL: 0x80241bfc..0x80241c68
MARK_BINARY_BLOB(readString__Q23EGG6StreamFPci, 0x80241bfc, 0x80241c68);
asm UNKNOWN_FUNCTION(readString__Q23EGG6StreamFPci) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r5;
  stw r30, 8(r1);
  mr r30, r4;
  lhz r0, 0xc(r3);
  clrlwi. r0, r0, 0x1f;
  beq lbl_80241c4c;
  bl getNextToken__Q23EGG6StreamFv;
  lis r5, 0x8026;
  mr r6, r3;
  addi r5, r5, -32208;
  mr r3, r30;
  mr r4, r31;
  addi r5, r5, 0x56;
  crclr 6;
  bl snprintf;
  b lbl_80241c50;
lbl_80241c4c:
  bl saferead__Q23EGG6StreamFPvUl;
lbl_80241c50:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: saferead__Q23EGG6StreamFPvUl
// PAL: 0x80241c68..0x80241ce0
MARK_BINARY_BLOB(saferead__Q23EGG6StreamFPvUl, 0x80241c68, 0x80241ce0);
asm UNKNOWN_FUNCTION(saferead__Q23EGG6StreamFPvUl) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r5;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  lwz r12, 0(r3);
  lwz r12, 0x14(r12);
  mtctr r12;
  bctrl;
  lwz r12, 0(r29);
  mr r3, r29;
  mr r4, r30;
  mr r5, r31;
  lwz r12, 0xc(r12);
  mtctr r12;
  bctrl;
  lwz r0, 8(r29);
  add r0, r0, r31;
  stw r0, 8(r29);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: copyToTextBuffer__Q23EGG6StreamFv
// PAL: 0x80241ce0..0x80241eac
MARK_BINARY_BLOB(copyToTextBuffer__Q23EGG6StreamFv, 0x80241ce0, 0x80241eac);
asm UNKNOWN_FUNCTION(copyToTextBuffer__Q23EGG6StreamFv) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r3;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  bl skipSpace__Q23EGG6StreamFv;
  lwz r4, 0x10(r31);
  li r29, 1;
  stb r3, 0(r4);
  b lbl_80241e68;
lbl_80241d10:
  lwz r12, 0(r31);
  mr r3, r31;
  lwz r12, 0x14(r12);
  mtctr r12;
  bctrl;
  lwz r12, 0(r31);
  mr r3, r31;
  addi r4, r1, 0xa;
  li r5, 1;
  lwz r12, 0xc(r12);
  mtctr r12;
  bctrl;
  lwz r4, 8(r31);
  mr r3, r31;
  addi r0, r4, 1;
  stw r0, 8(r31);
  lbz r0, 0xa(r1);
  extsb r30, r0;
  mr r4, r30;
  bl isSpace__Q23EGG6StreamFUc;
  cmpwi r3, 0;
  beq lbl_80241e54;
  lwz r3, 0x10(r31);
  li r0, 0;
  stbx r0, r3, r29;
  lbz r0, 0x1c(r31);
  cmpwi r0, 0;
  bne lbl_80241e90;
  cmpwi r30, 0x23;
  bne lbl_80241e90;
  b lbl_80241e34;
lbl_80241d8c:
  lwz r12, 0(r31);
  mr r3, r31;
  lwz r12, 0x14(r12);
  mtctr r12;
  bctrl;
  lwz r12, 0(r31);
  mr r3, r31;
  addi r4, r1, 9;
  li r5, 1;
  lwz r12, 0xc(r12);
  mtctr r12;
  bctrl;
  lwz r4, 8(r31);
  mr r3, r31;
  addi r0, r4, 1;
  stw r0, 8(r31);
  lbz r0, 9(r1);
  extsb r30, r0;
  mr r4, r30;
  bl isUpperSJIS__Q23EGG6StreamFUc;
  cmpwi r3, 0;
  beq lbl_80241e24;
  lwz r12, 0(r31);
  mr r3, r31;
  lwz r12, 0x14(r12);
  mtctr r12;
  bctrl;
  lwz r12, 0(r31);
  mr r3, r31;
  addi r4, r1, 8;
  li r5, 1;
  lwz r12, 0xc(r12);
  mtctr r12;
  bctrl;
  lwz r3, 8(r31);
  addi r0, r3, 1;
  stw r0, 8(r31);
  b lbl_80241e34;
lbl_80241e24:
  cmpwi r30, 0xd;
  beq lbl_80241e90;
  cmpwi r30, 0xa;
  beq lbl_80241e90;
lbl_80241e34:
  lwz r12, 0(r31);
  mr r3, r31;
  lwz r12, 0x14(r12);
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  beq lbl_80241d8c;
  b lbl_80241e90;
lbl_80241e54:
  lwz r3, 0x10(r31);
  cmpwi r30, 0;
  stbx r30, r3, r29;
  addi r29, r29, 1;
  beq lbl_80241e90;
lbl_80241e68:
  lwz r12, 0(r31);
  mr r3, r31;
  lwz r12, 0x14(r12);
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  bne lbl_80241e90;
  lwz r0, 0x14(r31);
  cmpw r29, r0;
  blt lbl_80241d10;
lbl_80241e90:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: getNextToken__Q23EGG6StreamFv
// PAL: 0x80241eac..0x80241f0c
MARK_BINARY_BLOB(getNextToken__Q23EGG6StreamFv, 0x80241eac, 0x80241f0c);
asm UNKNOWN_FUNCTION(getNextToken__Q23EGG6StreamFv) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  lhz r0, 0xc(r3);
  clrlwi. r0, r0, 0x1f;
  bne lbl_80241ed4;
  li r3, 0;
  b lbl_80241ef8;
lbl_80241ed4:
  lbz r0, 4(r3);
  cmpwi r0, 0;
  beq lbl_80241ef0;
  li r0, 0;
  stb r0, 4(r3);
  lwz r3, 0x10(r3);
  b lbl_80241ef8;
lbl_80241ef0:
  bl copyToTextBuffer__Q23EGG6StreamFv;
  lwz r3, 0x10(r31);
lbl_80241ef8:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: isSpace__Q23EGG6StreamFUc
// PAL: 0x80241f0c..0x80241f9c
MARK_BINARY_BLOB(isSpace__Q23EGG6StreamFUc, 0x80241f0c, 0x80241f9c);
asm UNKNOWN_FUNCTION(isSpace__Q23EGG6StreamFUc) {
  // clang-format off
  nofralloc;
  clrlwi r5, r4, 0x18;
  li r7, 1;
  addi r6, r5, 0xf7;
  li r8, 1;
  clrlwi r0, r6, 0x18;
  li r9, 0;
  cmplwi r0, 0x17;
  bgt lbl_80241f48;
  li r0, 1;
  lis r5, 0x80;
  slw r6, r0, r6;
  addi r0, r5, 0x13;
  and. r0, r6, r0;
  beq lbl_80241f48;
  li r9, 1;
lbl_80241f48:
  cmpwi r9, 0;
  bne lbl_80241f7c;
  lbz r0, 0x1c(r3);
  li r3, 0;
  cmpwi r0, 0;
  bne lbl_80241f70;
  extsb r0, r4;
  cmpwi r0, 0x23;
  bne lbl_80241f70;
  li r3, 1;
lbl_80241f70:
  cmpwi r3, 0;
  bne lbl_80241f7c;
  li r8, 0;
lbl_80241f7c:
  cmpwi r8, 0;
  bne lbl_80241f94;
  extsb r0, r4;
  cmpwi r0, 0x21;
  beq lbl_80241f94;
  li r7, 0;
lbl_80241f94:
  mr r3, r7;
  blr;
  // clang-format on
}

// Symbol: isUpperSJIS__Q23EGG6StreamFUc
// PAL: 0x80241f9c..0x80241fcc
MARK_BINARY_BLOB(isUpperSJIS__Q23EGG6StreamFUc, 0x80241f9c, 0x80241fcc);
asm UNKNOWN_FUNCTION(isUpperSJIS__Q23EGG6StreamFUc) {
  // clang-format off
  nofralloc;
  clrlwi r0, r4, 0x18;
  li r3, 0;
  cmplwi r0, 0x81;
  blt lbl_80241fb4;
  cmplwi r0, 0x9f;
  ble lbl_80241fc4;
lbl_80241fb4:
  cmplwi r0, 0xe0;
  bltlr;
  cmplwi r0, 0xfc;
  bgtlr;
lbl_80241fc4:
  li r3, 1;
  blr;
  // clang-format on
}

// Symbol: skipSpace__Q23EGG6StreamFv
// PAL: 0x80241fcc..0x802421d4
MARK_BINARY_BLOB(skipSpace__Q23EGG6StreamFv, 0x80241fcc, 0x802421d4);
asm UNKNOWN_FUNCTION(skipSpace__Q23EGG6StreamFv) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r3;
  stw r29, 0x14(r1);
  stw r28, 0x10(r1);
  lhz r0, 0xc(r3);
  clrlwi. r0, r0, 0x1f;
  beq lbl_802421b0;
  li r31, 0;
  li r28, 1;
  lis r29, 0x80;
  b lbl_80242194;
lbl_80242008:
  lwz r12, 0(r30);
  mr r3, r30;
  lwz r12, 0x14(r12);
  mtctr r12;
  bctrl;
  lwz r12, 0(r30);
  mr r3, r30;
  addi r4, r1, 9;
  li r5, 1;
  lwz r12, 0xc(r12);
  mtctr r12;
  bctrl;
  lwz r3, 8(r30);
  cmpwi r31, 0;
  addi r0, r3, 1;
  stw r0, 8(r30);
  lbz r0, 9(r1);
  extsb r3, r0;
  beq lbl_802420f0;
  clrlwi r4, r3, 0x18;
  li r0, 0;
  cmplwi r4, 0x81;
  blt lbl_8024206c;
  cmplwi r4, 0x9f;
  ble lbl_8024207c;
lbl_8024206c:
  cmplwi r4, 0xe0;
  blt lbl_80242080;
  cmplwi r4, 0xfc;
  bgt lbl_80242080;
lbl_8024207c:
  li r0, 1;
lbl_80242080:
  cmpwi r0, 0;
  beq lbl_802420c8;
  lwz r12, 0(r30);
  mr r3, r30;
  lwz r12, 0x14(r12);
  mtctr r12;
  bctrl;
  lwz r12, 0(r30);
  mr r3, r30;
  addi r4, r1, 8;
  li r5, 1;
  lwz r12, 0xc(r12);
  mtctr r12;
  bctrl;
  lwz r3, 8(r30);
  addi r0, r3, 1;
  stw r0, 8(r30);
  b lbl_80242194;
lbl_802420c8:
  cmpwi r3, 0xd;
  li r0, 0;
  beq lbl_802420dc;
  cmpwi r3, 0xa;
  bne lbl_802420e0;
lbl_802420dc:
  li r0, 1;
lbl_802420e0:
  cmpwi r0, 0;
  beq lbl_80242194;
  li r31, 0;
  b lbl_80242194;
lbl_802420f0:
  lbz r8, 0x1c(r30);
  cmpwi r8, 0;
  bne lbl_80242104;
  cmpwi r3, 0x23;
  beq lbl_8024210c;
lbl_80242104:
  cmpwi r3, 0x21;
  bne lbl_80242114;
lbl_8024210c:
  li r31, 1;
  b lbl_80242194;
lbl_80242114:
  clrlwi r4, r3, 0x18;
  li r5, 1;
  addi r4, r4, 0xf7;
  li r6, 1;
  clrlwi r0, r4, 0x18;
  li r7, 0;
  cmplwi r0, 0x17;
  bgt lbl_80242148;
  slw r4, r28, r4;
  addi r0, r29, 0x13;
  and. r0, r4, r0;
  beq lbl_80242148;
  li r7, 1;
lbl_80242148:
  cmpwi r7, 0;
  bne lbl_80242174;
  cmpwi r8, 0;
  li r0, 0;
  bne lbl_80242168;
  cmpwi r3, 0x23;
  bne lbl_80242168;
  li r0, 1;
lbl_80242168:
  cmpwi r0, 0;
  bne lbl_80242174;
  li r6, 0;
lbl_80242174:
  cmpwi r6, 0;
  bne lbl_80242188;
  cmpwi r3, 0x21;
  beq lbl_80242188;
  li r5, 0;
lbl_80242188:
  cmpwi r5, 0;
  bne lbl_80242194;
  b lbl_802421b4;
lbl_80242194:
  lwz r12, 0(r30);
  mr r3, r30;
  lwz r12, 0x14(r12);
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  beq lbl_80242008;
lbl_802421b0:
  li r3, 0;
lbl_802421b4:
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

// Symbol: __ct__Q23EGG9RamStreamFPUcUl
// PAL: 0x802421d4..0x80242218
MARK_BINARY_BLOB(__ct__Q23EGG9RamStreamFPUcUl, 0x802421d4, 0x80242218);
asm UNKNOWN_FUNCTION(__ct__Q23EGG9RamStreamFPUcUl) {
  // clang-format off
  nofralloc;
  lis r7, 0x8038;
  lis r6, 0x802a;
  li r8, 0;
  li r0, 0x400;
  addi r7, r7, 0x4560;
  addi r6, r6, 0x3f50;
  stb r8, 4(r3);
  sth r8, 0xc(r3);
  stw r8, 8(r3);
  stw r8, 0x18(r3);
  stw r0, 0x14(r3);
  stw r7, 0x10(r3);
  stb r8, 0x1c(r3);
  stw r6, 0(r3);
  stw r4, 0x20(r3);
  stw r5, 0x24(r3);
  blr;
  // clang-format on
}

// Symbol: read__Q23EGG9RamStreamFPvUl
// PAL: 0x80242218..0x80242328
MARK_BINARY_BLOB(read__Q23EGG9RamStreamFPvUl, 0x80242218, 0x80242328);
asm UNKNOWN_FUNCTION(read__Q23EGG9RamStreamFPvUl) {
  // clang-format off
  nofralloc;
  cmplwi r5, 0;
  li r7, 0;
  blelr;
  rlwinm. r0, r5, 0x1d, 3, 0x1f;
  mtctr r0;
  beq lbl_80242300;
lbl_80242230:
  lwz r0, 0x20(r3);
  lwz r6, 8(r3);
  add r0, r7, r0;
  addi r7, r7, 1;
  lbzx r0, r6, r0;
  stb r0, 0(r4);
  lwz r0, 0x20(r3);
  lwz r6, 8(r3);
  add r0, r7, r0;
  addi r7, r7, 1;
  lbzx r0, r6, r0;
  stb r0, 1(r4);
  lwz r0, 0x20(r3);
  lwz r6, 8(r3);
  add r0, r7, r0;
  addi r7, r7, 1;
  lbzx r0, r6, r0;
  stb r0, 2(r4);
  lwz r0, 0x20(r3);
  lwz r6, 8(r3);
  add r0, r7, r0;
  addi r7, r7, 1;
  lbzx r0, r6, r0;
  stb r0, 3(r4);
  lwz r0, 0x20(r3);
  lwz r6, 8(r3);
  add r0, r7, r0;
  addi r7, r7, 1;
  lbzx r0, r6, r0;
  stb r0, 4(r4);
  lwz r0, 0x20(r3);
  lwz r6, 8(r3);
  add r0, r7, r0;
  addi r7, r7, 1;
  lbzx r0, r6, r0;
  stb r0, 5(r4);
  lwz r0, 0x20(r3);
  lwz r6, 8(r3);
  add r0, r7, r0;
  addi r7, r7, 1;
  lbzx r0, r6, r0;
  stb r0, 6(r4);
  lwz r0, 0x20(r3);
  lwz r6, 8(r3);
  add r0, r7, r0;
  addi r7, r7, 1;
  lbzx r0, r6, r0;
  stb r0, 7(r4);
  addi r4, r4, 8;
  bdnz lbl_80242230;
  andi. r5, r5, 7;
  beqlr;
lbl_80242300:
  mtctr r5;
lbl_80242304:
  lwz r0, 0x20(r3);
  lwz r6, 8(r3);
  add r0, r7, r0;
  addi r7, r7, 1;
  lbzx r0, r6, r0;
  stb r0, 0(r4);
  addi r4, r4, 1;
  bdnz lbl_80242304;
  blr;
  // clang-format on
}

// Symbol: peek_u32__Q23EGG9RamStreamFv
// PAL: 0x80242328..0x80242364
MARK_BINARY_BLOB(peek_u32__Q23EGG9RamStreamFv, 0x80242328, 0x80242364);
asm UNKNOWN_FUNCTION(peek_u32__Q23EGG9RamStreamFv) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  lwz r4, 0x20(r3);
  lwz r0, 8(r3);
  add r5, r4, r0;
  lbzx r6, r4, r0;
  lbz r4, 1(r5);
  lbz r3, 2(r5);
  lbz r0, 3(r5);
  stb r6, 8(r1);
  stb r4, 9(r1);
  stb r3, 0xa(r1);
  stb r0, 0xb(r1);
  lwz r3, 8(r1);
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: write__Q23EGG9RamStreamFPvUl
// PAL: 0x80242364..0x80242474
MARK_BINARY_BLOB(write__Q23EGG9RamStreamFPvUl, 0x80242364, 0x80242474);
asm UNKNOWN_FUNCTION(write__Q23EGG9RamStreamFPvUl) {
  // clang-format off
  nofralloc;
  cmplwi r5, 0;
  li r8, 0;
  blelr;
  rlwinm. r0, r5, 0x1d, 3, 0x1f;
  mtctr r0;
  beq lbl_8024244c;
lbl_8024237c:
  lwz r0, 0x20(r3);
  lwz r6, 8(r3);
  add r0, r8, r0;
  lbz r7, 0(r4);
  stbx r7, r6, r0;
  addi r8, r8, 1;
  lwz r0, 0x20(r3);
  lwz r6, 8(r3);
  add r0, r8, r0;
  lbz r7, 1(r4);
  stbx r7, r6, r0;
  addi r8, r8, 1;
  lwz r0, 0x20(r3);
  lwz r6, 8(r3);
  add r0, r8, r0;
  lbz r7, 2(r4);
  stbx r7, r6, r0;
  addi r8, r8, 1;
  lwz r0, 0x20(r3);
  lwz r6, 8(r3);
  add r0, r8, r0;
  lbz r7, 3(r4);
  stbx r7, r6, r0;
  addi r8, r8, 1;
  lwz r0, 0x20(r3);
  lwz r6, 8(r3);
  add r0, r8, r0;
  lbz r7, 4(r4);
  stbx r7, r6, r0;
  addi r8, r8, 1;
  lwz r0, 0x20(r3);
  lwz r6, 8(r3);
  add r0, r8, r0;
  lbz r7, 5(r4);
  stbx r7, r6, r0;
  addi r8, r8, 1;
  lwz r0, 0x20(r3);
  lwz r6, 8(r3);
  add r0, r8, r0;
  lbz r7, 6(r4);
  stbx r7, r6, r0;
  addi r8, r8, 1;
  lwz r0, 0x20(r3);
  lwz r6, 8(r3);
  add r0, r8, r0;
  lbz r7, 7(r4);
  stbx r7, r6, r0;
  addi r8, r8, 1;
  addi r4, r4, 8;
  bdnz lbl_8024237c;
  andi. r5, r5, 7;
  beqlr;
lbl_8024244c:
  mtctr r5;
lbl_80242450:
  lwz r0, 0x20(r3);
  lwz r6, 8(r3);
  add r0, r8, r0;
  lbz r7, 0(r4);
  stbx r7, r6, r0;
  addi r8, r8, 1;
  addi r4, r4, 1;
  bdnz lbl_80242450;
  blr;
  // clang-format on
}
#endif

namespace EGG {

bool RamStream::eof() const { return m_position > m_dataSize; }
void RamStream::beginMemoryMap(char*) {}
void RamStream::endMemoryMap(char*) {}

} // namespace EGG
