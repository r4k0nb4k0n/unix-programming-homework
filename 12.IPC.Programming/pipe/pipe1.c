#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MSGSIZE 17

char *msg1 = "hello, world #1\n";
char *msg2 = "hello, world #2\n";
char *msg3 = "hello, world #3\n";

int main()
{
   char  inbuf[MSGSIZE];
   int     p[2], j;

   if (pipe(p) < 0) {
      perror("pipe call");
      exit(1);
   }
   /* write down pipe */
   write(p[1], msg1, MSGSIZE);
   write(p[1], msg2, MSGSIZE);
   write(p[1], msg3, MSGSIZE);

   for (j = 0; j < 3; j++) {
      read(p[0], inbuf, MSGSIZE);
      printf("%s", inbuf);
   }
}
