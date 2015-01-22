#include <stdio.h>
#include <stdlib.h>
#include <utime.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int i, fd;
	struct stat statres;
	struct utimbuf timebuf;

	for(i=1; i<argc; i++)
	{
		if(stat(argv[i], &statres) < 0){
			printf("%s: stat error\n", argv[i]);
			continue;
		}

		if((fd = open(argv[i], O_RDWR|O_TRUNC )) < 0){
			printf("%s: open error\n", argv[i]);
			continue;
		}
		close(fd);
		
		timebuf.actime = statres.st_atime;
		timebuf.modtime = statres.st_mtime;
		if(utime(argv[i], &timebuf) < 0){
			printf("%s: utime error", argv[i]);
			continue;
		}
	}

	exit(0);
}
