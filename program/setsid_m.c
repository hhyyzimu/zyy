#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <syslog.h>

#define FNAME	"/tmp/out"

static int daemonize(void)
{
	pid_t pid;
	int fd;

	pid = fork();

	if(pid < 0)
		return -1;//要关闭0，1，2，所以将错误返回到主函数处理

	if(pid > 0)
		exit(0);

	if(pid == 0)
	{
		fd = open("/dev/null", O_RDWR);
		if(fd < 0)
			return -1;

//只重定向0，1，2，保证stdin,stdout,stderr关闭
		dup2(fd, 0);
		dup2(fd, 1);
		dup2(fd, 2);

		if(fd > 2)
			close(fd);

		setsid();

		chdir("/");//更改当前进程的工作路径
	}
	return 0;
}

int main()
{
	FILE *fp;
	int i;

	openlog("mydaemon", LOG_PID, LOG_DAEMON);

	if(daemonize())
	{
		syslog(LOG_ERR, "daemonize() failed!");
		exit(1);
	}
	else
		syslog(LOG_INFO, "daemonize() successed!");

		fp = fopen(FNAME, "w");
		if(fp == NULL)
		{
			perror("fopen()");
			exit(1);
		}

		for(i = 0; ; i++)
		{
			fprintf(fp, "%d\n", i);
			fflush(fp);
			sleep(1);
		}

		fclose(fp);

		exit(0);

	return 0;
}
