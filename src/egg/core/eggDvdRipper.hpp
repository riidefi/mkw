/**
 * @file
 * @brief Headers for the EGG DVD ripper.
 */

#pragma once

#include <egg/core/eggDvdFile.hpp>
#include <egg/core/eggHeap.hpp>
#include <egg/core/eggStreamDecomp.hpp>

namespace EGG {

class DvdRipper {
public:
  class Arg {
  public:
    Arg();

  private:
    unk32 _00;
    unk32 _04;
    unk32 _08;
    unk32 _0c;
    unk32 _10;
    unk8* _14;
    unk8 _18[8];
  };

  typedef void (*DvdRipperCallback)(const Arg& arg);

private:
  static DvdRipperCallback sCallback;
  static bool sErrorRetry; //!< If true, the game will retry non-canceled
                           //!< DVDRead attempts.

public:
  //! @brief Describes the direction of allocating new blocks in a free memory
  //! region.
  //!
  enum EAllocDirection {
    ALLOC_DIR_PAD, // Unseen/unhandled so far
    ALLOC_DIR_TOP, //!< [1] Negative alignment; allocate block from top of free
                   //!< block.
    ALLOC_DIR_BOTTOM //!< [2] Positive alignment; allocate block from bottom of
                     //!< free block.
  };

  //! @brief Load a file on the disc to main RAM given the path.
  //!
  //! @param[in]        path            Path to the file on the disc.
  //! @param[in,out]    dst             Destination buffer to write file. If
  //! nullptr, an appropriately sized block of memory will be allocated.
  //! Otherwise the pre-allocated block MUST be big enough to store the file.
  //! @param[in]        heap            Heap to use if allocating a block.
  //! Cannot be nullptr if dst is also nullptr.
  //! @param[in]        allocDirection  Allocation direction of dst if it's
  //! nullptr.
  //! @param[in]        offset          Offset of the file on the disc to start
  //! reading from.
  //! @param[out]       amountRead      If not nullptr, will be set to the
  //! amount of bytes read from the disc.
  //! @param[out]       fileSize        If not nullptr, will be set to the file
  //! size of the file on disc (unrounded/offset).
  //!
  //! @returns Pointer to the ripped file, or nullptr in case of failure.
  //!
  static u8* loadToMainRAM(const char* path, u8* dst, Heap* heap,
                           EAllocDirection allocDirection, u32 offset,
                           u32* amountRead, u32* fileSize);

  //! @brief Load a file on the disc to main RAM given the DvdFile wrapper.
  //!
  //! @param[in]        dvdFile         Pointer to the DvdFile wrapper for the
  //! file on the disc.
  //! @param[in,out]    dst             Destination buffer to write file. If
  //! nullptr, an appropriately sized block of memory will be allocated.
  //! Otherwise the pre-allocated block MUST be big enough to store the file.
  //! @param[in]        heap            Heap to use if allocating a block.
  //! Cannot be nullptr if dst is also nullptr.
  //! @param[in]        allocDirection  Allocation direction of dst if it's
  //! nullptr.
  //! @param[in]        offset          Offset of the file on the disc to start
  //! reading from.
  //! @param[out]       amountRead      If not nullptr, will be set to the
  //! amount of bytes read from the disc.
  //! @param[out]       fileSize        If not nullptr, will be set to the file
  //! size of the file on disc (unrounded/offset).
  //!
  //! @returns Pointer to the ripped file, or nullptr in case of failure.
  //!
  static u8* loadToMainRAM(DvdFile* dvdFile, u8* dst, Heap* heap,
                           EAllocDirection allocDirection, u32 offset,
                           u32* amountRead, u32* fileSize);

  //! @brief Load and decompress a file on the disc to main RAM given the path.
  //!
  //! @param[in]        path            Path to the file on the disc.
  //! @param[in]        streamDecomp    Uninitialized decompressor.
  //! @param[in,out]    dst             Destination buffer to write file. If
  //! nullptr, an appropriately sized block of memory will be allocated.
  //! Otherwise the pre-allocated block MUST be big enough to store the
  //! DECOMPRESSED file.
  //! @param[in]        heap            Heap to use if allocating a block.
  //! Cannot be nullptr if dst is also nullptr.
  //! @param[in]        allocDirection  Allocation direction of dst if it's
  //! nullptr.
  //! @param[in]        offset          Offset of the file on the disc to start
  //! reading from.
  //! @param[in]        size            If non zero, size of the file to read.
  //! The sum of offset and size MUST NOT be larger than the compressed file
  //! size.
  //! @param[in]        maxChunkSize    The maximum size of the temporary buffer
  //! that will be allocated to read the compressed file.
  //!
  //! @returns Pointer to the ripped and decompressed file, or nullptr in case
  //! of failure.
  //!
  static u8* loadToMainRAMDecomp(const char* path, StreamDecomp* streamDecomp,
                                 u8* dst, Heap* heap,
                                 EAllocDirection allocDirection, u32 offset,
                                 u32 size, u32 maxChunkSize);

  //! @brief Load and decompress a file on the disc to main RAM given the
  //! DvdFile wrapper.
  //!
  //! @param[in]        dvdFile         Pointer to the DvdFile wrapper for the
  //! file on the disc.
  //! @param[in]        streamDecomp    Uninitialized decompressor.
  //! @param[in,out]    dst             Destination buffer to write file. If
  //! nullptr, an appropriately sized block of memory will be allocated.
  //! Otherwise the pre-allocated block MUST be big enough to store the
  //! DECOMPRESSED file.
  //! @param[in]        heap            Heap to use if allocating a block.
  //! Cannot be nullptr if dst is also nullptr.
  //! @param[in]        allocDirection  Allocation direction of dst if it's
  //! nullptr.
  //! @param[in]        offset          Offset of the file on the disc to start
  //! reading from.
  //! @param[in]        size            If non zero, size of the file to read.
  //! The sum of offset and size MUST NOT be larger than the compressed file
  //! size.
  //! @param[in]        maxChunkSize    The maximum size of the temporary buffer
  //! that will be allocated to read the compressed file.
  //!
  //! @returns Pointer to the ripped and decompressed file, or nullptr in case
  //! of failure.
  //!
  static u8* loadToMainRAMDecomp(DvdFile* dvdFile, StreamDecomp* streamDecomp,
                                 u8* dst, Heap* heap,
                                 EAllocDirection allocDirection, u32 offset,
                                 u32 size, u32 maxChunkSize);

private:
  DvdRipper() {}
};

} // namespace EGG
