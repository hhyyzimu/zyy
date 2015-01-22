/*得到日历时间*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	time_t timer = time(NULL);
	printf("ctime is %s\n", ctime(&timer));

	return 0;
}
