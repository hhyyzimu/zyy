#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd;
	char buf[32];
	struct stat buff;

	if((fd = open("temp.txt", O_RDWR|O_CREAT|O_TRUNC, S_IRWXU)) < 0)
	{
		printf("create file error!\n");
	}

	stat("temp.txt", &buff);
	printf("temp.link = %d\n", buff.st_nlink);
	
	link("temp.txt", "test.txt");
	stat("test.txt", &buff);
	printf("after link the temp.txt test's link = %d\n", buff.st_nlink);
	
	if(unlink("temp.txt") < 0)//第一次执行连接数为2，第二次为1，在文件被打开的时候，无法删除，等关闭后系统才删除此文件，且相应的连接文件的i节点减1
	{
		printf("unlink error!\n");
	}
		
	stat("temp.txt", &buff);
	printf("after unlink temp.txt link = %d\n", buff.st_nlink);
	if(write(fd, "temp", 5) < 0)
	{
		printf("write error!\n");
	}

	if((lseek(fd, 0, SEEK_SET)) == -1)
	{
		printf("lseek error!\n");
	}

	if((read(fd, buf, 5)) < 0)
	{
		printf("read error!\n");
	}

	printf("%s\n", buf);
	return 0;

	return 0;
}
