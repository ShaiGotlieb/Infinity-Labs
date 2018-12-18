#include "initArr.h"

void WriteToFile(struct Contact contacts[])
{
	FILE *fp;
	fp = fopen(PATH, "wb");

	if (fp == NULL)
	{
		perror("Couldn't open file!\n");
		exit(1);
	}

	fwrite(contacts, sizeof(*contacts), SIZE, fp);

	fclose(fp);
}

void ReadFromFile(struct Contact contacts[])
{
	FILE *fp;
	fp = fopen(PATH, "rb");

	if (fp == NULL)
	{
		perror("Couldn't open file!\n");
		exit(1);
	}

	fread(contacts, sizeof(*contacts), SIZE, fp);

	fclose(fp);
}


void Init(struct Contact *contacts, struct Contact *contacts_copy)
{
	WriteToFile(contacts);
	ReadFromFile(contacts_copy);
}
