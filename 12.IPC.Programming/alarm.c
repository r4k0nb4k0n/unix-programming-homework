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
   alarm(10);
   printf("process pause\n");
   pause();
   printf("process wakeup");
}
