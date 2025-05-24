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

u8* DvdRipper::loadToMainRAMDecomp(DvdFile* dvdFile, StreamDecomp* streamDecomp,
                                   u8* dst, Heap* heap,
                                   EAllocDirection allocDirection, u32 offset,
                                   u32 size, u32 maxChunkSize) {
  s32 uncompressedAlign, compressedAlign;
  bool allocatedFromHeap = false;

  // Setup aligns
  uncompressedAlign = allocDirection == ALLOC_DIR_TOP ? 32 : -32;
  compressedAlign = allocDirection == ALLOC_DIR_TOP ? -32 : 32;

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
  u32 uncompressedSize;
  if (result == static_cast<s32>(streamDecomp->getHeaderSize())) {
    // Get the size of the uncompressed data
    uncompressedSize = streamDecomp->getUncompressedSize(header);
  } else {
    // Memory leak in this case!
    return nullptr;
  }
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
  if (chunk != nullptr) {
    // Read and decompress the data
    u32 chunkOffset = 0;
    streamDecomp->init(dst, compressedSize);
    while (true) {
      u32 remainingSize = compressedSize - chunkOffset;
      u32 chunkSize =
          remainingSize < maxChunkSize ? remainingSize : maxChunkSize;

      s32 result = DVDRead(dvdFile->getFileInfo(), chunk,
                           ROUND_UP(chunkSize, 32), offset + chunkOffset);
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
  } else {
    if (allocatedFromHeap) {
      heap->free(dst);
    }
    return nullptr;
  }

  return dst;
}

} // namespace EGG
