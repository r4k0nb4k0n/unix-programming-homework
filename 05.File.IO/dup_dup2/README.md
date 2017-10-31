# dup, dup2
## NAME
dup, dup2 - duplicate a file descriptor
## SYNOPSIS
```
#include <unistd.h>
int dup(int filedes);
int dup2(int filedes, int newfiledes);
```
## RETURN VALUE
Return: new file descriptor if OK, -1 on error
## Description
* File descriptor를 복사
* dup(int filedes)
	* 인자로 넘어온 file descriptor의 엔트리를 사용되지 않는 가장 작은 file descriptor table의 엔트리로 복사
	* fd2 = dup(fd1)을 수행했을 때  
	![dup_desc](./dup_desc.png?raw=true "dup_desc")
* dup2(filedes, newfiledes)
	* filedes가 가리키는 file descriptor의 엔트리를 newfiledes가 가리키는 곳으로 복사
	* 만약 newfiledes가 가리키는 곳에 이미 엔트리가 존재할 경우 닫고 할당
	![dup2_desc](./dup2_desc.png?raw=true "dup2_desc")
## Screenshots
* dup_1.c
![dup_1](./dup_1.png?raw=true "dup_1")
* dup_2.c
![dup_2](./dup_2.png?raw=true "dup_2")
