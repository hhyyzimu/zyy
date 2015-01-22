#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>

int my_system(const char *cmdstring)
{
	pid_t pid;
	int status;

	if(cmdstring == NULL){
		return (1);
	}

	if((pid = fork()) < 0){
		status = -1;
	}else if(pid == 0){
		execl("/bin/sh", "sh", "-c", cmdstring, (char *)0);
		_exit(127);//若子进程正常执行则不会执行此句
	}else{
		while(waitpid(pid, &status, 0) < 0){
			if(errno != EINTR)
			{
				status = -1;
				break;
			}
		}
	}

	return status;
}

int main()
{
#if 0
	char buf[10];
	char *ps = "ps -ef|grep -c root";
	FILE *ptr;
	int i;

	if((ptr = popen(ps, "r")) != NULL)
	{
		fgets(buf, 10, ptr);
		i = atoi(buf);
		pclose(ptr);
	}
#endif
	
	my_system("clear");

	exit(0);
}
