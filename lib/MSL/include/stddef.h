#pragma once

#ifdef __clang__
#define offsetof(type, m) __builtin_offsetof(type,m)
#else
#define offsetof(type, m) ((size_t) & (((type*)0)->m))
#endif

#ifndef NULL
#define NULL 0
#endif

#ifndef SIZE_T_DEFINE
#define SIZE_T_DEFINE
typedef unsigned long size_t;
#endif
