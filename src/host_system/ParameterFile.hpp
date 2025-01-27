/*!
 * @file ParameterFile.hpp
 * @brief Contains reading code for an unused 'Parameter' file.
 */

#pragma once

#include <rk_types.h>
#include <egg/core/eggHeap.hpp>
#include <nw4r/ut/utList.hpp>

namespace System {

class ParameterFile {
public:
  ParameterFile(const char* path, u32 other);
  virtual ~ParameterFile();

  virtual void read(EGG::Heap* heap);
  s32 emptySub0();
  virtual void emptySub1();
  virtual void emptySub2();
  virtual void emptySub3();

  void appendData(char* str, u32 str_size, EGG::Heap* heap);

  template <typename T> void append(T& obj, EGG::Heap* heap) {
    appendData(reinterpret_cast<char*>(&obj), sizeof(obj), heap);
  }

private:
  class StringView {
  public:
    inline void set(char* begin, u32 size) {
      mData = begin;
      mSize = size;
    }

    inline const char* data() const { return mData; }
    inline char* data() { return mData; }
    inline u32 size() const { return mSize; }

    nw4r::ut::Node mNode;

  private:
    char* mData;
    u32 mSize;
  };

  inline StringView* nextString(StringView* string) {
    void* nextObj = nw4r::ut::List_GetNext(&mStrings, string);

    return reinterpret_cast<StringView*>(nextObj);
  }

  nw4r::ut::List mStrings; // 04
  u32 mTotalAllocated;     // 10
  const char* mPath;       // 14
  u32 _18;                 // 18
};

} // namespace System
