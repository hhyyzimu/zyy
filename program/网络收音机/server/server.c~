#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <proto.h>
//#include "../include/proto.h"

int sd;
/*void daemonize()
{
	pid_t pid;
	int fd;

	pid = fork();
	if(pid < 0)
	{
		perror("fork()");
		exit(1);
	}
	if(pid > 0)
		exit(0);

	fd = open("/dev/null",O_RDWR);
	if(fd < 0)
	{
		perror("open()");
		exit(1);
	}
	dup2(fd,0);
	dup2(fd,1);
	dup2(fd,2);
	if(fd > 2)
		close(fd);
	setsid();
	umask(0);
}*/
int socket_init()//初始化网络接口并创建多波组
{
	sd = socket(AF_INET,SOCK_DGRAM,0);
	if(sd < 0)
	{
		perror("socket()");
		return -1;
	}

	struct ip_mreqn mreq;
	inet_pton(AF_INET,DEFAULT_MGROUP,&mreq.imr_multiaddr);
	inet_pton(AF_INET,"0.0.0.0",&mreq.imr_address);
	mreq.imr_ifindex = if_nametoindex("eth0");

	if(setsockopt(sd,IPPROTO_IP,IP_MULTICAST_IF,&mreq,sizeof(mreq)) < 0)
	{
		perror("setsockopt()");
		return -1;
	}
	return 0;
}
int main()
{
	int err;
	err = socket_init();
	if(err < 0)
	{
		printf("failure");
		return -1;
	}
	mlib_add_channel("./English",16000+100);
	mlib_add_channel("./Chinese",16000+100);
	mlib_add_channel("./Music",16000+100);

	chndata_send(sd);
	chnlist_send(sd);
	return 0;
}
