/* 2017-2 Unix Programming
 * Written by Choe Hyeong Jin, Dept. of CSE, Univ. of Seoul
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	int lmt, i=1, sw=0, res=0;
	pid_t pid;
	if( (pid = fork()) > 0 ){
		res=1;
		scanf("%d", &lmt);
		for(i=1;i<=lmt;i++){
			res*=i;
		}
	}
	else{
		scanf("%d", &lmt);
		for(i=1;i<=lmt;i++){
			res+=i;
		}
	}
	if(sw==0){

	}
	else{

	}
	printf("pid = %d\n", getpid());
	return 0;
}
