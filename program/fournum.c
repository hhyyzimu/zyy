#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 0, j = 0, k = 0, sum = 0, s = 0;
	
	for(i = 1; i < 5; i++)	
{
		for(j = 1; j < 5; j++)
{
			for(k = 1; k < 5; k++)
{
				if(i != j && i != k && j != k)
{
					sum++;
					s = i*100 + j*10 + k;
					printf("the number is: %d\n", s);
}
}
}
}
	printf("total is: %d\n", sum);

	exit(0);
}
