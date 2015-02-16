#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <net/if.h>
#include "../include/proto.h"
#include "client.h"
#include <pthread.h>
#define SIZE 65535

uint32_t sel = 1;
pthread_t tid;
struct client_conf_st client_conf = {
	.mgroup = DEFAULT_MGROUP,
	.rcvport = DEFAULT_RCVPORT,
	.player = DEFAULT_PLAYER
};
struct msg_list_st *msg_list;
struct msg_channel_st *msg_data;

static void *func(void *p)
{
	while(1)
	{
		sleep(2);
		printf("\33[35m");
		printf("----------------------------------------------------------------------\n");
		printf("please sel the id you want to listen:\n");
		printf("\33[36m");
		scanf("%d",&sel);
	}
}

static void f1(void)
{
	free(msg_list);
	free(msg_data);
	printf("free success!\n");
}
static void f2(void)
{
	free(msg_data);
}
/*void player(int pipe)
{
	int fd,flag = 0;
	char buf[24000];
	fd = open("123.mp3",O_RDONLY);
	while(1)
	{
		int len;
		len = read(fd,buf,24000);
		if(flag < 20)
			flag++;
		else
		{
			write(pipe,buf,len);
			write(0,buf,len);
		}
	}
}*/

int main(int argc,char *argv[])
{
	system("clear");
	int sd;

	int c,i;
	int pd[2];
	int rd_count = 0;
	struct sockaddr_in laddr,raddr;
	struct ip_mreqn mreq;
	pid_t pid;
	socklen_t raddr_len;

	atexit(f1);
	
	while(1)
	{
		c = getopt(argc,argv,"M:P:p:H");
		if(c < 0)
			break;
		switch(c)
		{
			case 'M':
				client_conf.mgroup = argv[optind - 1];
				break;
			case 'P':
				client_conf.rcvport = argv[optind - 1];
				break;
			case 'p':
				client_conf.player = argv[optind - 1];
				break;
			case 'H':
				printf(" ** [-M] 指定多播组\n");
				printf(" ** [-P] 指定接收端口\n");
				printf(" ** [-p] 指定播放器\n");
				break;
			default:
				break;
		}
	}

	sd = socket(AF_INET,SOCK_DGRAM,0);
	if(sd < 0)
	{
		perror("socket()");
		exit(1);
	}

	if(inet_pton(AF_INET,client_conf.mgroup,&mreq.imr_multiaddr) < 0)
	{
		fprintf(stderr,"inet_pton() %s\n",strerror(errno));
		exit(1);
	}
	if(inet_pton(AF_INET,"0.0.0.0",&mreq.imr_address) < 0)
	{
		fprintf(stderr,"inet_pton() %s\n",strerror(errno));
		exit(1);
	}
	if((mreq.imr_ifindex = if_nametoindex("eth0")) == 0)
	{
		printf("if_nametoindex() is error\n");
		exit(1);
	}
	if(setsockopt(sd,IPPROTO_IP,IP_ADD_MEMBERSHIP,&mreq,sizeof(mreq)) < 0)
	{
		perror("setsockopt()");
		exit(1);
	}

	laddr.sin_family = AF_INET;
	laddr.sin_port = htons(atoi(client_conf.rcvport));
	if(inet_pton(AF_INET,"0.0.0.0",&laddr.sin_addr) < 0)
	{
		fprintf(stderr,"inet_pton() %s\n",strerror(errno));
		exit(1);
	}

	if(bind(sd,(void*)&laddr,sizeof(laddr)) < 0)
	{
		perror("bind()");
		exit(1);
	}

	raddr_len = sizeof(raddr);

	msg_list = malloc(SIZE);
	if(msg_list == NULL)
	{
		printf("malloc is error!\n");
		exit(1);
	}

	while(1)
	{
		if(recvfrom(sd,msg_list,SIZE,0,(void*)&raddr,&raddr_len) < 0)
		{
			perror("recvfrom()");
			exit(1);

		}
	//	printf("%u\n",msg_list->chnid);
		printf("\33[35m");
		printf("\n\n***********************Welcome to campus radio!***********************\n");
		printf("\33[36m");
		sleep(1);
		if(msg_list->chnid == 0)
		{
			if(msg_list->length == 1 && msg_list->entry[0].chnid == 0)
				continue;
			for(i = 0;i < msg_list->length;i++)
				printf("%3u %s\n",msg_list->entry[i].chnid,\
						msg_list->entry[i].desc);
			break;
		}
	}

	if(pipe(pd) < 0)   //pd[0]:读,pd[1]:写
	{
		perror("pipe()");
		exit(1);
	}
	do
	{
		pid = fork();
	}while(pid < 0);

	if(pid == 0)
	{
		close(pd[1]);         // 子进程关闭写端
		if(dup2(pd[0],0) < 0) //管道的读端作为子进程的标准输入
		{
			perror("dup2()");
			exit(1);
		}
		//client_conf.player "Player"
		close(pd[0]);
		if(execl("/usr/local/bin/mpg123","mpg123","-",NULL) < 0)
		{
			perror("execl()");
			exit(1);
		}
		perror("execl()");
		exit(1);
	}
	else
	{
	//	pthread_t tid;
		int err;

		err = pthread_create(&tid,NULL,func,NULL);
	//	printf("tid = %d\n",tid);
		if(err)
		{
			fprintf(stderr,"pthread_create():%s\n",strerror(err));
			exit(1);
		}
		
		close(pd[0]);      //关闭读端
		msg_data = malloc(SIZE);
		if(msg_data == NULL)
		{
			printf("malloc() is error!\n");
			exit(1);
		}
		while(1)
		{
			if((rd_count = recvfrom(sd,msg_data,SIZE,0,(void*)&raddr,\
							&raddr_len)) < 0)
			{
				perror("recvfrom()");
				exit(1);
			}
			if(msg_data->chnid == sel)     
				write(pd[1],msg_data->data,msg_data->datasize);
		}
		close(pd[1]);
		pthread_join(tid,NULL);
	}
}


