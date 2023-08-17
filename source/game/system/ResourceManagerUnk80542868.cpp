/**
 * This code is completely unused and unrefernced. It's just there to make the binary match.
*/

#include <rk_types.h>

class ResourceManager80542868 {
public:
  virtual s32 unk80542868(s32 a, s32 b);
  virtual s32 unk8054286c(s32 a, s32 b) = 0;
  virtual s32 unk80542870(s32 a, s32 b) = 0;
  virtual s32 unk80542874(s32 a, s32 b) = 0;
private:
  s32 a;
  s32 b;
};

extern const float arr_80890d10[];
const float arr_80890d10[] = {0.0, 1.0, 2.556854e-37f, 2.4979255e-37f};

s32 ResourceManager80542868::unk80542868(s32 a, s32 b) {
  this->a = a;
  this->b = b;
  return 1;
}
