#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNSUSED(x) (void)(x)

#define PATH "/home/ol62/git/c/ws5/"
#define TRUE 1
#define FALSE 0
#define SIZE 200

enum status {SUCCESS, FAILED, EXIT};

struct command 
{
	char *cmd;
	int (*is_match)(const char *, const char *);
	enum status (*execute)(const char *, const char *);
};


static void checkFOpen(FILE *fp)
{
	if (fp == NULL)
	{
		perror("Couldn't open file!\n");
	}
}

static void GetInput(char *input)
{
	fgets(input, SIZE, stdin);
}

/* add file name to 'path' */
static void MakePath(char *path, const char *file_name)
{
	if (file_name != NULL)
	{
		strcat(path, file_name); 
	}
	else
	{
		strcat(path, "default.txt"); /* file name not given as an argument - make default name */
	}
}

int Comparison(const char *cmd, const char *input)
{
	if (strstr(input, cmd) != NULL) 
	{
		return TRUE;
	}
	return FALSE;
}

/* check if input starts with '<' */
int isBegin(const char *cmd, const char *input)
{
	if (input[0] == cmd[0])
	{
		return TRUE;
	}
	return FALSE;
}

int True(const char* cmd, const char *input)
{
	UNSUSED(cmd);
	UNSUSED(input);
	return TRUE;
}

enum status HandleFile(const char *file_name, const char *input)
{
	char path[SIZE] = PATH;
	FILE *fp;
	
	MakePath(path, file_name);
	fp = fopen(path, "a+"); 
	checkFOpen(fp);
	fputs(input, fp);
	fclose(fp);

	return SUCCESS;
}

enum status Exit(const char *cmd, const char *input)
{
	UNSUSED(cmd);
	UNSUSED(input);
	return EXIT;
}

enum status Count(const char *file_name, const char *input)
{
	char path[SIZE] = PATH;
	FILE *fp; 
	int current;
	int lines = 0; 

	MakePath(path, file_name);
	fp = fopen(path, "r");
	checkFOpen(fp);

	while ((current = fgetc(fp)) != EOF)
  	{
  		if (current == '\n')
    	{
    		lines++;
    	}
  	}
	printf("There are: %d lines in the file\n", lines);
	
	fclose(fp);

	UNSUSED(input);
	return SUCCESS;
}
	
enum status Remove(const char *file_name, const char *input)
{	
	char path[SIZE] = PATH;
	int status = 0;
	
	MakePath(path, file_name);
	status = remove(path);

	if (status == 0)
	{
		printf("File: %s deleted successfuly!\n", path);
	}
	else
	{
		printf("File: %s Could not be deleted!", path); /* Faild to delete */
		return FAILED;

	}

	UNSUSED(input);
	return SUCCESS;
}

enum status AppendToBegin(const char *file_name, const char *input)
{
	const char *fname_tmp = "tmp.txt";
	char path[SIZE] = PATH;
	char tmp_file[SIZE] = PATH;
	char current;
	FILE *fp;
	FILE *ftmp;
	
	/* create new file (tmp.txt) with user input without '<' */
	HandleFile(fname_tmp, (input+1));
	
	MakePath(tmp_file, fname_tmp);
	MakePath(path, file_name);
	
	fp = fopen(path, "a+");
	ftmp = fopen(tmp_file, "a+");
	
	checkFOpen(fp);
	checkFOpen(ftmp);

	/* copy data from original file to temporary file */
	while ((current = fgetc(fp)) != EOF)
    	fputc(current, ftmp);

    fclose(ftmp);
    fclose(fp);

	/* rename the temporary file to replace the original file */
	rename(tmp_file, path);

	return SUCCESS;
}



enum status Logger(const char *file_name)
{
	const struct command commands[] = 
								{ {"-exit"  , Comparison, Exit},
							 	  {"-remove", Comparison, Remove},
							 	  {"-count" , Comparison, Count},
							 	  {"<"      , isBegin   , AppendToBegin},
							 	  {"true"   , True      , HandleFile} };
	const int size = sizeof(commands) / sizeof(commands[0]);
	char input[SIZE];
	enum status status = SUCCESS;
	int i = 0;

	printf("Please enter strings. When done enter '-exit' butten\n");
	while (status != EXIT || status != FAILED)
	{	
		GetInput(input);

		for (i = 0; i < size; ++i)
		{
			if (commands[i].is_match(commands[i].cmd, input))
			{
				status = commands[i].execute(file_name, input);
				if (status == EXIT)
				{
					return TRUE;
				}
				break; /* a function has been execute */
			}
		}
	}

	return FALSE;
}

int main(int argc, char const *argv[])
{
	UNSUSED(argc);

	return Logger(argv[1]);
}