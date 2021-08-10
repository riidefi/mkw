#include <egg/core/eggDvdFile.hpp>

#include <cstddef>

namespace EGG {

bool DvdFile::sIsInitialized;
nw4r::ut::List DvdFile::sDvdList;

void DvdFile::initialize() {
  if (!sIsInitialized) {
    nw4r::ut::List_Init(&sDvdList, offsetof(DvdFile, mNode));
    sIsInitialized = true;
  }
}

DvdFile::DvdFile() { initiate(); }

DvdFile::~DvdFile() { close(); }

void DvdFile::initiate() {
  mFileInfo.dvdFile = this;
  OSInitMutex(&mMutex);
  OSInitMutex(&_20);
  OSInitMessageQueue(&mMsgQueue, &mMsg, 1);
  OSInitMessageQueue(&_7C, &_9C, 1);
  mThread = nullptr;
  _38 = 0;
}

bool DvdFile::open(s32 entryNum) {
  if (!mIsOpen && entryNum != -1) {
    mIsOpen = DVDFastOpen(entryNum, &mFileInfo);
    if (mIsOpen) {
      nw4r::ut::List_Append(&sDvdList, this);
      DVDGetFileInfoStatus(&mFileInfo);
    }
  }

  return mIsOpen;
}

bool DvdFile::open(const char* path) {
  s32 entrynum = DVDConvertPathToEntrynum(path);
  return open(entrynum);
}

bool DvdFile::open(const char* path, void*) { return open(path); }

void DvdFile::close() {
  if (mIsOpen && DVDClose(&mFileInfo)) {
    mIsOpen = false;
    nw4r::ut::List_Remove(&sDvdList, this);
  }
}

s32 DvdFile::readData(void* buffer, s32 length, s32 offset) {
  OSLockMutex(&mMutex);

  if (mThread != nullptr) {
    OSUnlockMutex(&mMutex);
    return -1;
  }

  mThread = OSGetCurrentThread();
  int result = -1;
  if (DVDReadAsyncPrio(&mFileInfo, buffer, length, offset, &doneProcess, 2)) {
    result = sync();
  }
  mThread = nullptr;

  OSUnlockMutex(&mMutex);
  return result;
}

s32 DvdFile::writeData(const void* buffer, s32 length, s32 offset) {
  UNUSED_PARAM(buffer)
  UNUSED_PARAM(length)
  UNUSED_PARAM(offset)

  return -1; // You can't write to the Dvd!
}

s32 DvdFile::sync() {
  OSLockMutex(&mMutex);

  OSMessage message;
  OSReceiveMessage(&mMsgQueue, &message, OS_MESSAGE_BLOCK);

  mThread = nullptr;

  OSUnlockMutex(&mMutex);

  s32 result = reinterpret_cast<s32>(message);
  return result;
}

void DvdFile::doneProcess(s32 result, DVDFileInfo* fileInfo) {
  DvdFile* dvdFile = static_cast<FileInfo*>(fileInfo)->dvdFile;
  OSMessage message = reinterpret_cast<void*>(result);
  OSSendMessage(&dvdFile->mMsgQueue, message, OS_MESSAGE_NOBLOCK);
}

u32 DvdFile::getFileSize() const { return mFileInfo.length; }

} // namespace EGG
