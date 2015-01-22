#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

char buf1[] = "djoiefoijo";
char buf2[] = "LFJIOIEFJJ";

int main(void)
{
	int fd;

	if((fd = creat("a.c", 002) < 0))
		perror("create()");	

	if(write(fd, buf1, 10) != 10)
		printf("buf1 write error\n");

	if(lseek(fd, 20000, SEEK_SET) == -1)
		printf("lseek error!\n");

	if(write(fd, buf2, 10) != 10)
		printf("buf2 write error\n");

	exit(0);
}
