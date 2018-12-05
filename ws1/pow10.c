#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define BASE = 10;

double Pow10(int num)
{
	int abs_number = abs(num); 
	double result = 1;

	int i;
	for (i = 0; i < abs_number; i++)
	{
		result *= BASE;
	}

	if (num < 0)
	{
		result /= (result * result);
	}

	return result;
}

void PowTest(int num) 
{
	int i;
	for (i = -20; i <= 20; i++)
	{
		double expected = pow(BASE, num);
		if (Pow10(num) == expected)
		{
			printf("\x1B[32m-----------OK!-----------\nThe power of 10 by %d is: %0.f\n", num, expected);
		}
		else
		{
			printf("\x1B[31m-----------ERROR!-----------\nThe power of 10 by %d is: %f NOT: %f\n", num, expected, Pow10(num));
		}
	}
}

int main(void)
{
	int number;
	scanf("%d", &number);                                                 
	PowTest();

	if (number >= 0)  
	{
		printf("\x1B[34mThe power of 10 by %d is: %.0f\n", number, Pow10(number));
	}
	else
	{
		printf("\x1B[34mThe power of 10 by %d is: %.6f\n", number, Pow10(number));
	}

	return 0;
}
