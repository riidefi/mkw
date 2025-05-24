#include "ParameterFile.hpp"
#include <Static/System/SystemManager.hpp>

#include <EGG/util/eggStream.hpp>

namespace System {

ParameterFile::ParameterFile(const char* path, u32 other) : mPath(path) {
  mTotalAllocated = 0;
  _18 = other;
  nw4r::ut::List_Init(&mStrings, offsetof(StringView, mNode));
}

ParameterFile::~ParameterFile() {
  StringView* str = nullptr;
  StringView* it = str;
  while ((str = nextString(it)) != nullptr) {
    it = str;
    delete str;
  }
}

void ParameterFile::appendData(char* str, u32 str_capacity, EGG::Heap* heap) {
  StringView* newStr = new (heap, 4) StringView;
  newStr->set(str, str_capacity);
  nw4r::ut::List_Append(&mStrings, newStr);
  mTotalAllocated += str_capacity;
}

void ParameterFile::read(EGG::Heap* heap) {
  if (*m_path == '\0') {
    // No path to load from
    return;
  }

  u32 fileSize;
  u8* data = SystemManager::ripFromDisc(m_path, heap, true, &fileSize);

  if (data == nullptr) {
    // Specified parameter file does not exist
    return;
  }

  EGG::Stream stream(data, fileSize);

  if (stream.read_u32() != 'RKPF' || stream.eof()) {
    // Identifier mismatch
    return;
  }

  if (stream.read_u32() < _18 || stream.eof()) {
    // ?
    return;
  }

  StringView* it = nullptr;
  while ((it = nextString(it)) != nullptr) {
    if (stream.eof())
      break;

    stream.readString(it->data(), it->size());
  }
}

} // namespace System
