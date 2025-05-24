#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80005f34
void* memcpy(void*, const void*, u32);
// PAL: 0x80006038
void* memset(void*, int, size_t);

void* memmove(void*, const void*, size_t);
void* memchr(const void* ptr, int value, size_t num);
void* __memrchr(const void* ptr, int value, size_t num);

int memcmp(const void* s1, const void* s2, size_t n);

u32 strlen(const char*);

char* strcpy(char* dst, const char* src);
char* strncpy(char* dest, const char* src, size_t n);
int strcmp(const char* s1, const char* s2);
int strncmp(const char* s1, const char* s2, size_t n);

char* strchr(const char*, int);
char* strrchr(const char* str, int ch);

char* strstr(const char* haystack, const char* needle);

size_t strspn(const char* s, const char* accept);
size_t strcspn(const char* s, const char* reject);

char* strcat(char* restrict dest, const char* restrict src);
char* strncat(char* restrict dest, const char* restrict src, size_t n);

#ifdef __cplusplus
} // extern "C"
#endif
