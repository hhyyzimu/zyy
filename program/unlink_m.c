#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	if(open("tempfile", O_RDWR) < 0)
		perror("open()");
	if(unlink("tempfile") < 0)
		perror("unlink()");
	printf("file unlinked\n");
	sleep(1);
	printf("done\n");

	exit(0);
}
