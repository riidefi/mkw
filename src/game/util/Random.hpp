#pragma once

#include <rk_types.h>

namespace Util {

class Random {
public:
  Random();

  void reseed();

  Random(u32 seed);

  virtual ~Random();

  u32 nextU32();

  u32 nextU32(u32 range);

  f32 nextF32();

  f32 nextF32(f32 range);

private:
  static const f32 mul;

  u64 mX;
  u64 mSeed;
};

} // namespace Util
