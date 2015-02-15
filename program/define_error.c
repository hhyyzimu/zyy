/*检查编译此源文件的编译器是不是c++编译器
 *如果使用的是c语言编译器则执行#error命令
 *如果使用的是C++编译器则跳过#error命令
 * */
#ifndef __cplusplus
#error Is not c++ //当用户处理到此处时，将停止编译并输出用户自定义的错误消息
#endif

#include <stdio.h>

int main()
{
	printf("Hello, world!");

	return 0;
}
