/*二维数组，输入学生数量，每个学生考试的科目数量，各科的考试成绩*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int **p=NULL;
	int n=0;
	int m=0;
	int i=0;
	int j=0;

	printf("输入学生数量:");
	scanf("%d",&n);
	int a[n];
	p=(int **)malloc(sizeof(int *)*n);
	for(i=0;i<n;i++)
	{
		printf("输入第%d个学生考试科目数：\n",i+1);
		scanf("%d",&a[i]);
		p[i]=malloc(sizeof(int)*a[i]);
		for(j=0;j<a[i];j++)
		{
			printf("输入第%d个科目分数：",j+1);
			scanf("%d",&p[i][j]);
			}
		}
	for(i=0;i<n;i++)
	{
		printf("输出第%d个学生成绩：\n",i+1);
		for(j=0;j<a[i];j++)
		{
			printf("输出第%d个科目分数：",j+1);
			printf("%d\n",p[i][j]);
			}
		}
	for(i=0;i<n;i++)
	{
		free(p[i]);
		}
	free(p);

	return 0;
	}
