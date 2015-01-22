#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	time_t start, end;
	system("clear");//清屏
	start = time(NULL);
	system("sleep 5");//等待5秒
	end = time(NULL);

	printf("The difference is:%f seconds", difftime(end, start));

	exit(0);
}
