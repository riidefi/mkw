#include "ROOM.hpp"

namespace Net {

void ROOMHandler::reset() {
  u8* self = (u8*)this;
  u8** new_var;
  *self = 0;
  *(u32*)(self + 0x08) = 0;
  *(u32*)(self + 0x38) = 0;
  *(u32*)(self + 0x0c) = 0;
  *(u32*)(self + 0x3c) = 0;
  *(u32*)(self + 0x10) = 0;
  *(u32*)(self + 0x40) = 0;
  *(u32*)(self + 0x14) = 0;
  *(u32*)(self + 0x44) = 0;
  *(u32*)(self + 0x18) = 0;
  *(u32*)(self + 0x48) = 0;
  *(u32*)(self + 0x1c) = 0;
  *(u32*)(self + 0x4c) = 0;
  *(u32*)(self + 0x20) = 0;
  *(u32*)(self + 0x50) = 0;
  *(u32*)(self + 0x24) = 0;
  *(u32*)(self + 0x54) = 0;
  *(u32*)(self + 0x28) = 0;
  *(u32*)(self + 0x58) = 0;
  *(u32*)(self + 0x2c) = 0;
  *(u32*)(self + 0x5c) = 0;
  *(u32*)(self + 0x30) = 0;
  *(u32*)(self + 0x60) = 0;
  *(u32*)(self + 0x34) = 0;
  *(u32*)(self + 0x64) = 0;
  self[0x68] = 0xff;
  *(u32*)((*(new_var = &self)) + 0x74) = 0;
  *(u32*)((*new_var) + 0x70) = 0;
  *(u32*)((*new_var) + 0x7c) = 0;
  if (!(*new_var)) {}
  *(u32*)((*new_var) + 0x78) = 0;
}

} // namespace Net
