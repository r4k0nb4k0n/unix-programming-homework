#include <stdio.h>
int main(void){
	printf("this is the original program\n");

	/*execl("/bin/vi", "vi", "asdf.txt", (char*)0);*/
	execlp("vi", "vi", "asdf.txt", (char*)0);

	printf("this line should never be printed\n");
}
