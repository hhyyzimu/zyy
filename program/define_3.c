#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define		set(a, b, c, d)		a = b##_##c##_##d 

int main(void)
{
	char *a;
	
	set(a, b, c, d);

	fprintf(stdout, "a:%d\n", a);
	return 0;
}
