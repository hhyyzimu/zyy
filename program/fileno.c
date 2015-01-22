/*
 *函数功能：返回文件流所使用的文件描述符；
 *函数原型：int fileno(FILE *stream);
 *函数返回：返回文件描述符；
 * */

#include <stdio.h>

int main()
{
	FILE *fp;
	int fd;

	fp = fopen("/etc/passwd", "r");
	fd = fileno(fp);
	printf("fd = %d\n", fd);
	fclose(fp);

	return 0;
}
