#include <stdio.h>

int main()
{
	char a[40];
	char b[40];
	printf("a=");
	scanf("%s",a);
	printf("b=");
	scanf("%s",b);
	int i=0;
	for(i=0;a[i]!='\0' && b[i]!='\0';i++)	
	{
		if(a[i]!=b[i])
		{
			break;
			}
		else
		{
			continue;
			}
		}
	if(a[i]=='\0' && b[i]=='\0')
	{
		printf("相等\n");
		}
	else
	{
		printf("不相等\n");
		}

	return 0;
	}
