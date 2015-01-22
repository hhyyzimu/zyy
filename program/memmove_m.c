/*
函数原型：void *memmove(void *dest, const void *src, size_t n);
函数功能：字符串拷贝
函数返回：指向desc的指针
参数说明：src-源字符串，n-拷贝的最大长度
*/

#include <stdio.h>
#include <string.h>

int main()
{
	char dest[40] = "abcdef";
	printf("destination prior to memmove:%s\n", dest);
	memmove(dest+3, dest, 6);
	printf("destination after memmove:%s\n", dest);

	return 0;
}
