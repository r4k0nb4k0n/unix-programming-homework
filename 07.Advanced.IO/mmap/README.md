# Mapping Files into Memory
## NAME
mmap - map files into memory address space
## SYNOPSIS
```
#include <mman.h>
void* mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset);
```
## RETURN VALUE
Return: Not MAP_FAILED if OK, MAP_FAILED on error
