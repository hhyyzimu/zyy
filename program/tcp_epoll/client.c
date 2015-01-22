#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <string.h>

#define BUFFER_SIZE	40

int main(int argc, char *argv[])
{
	int client_sockfd;
	int len;
	struct sockaddr_in remote_addr;//服务器端网络地址结构
	char buf[BUFFER_SIZE];//数据传送的缓冲区
	
	memset(&remote_addr, 0, sizeof(remote_addr));
	remote_addr.sin_family = AF_INET;
	remote_addr.sin_port = htons(8000);
	remote_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	if((client_sockfd = socket(PF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("client socket creation failed");
		exit(EXIT_FAILURE);
	}

	if(connect(client_sockfd, (struct sockaddr *)&remote_addr, sizeof(struct sockaddr)) < 0)
	{
		perror("connect to server failed");
		exit(EXIT_FAILURE);
	}

	while(1)
	{
		printf("Please input the message:");
		scanf("%s", buf);
		if(strcmp(buf, "exit") == 0)
		{
			break;
		}
		send(client_sockfd, buf, BUFFER_SIZE, 0);
		len = recv(client_sockfd, buf, BUFFER_SIZE, 0);
		printf("receive from server: %s\n", buf);
		if(len < 0)
		{
			perror("receive from server failed");
			exit(EXIT_FAILURE);
		}
	}

	close(client_sockfd);
	return 0;
}
