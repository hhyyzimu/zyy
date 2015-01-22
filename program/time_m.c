#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	struct tm *ptr;
	time_t lt;
	lt = time(NULL);

	printf("The Calendar Time now is %d\n", lt);

	exit(0);
}
