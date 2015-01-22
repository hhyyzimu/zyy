#include <stdio.h>

int main()
{
	char a[40]={'\0'};
	int i=0;
	printf("a=");
	scanf("%s",a);
	for(i=0;a[i]!='\0';i++);
	printf("i=%d\n",i);

	return 0;
	}
