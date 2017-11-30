#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) 
{
	int stat, i;
	char *command[] = {"uname -a", "ls  /dev  >  devfile.txt", "more  <  /etc/passwd"};

	for( i = 0; i < 3; i++ )
		if( (stat = system(command[i])) < 0 )
			fprintf(stderr, "system call failed\n");
		else
			term_stat(stat);
}

void term_stat(int status) {
	if( WIFEXITED(status) )
		printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
	else if( WIFSIGNALED(status) )
		printf("abnormal termination, signal number = %d\n", WTERMSIG(status));
	else if( WIFSTOPPED(status) )
		printf("child stopped, signal number = %d\n", WSTOPSIG(status));
}
