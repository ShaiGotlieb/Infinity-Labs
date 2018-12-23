#include <stdio.h> /* printf() */
#include <stdlib.h> /* free() */
#include <string.h> /* strcat() */
#include <assert.h> /* assert() */
#include <limits.h> /* INT_MAX */

#define MAX_LINE 100000 
#define ARRAY_LENGTH(array) (sizeof((array))/sizeof((array)[0]))

struct struct_funcs
{
	void* data;
	void (*print)(struct struct_funcs *);
	void (*add)(struct struct_funcs *, int);
	void (*free_memory)(struct struct_funcs *);
};


void printInt(struct struct_funcs *s_item)
{
	assert(s_item);

	printf("int data = %d\n", *(int *)&s_item->data);
}

void printFloat(struct struct_funcs *s_item)
{
	assert(s_item);

	printf("float data = %f\n", *(float *)&s_item->data);
}

void printString(struct struct_funcs *s_item)
{
	assert(s_item);

	printf("string data = %s\n", (char *)s_item->data);
}

void addInt(struct struct_funcs *s_item, int num)
{
	assert(s_item);

	*(int *)&s_item->data += num; 
}

void addFloat(struct struct_funcs *s_item, int num)
{
	assert(s_item);

	*(float *)&s_item->data += num; 
}

void addString(struct struct_funcs *s_item, int num)
{
	char str[MAX_LINE];
	int size = 0;

	sprintf(str, "%d", num);
	size = strlen(s_item->data) + strlen(str) + 1;
	s_item->data = (char *)realloc((s_item->data), size);
	
	if(NULL == s_item->data)
	{
		printf("allocation failed");
		exit(EXIT_FAILURE);
	}
	
	assert(s_item);
	
	strcat(s_item->data, str);
}

void Freestr(struct struct_funcs *s_item)
{
	assert(s_item);

	free(s_item->data);
	s_item->data = NULL;
}

void FreeIntAndFloat(struct struct_funcs *s_item)
{
	s_item->data = 0;
}

void Init(int num, float f, char *string, int to_add)
{
	struct struct_funcs arr[3];
	int arr_size = ARRAY_LENGTH(arr);
	int i;

	char *str = calloc(sizeof(char), INT_MAX);

	if(NULL == str)
	{
		printf("allocation failed");
		exit(EXIT_FAILURE);
	}

	strcpy(str, string);

	*(int *)&(arr[0].data) = num;
	*(float *)&(arr[1].data) = f;
	arr[2].data = str;

	arr[0].add = addInt;
	arr[1].add = addFloat;
	arr[2].add = addString;

 	arr[0].print = printInt;
	arr[1].print = printFloat;
	arr[2].print = printString;

	arr[0].free_memory = FreeIntAndFloat;
	arr[1].free_memory = FreeIntAndFloat;
	arr[2].free_memory = Freestr;

 	for (i = 0; i < arr_size; ++i)
	{
		arr[i].add(&arr[i], to_add);
		arr[i].print(&arr[i]);
		arr[i].free_memory(&arr[i]);
	}
}

