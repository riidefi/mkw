/*!
 * @file
 * @brief TODO
 */

#pragma once

#include <egg/core/eggDisposer.hpp>
#include <egg/core/eggHeap.hpp>
#include <egg/eggInternal.hpp>
#include <nw4r/ut/utList.hpp>
#include <rk_types.h>
extern "C" {
#include <rvl/arc/rvlArchive.h>
}
extern "C" void memset(void*, int, u32);

namespace EGG {

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
  //! @details If the archive is already mounted, _14 of that archive will be
  //! incremented and a pointer to that archive will be returned.
  //! @returns A pointed to the mounted EGG Archive if successful. Otherwise,
  //! NULL.
  //!
  static Archive* mount(void* pArcStart, Heap* pHeap, int align);

  //! @brief Exact same as @see mount, except the status will be set such that
  //! fast get attemps fail.
  //!
  static Archive* mountNoFastGet(void* pArcStart, Heap* pHeap, int align);

  //! @brief Unmount an archive. (Set the status as NOT_LOADED and destroy self)
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

  struct LowArchive : public rvlArchive {
    inline void reset() { memset(this, 0, sizeof(*this)); }
    inline bool open(rvlArchiveEntryHandle path, rvlArchiveFile& file) {
      return ARCFastOpen(this, path, &file);
    }
    inline bool open(const char* path, rvlArchiveFile& file) {
      return ARCOpen(this, path, &file);
    }
  };

  Archive() {
    _14 = 1;
    mStatus = NOT_LOADED;
    mArcHandle.reset();
    if (!sIsArchiveListInitialized) {
      nw4r::ut::List_Init(&sArchiveList, 52);
      sIsArchiveListInitialized = true;
    }
    appendList(this);
  }
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

  u32 _08; // unseen
  u32 _0C; // unseen

  enum Status {
    NOT_LOADED,               //!< [0]
    LOADED_AND_CAN_FAST_READ, //!< [1]
    LOADED //!< [2] Just going by behavior, fast read can only proceed when set
           //!< to 1.
  };
  Status mStatus;        //!< [+0x10] set to 0 in ct
  int _14;               //!< [+0x14] set to 1 in ct; numMounts?
  LowArchive mArcHandle; // 0x18

  char _unk[8];
};

} // namespace EGG