#include <egg/util/eggCntFile.hpp>

namespace EGG {

static nw4r::ut::List gCntFileList;
static int gCurrentCntFile;

#ifdef NON_MATCHING
CntFile::CntFile() : mOpen(false) { initThreading(); }
#else
extern "C" void initThreading__Q23EGG7CntFileFv(void*);
extern "C" asm void* __ct__Q23EGG7CntFileFv(void*) {
  stwu r1, -16(r1);
  mflr r0;
  lis r4, -32726;
  stw r0, 20(r1);
  li r0, 0;
  addi r4, r4, 10760;
  stw r31, 12(r1);
  mr r31, r3;
  stb r0, 4(r3);
  stw r4, 0(r3);
  bl initThreading__Q23EGG7CntFileFv;
  mr r3, r31;
  lwz r31, 12(r1);
  lwz r0, 20(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
}
#endif
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
  if (!this->mOpen && entry_num != -1) {
    int cnt_file = contentFastOpenNAND(cnt_handle, entry_num, &this->mFileHnd);
    if (!cnt_file) {
      this->mOpen = 1;
      nw4r::ut::List_Append(&gCntFileList, this);
      this->_4C = cnt_handle;
    } else {
      this->mOpen = 0;
      this->_4C = 0;
    }
    gCurrentCntFile = cnt_file;
  }
  return this->mOpen;
}

void CntFile::close() {
  if (!mOpen) {
    return;
  }

  int result = contentCloseNAND(&mFileHnd);
  _4C = false;

  if (!result) {
    mOpen = false;
    nw4r::ut::List_Remove(&gCntFileList, this);
  }

  gCurrentCntFile = result;
}

int CntFile::readData(void* fileBuffer, u32 length, s32 offset) {
  OSLockMutex(&_08);
  if (_9C) {
    OSUnlockMutex(&_08);
    return -1;
  }
  _9C = OSGetCurrentThread();

  const s32 result = contentReadNAND(&mFileHnd, fileBuffer, length, offset);
  // TODO: Pattern?
  gCurrentCntFile = (result >> 31) & result;

  _9C = 0;
  OSUnlockMutex(&_08);
  return result;
}

int CntFile::writeData(const void*, int, int) { return -1; }
int CntFile::open(const char*) { return 0; }
u32 CntFile::getFileSize() const { return CNTGetLength(&mFileHnd); }

} // namespace EGG
