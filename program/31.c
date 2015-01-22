/*检查是ch是否可显示字符*/

#include <stdio.h>
#include <ctype.h>

int main()
{
	char ch1 = ' ';
	char ch2 = 'a';
	if(isgraph(ch1) != 0)
		printf("%c is the ascii ch1\n",ch1);
	else
		printf("%c is not the ascii ch1\n",ch1);
	if(isgraph(ch2) != 0)
		printf("%c is the ascii ch2\n",ch2);
	else
		printf("%c is not the ascii ch2\n",ch2);

	return 0;
}
