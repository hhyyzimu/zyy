#include <stdio.h>
#include <string.h>

int main()
{
	char *(str[10]);

	printf("%d\n", sizeof(str));
	printf("%d\n", strlen(*str));

	return 0;
}
