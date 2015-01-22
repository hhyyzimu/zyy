#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, j, result;

	printf("\n");

	for(i = 1; i < 10; i++)
	{
		for(j = 1; j < i+1; j++)
		{
			result = i*j;
			printf("%d * %d = %-3d", i, j, result);//%-3d表示左对齐，占3位
		}

		printf("\n");
	}

	exit(0);
}
