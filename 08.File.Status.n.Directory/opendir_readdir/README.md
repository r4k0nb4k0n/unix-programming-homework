# opendir, readdir function
## NAME
`opendir`, `readdir` - open or read directory entry
## SYNOPSIS
```c
#include <sys/types.h>
#include <dirent.h>
DIR* opendir(const char* pathname);
struct dirent* readdir(DIR* dp);
```
## RETURN VALUE
Return: pointer if OK, `NULL` on error
## Description
* opendir
* readdir
* 디렉토리 항목을 읽기 위해선 해당 디렉토리에 대한 읽기 권한이 있어야 함
* 디렉토리에 대한 쓰기 작업은 할 수 없다.
* `readdir()` 수행 시마다 디렉토리 파일의 offset은 sizeof(struct dirent)만큼 증가
