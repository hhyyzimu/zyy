#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define PROCNUM	20
#define FNAME		"/tmp/out"
#define BUFSIZE		1024

static void func_add(void)
{
	int fd;
	FILE *fp;
	char buf[BUFSIZE];

	fp = fopen(FNAME, "w+");
	if(fp == NULL)
	{
		perror("fopen()");
		exit(1);
	}

	fd = fileno(fp);
	if(fd < 0)
	{
		perror("fileno()");
		exit(1);
	}

	lockf(fd, F_LOCK, 0);

	fgets(buf, BUFSIZE, fp);
	fseek(fp, 0, SEEK_SET);
	sleep(1);
	fprintf(fp, "%d\n", atoi(buf)+1);
	fflush(fp);

	lockf(fd, F_ULOCK, 0);

	fclose(fp);
	return ;
}

int main()
{
	pid_t pid;
	int i, j, mark;
	int err;

	for(i = 0; i < PROCNUM; i++)
	{
		pid = fork();
		if(pid < 0)
		{
			perror("fork()");
			exit(1);
		}
		if(pid == 0)
		{
			func_add();
			exit(0);
		}
	}

	for(i =0; i < PROCNUM; i++)
		wait(NULL);

	exit(EXIT_SUCCESS);
}
