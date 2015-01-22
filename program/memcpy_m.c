/*
函数原型：void *memcpy(void *dest, const void *src, size_t n);
函数功能：字符串拷贝
函数返回：指向dest的指针
参数说明：src-源字符串，n-拷贝的最大长度
*/

#include <stdio.h>
#include <string.h>

int main()
{
	char src[] = "***";
	char dest[] = "abcdef";
	char *ptr;
	printf("destination before memcpy:%s\n", dest);
	ptr = strcpy(dest, src, strlen(src));

	if(ptr)
		printf("destination after memcpy:%s\n", dest);
	else
		printf("memcpy failed");

	return 0;
}
