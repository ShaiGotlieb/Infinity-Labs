#include <stdio.h>
#include <stdlib.h>

#define MASK 1
#define TRUE 1
#define FALSE 0

int Check2And6(unsigned char x)
{
	unsigned char bit2 = MASK & (x >> 2);
	unsigned char bit6 = MASK & (x >> 6);

    return (MASK == (bit2 & bit6));
}
int Check2Or6(unsigned char x)
{
	unsigned char bit2 = MASK & (x >> 2);
	unsigned char bit6 = MASK & (x >> 6);
    
     return (MASK == (bit2 | bit6));
}

void TestCheck2And6()
{
	int numbers[] = {70, 71, 102, 77};
	int answers[] = {TRUE, TRUE, TRUE, TRUE};
	int i;
	
	for (i = 0; i < 4; ++i)
	{
		if (Check2And6(numbers[i]) == answers[i])
		{
			printf("OK ---\n");
		}
		else
		{
			printf("ERROR!\n");
		}
	}
}

void TestCheck2Or6()
{
	int numbers[] = {70, 71, 102, 77};
	int answers[] = {TRUE, TRUE, TRUE, TRUE};
	int i;
	
	for (i = 0; i < 4; ++i)
	{
		if (Check2And6(numbers[i]) == answers[i])
		{
			printf("OK ---\n");
		}
		else
		{
			printf("ERROR!\n");
		}
	}
}

int Swap3And5(unsigned char n)
{
     
    unsigned char bit3 =  (n >> 3) & 1; /* get bit 3 */
    unsigned char bit5 =  (n >> 5) & 1; /* get bit 5 */
    unsigned char x = (bit3 ^ bit5); 
  	unsigned char result = 0;
    
    x = (x << 3) | (x << 5); /* back to original position */
  	result = n ^ x; 
    
    return result;
}

void Swap(int *x, int *y)
{
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
    
    printf("x:%d y:%d\n", *x, *y);
}

void TestSwap()
{
	int a = 0;
	int b = 4;
	int c = 8;
	int d = 16;
	int e = 3;
	int f = 9;
	
	printf("original x:%d y:%d\n", a, b);
	Swap(&a,&b);
	printf("original x:%d y:%d\n", c, d);
	Swap(&c,&d);
	printf("original x:%d y:%d\n", e, f);
	Swap(&e,&f);
	
}

int CountBitsLoop(int num)
{
	int counter = 0;

	while (num != 0)
	{
		if (num & MASK)
		{
			counter++;
		}
		num = num >> 1;
	}
	return counter;
}

void TestCountBitsLoop()
{
	int numbers[] = {0, 4, 20, 16, 170, 90};
	int answers[] = {0, 1,  2,  1,   4,  4};
	int i;
	
	for (i = 0; i < 6; ++i)
	{
		if (CountBitsLoop(numbers[i]) == answers[i])
		{
			printf("OK ---\n");
		}
		else
		{
			printf("ERROR!\n");
		}
	}
}

unsigned int Divide16(unsigned int num)
{
	number = number >> 4; /* remove 4 right bits */
	number = number << 4; /* bring back to original without 4 right bits */

	return number >= 16 ? number : 0; /* number that smaller than 16 and devided by 16 is 1 */
}

void TestDivide16()
{
	unsigned int numbers[] = {0, 4, 22, 33, 64, 17};
	unsigned int answers[] = {0, 1, 16, 32, 64, 16};
	int i;
	
	for (i = 0; i < 6; ++i)
	{
		if (Divide16(numbers[i]) == answers[i])
		{
			printf("OK ---\n");
		}
		else
		{
			printf("ERROR!\n");
		}
	}
}

int CountBits(int x)
{
	int mask1 = 0x55555555; /* 01010101 */
	int mask2 = 0x33333333; /* 00110011 */
	int mask3 = 0x0f0f0f0f; /* 00001111*/
	int mask4 = 0x00ff00ff; /* 16 zeros and 16 ones */
	int mask5 = 0x0000ffff; /* 32 zeros and 32 ones */

	x = (x & mask1 ) + ((x >>  1) & mask1 ); /* count the bits in each pair of bits */
    x = (x & mask2 ) + ((x >>  2) & mask2 ); /* count the bits in each nibble bits */
    x = (x & mask3 ) + ((x >>  4) & mask3 ); /* count 8 bits */
    x = (x & mask4 ) + ((x >>  8) & mask4 ); /* count 16 bits */
    x = (x & mask5 ) + ((x >>  16) & mask5 ); /* count 32 bits */

	return x; 
}

void TestCountBits()
{
	int numbers[] = {0, 4, 20, 16, 170, 0xffff};
	int answers[] = {0, 1,  2,  1,   4,  32};
	int i;
	
	for (i = 0; i < 6; ++i)
	{
		if (CountBits(numbers[i]) == answers[i])
		{
			printf("OK ---\n");
		}
		else
		{
			printf("ERROR!\n");
		}
	}
}
void FloatToBits(float num)
{
	unsigned int *p = (unsigned int *)&num;
	unsigned int mask = 0x80000000; /* 10000000000000000000000000000000 */

	while(mask > 0)
	{
		if ((*p & mask) != 0)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		mask = mask >> 1;
	}
}

int main()
{
	/*TestSwap();*/
	/*TestCountBitsLoop();*/
	/*TestCheck2And6();*/
	/*TestCheck2Or6();*/
	/*TestDivide16();*/
	/*TestCountBits();*/
	/*FloatToBits(2);*/

	return EXIT_SUCCESS;
}