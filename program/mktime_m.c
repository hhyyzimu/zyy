/*输出设定的时间*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	struct tm t;
	time_t t_of_day;

	t.tm_year = 2014-1900;
	t.tm_mon = 6;
	t.tm_mday = 1;
	t.tm_hour = 0;
	t.tm_min = 0;
	t.tm_sec = 1;
	t.tm_isdst = 0;
	t_of_day = mktime(&t);

	printf(ctime(&t_of_day));

	exit(0);
}
