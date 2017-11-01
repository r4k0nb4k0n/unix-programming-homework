# fclose function
## NAME
fclose - close a stream
## SYNOPSIS
```
#include <stdio.h>
int fcloes(FILE *fp);
```
## RETURN VALUE
Return : 0 if OK, EOF on error
## Description
* fp - 파일 포인터
* FILE 포인터가 가리키는 스트림과 파일을 분리한 후 파일 닫음
* 출력 버퍼에 있는 모든 자료는 파일에 저장되고, 입력 버퍼에 있는 모든 자료는 버려진 후에 버퍼를 해제
* 프로세스가 정상적으로 종료하는 경우, 닫히지 않은 표준 입출력 스트림에 대해 fclose가 자동 실행
