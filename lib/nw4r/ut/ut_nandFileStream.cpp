#include "ut_nandFileStream.hpp"

#include <rvl/nand/nand.h>

#include <decomp.h>

// Source:
// https://github.com/kiwi515/ogws/blob/master/src/nw4r/ut/ut_NandFileStream.cpp
// Credit: GibHaltmannKill

namespace nw4r {
namespace ut {

void NandFileStream::NandAsyncCallback_(s32 r3, NANDCommandBlock* r4) {
  NANDCB_UNK* r4_2 = r4->PTR_0x144;

  r4_2->BYTE_0x16A = false;
  r4_2->WORD_0x8 = r3;
  if (!r4_2->CALLBACK_0xC)
    return;
  r4_2->CALLBACK_0xC(r3, r4_2, r4_2->WORD_0x10);
  return;
}

// PAL: 0x800b0ad0..0x800b0b40
NandFileStream::NandFileStream(const char* str, u32 num) : mPosition() {
  Initialize_();
  Open(str, num);
}

// PAL: 0x800b0b40..0x800b0bb0
NandFileStream::NandFileStream(const NANDFileInfo* fileInfo, u32 num, bool b)
    : mPosition() {
  Initialize_();
  Open(fileInfo, num, b);
}

// PAL: 0x800b0bb0..0x800b0c30
NandFileStream::~NandFileStream() {
  if (BYTE_0x167)
    this->Close();
}

// PAL: 0x800b0c30..0x800b0d20
bool NandFileStream::Open(const char* str, u32 num) {
  u32 fileSize; // at 0x8

  if (BYTE_0x167)
    this->Close();

  mReadFlag = num & 0x00000001;
  mWriteFlag = num & 0x00000002;

  if (NANDOpen(str, &mFileInfo, num))
    return false;

  if (mReadFlag) {
    if (NANDGetLength(&mFileInfo, &fileSize) != 0) {
      NANDClose(&mFileInfo);
      return false;
    }

    mPosition.SetFileSize(fileSize);
  }

  mPosition.Seek(0, 0);

  BYTE_0x167 = 1;
  BYTE_0x168 = 1;
  BOOL_0x4 = true;

  return true;
}


// bool NandFileStream::Open(const NANDFileInfo*, u32, bool)

// PAL: 0x800b14a0..0x800b14f0
void NandFileStream::Close() {
  if (BYTE_0x168 && BOOL_0x4) {
    NANDClose(&mFileInfo);
    BOOL_0x4 = false;
  }
}

// PAL: 0x800b14f0..0x800b1570
int NandFileStream::Read(void* buf, u32 size) {
  int ret;

  NANDSeek(&mFileInfo, mPosition.mFileOffset, 0);
  ret = NANDRead(&mFileInfo, buf, size);
  if (ret > 0)
    mPosition.Skip(ret);

  return ret;
}

// PAL: 0x800b1570..0x800b1620
bool NandFileStream::ReadAsync(void* buf, u32 size, AsyncFunctor async,
                               void* ptr) {
  bool ret;
  ASYNC_0xC = async;
  PTR_0x10 = ptr;
  mBusyFlag = true;
  NANDSeek(&mFileInfo, mPosition.mFileOffset, 0);
  ret = NANDReadAsync(&mFileInfo, buf, size, NandAsyncCallback_, UNK_0x1C) == 0;

  if (ret) {
    mPosition.Skip(size);
  } else {
    mBusyFlag = false;
  }

  return ret;
}

// PAL: 0x800b1620..0x800b16a0
s32 NandFileStream::Write(const void* buf, u32 size) {
  NANDSeek(&mFileInfo, mPosition.mFileOffset, 0);
  s32 num = NANDWrite(&mFileInfo, buf, size);
  if (num > 0) {
    mPosition.Append(num);
  }
  return num;
}

// PAL: 0x800b16a0..0x800b1750
bool NandFileStream::WriteAsync(const void* buf, u32 size, AsyncFunctor async,
                                void* ptr) {
  ASYNC_0xC = async;
  PTR_0x10 = ptr;
  mBusyFlag = true;
  NANDSeek(&mFileInfo, mPosition.mFileOffset, 0);

  s32 ret = NANDWriteAsync(&mFileInfo, buf, size, NandAsyncCallback_, UNK_0x1C);

  if (ret == 0) {
    mPosition.Append(size);
  } else {
    mBusyFlag = false;
  }

  return ret == 0;
}

// PAL: 0x800b1750..0x800b1758
void NandFileStream::Seek(s32 offset, u32 origin) {
  mPosition.Seek(offset, origin);
}

u32 NandFileStream::GetSize() const { return mPosition.mFileSize; }
u32 NandFileStream::Tell() const { return mPosition.mFileOffset; }

detail::RuntimeTypeInfo NandFileStream::typeInfo(&FileStream::typeInfo);

} // namespace ut
} // namespace nw4r
