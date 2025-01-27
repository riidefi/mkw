/*!
 * @file
 * @brief Implementation of File for NAND-Content files (read-only).
 */

#pragma once

#include <egg/core/eggFile.hpp>
#include <nw4r/ut/utList.hpp>
#include <rk_types.h>
#include <rvl/cnt.h>
#include <rvl/os/osMessage.h>
#include <rvl/os/osMutex.h>
#include <rvl/os/osThread.h>

namespace EGG {

class CntFile : public File {
public:
  CntFile();

private:
  inline CntFile(const CntFile&) {}

  // Name not final
  void initThreading();
  // Name not final
  bool spawnFileHandle(const char* path, void* cnt_handle);

public:
  virtual ~CntFile();

  bool open(const char* path) override;
  void close() override;
  s32 readData(void* buffer, s32 length, s32 offset) override;
  s32 writeData(const void* buffer, s32 length, s32 offset) override;
  u32 getFileSize() const override;

private:
  OSMutex _08;
  OSMutex _20;
  u32 _38;
  CNTFileInfoNAND mFileHnd;
  void* _4C;
  void* _50;

  OSMessageQueue _54;
  OSMessage _74;
  OSMessageQueue _78;
  OSMessage _98;
  OSThread* _9C;
};
} // namespace EGG
