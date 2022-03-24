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
};

} // namespace EGG
