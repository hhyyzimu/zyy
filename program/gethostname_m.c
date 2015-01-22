#include <stdio.h>
#include <stdlib.h>

int main()
{
	char name[65];
	gethostname(name, sizeof(name));
	printf("hostname = %s\n", name);

	exit(0);
}
