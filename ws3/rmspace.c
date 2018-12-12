#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>

void RmSpaces(char *str)
{
   char *result = str;
   int index = 0; /* index of current character position to be substract from pointer 'result'*/
   int found_space = 0; /* flag to indicate space */

   while(*str != '\0')
   {
      if (*str != ' ' && *str != '\t')
      {
         *result = *str;
         result++;
         index++;
         found_space = 1;
      }
      else if (found_space == 1)
      {
         *result = *str;
         result++;
         index++;
         found_space = 0;
      }
      str++;
   }

   *result = '\0';
   /* remove spaces from the end */
   while(*result == ' ' || *result == '\t' || *result == '\0')
   {
      *result = '\0';
      result--; 
      index--; 
   } 

   result -= index; /* set pointer to begining of string*/
   str = result; /* set original string to result */
}

void TestRmSpaces()
{
   char str[] = "    ABC   ABC       ";
   char result[] = "ABC ABC";

   RmSpaces(str);

   if (strcmp(result, str) == 0)
   {
      printf("OK! ---- RmSpaces succeed!\n");
   }
   else
   {
      printf("ERROR!\n");
   }
}

int main (void)
{
   TestRmSpaces();

   return EXIT_SUCCESS;
}

