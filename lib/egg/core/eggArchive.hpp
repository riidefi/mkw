/*!
 * @file
 * @brief A read-only view of a "dolphin archive" .arc file.
 */

#pragma once

#include <rk_types.h>
#include <stddef.h>
#include <string.h>

#include <egg/core/eggDisposer.hpp>
#include <egg/core/eggHeap.hpp>
#include <egg/eggInternal.hpp>
#include <nw4r/ut/utList.hpp>
#include <rvl/arc/rvlArchive.h>

namespace EGG {

struct LowArchive : public rvlArchive {
  inline void reset() { memset(this, 0, sizeof(*this)); }
  inline bool open(rvlArchiveEntryHandle path, rvlArchiveFile& file) {
    return ARCFastOpen(this, path, &file);
  }
  inline bool open(const char* path, rvlArchiveFile& file) {
    return ARCOpen(this, path, &file);
  }
};

class Archive : public Disposer // sizeof=60,0x3C
{
public:
  struct FileInfo {
    u32 startOffset;
    u32 length;
  };

  //! Initialize the wrapped ARC handle from the start address pointer
  //! member.
  u32 initHandle(void* pArcStart) {
    // Here for now (since we don't have deadstripping)
    {
      EGG_ASSERT(pArcStart, "eggArchive.cpp", 61,
                 "arcBinary != NULL"); // from later inline
      return ARCInitHandle(pArcStart, &this->mArcHandle);
    }
  }

  //! @brief Find the EGG Archive wrapping the ARC file starting at pArchive.
  //! @remarks Always inlined.
  //!
  static Archive* findArchive(void* key) {
    // Here for now (since we don't have deadstripping)
    {
      Archive* found = NULL;
      if (isArchiveListInitialized()) {
        Archive* iterArchive = NULL;
        while ((iterArchive = (Archive*)nw4r::ut::List_GetNext(&sArchiveList,
                                                               iterArchive))) {
          if (iterArchive->mArcHandle.mHeader == key) {
            found = iterArchive;
            break;
          }
        }
      }
      return found;
    }
  }

  //! @brief Mount an archive.
  //! @details If the archive is already mounted, it will be used.
  //! @returns A pointed to the mounted EGG Archive if successful. Otherwise,
  //! NULL.
  //!
  static Archive* mount(void* pArcStart, Heap* pHeap, int align);

  //! @brief Exact same as @see mount, except the status will be set such that
  //! fast get attemps fail.
  //!
  static Archive* mountNoFastGet(void* pArcStart, Heap* pHeap, int align);

  //! @brief Unmount an archive. (Set the status as NOT_LOADED and decrease
  //! refcount)
  //!
  void unmount();

  //! @brief Convert the path to an ARC entry ID.
  int convertPathToEntryID(const char* path);
  void* getFileFast(int entryNum, FileInfo* pInfo);
  void getFile(const char* path, FileInfo* pInfo);
  // read arc file from disc
  static void* loadFromDisc(const char* path, Heap* pHeap, int align);

private:
  static bool sIsArchiveListInitialized;
  static nw4r::ut::List sArchiveList;

  static inline bool isArchiveListInitialized() {
    return sIsArchiveListInitialized;
  }

  Archive() {
    mRefCount = 1;
    mStatus = NOT_LOADED;
    mArcHandle.reset();
    if (!sIsArchiveListInitialized) {
      nw4r::ut::List_Init(&sArchiveList, offsetof(Archive, mLink));
      sIsArchiveListInitialized = true;
    }
    appendList(this);
  }
  inline Archive(const Archive&) {}
  virtual ~Archive() override; //!< [vt+0x00]

  //! @brief   Append an archive to the static archive list.
  //! @remarks Always inlined.
  //!
  static void appendList(Archive* pArchive) {
    nw4r::ut::List_Append(&sArchiveList, pArchive);
  }
  //! @brief Remove an archive to the static archive list.
  //!
  static void removeList(Archive* pArchive);

  enum Status {
    NOT_LOADED,               //!< [0]
    LOADED_AND_CAN_FAST_READ, //!< [1]
    LOADED //!< [2] Just going by behavior, fast read can only proceed when set
           //!< to 1.
  };
  Status mStatus;        //!< [+0x10] set to 0 in ct
  int mRefCount;         //!< [+0x14] set to 1 in ct
  LowArchive mArcHandle; // 0x18

  nw4r::ut::Node mLink;
};

} // namespace EGG
