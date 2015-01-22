/*
	函数原型：char *asctime(struct tm *ptr)
	函数功能：得到机器时间（日期时间转换为ASCII码）
	函数返回：返回的时间字符串格式为：星期，月，日，小时：分：秒，年
	参数说明：结构体指针ptr应通过函数localtime()和gmtime()得到

	函数原型：char *ctime(const time_t *time)
	函数功能：得到日历时间
	参数说明：time-该参数由函数time获得
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	time_t t;
	time(&t);
	printf("Today's date time:%s", ctime(&t));

	exit(0);
}
