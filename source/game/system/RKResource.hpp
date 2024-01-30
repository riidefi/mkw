
#pragma once

#include <rk_types.h>

// Very preliminary
namespace System {
class RKResource {
public:
    static bool resourceExists(u32 resId, const char*);
};

class DrawModel {
public:
  virtual ~DrawModel();	
};
}
