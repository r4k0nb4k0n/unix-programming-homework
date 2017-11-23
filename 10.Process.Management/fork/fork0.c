#include <stdio.h>
#include <unistd.h>
int main(void){
	printf("pid = %d, ppid = %d\n", getpid(), getppid());
	fork();
	printf("pid = %d, ppid = %d\n", getpid(), getppid());

	return 0;
}
