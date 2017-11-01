# Mapping Files into Memory
## NAME
munmap - remove file mapping from memory address space
## SYNOPSIS
```
#include <mman.h>
int munmap(void *addr, size_t len);
```
## RETURN VALUE
Return: 0 if OK, -1 on error
