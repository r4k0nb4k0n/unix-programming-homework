#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void sig_quit(int);

int main(void)
{
   sigset_t newmask, oldmask, pendmask;

   if (signal(SIGQUIT, sig_quit) == SIG_ERR)
      printf("can't catch SIGQUIT\n");

   sigemptyset(&newmask);
   sigaddset(&newmask, SIGQUIT);
   
   /*block SIGQUIT and save current signal mask */
   if (sigprocmask( SIG_BLOCK, &newmask, &oldmask) < 0)
      printf("SIG_BLOCK error\n");

   sleep(5);     /* SIGQUIT here will remain pending */

   if (sigpending(&pendmask) < 0)
      printf("sigpending error\n");
   if (sigismember(&pendmask, SIGQUIT))
      printf("sigQUIT pending\n");
 
   /* reset signal mask which unblocks SIGQUIT */
   if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
      printf("SIG_SETMASK error\n");
   printf("SIGQUIT unblocked\n");
   sleep(5);
}

void sig_quit(int signo)
{
   printf("caught SIGQUIT\n");
   if (signal(SIGQUIT, SIG_DFL) == SIG_ERR)
      printf("can't reset SIGQUIT\n");
}

