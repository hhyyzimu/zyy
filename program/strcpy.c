/*函数原型：char* strcpy(char * str1, char* str2);
 *函数功能：把str2指向的字符串拷贝到str1中去
 *函数返回：返回str1,即指向str1的指针
 * */

#include <stdio.h>
#include <string.h>

int main()
{
//	char *string;
	char string[10];
	char *str1 = "abcdefghi";
	strcpy(string, str1);
	printf("the string is: %s\n", string);

	return 0;
}
