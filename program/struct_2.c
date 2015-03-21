/*sizeof(array1) = 12
 *sizeof(array2) = 24
 * */
#include <stdio.h>

typedef struct array1{
	int a;
	int b;
	int c;
}A;

typedef struct array2{
	double d;
	double e;
	double f;
}B;

int main()
{

	A a = {
		.a = 1,
		.b = 2,
		.c = 3,
	};

	B b = {
		d : 11.11,
		e : 22.22,
		f : 33.33,
	};

	printf("sizeof(array1) = %d\n", sizeof(a));
	printf("sizeof(array2) = %d\n", sizeof(b));

	return 0;
}
