#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char file[] = "tmp1.XXXXXX";
	char file2[] = "tmp2.XXXXXX";
	int fd, fd2;

	fd = mkstemp(file);
	fprintf(stdout, "file: %s\n", file);
	fd2 = mkstemp(file2);
	fprintf(stdout, "file2: %s\n", file2);
	write(fd, "123", strlen("123"));
	fsync(fd);
//	pause();
	unlink(file);
	unlink(file2);

	exit(0);
}
