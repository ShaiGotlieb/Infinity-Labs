#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *Reverse(char *str)
{
    char tmp_char, *front, *back;

    if(!str || !*str)
        return str;

    for(front = str, back = str + strlen(str)-1; front < back; front++, back--)
    {
        tmp_char =*front;
        *front=*back;
        *back = tmp_char; 
    }

    return str;
}

char *Addition(char *number1, char *number2)
{
	int index = 0;
	int max = 0; /* max length */
	int i = 1; /* index to indicate the position of characters from the end of the string */
	int remainder = 0;
	
	int number1_size = strlen(number1);
	int number2_size = strlen(number2);

	char *result = (char *)malloc(number1_size + number2_size);
	
	/* check allocation */
	if (result == NULL)
	{
		printf("Allocate memory faild!\n");
		return NULL;
	}

	*result = '\0';

	/* check input - number cannot start with '0' or negative */
	if (*number1 == '0' || *number2 == '0' || *number1 == '-')
	{
		printf("Please enter a valid number! (Number must start with positive digit)\n");
		return NULL;
	}
	
	/*check max length*/
	if (number1_size >= number2_size)
	{
		max = number1_size;
	}
	else
	{
		max = number2_size;
	}


	while(index < max)
	{
		/* get the last character of string */
		char last1 = *(number1 + number1_size - i); 
		char last2 = *(number2 + number2_size - i);

		int num1 = 0;
		int num2 = 0;

		int added_numbers = 0;
		int current_digit = 0;
		

	/* set numbers to their value only if they still have digits */
	if(number1_size - index > 0)
	{
		num1 = last1 - '0'; /* convert char to int */
	}
	if(number2_size - index > 0)
	{
		num2 = last2 - '0'; 
	}

	added_numbers = num1 + num2 + remainder;
	remainder = 0; /* reset remainder after use */
	current_digit = (added_numbers % 10); /* get last digit */

		/* 2 digits number */
		if (added_numbers > 9)
		{
			*result = current_digit + '0'; 
			remainder = (added_numbers/10) % 10; /* tens digit */
		}
		else
		{
			*result = added_numbers +  '0'; 
		}
		result++; 
		index++;
		i++;
	}

	/* add remainder to the MSD (result number of digits bigger than original size) */
	*result = remainder + '0';

	/* check if last digit is 0 -> invalid*/
	if (*result == '0')
	{
		*result = '\0';
	}

	result = result - index; /* reset pointer to begining of string */
	result = Reverse(result); /* flip the result */

	return result;
}

int main(void)
{
	char number1[] = "9999999999";
	char number2[] = "123456789101112";
	char *result = Addition(number1, number2);

	printf("a = %s b = %s | a + b = %s\n", number1, number2, result);

	free(result);

	return 0;
}