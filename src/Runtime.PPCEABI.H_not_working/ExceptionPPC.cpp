#include "ExceptionPPC.h"
#include "rk_types.h"
#include <rvl/os/__ppc_eabi_init.h>

#define NUM_FRAGMENT 1

typedef struct FragmentInfo {
    const ExtabIndexInfo* eti; // at 0x0
    void* toc;                 // at 0x4
    BOOL regist;               // at 0x8
} FragmentInfo;

static FragmentInfo fragmentInfo[NUM_FRAGMENT];

int __register_fragment(const ExtabIndexInfo* eti, void* toc) {
    int i;
    FragmentInfo* frag;

    for (i = 0; i < NUM_FRAGMENT; i++) {
        frag = &fragmentInfo[i];

        if (!frag->regist) {
            frag->eti = eti;
            frag->toc = toc;
            frag->regist = TRUE;
            return 0;
        }
    }

    return -1;
}

void __unregister_fragment(int i) {
    FragmentInfo* frag;

    if (i != 0) {
        return;
    }

    frag = &fragmentInfo[i];
    frag->eti = NULL;
    frag->toc = NULL;
    frag->regist = FALSE;
}
