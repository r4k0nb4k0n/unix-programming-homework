#include <stdio.h>
int main(void){
	static char *nargv[] = {"echo", "parm1", "parm2", "parm3", (char*)0};
	printf("this is the original program\n");
	execvp("echo", nargv);
	//execlp("echo", "echo", "parm1", "parm2", "parm3", (char*)0);
	printf("this line should never be printed\n");
}
