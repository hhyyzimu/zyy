/*第一个是随机值
 * strlen(b) = 2
 * strlen(c) = 3
 * */
#include <stdio.h>
#include <string.h>

int main()
{
	char b[5];
	char c[5] = {'a', 'b', 'c'};
	printf("strlen(b) = %d\n", strlen(b)); //赶上哪里有\0，就会是多少
	printf("strlen(c) = %d\n", strlen(c));



	return 0;
}
