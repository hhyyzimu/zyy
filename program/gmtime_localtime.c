/*
	gmtime():将日历时间软化为世界标准时间,并用tm结构体保存这个时间
	localtime():将日历时间转化为本地时间

	中国地区获得的本地时间会比世界标准时间晚8小时
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	struct tm *local;
	time_t t;

	t = time(NULL);

	local = localtime(&t);
	printf("Local hour is: %d\n", local->tm_hour);

	local = gmtime(&t);
	printf("UTC hour is: %d\n", local->tm_hour);

	exit(0);
}
