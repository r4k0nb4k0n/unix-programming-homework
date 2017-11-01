# Readv, writev
## NAME
readv, writev
## SYNOPSIS
```
#include <sys/uio.h>

ssize_t readv(int fd, const struct iovec *iov, int count);
ssize_t writev(int fd, const struct iovec *iov, int count);

struct iovec{
	void *iov_base;
	size_t iov_len;
}
```
## RETURN VALUE
Return : number of bytes written or read if success, -1 if error
