#include "ut_nandFileStream.hpp"

#include <platform/eabi.h>
#include <rvl/nand/nand.h>

#include <decomp.h>

// Source:
// https://github.com/kiwi515/ogws/blob/master/src/nw4r/ut/ut_NandFileStream.cpp
// Credit: GibHaltmannKill

extern "C" {

// PAL: 0x800aff10..0x800aff80
UNKNOWN_FUNCTION(Skip__Q44nw4r2ut10FileStream12FilePositionFl);
// PAL: 0x800aff80..0x800affd0
UNKNOWN_FUNCTION(Append__Q44nw4r2ut10FileStream12FilePositionFl);
// PAL: 0x800affd0..0x800b0058
UNKNOWN_FUNCTION(Seek__Q44nw4r2ut10FileStream12FilePositionFlUl);

// PAL: 0x800b0ad0..0x800b0b40
UNKNOWN_FUNCTION(__ct__Q34nw4r2ut14NandFileStreamFPCcUl);
// PAL: 0x800b0b40..0x800b0bb0
UNKNOWN_FUNCTION(__ct__Q34nw4r2ut14NandFileStreamFPC12NANDFileInfoUlb);
// PAL: 0x800b0bb0..0x800b0c30
UNKNOWN_FUNCTION(__dt__Q34nw4r2ut14NandFileStreamFv);
// PAL: 0x800b0c30..0x800b0d20
UNKNOWN_FUNCTION(Open__Q34nw4r2ut14NandFileStreamFPCcUl);
// PAL: 0x800b0d20..0x800b14a0
UNKNOWN_FUNCTION(Open__Q34nw4r2ut14NandFileStreamFPC12NANDFileInfoUlb);
// PAL: 0x800b14a0..0x800b14f0
UNKNOWN_FUNCTION(Close__Q34nw4r2ut14NandFileStreamFv);
// PAL: 0x800b14f0..0x800b1570
UNKNOWN_FUNCTION(Read__Q34nw4r2ut14NandFileStreamFPvUl);
// PAL: 0x800b1570..0x800b1620
UNKNOWN_FUNCTION(ReadAsync__Q34nw4r2ut14NandFileStreamFPvUlUlPv);
// PAL: 0x800b1620..0x800b16a0
UNKNOWN_FUNCTION(Write__Q34nw4r2ut14NandFileStreamFPCvUl);
// PAL: 0x800b16a0..0x800b1750
UNKNOWN_FUNCTION(WriteAsync__Q34nw4r2ut14NandFileStreamFPCvUlUlPv);
// PAL: 0x800b1750..0x800b1758
UNKNOWN_FUNCTION(Seek__Q34nw4r2ut14NandFileStreamFlUl);
}

namespace nw4r {
namespace ut {

void NandFileStream::NandAsyncCallback_(s32 r3, NANDCommandBlock* r4) {
  NANDCB_UNK* r4_2 = r4->PTR_0x144;

  r4_2->BYTE_0x16A = false;
  r4_2->WORD_0x8 = r3;
  if (!r4_2->CALLBACK_0xC)
    return;
  r4_2->CALLBACK_0xC(r3, r4_2, r4_2->WORD_0x10);
  return;
}

// PAL: 0x800b0ad0..0x800b0b40
NandFileStream::NandFileStream(const char* str, u32 num) : mPosition() {
  Initialize_();
  Open(str, num);
}

// PAL: 0x800b0b40..0x800b0bb0
NandFileStream::NandFileStream(const NANDFileInfo* fileInfo, u32 num, bool b)
    : mPosition() {
  Initialize_();
  Open(fileInfo, num, b);
}

// PAL: 0x800b0bb0..0x800b0c30
NandFileStream::~NandFileStream() {
  if (BYTE_0x167)
    this->Close();
}

// PAL: 0x800b0c30..0x800b0d20
bool NandFileStream::Open(const char* str, u32 num) {
  u32 fileSize; // at 0x8

  if (BYTE_0x167)
    this->Close();

  mReadFlag = num & 0x00000001;
  mWriteFlag = num & 0x00000002;

  if (NANDOpen(str, &mFileInfo, num))
    return false;

  if (mReadFlag) {
    if (NANDGetLength(&mFileInfo, &fileSize) != 0) {
      NANDClose(&mFileInfo);
      return false;
    }

    mPosition.SetFileSize(fileSize);
  }

  mPosition.Seek(0, 0);

  BYTE_0x167 = 1;
  BYTE_0x168 = 1;
  BOOL_0x4 = true;

  return true;
}

// PAL: 0x800b0d20..0x800b14a0
MARK_BINARY_BLOB(Open__Q34nw4r2ut14NandFileStreamFPC12NANDFileInfoUlb,
                 0x800b0d20, 0x800b14a0);
asm bool NandFileStream::Open(const NANDFileInfo*, u32, bool) {
  // clang-format off
  nofralloc;
  stwu r1, -0x1a0(r1);
  mflr r0;
  stw r0, 0x1a4(r1);
  addi r11, r1, 0x1a0;
  bl _savegpr_14;
  lbz r0, 0x16b(r3);
  mr r30, r3;
  stb r6, 8(r1);
  mr r31, r4;
  cmpwi r0, 0;
  mr r14, r5;
  beq lbl_800b0d60;
  lwz r12, 0(r3);
  lwz r12, 0x10(r12);
  mtctr r12;
  bctrl;
lbl_800b0d60:
  lbz r28, 0x1e(r31);
  clrlwi r27, r14, 0x1f;
  stw r28, 0x148(r1);
  rlwinm r26, r14, 0x1f, 0x1f, 0x1f;
  lbz r28, 0x1f(r31);
  lbz r0, 0x1c(r31);
  stw r28, 0x10(r1);
  lbz r28, 0x20(r31);
  stw r28, 0x14(r1);
  lbz r28, 0x21(r31);
  stb r0, 0xf4(r30);
  lwz r0, 0x148(r1);
  stw r28, 0x18(r1);
  lbz r28, 0x22(r31);
  stb r0, 0xf6(r30);
  lwz r0, 0x10(r1);
  stw r28, 0x1c(r1);
  lbz r28, 0x23(r31);
  stb r0, 0xf7(r30);
  lwz r0, 0x14(r1);
  stw r28, 0x20(r1);
  lbz r28, 0x24(r31);
  stb r0, 0xf8(r30);
  lwz r0, 0x18(r1);
  stw r28, 0x24(r1);
  lbz r28, 0x25(r31);
  stb r0, 0xf9(r30);
  lwz r0, 0x1c(r1);
  stw r28, 0x28(r1);
  lbz r28, 0x26(r31);
  stb r0, 0xfa(r30);
  lwz r0, 0x20(r1);
  stw r28, 0x2c(r1);
  lbz r28, 0x27(r31);
  stb r0, 0xfb(r30);
  lwz r0, 0x24(r1);
  stw r28, 0x30(r1);
  lbz r28, 0x28(r31);
  stb r0, 0xfc(r30);
  lwz r0, 0x28(r1);
  stw r28, 0x34(r1);
  lbz r28, 0x29(r31);
  stb r0, 0xfd(r30);
  lwz r0, 0x2c(r1);
  stw r28, 0x38(r1);
  lbz r28, 0x2a(r31);
  stb r0, 0xfe(r30);
  lwz r0, 0x30(r1);
  stw r28, 0x3c(r1);
  lbz r28, 0x2b(r31);
  stb r0, 0xff(r30);
  lwz r0, 0x34(r1);
  stw r28, 0x40(r1);
  lbz r28, 0x2c(r31);
  stb r0, 0x100(r30);
  lwz r0, 0x38(r1);
  stw r28, 0x44(r1);
  lbz r28, 0x2d(r31);
  stb r0, 0x101(r30);
  lwz r0, 0x3c(r1);
  stw r28, 0x48(r1);
  lbz r28, 0x2e(r31);
  stb r0, 0x102(r30);
  lwz r0, 0x40(r1);
  stw r28, 0x4c(r1);
  lbz r28, 0x2f(r31);
  stb r0, 0x103(r30);
  lwz r0, 0x44(r1);
  stw r28, 0x50(r1);
  lbz r28, 0x30(r31);
  stb r0, 0x104(r30);
  lwz r0, 0x48(r1);
  stw r28, 0x54(r1);
  lbz r28, 0x31(r31);
  stb r0, 0x105(r30);
  lwz r0, 0x4c(r1);
  stw r28, 0x58(r1);
  lbz r28, 0x32(r31);
  stb r0, 0x106(r30);
  lwz r0, 0x50(r1);
  stw r28, 0x5c(r1);
  lbz r28, 0x33(r31);
  stb r0, 0x107(r30);
  lwz r0, 0x54(r1);
  stw r28, 0x60(r1);
  lbz r28, 0x34(r31);
  stb r0, 0x108(r30);
  lwz r0, 0x58(r1);
  stw r28, 0x64(r1);
  lbz r28, 0x35(r31);
  stb r0, 0x109(r30);
  lwz r0, 0x5c(r1);
  stw r28, 0x68(r1);
  lbz r28, 0x36(r31);
  stb r0, 0x10a(r30);
  lwz r0, 0x60(r1);
  stw r28, 0x6c(r1);
  lbz r28, 0x37(r31);
  stb r0, 0x10b(r30);
  lwz r0, 0x64(r1);
  stw r28, 0x70(r1);
  lbz r28, 0x38(r31);
  stb r0, 0x10c(r30);
  lwz r0, 0x68(r1);
  stw r28, 0x74(r1);
  lbz r28, 0x39(r31);
  stb r0, 0x10d(r30);
  lwz r0, 0x6c(r1);
  stw r28, 0x78(r1);
  lbz r28, 0x3a(r31);
  stb r0, 0x10e(r30);
  lwz r0, 0x70(r1);
  stw r28, 0x7c(r1);
  lbz r28, 0x3b(r31);
  stb r0, 0x10f(r30);
  lwz r0, 0x74(r1);
  stw r28, 0x80(r1);
  lbz r28, 0x3c(r31);
  stb r0, 0x110(r30);
  lwz r0, 0x78(r1);
  stw r28, 0x84(r1);
  lbz r28, 0x3d(r31);
  stb r0, 0x111(r30);
  lwz r0, 0x7c(r1);
  stw r28, 0x88(r1);
  lbz r28, 0x3e(r31);
  stb r0, 0x112(r30);
  lwz r0, 0x80(r1);
  stw r28, 0x8c(r1);
  lbz r28, 0x3f(r31);
  stb r0, 0x113(r30);
  lwz r0, 0x84(r1);
  stw r28, 0x90(r1);
  lbz r28, 0x40(r31);
  stb r0, 0x114(r30);
  lwz r0, 0x88(r1);
  stw r28, 0x94(r1);
  lbz r28, 0x41(r31);
  stb r0, 0x115(r30);
  lwz r0, 0x8c(r1);
  stw r28, 0x98(r1);
  lbz r28, 0x42(r31);
  stb r0, 0x116(r30);
  lwz r0, 0x90(r1);
  stw r28, 0x9c(r1);
  lbz r28, 0x43(r31);
  stb r0, 0x117(r30);
  lwz r0, 0x94(r1);
  stw r28, 0xa0(r1);
  lbz r28, 0x44(r31);
  stb r0, 0x118(r30);
  lwz r0, 0x98(r1);
  stw r28, 0xa4(r1);
  lbz r28, 0x45(r31);
  stb r0, 0x119(r30);
  lwz r0, 0x9c(r1);
  stw r28, 0xa8(r1);
  lbz r28, 0x46(r31);
  stb r0, 0x11a(r30);
  lwz r0, 0xa0(r1);
  stw r28, 0xac(r1);
  lbz r28, 0x47(r31);
  stb r0, 0x11b(r30);
  lwz r0, 0xa4(r1);
  stb r0, 0x11c(r30);
  lwz r0, 0xa8(r1);
  lwz r25, 0(r31);
  lwz r24, 4(r31);
  lbz r23, 8(r31);
  lbz r22, 9(r31);
  lbz r21, 0xa(r31);
  lbz r20, 0xb(r31);
  lbz r19, 0xc(r31);
  lbz r18, 0xd(r31);
  lbz r17, 0xe(r31);
  lbz r16, 0xf(r31);
  lbz r15, 0x10(r31);
  lbz r14, 0x11(r31);
  lbz r12, 0x12(r31);
  lbz r11, 0x13(r31);
  lbz r10, 0x14(r31);
  lbz r9, 0x15(r31);
  lbz r8, 0x16(r31);
  lbz r7, 0x17(r31);
  lbz r6, 0x18(r31);
  lbz r5, 0x19(r31);
  lbz r4, 0x1a(r31);
  lbz r3, 0x1b(r31);
  lbz r29, 0x1d(r31);
  stb r0, 0x11d(r30);
  lwz r0, 0xac(r1);
  stb r0, 0x11e(r30);
  mr r0, r28;
  stw r28, 0xb0(r1);
  stb r27, 0x168(r30);
  stb r26, 0x169(r30);
  stw r25, 0xd8(r30);
  stw r24, 0xdc(r30);
  stb r23, 0xe0(r30);
  stb r22, 0xe1(r30);
  stb r21, 0xe2(r30);
  stb r20, 0xe3(r30);
  stb r19, 0xe4(r30);
  stb r18, 0xe5(r30);
  stb r17, 0xe6(r30);
  stb r16, 0xe7(r30);
  stb r15, 0xe8(r30);
  stb r14, 0xe9(r30);
  stb r12, 0xea(r30);
  stb r11, 0xeb(r30);
  stb r10, 0xec(r30);
  stb r9, 0xed(r30);
  stb r8, 0xee(r30);
  stb r7, 0xef(r30);
  stb r6, 0xf0(r30);
  stb r5, 0xf1(r30);
  stb r4, 0xf2(r30);
  stb r3, 0xf3(r30);
  stb r29, 0xf5(r30);
  stb r0, 0x11f(r30);
  lbz r15, 0x62(r31);
  stw r15, 0x14c(r1);
  lbz r15, 0x63(r31);
  lbz r0, 0x60(r31);
  stw r15, 0xb4(r1);
  lbz r15, 0x64(r31);
  stw r15, 0xb8(r1);
  lbz r15, 0x65(r31);
  stb r0, 0x138(r30);
  lwz r0, 0x14c(r1);
  stw r15, 0xbc(r1);
  lbz r15, 0x66(r31);
  stb r0, 0x13a(r30);
  lwz r0, 0xb4(r1);
  stw r15, 0xc0(r1);
  lbz r15, 0x67(r31);
  stb r0, 0x13b(r30);
  lwz r0, 0xb8(r1);
  stw r15, 0xc4(r1);
  lbz r15, 0x68(r31);
  stb r0, 0x13c(r30);
  lwz r0, 0xbc(r1);
  stw r15, 0xc8(r1);
  lbz r15, 0x69(r31);
  stb r0, 0x13d(r30);
  lwz r0, 0xc0(r1);
  stw r15, 0xcc(r1);
  lbz r15, 0x6a(r31);
  stb r0, 0x13e(r30);
  lwz r0, 0xc4(r1);
  stw r15, 0xd0(r1);
  lbz r15, 0x6b(r31);
  stb r0, 0x13f(r30);
  lwz r0, 0xc8(r1);
  stw r15, 0xd4(r1);
  lbz r15, 0x6c(r31);
  stb r0, 0x140(r30);
  lwz r0, 0xcc(r1);
  stw r15, 0xd8(r1);
  lbz r15, 0x6d(r31);
  stb r0, 0x141(r30);
  lwz r0, 0xd0(r1);
  stw r15, 0xdc(r1);
  lbz r15, 0x6e(r31);
  stb r0, 0x142(r30);
  lwz r0, 0xd4(r1);
  stw r15, 0xe0(r1);
  lbz r15, 0x6f(r31);
  stb r0, 0x143(r30);
  lwz r0, 0xd8(r1);
  stw r15, 0xe4(r1);
  lbz r15, 0x70(r31);
  stb r0, 0x144(r30);
  lwz r0, 0xdc(r1);
  stw r15, 0xe8(r1);
  lbz r15, 0x71(r31);
  stb r0, 0x145(r30);
  lwz r0, 0xe0(r1);
  stw r15, 0xec(r1);
  lbz r15, 0x72(r31);
  stb r0, 0x146(r30);
  lwz r0, 0xe4(r1);
  stw r15, 0xf0(r1);
  lbz r15, 0x73(r31);
  stb r0, 0x147(r30);
  lwz r0, 0xe8(r1);
  stw r15, 0xf4(r1);
  lbz r15, 0x74(r31);
  stb r0, 0x148(r30);
  lwz r0, 0xec(r1);
  stw r15, 0xf8(r1);
  lbz r15, 0x75(r31);
  stb r0, 0x149(r30);
  lwz r0, 0xf0(r1);
  stw r15, 0xfc(r1);
  lbz r15, 0x76(r31);
  stb r0, 0x14a(r30);
  lwz r0, 0xf4(r1);
  stw r15, 0x100(r1);
  lbz r15, 0x77(r31);
  stb r0, 0x14b(r30);
  lwz r0, 0xf8(r1);
  stw r15, 0x104(r1);
  lbz r15, 0x78(r31);
  stb r0, 0x14c(r30);
  lwz r0, 0xfc(r1);
  stw r15, 0x108(r1);
  lbz r15, 0x79(r31);
  stb r0, 0x14d(r30);
  lwz r0, 0x100(r1);
  stw r15, 0x10c(r1);
  lbz r15, 0x7a(r31);
  stb r0, 0x14e(r30);
  lwz r0, 0x104(r1);
  stw r15, 0x110(r1);
  lbz r15, 0x7b(r31);
  stb r0, 0x14f(r30);
  lwz r0, 0x108(r1);
  stw r15, 0x114(r1);
  lbz r15, 0x7c(r31);
  stb r0, 0x150(r30);
  lwz r0, 0x10c(r1);
  stw r15, 0x118(r1);
  lbz r15, 0x7d(r31);
  stb r0, 0x151(r30);
  lwz r0, 0x110(r1);
  stw r15, 0x11c(r1);
  lbz r15, 0x7e(r31);
  stb r0, 0x152(r30);
  lwz r0, 0x114(r1);
  stw r15, 0x120(r1);
  lbz r15, 0x7f(r31);
  stb r0, 0x153(r30);
  lwz r0, 0x118(r1);
  stw r15, 0x124(r1);
  lbz r15, 0x80(r31);
  stb r0, 0x154(r30);
  lwz r0, 0x11c(r1);
  stw r15, 0x128(r1);
  lbz r15, 0x81(r31);
  stb r0, 0x155(r30);
  lwz r0, 0x120(r1);
  stw r15, 0x12c(r1);
  lbz r15, 0x82(r31);
  stb r0, 0x156(r30);
  lwz r0, 0x124(r1);
  stw r15, 0x130(r1);
  lbz r15, 0x83(r31);
  stb r0, 0x157(r30);
  lwz r0, 0x128(r1);
  stw r15, 0x134(r1);
  lbz r15, 0x84(r31);
  stb r0, 0x158(r30);
  lwz r0, 0x12c(r1);
  stw r15, 0x138(r1);
  lbz r15, 0x85(r31);
  stb r0, 0x159(r30);
  lwz r0, 0x130(r1);
  stw r15, 0x13c(r1);
  lbz r15, 0x86(r31);
  stb r0, 0x15a(r30);
  lwz r0, 0x134(r1);
  stw r15, 0x140(r1);
  lbz r15, 0x87(r31);
  stb r0, 0x15b(r30);
  lwz r0, 0x138(r1);
  stb r0, 0x15c(r30);
  lwz r0, 0x13c(r1);
  lbz r16, 0x48(r31);
  lbz r17, 0x49(r31);
  lbz r18, 0x4a(r31);
  lbz r19, 0x4b(r31);
  lbz r20, 0x4c(r31);
  lbz r21, 0x4d(r31);
  lbz r22, 0x4e(r31);
  lbz r23, 0x4f(r31);
  lbz r24, 0x50(r31);
  lbz r25, 0x51(r31);
  lbz r26, 0x52(r31);
  lbz r27, 0x53(r31);
  lbz r28, 0x54(r31);
  lbz r29, 0x55(r31);
  lbz r12, 0x56(r31);
  lbz r11, 0x57(r31);
  lbz r10, 0x58(r31);
  lbz r9, 0x59(r31);
  lbz r8, 0x5a(r31);
  lbz r7, 0x5b(r31);
  lbz r6, 0x5c(r31);
  lbz r5, 0x5d(r31);
  lbz r4, 0x5e(r31);
  lbz r3, 0x5f(r31);
  lbz r14, 0x61(r31);
  stb r0, 0x15d(r30);
  lwz r0, 0x140(r1);
  stb r0, 0x15e(r30);
  mr r0, r15;
  stw r15, 0x144(r1);
  stb r16, 0x120(r30);
  stb r17, 0x121(r30);
  stb r18, 0x122(r30);
  stb r19, 0x123(r30);
  stb r20, 0x124(r30);
  stb r21, 0x125(r30);
  stb r22, 0x126(r30);
  stb r23, 0x127(r30);
  stb r24, 0x128(r30);
  stb r25, 0x129(r30);
  stb r26, 0x12a(r30);
  stb r27, 0x12b(r30);
  stb r28, 0x12c(r30);
  stb r29, 0x12d(r30);
  stb r12, 0x12e(r30);
  stb r11, 0x12f(r30);
  stb r10, 0x130(r30);
  stb r9, 0x131(r30);
  stb r8, 0x132(r30);
  stb r7, 0x133(r30);
  stb r6, 0x134(r30);
  stb r5, 0x135(r30);
  stb r4, 0x136(r30);
  stb r3, 0x137(r30);
  stb r14, 0x139(r30);
  stb r0, 0x15f(r30);
  lbz r6, 0x88(r31);
  addi r3, r30, 0xd8;
  lbz r5, 0x89(r31);
  addi r4, r1, 0xc;
  lbz r0, 0x8a(r31);
  stb r6, 0x160(r30);
  stb r5, 0x161(r30);
  stb r0, 0x162(r30);
  bl NANDGetLength;
  cmpwi r3, 0;
  beq lbl_800b1448;
  lbz r0, 8(r1);
  cmpwi r0, 0;
  beq lbl_800b1440;
  addi r3, r30, 0xd8;
  bl NANDClose;
lbl_800b1440:
  li r3, 0;
  b lbl_800b147c;
lbl_800b1448:
  lwz r0, 0xc(r1);
  addi r3, r30, 0x14;
  stw r0, 0x14(r30);
  li r4, 0;
  li r5, 0;
  bl Seek__Q44nw4r2ut10FileStream12FilePositionFlUl;
  li r0, 0;
  stb r0, 0x16b(r30);
  lbz r0, 8(r1);
  li r4, 1;
  stb r0, 0x16c(r30);
  li r3, 1;
  stb r4, 4(r30);
lbl_800b147c:
  addi r11, r1, 0x1a0;
  bl _restgpr_14;
  lwz r0, 0x1a4(r1);
  mtlr r0;
  addi r1, r1, 0x1a0;
  blr;
  // clang-format on
}

// PAL: 0x800b14a0..0x800b14f0
void NandFileStream::Close() {
  if (BYTE_0x168 && BOOL_0x4) {
    NANDClose(&mFileInfo);
    BOOL_0x4 = false;
  }
}

// PAL: 0x800b14f0..0x800b1570
int NandFileStream::Read(void* buf, u32 size) {
  int ret;

  NANDSeek(&mFileInfo, mPosition.mFileOffset, 0);
  ret = NANDRead(&mFileInfo, buf, size);
  if (ret > 0)
    mPosition.Skip(ret);

  return ret;
}

// PAL: 0x800b1570..0x800b1620
bool NandFileStream::ReadAsync(void* buf, u32 size, AsyncFunctor async,
                               void* ptr) {
  bool ret;
  ASYNC_0xC = async;
  PTR_0x10 = ptr;
  mBusyFlag = true;
  NANDSeek(&mFileInfo, mPosition.mFileOffset, 0);
  ret = NANDReadAsync(&mFileInfo, buf, size, NandAsyncCallback_, UNK_0x1C) == 0;

  if (ret) {
    mPosition.Skip(size);
  } else {
    mBusyFlag = false;
  }

  return ret;
}

// PAL: 0x800b1620..0x800b16a0
s32 NandFileStream::Write(const void* buf, u32 size) {
  NANDSeek(&mFileInfo, mPosition.mFileOffset, 0);
  s32 num = NANDWrite(&mFileInfo, buf, size);
  if (num > 0) {
    mPosition.Append(num);
  }
  return num;
}

// PAL: 0x800b16a0..0x800b1750
bool NandFileStream::WriteAsync(const void* buf, u32 size, AsyncFunctor async,
                                void* ptr) {
  ASYNC_0xC = async;
  PTR_0x10 = ptr;
  mBusyFlag = true;
  NANDSeek(&mFileInfo, mPosition.mFileOffset, 0);

  s32 ret = NANDWriteAsync(&mFileInfo, buf, size, NandAsyncCallback_, UNK_0x1C);

  if (ret == 0) {
    mPosition.Append(size);
  } else {
    mBusyFlag = false;
  }

  return ret == 0;
}

// PAL: 0x800b1750..0x800b1758
void NandFileStream::Seek(s32 offset, u32 origin) {
  mPosition.Seek(offset, origin);
}

u32 NandFileStream::GetSize() const { return mPosition.mFileSize; }
u32 NandFileStream::Tell() const { return mPosition.mFileOffset; }

detail::RuntimeTypeInfo NandFileStream::typeInfo(&FileStream::typeInfo);

} // namespace ut
} // namespace nw4r
