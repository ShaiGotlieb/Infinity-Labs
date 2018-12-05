#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <strings.h>
#include <ctype.h>

/* messages array to be tested*/
char *messages[] = {"Hello World!", "S", " ", 
						 "ThisIsReallyReallyLongWordWithouAnySpaces",
						 "	This string started with tab", 
						 "        This string started with 8 spaces", 
						 "This string ended with 8 spaces        " 
						};

size_t Strlen(const char *str_ptr)
{
	size_t length = 0;

	assert(str_ptr);

	while (*str_ptr != '\0')
	{
		length++;
		str_ptr++;
	}

	return length;
}

int Strcmp(const char *txt1, const char *txt2)
{
	assert(txt1 && txt2);

	while (*txt1 == *txt2 && *txt1 != '\0')
	{
			txt1++;
			txt2++;
	}

	return *txt1 - *txt2; /* 0 -> strings are equal | negative -> left is less | positive -> right is less*/

}

char *Strcpy(char *dest, const char *src)
{
	assert(src);
	assert(dest);

	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}

	*dest = '\0';

	return dest;
}

char *Strncpy(char *dest, const char *src, int n)
{
	int size_counter = 0;

	assert(src);
	assert(dest);

	while (size_counter < n && *src != '\0') /* size_counter can be bigger than number of characters to be copied*/
	{
		if (*src == '\0')
		{
			dest = NULL; /*  In a case where the length of source is less than that of n, the remainder of dest will be padded with NULL */
		}

		*dest = *src;
		src++;
		dest++;
		size_counter++;
	}
	/* pad with \0 */
	while ( size_counter < n)
	{
		*dest = '\0';
		size_counter++;
		dest++;
	}
	
	return dest;
}

int Strcasecmp(const char *str1, const char *str2)
{
	assert(str1 && str2);

	while (tolower(*str1) == tolower(*str2) && *str1 != '\0')
	{
		str1++;
		str2++;
	}

	return tolower(*str1) - tolower(*str2);
}

char *Strchr(const char * str, int c)
{
	char *str_ptr = (char *)str; /* casting in order to use pointer to const*/
	
	assert(str != NULL);

	while (*str_ptr != '\0')
	{
		if (*str_ptr == c)
			return str_ptr; /* found */
			
		str_ptr++;
	}

	return NULL; /* not found*/
}


/* Tester for strlen*/
void TestStrlen()
{
	int i;

	printf("\n******************Start Test strlen******************\n");

	for (i = 0; i < 7; i++)
	{
		int length = strlen(messages[i]);
		int my_length = Strlen(messages[i]);

		if (my_length == length)
		{
			printf("OK! --- text: %s\n length = %d should be: %d \n", messages[i], my_length, length);
		}
		else
		{
			printf("**ERROR!** --- text: %s\n length = %d should be: %d \n", messages[i], my_length, length);
		}
	}
}

/* Tester for strcmp*/
void TestStrcmp()
{
	int return_value_strcmp = strcmp(messages[0], "Hello World"); /* string.h */
	int return_value_Strcmp = Strcmp(messages[0], "Hello World"); /* my Strcmp */

	printf("\n******************Start Test strcmp******************\n");

	if (return_value_Strcmp == return_value_strcmp)
	{
		printf("OK! --- text are equal\n");
	}
	else 
	{
		printf("**ERROR!** --- TEXT ARE NOT EQUAL! problem in text: %s\n", messages[0]);
	}

}

/* Tester for strcpy*/
void TestStrcpy()
{
	char *source = messages[0];
	char dest[100];
	char dest1[100];

	printf("\n******************Start Test strcpy******************\n");

	Strcpy(dest, source);
	strcpy(dest1, source);
	if (strcmp(dest, dest1) == 0)
	{
		printf("OK! --- source: %s destination: %s\n", source, dest);
	}
	else
	{
		printf("**ERROR!** --- Unable to copy source! problem in text: %s\n", messages[0]);
	}
	
}


/* Tester for strncpy*/
void TestStrncpy()
{
	char *source = messages[0];
	char dest[100] = {'\0'};
	char dest1[100] = {'\0'};

	printf("\n******************Start Test strncpy******************\n");

	Strncpy(dest, source, 12);
	strncpy(dest1, source, 12);

	if (strcmp(dest, dest1) == 0)
	{
		printf("OK! --- source: %s destination: %s\n", source, dest);
	}
	else
	{
		printf("**ERROR!** --- Unable to copy source! problem in text: %s\n", messages[0]);
	}
}

/* Tester for Strcasecmp*/
void Teststrcasecmp()
{
	int return_value_strcasecmp = strcasecmp(messages[0], "HELLO WORLD!");
	int return_value_Strcasecmp = Strcasecmp(messages[0], "HELLO WORLD!");

	printf("\n******************Start Test Strcasecmp******************\n");

	if (return_value_Strcasecmp == return_value_strcasecmp)
	{
		printf("OK! --- return value should be: %d and is: %d\n", return_value_strcasecmp, return_value_Strcasecmp);
	}
	else
	{
		printf("**ERROR!** --- strings are not equal in function Strcasecmp()\n");
	}
	
}

/* Tester for Strchr*/
void Teststrchr()
{
	char characters[] = {'o', 'S', ' ', 'l', 'd', 'p', 't'};
	int i;

	printf("\n******************Start Test Strchr******************\n");

	for (i = 0; i < 7; i++)
	{
		char *strchr_ptr = strchr(messages[i], characters[i]);
		char *Strchr_ptr = Strchr(messages[i], characters[i]);

		if (Strchr_ptr == strchr_ptr && strchr_ptr && Strchr_ptr)
		{
			printf("OK! --- found character: \'%c\' in: %s\n", characters[i], messages[i]);
		}
		else
		{
			printf("**ERROR!** --- could not find character: \'%c\'\n", characters[i]);
		}
	}
}

int main(void)
{
	TestStrlen();
	TestStrcmp();
	TestStrcpy();
	TestStrncpy();
	Teststrcasecmp();
	Teststrchr();

	return EXIT_SUCCESS;
}