
#include <stdio.h>
#include <stdlib.h>

#define PRINT_LINE fprintf(stderr, "%s %s %d\n", (char *)__FILE__, (char *)__FUNCTION__, (char *)__LINE__);

int main()
{
	PRINT_LINE(NULL);

	exit(0);
}
