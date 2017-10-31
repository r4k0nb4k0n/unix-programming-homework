# Multiplexed I/O: poll
poll
## SYNOPSIS
```
#include <sys/poll.h>

int poll(struct pollfd *fds, unsigned int nfds, int timeout);

struct pollfd{
	int fd;
	short events;
	short revents;
}
```
## RETURN VALUE
Return: number of fds ready for I/O, 0 if timeout, -1 if error
