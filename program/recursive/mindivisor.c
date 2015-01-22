#include <stdio.h>
#include <stdlib.h>

#define	M	18
#define N	16

int MinDivisor(int m, int n)
{
	if(m%n == 0)
		return n;
	else
		return MinDivisor(n, m%n);
}

int main()
{
	int result;

	result = MinDivisor(M, N);
	printf("result = %d\n", result);

	exit(0);
}
