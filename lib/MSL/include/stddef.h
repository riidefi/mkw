#pragma once

#define offsetof(type, m) ((size_t) & (((type*)0)->m))

#ifndef NULL
#define NULL 0
#endif

#ifndef SIZE_T_DEFINE
#define SIZE_T_DEFINE
typedef unsigned long size_t;
#endif
