# fsetpos & fgetpos functions
## NAME
fsetpos, fgetpos
## SYNOPSIS
```
#include <stdio.h>

int fsetpos(FILE *stream, fpos_t *pos);
int fgetpos(FILE *stream, fpos_t *pos);
```
## RETURN VALUE
Return : 0 if OK, -1 if error
