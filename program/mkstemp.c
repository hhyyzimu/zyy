#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
	int fd, fd1;
	char temp_file[BUFSIZ] = "tmp_XXXXXX";

	if((fd = mkstemp(temp_file)) == -1)
	{
		printf("creat temp file faile.\n");
		exit(1);
	}
	
	if((fd = open(temp_file, O_RDWR)) < 0)
	{
		perror("open()");
		exit(1);
	}

	write(fd, temp_file, strlen(temp_file));
	unlink(temp_file);

	close(fd);
}
