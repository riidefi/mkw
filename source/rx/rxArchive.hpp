#pragma once

#include <stdbool.h>  // bool
#include <rk_types.h> // u32

#ifdef __cplusplus
extern "C" {
#endif

//! Describes the type of an entry in an archive.
//!
typedef enum rxArchiveType {
  //! The entry is a file.
  //! Accessed via rxArchiveFile with rxArchiveFileOpen/rxArchiveFileOpenLow
  //!
  RX_ARCHIVE_FILE,

  //! The entry is a folder.
  //!
  RX_ARCHIVE_FOLDER
} rxArchiveType;

//! A unique integer handle.
//! Negative if the operation failed.
//! For use with rxArchiveFileOpenLow.
//!
typedef s32 rxEntryHandle;

//! Return if the handle returned by rxArchiveResolve is valid.
//!
//! @note A handle may be plausibly valid,
//!       although not valid for a specific archive.
//!
#define rxEntryHandleIsValid(handle) ((handle) >= 0)

//! Return if the handle is valid for a specific archive.
//!
#define rxEntryHandleIsValidForArchive(handle, archive)                        \
  ((handle) >= 0 && (handle) < archive->mCount)

//! A read-only view of an archive file.
//!
typedef struct rxArchive {
  const struct rxArchiveHeader* mHeader; //!< 00 Pointer to the archive header.
  const struct rxNode* mNodes; //!< 04 Array of nodes for each archive entry.
  const u8* mFileData;         //!< 08 File data buffer, accessed by nodes.
  u32 mCount;                  //!< 0C Number of nodes in the archive.
  const char* mStrings;        //!< 10 String buffer, accessed by nodes.
  u32 mFstSize;                //!< 14 Total bytesize of nodes and strings.
  u32 mCurrentPath;            //!< 18 The current directory of the archive.
} rxArchive;

//! File info.
//!
typedef struct rxArchiveFile {
  rxArchive* parent; //!< 00 The archive the file is a part of.
  u32 offset;        //!< 04 Offset into the archive's file data buffer.
  u32 size;          //!< 08 Size of the file.
} rxArchiveFile;

//! Info about a generic file or folder.
//! - If node_type is RX_ARCHIVE_FILE, use rxArchiveFileOpenLow to fill-in an
//!   rxArchiveFile.
//! - If node_type is RX_ARCHIVE_FOLDER, use rxArchiveFolderOpen to fill-in an
//!   rxArchiveFolderRange.
//!
typedef struct rxArchiveEntry {
  rxArchive* parent;       //!< 00 The archive the file is a part of.
  u32 path;                //!< 04 Special ID corresponding to a file path.
                           //!< Accepted by rxArchiveFileOpenLow.
  rxArchiveType node_type; //!< The entry type.
  const char* name;        //!< 0C Name of this entry in specific.
                           //!< (Not an absolute path)
} rxArchiveEntry;

//! Contains an iterable range of the recursive contents of a folder.
//!
typedef struct rxArchiveFolderRange {
  rxArchive* parent; //!< 00 The archive the file is a part of.
  u32 path_begin;    //!< 04 The lower bound of the iterator range.
  u32 path_it;       //!< 08 The current position of the iterator.
  u32 path_end;      //!< 0C The upper bound of the iterator range.
} rxArchiveFolderRange;

//! @brief Open an archive from the specified U8 data.
//!
//! @param[in]  pData Pointer to the U8 data.
//! @param[out] pOut  Pointer to the archive to create.
//!
//! @return If the operation succeeded.
//!
bool rxArchiveOpen(void* pData, rxArchive* pOut);

//! @brief Resolve a string path to a unique integer
//!        for use with rxArchiveFileOpenLow.
//!
//! @param[in] self The archive.
//! @param[in] path Null-terminated string path. Forward slashes must be used.
//!
//! @return A unique integer handle. Negative if the operation failed.
//!
rxEntryHandle rxArchiveResolve(rxArchive* self, const char* path);

//! @brief Set the current path of the archive to a new root for future access.
//!        Similar to the "cd" command.
//!
//! @param[in] self The archive.
//! @param[in] path Null-terminated string path. Forward slashes must be used.
//!
//! @return If the operation succeeded.
//!
bool rxArchiveSetCurrentPath(rxArchive* self, const char* path);

//! @brief Open a file handle from an archive.
//!
//! @param[in]  self The archive.
//! @param[in]  path Null-terminated string path. Forward slashes must be used.
//! @param[out] pOut Pointer to an rxArchiveFile to fill in.
//!
//! @return If the operation succeeded.
//!
bool rxArchiveFileOpen(const rxArchive* self, const char* path,
                       rxArchiveFile* pOut);

//! @brief Open a file handle from an archive.
//!
//! @param[in]  self The archive.
//! @param[in]  path Direct entry handle, from rxArchiveResolve.
//! @param[out] pOut Pointer to an rxArchiveFile to fill in.
//!
//! @return If the operation succeeded.
//!
bool rxArchiveFileOpenLow(const rxArchive* self, rxEntryHandle path,
                          rxArchiveFile* pOut);

//! @brief Get the file data from a file handle.
//!
//! @param[in] self Pointer to a file.
//!
//! @return A pointer to the beginning of the file data buffer.
//!
void* rxArchiveFileGetData(rxArchiveFile* self);

//! @brief Get the address translation of an archive subfile.
//!
//! @param[in] self Pointer to a file.
//!
//! @return The number of bytes in the archive file until the subfile begins.
//!
s32 rxArchiveFileGetOffset(const rxArchiveFile* self);

//! @brief Get the filesize of a file handle.
//!
//! @param[in] self Pointer to a file.
//!
//! @return The size of the file data buffer, in bytes.
//!
u32 rxArchiveFileGetSize(const rxArchiveFile* self);

//! @brief Close a file handle.
//!
//! @param[in] self Pointer to a file.
//!
//! @return If the operation succeeded.
//!
bool rxArchiveFileClose(rxArchiveFile* self);

//! @brief Get an iterable range of the recursive contents of a folder.
//!
//! @param[in]  self Pointer to an archive.
//! @param[in]  path Folder path.
//! @param[out] pOut A folder range to fill in.
//!
//! @return If the operation succeeded:
//!         - 1) The path exists and
//!         - 2) is not a file.
//!
bool rxArchiveFolderRangeOpen(const rxArchive* self, const char* path,
                              rxArchiveFolderRange* pOut);

//! @brief Retrieve the next element in the iterator.
//!
//! @param[in]  self The folder range.
//! @param[out] pOut The archive entry to fill in.
//!
//! @return False if the iterator has been exhausted.
//!
bool rxArchiveFolderRangeNext(rxArchiveFolderRange* self, rxArchiveEntry* pOut);

//! @brief Close the folder range handle.
//!
//! @param[in] self The folder range.
//!
//! @return If the operation succeeded.
//!
bool rxArchiveFolderRangeClose(rxArchiveFolderRange* self);

#ifdef GALAXY
inline s32 rxArchiveFileGetOffset(const rxArchiveFile* self) {
  return self->offset;
}
#endif // GALAXY

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

namespace rx {

template <typename T> class GenericEntry : private rxArchiveEntry {
public:
  bool isFile() const { return node_type == RX_ARCHIVE_FILE; }
  bool isFolder() const { return node_type == RX_ARCHIVE_FOLDER; }

  T* getParent() { return reinterpret_cast<T*>(parent); }
  const T* getParent() const { return reinterpret_cast<const T*>(parent); }
  u32 getPath() const { return path; }
  const char* getName() const { return name; }
};

namespace low {

//! Low-level archive wrapper. Directly maps to C functions.
//!
class Archive : private rxArchive {
public:
  bool open(const void* pData) {
    return rxArchiveOpen(const_cast<void*>(pData), this);
  }
  s32 resolve(const char* path) const {
    return rxArchiveResolve(const_cast<Archive*>(this), path);
  }
  bool setCurrentPath(const char* path) {
    return rxArchiveSetCurrentPath(path);
  }

  class File : private rxArchiveFile {
  public:
    bool open(const Archive* parent, const char* path) {
      return rxArchiveFileOpen(parent, path, this);
    }
    bool open(const Archive* parent, s32 path) {
      return rxArchiveFileOpenLow(parent, path, this);
    }
    void* getData() { return rxArchiveFileGetData(this); }
    const void* getData() const {
      return rxArchiveFileGetData(const_cast<File*>(this));
    }
    u32 getSize() const { return rxArchiveFileGetSize(this); }
    bool close() { return rxArchiveFileClose(this); }
  };

  class FolderRange : private rxArchiveFolderRange {
  public:
    bool open(const Archive* parent, const char* path) {
      rxArchiveFolderRangeOpen(parent, path, this);
    }
    bool next(GenericEntry<rx::low::Archive>& out) {
      rxArchiveFolderRangeNext(this, &out);
    }
    bool close() { return rxArchiveFolderRangeClose(this); }
  };
};
} // namespace low

//! High-level archive wrapper. Follows RAII principles.
//!
class Archive : private low::Archive {
public:
  Archive(const void* pData) { open(pData); }

  class File : public low::Archive::File {
  public:
    explicit File(const Archive* parent, const char* path) { open(path); }
    explicit File(const Archive* parent, s32 path) { open(path); }
    ~File() { close(); }
  };

  class FolderRange : private low::Archive::FolderRange {
    FolderRange(const Archive* parent, const char* path) { open(parent, path); }
    ~FolderRange() { close(); }
    bool next(GenericEntry<rx::Archive>& out) {
      return rx::low::Archive::FolderRange::next(
          reinterpret_cast<GenericEntry<rx::low::Archive&>>(out));
    }
  };
}

} // namespace rx

#endif // __cplusplus
