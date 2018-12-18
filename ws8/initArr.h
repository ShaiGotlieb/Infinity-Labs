#include <stdio.h>
#include <stdlib.h> /* EXIT_SUCCESS */
#include <string.h> /* strcmp() */

#define PATH "/home/ol62/git/c/ws8/contacts"
#define SIZE 10

struct DateOfBirth
{
	size_t day;
	size_t month;
	size_t year;
};

struct Contact
{
	char f_name[50];
	char l_name[50];
	struct DateOfBirth dob;
	size_t ID;	
};

void Init(struct Contact *contacts, struct Contact *contacts_copy);
void WriteToFile(struct Contact contacts[]);
void ReadFromFile(struct Contact contacts[]);
void IsSame(struct Contact *contacts1, struct Contact *contacts2);
