#include <stdio.h>

void div_num(unsigned int num, int *first, int *second, int *third){
	unsigned int temp = num;
	*first = num >> 22;
	*second = (num << 10) >> 22;
	*third = (num << 20) >> 20;
}

int check_nth_bit(unsigned int num, int n){
	return (num >> (n-1)) & 1;
}
int invert_nth_bit(unsigned int num, int n){
	return check_nth_bit(num, n) ^ 1;
	// (~num >> (n-1)) & 1;
}
int main(void){
	unsigned int num = 0x29387200;
	int first, second, third;
	div_num(num, &first, &second, &third);
	printf("%d %d %d", first, second, third);
	return 0;
}
