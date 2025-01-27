/*!
 * @file
 * @brief TODO
 */

#pragma once

#include <rk_types.h>
#include <egg/math/eggBoundBox.hpp>

#include <decomp.h>

namespace EGG {

// assumed names
class Viewport : public BoundBox2f {
public:
  Viewport();
  void set(int a, int b, int c, int d);
  void calculateAR();

  f32 m_width;       // _10
  f32 m_height;      // _14
  f32 m_aspectRatio; // _18
};

} // namespace EGG
