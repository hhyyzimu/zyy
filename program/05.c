/*输入旅游地点，输出旅游费用*/
#include <stdio.h>

int main()
{
	char x=0;//字符初始化
	printf("请选择旅游地点：\n\ta.日本\tb.意大利\tc.巴黎\n");
	scanf("%c",&x);
	switch(x)
	{
		default:
			printf("输入错误！\n");
			break;
		case 'a':
		case 'A':
			printf("去日本	1000元\n");
			break;
		case 'b':
		case 'B':
			printf("去意大利	2000元\n");
			break;
		case 'c':
		case 'C':
			printf("去巴黎	3000元\n");
			break;
		}

	return 0;
	}
