/*
函数原型：char *strrchr(const char *s,  char c);
函数功能：从右到左查找，即得到字符串s中最后一个含有c字符的位置指针
函数返回：位置指针
*/

#include <stdio.h>
#include <string.h>

int main()
{
	char string[15];
	char *ptr, c='i';
	strcpy(string, "This is a string");
	ptr = strrchr(string, c);

	if(ptr)
		printf("The character %c is at position:%d\n", c, ptr-string);
	else
		printf("The character was not found");

	return 0;
}
