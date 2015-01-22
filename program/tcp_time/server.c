#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>

int main(int argc, char **argv)
{
	int listenfd, connfd;
	struct sockaddr_in servaddr;
	char buff[BUFSIZ];
	time_t ticks;

	if(listenfd = socket(AF_INET, SOCK_STREAM, 0) < 0) 	
	{
		perror("socket()");
		exit(1);
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(13);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	if(bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
	{
		perror("bind()");
		exit(1);
	}

	if(listen(listenfd, sizeof(servaddr)) < 0)
	{
		perror("listen()");
		exit(1);
	}

	for(;;)
	{
		if((connfd = accept(listenfd, (struct sockaddr *)NULL, NULL)) < 0)
		{
			perror("accept()");
			exit(1);
		}

		ticks = time(NULL);
		snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));

		if(write(connfd, buff, strlen(buff)) < 0)
		{
			perror("write()");
			exit(0);
		}

		close(connfd);
	}
	
//	close(listenfd);

	exit(0);
}
