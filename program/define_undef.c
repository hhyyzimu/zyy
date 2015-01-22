#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct A{
	int a;
	int b;
	int c;
};

int main()
{
	struct A b;
	struct A a={
		.a = 10,
		.b = 20,
		.c = 30,
	};

	printf("a.a = %d\n", a.a);
	printf("a.b = %d\n", a.b);
	printf("a.c = %d\n", a.c);
	
	memset(&b, 0,sizeof(b));
	//memcpy(&b.a, &a.a, sizeof(a.a));

#define STRNCPY(v) strncpy(&b.v, &a.v, sizeof(b.v) - 1)
	STRNCPY(a);
	STRNCPY(b);
	STRNCPY(c);
#undef STRNCPY

	printf("b.a = %d\n", b.a);
	printf("b.b = %d\n", b.b);
	printf("b.c = %d\n", b.c);

	exit(0);
}
