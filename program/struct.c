#include <stdio.h>

struct a{
	int b;
	int c;
};

int main()
{
	struct a s = {
	
		.b = 10,
		.c = 20

};

	printf("s.b = %d, s.c = %d\n", s.b, s.c);

	return 0;
}
