/*
函数原型：int strspn(const char *s1, const char *s2);
函数功能：统计s1中从头开始知道一个“"不来自s2中的字符串"出现的长度
函数返回：位置指针，即从0开始和s2中字符不相同的数字
*/

#include <stdio.h>
#include <string.h>

int main()
{
	printf("%d\n", strspn("out to lunch", "aeiou"));
	printf("%d\n", strspn("out to lunch", "xyz"));

	return 0;
}
