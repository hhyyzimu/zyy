#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int i, j, k;
	int num = 0;
	int s, a;

	printf("\n");
	for(i = 1; i < 5; i++)
	{
		for(j = 1; j < 5; j++)
		{
			for(k = 1; k < 5; k++)
			{
				if(i!=k && i!=j && j!=k)
				{
					num +=1;
					s = i*100 + j*10 + k;
					printf("%d\t", s);
					if((num%8) == 0)
					{printf("\n");}
				}
			}
		}
	}

	printf("\n共有%d个，结果如上\n", num);

	exit(0);
}
