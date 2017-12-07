#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void alm(int signo)
{
    printf("SIGALRM Received\n");
}

main()
{
   sigset_t  newmask, oldmask;

   signal(SIGALRM, alm);
   sigemptyset(&newmask);
   sigaddset(&newmask, SIGALRM);
   sigprocmask(SIG_BLOCK, &newmask, &oldmask);

   alarm(10);
   printf("process pause\n");
   sigsuspend(&oldmask);
   printf("process wakeup");
}
