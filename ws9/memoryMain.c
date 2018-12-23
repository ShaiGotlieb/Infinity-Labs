#include "memory.h"

static void TestMemset()
{
	char str[1000] = "Hi this string should be replaced with 'Z'"; 
	int c = 'Z';
	int i;
	
	for (i = 0; i < 10; ++i)
	{
		if (memcmp(Memset(str, c, i), memset(str, c, i), i) == 0)
		{
			printf("[OK] --- Memset(): %s\n", str);
		}
		else
		{
			printf("[FAILED] --- Memset()\n");
		}
	}
}

static void TestMemcpy()
{
	char from[100] = "string something blabla I love avocado but only if they are soft"; 
	char to[100] = ""; 
	int i;

	for (i = 0; i < 10; ++i)
	{
		if (memcmp(Memcpy(to, from, strlen(from)), memcpy(to, from, strlen(from)), i) == 0)
		{
			printf("[OK] --- Memcpy(): \n\toriginal: %s \n\tdestination: %s\n", from, to);
		}
		else
		{
			printf("[FAILED] --- Memcpy()\n");
		}
	}
}

static void TestMemmove()
{
	int i;	
	char from[] = "this is just a string ayyyayayy";
	char to[] = "this is just a string ayyyayayy";

	for (i = 0; i < 10; ++i)
	{
		if (memcmp(Memmove(from , to, i), memmove(from , to, i), i) == 0)
		{
			printf("[OK] --- Memmove(): \n\toriginal: %s \n\tdestination: %s\n", from, to);
		}
		else
		{
			printf("[FAILED] --- Memmove(%s, %s, %d)\n", from, to, i);
		}
	}
}

int main()
{
    TestMemset();
    TestMemcpy();
	TestMemmove();

	return EXIT_SUCCESS;
}