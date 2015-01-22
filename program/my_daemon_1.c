/*gcc -wall -o daemontest daemontest.c
 *./daemontest
 *ps axj 查看程序运行进程号
 *vi /var/log/syslog可以看到程序进程信息，包括id
 *kill id
 *ps axj
 * */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <syslog.h>
#include <sys/types.h>
#include <sys/stat.h>

int daemon_init(void)
{
	pid_t pid;

	if((pid = fork()) < 0)
		return(-1);
	else if(pid != 0)
		exit(0);//parent exit

	//child continues
	setsid();//become session leader
	chdir("/");//change working directory
	umask(0);//clear file mode create ionmask
	close(0);//close stdin
	close(1);//close stdout
	close(2);//close stderr

	return(0);
}

void sig_term(int signo)
{
	//catched signal sent by kill(15) command
	if(signo == SIGTERM)
	{
		syslog(LOG_INFO, "program terminated.");
		closelog();
		exit(0);
	}
}

int main(void)
{
	if(daemon_init() == -1)
	{
		printf("can't fork self\n");
		exit(0);
	}

	openlog("daemontest", LOG_PID, LOG_USER);
	syslog(LOG_INFO, "program started");
	signal(SIGTERM, sig_term);//arrange to catch the siganl
	while(1)
	{
		sleep(1);//put your main program here
	}

	return(0);
}
