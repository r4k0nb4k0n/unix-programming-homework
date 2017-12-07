# pause function
## NAME
`pause` - wait for signal
## SYNOPSIS
```c
#include ,unistd.h>
void pause(void);
```
## RETURN VALUE
Return: `-1` with errno set to `EINTR`
