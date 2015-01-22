/*数组实现随机出题，升级版*/
#include <stdio.h>

int main()
{
	int n=0;
	srand(time(NULL));
	printf("本次测试题数：");
	scanf("%d",&n);

	int i=0;
	int a[n];
	int b[n];
	int c[n];
	int d[n];
	int e[n];
	int sum=0;
	int f=0;

	for(i=0;i<n;i++)//根据测试题数出题并保存学生答案和正确答案
	{
		a[i]=rand()%100;
		b[i]=rand()%4;
		c[i]=rand()%100;
		if(b[i]==0)
		{
			printf("%d+%d=",a[i],c[i]);
			scanf("%d",&d[i]);
			e[i]=a[i]+c[i];
			}
		else if(b[i]==1)
		{
			printf("%d-%d=",a[i],c[i]);
			scanf("%d",&d[i]);
			e[i]=a[i]-c[i];
			}
		else if(b[i]==2)
		{
			printf("%d*%d=",a[i],c[i]);
			scanf("%d",&d[i]);
			e[i]=a[i]*c[i];
			}
		else
		{
			printf("%d/%d=",a[i],c[i]);
			scanf("%d",&d[i]);
			e[i]=a[i]/c[i];
			}
		}
	
	for(i=0;i<n;i++)
	{
		if(d[i]!=e[i])//如果错误输出学生答案和正确答案
		{
			if(b[i]==0)
			{
				printf("学生答案%d+%d=%d",a[i],c[i],d[i]);
				printf("\t正确答案%d+%d=%d\n",a[i],c[i],e[i]);
				}
			else if(b[i]==1)
			{
				printf("学生答案%d-%d=%d",a[i],c[i],d[i]);
				printf("\t正确答案%d-%d=%d\n",a[i],c[i],e[i]);
				}
			else if(b[i]==2)
			{
				printf("学生答案%d*%d=%d",a[i],c[i],d[i]);
				printf("\t正确答案%d*%d=%d\n",a[i],c[i],e[i]);
				}
			else
			{
				printf("学生答案%d/%d=%d",a[i],c[i],d[i]);
				printf("\t正确答案%d/%d=%d\n",a[i],c[i],e[i]);
				}
			}
			else//如果正确sum++
			{
				sum++;
				}
		}

		printf("正确题数：%d\n",sum);
		printf("对错题是否重答：1 yes	2 no\n");
		scanf("%d",&f);
		if(f==1)//如果重答执行if，否则直接返回
		{
			for(i=0;i<n;i++)
			{
				if(e[i]!=d[i])
				{
					if(b[i]==0)
					{
						printf("%d+%d=",a[i],c[i]);
						scanf("%d",&d[i]);
						e[i]=a[i]+c[i];
						if(e[i]==d[i])
						{
							printf("\t正确\n");
							}
						else
						{
							printf("\t错误\n");
							}
						}
					else if(b[i]==1)
					{
						printf("%d-%d=",a[i],c[i]);
						scanf("%d",&d[i]);
						e[i]=a[i]-c[i];
						if(e[i]==d[i])
						{
							printf("\t正确\n");
							}
						else
						{
							printf("\t错误\n");
							}
						}
					else if(b[i]==2)
					{
						printf("%d*%d=",a[i],c[i]);
						scanf("%d",&d[i]);
						e[i]=a[i]*c[i];
						if(e[i]==d[i])
						{
							printf("\t正确\n");
							}
						else
						{
							printf("\t错误\n");
							}
						}
					else
					{
						printf("%d/%d=",a[i],c[i]);
						scanf("%d",&d[i]);
						e[i]=a[i]/c[i];
						if(e[i]==d[i])
						{
							printf("\t正确\n");
							}
						else
						{
							printf("\t错误\n");
							}
						}
					}
				}
			}

	return 0;
	}
