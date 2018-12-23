#include <stdio.h> 
#include <stdlib.h> /* EXIT_SUCCESS */

#define TRUE 1
#define FALSE 0
#define IS_LITTLE_ENDIAN ((unsigned char)(int)1) 
  
int IsLittleEndian()
{
	unsigned int num = 1; 
	char *address = (char*)&num; 

	if (0 != *address)
	{
    	return TRUE; 
	}     
	
	return FALSE;
}

void TestLittleEndian()
{
	int isLittleEndianMacro = IS_LITTLE_ENDIAN;
	int isLittleEndianFunc = IsLittleEndian();
	
	if ( isLittleEndianMacro == 1 && isLittleEndianFunc == 1)
	{
		printf("OK --- Your computer set to Little Endian\n");
	}
	else
	{
		printf("OK --- Your computer set to Big Endian\n");
	}

}

int main() 
{ 
	TestLittleEndian();
	
   return EXIT_SUCCESS; 
} 