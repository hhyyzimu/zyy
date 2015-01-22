/*
函数原型：ssize_t getline(char **lineptr, size_t *n, FILE *stream);
函数返回：成功返回读取一行的字节数，失败返回－1
函数参数：lineptr-指向存放该行字符的指针，如果是NULL,系统自动malloc,使用后需自己free，n-如果是系统malloc的指针要写0，stream-文件描述符
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	fp = fopen("strcat_m.c", "r");
	if(fp == NULL)
		exit(EXIT_FAILURE);

	while((read = getline(&line, &len, fp)) != -1)
	{
		printf("Retrieved line of length %zu:\n", read);
		printf("%s", line);
	}

	if(line)
		free(line);
	exit(EXIT_SUCCESS);
}
