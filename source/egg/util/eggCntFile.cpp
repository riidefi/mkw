#include <EGG/util/eggCntFile.hpp>

namespace EGG {

CntFile::CntFile() {}
CntFile::~CntFile() {}

bool CntFile::open() { return false; }

void CntFile::close() {
  if (!_04) {
    return;
  }

  bool returnVal = contentCloseNAND(&_3C);
  _4C = false;

  if (!returnVal) {
    _04 = false;
    nw4r::ut::List_Remove(&gCntFileList, this);
  }

  gCurrentCntFile = returnVal;
}

void CntFile::readData(void* fileBuffer, u32 length, s32 offset) {
  OSLockMutex(&_08);
  if (_9C) {
    OSUnlockMutex(&_08);
    return;
  }
  _9C = OSGetCurrentThread();

  const s32 readCode = contentReadNAND(&_3C, fileBuffer, length, offset);
  gCurrentCntFile = readCode == 0;
}

} // namespace EGG
