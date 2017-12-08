#include <stdio.h>
#include <unistd.h>
int main(void){
	printf("pid = %d, ppid = %d\n", getpid(), getppid());
	fork();
	printf("pid = %d, ppid = %d\n", getpid(), getppid());
	// 부모 프로세스가 먼저 실행될지, 자식 프로세스가 실행될지는 아무도 모른다.
	// 확률적으로 부모가 먼저다.
	// 만약에 부모 프로세스가 먼저 실행되고 종료되면,
	// 자식 프로세스는 고아 프로세스가 된다.
	// 이는 곧 init 프로세스로 연결된다.
	// 따라서 자식 프로세스의 부모의 pid가 1(init)이 될 수도 있다.
	return 0;
}
