#include <stdio.h>

int strlen1(char *str)
{
	int i=0;
	for(i=0;str[i]!='\0';i++);
	return i;
	}

int main()
{
	char a[40]={'\0'};
	printf("a=");
	scanf("%s",a);
	int x=strlen1(a);
	printf("x=%d\n",x);

	return 0;
	}
