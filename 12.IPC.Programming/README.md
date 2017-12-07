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
#define SIGIO SIGPOLL   // socket I/O possible (SIGPOLL alias)
#define SIGSTOP 23      // stop(cannot be caught or ignored)
#define SIGTSTP 24      // user stop requested from tty
#define SIGCONT 25      // stopped process has ben continued
#define SIGTTIN 26      // background tty read attempted
#define SIGTTOU 27      // background tty write attempted
#define SIGVTALRM 28    // virtual timer expired
#define SIGPROF 29      // profiling timer expired
#define SIGXCPU 30      // exceeded cpu limit
#define SIGXFSZ 31      // exceeded file size limit
#define SIGWAITING 32   // process's lwps are blocked
#define SIGLWP 33       // special signal used by thread library
#define SIGFREEZE 34    // special signal used by CPR
#define SIGTHAW 35      // special signal used by CPR
#define SIGCANCEL 36    // thread cancellation signal used by libthread
#define SIGLOST 37      // resource lost(eg. record-lock lost)
```
* 대표적인 signal
	- `SIGABRT`: `abort()` 함수의 호출에 의해 발생. 프로세스는 비정상적으로 종료
	- `SIGALRM`: alarm 함수에 의해 설정된 타이머에 의해 발생
	- `SIGCHLD`: 프로세스가 종료하거나 정지한 경우, 부모 프로세스에게 전달
	- `SIGFPE`: 산술 연산 에러에 의해 발생(0으로 나눈 경우 등)
	- `SIGHUP`: 터미널 연결이 단절되는 경우 제어 프로세스에게 전달
	- `SIGINT`: 인터럽트 키(Ctrl+C)를 누를 경우 터미널에서 동작하는 프로세스에게 전달
	- `SIGKILL`: 프로세스를 종료하라는 시그널. 무시하거나 임이의 처리를 할 수  없는 시그널.
	- `SIGQUIT`: quit 키(ctrl+\)를 누르면 터미널 드라이버에서 발생. 종료된 프로세스는 core 파일을 생성
	- `SIGSEGV`: 잘못된 메모리 참조에 의해 발생
	- `SIGSTOP`: 프로세스를 정지시키는 작업 제어 시그널. 무시하거나 임이의 처리를 할 수 없는 시그널.
	- `SIGTERM`: 작업 종료 시그널
	- `SIGUSR1`: 응용 프로그램에서 사용자가 정의하여 사용할 수 있는 시그널.
	- `SIGUSR2`: 응용 프로그램에서 사용자가 정의하여 사용할 수 있는 시그널.
* Signal의 처리
	* 시그널 무시 (ignore)
		- `SIGKILL`과 `SIGSTOP` 시그널을 제외한 모든 시그널을 무시할 수 있음
		- 하드웨어 오류에 의해 발생한 시그널에 대해서는 주의해야 함
	* 시그널 처리 (catch)
		- 시그널이 발생하면 미리 등록된 함수(handler)가 수행됨
		- `SIGKILL`과 `SIGSTOP` 시그널에는 처리할 함수를 등록할 수 없음
	* 기본 처리 (default)
		- 특별한 처리 방법을 선택하지 않은 경우
		- 대부분 시그널의 기본 처리 방법은 프로세스의 종료
## Signal 관련 함수들
* [Signal function](./signal)
* [kill function](./kill)
* [raise function](./raise)
* signal, kill function
	- [signal1.c](./signal1.c)
	- [signal2.c](./signal2.c)
	- [sig_parent.c](./sig_parent.c), [sig_child.c](./sig_child.c)
* [alarm function](./alarm)
* [pause function](./pause)
* alarm, pause function
	- [alarm.c](./alarm_pause.c)
* [Signal set](./signal_set)
* [sigprocmask function](./sigprocmask)
* [sigpending function](./sigpending)
* [SIGSUSPEND function](./sigsuspend)
* [Race Condition 없는 `SIGALRM`](./sigsuspend/norace_alm.c)
## Pipe

