#pragma once

namespace nw4r {
namespace math {
f32 FrSqrt(f32 x);

inline f32 FSqrt(f32 x) {
    return x <= 0.0f ? 0.0f : x * FrSqrt(x);
}
}
}
