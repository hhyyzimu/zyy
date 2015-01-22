#include <stdio.h>

int j = 1;

int main()
{
	static int i = 5;
	
	i = 10;
	j = 2;

	printf("i = %d, j = %d\n", i, j);

	return 0;
}
