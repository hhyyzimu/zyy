/*函数原型：char *strpbrk(const char *s1, const char *s2);
 *函数功能：得到s1中第一个“同时也出现在所s2中”字符的位置指针
 *函数返回：s1中相应字符的位置指针
 *
 * */

#include <stdio.h>
#include <string.h>

int main()
{
	char *p = "Find all vowels";
	while(p)
	{
		printf("%s\n", p);
		p = strpbrk(p+1, "aeiouAEIO");
	}

	return 0;
}
