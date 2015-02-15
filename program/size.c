#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char *str = "0123456789";
	char str1[100] = "0123456789";
	char str2[] = "0123456789";
	int str3[100];

	printf("strlen(char *str = '0123456789') = %d\n", strlen(str));
	printf("sizeof(char *str = '0123456789') = %d\n", sizeof(str));

	printf("strlen(str1[100] = '0123456789') = %d\n", strlen(str1));
	printf("sizeof(str1[100] = '0123456789') = %d\n", sizeof(str1));

	printf("strlen(str2[] = '0123456789') = %d\n", strlen(str2));
	printf("sizeof(str2[] = '0123456789') = %d\n", sizeof(str2));

	printf("sizeof(str3[100] = '0123456789') = %d\n", sizeof(str3));

	exit(0);
}
