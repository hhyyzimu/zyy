#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv)
{
	int i = 0, num = 0;
	//num = *argv[1];

	if(argc != 2)
	{
		printf("I will print the errro number from 0 to your input, please input the number of end: ");
		scanf("%d", &num);
	}

	for(i = 0; i < num; i++)
	{
		printf("errno: %02d is : %s\n",i, strerror(i));
	}

	return 0;
}
