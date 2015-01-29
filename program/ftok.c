#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i = 0;
	for(i=1; i<256; ++i)
		printf("key = %x\n", ftok(".", i));

	return 0;
}
