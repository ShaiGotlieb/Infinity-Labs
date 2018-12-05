#include <stdio.h>
#include <stdlib.h>

/* function that return 1 for a number contains 7 else return 0*/
int ContainSeven(int num)
{
	while (num > 0)
	{
		if (num % 10 == 7) /* check if last digit is 7*/
		{
			return 1;
		}
		else
		{
			num /= 10; /* remove last digit from number*/
		}
	}
	return 0; /* number does not contain 7*/
}

void Boom()
{
	int from = 0;
	int to = 0;

	printf("Please enter a starting number: \n");
	scanf("%d", &from);

	/* check that start number positive*/
	while(from < 0)
	{
		printf("start number (%d) must be positive!\n", from);
		printf("Please enter a starting number: \n");
		scanf("%d", &from);
	}

	printf("Please enter ending number: \n");
	scanf("%d", &to);

	/* check that end number smaller than start number*/
	while(to <= from)
	{
		printf("end number (%d) must be bigger than start number (%d)\n", from, to);
		printf("Please enter ending number: \n");
		scanf("%d", &to);
	}

	while (from <= to)
	{
		if (from % 7 == 0 || ContainSeven(from) == 1)
		{
			printf("BOOM!\n");
		}
		else
		{
			printf("%d\n", from);
		}
		from++;
	}
}

int main (void)
{
	Boom();
	return EXIT_SUCCESS;
}