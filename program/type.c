#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

	struct A{
		char ch;
		int *num;
	};

int main()
{
	struct A a = {0};
	int *num2;

//	typeof(((a *)0)->(a->num)) *ptr = a->num;
//	a = (a *)((char *)ptr - offsetof(a,a->num));
	typeof(((a *)0)->num) (*ptr) =(num2);
	printf("%p\n",((char *)ptr - offsetof(a,num2)));
	printf("a = %p\n", a);
	printf("A = %p\n", a);

	exit(0);
}
