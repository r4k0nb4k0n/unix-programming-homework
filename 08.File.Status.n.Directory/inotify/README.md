# 사건 감시 (inotify)
## NAME
`inotify` - Watch events (move, delete, read, write, ...) for files(dirs)
## SYNOPSIS
```c
#include <sys/inotify.h>

int inotify_init(void);
int inotify_add_watch(int fd, const char *path, uint32_t mask);
int inotify_rm_watch(int f d, uint32_t wd);
int close(int fd);
```
## DATA STRUCTURE
```c
struct inotify_event {
	int wd, uint32_t mask,
	uint32_t cookie,
	uint32_t len, char name[];
};
```
