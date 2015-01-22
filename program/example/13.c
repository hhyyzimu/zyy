#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, j, k, n, sum = 0;

	for(n=100; n<1000; n++)
	{
		i = n/100;
		j = n%100/10;
		k = n%10;

		if(i*i*i + j*j*j + k*k*k == n)
		{
		//	sum++;
			++sum;
			printf("%d = %d\n", sum, n);
		}
	}

	printf("\n");

	exit(0);
}
