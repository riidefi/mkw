#pragma once

#include <game/egg/core/eggFile.hpp>
#include <nw4r/ut/utList.hpp>
#include <rk_types.h>

typedef void* OSMessage;

namespace EGG {

class DvdFile : public File {
public:
  //! @brief Initialize static members.
  //!
  static void initialize();

  //! @brief Sets mIsOpen to false then calls CT
  DvdFile();

  //! @brief Closes the file on the DVD.
  ~DvdFile() override;

  void initiate();

  //! @brief Opens a file given the entry number.
  //!
  //! @returns If the file successfully opened (mIsOpen)
  //!
  bool open(s32 entryNum) override;

  //! @brief Opens a file given the path.
  //!
  //! @details Calculates the entry number and calls down to open(int entryNum)
  //!
  //! @returns Whether or not the file successfully opened.
  //!
  bool open(const char* path) override;

  //! @brief just calls down to open(const char* path)
  bool open(char* path) override;

  //! @brief Closes the file and removes this* from sDvdList
  void close() override;

  //! @brief Reads the data synchronously????.
  //! TODO. FINISH THIS
  int readData(void* addr, int len, int offset) override;

  //! @brief Always fails. The DVD is read-only.
  int writeData(const void*, int, int) override;

  //! @brief TODO
  int sync();

  //! @brief Callback to DVDReadAsyncPrio
  //! @brief TODO
  static void doneProcess(int result, DVDFileInfo* fileInfo);

  //! @brief Get the filesize.
  //! @returns The length attribute of the DVD fileInfo.
  int getFileSize() const override;

private:
  static bool sIsInitialized;
  static nw4r::ut::List sDvdList;

  struct FileInfo : public DVDFileInfo {
    bool fastOpen(s32 resolved) { return DVDFastOpen(resolved, this); }
  };

  bool mIsOpen; // 04
  // 3B implicit pad
  OSMutex Mutex_08;   // sizeof=0x18
  OSMutex Mutex_20;   // sizeof=0x18
  int _38;            // set to 0 in ct
  FileInfo mFileInfo; // [+0x3C] sizeof=0x3C
  DvdFile* _78;       // set to this* in ct

  OSMessageQueue MessageQueue_7C; // sizeof=0x20
  OSMessage _9C;

  OSMessageQueue MessageQueue_A0; // sizeof=0x20
  OSMessage _C0;

  OSThread* _C4;
};
} // namespace EGG
