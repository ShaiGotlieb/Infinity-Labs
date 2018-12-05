#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int IsPalindrome(const char *str)
{
	int str_length = (int)strlen(str);
	char *left = (char *)str; /* first character in string */
	char *right = (char *)str + str_length - 1; /* last character in string */

	while (left < right)
	{
		if (*left == *right)
		{
			left++;
			right--;
		}
		else
		{
			return 0; /* not a palindrome */
		}
	}
	return 1; /* is a palindrome*/
}

void TestPalindrome()
{
	char *words[] = {"aabbaa", "aba", "a", "ap", "aabbcbbaaa", "aabbcbbaa"};
	int i;

	for (i = 0; i < 6; i++)
	{
		int result = IsPalindrome(words[i]);

		if (result == 1)
		{
			printf("OK! --- %s is a palindrome\n", words[i]);
		}
		else
		{
			printf("OK! --- %s is NOT palindrome\n", words[i]);
		}
	}
}

int main (void)
{
	TestPalindrome();
	
	return EXIT_SUCCESS;
}