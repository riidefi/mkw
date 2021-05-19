#pragma once

#include <Common/rk_types.h>
#include <nw4r/ut/list.h>
#include <revolution/cnt.h>
#include <revolution/os/OSMutex.h>

namespace EGG {

static nw4r::ut::List gCntFileList;
static BOOL gCurrentCntFile;

class CntFile {
public:
  CntFile();
  virtual ~CntFile();

  virtual bool open();                                             // 0
  virtual void close();                                            // 4
  virtual void readData(void* fileBuffer, u32 length, s32 offset); // 8

private:
  bool _04;            // 4
  OSMutex _08;         // 8
  unk32 _38;           // 38
  CNTFileInfoNAND _3C; // 3C
  char _40[0x10];      // 40
  unk32 _4C;           // 4C
  char _50[0x50];      // 50
  OSThread* _9C;       // 9C
};
} // namespace EGG
