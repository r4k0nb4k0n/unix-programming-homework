/* 2017-2 Unix Programming
 * fgets, fputs
 * Written by Choe Hyeong Jin, Dept. of CSE, Univ of Seoul
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE *fp;
	char buf[100];

	if( (fp = fopen("test.txt", "r")) != NULL ){
		printf("Success!\n");
		printf("Opening \"test.txt\" in \"r\" mode!\n");
		printf("File descriptor of fp: %d\n", fp->_fileno);
	}
	else{
		perror("Error");
		exit(-1);
	}
	while( fgets(buf, 100, fp) )
		fputs(buf, stdout);
	fclose(fp);
	return 0;
}
