# Hard link
## NAME
`link` - make a new name for a file
## SYNOPSIS
```c
#include <unistd.h>
int link(const char* existingpath, const char* newpath);
```
## RETURN VALUE
Return: 0 if OK, -1 on error
## Description
* existingpath - 이미 존재하는 파일의 경로
* newpath - 연결에 의해 생성될 파일의 경로
* 이미 존재하는 파일에 대하여 새로운 디렉토리 엔트리 생성
* 동일한 inode를 갖는 다수의 파일 존재 가능
* inode에 대한 연결 계수(link count)가 증가
  * Reference counter와 다른 개념
* 디렉토리에 대한 `link()` call은 root만 사용 가능
* 서로 다른 파일 시스템간의 링크는 허용하지 않음
* Link Count
* ![link_count](./link_count.png?raw=true)
