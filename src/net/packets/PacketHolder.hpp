#pragma once

#include <rk_types.h>

namespace Net {

template <typename T>
class PacketHolder {
public:
  PacketHolder(u32 bufferSize);
  ~PacketHolder();

  void reset();
  void copy(T *src, u32 len);
  void append(T *src, u32 len);

private:
  T *packet;
  u32 bufferSize;
  u32 packetSize;

};

}
