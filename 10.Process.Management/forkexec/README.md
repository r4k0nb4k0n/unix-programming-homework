# 새로운 프로그램의 실행(`fork`/`exec`)
```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){
	if( fork() == 0 ){
		exec("/bin/echo", "echo", "this is", "message one", (char*) 0);
		printf("exec one failed\n");
		exit(1);
	}
	if( fork() == 0 ){
		execl("/bin/echo", "echo", "this is", "message two", (char*) 0);
		printf("execl failed\n");
		exit(1);
	}
	if( fork() == 0 ){
		execl("/bin/echo", "echo", "this is", "message three", (char*) 0);
		printf("execl one failed\n");
		exit(1);
	}
	printf("Parent program ending\n");
	return 0;
}
```
