#include <stdio.h>
#include <stdlib.h>

#define	N	4

int jc(int n)
{
	if(n == 0)
	{
		return 1;
	}
	return	n*jc(n-1);
}

int main()
{
	int result, i;
	i = N;

	result = jc(i);
	printf("%d的阶乘是：%d\n", i, result);

	exit(0);
}
