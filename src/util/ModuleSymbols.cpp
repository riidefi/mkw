
#ifdef __cplusplus
extern "C" {
#endif

#include <rvl/os/osError.h>
#include <rvl/os/osContext.h>

typedef void (*voidfunctionptr) (void); /* ptr to function returning void */
__declspec(section ".init") extern voidfunctionptr _ctors[];
__declspec(section ".init") extern voidfunctionptr _dtors[];

void _prolog(void);
void _epilog(void);
void _unresolved(void);

void rel_main(void);

void _prolog(void) {
  voidfunctionptr *constructor;

  /*
   *  call static initializers
   */
  for (constructor = _ctors; *constructor; constructor++) {
    (*constructor)();
  }
  rel_main();
}

void _epilog(void) {
  voidfunctionptr *destructor;

  /*
   *  call destructors
   */
  for (destructor = _dtors; *destructor; destructor++) {
    (*destructor)();
  }
}

void _unresolved(void) {
  OSReport("\nError: A called an unlinked function.\n");
  OSReport("Address:      Back Chain    LR Save\n");
  u32 i = 0;
  u32* sp = (u32*) OSGetStackPointer();
  while ((sp != nullptr) && (((s32)sp) != 0xffffffff) && (i++ < 0x10)) {
    OSReport("0x%08x:   0x%08x    0x%08x\n", sp, *sp , *(sp + 1));
    sp = (u32*)*sp;
  }
  OSReport("\n");
  return;
}

#ifdef __cplusplus
}
#endif
