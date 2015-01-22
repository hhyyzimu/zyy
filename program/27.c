/*求以下表达式的值：1-2+3-4*/
#include <stdio.h>
#include <stdlib.h>

#define N	7

int main()
{
	int sum = 0,i = 0;

	for(i = 1;i <= N;i++)
	{
		if((i % 2 == 1))
			sum += i;
		else
			sum -= i;
		}

	printf("%d\n",sum);
	exit(1);
	}
