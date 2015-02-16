#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <pthread.h>
#include <fcntl.h>
#include <errno.h>
#include <proto.h>
//#include "../include/proto.h"
#include "medialib.h"

/*struct msg_channel_st
{
	chnid_t chnid;
	uint32_t datasize;
	uint8_t data[1];
}__attribute__((packed));*/
struct arguement
{
	chnid_t cid;
	int sd;
};

void *chndata_send_one(void *p)
{
	struct sockaddr_in raddr;
	struct msg_channel_st *sbuf;
	struct mlib_chn_st me;
	int err,fd,num;
	struct arguement *targ = p; 

	if(targ->sd < 0 || targ->cid < 1)
		return;

	raddr.sin_family = AF_INET;
	raddr.sin_port = htons(atoi(DEFAULT_RCVPORT));
	inet_pton(AF_INET,DEFAULT_MGROUP,&raddr.sin_addr);
	while(1)
	{
		me.chnid = targ->cid;
		me.cps = 0;
		me.desc = NULL;

		err = mlib_getchndata(&me);
		if(err < 0 || me.desc == NULL)
			break;
		fd = open(me.desc,O_RDONLY);
		if(fd < 0)
			continue;
		sbuf = malloc(sizeof(struct msg_channel_st) + me.cps);
		while(1)
		{
			printf("%d is working\n",targ->cid);
			memset(sbuf,'\0',sizeof(struct msg_channel_st)+me.cps);
			sbuf->chnid = targ->cid;
			num = read(fd,sbuf->data,me.cps);
			if(num <= 0)
				break;
			sbuf->datasize = num;
			if(sendto(targ->sd,sbuf,sizeof(struct msg_channel_st)+me.cps,0,\
						(void*)&raddr,sizeof(raddr)) < 0)
			{
				printf("%d send is faile\n",targ->cid);
				perror("faile cause:");
			}
			sleep(1);
		}
		free(sbuf);
		close(fd);
		sleep(1);
	}
	return;
}
#if 0
int main()
{
	int sd;
	pthread_t tid;
	struct arguement targ;

	sd = socket(AF_INET,SOCK_DGRAM,0);
	if(sd < 0)
	{
		perror("socket()");
		exit(1);
	}
	mlib_add_channel("/root/Desktop/中国好声音/",4000);
	mlib_add_channel("/root/Desktop/Music",8989);
	struct ip_mreqn mreq;
	inet_pton(AF_INET,DEFAULT_MGROUP,&mreq.imr_multiaddr);
	inet_pton(AF_INET,"0.0.0.0",&mreq.imr_address);
	mreq.imr_ifindex = if_nametoindex("eth0");

	if(setsockopt(sd,IPPROTO_IP,IP_MULTICAST_IF,&mreq,sizeof(mreq)) < 0)
	{
		perror("setsockopt()");
		exit(1);
	}
	targ.sd = sd;
	targ.cid = 1;
	pthread_create(&tid,NULL,chndata_send,&targ);
	while(1);
	pthread_join(tid,NULL);
}
#endif

void chndata_send(int sd)
{
	struct arguement targ[200];
	pthread_t tid[200];
	int i;
	for(i = 0;i < 10;i++)
	{
		targ[i].cid = i+1;
		targ[i].sd = sd;
		pthread_create(&tid[i],NULL,chndata_send_one,&targ[i]);
	}
//	for(i = 0;i < 200;i++)
//		pthread_join(tid[i],NULL);
}
