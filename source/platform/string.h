#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80005f34
void* memcpy(void*, const void*, u32);
// PAL: 0x80006038
void* memset(void*, s32, u32);

void *memmove(void *, const void *, size_t);

int memcmp(const void *s1, const void *s2, size_t n);

u32 strlen(const char *);

char * strcpy(char * dst, const char * src);
char *strncpy(char *dest, const char *src, size_t n);
int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);

char * strchr ( const char *, int );

char *strstr(const char *haystack, const char *needle);

#ifdef __cplusplus
} // extern "C"
#endif
