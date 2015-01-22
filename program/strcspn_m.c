/*
函数原型：int strcspn(const char *s1, const char *2);
函数功能：统计s1中从头开始直到第一个“"来自s2中的字符"出现的长度
函数返回：长度
*/

#include <stdio.h>
#include <string.h>

int main()
{
	printf("%d\n", strcspn("abcbcbadef", "cba"));
	printf("%d\n", strcspn("xxxbcbadef", "cba"));
	printf("%d\n", strcspn("0123456789", "cba"));

	return 0;
}
