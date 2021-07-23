#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

f64 sin(f64);
inline f32 sinf(f32 x) { return (float)sin(x); };

f64 cos(f64);
inline f32 cosf(f32 x) { return (float)cos(x); };

f64 tan(f64);
inline f32 tanf(f32 x) { return (float)tan(x); };

f64 sqrt(f64);
inline f32 sqrtf(f32 x) { return (f32)sqrt(x); }

f64 acos(f64);
inline f32 acosf(f32 x) { return (f32)acos(x); }

#ifdef __cplusplus
} // extern "C"
#endif
