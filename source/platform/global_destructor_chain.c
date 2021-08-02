#include "global_destructor_chain.h"

DestructorChain* __global_destructor_chain;

// Symbol: __register_global_object
// PAL: 0x80021338..0x80021350
void* __register_global_object(void* object, void* destructor, void* reg) {
  ((DestructorChain*)reg)->succ = __global_destructor_chain;
  ((DestructorChain*)reg)->destructor = destructor;
  ((DestructorChain*)reg)->object = object;
  __global_destructor_chain = (DestructorChain*)reg;
  return object;
}

// Symbol: __destroy_global_chain
// PAL: 0x80021350..0x80021398
void __destroy_global_chain(void) {
  DestructorChain* dtors;
  while ((dtors = __global_destructor_chain) != 0L) {
    __global_destructor_chain = dtors->succ;
    (((void (*)(void*, int))dtors->destructor)(dtors->object, -1));
  }
}

static DestructorChain atexit_funcs[64];
static long atexit_curr_func = 0;

// Symbol: __register_atexit
// PAL: 0x80021398..0x800213e4
int __register_atexit(void (*func)(void)) {
  if (atexit_curr_func == 64)
    return -1;
  __register_global_object(0, func, &atexit_funcs[atexit_curr_func++]);
  return 0;
}
