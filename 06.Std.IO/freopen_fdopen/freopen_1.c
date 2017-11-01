/* 2017-2 Unix Programming
 * freopen function
 * Written by Choe Hyeong Jin, Dept. of CSE, Univ. of Seoul
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void){
	char *fname = "test1.txt";
	FILE *fp;

	printf("First printf is on the screen.\n");
	if( (fp = freopen(fname, "w", stdout)) == NULL ){
		perror("freopen");
		exit(-1);
	}
	printf("Second printf is in this file.\n");
	return 0;
}
