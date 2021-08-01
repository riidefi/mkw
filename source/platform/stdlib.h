#pragma once

#include <rk_types.h>

// Compiler intrinsic functions.
#define abs(x) __abs(x)
#define labs(x) __labs(x)

long strtol(const char* restrict nptr, char** restrict endptr, int base);
unsigned long int strtoul(const char* str, char** endptr, int base);
unsigned long __strtoul(int, int, int (*)(void*, int, int), void*, int*, int*,
                        int*);

int atoi(const char* nptr);
long atol(const char* nptr);
long long atoll(const char* nptr);
long long atoq(const char* nptr);
double atof(const char* nptr);

void qsort(void* base, size_t nitems, size_t size,
           int (*compar)(const void*, const void*));

void srand(unsigned int seed);
int rand(void);
