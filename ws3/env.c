#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define UNSUSED(x) (void)(x)

void PrintEnv(char *envp[])
{
	while (*envp != NULL)
	{
		puts(*envp);
		envp++;
	}
}

void FreeEnv(char **envp)
{
	char **envp_begin = envp;

	while(*envp != NULL)
	{
		free(*envp);
		*envp = NULL;
		envp++;
	}
	free(envp_begin);
	envp_begin = NULL;
}

static int CountEnv(char **envp)
{
	int count = 0;

	/* count size of envp */
	while(*envp != NULL)
	{
		envp++;
		count++;
	}

	return count;
}

static void EnvToLower(char **envp, char *buffer_str)
{
	char *current_char = *envp;

	while(*current_char != '\0')
	{
		*buffer_str = tolower(*current_char);
		buffer_str++;
		current_char++;
	}
	*buffer_str = '\0';
}

int main(int argc, char *argv[], char *envp[])
{
	int envp_size = 0;
	char *buffer_str;
	char *buffer_str_begin;
	char **envp_begin = envp;
	char **buffer;
	char **buffer_begin;

	UNSUSED(argc);
	UNSUSED(*argv);
	
	assert(envp);

	envp_size = CountEnv(envp);

	buffer = (char **)calloc((envp_size + 1), sizeof(*buffer));
	buffer_begin = buffer;
	
	/* check allocation */
	if (buffer == NULL)
	{
		puts("Allocation failed!\n");
		return EXIT_FAILURE;
	}

	while(*envp != NULL)
	{
		int str_length = strlen(*envp);
		buffer_str = (char *)calloc((str_length + 1), sizeof(*buffer_str));

		/* check allocation */
		if (buffer_str == NULL)
		{
			printf("Allocation failed!\n");
			return EXIT_FAILURE;
		}
		buffer_str_begin = buffer_str;
		
		EnvToLower(envp, buffer_str);

		*buffer = buffer_str_begin;
		buffer++;
		envp++;
	}
	
	*buffer = NULL; /* set last entery of buffer */

	PrintEnv(envp_begin);
	PrintEnv(buffer_begin);

	FreeEnv(buffer_begin);

	return EXIT_SUCCESS;
}