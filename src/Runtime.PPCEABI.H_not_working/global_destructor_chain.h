#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct DestructorChain {
  struct DestructorChain* succ;
  void* destructor;
  void* object;
} DestructorChain;

// PAL: 0x80021338..0x80021350
void* __register_global_object(void* object, void* destructor,
                               void* registration);
// PAL: 0x80021350..0x80021398
void __destroy_global_chain(void);
// PAL: 0x80021398..0x800213e4
int __register_atexit(void (*)(void));

#ifdef __cplusplus
}
#endif
