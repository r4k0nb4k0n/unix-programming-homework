#include <stdio.h>

int main(void)
{
	int n=10;
	int a=0,b=1;
	int pid, i;
	
	if((pid=fork())>0) {
		for(i=1;i<=n;i++) {
			a+=i;
		}
		printf("%d",a);
	}
	else if (pid==0){
		for(i=1;i<=n;i++) {
			b=b*i;
		}
		printf("%d",b);
		sleep(1);
	}

	return 0;
}
