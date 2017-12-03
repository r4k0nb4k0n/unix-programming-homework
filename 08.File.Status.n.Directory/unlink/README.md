# Unlink
## NAME
`unlink` - delete a name and possibly the file it refers to
## SYNOPSIS
```c
#include <unistd.h>
int unlink(const char* pathname);
```
## RETURN VALUE
Return: 0 if OK, -1 on error
## Description
* pathname - unlink할 파일의 경로 이름
* 파일의 연결 계수(link counter)를 하나 감소시킴
* `unlink()`의 결과로 연결 계수가 0이 되면 디스크 공간과 inode는 시스템에 반납(이 때 참조 계수도 0이어야 함)
  * 물리적으로 파일이 삭제
* 참조 계수 vs. 연결 계수
  * 참조 계수 - 파일을 사용(open)하고 있는 프로세스가 몇 개인지 나타내는 역할
  * 연결 계수 - inode를 가리키는 디렉토리 엔트리가 몇 개인지 나타내는 역할
* 디스크에서 파일이 제거되는 시점은 연결 계수와 참조 계수 모두 0이 되는 시점
