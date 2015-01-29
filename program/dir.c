#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char **argv)
{
	DIR *dir;
	struct dirent *ptr;

	if(argc < 2)
	{
		printf("Usage....\n");
		exit(EXIT_FAILURE);
	}

	if((dir = opendir(argv[1])) == NULL)
	{
		perror("opendir()");
		exit(EXIT_FAILURE);
	}

	while((ptr = readdir(dir)) != NULL)
	{
		printf("%s\n", ptr->d_name);
	}

	exit(0);	
}
