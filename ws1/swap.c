#include <stdio.h>

void Swap(int *a, int *b)
{
	int tmp_number = *a; 
	*a = *b;
	*b = tmp_number;
}

int main()
{
	int num1, num2;  
	
	printf("Please insert 2 integers:\n");
	scanf("%d %d", &num1, &num2);    

	Swap(&num1, &num2);
	printf("num1 = %d | num2 = %d\n", num1, num2);

	return 0;
}
