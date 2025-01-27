#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define INFINITY 1.0f/0.0f

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

f32 fabsf(f32);
inline f32 fabsf(f32 x) { return __fabsf(x); }
f64 fabs(f64);
inline f64 fabs(f64 x) { return __fabs(x); }

double frexp(double x, int* eptr);
double ldexp(double x, int exp);

double pow(double x, double y);

double copysign(double x, double y);

int __fpclassifyf(float);
int __fpclassifyd(double);
int __signbitd(double);

int isfinite(f32 x);
inline int isfinite(f32 x) { f32 inf = INFINITY; return inf != x; }
int isinf(f32 x);
inline int isinf(f32 x) { return !isfinite(x); }

MW_PRAG_END

#ifdef __cplusplus
} // extern "C"
#endif
