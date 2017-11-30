/* 2017-2 Unix Programming
 * Written by Choe Hyeong Jin, Dept. of CSE, Univ. of Seoul
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	int lmt, i=1, sw, res;
	pid_t pid;
	scanf("%d", &lmt);
	if( (pid = fork()) > 0 ){
		sw=1; res=1;
		for(i=1;i<=lmt;i++)
			res*=i;
	}
	else{
		sw=0; res=0;
		for(i=1;i<=lmt;i++)
			res+=i;
	}
	if(sw==0){
		printf("Multiply 1 to %d => %d\n", lmt, res);
	}
	else{
		printf("Sum 1 to %d => %d\n", lmt, res);
	}
	printf("pid = %d\n", getpid());
	return 0;
}
