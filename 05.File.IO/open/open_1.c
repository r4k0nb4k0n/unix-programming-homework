/* 2017-2 Unix Programming
 * open function
 * Written by Choe Hyeong Jin, Dept. of Computer Science and Engineering, Univ. of Seoul
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void){
	char *fname = "test.txt";
	int fd;

	fd = open(fname, O_RDONLY);
	if( fd > 0 ){
		printf("Success\n FileName:%s, fd: %d\n", fname, fd);
		close(fd);
	}
	else
		perror("open failed\n");

	return 0;
}
