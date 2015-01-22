/*输入年份，判断是不是润年*/
#include <stdio.h>

int main()
{
	int year = 0;
	printf("Please input the year:");
	scanf("%d",&year);
	if(year%4!=0)//由于平年多于润年，所以先判断平年可以减少循环
	{
		printf("%d年不是润年\n",year);	
		}
	else if(year%100==0)
	{
		if(year%400==0)
		{
			printf("%d年是润年\n",year);
			}
		else
		{
			printf("%d年不是润年\n",year);
			}
		}
	else
	{
		printf("%d年是润年\n",year);
		}

	return 0;
	}
