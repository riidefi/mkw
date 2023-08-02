#include "eggViewport.hpp"

namespace EGG {

Viewport::Viewport() : m_width(0.0f), m_height(0.0f), m_aspectRatio(0.0f) {}

void Viewport::set(int a, int b, int c, int d) {
  min.x = a;
  min.y = b;
  max.x = c;
  max.y = d;
  calculateAR();
}

void Viewport::calculateAR() {
  m_width = max.x - min.x;
  m_height = max.y - min.y;
  m_aspectRatio = m_width / m_height;
}

} // namespace EGG
