#include <stdio.h>
#include <stdlib.h>

int main()
{
	time_t ticks;
	ticks = time(NULL);
	printf("%s\n", ctime(&ticks));

	exit(0);
}
