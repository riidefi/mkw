#pragma once

// Source:
// https://github.com/kiwi515/ogws/blob/master/include/nw4r/ut/ut_ResFont.h
// Credit: GibHaltmannKill

#include <rk_types.h>

#include <decomp.h>

#include "ut_resFontBase.hpp"

namespace nw4r {
namespace ut {

struct BinaryFileHeader;

struct ResFont : detail::ResFontBase {
  ResFont();
  ~ResFont();

  bool SetResource(void*);
  static FontInformation* Rebuild(BinaryFileHeader*);
};
} // namespace ut
} // namespace nw4r
