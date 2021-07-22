#pragma once

#include <rk_types.h>

typedef unsigned short wchar_t;

u32 wcslen(const wchar_t*);
u32 wcsnlen_s(const wchar_t*, u32);

wchar_t* wcscpy(wchar_t*, const wchar_t*);

// PAL: 0x800179d0
wchar_t* wcsncpy(wchar_t* dest, const wchar_t* src, size_t n);

// PAL: 0x80017a14
int wcscmp(const wchar_t* s1, const wchar_t* s2);
