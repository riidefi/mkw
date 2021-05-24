#pragma once

namespace nw4r {
namespace ut {

template <typename T> static inline T RoundUp(T num, unsigned int align) {
  return (num + align - 1) & -align;
}

template <typename T> static inline T RoundDown(T num, unsigned int align) {
  return num & -align;
}

} // namespace ut
} // namespace nw4r