/* 2017-2 Unix Programming
 * creat function
 * Written by Choe Hyeong Jin, Dept. of Computer Science and Engineering, Univ. of Seoul
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void){
	char *fname = "test.txt";
	int fd;

	fd = creat(fname, 0666);
	if( fd < 0 )
		perror("creat()");
	else{
		printf("Success!\n Filename: %s, fd: %d\n", fname, fd);
		close(fd);
	}

	return 0;
}
