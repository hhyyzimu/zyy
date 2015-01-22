/*
函数原型：void *memccpy(void *dest, const void *src, int c, size_t n);
函数功能：字符串拷贝，到指定长度活遇到指定字符时停止拷贝
参数说明：src-源字符串指针，c-终止拷贝检查字符，n-拷贝的目的字符串指针
*/

#include <stdio.h>
#include <string.h>

int main()
{
	char *src = "This is the source string";
	char dest[50];
	char *ptr;

	ptr = memccpy(dest, src, 'c', strlen(src));
	if(ptr)
	{
		*ptr = '\0';
	//	ptr = NULL;
		printf("The character was found:%s\n", dest);
	}
	else
		printf("The character wasn't found\n");

	return 0;
}
