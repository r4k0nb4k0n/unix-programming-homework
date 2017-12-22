#include<stdio.h>

int main(int argc, char *argv[])
{
	int pid;
	int i;
	if(argc<2) {exit(1);}


	for(i=1;i<argc;i++){
		pid=fork();
		if(pid==0) {
			execlp("wc","wc",argv[i],(char *)0);
		}
	}
	sleep(2);
	return 0;
}
