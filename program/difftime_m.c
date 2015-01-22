#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

int main()
{
	time_t start, end;
	
	start = time(NULL);
//	system("pause");
//	pause();
	sleep(2);

	end = time(NULL);
	printf("The sleep used %f seconds.\n", difftime(end, start));
//	printf("The sleep used %f seconds.\n", end-start);//返回0?

	exit(0);
}
