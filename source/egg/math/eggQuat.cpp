/*!
 * @file
 * @brief TODO
 */

#include <egg/math/eggQuat.hpp>

namespace EGG {

void Quatf::set(float a, float b, float c, float d) {
  _[3] = a;
  _[0] = b;
  _[1] = c;
  _[2] = d;
}

} // namespace EGG
