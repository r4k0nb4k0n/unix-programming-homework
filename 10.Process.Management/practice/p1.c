/* 2017-2 Unix Programming
 * Written by Choe Hyeong Jin, Dept. of CSE, Univ. of Seoul
 * 10장 프로세스 
 * 실습 1
 * 사용자로부터 양의 정수값 하나를 입력받는다.
 * fork()를 통해 자식 프로세스 생성
 * 부모 - 1부터 해당 정수까지의 합을 계산하여 출력
 * 자식 - 1부터 해당 정수까지의 곱을 계산하여 출력
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	int lmt, i=1, sw, res;
	pid_t pid;
	scanf("%d", &lmt);
	if( (pid = fork()) > 0 ){ // 부모
		res=0;
		for(i=1;i<=lmt;i++)
			res+=i;
		printf("Sum 1 to %d => %d\n", lmt, res);
	}
	else{ // 자식 또는 에러
		res=1;
		for(i=1;i<=lmt;i++)
			res*=i;
		printf("Multiply 1 to %d => %d\n", lmt, res);
	}
	printf("pid = %d\n", getpid());
	return 0;
}
