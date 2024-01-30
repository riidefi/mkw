
#pragma once

#include <rk_types.h>

namespace nw4r { namespace g3d {

struct ResDicData
{
  u32 size;
  u32  numData;
  struct ResDicNodeData
  {
    u16 ref;
    u16 flag;
    u16 idxLeft;
    u16 idxRight;
    s32 ofsString;
    s32 ofsData;
  }
  data[1]; // There are numData + 1 pieces of data
};

}} // nw4r::g3d
