/*函数原型：char *strncpy(char *dest, const char *src, int count);
 *函数功能：将字符串src中的count个字符拷贝到字符串dest中
 *函数返回：返回指向dest的指针 
 *参数说明：dest-目的字符串，src-源字符串，count-拷贝的字符个数
 * */

#include <stdio.h>
#include <string.h>

int main()
{
	char string[10];
	char *str1 = "abcdefghi";
	strncpy(string, str1, 3);
	string[3] = '\0';
	printf("%s", string);

	return 0;
}
