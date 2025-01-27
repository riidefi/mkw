/*!
 * @file
 * @brief Base file class.
 */

#pragma once

#include <rk_types.h>

namespace EGG {

class File {
public:
  File() : mIsOpen(false) {}
  virtual ~File() {}
  virtual bool open(const char* path) = 0;
  virtual void close() = 0;
  virtual s32 readData(void* buffer, s32 length, s32 offset) = 0;
  virtual s32 writeData(const void* buffer, s32 length, s32 offset) = 0;
  virtual u32 getFileSize() const = 0;

  bool mIsOpen;

private:
  u8 pad[3];
};

} // namespace EGG
