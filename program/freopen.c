/*
 *函数功能：将原stream打开的文件流关闭，然后打开path的文件；
 *函数原型：FILE *freopen(const char *path, const char *mode, FILE *stream);
 *函数参数：path欲打开的文件路径及文件名，mode同fopen，stream已打开的文件指针；
 *函数返回：成功返回指向该流的文件指针，失败返回NULL，错误代码存入errno;
 * */

#include <stdio.h>

int main()
{
	FILE *fp;

	fp = fopen("/etc/passwd", "r");
	fp = freopen("/etc/group", "r", fp);

	fclose(fp);
}
