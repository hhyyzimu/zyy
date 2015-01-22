#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;

	int *pn = (int *)malloc(5*sizeof(int));//分配了5个整形的空间
	printf("malloc:%p\n", pn);
	for(i=0; i<5; i++)
		pn[i]=i;

	pn = (int *)realloc(pn, 10*sizeof(int));//在原来的基础上重新分配，共10各整形空间的大小，如果原来的地址不够会从别的地方重新找个10个整形大小的空间
	printf("realloc:%p\n", pn);
	for(i=5; i<10; i++)
		pn[i]=i;

	for(i=0; i<10; i++)
		printf("%3d\n", pn[i]);

	free(pn);

	exit(0);
}
