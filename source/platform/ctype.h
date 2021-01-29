#pragma once

#ifndef MSL_CTYPE_H
#define MSL_CTYPE_H

#include "rk_types.h"

#ifdef __cplusplus
extern "C" {
#endif

struct __CMap {
	u8 _0[16];
	const u8* to_lower_table; // 10
	const u8* to_upper_table;
};
struct __Locale {
	u8 _[56];
	struct __CMap* cmap;
	u8 _1[0x44-56-4];
};
extern struct __Locale _current_locale;

#define case_table (&_current_locale)->cmap->to_lower_table
#define up_case_table (&_current_locale)->cmap->to_upper_table
static inline int tolower(int x) {
	return (x < 0 || x >= 256) ? x : (int)case_table[x];
}
static inline int toupper(int x) {
	return (x < 0 || x >= 256) ? x : (int)up_case_table[x];
}

#ifdef __cplusplus
} // extern "C"
#endif

#endif // MSL_CTYPE_H