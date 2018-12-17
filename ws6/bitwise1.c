#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define BYTE 8
#define MASK 1

int Add1(unsigned int num)
{
	int steps = 0;

	while((MASK & num) == 1)
	{
		num = num >> 1;
		steps++;
	}

	num |= MASK; /* add 1 */
	num = num << steps;

	return num;
}

void TestAdd1()
{
	int i = 0;

	for (i = 0; i < 10; ++i)
	{
		if (Add1(i) == i+1 )
		{
			printf("OK---\n");
		}
		else
		{
			printf("ERROR---\n");
		}
	}
}

double Pow2(unsigned int x, int y)
{
	unsigned int a = x;
	int b = y;
	double result = 0;
	int isNegative = 0;
	
	if ( b < 0)
	{
		/* make b positive */
		b = ~b;
		b = Add1(b);

		isNegative = 1;
	}
	result = MASK << b;

	if (isNegative)
	{
		result = (double)a / result; 
	}
	else
	{
		result = (double)a * result;
	}

	return result;
}

void TestPow2()
{
	printf("OK --- my pow: %f pow: %f\n", Pow2(2, -8), 2*(pow(2, -8)));
	printf("OK --- my pow: %f pow: %f\n", Pow2(0, 0), 0*(pow(0, 0)));
	printf("OK --- my pow: %f pow: %f\n", Pow2(2, 3), 2*(pow(2,3)));
	printf("OK --- my pow: %f pow: %f\n", Pow2(2, -1), 2*(pow(2, -1)));
	printf("OK --- my pow: %f pow: %f\n", Pow2(1, 0), 1*(pow(1, 0)));
}

int Check2Loop(unsigned int x)
{
	int counter = 0;

	while (x != 0)
	{
		if (x & MASK)
		{
			counter++;
		}
		x = x >> 1;
	}
	
	return counter == 1 ? TRUE : FALSE;
}

int CheckLoop(unsigned int x)
{
	if ( (x & ( x - 1)) || x == 0 )
	{
		return FALSE;
	}
	return TRUE;
}

void TestCheck2Loop()
{
	unsigned int numbers[] = {0, 4, 8, 16, 3, 9, 64};
	int answers[] =          {0, 1, 1, 1 , 0, 0,  1};
	int i = 0;
	
	while(i < 7)
	{
		if (Check2Loop(numbers[i]) == answers[i])
		{
			printf("OK---\n");
		}
		else
		{
			printf("ERROR --- %d is NOT power of 2\n", numbers[i]);
		}
		i++;
	}
}

void TestCheckLoop()
{
	unsigned int numbers[] = {0, 4, 8, 16, 3, 9, 64};
	int answers[] =          {0, 1, 1, 1 , 0, 0,  1};
	int i = 0; 
	
	while(i < 7)
	{
		if (CheckLoop(numbers[i]) == answers[i])
		{
			printf("OK---\n");
		}
		else
		{
			printf("ERROR --- %d is NOT power of 2\n", numbers[i]);
		}
		i++;
	}
}

void Bit3On(unsigned int arr[], int size)
{
	unsigned int number = 0;
	int counter = 0;
	int i = 0;

	for (i = 0; i < size; ++i)
	{
		number = arr[i];

		while(number > 0)
		{
			number = number & (number-1);
			counter++;
		}

		if (counter == 3)
		{
			printf("Number: %d has 3 bits on\n", arr[i]);
		}
		counter = 0;	
	}
}

void TestBit3on()
{
	unsigned int arr[] = {7, 10, 70, 112, 14};

	Bit3On(arr, 5);
}

int ByteMirrorLoop(unsigned int num)
{
	unsigned int mirror = 0;
	int i = 0;

	while(i < BYTE)
	{	
		mirror = mirror << 1;
		mirror = mirror | (num & MASK); /* add LSD */			
		num = num >> 1;
		i++;
	}

	return mirror;
}

void TestByteMirrorLoop()
{
	unsigned int numbers[] = {0, 1, 2, 5};
	int answers[] =          {0, 128, 64, 160};
	int i = 0;
	int result = 0;
	
	while(i < 4)
	{
		result = ByteMirrorLoop(numbers[i]);
		if (result == answers[i])
		{
			printf("OK--- Original: %d Mirror: %d\n", numbers[i], result);
		}
		else
		{
			printf("ERROR --- %d is NOT power of 2\n", numbers[i]);
		}
		i++;
	}
}

unsigned int ByteMirror(unsigned int num)
{
	unsigned int x = num;
	unsigned int y = num;

	unsigned int result1 = 0;
	unsigned int result2 = 0;
	unsigned int result3 = 0;

	unsigned int mask1 = 0xf0;
	unsigned int mask2 = 0x0f;
	unsigned int mask3 = 0xcc;
	unsigned int mask4 = 0x33;
	unsigned int mask5 = 0xaa;
	unsigned int mask6 = 0x55;

	x = ((num & mask1) >> 4); 
	y = ((num & mask2) << 4);
	result1 = x | y;

	x = ((result1 & mask3) >> 2); 
	y = ((result1 & mask4) << 2);
	result2 = x | y;

	x = ((result2 & mask5) >> 1);
	y = ((result2 & mask6) << 1);
	result3 =  x | y; 

	return result3;
}

void TestByteMirror()
{
	unsigned int numbers[] = {0, 1, 2, 5};
	int answers[] =          {0, 128, 64, 160};
	int i = 0;
	int result = 0;
	
	while(i < 4)
	{
		result = ByteMirror(numbers[i]);
		if (result == answers[i])
		{
			printf("OK--- Original: %d Mirror: %d\n", numbers[i], result);
		}
		else
		{
			printf("ERROR --- %d is NOT power of 2\n", numbers[i]);
		}
		i++;
	}
}

int main()
{
	TestPow2();
	TestCheck2Loop();
	TestCheckLoop();
	TestAdd1();
	TestBit3on(); 
	ByteMirrorLoop(1);
	TestByteMirrorLoop();
	TestByteMirror();
	
	
	return EXIT_SUCCESS;
}