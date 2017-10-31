# fsync, fdatasync, sync
## NAME
fsync, fdatasync
## SYNOPSIS
```
#include <unistd.h>

int fsync (int fd);
int fdatasync (int fd);
void sync (void);
```
## RETURN VALUE
Return: 0 if OK, -1 if error

## Description
* fsync(fd): fd의 메타데이터와 파일 데이터 저장
* fdsync(fd): fd의 파일 데이터 저장
* Sync(): 시스템의 모든 변경된 데이터 
