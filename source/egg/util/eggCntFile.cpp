#include <egg/util/eggCntFile.hpp>

namespace EGG {

static nw4r::ut::List gCntFileList;
static int gCurrentCntFile;

CntFile::CntFile() { initThreading(); }
CntFile::~CntFile() { close(); }

void CntFile::initThreading() {
  this->_50 = this;
  this->_4C = 0;
  OSInitMutex(&this->_08);
  OSInitMutex(&this->_20);
  OSInitMessageQueue(&this->_78, &this->_98, 1);
  OSInitMessageQueue(&this->_54, &this->_74, 1);
  this->_9C = 0;
  this->_38 = 0;
}

bool CntFile::spawnFileHandle(const char* path, void* cnt_handle) {
  int entry_num = CNTConvertPathToEntrynum(cnt_handle, path);
  if (!this->mIsOpen && entry_num != -1) {
    int cnt_file = contentFastOpenNAND(cnt_handle, entry_num, &this->mFileHnd);
    if (!cnt_file) {
      this->mIsOpen = 1;
      nw4r::ut::List_Append(&gCntFileList, this);
      this->_4C = cnt_handle;
    } else {
      this->mIsOpen = 0;
      this->_4C = 0;
    }
    gCurrentCntFile = cnt_file;
  }
  return this->mIsOpen;
}

void CntFile::close() {
  if (!mIsOpen) {
    return;
  }

  int result = contentCloseNAND(&mFileHnd);
  _4C = false;

  if (!result) {
    mIsOpen = false;
    nw4r::ut::List_Remove(&gCntFileList, this);
  }

  gCurrentCntFile = result;
}

s32 CntFile::readData(void* buffer, s32 length, s32 offset) {
  OSLockMutex(&_08);
  if (_9C) {
    OSUnlockMutex(&_08);
    return -1;
  }
  _9C = OSGetCurrentThread();

  const s32 result = contentReadNAND(&mFileHnd, buffer, length, offset);
  // TODO: Pattern?
  gCurrentCntFile = (result >> 31) & result;

  _9C = 0;
  OSUnlockMutex(&_08);
  return result;
}

s32 CntFile::writeData(const void*, s32, s32) { return -1; }
bool CntFile::open(const char*) { return false; }
u32 CntFile::getFileSize() const { return CNTGetLength(&mFileHnd); }

} // namespace EGG
