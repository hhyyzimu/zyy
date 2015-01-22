/*函数原型：int strcmp(char *str1, char *str2);
 *函数功能：比较两个字符串str1,str2
 *函数返回：str1 < str2,返回负数； str1 = str2,返回0； str1 > str2,返回正数
 *
 * */
#include <stdio.h>
#include <string.h>

int main()
{
	char *buf1 = "aaa", *buf2 = "bbb" , *buf3 = "ccc", *buf4 = "AAA", *buf5 = "aaaa", *buf6 = "aaa";
	int ptr;

	ptr = strcmp(buf2, buf1);
	if(ptr > 0)
		printf("%s is greater than %s\n", buf2, buf1);
	else
		printf("%s is less than %s\n", buf2, buf1);
	
	ptr = strcmp(buf2, buf3);
	if(ptr > 0)
		printf("%s is greater than %s\n", buf2, buf3);
	else
		printf("%s is less than %s\n", buf2, buf3);

	printf("=======================================\n");

	ptr = strcmp(buf1, buf4);
	if(ptr > 0)
		printf("%s is greater than %s\n", buf1, buf4);
	else if(ptr < 0)
		printf("%s is less than %s\n", buf1, buf4);
	else
		printf("%s is equle %s\n", buf1, buf4);

	ptr = strcmp(buf1, buf5);
	if(ptr > 0)
		printf("%s is greater than %s\n", buf1, buf5);
	else if(ptr < 0)
		printf("%s is less than %s\n", buf1, buf5);
	else
		printf("%s is equle %s\n", buf1, buf5);

	ptr = strcmp(buf1, buf6);
	if(ptr > 0)
		printf("%s is greater than %s\n", buf1, buf6);
	else if(ptr < 0)
		printf("%s is less than %s\n", buf1, buf6);
	else
		printf("%s is equle %s\n", buf1, buf6);

	return 0;
}
