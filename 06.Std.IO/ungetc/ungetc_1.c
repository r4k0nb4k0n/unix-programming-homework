/* 2017-2 Unix Programming
 * ungetc function
 * Written by Choe Hyeong Jin, Dept. of CSE, Univ. of Seoul
 */

/*12345+67*/
#include <stdio.h>
int main(void){
	int c, number;
	FILE *fp;

	if( (fp = fopen("test.txt", "r")) == NULL ){
		perror("File open error");
		exit(-1);
	}
	while( !feof(fp) ){
		c = fgetc(fp);
		if( c == '\n' ) continue;
		else if(isdigit(c)){
			number = c - '0';
			while( (c = fgetc(fp)) != EOF && isdigit(c) )
				number = 10*number+c-'0';
			fprintf(stdout, "Operand => %d\n", number);
			ungetc(c, fp);
		}
		else fprintf(stdout, "Operator => %c\n", (char) c);
	}
	fclose(fp);
	return 0;
}
