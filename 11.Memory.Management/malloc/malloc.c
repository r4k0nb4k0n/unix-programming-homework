#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *arr;
	int nums, i;

	printf("how many number do you want to enter? ");
	scanf("%d", &nums);

	if( nums < 0 )
		exit(1);

	if( !(arr = malloc(sizeof(int)*nums)) ) 
		printf("memory allocation error\n");
	
	for( i = 0; i < nums; i++ )
	{
		printf("arr[%d]: ", i);
		scanf("%d", &arr[i]);
	}

	printf("\ntyped numbers. \n");

	for( i = 0; i < nums; i++ )
		printf("arr[%d]: %d\n", i, arr[i]);

	return 0;
}
