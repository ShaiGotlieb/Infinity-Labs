#include <stdio.h>
#include <stdlib.h> /* EXIT_SUCCESS */

#define ARR_SIZE 58 /* number of letters A..Z + a..z + 6 signs */
#define OFFSET 65 /* 'A' - 65 = 0 ('A' will be stored in index 0 of array) */
#define ARRAY_LENGTH(array) (sizeof((array))/sizeof((array)[0]))

/* Algorithem explenation: 
 *	1. run through each array once
 *	2. insert to matching array +1 for the place the letter represent as shown in define 'OFFSET'
 *	3. for the 3rd array insert -1
 *	4. run through 3 arrays simultanious
 *	5. if the location of the letter inside 1st and 2nd array is > 0 and it's not appearing in 3rd array (0) - print the char
 *	   else - the letter appears in 3rd array (negative number)
*/
void FindInArr(char arr1[], char arr2[], char arr3[], int size1, int size2, int size3)
{
	int appear_in_arr1[ARR_SIZE] = {0};
	int appear_in_arr2[ARR_SIZE] = {0};
	int appear_in_arr3[ARR_SIZE] = {0};
	int i;

	for (i = 0; i < size1; ++i)
	{
		appear_in_arr1[arr1[i] - OFFSET] += 1;
	}

	for (i = 0; i < size2; ++i)
	{
		appear_in_arr2[arr2[i] - OFFSET] += 1;
	}

	for (i = 0; i < size3; ++i)
	{
		appear_in_arr3[arr3[i] - OFFSET] -= 1;
	}

	/* check apperance in first 2 arrays but not in third */
	for (i = 0; i < ARR_SIZE; ++i)
	{
		if (appear_in_arr1[i] > 0 && appear_in_arr2[i] > 0 && appear_in_arr3[i] == 0)
		{
			printf("%c", i + OFFSET);
		}
	}
	printf("\n");

}

int main()
{
	char arr1[] = {'a', 'b', 'c', 'd', 'e'};
	char arr2[] = {'a', 'b', 'b', 'e', 'd'};
	char arr3[] = {'H', 'e', 'c', 'e', 'd'};
	int size1 = ARRAY_LENGTH(arr1);
	int size2 = ARRAY_LENGTH(arr2);
	int size3 = ARRAY_LENGTH(arr3);

	FindInArr(arr1, arr2, arr3, size1, size2, size3);

	return EXIT_SUCCESS;
}