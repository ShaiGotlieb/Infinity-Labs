#include <stdio.h>
#include <stdlib.h>

int Flavius(int n)
{
	int i;
	int *a;
	a = malloc(n * sizeof(n));

	/* check allocation*/
	if (NULL == a)
	{
		printf("Allocation failure!\n");
		return -1;
	}

	/* init array with numbers: 1...n */
	for (i = 0; i < n-1; ++i)
	{
		a[i] = i + 1;
	}
	a[n-1] = 0; /* last cell is 0 */

	i = 0; /* reset index */
	while(i != a[i])
	{
		a[i] = a[a[i]];
		i = a[i];
	}
	free(a);
	return i + 1;
}

int main(void)
{
	int people_num = 0;
	int result = 0;

	printf("Please enter number of people in the circle!\n");
	scanf("%d", &people_num);

	result = Flavius(people_num);
	if (result != -1)
	{
		printf("Person %d got lucky!\n", result);
	}

	return EXIT_SUCCESS;
}