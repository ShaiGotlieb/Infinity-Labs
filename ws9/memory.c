#include "memory.h"

void *Memset(void *str, int c, size_t n)
{
	unsigned char *ptr_char = (unsigned char *)str;
	unsigned long *ptr_long = (unsigned long *)ptr_char;
	unsigned long word = 0;
	int long_size = sizeof(unsigned long);
	int i = 0;

	/* create word to be inserted */
    while(i < long_size)
	{
		word = word << BYTE;
		word = word | (unsigned char)c;
		i++;
	}

	/*handle left align */
	while (((unsigned long)ptr_char & MASK) != 0 && n > 0)
	{
		*ptr_char = (unsigned char)c;
		ptr_char++;
		n--;
	}
	
	/* major chunk */
	while (n >= BYTE)
	{
		*ptr_long = word;
		n -= BYTE;
		ptr_long++;
	}
	
	ptr_char = (unsigned char *)ptr_long; /* set ptr_char to last location of ptr_long */
	/* handle right align */
	while (n > 0)
	{
		*ptr_char = (unsigned char)c;
		ptr_char++;
		n--;
	}

	return str;
}

void *Memcpy(void *str1, const void *str2, size_t n)
{
	unsigned char *char1 = (unsigned char*)str1;
	unsigned char *char2 = (unsigned char*)str2;
	unsigned long *word1;
	unsigned long *word2;


	while ((((unsigned long)char1 & MASK)) != 0 && (n > 0))
	{
		*char1 = *char2;
		char1++;
		char2++;
		n--;
	}

	word1 = (unsigned long*)char1;
	word2 = (unsigned long*)char2;
	while (n >= BYTE)
	{
		*word1 = *word2;		
		n -= BYTE;
		word1++;
		word2++;
	}
	
	char1 = (unsigned char*)word1;
	char2 = (unsigned char*)word2;
	while (n > 0)
	{
		*char1 = *char2;
		char1++;
		char2++;
		n--;
	}

	return str1;
}

void *Memmove(void *str1, const void *str2, size_t n)
{
	unsigned long *word1;
	unsigned long *word2;
	unsigned char *char1;
	unsigned char *char2;

	if ((unsigned long)str1 < (unsigned long)str2)
	{
		return memcpy(str1, str2, n);
	}

	/* set to last */
	char1 = (unsigned char*)str1 + n - 1;
	char2 = (unsigned char*)str2 + n - 1;
	while (n % BYTE != 0)
	{
		*char1 = *char2;
		char1--;
		char2--;
		n--;
	}

	word1 = (unsigned long*)char1;
	word2 = (unsigned long*)char2;
	while (n > 0)
	{
		*word1 = *word2;		
		word1--;
		word2--;	
		n = n - BYTE;
	}

	return str1;
}
