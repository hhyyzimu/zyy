#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

int listenfd, connfd;

void sig_chld(int signo)
{
	pid_t pid;
	int stat;

	while((pid = waitpid(-1, &stat, WNOHANG)) > 0)
		printf("child %d terminated\n", pid);
			
	printf("getpid(%d), getppid(%d)\n", getpid(), getppid());
	close(connfd);

	//sleep(1);
	//exit(0);
}

int main()
{
	pid_t childpid;
	socklen_t clilen;
	struct sockaddr_in cliaddr, servaddr;
	
	void sig_chld(int);

	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if(listenfd < 0)
	{
		perror("socket()");
		exit(1);
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(2222);
	
	if(bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
	{
		perror("bind()");
		exit(1);
	}
	
	if(listen(listenfd, 200) < 0)
	{
		perror("listen()");
		exit(1);
	}

	signal(SIGCHLD, sig_chld);
	for(;;){
		clilen = sizeof(cliaddr);
		if((connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen)) < 0){
			if(errno == EINTR)
				continue;
			else{
				perror("accept()");
				exit(1);
			}
		}
			if((childpid = fork()) == 0){
				close(listenfd);
				printf("connfd\n");
				printf("for_getpid(%d), for_getppid(%d)\n", getpid(), getppid());
//				exit(0);
			}
			
		}
//			printf("getpid(%d), getppid(%d)\n", getpid(), getppid());
//			close(connfd);
//			exit(0);
	}
