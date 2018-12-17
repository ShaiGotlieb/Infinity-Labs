#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ESC 27
#define LUT_SIZE 256

static void Empty(){} /* empty function */

static void Ifelse(char ch)
{
		if(ch == 'A' || ch == 'T')
		{
			printf("%c pressed\n", ch);
		}
}

static void Switchcase(char ch)
{	
		switch(ch)
		{
			case 'A':
				printf("%c pressed\n", ch);
				break;

			case 'T':
				printf("%c pressed\n", ch);
				break;
		}
}

static void PrintA()
{
	printf("A pressed\n");
}

static void PrintT()
{
	printf("T pressed\n");
}

static void Lut(int ch)
{
	static void (*ascii[LUT_SIZE])();
	int i = 0;

	/* fill ascii look up table with empty functions */
	for (i = 0; i < LUT_SIZE; ++i)
	{
		ascii[i] = Empty;
	}

	/* set functions 'PrintA' & 'PrintT' into LUT */
	ascii['A'] = PrintA;
	ascii['T'] = PrintT;

	
	(*ascii[ch])(); /* call function from LUT */
}

int main()
{
	char ch = 0;

	system("stty -icanon -echo"); /* stop terminal buffering & stop echoing keyboard pressing*/
	
	printf("Enter any character: \n");

	while(ch != ESC)
	{
		ch = getchar(); 

		Ifelse(ch);
		Switchcase(ch);
		Lut(ch);
	}

	system("stty icanon echo"); /* reset terminal to default state */

	return EXIT_SUCCESS;
}