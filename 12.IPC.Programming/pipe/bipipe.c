#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAXBUFF 1024

void client(int readfd, int writefd)
{
   char buff[MAXBUFF];
   int  n;

   printf("Client: Enter file name: ");
   if (fgets(buff, MAXBUFF, stdin) == NULL)
      printf("Client: filename read error\n");
   n = strlen(buff);
   if (buff[n-1] == '\n')
      n--;

   if (write(writefd, buff, n) != n)
        printf("Client: filename write error\n");
   while ((n=read(readfd, buff, MAXBUFF)) > 0)
         if (write(1, buff, n) != n)
            printf("Client: data write error\n");
   if (n < 0)
      printf("client: data read error\n");
}

void server(int readfd, int writefd)
{
   char buff[MAXBUFF];
   int  n, fd;

   if ((n=read(readfd, buff, MAXBUFF)) <= 0)
      printf("Server: filename read error\n");
   buff[n] = '\0';

   if ((fd=open(buff, 0)) < 0) {
      strcat(buff, " can't open\n");
      n = strlen(buff);
      if (write(writefd, buff, n) != n)
         printf("Server: errmsg write error\n");
   }
   else {
      while ((n=read(fd, buff, MAXBUFF)) > 0)
         if (write(writefd, buff, n) != n)
             printf("Server: data write error\n");
      if(n < 0)
         printf("Server: read error\n");
   }
}

int main()
{
   int childpid, pipe1[2], pipe2[2];

   if (pipe(pipe1) < 0 || pipe(pipe2) < 0)
      printf("pipe error\n");
   if ((childpid = fork()) < 0)
      printf("fork error\n");
   else if (childpid > 0) {    /* parent process */
      close(pipe1[0]);
      close(pipe2[1]); 
      client(pipe2[0], pipe1[1]);
      while (wait((int *) 0) != childpid);
      close(pipe1[1]);
      close(pipe2[0]);
      exit(0);
   }
   else {          /* child process */
      close(pipe1[1]);
      close(pipe2[0]); 
      server(pipe1[0], pipe2[1]);
      close(pipe1[0]);
      close(pipe2[1]);
      exit(0);
   }
}
