/*
函数原型：void *memchr(const void *s, int c, size_t n);
函数功能：在字符串中前n个字符开始寻找某个字符c的位置
函数返回：返回c的位置指针，为找到返回NULL
参数说明：s-要搜索的字符串，c-要寻找的字符，n-指定长度
*/

#include <stdio.h>
#include <string.h>

int main()
{
	char str[17];
	char *ptr;
	strcpy(str, "This is a string");
	ptr = memchr(str, 'r', strlen(str));
	if(ptr)
		printf("The character 'r' is at position:%d\n", ptr-str);
	else
		printf("The character was not found\n");

	return 0;
}
