/*!
 * @file
 * @brief Implementation of File for files on the DVD (read-only).
 */

#pragma once

#include <egg/core/eggFile.hpp>

#include <nw4r/ut/utList.hpp>

#include <rvl/os/osMessage.h>
#include <rvl/os/osMutex.h>
#include <rvl/os/osThread.h>
#include <rvl/dvd/dvd.h>

namespace EGG {

class DvdFile : public File {
public:
  //! @brief Initialize static members.
  static void initialize();

  //! @brief Sets mIsOpen to false then calls initiate.
  DvdFile();

private:
  inline DvdFile(const DvdFile&) {}

public:
  //! @brief Closes the file on the DVD.
  ~DvdFile() override;

  //! @brief Opens a file given the path.
  //!
  //! @details Calculates the entry number and calls down to open(int entryNum)
  //!
  //! @returns Whether or not the file successfully opened.
  bool open(const char* path) override;

  //! @brief Closes the file and removes this* from sDvdList.
  void close() override;

  //! @brief Reads the data synchronously.
  //!
  //! @returns The number of bytes read on success, -1 on error.
  s32 readData(void* buffer, s32 length, s32 offset) override;

  //! @brief Always fails. The DVD is read-only.
  //!
  //! @returns Always -1.
  s32 writeData(const void* buffer, s32 length, s32 offset) override;

  //! @brief Get the filesize.
  //!
  //! @returns The length attribute of the DVD fileInfo.
  u32 getFileSize() const override;

  //! @brief Opens a file given the entry number.
  //!
  //! @returns If the file successfully opened (mIsOpen).
  virtual bool open(s32 entrynum);

  //! @brief Just calls down to open(const char* path).
  //!
  //! @returns If the file successfully opened (mIsOpen).
  virtual bool open(const char* path, void*);

  inline DVDFileInfo* getFileInfo() { return &mFileInfo; }

private:
  void initiate();

  s32 sync();

  static void doneProcess(s32 result, DVDFileInfo* fileInfo);

  static bool sIsInitialized;
  static nw4r::ut::List sDvdList;

  struct FileInfo : public DVDFileInfo {
    DvdFile* dvdFile;
  };

  OSMutex mMutex;
  OSMutex _20; // unused
  unk32 _38;   // unused
  FileInfo mFileInfo;
  OSMessageQueue _7C; // unused
  OSMessage _9C;      // unused
  OSMessageQueue mMsgQueue;
  OSMessage mMsg;
  OSThread* mThread;
  nw4r::ut::Node mNode;
};

} // namespace EGG
