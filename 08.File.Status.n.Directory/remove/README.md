# Remove
## NAME
`remove` - delete a name and possibly the file it refers to
## SYNOPSIS
```c
#include <stdio.h>
int remove(const char* pathname);
```
## RETURN VALUE
Return: 0 if OK, -1 on error
## Description
* pathname - 대상 파일의 경로
* pathname이 파일이면 `unlink()`와 같은 동작
* 디렉토리이면 `rmdir()`과 같은 기능 수행
* 파일의 내용이 있으면 지워지지 않음
