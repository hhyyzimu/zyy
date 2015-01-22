#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;
	int *pn = (int *)calloc(10, sizeof(int));

	for(i=0; i<10; i++)
		printf("%d", pn[i]);

	printf("\n");

	free(pn);

	exit(0);
}
