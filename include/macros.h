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

// For VSCode
#ifdef __INTELLISENSE__
#define asm
#define __attribute__(x)
#define __declspec(x)
#endif

