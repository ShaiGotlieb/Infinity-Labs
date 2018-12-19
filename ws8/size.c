#include <stdio.h>

#define SIZEOF(a) ((size_t)(&(a)+1)-(size_t)(&(a))) 
#define TYPEOF(a) (size_t)(1 + ((a*)0)) 

int main()
{
	union Numbers
	{
		int i;
		float f;
		double d;
	};

	struct X
	{
		int i;
		char c;
		double d;
		short s;
	};

	struct Card
	{
		unsigned int suit : 2;
		unsigned int face : 4;
	};

	union Numbers numbers;
	struct X x;
	struct Card card;

	int a = 18;
	double b = 8.45;

	card.suit = 8;
	card.face = 100;

	int sizea = SIZEOF(a);
	int sizeb = SIZEOF(b);
	int typea = TYPEOF(int);
	int typeb = TYPEOF(char);

	printf("%d\n", sizea);
	printf("%d\n", sizeb);
	printf("%d\n", typeb);
	
	printf("%d\n", sizeof(numbers));
	printf("%d\n", sizeof(x));
	printf("%d\n", sizeof(card));
	printf("%d\n", sizeof(unsigned int));

	return 0;
}
