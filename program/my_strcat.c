#include <stdio.h>

int main()
{
	char a[80]={'\0'};
	char b[40]={'\0'};

	int i=0;
	int j=0;
	printf("a=");
	scanf("%s",a);
	printf("b=");
	scanf("%s",b);
	for(i=0;a[i]!='\0';i++);
	for(j=0;b[j]!='\0';i++,j++)
	{
		a[i]=b[j];
		}
	a[i]='\0';
	printf("a=%s\n",a);

	return 0;
	}
