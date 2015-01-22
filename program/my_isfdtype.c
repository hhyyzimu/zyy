#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#ifndef S_IFSOCK
#error S_IFSOCK not defined
#endif

int isfdtype(int fd, int fdtype)
{
	struct stat buf;

	if(fstat(fd, &buf) < 0)
		return (-1);
	if((buf.st_mode & S_IFMT) == fdtype)
		return (1);

	else
		return (0);
}
