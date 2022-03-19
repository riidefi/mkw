#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <rk_types.h> // u32
#include <stdbool.h>  // bool

//! Describes the type of an entry in an archive.
//!
typedef enum rvlArchiveType {
  //! The entry is a file.
  //! Accessed via rvlArchiveFile with ARCOpen/ARCFastOpen
  //!
  RVL_ARCHIVE_FILE,

  //! The entry is a folder.
  //!
  RVL_ARCHIVE_FOLDER
} rvlArchiveType;

//! A unique integer handle.
//! Negative if the operation failed.
//! For use with rvlArchiveFileOpenLow.
//!
typedef s32 rvlArchiveEntryHandle;

//! Return if the handle returned by rvlArchiveResolve is valid.
//!
//! @note A handle may be plausibly valid,
//!       although not valid for a specific archive.
//!
#define rvlArchiveEntryHandleIsValid(handle) ((handle) >= 0)

//! Return if the handle is valid for a specific archive.
//!
#define rvlArchiveEntryHandleIsValidForArchive(handle, archive)                \
  ((handle) >= 0 && (handle) < archive->mCount)

//! A read-only view of an archive file.
//!
typedef struct rvlArchive {
  const struct rvlArchiveHeader* mHeader; //!< 00 Pointer to the archive header.
  const struct rvlArchiveNode*
      mNodes;           //!< 04 Array of nodes for each archive entry.
  const u8* mFileData;  //!< 08 File data buffer, accessed by nodes.
  u32 mCount;           //!< 0C Number of nodes in the archive.
  const char* mStrings; //!< 10 String buffer, accessed by nodes.
  u32 mFstSize;         //!< 14 Total bytesize of nodes and strings.
  u32 mCurrentPath;     //!< 18 The current directory of the archive.
} rvlArchive;

//! File info.
//!
typedef struct rvlArchiveFile {
  rvlArchive* parent; //!< 00 The archive the file is a part of.
  u32 offset;         //!< 04 Offset into the archive's file data buffer.
  u32 size;           //!< 08 Size of the file.
} rvlArchiveFile;

//! Info about a generic file or folder.
//! - If node_type is rvl_ARCHIVE_FILE, use rvlArchiveFileOpenLow to fill-in an
//!   rvlArchiveFile.
//! - If node_type is rvl_ARCHIVE_FOLDER, use rvlArchiveFolderOpen to fill-in an
//!   rvlArchiveFolderRange.
//!
typedef struct rvlArchiveEntry {
  rvlArchive* parent;       //!< 00 The archive the file is a part of.
  u32 path;                 //!< 04 Special ID corresponding to a file path.
                            //!< Accepted by rvlArchiveFileOpenLow.
  rvlArchiveType node_type; //!< The entry type.
  const char* name;         //!< 0C Name of this entry in specific.
                            //!< (Not an absolute path)
} rvlArchiveEntry;

//! Contains an iterable range of the recursive contents of a folder.
//!
typedef struct rvlArchiveFolderRange {
  rvlArchive* parent; //!< 00 The archive the file is a part of.
  u32 path_begin;     //!< 04 The lower bound of the iterator range.
  u32 path_it;        //!< 08 The current position of the iterator.
  u32 path_end;       //!< 0C The upper bound of the iterator range.
} rvlArchiveFolderRange;

//! @brief Open an archive from the specified U8 data.
//!
//! @param[in]  pData Pointer to the U8 data.
//! @param[out] pOut  Pointer to the archive to create.
//!
//! @return If the operation succeeded.
//!
bool ARCInitHandle(void* pData, rvlArchive* pOut);

//! @brief Resolve a string path to a unique integer
//!        for use with ARCFastOpen.
//!
//! @param[in] self The archive.
//! @param[in] path Null-terminated string path. Forward slashes must be used.
//!
//! @return A unique integer handle. Negative if the operation failed.
//!
rvlArchiveEntryHandle ARCConvertPathToEntrynum(rvlArchive* self,
                                               const char* path);

//! @brief Set the current path of the archive to a new root for future access.
//!        Similar to the "cd" command.
//!
//! @param[in] self The archive.
//! @param[in] path Null-terminated string path. Forward slashes must be used.
//!
//! @return If the operation succeeded.
//!
bool ARCChangeDir(rvlArchive* self, const char* path);

//! @brief Open a file handle from an archive.
//!
//! @param[in]  self The archive.
//! @param[in]  path Null-terminated string path. Forward slashes must be used.
//! @param[out] pOut Pointer to an rvlArchiveFile to fill in.
//!
//! @return If the operation succeeded.
//!
int ARCOpen(const rvlArchive* self, const char* path, rvlArchiveFile* pOut);

//! @brief Open a file handle from an archive.
//!
//! @param[in]  self The archive.
//! @param[in]  path Direct entry handle, from rvlArchiveResolve.
//! @param[out] pOut Pointer to an rvlArchiveFile to fill in.
//!
//! @return If the operation succeeded.
//!
int ARCFastOpen(const rvlArchive* self, rvlArchiveEntryHandle path,
                rvlArchiveFile* pOut);

//! @brief Get the file data from a file handle.
//!
//! @param[in] self Pointer to a file.
//!
//! @return A pointer to the beginning of the file data buffer.
//!
void* ARCGetStartAddrInMem(rvlArchiveFile* self);

//! @brief Get the address translation of an archive subfile.
//!
//! @param[in] self Pointer to a file.
//!
//! @return The number of bytes in the archive file until the subfile begins.
//!
s32 ARCGetStartOffset(const rvlArchiveFile* self);

//! @brief Get the filesize of a file handle.
//!
//! @param[in] self Pointer to a file.
//!
//! @return The size of the file data buffer, in bytes.
//!
u32 ARCGetLength(const rvlArchiveFile* self);

//! @brief Close a file handle.
//!
//! @param[in] self Pointer to a file.
//!
//! @return If the operation succeeded.
//!
bool ARCClose(rvlArchiveFile* self);

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
bool ARCOpenDir(const rvlArchive* self, const char* path,
                rvlArchiveFolderRange* pOut);

//! @brief Retrieve the next element in the iterator.
//!
//! @param[in]  self The folder range.
//! @param[out] pOut The archive entry to fill in.
//!
//! @return False if the iterator has been exhausted.
//!
bool ARCReadDir(rvlArchiveFolderRange* self, rvlArchiveEntry* pOut);

//! @brief Close the folder range handle.
//!
//! @param[in] self The folder range.
//!
//! @return If the operation succeeded.
//!
bool ARCCloseDir(rvlArchiveFolderRange* self);

#ifdef __cplusplus
}
#endif
