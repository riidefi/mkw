#include "mtx.h"

double tan(double);

inline float tanf(float x) { return (float)tan(x); }

void C_MTXPerspective(Mtx44 m, f32 fovY, f32 aspect, f32 n, f32 f) {
  // force sdata2 order
  (void)1.0f;
  (void)2.0f;
  (void)0.0f;
  (void)-1.0f;
  (void)0.5f;
  (void)0.01745329252f;

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
