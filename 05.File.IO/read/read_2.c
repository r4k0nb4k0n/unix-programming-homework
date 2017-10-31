/* 2017-2 Unix Programming
 * read function. Process vs. File descriptor (1)
 * Written by Choe Hyeong Jin, Dept. of Computer Science and Engineering, Univ. of Seoul
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(void){
	char *fname = "test.txt";
	int fd1, fd2, cnt;
	char buf[30];

	fd1 = open(fname, O_RDONLY);
	fd2 = open(fname, O_RDONLY);
	if( fd1 < 0 || fd2 < 0 ){
		perror("open()");
		exit(-1);
	}
	cnt = read(fd1, buf, 12);
	buf[cnt] = '\0';
	printf("fd1's first printf: %s\n", buf);
	lseek(fd1, 1, SEEK_CUR);
	cnt = read(fd1, buf, 12);
	buf[cnt] = '\0';
	printf("fd1's second printf: %s\n", buf);
	cnt = read(fd2, buf, 12);
	buf[cnt] = '\0';
	printf("fd2's first printf: %s\n", buf);
	lseek(fd2, 1, SEEK_CUR);
	cnt = read(fd2, buf, 12);
	buf[cnt] = '\0';
	printf("fd2's second printf: %s\n", buf);
	return 0;
}
