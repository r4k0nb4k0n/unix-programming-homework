# 실행 이미지의 대체(exec)
## NAME
execv, execle, execve, execlp, execvp - execute a file
## SYNOPSIS
```c
int execl(char* path, char* arg0, char* arg1, ..., char* argn, (char*)0);
int execv(char* path, char* argv[]);
int execle();
int execve();
int execlp();
int execvp();
```
## RETURN VALUE
Return : do not Return if OK, -1 on error
## Description
* exec에 붙는 문자의 의미
## 프로그램의 실행(exec)
* [exec1.c](./exec1.c)
* [exec2.c](./exec2.c)
* [exec3.c](./exec3.c)
