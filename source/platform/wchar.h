#pragma once

#include <rk_types.h>

typedef unsigned short wchar_t;

u32 wcslen( const wchar_t * );
u32 wcsnlen_s(const wchar_t *, u32 );

wchar_t *wcscpy( wchar_t *, const wchar_t * );
