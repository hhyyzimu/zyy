#include <stdio.h>
#include <arpa/inet.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>

#define	UNIX_PATH	"/tmp/unix_tmp"

void sin_int(int signum)
{
	int sa_er;
	sa_er = errno;//保存errno的原始值

	unlink(UNIX_PATH);//如果存在UNIX_PATH则删除
	if(signal(SIGINT, SIG_DFL) == SIG_ERR)//将信号变为默认信号
		fprintf(stdout, "set SIGINT SIG_DEF failed\n");
	
	errno = sa_er;//还原errno的值?

	return;
}

static inline int min(int a, int b)
{
	return (a < b ? a : b);
}

int main(int arc, char **argv)
{
	/*ignore the signal SIGCHLD*/
	if(signal(SIGCHLD, SIG_IGN) == SIG_ERR)//======>
		fprintf(stdout, "socket SIGCHLD of SIG_IGN failed!\n");
		exit(EXIT_FAILURE);

	/*execute the handler of sin_int*/
	if(signal(SIGINT, sin_int) == SIG_ERR)
		fprintf(stdout, "set SIGINT of sin_int failed!\n");

	/*建立socket*/
	int sevfd, clifd;
	if((sevfd = socket(AF_LOCAL, SOCK_STREAM, 0)) < 0)
	{
		fprintf(stdout, "socket error: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	/*绑定套接子，若地址以在socket类型文件中，则绑定失败*/
	char *fpath = UNIX_PATH;
	int ret;
	struct sockaddr_un un_sevaddr;

	bzero(&un_sevaddr, sizeof(un_sevaddr));
	un_sevaddr.sun_family = AF_LOCAL;
	bcopy(fpath, un_sevaddr.sun_path, min(strlen(fpath), sizeof(un_sevaddr.sun_path)-1));//将fpath里的地址给un_addr,大小为长度值小的
	unlink(fpath);//删除文件fpath

	if((ret = bind(sevfd, (struct sockaddr *)&un_sevaddr, sizeof(un_sevaddr))) < 0)
	{
		fprintf(stdout, "bind error: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	
	/*listen*/
	if((ret = listen(sevfd, 10)) < 0)
	{
		fprintf(stderr, "listen error: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	struct sockaddr_un un_cliaddr;
	socklen_t clilen = sizeof(un_cliaddr);
	pid_t pid;
	char rbuf[BUFSIZ], sbuf[BUFSIZ];
	int count;

	for(;;)
	{
		count = 0;

		/*accept*/
		if((clifd = accept(sevfd, (struct sockaddr *)&un_cliaddr, &clilen)) < 0)
		{
			fprintf(stdout, "accept error: %s\n", strerror(errno));
			exit(EXIT_FAILURE);
		}

		/*fork child*/
		if((pid = fork()) < 0)
		{
			fprintf(stdout, "fork error: %s\n", strerror(errno));
		}
		else if(pid > 0)
		{
			/*parent operation*/
			unlink(UNIX_PATH);
			close(clifd);
			clifd = -1; //?
		}
		else
		{
			/*child operation*/
			close(sevfd);
			clifd = -1; //?

			while(bzero(rbuf, sizeof(rbuf)), (ret = recv(clifd, rbuf, sizeof(rbuf), 0)) > 0)
			{
				fprintf(stdout, "received buf: %s", rbuf);
				bzero(sbuf, sizeof(sbuf));
				sprintf(sbuf, "received counter: %d\n", count++);
				send(clifd, sbuf, strlen(sbuf), 0);//将获取的字数发给client
				sleep(10);
			}
			if(ret == 0)
				fprintf(stdout, "client close\n");
			else
				fprintf(stdout, "received error: %s\n", strerror(errno));
			close(clifd);
			clifd = -1;
			unlink(fpath);

			exit(EXIT_SUCCESS);
		}
	}

	return 0;
}
