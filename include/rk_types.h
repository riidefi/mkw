#pragma once

#include <stdint.h>
#include <stddef.h>
#include <macros.h>

//! Describes an unknown 32 bit value
typedef int unk32;
//! Describes an unknown 16 bit value
typedef short unk16;
//! Describes an unknown 8 bit value
typedef unsigned char unk8;
//! Unknown value of unknown size
typedef unk32 unk;

// Necesary for CW
#if __cplusplus < 201103L && !defined(_WIN32)
#define override
#define noexcept
#define nullptr NULL
#endif

#define ensures(cond)
#define expects(cond)

#ifdef __CWCC__
#define MWREG register
#define CONST_MWREG register

#define WPOPT volatile
#define MW_PRAG_NOINLINE _Pragma("push") _Pragma("dont_inline on")
#define MW_PRAG_OPT_S _Pragma("push") _Pragma("optimize_for_size on")
#define MW_PRAG_NO_WARN_10216 _Pragma("push") _Pragma("warning off(10216)")
#define MW_PRAG_PACKED _Pragma("push") _Pragma("options align=packed")

#define MW_PRAG_END _Pragma("pop")
#define DECOMP // TODO: Move to build

#define FORCE_INLINE __inline
#define NEVER_INLINE __attribute__((never_inline))

#else
#define MWREG
#define CONST_MWREG const
#define MW_PRAG_NOINLINE
#define MW_PRAG_END
#define MW_PRAG_OPT_S
#define MW_PRAG_PACKED
#define MW_PRAG_NO_WARN_10216

#define FORCE_INLINE __forceinline
#define NEVER_INLINE
#endif

// A function that does nothing
#define NULLSUB void

// We know it's release stripped usually from context. i.e. allocated on debug
// heap
#define RELEASE_STRIPPED_ALL NULLSUB

#define UNUSED_PARAM(x) (void)(x); // EPPC:#pragma unused
#define UNUSED

#ifdef DECOMP

#define LOCALREF(key, type, data, ref) extern type key;
#else
#define LINKED_ELSEWHERE

#define LOCALREF(key, type, data, ref) type key = data;
#endif

// Standard types
typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef volatile u8 vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;
typedef volatile s8 vs8;
typedef volatile s16 vs16;
typedef volatile s32 vs32;
typedef volatile s64 vs64;

typedef float f32;
typedef double f64;
typedef volatile f32 vf32;
typedef volatile f64 vf64;

enum { FALSE, TRUE };
typedef int BOOL;

#ifdef __cplusplus
#define restrict

class NonCopyable {
public:
  inline NonCopyable() {}

private:
  inline NonCopyable(const NonCopyable&) {}
};

#define STATIC_ASSERT_CONCAT(a, b) a##b
#define STATIC_ASSERT_MAKE_NAME(line) STATIC_ASSERT_CONCAT(static_assertion_failed_at_line_, line)

// Main static assert macro
#define static_assert(cond) \
    typedef char STATIC_ASSERT_MAKE_NAME(__LINE__)[(cond) ? 1 : -1]
#endif // __cplusplus

#define INLINE_ELSEWHERE(x)

inline u32 min32(u32 a, u32 b) { return a <= b ? a : b; }
