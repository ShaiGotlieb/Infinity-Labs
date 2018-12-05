#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Swap( int **num1, int **num2)
{
	int *tmp_ptr = *num1;
	*num1 = *num2;
	*num2 = tmp_ptr;
}

int main (void)
{
	int num1 = 1;
	int num2 = 8;
	
	int *num1_ptr = &num1;
	int *num2_ptr = &num2;

	Swap(&num1_ptr, &num2_ptr);
	printf("original num1 = %d |  original num2 = %d\n", num1, num2);
	printf("         num1 = %d |  num2 = %d\n", *num1_ptr, *num2_ptr);
	
	return EXIT_SUCCESS;
}