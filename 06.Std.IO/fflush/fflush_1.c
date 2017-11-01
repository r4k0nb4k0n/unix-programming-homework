/* 2017-2 Unix Programming
 * Buffer Flushing fflush_1.c
 * Written by Choe Hyeong Jin, Dept. of CSE, Univ. of Seoul
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
	fprintf(stdout, "Good Bye ...");
	sleep(5);
	fflush(stdout);
	sleep(5);
	return 0;
}
