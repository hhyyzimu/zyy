/*停车计费，前1小时免费，以后每小时50*/
#include <stdio.h>

int main()
{
	int t=0;
	int m=0;
	printf("输入停车时间：");
	scanf("%d",&t);
	if(t>1)
	{
		m=50*(t-1);
		}
	printf("停车费用：%d\n",m);

	return 0;
	}
