#include <stdio.h>
#include <stdlib.h>

int main()
{
start:
	printf("start\n");

	goto begin;

begin:
	printf("begin\n");

end:
	printf("end\n");

	exit(0);
}
