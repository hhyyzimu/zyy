#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int len;
	int fp;

	fp = open("lseek_m.c", S_IRUSR);

	len = lseek(fp, 2, SEEK_CUR);
	printf("len = %d\n", len);

	exit(0);
}
