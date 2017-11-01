# File locking for multi-thread programming
## NAME
flockfile, funlockfile, ftrylockfile
## SYNOPSIS
```
#include <stdio.h>

void flockfile(FILE *stream);
void funlockfile(FILE *stream);
int ftrylockfile(FILE *stream);
```
## RETURN
Return: ftrylockfile: 0 if the stream is unlocked previously, nonzero if the stream is locked already
