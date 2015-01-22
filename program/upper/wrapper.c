#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int fd;

	if(argc != 2){
		fputs("Usage: warpper file \n", stderr);
		exit(1);
	}

	fd = open(argv[1], O_RDONLY);
	if(fd<0){
		perror("open");
		exit(1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	execl("./upper", "uuuuuuuuupper", NULL);
	perror("exec ./upper");
	exit(1);
}
