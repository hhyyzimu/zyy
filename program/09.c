/*字符数组的修改，指针的初始化值在常数区，相同字符串不会重新定义，不可以改变常熟区常量*/
#include <stdio.h>

int main()
{
	char a[40]="abcdefg";
	char *p="abcdefg";
	printf("a=%s\n",a);
	printf("p=%s\n",p);
	printf("a=%p\n",p);
	char *pc="abcdefg";
	printf("pc=%p\n",pc);
	a[0]='x';
	printf("a=%s\n",a);
	//p[0]='y';//常熟区的值不能改变

	return 0;
	}
