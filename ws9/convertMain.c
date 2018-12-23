#include "convert.h"

int main(void)
{
	char *str = "";
	char *str1 = "";
	char *str2 = "";
	str = Itoa(12345, str);
	printf("%s\n", str);
	free(str);
	printf("%d\n", Atoi("12345"));
	str1 = ConvertToStringBase(125,str1, 2);
	printf("%s\n", str1);
	free(str1);
	str2 = "125";
	printf("%d\n", ConvertToIntBase(str2, 2));

	return 0;
}