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
/*
struct list_entry_st
{
	chnid_t chnid;
//	uint8_t note[MAX_ENTRY_ONE];
	uint8_t desc[MAX_ENTRY_ONE];
}__attribute__((packed));

struct msg_list_st
{
	chnid_t chnid;
	uint8_t length;
	struct list_entry_st entry[1];
}__attribute__((packed));*/


static struct msg_list_st *chnlist_getlist()
{
	struct msg_list_st *me;
	struct mlib_chn_st *chnlist = NULL;
	int num = 0;
	int err,i,fd;

	err = mlib_getchnlist(&chnlist,&num);
	if(err < 0)
		num = 1;

	me = malloc(sizeof(struct msg_list_st)+(num-1)*\
			sizeof(struct list_entry_st));
	memset(me,'\0',sizeof(struct msg_list_st)+(num-1)*sizeof(struct list_entry_st));

	me->chnid = 0;
	me->length = num;
	//printf("err = %d\n",err);
	if(err < 0)
	{
		(me->entry)->chnid = 0;
		strncpy((me->entry)->desc,"no list",MAX_ENTRY_ONE);
		return me;
	}

	for(i = 0;i < num;i++)
	{
		((me->entry)+i)->chnid = (chnlist+i)->chnid;
		fd = open((chnlist+i)->desc,O_RDONLY);
		if(fd < 0)
		{
			strncpy(((me->entry)+i)->desc,"无法获得频道信息",MAX_ENTRY_ONE);
			continue;
		}
		read(fd,((me->entry)+i)->desc,MAX_ENTRY_ONE);
		close(fd);
	}
	return me;
}

int chnlist_send(int sd)
{
	struct sockaddr_in raddr;
	struct msg_list_st *sbuf;
	int i;

	if(sd < 0)
		return -EINVAL;

	raddr.sin_family = AF_INET;
	raddr.sin_port = htons(atoi(DEFAULT_RCVPORT));
	inet_pton(AF_INET,DEFAULT_MGROUP,&raddr.sin_addr);
	while(1)
	{
	//	printf("send chnlist\n");
		sbuf = chnlist_getlist();
		if(sbuf == NULL)
		{
			printf("sbuf is NULL\n");
			continue;
		}
		if(sendto(sd,sbuf,sizeof(struct list_entry_st)+(sbuf->length-1)*\
					sizeof(struct list_entry_st),0,(void*)&raddr,\
					sizeof(raddr)) < 0)
		{
			printf("send list failed!\n");
			free(sbuf);
			continue;
		}
	//	printf("%u\n",sbuf->chnid);
	//	for(i = 0;i < sbuf->length;i++)
	//		printf("%u %s\n",sbuf->entry[i].chnid,sbuf->entry[i].desc);
		free(sbuf);
	//	sleep(1);
	}
	return 0;
}
#if 0
int main()
{
	int sd;
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
	chnlist_send(sd);
}
#endif
