#include <stdio.h>
#include <stdlib.h>

int main()
{
	pid_t pid;

	printf("[%d]Begin!\n", getpid());

	pid = fork();
	if(pid < 0)
	{
		perror("fork()");
		exit(1);
	}
	if(pid == 0)
	{
		printf("[%d]Child is working!\n", getpid());
	}
	else
	{
		printf("[%d]Parent is working!\n", getppid());
	}

	printf("[%d]End!\n", getpid());

	exit(0);
}
