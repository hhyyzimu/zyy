#include <stdio.h>
#include <stdlib.h>

#define N	8

int main()
{
	int i,j,k;
	for(i = 0;i < N;i++)
	{
		for(j = 0;j <= i;j++ )
		{
			printf("*");
			for(k = 0;k < i;k++)
			{
				printf(".");
				}
			}
			printf("\n");
		}

	exit(0);
	}
