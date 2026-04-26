#include "USER.hpp"

#include "net/NetManager.hpp"

#include <string.h>

extern "C" {
void fn_1_152498(void*);
void fn_1_152B08(void*);
s32 RFLGetAsyncStatus();
}

namespace Net {

void USERHandler::update() {
  if (NetManager::getInstance()->hasFoundMatch()) {
    if (*(u8*)this == 0) {
      fn_1_152498(this);
    }
  } else {
    if (*(u8*)this != 0) {
      *(u8*)this = 0;
      *(u32*)((char*)this + 0x9e0) = 0;
      *(u32*)((char*)this + 0x9e4) = 0;
      *(u32*)((char*)this + 0x9e8) = 0;
      memset((char*)this + 0x8, 0, 0xc0);
      u32 i;
      char* p = (char*)this + 0xc8;
      for (i = 0; i < 0xc; i++) {
        memset(p, 0, 0xc0);
        p += 0xc0;
      }
    }
  }
  if (*(u8*)this != 0) {
    fn_1_152B08(this);
    if (*(s32*)((char*)this + 0x9dc) == 1) {
      if (RFLGetAsyncStatus() != 6) {
        *(u32*)((char*)this + 0x9e0) = *(u32*)((char*)this + 0x9e8);
        *(u32*)((char*)this + 0x9e8) = 0;
        *(u32*)((char*)this + 0x9dc) = 0;
      }
    }
  }
}

} // namespace Net
