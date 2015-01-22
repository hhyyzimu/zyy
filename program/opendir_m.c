#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

int my_readdir(const char *path)
{
	DIR *dir;
	struct dirent *ptr;

	if((dir = opendir(path)) == NULL)
	{
		perror("opendir()");
		exit(1);
	}
	while((ptr = readdir(dir)) != NULL){
		printf("file name: %s\n", ptr->d_name);
	}
	closedir(dir);

	exit(0);
}

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		printf("Usage...\n");
		exit(1);
	}

	if(my_readdir(argv[1]) < 0)
	{
		exit(1);
	}

	exit(0);
}
