#include <signal.h>
#include <stdio.h>

void catchint(int  signo)
{
    printf("SIGINT Received\n");
}

main()
{
   signal(SIGINT, (void *) catchint);

   printf("sleep call #1\n");     sleep(1);
   printf("sleep call #1\n");     sleep(1);
   printf("sleep call #1\n");     sleep(1);
   printf("sleep call #1\n");     sleep(1);
   printf("Exiting");
}
