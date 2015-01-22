/*用户输入题数，程序给出随机100以内的加减乘除测试题,答题错误提示并输出正确答案，最后给出答对的个数*/
#include <stdio.h>

int main()
{
	int i=0;
	int n=0;
	int a=0;//随机数
	int b=0;//随机数
	int c=0;//用户输出答案
	int d=0;//正确答案
	int f=0;//随机运算方法
	int sum=0;//答对个数
	printf("请输入题数：");
	scanf("%d",&n);
	srand(time(NULL));
	for(i=0;i<n;i++)
	{
		a=rand()%101;
		b=rand()%101;
		f=rand()%4;
		if(f==0)
		{
			printf("%d+%d=",a,b);
			scanf("%d",&c);
			d=a+b;
			if(c==d)
			{
				printf("\t正确\n");
				sum++;
				}
			else
			{
				printf("\t错误\t");
				printf("正确答案：%d+%d=%d\n",a,b,d);
				}
			}
		else if(f==1)
		{
			printf("%d-%d=",a,b);
			scanf("%d",&c);
			d=a-b;
			if(c==d)
			{
				printf("\t正确\n");
				sum++;
				}
			else
			{
				printf("\t错误\t");
				printf("正确答案:%d-%d=%d\n",a,b,d);
				}
			}
		else if(f==2)
		{
			printf("%d*%d=",a,b);
			scanf("%d",&c);
			d=a*b;
			if(c==d)
			{
				printf("\t正确\n");
				sum++;
				}
			else
			{
				printf("\t错误\t");
				printf("正确答案:%d*%d=%d\n",a,b,d);
				}
			}
		else
		{
			printf("%d/%d=",a,b);
			scanf("%d",&c);
			d=a/b;
			if(d==c)
			{
				printf("\t正确\n");
				sum++;
				}
			else
			{
				printf("\t错误\t");
				printf("正确答案:%d/%d=%d\n",a,b,d);
				}
			}
		}

	printf("答对题数：%d\n",sum);

	return 0;
	}
