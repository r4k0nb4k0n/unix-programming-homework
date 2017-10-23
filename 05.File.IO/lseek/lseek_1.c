/* 2017-2 Unix Programming
 * lseek function
 * Written by Choe Hyeong Jin, Dept. of Computer Science and Engineering, Univ. of Seoul
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(void){
	char *fname = "test.txt";
	int fd;
	off_t fsize;

	if( (fd = open(fname, O_RDONLY)) < 0 ){
		perror("open()");
		exit(-1);
	}
	fsize = lseek(fd, 0, SEEK_END);
	printf("The size of <%s> is %lu bytes.\n", fname, fsize);
	return 0;
}
