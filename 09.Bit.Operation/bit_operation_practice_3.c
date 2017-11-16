#include <stdio.h>

void div_num(unsigned int num, int *first, int *second, int *third){
	unsigned int temp = num;
	*first = num >> 22;
	*second = (num << 10) >> 22;
	*third = (num << 20) >> 20;
}

int main(void){
	unsigned int num = 0x29387200;
	int first, second, third;
	div_num(num, &first, &second, &third);
	printf("%d %d %d\n", first, second, third);
	return 0;
}
