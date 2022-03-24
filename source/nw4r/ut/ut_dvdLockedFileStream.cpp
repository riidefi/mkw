#include "ut_dvdLockedFileStream.hpp"

// Source:
// https://github.com/kiwi515/ogws/blob/master/src/nw4r/ut/ut_DvdLockedFileStream.cpp
// Credit: kiwi515

namespace nw4r {
namespace ut {

DvdLockedFileStream::DvdLockedFileStream(s32 id)
    : DvdFileStream(id), mCancelFlag(false) {
  InitMutex_();
}

DvdLockedFileStream::DvdLockedFileStream(const DVDFileInfo* file, bool b)
    : DvdFileStream(file, b), mCancelFlag(false) {
  InitMutex_();
}

DvdLockedFileStream::~DvdLockedFileStream() {}

void DvdLockedFileStream::Close(void) {
  DvdFileStream::Close();
  mCancelFlag = false;
}

int DvdLockedFileStream::Read(void* buffer, u32 count) {
  if (!LockMutex_()) {
    return -3;
  }
  int ret = this->DvdFileStream::Read(buffer, count);
  UnlockMutex_();
  return ret;
}

s32 DvdLockedFileStream::Peek(void* buffer, u32 count) {
  if (!LockMutex_()) {
    return -3;
  }
  s32 ret = this->DvdFileStream::Peek(buffer, count);
  UnlockMutex_();
  return ret;
}

void DvdLockedFileStream::Cancel() {
  CancelMutex_();
  DvdFileStream::Cancel();
}

detail::RuntimeTypeInfo DvdLockedFileStream::typeInfo(&DvdFileStream::typeInfo);

OSMutex DvdLockedFileStream::sMutex;
OSThreadQueue DvdLockedFileStream::sThreadQueue __attribute__((aligned(8)));
bool DvdLockedFileStream::sInitialized = false;

} // namespace ut
} // namespace nw4r
