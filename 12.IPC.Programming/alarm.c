#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void alm(signo)
int signo;
{
    printf("SIGALRM Received\n");
}

main()
{
   signal(SIGALRM, alm);
   alarm(10); // kernel이 칼같이 알람시그널 보내준다.
   printf("process pause\n"); // 누가 먼저 실행되느냐에 따라 영원히 멈출수도 있다.
   // race condition
   pause();
   printf("process wakeup");
}
