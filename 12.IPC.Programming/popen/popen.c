#include <stdio.h>

int main(void)
{
   FILE  *pipein_fp, *pipeout_fp;
   char  readbuf[80];

   /* create one way pipe with popen() */
   pipein_fp = popen("ls", "r");

   /* create one way pipe with popen() */
   pipeout_fp = popen("sort", "w");

   /* read from pipein_fp and write to pipeout_fp */
   while (fgets(readbuf, 80, pipein_fp))
      fputs(readbuf, pipeout_fp);

   /* close pipes */
   pclose(pipein_fp);
   pclose(pipeout_fp);

   return 0;
}
