#pragma once

#include <rk_types.h>

// Compiler intrinsic functions.
#define abs(x) __abs(x)
#define labs(x) __labs(x)

long long atoll(const char *);

void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
