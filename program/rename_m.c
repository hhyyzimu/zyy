/*重命名一个文件，如果新文件名和已有文件名冲突，会删除已有文件，不是用于二进制文件*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if(argc < 3)
	{
		printf("Usage...");
		exit(1);
	}

	if(rename(argv[1], argv[2]) < 2)
	{
		perror("rename()");
		exit(1);
	}
	printf("rename success!\n");

	exit(0);
}
