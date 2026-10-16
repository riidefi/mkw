#include "fxReverbHi.h"

#include "fxReverbHiExp.h"

#include <rk_types.h>

int AXFXReverbHiExpInit(void* fx);

int AXFXReverbHiInit(void* fx) {
  u8* p = (u8*)fx;
  *(u32*)(p + 0x110) = 5;
  *(f32*)(p + 0x114) = *(f32*)(p + 0x158);
  *(f32*)(p + 0x118) = *(f32*)(p + 0x158);
  *(u32*)(p + 0x11c) = 0;
  *(f32*)(p + 0x120) = *(f32*)(p + 0x150);
  *(f32*)(p + 0x124) = *(f32*)(p + 0x148);
  *(f32*)(p + 0x128) = *(f32*)(p + 0x154);
  *(f32*)(p + 0x12c) = *(f32*)(p + 0x15c);
  *(f32*)(p + 0x130) = 0.0f;
  *(f32*)(p + 0x134) = 1.0f;
  *(u32*)(p + 0x138) = 0;
  *(u32*)(p + 0x13c) = 0;
  *(f32*)(p + 0x140) = *(f32*)(p + 0x14c);
  *(f32*)(p + 0x144) = 0.0f;
  return AXFXReverbHiExpInit(fx);
}

int AXFXReverbHiShutdown(void* fx) {
  AXFXReverbHiExpShutdown(fx);
  return 1;
}

void AXFXReverbHiCallback(void* fx) { AXFXReverbHiExpCallback(fx); }
