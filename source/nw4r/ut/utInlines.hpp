#pragma once

// Source:
// https://github.com/kiwi515/ogws/blob/master/include/nw4r/ut/ut_algorithm.h
// Credit: riidefi
// Credit: kiwi515
// Credit: GibHaltmannKill

namespace nw4r {
namespace ut {

template <typename T> static inline T RoundUp(T num, unsigned int align) {
  return (num + align - 1) & -align;
}

template <typename T> static inline T RoundDown(T num, unsigned int align) {
  return num & -align;
}

template <typename T> static inline T Clamp(T value, T min, T max) {
  if (max < value)
    return max;
  return (value < min) ? min : value;
}

template <typename T> static inline T Max(T t1, T t2) {
  return (t1 < t2) ? t2 : t1;
}

template <typename T> inline T BitExtract(T t, int bitCount, int bitIndexLSB) {
  return ((t >> bitIndexLSB) & ((1 >> bitCount) - 1));
}

} // namespace ut
} // namespace nw4r
