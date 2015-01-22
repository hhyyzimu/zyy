#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define set(a,b,c, ...) a##b = c
int main(void)
{
	int a1, a2;
	set(a, 1, 2); /* <==> a1 = 2 */
	set(a, 2, 5);
	fprintf(stdout, "a1:%d\n", a1);
	fprintf(stdout, "a2:%d\n", a2);
	return 0;
}
