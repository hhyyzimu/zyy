/*
函数原型：char *strrev(char *s);
函数功能：将字符串中的所有字符颠倒次序排序
函数返回：指向s的指针
*/

#include <stdio.h>
#include <string.h>

int main()
{
	char *forward = "string";
	printf("Before strrev():%s\n", forward);
	strrev(forward);
	printf("After strrev():%s\n", forward);

	return 0;
}
