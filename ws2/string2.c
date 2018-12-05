#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <strings.h>
#include <ctype.h>

/* messages array to be tested*/
char *messages[] = {"Hello World!",  
						 "ThisIsReallyReallyLongWordWithouAnySpaces",
						 "	This string started with tab", 
						 "        This string started with 8 spaces", 
						 "This string ended with 8 spaces        ", 
						 "S", " "
						};

char *Strdup(const char * str) /*NIMROD: OK*/
{
	char *dest = (char *) malloc(strlen(str) + 100); /* allocate new memory for a string */

	if (dest == NULL) 
	{
		return NULL; /* could not allocate memory */
	}
	else
	{
		strcpy(dest, str);
	}

	return dest;
}

char *Strcat(char *dest, const char *src) /*NIMROD: OK */
{
	int dest_length = (int)strlen(dest);
	char *last = dest + dest_length; /* pointer to last element of 'dest'*/

	assert(dest && src);

	while(*src != '\0')
	{
		*last = *src;
		last++;
		src++;
	}

	*last = '\0'; /* mark the end of the string */

	return dest;
}

char *Strncat(char* dest, const char *src, size_t n) /*NIMROD: OK*/
{
	int source_length = strlen(src);
	int dest_length = strlen(dest);
	char *last = dest + dest_length; /* pointer to last element of 'dest'*/
	int until = n; /* number of characters to be appended */
	int i = 0;

	assert(dest && src);

	/* check validation length of sorce and number of chars to be appended*/
	if (until > source_length) 
	{
		strcat(dest, src);
	}

	while(i < until)
	{
		*last = *src;
		i++;
		last++;
		src++;
	}

	*last = '\0';

	return dest;
}

char *Strstr(const char *haystack, const char *needle)
{
	char *return_value = NULL;
	assert(haystack && needle);

	while(*haystack != '\0')
	{
		char *begin = (char *)haystack; /* pointer to beging of finding chars*/
		char *search = (char *)needle; /* search this sub-string*/
		char *next = (char *)haystack; /* pointer to move through string*/

		if(*next == *search)
		{
			begin = next; /* save the first occurence of matching chars*/
		}

		while(*next != '\0' && *search != '\0' && *next == *search) /* chars are matching*/
		{
			next++;
			search++;
		}

		if (*search == '\0')
		{
			return begin; /* pointer to beging of sub-string*/
		}

		haystack = next + 1; /* increament the outside loop*/
	}
	return return_value; /* substring not found*/
}


/* Tester for Strdup*/
void Teststrdup()
{
	int i;

	printf("\n******************Start Test strlen******************\n");

	for (i = 0; i < 7; i++)
	{
		char * Str_strdup = Strdup(messages[i]);
		if (strcmp(Str_strdup, messages[i]) == 0)
	{
		printf("OK! --- string duplicated successfuly\n");
	}
	else
	{
		printf("**ERROR!** --- could not duplicate string: %s\n", messages[i]);
	}
	}
	
}

/* Tester for Strcat*/
void Teststrcat()
{
	char dest[1000] = "The messages should be added now: ";
	char dest1[1000] = "The messages should be added now: ";

	int i;

	printf("\n******************Start Test strcat******************\n");

	for (i = 0; i < 5; i++)
	{
		Strcat(dest, messages[i]);
		strcat(dest1, messages[i]);

		if (strcmp(dest, dest1) == 0)
		{
			printf("OK! --- string was concatanated successfuly\n");
		}
		else
		{
			printf("**ERROR!** --- could not concatenate string: %s\n", messages[i]);
		}

	}
}

/* Tester for Strncat*/
void Teststrncat()
{
	char dest[1000] = "The messages should be added now: ";
	char dest1[1000] = "The messages should be added now: ";
	
	int appended_chars = 50;
	int i;

	printf("\n******************Start Test strncat******************\n");

	for (i = 0; i < 5; i++)
	{
		Strncat(dest, messages[i], appended_chars);
		strncat(dest1, messages[i], appended_chars);

		if (strcmp(dest, dest1) == 0)
		{
			printf("OK! --- string was concatanated successfuly\n");
		}
		else
		{
			printf("**ERROR!** --- could not concatenate string: %s\n", messages[i]);
		}
	}
}

/* Tester for Strstr*/
void Teststrstr()
{
	char *find[] = { "z", "Rea", "tab", "with", "end" }; /* find this substrings*/
	int i;

	printf("\n******************Start Test strstr******************\n");

	for (i = 0; i < 5; i++)
	{
		char *Strstr_return_value = Strstr(messages[i], find[i]);
		char *strstr_return_value = strstr(messages[i], find[i]);

		if (strcmp(Strstr_return_value, strstr_return_value) == 0)
		{
			printf("OK! --- text \"%s\" was found in text: \"%s\"\n 	result of pointer: %s\n", find[i], messages[i], Strstr_return_value);
		}
		else
		{
			printf("**ERROR!** --- could not find sub-string: %s in string: %s\n", find[i], messages[i]);
		}
	}
}

int main(void)
{
	Teststrdup();
	Teststrcat();
	Teststrncat();
	Teststrstr();

	return EXIT_SUCCESS;
}
