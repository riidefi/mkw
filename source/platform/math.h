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

#ifdef __cplusplus
} // extern "C"
#endif
