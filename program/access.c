#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	if(argc != 2)
		printf("Usage...");

	if(access(argv[1], F_OK) < 0)
		printf("The file is not here!\n");
	else
		printf("here is the file %s\n", argv[1]);

	if(access(argv[1], R_OK) < 0)
		printf("access error for %s\n", argv[1]);
	else 
		printf("read access ok!\n");

	if(access(argv[1], W_OK) < 0)
		printf("Can't write!\n");
	else 
		printf("write access ok!\n");

	if(open(argv[1], O_RDWR) < 0)
		printf("Can't read and write!\n");
	else
		printf("read and write ok !\n");
	

	exit(0);
}
