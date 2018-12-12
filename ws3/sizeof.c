#include <stdio.h>
#include <stdlib.h>

void PrintType(char **types, int *types_size, int size)
{
	
	int i;

	for (i = 0; i < size; ++i)
	{
		printf("%s: %d\n", types[i], types_size[i]);
	}
}

int main(void)
{
	char *types[] = {"int", "signed int", "unsigned int", "short", "short int", "signed short", "signed short int", "unsigned short", 
				"unsigned short int", "long", "long int", "signed long", "unsigned long", "unsigned long int", 
				"long int", "float", "double", "long double", "char", "signed char", "unsigned char", "*void", "size_t" };
	int types_size[23];
	int size = sizeof(types) / sizeof (types[0]);

	types_size[0] = sizeof(int);
	types_size[1] = sizeof(signed int);
	types_size[2] = sizeof(unsigned int);
	types_size[3] = sizeof(short);
	types_size[4] = sizeof(short int);
	types_size[5] = sizeof(signed short);
	types_size[6] = sizeof(signed short int);
	types_size[7] = sizeof(unsigned short); 
	types_size[8] = sizeof(unsigned short int);
	types_size[9] = sizeof(long);
	types_size[10] = sizeof(long int);
	types_size[11] = sizeof(signed long);
	types_size[12] = sizeof(unsigned long);
	types_size[13] = sizeof(unsigned long int);
	types_size[14] = sizeof(long int);	
	types_size[15] = sizeof(float);
	types_size[16] = sizeof(double);
	types_size[17] = sizeof(long double);
	types_size[18] = sizeof(char);
	types_size[19] = sizeof(signed char);
	types_size[20] = sizeof(unsigned char);
	types_size[21] = sizeof(void*);
	types_size[22] = sizeof(size_t);

	PrintType(types ,types_size, size);

	return EXIT_SUCCESS;
}