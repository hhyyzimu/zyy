/*函数原型：char *strncat(char *dest, const char *src, size_t maxlen);
 *函数功能：将字符串src中前maxlen各字符链接到dest中
 *
 *
 * */

#include <stdio.h>
#include <string.h>

char buffer[80];

int main()
{
	strcpy(buffer, "Hello ");
	strncat(buffer, "world", 8);
	printf("%s\n", buffer);
	strncat(buffer, "**********", 4);
	printf("%s\n", buffer);

	return 0;
}
