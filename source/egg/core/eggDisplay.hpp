#pragma once

#include <rk_types.h>

#include <decomp.h>

namespace EGG {

class Display {
public:
  Display(unsigned char);

  void getTickPerFrame(void);
  void beginFrame(void);
  void j_endRender(void);
  void endFrame(void);
  void endRender(void);
  void calcFrequency(void);

public:
  unsigned char mFlag; // 0x00
  void * vtable; // 0x04
  unsigned char mMaxRetraces; // 0x08
  unsigned char mScreenStateFlag; // 0x09
};

} // namespace EGG
