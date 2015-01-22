/*输入要选择的国家*/
#include <stdio.h>

int main()
{
	char arr=0;
	printf("请输入你要选择的国家:\na.日本	b.英国	c.美国\n");
	scanf("%c",&arr);

	switch(arr)
	{
		case 'a':
			printf("你选择了日本！\n");
			break;
		case 'b':
			printf("你选择了英国!\n");
			break;
		case 'c':
			printf("你选择了美国!\n");
			break;
		default:
			printf("请输入a,b,c\n");
			break;
		}

	return 0;
	}
