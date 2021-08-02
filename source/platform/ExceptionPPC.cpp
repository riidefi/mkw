#include "ExceptionPPC.h"

typedef struct ProcessInfo {
  __eti_init_info* exception;
  char* TOC;
  int active;
} ProcessInfo;

static ProcessInfo fragmentinfo[1];

// Symbol: __register_fragment
// PAL: 0x80020dd8..0x80020e0c
int __register_fragment(struct __eti_init_info* info, char* TOC) {
  ProcessInfo* f;
  int i;
  for (i = 0, f = fragmentinfo; i < 1; ++i, ++f) {
    if (f->active == 0) {
      f->exception = info;
      f->TOC = TOC;
      f->active = 1;
      return i;
    }
  }
  return -1;
}

// Symbol: __unregister_fragment
// PAL: 0x80020e0c..0x80020e34
void __unregister_fragment(int fragmentID) {
  ProcessInfo* f;
  if (fragmentID >= 0 && fragmentID < 1) {
    f = &fragmentinfo[fragmentID];
    f->exception = 0;
    f->TOC = 0;
    f->active = 0;
  }
}
