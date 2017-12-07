# 익명 메모리 사상
## NAME
`mmap`, `munmap` - anonymous memory mapping
## SYNOPSIS
```c
#include <sys/mman.h>
void* mmap(void* start, size_t length, int prot, int flags, int fd, off_t offset);
int munmap(void* start, size_t length);
```
## RETURN VALUE
Return:
* `mmap`: Not `NULL` if OK, `NULL` on error
* `munmap`: `0` if OK, otherwise on error
## Anonymous mmap()
[anony_mmap.c](./anony_mmap.c)
## `/dev/zero`에 사상하기
[zero_device.c](./zero_device.c)
