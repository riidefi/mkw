#pragma once

#include <nw4r/ut/utList.hpp>
#include <rk_types.h>
#include <rvl/cnt.h>
#include <rvl/os/osMessage.h>
#include <rvl/os/osMutex.h>
#include <rvl/os/osThread.h>

namespace EGG {

class CntFile {
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

  virtual int open(const char*);
  virtual void close();
  virtual int readData(void* fileBuffer, u32 length, s32 offset);
  virtual int writeData(const void*, int, int);
  virtual u32 getFileSize() const;

private:
  bool mOpen;
  char _p[3];
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
