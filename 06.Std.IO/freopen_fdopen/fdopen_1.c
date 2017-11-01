/* 2017-2 Unix Programming
 * fdopen function
 * Written by Choe Hyeong Jin, Dept. of CSE, Univ. of Seoul
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void){
	char *fname = "test2.txt";
	int fd;
	FILE *fp;

	if( (fp = open(fname, O_WRONLY)) > 0 ){
		printf("Success!!\nFile descriptor: %d\n", fd);
	}
	else{
		printf("failed\n");
	}
	if( (fp = fdopen(fd, "w")) != NULL ){
		printf("fdopen() Success!!\n");
	}
	else{
		printf("fdopen() failed\n");
	}
	fprintf(fp, "I'm your father.\n");
	fclose(fp);
	return 0;
}
