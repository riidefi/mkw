#pragma once

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

#define CLAMP(low, high, x)                                                    \
    ((x) > (high) ? (high) : ((x) < (low) ? (low) : (x)))

#define ROUND_UP(x, align) (((x) + (align) - 1) & (-(align)))
#define ROUND_UP_PTR(x, align)                                                 \
    ((void*)((((u32)(x)) + (align) - 1) & (~((align) - 1))))

#define ROUND_DOWN(x, align) ((x) & (-(align)))
#define ROUND_DOWN_PTR(x, align) ((void*)(((u32)(x)) & (~((align) - 1))))

#define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))

#define MEMCLR(x) __memclr((x), sizeof(*(x)))

#define ALIGN(x) __attribute__((aligned(x)))

#define DECL_SECTION(x) __declspec(section x)
#define DECL_WEAK __declspec(weak)

#define DECLTYPE(x) __decltype__(x)

#if defined(__INTELLISENSE__) || defined(__CLANGD__)
// TODO(KooShnoo): are we happy with this name?
#define __EDITOR_CHECKING__
#endif

#ifdef __CWCC__
// codewarrior-specific syntax
#define AT_ADDRESS(addr) : (addr)
#elif defined(__EDITOR_CHECKING__)
// dummy implementations for editor tooling
#define AT_ADDRESS(addr)
#define asm
#define __attribute__(x)
#define __declspec(x)
#else
// building with a non-codewarrior compiler is not supported yet
#error "workarounds for codewarrior's language extensions unimplemented"
#endif
