/*
函数原型：char *strchr(char *str, char ch);
函数功能：从前到后找出str指向的字符串中第一次出现字符ch的位置
函数返回：返回指向该位置的指针，找不到返回NULL
参数说明：str-待搜错的字符串，ch-查找的字符
*/

#include <stdio.h>
#include <string.h>

int main()
{
	char string[15];
	char *ptr, c='r';
	strcpy(string,"This is a string");
	ptr = strchr(string, c);

	if(ptr)
		printf("The character %c is at position:%d\n", c, ptr-string);
	else
		printf("The character was not found\n");

	return 0;
}
