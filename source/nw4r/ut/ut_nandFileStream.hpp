#pragma once

#include <rk_types.h>

#include <rvl/nand/nand.h>

#include "ut_IOStream.hpp"
#include "ut_fileStream.hpp"

// Stolen from ogws.
// Credit: kiwi515
// Credit: GibHaltmannKill

namespace nw4r {
namespace ut {
class NandFileStream : FileStream {

public:
  // PAL: 0x800b0ad0..0x800b0b40
  NandFileStream(const char*, u32);
  // PAL: 0x800b0b40..0x800b0bb0
  NandFileStream(const NANDFileInfo*, u32, bool);
  // PAL: 0x800b0bb0..0x800b0c30
  ~NandFileStream();

  // PAL: 0x800b0c30..0x800b0d20
  bool Open(const char*, u32);
  // PAL: 0x800b0d20..0x800b14a0
  bool Open(const NANDFileInfo*, u32, bool);
  // PAL: 0x800b14a0..0x800b14f0
  void Close();
  // PAL: 0x800b14f0..0x800b1570
  int Read(void*, u32);
  // PAL: 0x800b1570..0x800b1620
  bool ReadAsync(void*, u32, AsyncFunctor, void*);
  // PAL: 0x800b1620..0x800b16a0
  void Write(const void*, u32);
  // PAL: 0x800b16a0..0x800b1750
  bool WriteAsync(const void*, u32, AsyncFunctor, void*);
  // PAL: 0x800b1750..0x800b1758
  void Seek(s32, u32);

private:
  inline void Initialize_() {
    mReadFlag = false;
    mWriteFlag = false;
    BYTE_0x167 = false;
    BYTE_0x168 = false;
    BOOL_0x4 = false;
    mBusyFlag = false;
    ASYNC_0xC = NULL;
    PTR_0x10 = NULL;
    WORD_0x8 = 0;
    THIS_0x160 = this;
  }

private:
  FilePosition mPosition; // at 0x14
  char UNK_0x1C[0xB8];
  u32 pad;

  NANDFileInfo mFileInfo; // at 0xd4 (ends in 0x160)

  NandFileStream* THIS_0x160;

  char lolll[136];

  bool mReadFlag;  // at 0x164
  bool mWriteFlag; // at 0x165
  bool mBusyFlag;  // at 0x166
  bool BYTE_0x167; // at 0x167
  bool BYTE_0x168; // at 0x168
};

} // namespace ut
} // namespace nw4r