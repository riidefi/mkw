#pragma once

#ifndef SIZE_T_DEFINE
#define SIZE_T_DEFINE
typedef unsigned long size_t;
#endif

typedef unsigned short wchar_t;

size_t wcslen(const wchar_t*);

wchar_t* wcscpy(wchar_t*, const wchar_t*);

// PAL: 0x800179d0
wchar_t* wcsncpy(wchar_t* dest, const wchar_t* src, size_t n);

// PAL: 0x80017a14
int wcscmp(const wchar_t* s1, const wchar_t* s2);

#ifndef NULL
#define NULL 0
#endif
