#include "mtx.h"

double tan(double);

inline float tanf(float x) { return (float)tan(x); }

void C_MTXFrustum(Mtx44 m, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5,
                  f32 arg6) {
  f32 tmp = 1.0f / (arg4 - arg3);
  m[0][0] = (2 * arg5) * tmp;
  m[0][1] = 0.0f;
  m[0][2] = (arg4 + arg3) * tmp;
  m[0][3] = 0.0f;
  tmp = 1.0f / (arg1 - arg2);
  m[1][0] = 0.0f;
  m[1][1] = (2 * arg5) * tmp;
  m[1][2] = (arg1 + arg2) * tmp;
  m[1][3] = 0.0f;
  m[2][0] = 0.0f;
  m[2][1] = 0.0f;
  tmp = 1.0f / (arg6 - arg5);
  m[2][2] = -(arg5)*tmp;
  m[2][3] = -(arg6 * arg5) * tmp;
  m[3][0] = 0.0f;
  m[3][1] = 0.0f;
  m[3][2] = -1.0f;
  m[3][3] = 0.0f;
}

void C_MTXPerspective(Mtx44 m, f32 fovY, f32 aspect, f32 n, f32 f) {
  f32 angle = fovY * 0.5f;
  angle = ((angle)*0.01745329252f);
  f32 cot = 1.0f / tanf(angle);
  m[0][0] = cot / aspect;
  m[0][1] = 0.0f;
  m[0][2] = 0.0f;
  m[0][3] = 0.0f;
  m[1][0] = 0.0f;
  m[1][1] = cot;
  m[1][2] = 0.0f;
  m[1][3] = 0.0f;
  m[2][0] = 0.0f;
  m[2][1] = 0.0f;
  f32 tmp = 1.0f / (f - n);
  m[2][2] = -(n)*tmp;
  m[2][3] = -(f * n) * tmp;
  m[3][0] = 0.0f;
  m[3][1] = 0.0f;
  m[3][2] = -1.0f;
  m[3][3] = 0.0f;
}

void C_MTXOrtho(Mtx44 m, f32 a1, f32 a2, f32 a3, f32 a4, f32 a5, f32 a6) {
  f32 tmp = 1.0f / (a4 - a3);
  m[0][0] = 2.0f * tmp;
  m[0][1] = 0.0f;
  m[0][2] = 0.0f;
  m[0][3] = -(a4 + a3) * tmp;
  tmp = 1.0f / (a1 - a2);
  m[1][0] = 0.0f;
  m[1][1] = 2.0f * tmp;
  m[1][2] = 0.0f;
  m[1][3] = -(a1 + a2) * tmp;
  m[2][0] = 0.0f;
  m[2][1] = 0.0f;
  tmp = 1.0f / (a6 - a5);
  m[2][2] = -(1.0f) * tmp;
  m[2][3] = -(a6)*tmp;
  m[3][0] = 0.0f;
  m[3][1] = 0.0f;
  m[3][2] = 0.0f;
  m[3][3] = 1.0f;
}
