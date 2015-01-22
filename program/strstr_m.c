/*
函数原型：char *strstr(char *str1, char *str2);
函数功能：找出str2字符串在str1字符串中第一次出现的位置（不包括str2串的结束符）
函数返回：返回该位置的指针，如找不到，返回NULL
*/

#include <stdio.h>
#include <string.h>

int main()
{
	char *str1 = "Open Watcom C/C++", *str2 = "Watcom", *ptr;
	ptr = strstr(str1, str2);
	printf("The substring is:%s\n", ptr);

	return 0;
}
