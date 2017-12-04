# 실행 이미지의 대체(exec)
## NAME
`execv`, `execle`, `execve`, `execlp`, `execvp` - execute a file
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
	* `l` : 리스트 형태의 명령라인 인자(`argv[0]`, `argv[1]`, `argv[2]`...)
	* `v` : 벡터(vector) 형태의 명령 라인 인자(`argv[]`)
	* `e` : 환경변수 인자(`envp[]`)
	* `p` : path 정보가 없는 실행화일 이름
* `execve` 함수만이 커널 내의 시스템 함수
* 나머지 함수들은 라이브러리 함수로서 `execve` 함수를 호출한다.
![exec](./exec.png?raw=true)
## 프로그램의 실행(exec)
* [exec1.c](./exec1.c)
* [exec2.c](./exec2.c)
* [exec3.c](./exec3.c)
## `exec` 호출 후 프로세스 속성
* 새로운 프로세스의 속성
	* 호출 전에 open된 파일 디스크립터들은 호출 후에도 그대로 유지되어 사용될 수 있음
		* File descriptor에 `FD_CLOEXEC`이 세트되지 않을 경우
	* 대기 중인 시그널을 잃어버림
	* 메모리 잠금이 풀림
	* 스레드 속성 대부분이 기본값으로 돌아감
	* 프로세스 통계 대부분이 재설정
	* `mmap` 파일과 프로세스 메모리 관련 설정이 해제
* 유지되는 속성
	* pid, ppid, 우선순위, 소유자와 그룹
	* 현재 작업 디렉토리, root 디렉토리
	* 파일 생성 마스크, 파일 잠금
	* CPU 사용 시간(`tms_utime`, `tms_stime`, `tms)cutime`, `tms_ustime`)
