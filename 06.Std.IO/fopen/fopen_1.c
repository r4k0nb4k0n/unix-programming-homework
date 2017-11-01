/* 2017-2 Unix Programming
 * fopen function
 * Written by Choe Hyeong Jin, Dept. of CSE, Univ. of Seoul
 */

#include <stdio.h>

int main(void){
	FILE *fp;

	if( (fp = fopen("test.txt", "r")) != NULL ){
		printf("Success!\n");
		printf("Opening \"test.txt\" in \"r\" mode!\n");
		printf("File descriptor of fp: %d\n", fp->_fileno);
	}
	else{
		perror("Error");
		exit(-1);
	}
	fclose(fp);

	return 0;
}
