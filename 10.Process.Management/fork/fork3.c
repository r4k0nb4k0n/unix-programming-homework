#include <stdio.h>
#include <unistd.h>
int main(void){
	char first, last, ch;
	int pid, i;

	if( (pid = fork()) > 0 ){ // 부모
		first = 'A';
		last = 'Z';
	}
	else if( pid == 0 ){ // 자식
		first = 'a';
		last = 'z';
		sleep(1);
	}

	for(ch = first;ch <= last;ch++)
		write(1, &ch, 1);

	return 0;
}
