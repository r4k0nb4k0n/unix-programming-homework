# rewinddir, closedir function
## NAME
`rewinddir`, `closedir` - reset or close directory stream
## SYNOPSIS
```c
#include <sys/types.h>
#include <dirent.h>
void rewinddir(DIR* dp);
int closedir(DIR* dp);
```
## RETURN VALUE
Return: 0 if OK, -1 on error
## Description
* rewinddir : 디렉토리 파일의 offset을 처음으로 이동
* closedir : 디렉토리를 닫는다.
