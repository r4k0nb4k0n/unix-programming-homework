#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
static int glob = 6;
char buf[] = "a write to stdout\n";
int main(void){
	int var;
	pid_t pid;
	var = 88;
	if( write(STDOUT_FILENO, buf, sizeof(buf)-1) != sizeof(buf)-1 )
		printf("write error\n");
	printf("before fork\n");
	if( (pid = fork()) < 0 )
		printf("fork error\n");
	else if( pid == 0 ){
		glob++;
		var++;
	}
	else
		sleep(2);
	printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
	exit(0);
}
