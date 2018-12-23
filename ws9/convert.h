#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h> /* INT_MAX */
#include <string.h> /* strlen() */

#define BYTE 8
#define INT_MAX_LENGTH 10
#define INT_MAX_STR "2147483647"
#define INT_MIN_STR "-2147483647" 
#define INT_MAX_BASE 32 
#define STRING 0 
#define INTEGER 1 

char *Reverse(char *str);
int IsValidString(const char *str);
char *Itoa(int value, char *str);
int Atoi(const char *str);
char *ConvertToStringBase(int num, char *str, int base);
int ConvertToIntBase(char *str, int base);