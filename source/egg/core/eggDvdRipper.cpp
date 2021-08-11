/**
 * @file
 * @brief Implementations for the EGG DVD ripper.
 */

#include <egg/core/eggDvdRipper.hpp>

#include <rvl/os/osCache.h>
#include <rvl/vi.h>

namespace EGG {

DvdRipper::DvdRipperCallback DvdRipper::sCallback = nullptr;

bool DvdRipper::sErrorRetry = true;

u8* DvdRipper::loadToMainRAM(const char* path, u8* dst, Heap* heap,
                             EAllocDirection allocDirection, u32 offset,
                             u32* amountRead, u32* fileSize) {
  DvdFile dvdFile;
  if (!dvdFile.open(path)) {
    return nullptr;
  }

  return loadToMainRAM(&dvdFile, dst, heap, allocDirection, offset, amountRead,
                       fileSize);
}

inline DvdRipper::Arg::Arg() {
  _04 = 0;
  _08 = 0;
  _0c = 1;
  _10 = 0;
  _14 = _18;
}

u8* DvdRipper::loadToMainRAM(DvdFile* dvdFile, u8* dst, Heap* heap,
                             EAllocDirection allocDirection, u32 offset,
                             u32* amountRead, u32* fileSize) {
  u32 roundedFileSize, roundedFileSize2;
  bool allocatedFromHeap = false;

  if (sCallback != nullptr) {
    Arg arg;
    sCallback(arg);
  }

  u32 exactFileSize = dvdFile->getFileSize();
  if (fileSize != nullptr) {
    *fileSize = exactFileSize;
  }
  roundedFileSize = ROUND_UP(exactFileSize, 32);

  if (dst == nullptr) {
    s32 align = allocDirection == ALLOC_DIR_TOP ? 32 : -32;
    dst = Heap::alloc<u8>(roundedFileSize - offset, heap, align);
    allocatedFromHeap = true;
  }

  if (dst == nullptr) {
    return nullptr;
  }

  if (offset != 0) {
    u8 buf[64];
    u8* buf_ptr = (u8*)ROUND_UP(&buf, 32);
    while (true) {
      s32 result = DVDRead(dvdFile->getFileInfo(), buf_ptr, 32, offset);
      if (result >= 0) {
        break;
      }

      if (result == DVD_RESULT_CANCELED || !sErrorRetry) {
        if (allocatedFromHeap) {
          Heap::free(dst, nullptr);
        }
        return nullptr;
      }

      VIWaitForRetrace();
    }

    DCInvalidateRange(buf_ptr, 32);
  }

  roundedFileSize2 = roundedFileSize - offset;
  while (true) {
    s32 result = DVDRead(dvdFile->getFileInfo(), dst, roundedFileSize2, offset);
    if (result >= 0) {
      break;
    }

    if (result == DVD_RESULT_CANCELED || !sErrorRetry) {
      if (allocatedFromHeap) {
        Heap::free(dst, nullptr);
      }
      return nullptr;
    }

    VIWaitForRetrace();
  }

  if (amountRead) {
    *amountRead = roundedFileSize2;
  }

  return dst;
}

u8* DvdRipper::loadToMainRAMDecomp(const char* path, StreamDecomp* streamDecomp,
                                   u8* dst, Heap* heap,
                                   EAllocDirection allocDirection, u32 offset,
                                   u32 size, u32 maxChunkSize) {
  DvdFile dvdFile;
  if (!dvdFile.open(path)) {
    return nullptr;
  }

  return loadToMainRAMDecomp(&dvdFile, streamDecomp, dst, heap, allocDirection,
                             offset, size, maxChunkSize);
}

#ifdef NON_MATCHING
u8* DvdRipper::loadToMainRAMDecomp(DvdFile* dvdFile, StreamDecomp* streamDecomp,
                                   u8* dst, Heap* heap,
                                   EAllocDirection allocDirection, u32 offset,
                                   u32 size, u32 maxChunkSize) {
  bool allocatedFromHeap = false;

  // Setup aligns
  s32 uncompressedAlign = allocDirection == ALLOC_DIR_TOP ? 32 : -32;
  s32 compressedAlign = allocDirection == ALLOC_DIR_TOP ? -32 : 32;

  // Compute the compressed size to read from the file
  dvdFile->getFileSize(); // From debug print?
  u32 exactFileSize = dvdFile->getFileSize();
  u32 compressedSize = ROUND_UP(exactFileSize, 32) - offset;
  if (size != 0) {
    compressedSize = size;
  }

  // Allocate memory for the header
  void* header = heap->alloc(streamDecomp->getHeaderSize(), compressedAlign);
  if (header == nullptr) {
    return nullptr;
  }

  // Read the header
  s32 result = DVDRead(dvdFile->getFileInfo(), header,
                       streamDecomp->getHeaderSize(), offset);
  if (result != streamDecomp->getHeaderSize()) {
    // Memory leak in this case!
    return nullptr;
  }

  // Get the size of the uncompressed data
  u32 uncompressedSize = streamDecomp->getUncompressedSize(header);
  heap->free(header);

  // Allocate memory for the uncompressed data if necessary
  if (dst == nullptr) {
    dst = (u8*)heap->alloc(uncompressedSize, uncompressedAlign);
    allocatedFromHeap = true;
  }
  if (dst == nullptr) {
    return nullptr;
  }

  // Allocate memory for the compressed data
  void* chunk = heap->alloc(maxChunkSize, compressedAlign);
  if (chunk == nullptr) {
    if (allocatedFromHeap) {
      heap->free(dst);
    }
    return nullptr;
  }

  // Read and decompress the data
  u32 chunkOffset = 0;
  streamDecomp->init(dst, compressedSize);
  while (true) {
    u32 remainingSize = compressedSize - chunkOffset;
    u32 chunkSize = remainingSize < maxChunkSize ? remainingSize : maxChunkSize;

    s32 result = DVDRead(dvdFile->getFileInfo(), chunk, ROUND_UP(chunkSize, 32),
                         offset + chunkOffset);
    if (result < 0) {
      heap->free(chunk);
      if (allocatedFromHeap) {
        heap->free(dst);
      }
      return nullptr;
    }

    if (streamDecomp->decomp(chunk, result)) {
      break;
    }

    chunkOffset += result;
  }

  heap->free(chunk);
  return dst;
}
#else
MARK_BINARY_BLOB(
    loadToMainRAMDecomp__Q23EGG9DvdRipperFPQ23EGG7DvdFilePQ23EGG12StreamDecompPUcPQ23EGG4HeapQ33EGG9DvdRipper15EAllocDirectionUlUlUl,
    0x802229e8, 0x80222ccc);
asm u8* DvdRipper::loadToMainRAMDecomp(DvdFile* dvdFile,
                                       StreamDecomp* streamDecomp, u8* dst,
                                       Heap* heap,
                                       EAllocDirection allocDirection,
                                       u32 offset, u32 size, u32 maxChunkSize) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  mflr r0;
  cmpwi r7, 1;
  stw r0, 0x44(r1);
  stmw r20, 0x10(r1);
  mr r26, r3;
  mr r27, r4;
  mr r28, r5;
  mr r29, r6;
  mr r30, r8;
  mr r20, r9;
  mr r31, r10;
  li r22, 0;
  li r24, -32;
  bne lbl_80222a28;
  li r24, 0x20;
lbl_80222a28:
  cmpwi r7, 1;
  li r23, 0x20;
  bne lbl_80222a38;
  li r23, -32;
lbl_80222a38:
  lwz r12, 0(r26);
  mr r3, r26;
  lwz r12, 0x1c(r12);
  mtctr r12;
  bctrl;
  lwz r12, 0(r26);
  mr r3, r26;
  lwz r12, 0x1c(r12);
  mtctr r12;
  bctrl;
  addi r0, r3, 0x1f;
  cmpwi r20, 0;
  rlwinm r0, r0, 0, 0, 0x1a;
  subf r21, r30, r0;
  beq lbl_80222a78;
  mr r21, r20;
lbl_80222a78:
  lwz r12, 0(r27);
  mr r3, r27;
  lwz r12, 0x10(r12);
  mtctr r12;
  bctrl;
  lwz r12, 0(r29);
  mr r4, r3;
  mr r3, r29;
  mr r5, r23;
  lwz r12, 0x14(r12);
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  mr r20, r3;
  bne lbl_80222abc;
  li r3, 0;
  b lbl_80222cb8;
lbl_80222abc:
  lwz r12, 0(r27);
  mr r3, r27;
  lwz r12, 0x10(r12);
  mtctr r12;
  bctrl;
  mr r5, r3;
  mr r4, r20;
  mr r6, r30;
  addi r3, r26, 0x3c;
  li r7, 2;
  bl DVDReadPrio;
  lwz r12, 0(r27);
  mr r25, r3;
  mr r3, r27;
  lwz r12, 0x10(r12);
  mtctr r12;
  bctrl;
  cmpw r25, r3;
  bne lbl_80222b28;
  lwz r12, 0(r27);
  mr r3, r27;
  mr r4, r20;
  lwz r12, 0x14(r12);
  mtctr r12;
  bctrl;
  mr r25, r3;
  b lbl_80222b30;
lbl_80222b28:
  li r3, 0;
  b lbl_80222cb8;
lbl_80222b30:
  lwz r12, 0(r29);
  mr r3, r29;
  mr r4, r20;
  lwz r12, 0x18(r12);
  mtctr r12;
  bctrl;
  cmpwi r28, 0;
  bne lbl_80222b74;
  lwz r12, 0(r29);
  mr r3, r29;
  mr r4, r25;
  mr r5, r24;
  lwz r12, 0x14(r12);
  mtctr r12;
  bctrl;
  mr r28, r3;
  li r22, 1;
lbl_80222b74:
  cmpwi r28, 0;
  bne lbl_80222b84;
  li r3, 0;
  b lbl_80222cb8;
lbl_80222b84:
  lwz r12, 0(r29);
  mr r3, r29;
  mr r4, r31;
  mr r5, r23;
  lwz r12, 0x14(r12);
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  mr r20, r3;
  beq lbl_80222c8c;
  lwz r12, 0(r27);
  mr r3, r27;
  mr r4, r28;
  mr r5, r21;
  lwz r12, 8(r12);
  li r23, 0;
  mtctr r12;
  bctrl;
lbl_80222bcc:
  subf r5, r23, r21;
  mr r4, r20;
  cmplw r5, r31;
  addi r3, r26, 0x3c;
  blt lbl_80222be4;
  mr r5, r31;
lbl_80222be4:
  addi r0, r5, 0x1f;
  add r6, r30, r23;
  rlwinm r5, r0, 0, 0, 0x1a;
  li r7, 2;
  bl DVDReadPrio;
  cmpwi r3, 0;
  mr r24, r3;
  bge lbl_80222c44;
  lwz r12, 0(r29);
  mr r3, r29;
  mr r4, r20;
  lwz r12, 0x18(r12);
  mtctr r12;
  bctrl;
  cmpwi r22, 0;
  beq lbl_80222c3c;
  lwz r12, 0(r29);
  mr r3, r29;
  mr r4, r28;
  lwz r12, 0x18(r12);
  mtctr r12;
  bctrl;
lbl_80222c3c:
  li r3, 0;
  b lbl_80222cb8;
lbl_80222c44:
  lwz r12, 0(r27);
  mr r3, r27;
  mr r4, r20;
  mr r5, r24;
  lwz r12, 0xc(r12);
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  bne lbl_80222c70;
  add r23, r23, r24;
  b lbl_80222bcc;
lbl_80222c70:
  lwz r12, 0(r29);
  mr r3, r29;
  mr r4, r20;
  lwz r12, 0x18(r12);
  mtctr r12;
  bctrl;
  b lbl_80222cb4;
lbl_80222c8c:
  cmpwi r22, 0;
  beq lbl_80222cac;
  lwz r12, 0(r29);
  mr r3, r29;
  mr r4, r28;
  lwz r12, 0x18(r12);
  mtctr r12;
  bctrl;
lbl_80222cac:
  li r3, 0;
  b lbl_80222cb8;
lbl_80222cb4:
  mr r3, r28;
lbl_80222cb8:
  lmw r20, 0x10(r1);
  lwz r0, 0x44(r1);
  mtlr r0;
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}
#endif

} // namespace EGG
