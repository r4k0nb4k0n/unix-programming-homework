#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MSGSIZE 64

int main(void) {
   char  msg[MSGSIZE];
   int     fd, cnt;

   if((fd = open("./fifo", O_WRONLY)) < 0) {
      printf("fail to open fifo file\n");          exit(1);
   }

   for (cnt = 0; cnt < 3; cnt++) {
      printf("input a message: ");
      scanf("%s", msg);
      if (write(fd, msg, MSGSIZE) == -1) {
         printf("fail to write to fifo\n");             exit(1);
      }
      sleep(1);
   }
}
