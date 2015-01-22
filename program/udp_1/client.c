#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main()
{
	int sd;
	char buf[BUFSIZ];
	struct sockaddr_in raddr;
	int len;

	if((sd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
	{
		perror("socket()");
		exit(1);
	}

	bzero(&raddr, sizeof(raddr));
	raddr.sin_family = AF_INET;
	raddr.sin_port = htons(3333);
	raddr.sin_addr.s_addr = htonl(INADDR_ANY);

	bzero(buf, BUFSIZ + 1);
	len = sizeof(struct sockaddr);
	strcpy(buf, "cli");
	if(sendto(sd, buf, BUFSIZ, 0, (struct sockaddr *)&raddr, len) < 0)
	{
		perror("sendto()");
		exit(1);
	}

	bzero(buf, BUFSIZ + 1);
	if(recvfrom(sd, buf, BUFSIZ, 0, (struct sockaddr *)&raddr, &len) < 0)
	{
		perror("recvfrom()");
		exit(1);
	}
	printf("success:%s\n", buf);

	close(sd);
	exit(0);
}
