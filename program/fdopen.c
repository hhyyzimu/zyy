/*函数原型：FILE fdopen(int fildes, const char *mode);
 *函数参数：fildes要转换的文件描述符，mode打开方式，要与原先文件描述符打开方式形同；
 *函数功能：将文件描述符变为文件指针；
 *函数返回：成功返回该文件指针，失败返回NULL并将错误代码放在errno中；
 * */

#include <stdio.h>

int main()
{
	FILE *fp = fdopen(0, "w+");

	fprintf(fp, "%s\n", "hello!");
	fclose(fp);

	return 0;
}
