#include <stdio.h>
#include <stdlib.h>

int num[5] = {0};

void insertion_sort(void)
{
	int i, j, key;
	for(j=1; j<5; ++j )
	{
		printf("%d, %d, %d, %d, %d\n", num[0], num[1], num[2], num[3], num[4]);
		key = num[j];
		i = j-1;
		while(i>=0 && num[i]>key)
		{
			num[i+1] = num[i];
			--i;
		}
		num[i+1] = key;
	}
	printf("%d, %d, %d, %d, %d\n", num[0], num[1], num[2], num[3], num[4]);
}

int main()
{
	printf("Please input five numbers:");
	scanf("%d%d%d%d%d", &num[0], &num[1], &num[2], &num[3], &num[4]);
	
	insertion_sort();

	exit(0);
}
