#include <stdio.h>
#include <stdlib.h>

#define NAME(str) printf(#str)

int main()
{
	NAME(ZYY\n);

	exit(0);
}
