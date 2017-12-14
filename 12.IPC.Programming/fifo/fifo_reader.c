#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MSGSIZE 64

int main(void) {
   char   msg[MSGSIZE];
   int     fd, nread, cnt;

   if (mkfifo("./fifo", 0666) == -1) {
      printf("fail to create fifo file\n");       exit(1);
   }
   if ((fd = open("./fifo", O_RDWR)) < 0) {
      printf("fail to open fifo file\n");        exit(1);
   }
   for (cnt= 0 ; cnt < 3; cnt++) {
      if ((nread = read(fd, msg, MSGSIZE)) < 0) {
         printf("fail to read from fifo file\n");            exit(1);
      }
      printf("recv: %s\n", msg);
   }
   unlink("./fifo");
}
