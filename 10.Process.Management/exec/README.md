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
