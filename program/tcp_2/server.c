#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

static void job(int new_sd)
{
	socklen_t len;
	char buf[BUFSIZ];
	bzero(buf, BUFSIZ + 1);
	strcpy(buf, "server");
	len = send(new_sd, buf, strlen(buf), 0);
	if(len < 0)
	{
		perror("send()");
		exit(1);
	}

	bzero(buf, BUFSIZ + 1);
	len = recv(new_sd, buf, BUFSIZ, 0);
	if(len > 0)
	{
		printf("success:%s\n", buf);
	}else{
		printf("faild\n");
	}
	}

int main()
{
	int sd, new_sd;
	socklen_t len;
	struct sockaddr_in laddr, raddr;

	if((sd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("socket()");
		exit(1);
	}

	bzero(&laddr, sizeof(laddr));
	laddr.sin_family = AF_INET;
	laddr.sin_port = htons(2222);
	laddr.sin_addr.s_addr = INADDR_ANY;

	if(bind(sd, (struct sockaddr *)&laddr, sizeof(struct sockaddr)) < 0)
	{
		perror("bind()");
		exit(1);
	}

	if(listen(sd, 200) < 0)
	{
		perror("listen()");
		exit(1);
	}

	while(1){
		len = sizeof(struct sockaddr);
		if((new_sd = accept(sd, (struct sockaddr *)&raddr, &len)) < 0)
		{
			perror("accept()");
			exit(1);
		}

		job(new_sd);
	}
	
	close(sd);
	exit(0);
}
