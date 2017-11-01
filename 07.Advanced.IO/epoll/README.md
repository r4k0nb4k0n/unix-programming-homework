# Epoll interface
## NAME
epoll_create, epoll_ctl, epoll_wait
## SYNOPSIS
```
#include <sys/poll.h>

int epoll_create(int size);
int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);
int epoll_wait(int epfd, struct epoll_event *event, int maxevnts, int timeout);
```
## RETURN VALUE
Return:  
epoll_create: -1 if error; otherwise handle number  
epoll_ctl: 0 if success; -1 if error  
epoll_wait: -1 if error; otherwise number of events occurred  

