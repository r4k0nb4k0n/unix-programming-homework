/* 2017-2 Unix Programming
 * rewind function
 * Written by Choe Hyeong Jin, Dept. of CSE, Univ. of Seoul
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
	char *fname = "test.txt";
	long position;
	FILE *fp;

	if( (fp = fopen(fname, "r")) == NULL ){
		printf("File Open Error\n");
		exit(-1);
	}

	fseek(fp, 10L, SEEK_CUR);
	position = ftell(fp);
	printf("Current position = %ld\n", position);

	rewind(fp);
	position = ftell(fp);
	printf("After rewind() position = %ld\n", position);

	return 0;
}
