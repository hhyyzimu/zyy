/*函数原型：char *strdup(const char *s);
 *函数功能：字符串拷贝，目的空间由该函数分配
 *函数返回：指向拷贝后的字符串指针
 *参数说明：src-待拷贝的源字符串
 * */

#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main()
{
	char *dup_str,*string = "adcde";
	dup_str = strdup(string);
	printf("%s\n",dup_str);
	free(dup_str);

	return 0;
}
