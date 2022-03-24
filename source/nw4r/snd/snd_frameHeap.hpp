#pragma once

// Source:
// https://github.com/kiwi515/ogws/blob/master/include/nw4r/snd/snd_FrameHeap.h
// Credit: kiwi515
// Credit: GibHaltmannKill

#include <nw4r/ut/utList.hpp>

namespace nw4r {
namespace snd {
namespace detail {

struct FrameHeap {
  u32 _unk00;
  ut::List _unk04;
};

} // namespace detail
} // namespace snd
} // namespace nw4r
