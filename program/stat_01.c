#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	struct stat statres;
	char *ptr;

	for(i = 1; i < argc; i++)
	{
		printf("%s: ", argv[i]);
		if(lstat(argv[i], &statres))
		{
			perror("lstat()");
			continue;
		}
		if(S_ISREG(statres.st_mode))
			ptr = "regular";
		else if(S_ISDIR(statres.st_mode))
			ptr = "directory";
		else if(S_ISCHR(statres.st_mode))
			ptr = "character special";
		else if(S_ISBLK(statres.st_mode))
			ptr = "block special";
		else if(S_ISFIFO(statres.st_mode))
			ptr = "fifo";
		else if(S_ISFIFO(statres.st_mode))
			ptr = "symbolic link";
		else if(S_ISSOCK(statres.st_mode))
			ptr = "socket";
		else
			ptr = "** unknown mode **";

		printf("%s\n", ptr);
	}

	exit(0);
}
