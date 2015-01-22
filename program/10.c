/*问题：p[0]可以改变指向*/
#include <stdio.h>
#include <string.h>

int main()
{
	char a[3][40]={
		"abcde",
		"xyz",
		"m"
		};
	char *p[3]={
		"abcde",
		"xyz",
		"m"
		};
	p[0]="qwert";
	char *pc="yuiop";
	pc="hjkl";
	int i=0;
	for(i=0;i<3;i++)
	{
		printf("a[%d]=%s\n",i,a[i]);
		}
	for(i=0;i<3;i++)
	{
		printf("p[%d]=%s\n",i,p[i]);
		}
	return 0;

	return 0;
	}
