///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#pragma once

// GameSpy platform definition and headers

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// Include common OS headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include <limits.h>

// Raw sockets are undefined on Revolution
#define SB_NO_ICMP_SUPPORT

//---------- __cdecl fix for __fastcall conventions ----------
#define GS_STATIC_CALLBACK

//---------- Handle Endianess ----------------------
#define GSI_BIG_ENDIAN

#include <ctype.h>

#include <assert.h>
#define assert (void)

#define NOFILE 1
#define GSI_DOMAIN_NAME "gs.nintendowifi.net"

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// Define GameSpy types

// common base type defines, please refer to ranges below when porting
typedef char gsi_i8;
typedef unsigned char gsi_u8;
typedef short gsi_i16;
typedef unsigned short gsi_u16;
typedef int gsi_i32;
typedef unsigned int gsi_u32;
typedef unsigned int gsi_time; // must be 32 bits

// decprecated
typedef gsi_i32 goa_int32; // 2003.Oct.04.JED - typename deprecated
typedef gsi_u32
    goa_uint32; //  these types will be removed once all SDK's are updated

typedef int gsi_bool;
#define gsi_false ((gsi_bool)0)
#define gsi_true ((gsi_bool)1)
#define gsi_is_false(x) ((x) == gsi_false)
#define gsi_is_true(x) ((x) != gsi_false)

// Max integer size
#if defined(_INTEGRAL_MAX_BITS) && !defined(GSI_MAX_INTEGRAL_BITS)
#define GSI_MAX_INTEGRAL_BITS _INTEGRAL_MAX_BITS
#else
#define GSI_MAX_INTEGRAL_BITS 32
#endif

// Platform dependent types
typedef signed long long gsi_i64;
typedef unsigned long long gsi_u64;

#define gsi_char char

// expected ranges for integer types
#define GSI_MIN_I8 CHAR_MIN
#define GSI_MAX_I8 CHAR_MAX
#define GSI_MAX_U8 UCHAR_MAX

#define GSI_MIN_I16 SHRT_MIN
#define GSI_MAX_I16 SHRT_MAX
#define GSI_MAX_U16 USHRT_MAX

#define GSI_MIN_I32 INT_MIN
#define GSI_MAX_I32 INT_MAX
#define GSI_MAX_U32 UINT_MAX

#if (GSI_MAX_INTEGRAL_BITS >= 64)
#define GSI_MIN_I64 (-9223372036854775807 - 1)
#define GSI_MAX_I64 9223372036854775807
#define GSI_MAX_U64 0xffffffffffffffffui64
#endif

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// Common platform string functions
#undef _vftprintf
#undef _ftprintf
#undef _stprintf
#undef _tprintf
#undef _tcscpy
#undef _tcsncpy
#undef _tcscat
#undef _tcslen
#undef _tcschr
#undef _tcscmp
#undef _tfopen
#undef _T
#undef _tsnprintf

#define _T(a) a

#define _tsnprintf snprintf
#define _vftprintf vfprintf
#define _ftprintf fprintf
#define _stprintf sprintf
#define _tprintf printf
#define _tcscpy strcpy
#define _tcsncpy strncpy
#define _tcscat strcat
#define _tcslen strlen

char* _strlwr(char* string);
char* _strupr(char* string);

char* goastrdup(const char* src);
unsigned short* goawstrdup(const unsigned short* src);

// ------ Cross Plat Alignment macros ------------
/* ex use
PRE_ALIGN(16)	struct VECTOR
{
        float	x,y,z,_unused;
}	POST_ALIGN(16);

// another example when defining a variable:
PRE_ALIGN(16);
static char _mempool[MEMPOOL_SIZE]	POST_ALIGN(16);

*/
#define PRE_ALIGN(x) // not needed
#define POST_ALIGN(x) __attribute__((aligned(32)))

#define DIM(x) (sizeof(x) / sizeof((x)[0]))

unsigned char* gsiFloatSwap(unsigned char buf[4], float);
float gsiFloatUnswap(unsigned char buf[4]);
extern gsi_u16 gsiByteOrderSwap16(gsi_u16);
extern gsi_u32 gsiByteOrderSwap32(gsi_u32);
extern gsi_u64 gsiByteOrderSwap64(gsi_u64);

#ifdef __cplusplus
}
#endif

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
