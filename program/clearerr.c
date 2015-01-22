/*
 *函数原型：void clearerr(FILE *stream);
 *函数说明：清除stream指定的文件流所使用的错误旗标； 
 * */

#include <stdio.h>

int main(void)
{
	FILE *fp;
	char ch;
		
	fp = fopen("a.txt", "w"); //open file for writing
	ch = fgetc(fp);
	printf("%c\n", ch);
	if(ferror(fp))
	{
		printf("Error reading for a.txt\n");
		clearerr(fp);
	}
	fclose(fp);
	return 0;
}
