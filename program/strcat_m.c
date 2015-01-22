/*函数原型：char *strcat(char *str1, char *str2);
 *函数功能：把字符串str2接到str1后面，str1最后的'\0'被取消
 *函数返回：str1
 * */

#include <stdio.h>
#include <string.h>

int main()
{
	char buffer[80];
	strcpy(buffer, "Hello ");
	strcat(buffer, "world");
	printf("%s\n", buffer);

	return 0;
}
