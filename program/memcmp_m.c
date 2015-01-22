/*
函数原型：int memcmp(const void *s1, const void *s2, size_t n);
函数功能：按字典顺序比较两个串s1和s2的前n个字节
函数返回：<0,=0,>0,分别表示s1<,=,>s2
参数说明：s1,s2-要比较的字符串，n-比较的长度
*/

#include <stdio.h>
#include <string.h>

int main()
{
	char *buf1 = "ABCDE123";
	char *buf2 = "abcde456";
	int stat;
	stat = memcmp(buf1, buf2, 5);
	printf("The strings to position 5 are");
	if(stat)
		printf("not ");
	printf("the same\n");

	return 0;
}
