#include <stdio.h>

static char *my_strcpy()
{
	
	}

int main()
{
	char a[40];
	char b[40];
	printf("a=");
	scanf("%s",a);
	int i=0;
	for(i=0;a[i]!='\0';i++)
	{
		b[i]=a[i];
		}
	b[i]='\0';
	printf("b=%s\n",b);
	return 0;
	}
