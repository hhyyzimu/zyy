#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

void init_daemon()
{
	int pid;
	int i;
	pid = fork();
	if(pid < 0)
		exit(1);//创建错误退出
	else if(pid > 0)//父进程退出
		exit(0);

	setsid();//使子进程成为组长
	pid = fork();
	if(pid > 0)
		exit(0);//再次退出，使进程不是组长，这样进程就不会打开控制终端
	else if(pid < 0)
		exit(1);

	//关闭进程打开的文件句柄
	for(i = 0; i < NOFILE; i++)
		close(i);
	chdir("/root/test");
	umask(0);
	return;
}

int main()
{
	FILE *fp;
	time_t t;
	init_daemon();
	while(1)
	{
		sleep(60);
		fp = fopen("testfork2.log", "a");
		if(fp >= 0)
		{
			time(&t);
			fprintf(fp, "current time is:%s\n", asctime(localtime(&t)));
			fclose(fp);
		}
	}

	return;
}
