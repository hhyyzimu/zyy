/*函数原型：int strncmp(char *str1, char *str2, int count);
 *函数功能：对str1和str2中的前count个字符按字典数序比较
 *函数返回：小于0：str < str2, 等于0: str1 = str2, 大于0：str1 > str2
 *
 * */

#include <stdio.h>
#include <string.h>

int main()
{
	int ptr;
	char *buf1 = "aaabbb", *buf2 = "bbbccc", *buf3 = "ccc", *buf4 = "aaa";

	ptr = strncmp(buf1, buf2, 3);
	if(ptr > 0)
		printf("%s is greater than %s\n", buf1, buf2);
	else if(ptr < 0)
		printf("%s is less than %s\n", buf1, buf2);
	else
		printf("%s is equle %s\n", buf1, buf2);

	ptr = strncmp(buf2, buf3, 3);
	if(ptr > 0)
		printf("%s is greater than %s\n", buf2, buf3);
	else if(ptr < 0)
		printf("%s is less than %s\n", buf2, buf3);
	else
		printf("%s is equle %s\n", buf2, buf3);

	ptr = strncmp(buf1, buf4, 3);
	if(ptr > 0)
		printf("%s is greater than %s\n", buf1, buf4);
	else if(ptr < 0)
		printf("%s is less than %s\n", buf1, buf4);
	else
		printf("%s is equle %s\n", buf1, buf4);

	return 0;
}
