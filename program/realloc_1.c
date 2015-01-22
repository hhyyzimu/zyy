#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *p;
	
//	clrscr();//clearscreen
	system("clear");

	p = (char *)malloc(100);
	if(p)
		printf("Memory Allocatedat:%p", p);
	else
		printf("Not Enough Memory!\n");

	getchar();

	p = (char *)realloc(p, 256);
	if(p)
		printf("Memory Reallocatedat:%p", p);
	else
		printf("Not Enough Memoty!\n");

	free(p);

	getchar();

//	printf("\n");

	exit(0);
}
