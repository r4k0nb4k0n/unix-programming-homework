# 에러 처리
## NAME
`perror`, `strerror`
## SYNOPSIS
```c
#include <string.h>
char* strerror(int errnum);

#include <stdio.h>
void perror(const char* msg);
```
## RETURN VALUE
Return : file descriptor if OK. -1 on error
## Description
* 리눅스 함수는 일반적으로 음수를 리턴하여 에러가 발생했음을 알림.
* 에러 발생 시, 에러의 종류에 따라 전역 변수의 errno에 특정 값이 설정됨.
* `<error.h>`에 에러의 종류와 해당 값이 정의되어 있음
* `strerror`
  * `errno`값에 해당하는 에러 메시지를 리턴
* `perror`
  * 현재의 `errno`값을 읽어 해당하는 에러 메시지를 `msg`와 함께 표준 출력(화면)에 표시
