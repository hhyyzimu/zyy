#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
#if 1
	char str[5];
	gets(str);
	puts(str);
#endif

#if 0
	int i;
	printf("argc = %d\n",argc);
	for(i=0;argv[i]!=NULL;i++)
		puts(argv[i]);
#endif

	exit(0);
	}
