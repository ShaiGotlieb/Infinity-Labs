#include <stdio.h>
#include <stdlib.h>

int Flip(int number)
{
	int flipped_number = 0; 
	int is_negative = 1;  
	
	if(number < 0)
	{
		number *= -1; /* make number positive*/
		is_negative = -1; 
	}

	while(number > 0)	
	{
		flipped_number *= 10;
		flipped_number += number % 10;
		number /= 10;
	}

	return is_negative * flipped_number;
}

void TestFlip()
{
	int i;
	for (i = 999999998; i > 0; i /= 9)
	{
		printf("Original Number: %d | Flipped Number: %d\n", i, Flip(i));
	}
}

int main()
{
	int user_number;  

	scanf("%d", &user_number);
	printf("USER INPUT------> Original Number: %d  |  Flipped Number: %d\n", user_number, Flip(user_number));
	printf("____TEST____\n");
	TestFlip();

	return 0;
}
