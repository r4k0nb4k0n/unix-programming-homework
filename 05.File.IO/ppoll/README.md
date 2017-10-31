# Multiplexed I/O: ppoll (Linux Only)
## NAME
ppoll
## SYNOPSIS
```
#include <sys/poll.h>

int ppoll(struct pollfd *fds, unsigned int nfds, int timeout, const sigset_t *sigmask);

struct pollfd{
	int fd;
	short events;
	short revents;
}
```
## RETURN VALUE
Return: number of fds ready for I/O, 0 if timeout, -1 if error
