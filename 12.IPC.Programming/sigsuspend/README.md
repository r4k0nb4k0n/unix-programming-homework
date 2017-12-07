# SIGSUSPEND function
## NAME
`sigsuspend` - wait signal after sigmask set
## SYNOPSIS
```c

```
## RETURN VALUE
Return:
* `-1` with errno set to `EINTR`
* `-1` with errno set to `EFAULT` if `set` is invalid pointer
