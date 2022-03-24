#pragma once

// Source:
// https://github.com/kiwi515/ogws/blob/master/include/nw4r/ut/ut_IOStream.h
// Credit: GibHaltmannKill

#include <rk_types.h>

#include "ut_RTTI.hpp"

namespace nw4r {
namespace ut {
struct IOStream : Polymorphic {
public:
  typedef void (*AsyncFunctor)(s32, IOStream*, void*);

  inline virtual ~IOStream() {}

  virtual void Close() = 0;
  virtual int Read(void*, u32);
  virtual bool ReadAsync(void*, u32, AsyncFunctor, void*);
  virtual s32 Write(const void*, u32);
  virtual bool WriteAsync(const void*, u32, AsyncFunctor, void*);
  virtual bool IsBusy() const = 0;
  virtual bool CanAsync() const = 0;
  virtual bool CanRead() const = 0;
  virtual bool CanWrite() const = 0;
  virtual u32 GetOffsetAlign() const = 0;
  virtual u32 GetSizeAlign() const = 0;
  virtual u32 GetBufferAlign() const = 0;
  virtual u32 GetSize() const = 0;
  virtual void Seek(s32, u32) = 0;
  virtual void Cancel() = 0;
  virtual bool CancelAsync(AsyncFunctor, void*) = 0;
  virtual bool CanSeek() const = 0;
  virtual bool CanCancel() const = 0;
  virtual u32 Tell() const = 0;
  // virtual s32 Peek(void *, u32) = 0;
  // virtual bool PeekAsync(void *, u32, AsyncFunctor, void *) = 0;

protected:
  static detail::RuntimeTypeInfo typeInfo;
};
} // namespace ut
} // namespace nw4r
