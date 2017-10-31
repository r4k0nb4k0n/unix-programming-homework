# Multiplexed I/O: pselect
## NAME
select
## SYNOPSIS
```
#define _XOPEN_SOURCE 600
#include <sys/select.h>

int pselect(int n, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, const struct timespec *timeout, const sigset_t *sigmask);
FD_CLR(int fd, fd_set *set);
FD_ISSET(int fd, fd_set *set);
FD_SET(int fd, fd_set *set);
FD_ZERO(fd_set *set);
```
## RETURN VALUE
ReturnL number of fds ready for I/O, 0 if timeout, -1 if error
