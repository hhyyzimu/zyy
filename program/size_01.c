/*
 *4
 *4
 * */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *p = NULL;

	p = malloc(100);

	printf("%d\n", sizeof(p));
	printf("%d\n", sizeof(*p));

	return 0;
}
