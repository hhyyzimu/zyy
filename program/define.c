#include <stdio.h>
#include <stdlib.h>

#define head(a) 	a ? 4 : 5

int main()
{
	int a = 0;
	int b = 0;
	
	b = head(a);
	printf("b = %d\n", b);

	exit(0);
}
