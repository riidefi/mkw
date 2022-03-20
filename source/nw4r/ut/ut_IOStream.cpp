#include "ut_IOStream.hpp"

// Stolen from ogws.
// Credit: kiwi515
// Credit: GibHaltmannKill

namespace nw4r {
namespace ut {
int IOStream::Read(void*, u32) { return 0; }

bool IOStream::ReadAsync(void*, u32, AsyncFunctor, void*) { return false; }

s32 IOStream::Write(const void*, u32) { return 0; }

bool IOStream::WriteAsync(const void*, u32, AsyncFunctor, void*) {
  return false;
}

bool IOStream::IsBusy() const { return false; }

u32 IOStream::GetBufferAlign() const { return 1; }

u32 IOStream::GetSizeAlign() const { return 1; }

u32 IOStream::GetOffsetAlign() const { return 1; }

detail::RuntimeTypeInfo IOStream::typeInfo(NULL);
} // namespace ut
} // namespace nw4r
