#include "MultiDvdArchive.hpp"

extern "C" {
// PAL: 0x80518e10
extern UNKNOWN_FUNCTION(
    load__Q26System10DvdArchiveFPCcPQ23EGG4HeapilPQ23EGG4HeapUl);
// PAL: 0x80518fbc
extern UNKNOWN_FUNCTION(loadBuffer__Q26System10DvdArchiveFPvUlPQ23EGG4Heapl);
// PAL: 0x805190f0
extern UNKNOWN_FUNCTION(ripFile__Q26System10DvdArchiveFPCcPQ23EGG4HeapUc);
// PAL: 0x805553b0
extern UNKNOWN_FUNCTION(unk_805553b0);
}

#include <string.h>

#define SUFFIX_SIZE 128
extern const char*const SZS;

// Symbol: MultiDvdArchive_create
// PAL: 0x8052a098..0x8052a1c8
MARK_BINARY_BLOB(MultiDvdArchive_create, 0x8052a098, 0x8052a1c8);
asm UNKNOWN_FUNCTION(MultiDvdArchive_create) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  addi r0, r3, -3;
  cmplwi r0, 5;
  stw r31, 0xc(r1);
  li r31, 0;
  ble lbl_8052a0d4;
  cmpwi r3, 0;
  beq lbl_8052a0f4;
  cmpwi r3, 1;
  beq lbl_8052a134;
  cmpwi r3, 2;
  beq lbl_8052a174;
  b lbl_8052a1b0;
lbl_8052a0d4:
  li r3, 0x1c;
  bl unk_805553b0;
  cmpwi r3, 0;
  beq lbl_8052a0ec;
  li r4, 1;
  bl __ct__Q26System15MultiDvdArchiveFUs;
lbl_8052a0ec:
  mr r31, r3;
  b lbl_8052a1b0;
lbl_8052a0f4:
  li r3, 0x1c;
  bl unk_805553b0;
  cmpwi r3, 0;
  mr r31, r3;
  beq lbl_8052a1b0;
  li r4, 2;
  bl __ct__Q26System15MultiDvdArchiveFUs;
  lis r4, 0;
  mr r3, r31;
  addi r4, r4, 0;
  stw r4, 0(r31);
  lwz r12, 0(r31);
  lwz r12, 0xc(r12);
  mtctr r12;
  bctrl;
  b lbl_8052a1b0;
lbl_8052a134:
  li r3, 0x1c;
  bl unk_805553b0;
  cmpwi r3, 0;
  mr r31, r3;
  beq lbl_8052a1b0;
  li r4, 4;
  bl __ct__Q26System15MultiDvdArchiveFUs;
  lis r4, 0;
  mr r3, r31;
  addi r4, r4, 0;
  stw r4, 0(r31);
  lwz r12, 0(r31);
  lwz r12, 0xc(r12);
  mtctr r12;
  bctrl;
  b lbl_8052a1b0;
lbl_8052a174:
  li r3, 0x1c;
  bl unk_805553b0;
  cmpwi r3, 0;
  mr r31, r3;
  beq lbl_8052a1b0;
  li r4, 2;
  bl __ct__Q26System15MultiDvdArchiveFUs;
  lis r4, 0;
  mr r3, r31;
  addi r4, r4, 0;
  stw r4, 0(r31);
  lwz r12, 0(r31);
  lwz r12, 0xc(r12);
  mtctr r12;
  bctrl;
lbl_8052a1b0:
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_8052a1c8
// PAL: 0x8052a1c8..0x8052a21c
MARK_BINARY_BLOB(unk_8052a1c8, 0x8052a1c8, 0x8052a21c);
asm UNKNOWN_FUNCTION(unk_8052a1c8) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r4, 4;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl __ct__Q26System15MultiDvdArchiveFUs;
  lis r4, 0;
  mr r3, r31;
  addi r4, r4, 0;
  stw r4, 0(r31);
  lwz r12, 0(r31);
  lwz r12, 0xc(r12);
  mtctr r12;
  bctrl;
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: CourseMultiDvdArchive_init
// PAL: 0x8052a21c..0x8052a2a8
MARK_BINARY_BLOB(CourseMultiDvdArchive_init, 0x8052a21c, 0x8052a2a8);
asm UNKNOWN_FUNCTION(CourseMultiDvdArchive_init) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl init__Q26System15MultiDvdArchiveFv;
  lhz r0, 8(r31);
  lis r4, 0;
  addi r4, r4, 0;
  cmplwi r0, 1;
  ble lbl_8052a264;
  lwz r3, 0x18(r31);
  li r0, 0;
  li r5, 0x80;
  stw r0, 4(r3);
  lwz r3, 0x10(r31);
  lwz r3, 4(r3);
  bl unk_805553b0;
lbl_8052a264:
  lhz r0, 8(r31);
  cmplwi r0, 2;
  ble lbl_8052a27c;
  lwz r3, 0x18(r31);
  li r0, 4;
  stw r0, 8(r3);
lbl_8052a27c:
  lhz r0, 8(r31);
  cmplwi r0, 3;
  ble lbl_8052a294;
  lwz r3, 0x18(r31);
  li r0, 4;
  stw r0, 0xc(r3);
lbl_8052a294:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_8052a2a8
// PAL: 0x8052a2a8..0x8052a2fc
MARK_BINARY_BLOB(unk_8052a2a8, 0x8052a2a8, 0x8052a2fc);
asm UNKNOWN_FUNCTION(unk_8052a2a8) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r4, 2;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl __ct__Q26System15MultiDvdArchiveFUs;
  lis r4, 0;
  mr r3, r31;
  addi r4, r4, 0;
  stw r4, 0(r31);
  lwz r12, 0(r31);
  lwz r12, 0xc(r12);
  mtctr r12;
  bctrl;
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_8052a2fc
// PAL: 0x8052a2fc..0x8052a36c
MARK_BINARY_BLOB(unk_8052a2fc, 0x8052a2fc, 0x8052a36c);
asm UNKNOWN_FUNCTION(unk_8052a2fc) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl init__Q26System15MultiDvdArchiveFv;
  lis r3, 0;
  lhz r0, 8(r31);
  lwz r4, 0(r3);
  lis r3, 0;
  cmplwi r0, 1;
  lwz r0, 0x5c(r4);
  addi r3, r3, 0;
  slwi r0, r0, 2;
  lwzx r4, r3, r0;
  ble lbl_8052a358;
  lwz r3, 0x18(r31);
  li r0, 0;
  li r5, 0x80;
  stw r0, 4(r3);
  lwz r3, 0x10(r31);
  lwz r3, 4(r3);
  bl unk_805553b0;
lbl_8052a358:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_8052a36c
// PAL: 0x8052a36c..0x8052a3c0
MARK_BINARY_BLOB(unk_8052a36c, 0x8052a36c, 0x8052a3c0);
asm UNKNOWN_FUNCTION(unk_8052a36c) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r4, 2;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl __ct__Q26System15MultiDvdArchiveFUs;
  lis r4, 0;
  mr r3, r31;
  addi r4, r4, 0;
  stw r4, 0(r31);
  lwz r12, 0(r31);
  lwz r12, 0xc(r12);
  mtctr r12;
  bctrl;
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_8052a3c0
// PAL: 0x8052a3c0..0x8052a430
MARK_BINARY_BLOB(unk_8052a3c0, 0x8052a3c0, 0x8052a430);
asm UNKNOWN_FUNCTION(unk_8052a3c0) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl init__Q26System15MultiDvdArchiveFv;
  lis r3, 0;
  lhz r0, 8(r31);
  lwz r4, 0(r3);
  lis r3, 0;
  cmplwi r0, 1;
  lwz r0, 0x5c(r4);
  addi r3, r3, 0;
  slwi r0, r0, 2;
  lwzx r4, r3, r0;
  ble lbl_8052a41c;
  lwz r3, 0x18(r31);
  li r0, 0;
  li r5, 0x80;
  stw r0, 4(r3);
  lwz r3, 0x10(r31);
  lwz r3, 4(r3);
  bl unk_805553b0;
lbl_8052a41c:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_8052a430
// PAL: 0x8052a430..0x8052a488
MARK_BINARY_BLOB(unk_8052a430, 0x8052a430, 0x8052a488);
asm UNKNOWN_FUNCTION(unk_8052a430) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  beq lbl_8052a46c;
  li r4, 0;
  bl __dt__Q26System15MultiDvdArchiveFv;
  cmpwi r31, 0;
  ble lbl_8052a46c;
  mr r3, r30;
  bl unk_805553b0;
lbl_8052a46c:
  mr r3, r30;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_8052a488
// PAL: 0x8052a488..0x8052a4e0
MARK_BINARY_BLOB(unk_8052a488, 0x8052a488, 0x8052a4e0);
asm UNKNOWN_FUNCTION(unk_8052a488) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  beq lbl_8052a4c4;
  li r4, 0;
  bl __dt__Q26System15MultiDvdArchiveFv;
  cmpwi r31, 0;
  ble lbl_8052a4c4;
  mr r3, r30;
  bl unk_805553b0;
lbl_8052a4c4:
  mr r3, r30;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_8052a4e0
// PAL: 0x8052a4e0..0x8052a538
MARK_BINARY_BLOB(unk_8052a4e0, 0x8052a4e0, 0x8052a538);
asm UNKNOWN_FUNCTION(unk_8052a4e0) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  beq lbl_8052a51c;
  li r4, 0;
  bl __dt__Q26System15MultiDvdArchiveFv;
  cmpwi r31, 0;
  ble lbl_8052a51c;
  mr r3, r30;
  bl unk_805553b0;
lbl_8052a51c:
  mr r3, r30;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

namespace System {
MultiDvdArchive::MultiDvdArchive(u16 archiveCount) {
    this->archives = nullptr;
    this->archiveCount = archiveCount;
    this->suffixes = nullptr;

    this->archives = new DvdArchive[archiveCount];
    this->suffixes = (char**) new char*[archiveCount];
    this->fileStarts = (void **) new u32[archiveCount];
    this->kinds = new u32[archiveCount];
    this->fileSizes = new u32[archiveCount];

    for (u16 i = 0; i < this->archiveCount; i++) {
        this->suffixes[i] = new char[SUFFIX_SIZE];
        strncpy(this->suffixes[i],SZS, SUFFIX_SIZE);
        this->kinds[i] = 0;
        this->fileSizes[i] = 0;
        this->fileStarts[i] = nullptr;
    }
}

void MultiDvdArchive::init() {
    const char* suffix = SZS;
    for (unsigned short i = 0; i < this->archiveCount; i++) {
        // matches less for some reason if this unneccesary extra comparison is removed
        if (i < this->archiveCount) {
            this->kinds[i] = 0;
            strncpy(this->suffixes[i],suffix,128);
        }
    }
}

}

// Symbol: __dt__Q26System15MultiDvdArchiveFv
// PAL: 0x8052a6dc..0x8052a760
MARK_BINARY_BLOB(__dt__Q26System15MultiDvdArchiveFv, 0x8052a6dc, 0x8052a760);
asm UNKNOWN_FUNCTION(__dt__Q26System15MultiDvdArchiveFv) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  beq lbl_8052a744;
  lis r5, 0;
  lis r4, 0;
  addi r5, r5, 0;
  stw r5, 0(r3);
  lwz r3, 4(r3);
  addi r4, r4, 0;
  bl unk_805553b0;
  lwz r3, 0x10(r30);
  bl unk_805553b0;
  lwz r3, 0x18(r30);
  bl unk_805553b0;
  lwz r3, 0xc(r30);
  bl unk_805553b0;
  cmpwi r31, 0;
  ble lbl_8052a744;
  mr r3, r30;
  bl unk_805553b0;
lbl_8052a744:
  mr r3, r30;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

namespace System {
/*MultiDvdArchive::~MultiDvdArchive() {
    delete[] this->archives;
    delete[] this->suffixes;
    delete[] this->kinds;
    delete[] this->fileSizes;
}*/

void* MultiDvdArchive::getFile(const char* filename, size_t* size) {
    DvdArchive* archive;
    bool loaded;
    void *file = nullptr;

    for (int i = this->archiveCount - 1; i >= 0; i--) {
        loaded = false;
        archive = &this->archives[i];
        if ((archive->mStatus == DVD_ARCHIVE_STATE_MOUNTED) || (archive->mStatus == DVD_ARCHIVE_STATE_UNKN5)) {
            loaded = true;
        }
        if (loaded && ((file = archive->getFile(filename, size)) != NULL)) break;
    }

    return file;
}

bool MultiDvdArchive::isLoaded() {
    for (u16 i = 0; i < this->archiveCount; i++) {
        if (this->archives[i].isLoaded()) return true;
    }
    return false;
}
}

// Symbol: MultiDvdArchive_exists
// PAL: 0x8052a864..0x8052a954
MARK_BINARY_BLOB(MultiDvdArchive_exists, 0x8052a864, 0x8052a954);
asm UNKNOWN_FUNCTION(MultiDvdArchive_exists) {
  // clang-format off
  nofralloc;
  stwu r1, -0x120(r1);
  mflr r0;
  stw r0, 0x124(r1);
  stmw r27, 0x10c(r1);
  lis r30, 0;
  mr r27, r3;
  mr r28, r4;
  li r29, 0;
  addi r31, r30, 0;
  b lbl_8052a92c;
lbl_8052a88c:
  lwz r3, 0x18(r27);
  rlwinm r0, r29, 2, 0xe, 0x1d;
  lwzx r3, r3, r0;
  cmpwi r3, 0;
  beq lbl_8052a8b4;
  cmpwi r3, 1;
  beq lbl_8052a8d8;
  cmpwi r3, 2;
  beq lbl_8052a8f8;
  b lbl_8052a928;
lbl_8052a8b4:
  lwz r4, 0x10(r27);
  mr r6, r28;
  addi r3, r1, 8;
  addi r5, r30, 0;
  lwzx r7, r4, r0;
  li r4, 0x100;
  crclr 6;
  bl unk_805553b0;
  b lbl_8052a910;
lbl_8052a8d8:
  lwz r6, 0x10(r27);
  addi r3, r1, 8;
  addi r5, r31, 5;
  li r4, 0x100;
  lwzx r6, r6, r0;
  crclr 6;
  bl unk_805553b0;
  b lbl_8052a910;
lbl_8052a8f8:
  lwz r3, 0x14(r27);
  lwzx r0, r3, r0;
  cmpwi r0, 0;
  beq lbl_8052a910;
  li r3, 1;
  b lbl_8052a940;
lbl_8052a910:
  addi r3, r1, 8;
  bl unk_805553b0;
  cmpwi r3, -1;
  beq lbl_8052a928;
  li r3, 1;
  b lbl_8052a940;
lbl_8052a928:
  addi r29, r29, 1;
lbl_8052a92c:
  lhz r0, 8(r27);
  clrlwi r3, r29, 0x10;
  cmplw r3, r0;
  blt lbl_8052a88c;
  li r3, 0;
lbl_8052a940:
  lmw r27, 0x10c(r1);
  lwz r0, 0x124(r1);
  mtlr r0;
  addi r1, r1, 0x120;
  blr;
  // clang-format on
}

/*namespace System {
bool MultiDvdArchive::exists(const char* name) {
    char fullname[256];
    
    for (u16 i = 0; i < this->archiveCount; i++) {
        s32 kind = this->kinds[i];

        switch (kind) {
            case 0:
                snprintf(fullname, sizeof(fullname), "%s%s", name, this->suffixes[i]);
                break;
            case 1:
                snprintf(fullname, sizeof(fullname), "%s", this->suffixes[i]);
                break;
            case 2:
                if (this->fileStarts[i] != 0) {
                    return true;
                }
                break;
            default:
                continue;
        }
        // from RVL
        if (DVDConvertPathToEntrynum(fullname) != -1) {
            return true;
        }
    }
    return false;
}
}*/

// Symbol: MultiDvdArchive_load
// PAL: 0x8052a954..0x8052aa88
MARK_BINARY_BLOB(MultiDvdArchive_load, 0x8052a954, 0x8052aa88);
asm UNKNOWN_FUNCTION(MultiDvdArchive_load) {
  // clang-format off
  nofralloc;
  stwu r1, -0x130(r1);
  mflr r0;
  lis r8, 0;
  stw r0, 0x134(r1);
  stmw r23, 0x10c(r1);
  mr r25, r3;
  mr r26, r4;
  mr r27, r5;
  mr r28, r6;
  mr r29, r7;
  addi r31, r8, 0;
  li r30, 0;
  b lbl_8052aa64;
lbl_8052a988:
  lwz r3, 0x18(r25);
  rlwinm r24, r30, 2, 0xe, 0x1d;
  li r23, 1;
  lwzx r0, r3, r24;
  cmpwi r0, 0;
  beq lbl_8052a9b4;
  cmpwi r0, 1;
  beq lbl_8052a9d8;
  cmpwi r0, 2;
  beq lbl_8052a9f8;
  b lbl_8052aa60;
lbl_8052a9b4:
  lwz r4, 0x10(r25);
  mr r6, r26;
  addi r3, r1, 8;
  addi r5, r31, 8;
  lwzx r7, r4, r24;
  li r4, 0x100;
  crclr 6;
  bl unk_805553b0;
  b lbl_8052a9fc;
lbl_8052a9d8:
  lwz r6, 0x10(r25);
  addi r3, r1, 8;
  addi r5, r31, 0xd;
  li r4, 0x100;
  lwzx r6, r6, r24;
  crclr 6;
  bl unk_805553b0;
  b lbl_8052a9fc;
lbl_8052a9f8:
  li r23, 0;
lbl_8052a9fc:
  cmpwi r23, 0;
  beq lbl_8052aa34;
  clrlwi r0, r30, 0x10;
  lwz r3, 4(r25);
  mulli r0, r0, 0x24;
  mr r5, r27;
  mr r8, r28;
  mr r9, r29;
  add r3, r3, r0;
  addi r4, r1, 8;
  li r6, 1;
  li r7, 8;
  bl load__Q26System10DvdArchiveFPCcPQ23EGG4HeapilPQ23EGG4HeapUl;
  b lbl_8052aa60;
lbl_8052aa34:
  clrlwi r0, r30, 0x10;
  lwz r4, 0x14(r25);
  lwz r3, 0xc(r25);
  mulli r0, r0, 0x24;
  lwz r8, 4(r25);
  mr r6, r27;
  lwzx r5, r3, r24;
  li r7, 1;
  lwzx r4, r4, r24;
  add r3, r8, r0;
  bl loadBuffer__Q26System10DvdArchiveFPvUlPQ23EGG4Heapl;
lbl_8052aa60:
  addi r30, r30, 1;
lbl_8052aa64:
  lhz r0, 8(r25);
  clrlwi r3, r30, 0x10;
  cmplw r3, r0;
  blt lbl_8052a988;
  lmw r23, 0x10c(r1);
  lwz r0, 0x134(r1);
  mtlr r0;
  addi r1, r1, 0x130;
  blr;
  // clang-format on
}

namespace System {
/*void MultiDvdArchive::load(const char *filename, EGG::Heap* param_3, EGG::Heap *heap, unk32 param_5) {
    bool kindFile;
    char fullname[256];

    for (u16 i = 0; i < this->archiveCount; i++) {
        kindFile = true;
        s32 kind = this->kinds[i];

        switch (kind) {
            case 0:
                snprintf(fullname, sizeof(fullname), "%s%s", filename, this->suffixes[i]);
                break;
            case 1:
                snprintf(fullname, sizeof(fullname), "%s", this->suffixes[i]);
                break;
            case 2:
                kindFile = false;
                break;
            default:
                continue;

            }
        if (kindFile) {
            this->archives[i].load(fullname, param_3, 1, '\b', heap, param_5);
        } else {
            this->archives[i].loadBuffer(this->fileStarts[i], this->fileSizes[i], param_3, 1);
        }
    }
}*/

void MultiDvdArchive::unmount() {
    for (u16 i = 0; i < this->archiveCount; i++) {
        this->archives[i].unmount();
    }
}

void MultiDvdArchive::loadOther(MultiDvdArchive* other, EGG::Heap* heap) {
    for (u16 i = 0; i < this->archiveCount; i++) {
        this->archives[i].loadOther(&other->archives[i], heap);
    }

}

/*void MultiDvdArchive::rip(const char* name, EGG::Heap* heap) {
    char fullname[256];

    for (u16 i = 0; i < this->archiveCount; i++) {
        s32 kind = this->kinds[i];

        switch (kind) {
            case 0:
                snprintf(fullname, sizeof(fullname), "%s%s", name, this->suffixes[i]);
                break;
            case 1:
                snprintf(fullname, sizeof(fullname), "%s", this->suffixes[i]);
                break;
            default:
                continue;
        }
        this->archives[i].ripFile(fullname, heap, 8);
    }
    rip(name, heap);
}*/
}

// Symbol: unk_8052ab6c
// PAL: 0x8052ab6c..0x8052ac40
MARK_BINARY_BLOB(unk_8052ab6c, 0x8052ab6c, 0x8052ac40);
asm UNKNOWN_FUNCTION(unk_8052ab6c) {
  // clang-format off
  nofralloc;
  stwu r1, -0x120(r1);
  mflr r0;
  lis r6, 0;
  stw r0, 0x124(r1);
  stmw r27, 0x10c(r1);
  mr r27, r3;
  mr r28, r4;
  mr r29, r5;
  addi r31, r6, 0;
  li r30, 0;
  b lbl_8052ac1c;
lbl_8052ab98:
  lwz r3, 0x18(r27);
  rlwinm r0, r30, 2, 0xe, 0x1d;
  lwzx r3, r3, r0;
  cmpwi r3, 0;
  beq lbl_8052abb8;
  cmpwi r3, 1;
  beq lbl_8052abdc;
  b lbl_8052ac18;
lbl_8052abb8:
  lwz r4, 0x10(r27);
  mr r6, r28;
  addi r3, r1, 8;
  addi r5, r31, 0x10;
  lwzx r7, r4, r0;
  li r4, 0x100;
  crclr 6;
  bl unk_805553b0;
  b lbl_8052abf8;
lbl_8052abdc:
  lwz r6, 0x10(r27);
  addi r3, r1, 8;
  addi r5, r31, 0x15;
  li r4, 0x100;
  lwzx r6, r6, r0;
  crclr 6;
  bl unk_805553b0;
lbl_8052abf8:
  clrlwi r0, r30, 0x10;
  lwz r3, 4(r27);
  mulli r0, r0, 0x24;
  mr r5, r29;
  addi r4, r1, 8;
  li r6, 8;
  add r3, r3, r0;
  bl ripFile__Q26System10DvdArchiveFPCcPQ23EGG4HeapUc;
lbl_8052ac18:
  addi r30, r30, 1;
lbl_8052ac1c:
  lhz r0, 8(r27);
  clrlwi r3, r30, 0x10;
  cmplw r3, r0;
  blt lbl_8052ab98;
  lmw r27, 0x10c(r1);
  lwz r0, 0x124(r1);
  mtlr r0;
  addi r1, r1, 0x120;
  blr;
  // clang-format on
}

namespace System {
void MultiDvdArchive::clear() {
    for (u16 i = 0; i < this->archiveCount; i++) {
        this->archives[i].clear();
    }
}

int MultiDvdArchive::totalArchiveSize() {
    u32 sum = 0;
    DvdArchive* archive;

    for (u16 i = 0; i < this->archiveCount; i++) {
        archive = &this->archives[i];
        if (archive->isLoaded()) {
            sum += archive->mArchiveSize;
        }
    }

    return sum;
}

void* MultiDvdArchive::getEarliestResBufInMem() {
    void* ret = nullptr;
    for (u16 i = 0; i < this->archiveCount; i++) {
        DvdArchive* archive = &this->archives[i];
        
        if (archive->isLoaded()) {
            if (ret == nullptr || ret < archive->mArchiveStart) {
                ret = archive->mArchiveStart;
            }
        }
    }

    return ret;
}

void* MultiDvdArchive::getFarthestResBufInMem() {
    void* ret = nullptr;
    for (u16 i = 0; i < this->archiveCount; i++) {
        DvdArchive* archive = &this->archives[i];
        
        if (archive->isLoaded()) {
            if (ret == nullptr || ret > archive->getArchiveEnd()) {
                ret = archive->getArchiveEnd();
            }
        }
    }
    return ret;
}

u16 MultiDvdArchive::rippedArchiveCount() {
    u16 count = 0;

    for (u16 i = 0; i < this->archiveCount; i++) {
        if (this->archives[i].isRipped()) {
            count++;
        }
    }

    return count;
}

}
