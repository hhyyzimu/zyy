#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{
	int sd, addrlen;
	struct sockaddr_in laddr, raddr;
	char buf[BUFSIZ];

	if((sd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
	{
		perror("socket()");
		exit(1);
	}

	bzero(&laddr, sizeof(laddr));
	laddr.sin_family = AF_INET;
	laddr.sin_port = htons(3333);
	laddr.sin_addr.s_addr = htonl(INADDR_ANY);

	if(bind(sd, (struct sockaddr *)&laddr, sizeof(laddr)) < 0)
	{
		perror("bind()");
		exit(1);
	}

	addrlen = sizeof(struct sockaddr);

	while(1)
	{
		if(recvfrom(sd, buf, BUFSIZ, 0, (struct sockaddr *)&raddr, &addrlen) < 0)
		{
			perror("recvfrom()");
			exit(1);
		}
		printf("success:%s\n", buf);

		strcpy(buf, "server");
		if(sendto(sd, buf, BUFSIZ, 0, (struct sockaddr *)&raddr, addrlen) < 0)
{
			perror("sendto()");
			exit(1);
		}
		}
	close(sd);

	exit(0);
}
