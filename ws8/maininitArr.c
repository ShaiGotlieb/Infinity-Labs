#include "initArr.h"

void IsSame(struct Contact *contacts1, struct Contact *contacts2)
{
	int i;
	for (i = 0; i < SIZE; ++i)
	{
		if (strcmp(contacts1[i].f_name, contacts2[i].f_name) == 0 && 
			strcmp(contacts1[i].l_name, contacts2[i].l_name) == 0 &&
			contacts1[i].ID == contacts2[i].ID &&
			contacts1[i].dob.day == contacts2[i].dob.day && 
			contacts1[i].dob.month == contacts2[i].dob.month &&
			contacts1[i].dob.year == contacts2[i].dob.year)
		{
			printf("ok: %d\n", i);
		}
		else
		{
			printf("ERROR: %d\n", i);
		}
	}
}

int main()
{
	struct Contact contacts[] = {{"Shai", "Gotlieb", {20,12,1990}, 305465924 },
								{"Ran", "Lazd", {21,02,1991}, 305165924 },
								{"Nimrod", "Zilber", {22,03,1992}, 305265924 },
								{"Benji", "Amram", {23,04,1993}, 305365924 },
								{"Reut", "Hambur", {24,05,1994}, 304465924 },
								{"Dan", "Deman", {25,06,1995}, 305565924 },
								{"Eytan", "Mich", {26,07,1996}, 305665924 },
								{"Steve", "Nash", {27,10,1997}, 305765924 },
								{"David", "Goliat", {07,10,1998}, 305865924 },
								{"Dudu", "Didi", {29,11,1999}, 305965924 }};
	struct Contact contacts_copy[SIZE];	
	Init(contacts, contacts_copy);
	IsSame(contacts, contacts_copy);
	return EXIT_SUCCESS;
}