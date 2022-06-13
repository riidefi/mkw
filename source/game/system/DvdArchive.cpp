#include "DvdArchive.hpp"

// Extern function references.
// PAL: 0x805553b0
extern UNKNOWN_FUNCTION(unk_805553b0);

// ??????
__declspec(section ".rodata") int int_8088FAA0 = 0x4B000;

DvdArchive::DvdArchive() {
  mArchive = nullptr;
  mArchiveStart = nullptr;
  mArchiveSize = NULL;
  mArchiveHeap = nullptr;
  mFileStart = nullptr;
  mFileSize = NULL;
  mFileHeap = nullptr;
  mStatus = DVD_ARCHIVE_STATE_CLEARED;
}

DvdArchive::~DvdArchive() {
  if (mStatus == DVD_ARCHIVE_STATE_MOUNTED) {
    mArchive->unmount();
  }
  DvdArchive::clearArchive();
  DvdArchive::clearFile();
  mStatus = DVD_ARCHIVE_STATE_CLEARED;
}

// inline function that's been compiled
void DvdArchive::_mount(EGG::Heap* archiveHeap) {
  DvdArchive::mount(archiveHeap);
}

// haven't got a clue
void DvdArchive::_UNKNOWN() { return; }

void DvdArchive::load(char* path, EGG::Heap* archiveHeap, int decompress,
                      s32 param_5, EGG::Heap* fileHeap, u32 param_7) {
  if ((decompress == 0) || !fileHeap) {
    fileHeap = archiveHeap;
  }

  if (mStatus == DVD_ARCHIVE_STATE_CLEARED) {
    bool ripped = false;
    s32 allocDirection = 1;
    s8 cVar1 = -8;

    if (decompress == 0) {
      cVar1 = param_5;
    }
    if (cVar1 < 0) {
      allocDirection = 2;
    }

    mFileStart = DvdRipper_loadToMainRAM(path, 0, fileHeap, allocDirection, 0,
                                         0, &mFileSize);
    if ((mFileSize != 0) && mFileStart) {
      mFileHeap = fileHeap;
      ripped = true;
    } else {
      mFileSize = 0;
    }

    // ternary doesn't work here for some reason
    if (ripped) {
      mStatus = DVD_ARCHIVE_STATE_RIPPED;
    } else {
      mStatus = DVD_ARCHIVE_STATE_CLEARED;
    }
  }

  if (!(mStatus - 2) & ~0x2) {
    if (decompress != 0) {
      DvdArchive::decompress(path, archiveHeap, param_7);
      DvdArchive::clearFile();
    } else {
      DvdArchive::move();
    }
    DvdArchive::mount(archiveHeap);
  }

  return;
}

void DvdArchive::load(char* path, u32 param_2, EGG::Heap* archiveHeap) {
  DvdArchive::load(path, archiveHeap, 0, -8, 0, 0);
}

void DvdArchive::loadBuffer(void* fileStart, u32 fileSize,
                            EGG::Heap* archiveHeap, s32 param_4) {
  mFileStart = fileStart;
  mFileSize = fileSize;
  if (param_4 != 0) {
    DvdArchive::decompress("buffer_data", archiveHeap, 0);
    mFileStart = 0;
    mFileSize = 0;
    mFileHeap = 0;
  }
  DvdArchive::mount(archiveHeap);
}

void* DvdArchive::getFileCopy(char* filename, EGG::Heap* heap, size_t* size,
                              s8 param_4) {
  size_t local_18;
  void* file = DvdArchive::getFile(filename, &local_18);
  void* result = file;

  if (file) {
    void* __dest = heap->alloc(local_18, (int)param_4);
    memcpy(__dest, file, local_18);
    result = __dest;
    if (__dest && size) {
      *size = local_18;
    }
  }
  return result;
}

void DvdArchive::_UNKNOWN3(int, void* p) { delete[] p; }

// Symbol: SArchive_ripFile
// PAL: 0x805190f0..0x805191a4
MARK_BINARY_BLOB(SArchive_ripFile, 0x805190f0, 0x805191a4);
asm UNKNOWN_FUNCTION(SArchive_ripFile) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  extsb. r0, r6;
  li r6, 1;
  stw r31, 0x1c(r1);
  li r31, 0;
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r3;
  bge lbl_80519124;
  li r6, 2;
lbl_80519124:
  mr r3, r4;
  mr r5, r30;
  addi r9, r29, 0x18;
  li r4, 0;
  li r7, 0;
  li r8, 0;
  bl unk_805553b0;
  lwz r0, 0x18(r29);
  stw r3, 0x14(r29);
  cmpwi r0, 0;
  beq lbl_80519164;
  cmpwi r3, 0;
  beq lbl_80519164;
  stw r30, 0x1c(r29);
  li r31, 1;
  b lbl_8051916c;
lbl_80519164:
  li r0, 0;
  stw r0, 0x18(r29);
lbl_8051916c:
  cmpwi r31, 0;
  beq lbl_80519180;
  li r0, 2;
  stw r0, 0x20(r29);
  b lbl_80519188;
lbl_80519180:
  li r0, 0;
  stw r0, 0x20(r29);
lbl_80519188:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

bool DvdArchive::_tryRipFile(char* path, EGG::Heap* fileHeap, u8 param_3) {
  return DvdArchive::tryRipFile(path, fileHeap, param_3);
}

void DvdArchive::clear() {
  DvdArchive::clearArchive();
  DvdArchive::clearFile();
  return;
}

void DvdArchive::_UNKNOWN2() { return; }

void DvdArchive::unmount() {
  if (mStatus == DVD_ARCHIVE_STATE_MOUNTED) {
    mArchive->unmount();
  }
  DvdArchive::clearArchive();
  DvdArchive::clearFile();
  mStatus = DVD_ARCHIVE_STATE_CLEARED;
  return;
}

void DvdArchive::_clearArchive() {
  DvdArchive::clearArchive();
  return;
}

void DvdArchive::_clearFile() {
  DvdArchive::clearFile();
  return;
}

void* DvdArchive::getFile(char* filename, size_t* size) {
  void* result;
  int entryId;
  EGG::Archive::FileInfo fileInfo;
  char buffer[256];

  if (mStatus != DVD_ARCHIVE_STATE_MOUNTED) {
    return 0;
  }

  if (filename[0] == '/') {
    snprintf(buffer, sizeof(buffer), "%s", filename);
  } else {
    snprintf(buffer, sizeof(buffer), "/%s", filename);
  }
  buffer[255] = 0;

  fileInfo.startOffset = 0;
  fileInfo.length = 0;
  entryId = mArchive->convertPathToEntryID(buffer);
  result = nullptr;

  if (entryId != -1) {
    result = mArchive->getFileFast(entryId, &fileInfo);
    if (result && size) {
      *size = fileInfo.length;
    }
  }

  return result;
}

// Symbol: decompress__10DvdArchiveFPcPQ23EGG4HeapUl
// PAL: 0x80519508..0x805195a4
MARK_BINARY_BLOB(decompress__10DvdArchiveFPcPQ23EGG4HeapUl, 0x80519508,
                 0x805195a4);
asm UNKNOWN_FUNCTION(decompress__10DvdArchiveFPcPQ23EGG4HeapUl) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r5;
  stw r28, 0x10(r1);
  mr r28, r3;
  lwz r3, 0x14(r3);
  bl unk_805553b0;
  lwz r12, 0(r29);
  mr r31, r3;
  mr r3, r29;
  li r5, 0x20;
  lwz r12, 0x14(r12);
  mr r4, r31;
  mtctr r12;
  bctrl;
  mr r30, r3;
  lwz r3, 0x14(r28);
  mr r4, r30;
  bl unk_805553b0;
  stw r31, 0xc(r28);
  mr r3, r30;
  mr r4, r31;
  stw r30, 8(r28);
  stw r29, 0x10(r28);
  bl unk_805553b0;
  li r0, 3;
  stw r0, 0x20(r28);
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

void DvdArchive::_move() {
  DvdArchive::move();
  return;
}

// Symbol: SArchive_loadOther
// PAL: 0x805195d8..0x80519670
MARK_BINARY_BLOB(SArchive_loadOther, 0x805195d8, 0x80519670);
asm UNKNOWN_FUNCTION(SArchive_loadOther) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lwz r6, 0x20(r4);
  stw r0, 0x14(r1);
  addi r0, r6, -2;
  stw r31, 0xc(r1);
  cntlzw r0, r0;
  rlwinm. r0, r0, 0x1b, 5, 0x1f;
  mr r31, r5;
  stw r30, 8(r1);
  mr r30, r3;
  beq lbl_80519650;
  lwz r4, 0x14(r4);
  li r0, 2;
  stw r4, 0x14(r3);
  li r4, 0;
  li r6, 0;
  stw r0, 0x20(r3);
  bl decompress__10DvdArchiveFPcPQ23EGG4HeapUl;
  lwz r3, 8(r30);
  mr r4, r31;
  li r5, 4;
  bl unk_805553b0;
  li r0, 0;
  li r4, 4;
  stw r3, 4(r30);
  stw r4, 0x20(r30);
  stw r0, 0x14(r30);
  stw r0, 0x18(r30);
  b lbl_80519658;
lbl_80519650:
  li r0, 0;
  stw r0, 0x20(r3);
lbl_80519658:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}
