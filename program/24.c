/**/
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	int fp=0,sum=0;

	while(1)
	{
		fp=open("01.c",O_RDONLY);
		if(fp==-1)
		{
			break;
			}
		sum++;
		printf("fp=%d\n",fp);
	//	close(fp);
		}

	printf("sum=%d\n",sum);
	exit(1);
	}
