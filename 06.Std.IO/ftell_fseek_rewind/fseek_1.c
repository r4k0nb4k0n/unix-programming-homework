/* 2017-2 Unix Programming
 * fseek function
 * Written by Choe Hyeong Jin, Dept. of CSE, Univ. of Seoul
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
	char *fname = "test.txt";
	long position;
	int ch;
	FILE *fp;

	if( (fp = fopen(fname, "r")) == NULL ){
		printf("File Open Error\n");
		exit(-1);
	}

	printf("Input number >> ");
	scanf("%ld", &position);

	fseek(fp, position-1L, SEEK_SET);
	ch = getc(fp);
	printf("%ldth character => %c\n", position, ch);
	return 0;
}
