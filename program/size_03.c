#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *ss = "0123456789";
	char ss1[] = "0123456789";
	char ss2[100] = "0123456789";
//	int ss3[100] = "0123456789";

	printf("ss = '0123456789\n'");
	printf("sizeof(ss) = %d\n", sizeof(ss));
	printf("sizeof(*ss) = %d\n", sizeof(*ss));

	printf("ss1[] = '0123456789'\n");
	printf("sizeof(ss1) = %d\n", sizeof(ss1));
	printf("strlen(ss1) = %d\n", strlen(ss1));

	printf("ss2[100] = '0123456789'\n");
	printf("sizeof(ss2) = %d\n", sizeof(ss2));
	printf("strlen(ss2) = %d\n", strlen(ss2));

	/*
	printf("ss3[100] = '0123456789'\n");
	printf("sizeof(ss3) = %d\n", sizeof(ss3));
	printf("strlen(ss3) = %d\n", strlen(ss3));
	*/

	char q[] = "abc";
	char p[] = "a\n";
	printf("sizeof(q) = %d\n", sizeof(q));
	printf("sizeof(p) = %d\n", sizeof(p));
	printf("strlen(q) = %d\n", strlen(q));
	printf("strlen(p) = %d\n", strlen(p));

	exit(0);
}
