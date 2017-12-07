# 메모리 조작 함수들
## NAME
`memset`, `memcmp`, `memmove`, `memcpy`, `memccpy`, `mempcmp`, `memchr`, `memrchr`, `memmem`
## SYNOPSIS
```c
#define _GNU_SOURCE
#include <string.h>
void* memset(void* s, int c, size_t n);
void* memcmp(const void* s1, const void* s2, size_t n);
void* memmove(void* dst, const void* src, size_t n);
void* memcpy(void* dst, const void* src, size_t n);
void* memchr(const void* s, int c, size_t n);
void* memmem(const void* haystack, size_t haystacklen, const void* needle, size_t needlelen);
```
