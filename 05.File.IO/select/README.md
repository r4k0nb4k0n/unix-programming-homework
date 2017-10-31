# Multiplexed I/O: select
## NAME
select
## SYNOPSIS
```
#include <sys/time.h>
#include <sys/type.h>
#include <unistd.h>

int select(int n, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
FD_CLR(int fd, fd_set *set);
FD_ISSET(int fd, fd_set *set);
FD_SET(int fd, fd_set *set);
FD_ZERO(fd_set, *set);
```
## RETURN VALUE
Return: number of fds ready for I/O, 0 if timeout, -1 if error
## Screenshot
![select](./select.png?raw=true "select")
