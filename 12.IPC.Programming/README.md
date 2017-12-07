# 12.IPC.Programing
## IPC
* Inter-process Communication
	* Process간의 resource와 information의 공유
	* Kernel에 의해 지원
![IPC](./ipc.png?raw=true)
## Signal
* 정의
	* 프로세스간에 메시지를 전달하기 위한
	* 프로세스간 동기화 및 메시지 전달 시 이용
* Signal의 전달
	* 한 프로세스가 다른 프로세스에게 보냄
	* 커널이 프로세스에게 보냄
	* 사용자가 프로세스에게 전달
	* 시그널은 프로세스가 실행을 멈추었다가 재실행될 때 시그널을 받음
* Signal의 발생
	* 인위적 발생: `kill()`
	* 사건발생: 알람, 프로세스 종료 등
	* 에러상황: 잘못된 메모리 접근 등
	* 외부상황: 키보드 입력(Ctrl+C)
* Signal의 처리
	* 무시, 보류 종료, 특정함수 호출
* Signal Definition
```c
#define SIGHUP 1        // hangup
#define SIGINT 2        // interrupt (rubout)
#define SIGQUIT 3       // quit (ASCII FS)
#define SIGILL 4        // illegal instruction (net reset when caught)
#define SIGTRAP 5       // trace trap(not reset when caught)
#define SIGIOT 6        // IOT instruction
#define SIGABRT 6       // used by abort, replace SIGIOT in the future
#define SIGEMT 7        // EMT instruction
#define SIGFPE 8        // floating point exception
#define SIGKILL 9       // kill(cannot be caught or ignored)
#define SIGBUS 10       // bus error
#define SIGSEGV 11      // segmentation violation
#define SIGSYS 12       // bad argument to system call
#define SIGPIPE 13      // write on a pipe with no one to read it
#define SIGALRM 14      // alarm clock
#define SIGTERM 15      // software termination signal from kill
#define SIGUSR1 16      // user defined signal 1
#define SIGUSR2 17      // user defined signal 2
#define SIGCLD 18       // child status change
#define SIGPWR 19       // power-fail restart
#define SIGWINCH 20     // window size change
#define SIGURG 21       // urgent socket condition
#define SIGPOLL 22      // pollable event occured
```
