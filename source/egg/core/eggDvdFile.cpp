#include <EGG/core/eggDvdFile.hpp>
#include <revolution/os.h>

namespace EGG {

bool DvdFile::sIsInitialized;
nw4r::ut::List DvdFile::sDvdList;

void DvdFile::initialize() {
  if (!sIsInitialized) {
    nw4r::ut::List_Init(&sDvdList, 200);
    sIsInitialized = true;
  }
}

DvdFile::DvdFile() : mIsOpen(false) { create(); }

DvdFile::~DvdFile() { close(); }

void DvdFile::initiate() {
  this->_78 = this;
  OSInitMutex(&this->Mutex_08);
  OSInitMutex(&this->Mutex_20);
  OSInitMessageQueue(&this->MessageQueue_A0, &this->_C0, 1);
  OSInitMessageQueue(&this->MessageQueue_7C, &this->_9C, 1);

  this->_C4 = 0;
  this->_38 = 0;
}


bool DvdFile::open(s32 entryNum) {
  if (!this->mIsOpen && entryNum != -1) {
    if (mFileInfo.open(entryNum)) {
      nw4r::ut::List_Append(&sDvdList, this);
      DVDGetCommandBlockStatus(&mFileInfo.cb);
    }
  }

  return mIsOpen;
}

bool DvdFile::open(const char* filename) {
  return this->open(DVDConvertPathToEntrynum(filename));
}

bool DvdFile::open(char* path) { return open((const char*)path); }

void DvdFile::close() {
  if (this->mIsOpen && DVDClose(&this->mFileInfo)) {
    this->mIsOpen = false;
    nw4r::ut::List_Remove(&sDvdList, this);
  }
}

int DvdFile::readData(void* addr, int len, int offset) {
  OSLockMutex(&this->Mutex_08);
  if (this->_C4 != 0) {
    OSUnlockMutex(&this->Mutex_08);
    return -1;
  }
  this->_C4 = OSGetCurrentThread();
  int r31 = (void*)-1;
	if (DVDReadAsyncPrio(&this->mFileInfo, addr, len, offset, (DVDCallback)&doneProcess, 2))
		r31 = this->sync();
  this->_C4 = 0;
  OSUnlockMutex(&this->Mutex_08);
  return r31;
}

int DvdFile::writeData(const void*, int, int) {
  return -1; // You can't write to the Dvd!
}

void DvdFile::sync() {
  OSLockMutex(&this->Mutex_08);

  OSMessage message;
  OSReceiveMessage(&this->MessageQueue_A0, &message, 1);

  _C4 = 0;

  OSUnlockMutex(&this->Mutex_08);

  return message;
}

void DvdFile::doneProcess(int result, DVDFileInfo* fileInfo) {
  OSSendMessage(&fileInfo->_3C->_A0, this, 0);
}

int DvdFile::getFileSize() const { return mFileInfo.length; }

} // namespace EGG
