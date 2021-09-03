#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

MW_PRAG_NO_WARN_10216

f64 sin(f64);
inline f32 sinf(f32 x) { return (float)sin(x); }

f64 cos(f64);
inline f32 cosf(f32 x) { return (float)cos(x); }

f64 tan(f64);
inline f32 tanf(f32 x) { return (float)tan(x); }

f64 sqrt(f64);
inline f32 sqrtf(f32 x) { return (f32)sqrt(x); }

f64 acos(f64);
inline f32 acosf(f32 x) { return (f32)acos(x); }

double frexp(double x, int* eptr);
double ldexp(double x, int exp);

double pow(double x, double y);

double copysign(double x, double y);

int __fpclassifyf(float);
int __fpclassifyd(double);
int __signbitd(double);

MW_PRAG_END

#ifdef __cplusplus
} // extern "C"
#endif
