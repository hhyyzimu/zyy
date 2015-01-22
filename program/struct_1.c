#include <stdio.h>
#include <stdlib.h>

struct A{
	int a;
	int b;
};

int main()
{
	struct A aa[] = {
		[0] = {
			.a = 1,
			.b = 2,
		},
		[1] = {
			.a = 3,
			.b = 4
		},
	
	};

	printf("aa[0].a:%d\n", aa[0].a);
	printf("aa[0].b:%d\n", aa[0].b);
	printf("aa[1].a:%d\n", aa[1].a);
	printf("aa[1].b:%d\n", aa[1].b);

	exit(0);
}
