#include "snd_dvdSoundArchive.hpp"

// Source:
// https://github.com/kiwi515/ogws/blob/master/src/nw4r/snd/snd_DvdSoundArchive.cpp
// Credit: kiwi515
// Credit: GibHaltmannKill

#include <string.h>

// Extern function references.
extern "C" {
// PAL: 0x8009de90
extern UNKNOWN_FUNCTION(unk_8009de90);
// PAL: 0x8009e610
extern UNKNOWN_FUNCTION(unk_8009e610);
// PAL: 0x8009e690
extern UNKNOWN_FUNCTION(unk_8009e690);
// PAL: 0x8009e6c0
extern UNKNOWN_FUNCTION(SoundArchiveFileReader_Init);
// PAL: 0x8009e770
extern UNKNOWN_FUNCTION(unk_8009e770);
// PAL: 0x8009e820
extern UNKNOWN_FUNCTION(unk_8009e820);
// PAL: 0x800b05e0
extern UNKNOWN_FUNCTION(Seek__Q34nw4r2ut13DvdFileStreamFlUl);
// PAL: 0x800b06b0
extern UNKNOWN_FUNCTION(__ct__Q34nw4r2ut19DvdLockedFileStreamFl);
// PAL: 0x800b0740
extern UNKNOWN_FUNCTION(__ct__Q34nw4r2ut19DvdLockedFileStreamFPC11DVDFileInfob);
// PAL: 0x800b07d0
extern UNKNOWN_FUNCTION(unk_800b07d0);
// PAL: 0x800b0870
extern UNKNOWN_FUNCTION(unk_800b0870);
}

// TODO Symbol names are best guesses.

namespace nw4r {
namespace snd {

// Symbol: __ct__Q34nw4r3snd15DvdSoundArchiveFv
// PAL: 0x80090fc0..0x80091010
DvdSoundArchive::DvdSoundArchive() : mOpenFlag(false) {}

// Symbol: __dt__Q34nw4r3snd15DvdSoundArchiveFv
// PAL: 0x80091010..0x80091090
DvdSoundArchive::~DvdSoundArchive() { Close(); }

// Symbol: Open__Q34nw4r3snd15DvdSoundArchiveFPCc
// PAL: 0x80091090..0x800911d0
MARK_BINARY_BLOB(Open__Q34nw4r3snd15DvdSoundArchiveFPCc, 0x80091090,
                 0x800911d0);
asm bool DvdSoundArchive::Open(const char* path) {
  // clang-format off
  nofralloc;
  stwu r1, -0x180(r1);
  mflr r0;
  stw r0, 0x184(r1);
  stw r31, 0x17c(r1);
  stw r30, 0x178(r1);
  mr r30, r4;
  stw r29, 0x174(r1);
  mr r29, r3;
  mr r3, r30;
  bl DVDConvertPathToEntrynum;
  cmpwi r3, 0;
  bge lbl_800910c8;
  li r3, 0;
  b lbl_800911b0;
lbl_800910c8:
  addi r4, r29, 0x14c;
  bl DVDFastOpen;
  cmpwi r3, 0;
  bne lbl_800910e0;
  li r0, 0;
  b lbl_80091134;
lbl_800910e0:
  addi r0, r1, 0x27;
  li r3, 1;
  rlwinm r31, r0, 0, 0, 0x1a;
  stb r3, 0x188(r29);
  mr r4, r31;
  addi r3, r29, 0x14c;
  li r5, 0x40;
  li r6, 0;
  li r7, 2;
  bl DVDReadPrio;
  cmplwi r3, 0x40;
  beq lbl_80091118;
  li r0, 0;
  b lbl_80091134;
lbl_80091118:
  mr r4, r31;
  addi r3, r29, 0x108;
  bl SoundArchiveFileReader_Init;
  mr r3, r29;
  addi r4, r29, 0x108;
  bl unk_8009de90;
  li r0, 1;
lbl_80091134:
  cmpwi r0, 0;
  bne lbl_80091144;
  li r3, 0;
  b lbl_800911b0;
lbl_80091144:
  mr r3, r30;
  bl strlen;
  addic. r31, r3, -1;
  addi r0, r31, 1;
  add r3, r30, r31;
  mtctr r0;
  blt lbl_800911ac;
lbl_80091160:
  lbz r0, 0(r3);
  extsb r0, r0;
  cmpwi r0, 0x2f;
  beq lbl_80091178;
  cmpwi r0, 0x5c;
  bne lbl_800911a0;
lbl_80091178:
  mr r4, r30;
  mr r5, r31;
  addi r3, r1, 0x70;
  bl strncpy;
  addi r4, r1, 0x70;
  li r0, 0;
  stbx r0, r4, r31;
  mr r3, r29;
  bl unk_8009e610;
  b lbl_800911ac;
lbl_800911a0:
  addi r31, r31, -1;
  addi r3, r3, -1;
  bdnz lbl_80091160;
lbl_800911ac:
  li r3, 1;
lbl_800911b0:
  lwz r0, 0x184(r1);
  lwz r31, 0x17c(r1);
  lwz r30, 0x178(r1);
  lwz r29, 0x174(r1);
  mtlr r0;
  addi r1, r1, 0x180;
  blr;
  // clang-format on
}

// Symbol: Close__Q34nw4r3snd15DvdSoundArchiveFv
// PAL: 0x800911d0..0x80091210
void DvdSoundArchive::Close() {
  DVDClose(&mFileInfo);
  mOpenFlag = false;
  SoundArchive::Shutdown();
}

// Symbol: OpenStream__Q34nw4r3snd15DvdSoundArchiveFPviUlUl
// PAL: 0x80091210..0x800912c0
MARK_BINARY_BLOB(OpenStream__Q34nw4r3snd15DvdSoundArchiveFPviUlUl, 0x80091210,
                 0x800912c0);
asm void* DvdSoundArchive::OpenStream(void* buf, int size, u32 offset,
                                      u32 limit) const {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  mr r8, r3;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r7;
  stw r30, 0x18(r1);
  mr r30, r6;
  stw r29, 0x14(r1);
  mr r29, r4;
  lbz r0, 0x188(r3);
  cmpwi r0, 0;
  bne lbl_8009124c;
  li r3, 0;
  b lbl_8009129c;
lbl_8009124c:
  cmplwi r5, 0x78;
  bge lbl_8009125c;
  li r3, 0;
  b lbl_8009129c;
lbl_8009125c:
  cmpwi r4, 0;
  beq lbl_80091298;
  mr r3, r29;
  addi r4, r8, 0x14c;
  li r5, 0;
  bl __ct__Q34nw4r2ut19DvdLockedFileStreamFPC11DVDFileInfob;
  lis r4, 0x8027;
  stw r30, 0x70(r29);
  addi r4, r4, 0x42b0;
  mr r3, r29;
  stw r4, 0(r29);
  mr r4, r30;
  li r5, 0;
  stw r31, 0x74(r29);
  bl Seek__Q34nw4r2ut13DvdFileStreamFlUl;
lbl_80091298:
  mr r3, r29;
lbl_8009129c:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: OpenExtStream__Q34nw4r3snd15DvdSoundArchiveFPviPCcUlUl
// PAL: 0x800912c0..0x80091380
MARK_BINARY_BLOB(OpenExtStream__Q34nw4r3snd15DvdSoundArchiveFPviPCcUlUl,
                 0x800912c0, 0x80091380);
asm void* DvdSoundArchive::OpenExtStream(void* buf, int size, const char* path,
                                         u32 offset, u32 limit) const {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  lbz r0, 0x188(r3);
  stw r31, 0x1c(r1);
  mr r31, r8;
  cmpwi r0, 0;
  stw r30, 0x18(r1);
  mr r30, r7;
  stw r29, 0x14(r1);
  mr r29, r4;
  bne lbl_800912f8;
  li r3, 0;
  b lbl_8009135c;
lbl_800912f8:
  cmplwi r5, 0x78;
  bge lbl_80091308;
  li r3, 0;
  b lbl_8009135c;
lbl_80091308:
  mr r3, r6;
  bl DVDConvertPathToEntrynum;
  cmpwi r3, 0;
  mr r4, r3;
  bge lbl_80091324;
  li r3, 0;
  b lbl_8009135c;
lbl_80091324:
  cmpwi r29, 0;
  beq lbl_80091358;
  mr r3, r29;
  bl __ct__Q34nw4r2ut19DvdLockedFileStreamFl;
  lis r4, 0x8027;
  stw r30, 0x70(r29);
  addi r4, r4, 0x42b0;
  mr r3, r29;
  stw r4, 0(r29);
  mr r4, r30;
  li r5, 0;
  stw r31, 0x74(r29);
  bl Seek__Q34nw4r2ut13DvdFileStreamFlUl;
lbl_80091358:
  mr r3, r29;
lbl_8009135c:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: detail_GetRequiredStreamBufferSize__Q34nw4r3snd15DvdSoundArchiveFv
// PAL: 0x80091380..0x80091390
int DvdSoundArchive::detail_GetRequiredStreamBufferSize() const { return 0x78; }

// Symbol: LoadHeader__Q34nw4r3snd15DvdSoundArchiveFPvUl
// PAL: 0x80091390..0x80091420
MARK_BINARY_BLOB(LoadHeader__Q34nw4r3snd15DvdSoundArchiveFPvUl, 0x80091390,
                 0x80091420);
asm bool DvdSoundArchive::LoadHeader(void* buf, u32 size) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  lwz r31, 0x124(r3);
  lwz r6, 0x120(r3);
  cmplw r5, r31;
  bge lbl_800913c8;
  li r3, 0;
  b lbl_800913fc;
lbl_800913c8:
  mr r5, r31;
  li r7, 2;
  addi r3, r3, 0x14c;
  bl DVDReadPrio;
  cmplw r3, r31;
  beq lbl_800913e8;
  li r3, 0;
  b lbl_800913fc;
lbl_800913e8:
  mr r4, r30;
  mr r5, r31;
  addi r3, r29, 0x108;
  bl unk_8009e820;
  li r3, 1;
lbl_800913fc:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

} // namespace snd
} // namespace nw4r
