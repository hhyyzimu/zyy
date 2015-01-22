#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

static void job(sd)
{
	bzero(buf, BUFSIZ + 1);
	len = recv(sd, buf, BUFSIZ, 0);
	if(len > 0)
	{
		printf("success:%s\n", buf);
	}else{
		printf("fail!\n");
	}

	bzero(buf, BUFSIZ + 1);
	strcpy(buf, "client");
	len = send(sd, buf, strlen(buf), 0);
	if(len < 0)
	{
		perror("send()");
		exit(1);
	}
}

int main()
{
	int sd, len;
	struct sockaddr_in raddr;
	char buf[BUFSIZ];

	if((sd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("socket()");
		exit(1);
	}

	bzero(&raddr, sizeof(raddr));
	raddr.sin_family = AF_INET;
	raddr.sin_port = htons(2222);
	inet_aton("0.0.0.0", (struct in_addr *)&raddr.sin_addr.s_addr);

	if(connect(sd, (struct sockaddr *)&raddr, sizeof(raddr)) != 0)
	{
		perror("connect()");
		exit(1);
	}
	job(sd);

	close(sd);
	exit(0);
}
