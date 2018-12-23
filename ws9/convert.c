#include "convert.h"

/* function to reverse a string - use for 'Itoa' function */
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

char *Itoa(int value, char *str)
{
	char *str_ptr;
	int isNegative = 0;

	/* handle negative*/
	if (value < 0)
	{
		isNegative = 1;
		value *= -1;
	}
	else if (value == 0)
	{
		return "0";
	}

	str = (char *)malloc(INT_MAX_LENGTH + isNegative + 1);
	if (str == NULL)
	{
		printf("Allocation failed\n");
		exit(EXIT_FAILURE);
	}
	str_ptr = str;

	while(value != 0)
	{
		*str_ptr = (value % 10) + '0'; /* get last digit */
		value /= 10; /* remove last digit */
		str_ptr++;
	}

	if (isNegative == 1)
	{
		*str_ptr = '-'; /* add negative sign */
		str_ptr++;
	}
	*str_ptr = '\0'; 

	str = Reverse(str);

	return str;
}

/* function that dertermain wether a string can be a valid integer used in 'AtoI'*/
int IsValidString(const char *str)
{
	int length = strlen(str) - 1;

	if (length >= INT_MAX_LENGTH && (strcmp(str, INT_MAX_STR) > 0 || strcmp(str, INT_MIN_STR) < 0))
	{
		perror("Trying to convert number bigger/smaller than integer can store: "); /* change success print to failed */
		return 0;
	}

	return 1;
}

int Atoi(const char *str)
{
	int length = strlen(str) - 1;
	int result = 0;
	int isNegative = 0;
	int result_length = 1;
	char *first = (char *)str;
	char *last = (char *)str + length;
	char current;

	if (IsValidString(str) == 0)
	{
		exit(EXIT_FAILURE);
	}

	if (*first == '-')
	{
		isNegative = 1;
		first++;
	}

	while(first <= last)
	{
		current = *first;
		result += current - '0';
		if (result_length < INT_MAX_LENGTH)
		{
			result *= 10;
		}
		first++;
		result_length++; 
	}

	if (result_length <= INT_MAX_LENGTH)
	{
		result /= 10; /* remove last unnecasary digit */
	}

	return isNegative == 0 ? result: -result;

}

char *ConvertToStringBase(int num, char *str, int base)
{
	int converted_number[32];
	int i = 0;
	int remainder = 0;
	char *str_ptr;
	
	str = (char *)malloc(INT_MAX_BASE);
	if (str == NULL)
	{
		printf("Allocation failed\n");
		exit(EXIT_FAILURE);
	}
	str_ptr = str;
  
    while (num > 0) 
    {
        remainder = num % base; 
        num /= base; 
        converted_number[i] = remainder; 
        i++;
    }


	for (i -= 1; i >= 0; i--)
	{
    	char current = converted_number[i] + '0';
    	*str_ptr = current;
    	str_ptr++;
    }
    *str_ptr = '\0';

	return str;
}

int ConvertToIntBase(char *str, int base)
{
	int converted_number[32];
	int i = 0;
	int number = 0;
	int remainder = 0;
	int num = Atoi(str);
	char *str_ptr;
	
	str = (char *)malloc(INT_MAX_BASE);
	if (str == NULL)
	{
		printf("Allocation failed\n");
		exit(EXIT_FAILURE);
	}
	str_ptr = str;
  
    while (num > 0) 
    {
        remainder = num % base; 
        num /= base; 
        converted_number[i] = remainder; 
        i++;
    }

    for (i -= 1; i >= 0; i--)
	{
	    char current = converted_number[i] + '0';
	    *str_ptr = current;
		str_ptr++;
	}

    *str_ptr = '\0';
    number = atoi(str);
    free(str);
    str = NULL;
    return number;
}