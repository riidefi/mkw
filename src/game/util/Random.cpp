#include "Random.hpp"

#include <rvl/os/os.h>

namespace Util {

Random::Random() {
  mX = 0;
  mSeed = 0;
  reseed();
}

void Random::reseed() {
  u32 tick = OSGetTick();
  u32 seed = (tick & 0xfff) << 0x10 | tick >> 0x10;
  mX = seed;
  mSeed = seed;
}

Random::Random(u32 seed) {
  mX = seed;
  mSeed = seed;
}

Random::~Random() {}

u32 Random::nextU32() {
  mX = 7567025607324980273 * mX + 5279421;
  return mX >> 0x20;
}

u32 Random::nextU32(u32 range) {
  mX = 7567025607324980273 * mX + 5279421;
  return ((mX >> 0x20) * range) >> 0x20;
}

const f32 Random::mul = 2.3283064e-10f; // 1 / (2 ^ 32)

f32 Random::nextF32() { return Random::mul * nextU32(); }

f32 Random::nextF32(f32 range) { return range * nextF32(); }

} // namespace Util
