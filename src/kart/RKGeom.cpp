#include "RKGeom.hpp"

namespace RKGeom {
void projUnit(EGG::Vector3f &dst, const EGG::Vector3f &v0, const EGG::Vector3f &v1) {
  f32 dot = v1.dot(v0);
  dst.x = v1.x * dot;
  dst.y = v1.y * dot;
  dst.z = v1.z * dot;
}

void rejUnit(EGG::Vector3f &dst, const EGG::Vector3f &v0, const EGG::Vector3f &v1) {
  f32 dot = v1.dot(v0);
  dst.x = v0.x - v1.x * dot;
  dst.y = v0.y - v1.y * dot;
  dst.z = v0.z - v1.z * dot;
}

void projAndRej(EGG::Vector3f &proj, EGG::Vector3f &rej, const EGG::Vector3f &v0, const EGG::Vector3f &v1) {
    projUnit(proj, v0, v1);
    rej.x = v0.x - proj.x;
    rej.y = v0.y - proj.y;
    rej.z = v0.z - proj.z;
}
}
